/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "drv_ble.h"
#include "bsp_ble.h"
#include "ble_nus.h"
#include "drv_comm.h"
#include "event_config.h"
#include "ssz_queue.h"
#include "ssz_common.h"
#include "event.h"
#include "event_config.h"
#include "timer.h"
#include "timer_config.h"

/************************************************
* Declaration
************************************************/
#define BLE_SEND_DATA_TIME_MS 100

/************************************************
* Variable 
************************************************/
static uint8_t g_drv_ble_recv_buff[244*3+1];

static uint8_t g_drv_ble_send_buff[244*6];
static SszQueue g_drv_ble_send_queue;
static uint8_t g_drv_ble_once_send_content[244];
static uint8_t g_drv_ble_once_send_cotent_size=0;


/************************************************
* Function 
************************************************/
bool drv_ble_send(void* obj, const void* buff, int buff_size) {
	if (!ERT_drv_ble_is_connected()) {
		return false;
	}
	for (int i = 0; i < buff_size; i++) {
		if (-1 == ssz_queue_push_back(&g_drv_ble_send_queue, ((const uint8_t*)buff)+i)) {
			ssz_traceln("ble send buff is full, ignore bytes[%d]\n", buff_size-i);
			return false;
		}
	}
	event_set(kEventBLESendNewData);
	return true;
}

static const uint8_t* drv_ble_peek_send_content(int *send_content_size){
	ssz_assert(send_content_size);
	if (g_drv_ble_once_send_cotent_size==0 && ssz_queue_size(&g_drv_ble_send_queue)>0) {
		//read from queue
		int content_max_length = sizeof(g_drv_ble_once_send_content);
		//the max size must small than mtu size
		if (content_max_length>247-3) {
			content_max_length = 247 - 3;
		}

		int once_send_content_size;
		once_send_content_size = ssz_queue_size(&g_drv_ble_send_queue);
		ssz_assert(once_send_content_size>0);
		if (once_send_content_size > content_max_length) {
			once_send_content_size = content_max_length;
		}
		uint8_t* p;
		int i;
		for (i = 0; i < once_send_content_size; i++) {
			p = (uint8_t*)ssz_queue_front(&g_drv_ble_send_queue);
			if (p == NULL) {
				break;
			}
			ssz_queue_pop_font(&g_drv_ble_send_queue);
			g_drv_ble_once_send_content[i] = *p;
		}
		g_drv_ble_once_send_cotent_size = i;
	}

	if (g_drv_ble_once_send_cotent_size>0) {
		*send_content_size = g_drv_ble_once_send_cotent_size;
		return g_drv_ble_once_send_content;
	}else{
		*send_content_size = 0;
		return NULL;
	}
}
static void drv_ble_pop_send_content(){
	g_drv_ble_once_send_cotent_size = 0;
}
static bool drv_ble_is_send_content_empty(){
	if (g_drv_ble_once_send_cotent_size>0
	 || ssz_queue_size(&g_drv_ble_send_queue) > 0) {
		return false;
	}
	else{
		return true;
	}
}
static void drv_ble_send_cache_data() {
	if (drv_ble_is_send_content_empty()) {
		return;
	}
	const uint8_t* content;

	int send_content_size;
	uint32_t send_ret;
	int send_count = 0;
	while (true) {
		if (drv_ble_is_send_content_empty()) {
			break;
		}

		content = drv_ble_peek_send_content(&send_content_size);
		if (content) {
#ifdef SSZ_TARGET_MACHINE
			send_ret = bsp_ble_send(content, send_content_size);
			if (send_ret != NRF_SUCCESS) {
				break;
			}
			else {
				send_count++;
			}
#endif
			drv_ble_pop_send_content();
		}
	}
}

static void drv_ble_on_send_new_data() {
	if (ERT_drv_ble_is_connected()) {
		drv_ble_send_cache_data();
		if (!drv_ble_is_send_content_empty()) {
			//发送缓存主要靠kEventBLEOnePackageSendComplete事件来触发
			//此处使用timer来发送缓存,主要是为了防止kEventBLEOnePackageSendComplete可能收不到
			timer_start_oneshot_after(kTimerBLESendNewData, BLE_SEND_DATA_TIME_MS);
		}
	}
}

int8_t ERT_drv_ble_init(const char * device_name)
{
	drv_comm_init(kCommBLE, kEventBLEReceiveNewData, false, 
		          g_drv_ble_recv_buff, ssz_array_size(g_drv_ble_recv_buff), NULL, drv_ble_send);

	ssz_queue_init(&g_drv_ble_send_queue, g_drv_ble_send_buff, sizeof(g_drv_ble_send_buff), 1);
	
	event_set_handler(kEventBLESendNewData, drv_ble_on_send_new_data);
	timer_set_handler(kTimerBLESendNewData, drv_ble_on_send_new_data);

	bsp_ble_init(device_name);
	bsp_ble_start_advertising();
	
	return 0;
}


void ERT_drv_ble_start_advertising()
{
	bsp_ble_start_advertising();
}

void ERT_drv_ble_stop_advertising()
{
	bsp_ble_stop_advertising();
}

void ERT_drv_ble_set_advertising_inter_ms(int inter_ms)
{
	bsp_ble_set_adv_inter_ms(inter_ms);
}

uint32_t ERT_drv_ble_change_mtu_size(int mtu_size)
{
	return bsp_ble_change_mtu_size(mtu_size);
}

uint32_t ERT_drv_ble_change_conn_interval(int min_conn_interval_ms, int max_conn_interval_ms)
{
	return bsp_ble_change_conn_interval(min_conn_interval_ms, max_conn_interval_ms); 
}

int ERT_drv_ble_is_connected()
{
	if(bsp_ble_connect_handle() != BLE_CONN_HANDLE_INVALID){
		return true;
	}else{
		return false;
	}
}

void ERT_drv_ble_close()
{
	bsp_ble_close();
}



