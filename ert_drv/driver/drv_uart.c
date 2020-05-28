/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "drv_uart.h"
#include "bsp_uart.h"
#include "drv_common.h"
#include "drv_comm.h"
#include "comm_config.h"
#include "ssz_uart.h"
#include "event_config.h"
#include "ssz_common.h"
#include "ssz_queue.h"
#include "event.h"
#include "event_config.h"
#include "timer.h"
#include "timer_config.h"

/************************************************
* Declaration
************************************************/
#define PEER_SEND_DATA_TIME_MS 100

void drv_peer_on_send_new_data();

/************************************************
* Variable 
************************************************/
#if PEER_COMM_MSG_MODULE_ENABLE
static uint8_t g_drv_peer_uart_recv_buff[64 + 1];
#endif

static uint8_t g_drv_peer_send_data_arr[128];
static SszQueue g_drv_peer_send_data_queue;

static uint8_t g_drv_peer_once_send_content[244];
static uint8_t g_drv_peer_once_send_cotent_size=0;

/************************************************
* Function 
************************************************/
bool drv_uart_send(void* obj, const void* buff, int buff_size){
	for (int i = 0; i < buff_size; i++) 
	{
		if (-1 == ssz_queue_push_back(&g_drv_peer_send_data_queue, ((const uint8_t *)buff)+i)) {
				//ssz_traceln("ble send buff is full, ignore bytes[%d]\n", buff_size-i);
			return false;
		}
	}
	event_set(kEventPeerSendNewData);
	return true;
}

static const uint8_t* drv_pee_uart_peek_send_content(int *send_content_size){
	ssz_assert(send_content_size);

	if (g_drv_peer_once_send_cotent_size==0 && ssz_queue_size(&g_drv_peer_send_data_queue)>0) {
		//read from queue
		int content_max_length = sizeof(g_drv_peer_once_send_content);
		//the max size must small than mtu size
		if (content_max_length>247-3) {
			content_max_length = 247 - 3;
		}

		int once_send_content_size;
		once_send_content_size = ssz_queue_size(&g_drv_peer_send_data_queue);
		ssz_assert(once_send_content_size>0);
		if (once_send_content_size > content_max_length) {
			once_send_content_size = content_max_length;
		}
		uint8_t* p;
		int i;
		for (i = 0; i < once_send_content_size; i++) {
			p = (uint8_t*)ssz_queue_front(&g_drv_peer_send_data_queue);
			if (p == NULL) {
				break;
			}
			ssz_queue_pop_font(&g_drv_peer_send_data_queue);
			g_drv_peer_once_send_content[i] = *p;
		}
		g_drv_peer_once_send_cotent_size = i;
	}

	if (g_drv_peer_once_send_cotent_size>0) {
		*send_content_size = g_drv_peer_once_send_cotent_size;
		return g_drv_peer_once_send_content;
	}else{
		*send_content_size = 0;
		return NULL;
	}
}

static void drv_peer_pop_send_content(){
	g_drv_peer_once_send_cotent_size = 0;
}

static bool drv_peer_is_send_content_empty(){
	if (g_drv_peer_once_send_cotent_size>0
	 || ssz_queue_size(&g_drv_peer_send_data_queue) > 0) {
		return false;
	}
	else{
		return true;
	}
}

static void drv_peer_send_cache_data() {
	if (drv_peer_is_send_content_empty()) {
		return;
	}
	const uint8_t* content;

	int send_content_size;
	uint32_t send_ret;
	int send_count = 0;
	while (true) {
		if (drv_peer_is_send_content_empty()) {
			break;
		}

		content = drv_pee_uart_peek_send_content(&send_content_size);
		if (content) {
			send_ret = bsp_uart_send(content, send_content_size);
			if (send_ret != true) {
				break;
			}
			else {
				send_count++;
			}
			drv_peer_pop_send_content();
		}
	}
}

void drv_peer_on_send_new_data() {
	drv_peer_send_cache_data();
	if (!drv_peer_is_send_content_empty()) {
		//发送缓存主要靠kEventBLEOnePackageSendComplete事件来触发
		//此处使用timer来发送缓存,主要是为了防止kEventBLEOnePackageSendComplete可能收不到
		timer_start_oneshot_after(kTimerPeerSendNewData, PEER_SEND_DATA_TIME_MS);
	}
}

int8_t ERT_drv_uart_init(uint8_t uart_id)
{
#if PEER_COMM_MSG_MODULE_ENABLE

	drv_comm_init(kCommPeerUart, kEventPeerUartReceiveNewData, 
		          true, g_drv_peer_uart_recv_buff, ssz_array_size(g_drv_peer_uart_recv_buff), 
		          NULL, drv_uart_send);
#endif

	ssz_queue_init(&g_drv_peer_send_data_queue, g_drv_peer_send_data_arr, ssz_array_size(g_drv_peer_send_data_arr),
						ssz_array_node_size(g_drv_peer_send_data_arr));

	event_set_handler(kEventPeerSendNewData, drv_peer_on_send_new_data);
	timer_set_handler(kTimerPeerSendNewData, drv_peer_on_send_new_data);
	return 0;
}

void ERT_drv_uart_deinit(void)
{
	bsp_uart_deinit();
}
















