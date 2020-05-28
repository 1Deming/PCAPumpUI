/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "drv_led.h"
#include "bsp_gpio.h"
#include "nordic_common.h"
#include "nrf.h"
#include "nrf_log.h"
#include "app_error.h"
#include "app_timer.h"

#include "nrf_gpio.h"
#include "nrf_gpiote.h"
#include "nrf_drv_gpiote.h"
#include "timer.h"



/************************************************
* Declaration
************************************************/
typedef struct
{
	LedID id;
	nrfx_gpiote_pin_t pin;
}LedInfo;

/************************************************
* Variable 
************************************************/
LedInfo g_len_info[kLedIDMax] =
{
	{kLedRed,  LED_RED_PIN_NUM},
	{kLedBlue, LED_BLUE_PIN_NUM},
	{kLedGreen, LED_GREEN_PIN_NUM},
};

uint8_t g_blue_red_led_flash_count;
bool g_ble_red_alternate;
/************************************************
* Function 
************************************************/
void drv_led_on(LedID ledid)
{
	nrfx_gpiote_pin_t pin_number;

	for(int i=0; i<kLedIDMax; i++)
	{
		if(ledid == g_len_info[i].id)
		{
			pin_number = g_len_info[i].pin;
			bsp_gpio_output_set(pin_number);
			break;
		}
	}
}

void drv_led_off(LedID ledid)
{
	nrfx_gpiote_pin_t pin_number;

	for(int i=0; i<kLedIDMax; i++)
	{
		if(ledid == g_len_info[i].id)
		{
			pin_number = g_len_info[i].pin;
			bsp_gpio_output_clear(pin_number);
			break;
		}
	}
}

void ERT_drv_led_all_off(void)
{
	drv_led_off(kLedRed);
	drv_led_off(kLedBlue);
	drv_led_off(kLedGreen);
}

void drv_led_blue3_red2(void)
{
	if(++g_blue_red_led_flash_count < 3)
	{
		drv_led_on(kLedBlue);
	}
	else if(g_blue_red_led_flash_count < 4)
	{
		drv_led_off(kLedBlue);
	}
	else if(g_blue_red_led_flash_count < 7)
	{
		drv_led_on(kLedBlue);
	}
	else if(g_blue_red_led_flash_count < 8)
	{
		drv_led_off(kLedBlue);
	}
	else if(g_blue_red_led_flash_count < 9)
	{
		drv_led_on(kLedBlue);
	}
	else if(g_blue_red_led_flash_count < 10)
	{
		drv_led_off(kLedBlue);
	}
	else if(g_blue_red_led_flash_count <12)
	{
		drv_led_on(kLedRed);
	}
	else if(g_blue_red_led_flash_count <14)
	{
		drv_led_off(kLedRed);
	}
	else if(g_blue_red_led_flash_count <16)
	{
		drv_led_on(kLedRed);
	}
	else if(g_blue_red_led_flash_count <18)
	{
		drv_led_off(kLedRed);
	}
	else if(g_blue_red_led_flash_count <30)
	{
		drv_led_off(kLedRed);
		drv_led_off(kLedBlue);
	}
	else
	{
		g_blue_red_led_flash_count = 0;
	}
}


void ERT_drv_led_three_long_two_short_start(void)
{
	g_blue_red_led_flash_count = 0;
	ERT_drv_led_all_off();
	timer_set_handler(kTimerLedBlueRed, drv_led_blue3_red2);
	timer_start_periodic_every(kTimerLedBlueRed, 100);
	drv_led_blue3_red2();
}


void ERT_drv_led_three_long_two_short_stop(void)
{
	timer_stop(kTimerLedBlueRed);
	drv_led_off(kLedRed);
	drv_led_off(kLedBlue);
	g_blue_red_led_flash_count = 0;
}


void drv_blue_red_alternate(void)
{
	if(g_ble_red_alternate == 0)
	{
		drv_led_on(kLedRed);
		drv_led_off(kLedBlue);
		g_ble_red_alternate =1;
	}
	else if(g_ble_red_alternate == 1)
	{
		drv_led_off(kLedRed);
		drv_led_on(kLedBlue);
		g_ble_red_alternate =0;
	}
}

void ERT_drv_blue_red_alternate_start(void)
{
	ERT_drv_led_all_off();
	timer_set_handler(kTimerLedAlternate, drv_blue_red_alternate);
	timer_start_periodic_every(kTimerLedAlternate, 1000);
	drv_blue_red_alternate();
}


void ERT_drv_blue_red_alternate_stop(void)
{
	timer_stop(kTimerLedAlternate);
	ERT_drv_led_all_off();
	g_blue_red_led_flash_count = 0;
}









