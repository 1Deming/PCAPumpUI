/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "drv_virtual_uart.h"
#include "ssz_virtual_uart.h"
#include "nrfx_timer.h"
#include "bsp_gpio.h"
#include "ssz_safe_queue.h"
#include "ssz_common.h"


/************************************************
* Declaration
************************************************/
#define VIRTUAL_UART_BAUDRATE		1200
#define VIRTUAL_UART_DATA_LEN		8
#define VIRTUAL_UART_STOP_BIT		1


/************************************************
* Variable 
************************************************/
const nrf_drv_timer_t g_virtual_uart_timer = NRF_DRV_TIMER_INSTANCE(3);
SszVirtualUart g_drv_virtual_uart;

uint8_t g_drv_virtual_uart_send_buff[128];


SszSafeQueue g_monitor_uart_queue_inter;
SszSafeQueue *g_monitor_uart_queue = &g_monitor_uart_queue_inter;
uint8_t g_monotor_uart_rev_buff[64];



/************************************************
* Function 
************************************************/
void virtual_uart_rx_pin_event_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
	if(pin != VIRTUAL_UART_RX_PIN_NUMBER) return;
	

	switch(action)
	{
		case NRF_GPIOTE_POLARITY_LOTOHI:
			break;

		case NRF_GPIOTE_POLARITY_HITOLO:
			ssz_virtual_uart_on_start_bit_event(&g_drv_virtual_uart);
			break;

		case NRF_GPIOTE_POLARITY_TOGGLE:
			break;
	}
}

void virtual_uart_timer_handler(nrf_timer_event_t event_type, void* p_context)
{
	uint8_t ch;
	if(ssz_virtual_uart_on_receive_byte(&g_drv_virtual_uart, &ch))
	{//获取一个字节
		ssz_safe_queue_push_back(g_monitor_uart_queue, &ch);
	}

	ssz_virtual_uart_on_send_byte(&g_drv_virtual_uart);
}

void drv_virtaul_uart_init(void)
{
	VirtualUartSettings uart_set =
	{
		.baud_rate = VIRTUAL_UART_BAUDRATE,
		.data_len = VIRTUAL_UART_DATA_LEN,
		.stop_bit = VIRTUAL_UART_STOP_BIT,
	};
	
	ssz_virtual_uart_init(&g_drv_virtual_uart, NULL, uart_set, VIRTUAL_UART_RX_PIN_NUMBER, VITTUAL_UART_TX_PIN_NUMBER, 
						  virtual_uart_rx_pin_event_handler, g_drv_virtual_uart_send_buff, sizeof(g_drv_virtual_uart_send_buff),
						  g_virtual_uart_timer, virtual_uart_timer_handler);


	ssz_safe_queue_init(g_monitor_uart_queue, g_monotor_uart_rev_buff, ssz_array_size(g_monotor_uart_rev_buff), 
						ssz_array_node_size(g_monotor_uart_rev_buff));				  
}


int drv_virtual_uart_send(uint8_t *buff, int buff_size)
{
	return ssz_virtual_uart_on_send(&g_drv_virtual_uart, buff, buff_size);
}




























































