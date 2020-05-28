/************************************************
* DESCRIPTION:
*
*
************************************************/
#pragma once

#include "ssz_def.h"
#include "ssz_safe_queue.h"
#include "nrf_gpio.h"
#include "nrf_gpiote.h"
#include "nrf_drv_gpiote.h"
#include "nrf_drv_timer.h"

#include "nrf.h"
#include "app_error.h"
#include "nrf_delay.h"


/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
	uint16_t baud_rate;
	uint8_t data_len;
	uint8_t stop_bit;
}VirtualUartSettings;

typedef struct
{
	void *object;
	VirtualUartSettings uart_settings;
	uint8_t rxd_pin;  
	uint8_t txd_pin;
	
	bool flag_receive_start_bit;        /* receive start bit */
	uint8_t receive_bit_count;
	bool flag_is_receiving;
	uint8_t byte_data;

	SszSafeQueue send_queue;
	uint8_t send_byte_data;
	uint8_t send_bit_count;
	uint8_t send_bit_size;
	bool flag_is_sending;
	
	nrf_drv_timer_t timer;	
}SszVirtualUart;

typedef void (*GpioEventhandler)(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action);
typedef	void (*TimerEventHandler)(nrf_timer_event_t event_type, void* p_context);
bool ssz_virtual_uart_on_start_bit_event(SszVirtualUart *virtual_uart);
int ssz_virtual_uart_init(SszVirtualUart *virtual_uart, void *obj, VirtualUartSettings settings, uint8_t rx_pin, uint8_t tx_pin, 
                                  GpioEventhandler gpioe_handler, uint8_t *send_buff, uint16_t send_size, nrf_drv_timer_t timer, TimerEventHandler timer_handler);
bool ssz_virtual_uart_on_receive_byte(SszVirtualUart *virtual_uart, uint8_t *byte);
bool ssz_virtual_uart_on_send_byte(SszVirtualUart * virtual_uart);
int ssz_virtual_uart_on_send(SszVirtualUart * virtual_uart, uint8_t *buff, int buff_size);







#ifdef __cplusplus
}
#endif

