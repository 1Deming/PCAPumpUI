/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "drv_uart_protocol.h"
#include "comm.h"
#include "comm_config.h"
#include "ssz_safe_queue.h"
#include "timer_config.h"
#include "timer.h"
#include "ssz_config.h"
#include <string.h>
#include "drv_comm.h"
#include "bsp_uart.h"
#include "ssz_common.h"
#include "ssz_safe_buff.h"
#include "ssz_queue.h"
#include "msg.h"


/************************************************
* Declaration
************************************************/
#define COMM_ID 					kComMCUUart
#define COMM_HANDLE_ORDER 			kCommHandleFirst

#define UART_PROTOCOL_START_SIGN	0x61
#define UART_PROTOCOL_END_SIGN		0x7A

#define UART_PROTOCOL_MSG_LEN		(1+16)

/************************************************
* Variable 
************************************************/
static uint8_t g_peer_uart_comm_receive[UART_PROTOCOL_MSG_LEN*2];
static int g_peer_uart_receive_index = 0;

static uint8_t g_drv_peer_data_arr[8][UART_PROTOCOL_MSG_LEN];
static SszSafeQueue g_drv_peer_data_queue;

/************************************************
* Function 
************************************************/
uint16_t com_crc16( uint8_t* data_p, uint8_t length)
{
  uint8_t x;
  uint16_t crc = 0xFFFF;

  while(length--){
    x = (crc >> 8) ^ (*data_p++);
    x ^= x>>4;
    crc = (crc << 8) ^ ((uint16_t)(x << 12))
          ^ ((uint16_t)(x <<5)) ^ ((uint16_t)x);
  }
  return crc;
}

// A frame data timeout , Array index to 0
void drv_peer_uart_recv_from_slave_time_out( void )
{
    g_peer_uart_receive_index = 0;   
}

bool drv_uart_receive_byte_handler(CommID comm_id, uint8_t ch,
                                       bool is_handled_ok_at_pre_handler)
{
	timer_start_oneshot_after(kTimerPeerCommTimeTooLong, 1000);
	if(g_peer_uart_receive_index == 0)
	{
		if(ch == UART_PROTOCOL_START_SIGN){
			g_peer_uart_comm_receive[g_peer_uart_receive_index] = ch;
			g_peer_uart_receive_index++;			
		}else{
			g_peer_uart_receive_index = 0;
		}
	}
	else 
	{
		g_peer_uart_comm_receive[g_peer_uart_receive_index] = ch;
		g_peer_uart_receive_index++;
		if(g_peer_uart_receive_index == (UART_PROTOCOL_MSG_LEN+4))
		{
			g_peer_uart_receive_index = 0;
			uint16_t crc16_result, crc16_rev;
			crc16_result = com_crc16(g_peer_uart_comm_receive, UART_PROTOCOL_MSG_LEN+1);
			crc16_rev = (uint16_t)(g_peer_uart_comm_receive[UART_PROTOCOL_MSG_LEN+1]<<8)
				        |g_peer_uart_comm_receive[UART_PROTOCOL_MSG_LEN+2];
			if(memcmp(&crc16_result, &crc16_rev, 2) == 0)
			{//handle data
				uint8_t data_buff[UART_PROTOCOL_MSG_LEN];
				memcpy(data_buff, g_peer_uart_comm_receive+1, UART_PROTOCOL_MSG_LEN);
				
				
				
				ssz_safe_queue_push_back(&g_drv_peer_data_queue, data_buff);
			}
			timer_stop(kTimerPeerCommTimeTooLong);
		}

	}
	return true;
}


                              

void ERT_drv_uart_protocol_init(uint8_t uart_id)
{
	comm_set_file(kCommPeerUart, drv_comm_file(kCommPeerUart));
	comm_set_byte_receive_handler(kCommPeerUart, COMM_HANDLE_ORDER, drv_uart_receive_byte_handler);

	timer_set_handler(kTimerPeerCommTimeTooLong, drv_peer_uart_recv_from_slave_time_out);

	ssz_safe_queue_init(&g_drv_peer_data_queue, &g_drv_peer_data_arr, ssz_array_size(g_drv_peer_data_arr), 
						ssz_array_node_size(g_drv_peer_data_arr));

}

bool ERT_drv_uart_new_data_flag(uint8_t uart_id)
{
	return ssz_safe_queue_is_empty(&g_drv_peer_data_queue)? 0 : 1;
}

int ERT_drv_uart_get_data(uint8_t uart_id, uint8_t *data)
{
	if(ssz_safe_queue_is_empty(&g_drv_peer_data_queue))
	{
		return 0;
	}
	memcpy(data, (uint8_t *)ssz_safe_queue_front(&g_drv_peer_data_queue), UART_PROTOCOL_MSG_LEN);
	ssz_safe_queue_pop_front(&g_drv_peer_data_queue);
	return UART_PROTOCOL_MSG_LEN;
}

bool ert_getSerialData(uint8_t * data)
{
	if(ssz_safe_queue_is_empty(&g_drv_peer_data_queue))
	{
	    memset(data, 0, 14);
		return false;
	}

	memcpy(data, (uint8_t *)ssz_safe_queue_front(&g_drv_peer_data_queue), 11);
	ssz_safe_queue_pop_front(&g_drv_peer_data_queue);

	return true;
}


int ERT_drv_uart_send(uint8_t uart_id, void *buff, int buff_size)
{
    uint8_t tx_buff[UART_PROTOCOL_START_SIGN+8];
	uint8_t *p = tx_buff;
	uint16_t crc16_result = 0xFFFF;
	uint8_t count = 0;

	p[count++] = UART_PROTOCOL_START_SIGN;
	memcpy(&p[count], buff, buff_size);
	count += buff_size;
	memset(&p[count], 0, UART_PROTOCOL_MSG_LEN-buff_size);  //fill with zero
	count += UART_PROTOCOL_MSG_LEN-buff_size;
	crc16_result = com_crc16(tx_buff, count);
	p[count++] = (uint8_t)(crc16_result>>8);
	p[count++] = (uint8_t)(crc16_result&0xff);
	p[count++] = UART_PROTOCOL_END_SIGN; 

	ssz_fwrite(comm_to_file(kCommPeerUart), tx_buff, count);
	return count;
}



bool ert_sendSerialData(uint8_t *data)
{
    uint8_t tx_buff[UART_PROTOCOL_START_SIGN+8];
	uint8_t *p = tx_buff;
	uint16_t crc16_result = 0xFFFF;
	uint8_t count = 0;

	p[count++] = UART_PROTOCOL_START_SIGN;

	memcpy(&p[count], data, 11);
	count += 11;
	
	crc16_result = com_crc16(tx_buff, count);
	p[count++] = (uint8_t)(crc16_result>>8);
	p[count++] = (uint8_t)(crc16_result&0xff);
	p[count++] = UART_PROTOCOL_END_SIGN; 

	//ssz_fwrite(comm_to_file(kCommPeerUart), tx_buff, count);
	//队列
	return true;
}


































