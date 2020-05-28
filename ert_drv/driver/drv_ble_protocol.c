/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "drv_ble_protocol.h"
#include "drv_ble.h"
#include <string.h>
#include "ssz_algorithm.h"
#include "event_config.h"
#include "ssz_safe_queue.h"
#include "event.h"
#include "ssz_common.h"
#include "timer.h"
#include "timer_config.h"
#include "comm.h"
#include "comm_config.h"
#include "drv_comm.h"
#include <string.h>
#include "ssz_queue.h"
#include "bsp_ble.h"
#include "msg.h"
#include "msg_config.h"

/************************************************
* Declaration
************************************************/
#define COMM_MAX_SIZE_OF_RECEIVE_STR 224


/************************************************
* Variable 
************************************************/
static uint8_t g_ble_comm_receive[256];
static int g_ble_comm_receive_index = 0;

static uint8_t g_drv_ble_comm_rev_data_arr[8][COMM_MAX_SIZE_OF_RECEIVE_STR];
static SszQueue g_drv_ble_comm_rev_data_list;

/************************************************
* Function 
************************************************/
// A frame data timeout , Array index to 0
void drv_ble_comm_recv_from_slave_time_out( void )
{
    g_ble_comm_receive_index = 0;   
}

bool drv_ble_on_recv_byte_handle(CommID comm_id, uint8_t ch)
{
	timer_start_oneshot_after(kTimerBLECommTimeTooLong, 1000);

	if(g_ble_comm_receive_index == 0)
	{
		if(ch != 0x55) 
		{
			g_ble_comm_receive_index = 0;
		}else{
			g_ble_comm_receive[g_ble_comm_receive_index] = 0x55;
			g_ble_comm_receive_index++;			
		}
	}
	else if(g_ble_comm_receive_index == 1)
	{
		if(ch != 0xAA)
		{
			g_ble_comm_receive_index = 0;
			if(ch == 0x55)
			{
				g_ble_comm_receive[0] = 0x55;
				g_ble_comm_receive_index = 1;	
			}
		}else{
			g_ble_comm_receive[g_ble_comm_receive_index] = 0xAA;
			g_ble_comm_receive_index++;
		}
	}
	else if(g_ble_comm_receive_index == 2)
	{

		g_ble_comm_receive[g_ble_comm_receive_index] = ch;
		g_ble_comm_receive_index++;
	}
	else if(g_ble_comm_receive_index == 3)
	{

		g_ble_comm_receive[g_ble_comm_receive_index] = ch;
		g_ble_comm_receive_index++;
	}
	else
	{
		g_ble_comm_receive[g_ble_comm_receive_index] = ch;
		g_ble_comm_receive_index++;
		if(g_ble_comm_receive_index >= (3 + g_ble_comm_receive[3] + 4))
		{
			uint32_t crc32_result = ssz_crc32(g_ble_comm_receive, 3 + g_ble_comm_receive[3]);
			uint32_t crc32_rec = (g_ble_comm_receive[g_ble_comm_receive_index-4]<<24)
			                     |(g_ble_comm_receive[g_ble_comm_receive_index-3]<<16)
			                     |(g_ble_comm_receive[g_ble_comm_receive_index-2]<<8)
				                 |(g_ble_comm_receive[g_ble_comm_receive_index-1]);
			g_ble_comm_receive_index = 0;
			//if(crc32_result == crc32_rec)
			{
				uint8_t data_buff[COMM_MAX_SIZE_OF_RECEIVE_STR];
				memset(data_buff, 0, sizeof(data_buff));
				memcpy(data_buff, g_ble_comm_receive+3, g_ble_comm_receive[3]);
				
				msg_post_two_param(kMsgBleSendAck, g_ble_comm_receive[4], ((g_ble_comm_receive[5]<<8)|g_ble_comm_receive[6]));

				ssz_queue_push_back(&g_drv_ble_comm_rev_data_list, data_buff);
			}
			
			timer_stop(kTimerBLECommTimeTooLong);
		}
	}
	return true;
}


void ERT_drv_ble_send_ack(MsgParam param)
{
	uint8_t tx_data[5] = {0x05, 0x0, 0x0, 0x0, 0x01};
	uint16_t sn = param.int16_param1;
	tx_data[1] = (uint8_t)sn;
	uint16_t cmd = param.int16_param2;
	tx_data[2] = (uint8_t)(cmd>>8);
	tx_data[3] = cmd&0xFF;

	switch(cmd)
	{
		case 0x0165:
		case 0x0166:
		case 0x0167:
		case 0x0168:

		case 0x0205:
		case 0x0206:
		case 0x0207:

		case 0x0303:

		case 0x0503:
		case 0x0505:
		case 0x0506:

		case 0x0605:
		case 0x0606:
				
		case 0x0701:
		case 0x0702:
		case 0x0703:
		case 0x0704:
		case 0x0705:
			ert_sendBleData(tx_data);
			break;
		
		default:
			break;

	}

}
   
bool drv_ble_on_recv_buff(CommID comm_id, const uint8_t* buff, int buff_size, bool is_handled_ok_at_pre_handler)
{
	for(int i=0; i<buff_size;i++)
	{
		drv_ble_on_recv_byte_handle(comm_id, buff[i]);
	}
	return true;
}

void ERT_drv_ble_protocol_init(void)
{
	comm_set_file(kCommBLE, drv_comm_file(kCommBLE));
	comm_set_buff_receive_handler(kCommBLE, kCommHandleFirst, drv_ble_on_recv_buff);
	
	timer_set_handler(kTimerBLECommTimeTooLong, drv_ble_comm_recv_from_slave_time_out);

	ssz_queue_init(&g_drv_ble_comm_rev_data_list, &g_drv_ble_comm_rev_data_arr, 
		             ssz_array_size(g_drv_ble_comm_rev_data_arr), ssz_array_node_size(g_drv_ble_comm_rev_data_arr));

	msg_set_handler(kMsgBleSendAck, ERT_drv_ble_send_ack);

}

bool ERT_drv_ble_new_data_flag(void)
{
	return ssz_queue_is_empty(&g_drv_ble_comm_rev_data_list)? 0 : 1;
}

int ERT_drv_ble_get_data(uint8_t *data)
{
	if(ssz_queue_is_empty(&g_drv_ble_comm_rev_data_list))
	{
		memset(data, 0, COMM_MAX_SIZE_OF_RECEIVE_STR);
		return 0;
	}
	memcpy(data, (uint8_t *)ssz_queue_front(&g_drv_ble_comm_rev_data_list), COMM_MAX_SIZE_OF_RECEIVE_STR);
	ssz_queue_pop_font(&g_drv_ble_comm_rev_data_list);
	return ssz_queue_size(&g_drv_ble_comm_rev_data_list);
}



int ERT_drv_ble_send(void *buff, int buff_size)
{
	uint8_t data_buff[256];
	uint8_t count = 0;
	uint8_t *p = data_buff;
	
	p[count++] = DRV_BLE_PTOROCOL_START_SIGN1;
	p[count++] = DRV_BLE_PTOROCOL_START_SIGN2;
	p[count++] = 0x0;
	p[count++] = buff_size+1;
	p[count++] = 0xFF;	//msg ID
	memcpy(&p[count], (uint8_t *)buff, buff_size);
	count += buff_size;
	uint32_t crc32 = ssz_crc32(data_buff,  count);
	memcpy(&p[count], &crc32, 4);
	count += 4;
	p[count++] = 0xED;

	ssz_fwrite(comm_to_file(kCommBLE), data_buff, count);
	
	return count;
}


bool ert_getBleData(uint8_t *data)
{
	if(ssz_queue_is_empty(&g_drv_ble_comm_rev_data_list))
	{
		return false;
	}
	memcpy(data, (uint8_t *)ssz_queue_front(&g_drv_ble_comm_rev_data_list), COMM_MAX_SIZE_OF_RECEIVE_STR);
	ssz_queue_pop_font(&g_drv_ble_comm_rev_data_list);
	return true;	
}

void ert_sendBleData(uint8_t *data)
{
	uint8_t data_buff[256];
	uint8_t count = 0;
	uint8_t *p = data_buff;
	uint8_t data_size = data[0];
	
	p[count++] = DRV_BLE_PTOROCOL_START_SIGN1;
	p[count++] = DRV_BLE_PTOROCOL_START_SIGN2;
	p[count++] = 0x0;
	
	memcpy(&p[count], (uint8_t *)data, data_size);
	count += data_size;

	uint32_t crc32 = ssz_crc32(data_buff,  count);
	memcpy(&p[count], &crc32, 4);
	count += 4;
	
	p[count++] = 0xED;

	ssz_fwrite(comm_to_file(kCommBLE), data_buff, count);
	///drv_ble_send

}












