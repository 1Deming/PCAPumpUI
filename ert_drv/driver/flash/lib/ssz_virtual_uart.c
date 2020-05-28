/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "ssz_virtual_uart.h"
#include "bsp_gpio.h"
#include "ssz_common.h"
#include "nrf_gpio.h"
#include "drv_gpio.h"


/************************************************
* Declaration
************************************************/
#define VIRTUAL_UART_START_BIT_LEN		1
#define M_get_uart_data_len(virtual_uart)  (virtual_uart->uart_settings.data_len)
#define M_get_uart_frame_len(virtual_uart)	(virtual_uart->uart_settings.data_len + virtual_uart->uart_settings.stop_bit + VIRTUAL_UART_START_BIT_LEN)

/************************************************
* Variable 
************************************************/

/************************************************
* Function 
************************************************/
uint32_t ssz_gpioe_set_pin(uint8_t pin_number, GpioEventhandler event_handler)
{
    uint32_t err_code;
    nrf_drv_gpiote_in_config_t config = NRFX_GPIOTE_CONFIG_IN_SENSE_HITOLO(false);
    config.sense = NRF_GPIOTE_POLARITY_HITOLO;
    config.pull = NRF_GPIO_PIN_PULLUP;
    err_code = nrf_drv_gpiote_in_init(pin_number, &config, event_handler);
    //APP_ERROR_CHECK(err_code);
    
    nrf_drv_gpiote_in_event_enable(pin_number, true);
	return err_code;
}

uint32_t ssz_timer_us_init(nrf_drv_timer_t *timer, uint32_t inteval_us, TimerEventHandler timer_handler)
{
    //uint32_t time_us = inteval_us; //Time(in miliseconds) between consecutive compare events.
    uint32_t time_ticks;
    uint32_t err_code = NRF_SUCCESS;

    nrf_drv_timer_config_t timer_cfg = NRF_DRV_TIMER_DEFAULT_CONFIG;
    err_code = nrf_drv_timer_init(timer, &timer_cfg, timer_handler);

    time_ticks = nrf_drv_timer_us_to_ticks(timer, inteval_us);

    nrf_drv_timer_extended_compare(
         timer, NRF_TIMER_CC_CHANNEL0, time_ticks, NRF_TIMER_SHORT_COMPARE0_CLEAR_MASK, true);

    nrf_drv_timer_enable(timer);
	return err_code;
}

int ssz_virtual_uart_init(SszVirtualUart *virtual_uart, void *obj, VirtualUartSettings settings, uint8_t rx_pin, uint8_t tx_pin, 
                                  GpioEventhandler gpioe_handler, uint8_t *send_buff, uint16_t send_size, nrf_drv_timer_t timer, TimerEventHandler timer_handler)
{
	uint32_t interval_us;
	//init gpio
	ERT_drv_gpio_set_dir_output(tx_pin);
	ERT_drv_gpio_output_set(tx_pin);

	virtual_uart->object = obj;
	virtual_uart->uart_settings = settings;
	virtual_uart->rxd_pin = rx_pin;
	virtual_uart->txd_pin = tx_pin;

	
	//rx
	virtual_uart->receive_bit_count = 0;
	virtual_uart->flag_receive_start_bit = 0;
	virtual_uart->flag_is_receiving = 0;
	virtual_uart->byte_data = 0;
	
	
	//send
	virtual_uart->send_bit_count = 0;
	virtual_uart->send_byte_data = 0xFF;
	virtual_uart->send_bit_size = M_get_uart_frame_len(virtual_uart);
	virtual_uart->flag_is_sending = 0;
	ssz_safe_queue_init(&virtual_uart->send_queue, send_buff, send_size, 1);

	//timer
	interval_us = 1000000 / virtual_uart->uart_settings.baud_rate;
	virtual_uart->timer = timer;
	ssz_timer_us_init(&virtual_uart->timer, interval_us, timer_handler);

	//default High is invaid
	bsp_gpio_output_set(tx_pin);
	ssz_gpioe_set_pin(rx_pin, gpioe_handler);
	return 0;
}

//The use must place this function in the reverse event handler of rx pin
bool ssz_virtual_uart_on_start_bit_event(SszVirtualUart *virtual_uart)
{
	bool result = false;

	if((virtual_uart->receive_bit_count == 0)
		&&(virtual_uart->flag_receive_start_bit == false)
		&& (virtual_uart->flag_is_receiving == false))
	{
		virtual_uart->flag_receive_start_bit = true;
		virtual_uart->receive_bit_count = 0;
		virtual_uart->byte_data = 0;
		virtual_uart->flag_is_receiving = true;
		result = true;
	}

	return result;
}

void ssz_virtual_uart_stop(SszVirtualUart *virtual_uart)
{
	virtual_uart->flag_is_receiving = false;
	virtual_uart->flag_receive_start_bit = false;
	virtual_uart->receive_bit_count = 0;
}

bool ssz_virtual_uart_rxd_is_high(SszVirtualUart *virtual_uart)
{
	return bsp_gpio_input_is_high(virtual_uart->rxd_pin);
}

//The use must place it at timer interrupt
bool ssz_virtual_uart_on_receive_byte(SszVirtualUart *virtual_uart, uint8_t *byte)
{
	bool is_receive_byte_ok = false;

	if(virtual_uart->flag_receive_start_bit != true)
		return false;
	//data area, 8 bit
	virtual_uart->receive_bit_count++;
	if(virtual_uart->receive_bit_count <= M_get_uart_frame_len(virtual_uart)-1)
	{
	
		if(ssz_virtual_uart_rxd_is_high(virtual_uart))
		{
			virtual_uart->byte_data |= 0x80;
		}
		virtual_uart->byte_data >>= 0x01;	
	}
	else 
	{
	  	//¸ßµãÆÁ½éËØ
		ssz_virtual_uart_stop(virtual_uart);
		*byte = virtual_uart->byte_data;
		virtual_uart->byte_data = 0xFF;
		is_receive_byte_ok = true;
	}

	return is_receive_byte_ok;
}



void ssz_virtual_uart_send_start_bit(SszVirtualUart * virtual_uart)
{
	bsp_gpio_output_clear(virtual_uart->txd_pin);
	virtual_uart->flag_is_sending = true;
}

void ssz_virtual_uart_send_stop_bit(SszVirtualUart * virtual_uart)
{
	bsp_gpio_output_set(virtual_uart->txd_pin);
	virtual_uart->flag_is_sending = false;
}

bool ssz_virtual_uart_is_sending(SszVirtualUart * virtual_uart)
{
	return virtual_uart->flag_is_sending;
}

bool ssz_virtual_is_need_send(SszVirtualUart * virtual_uart)
{
	return (ssz_safe_queue_is_empty(&virtual_uart->send_queue)?0:1);
}

uint8_t ssz_virtual_uart_get_send_data_from_queue(SszVirtualUart * virtual_uart)
{
	uint8_t data = *(uint8_t *)ssz_safe_queue_front(&virtual_uart->send_queue);
	ssz_safe_queue_pop_front(&virtual_uart->send_queue);
	return data;
}

//must placed this function at timer intrrupt
bool ssz_virtual_uart_on_send_byte(SszVirtualUart * virtual_uart)
{
	uint8_t bit;

	
	ssz_assert(virtual_uart);

	if(virtual_uart->send_bit_count == 0)
	{
		if(!ssz_virtual_is_need_send(virtual_uart))
		{
			return 0;
		}
		//start bit
		ssz_virtual_uart_send_start_bit(virtual_uart);
		//get send byte data
		virtual_uart->send_byte_data = ssz_virtual_uart_get_send_data_from_queue(virtual_uart);
		virtual_uart->send_bit_count += 1;
	}
	else if(virtual_uart->send_bit_count <= M_get_uart_frame_len(virtual_uart)-1)
	{
		bit = virtual_uart->send_byte_data&0x01;
		if(bit == 0x01)
		{
			bsp_gpio_output_set(virtual_uart->txd_pin);
		}
		else
		{
			bsp_gpio_output_clear(virtual_uart->txd_pin);
		}
		virtual_uart->send_byte_data >>= 0x01;
		virtual_uart->send_bit_count += 1;
	}
	else 
	{
		//stop bit
		ssz_virtual_uart_send_stop_bit(virtual_uart);
		virtual_uart->send_bit_count = 0;
	}

	return virtual_uart->flag_is_sending;
}

int ssz_virtual_uart_on_send(SszVirtualUart * virtual_uart, uint8_t *buff, int buff_size)
{
	int real_size;
	for(int i=0; i<buff_size; i++)
	{
		real_size = ssz_safe_queue_push_back(&virtual_uart->send_queue, &buff[i]);
	}
	return real_size; 
}












