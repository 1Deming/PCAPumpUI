/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "drv_key_new.h"
#include "bsp_gpio.h"
#include "nordic_common.h"
#include "nrf.h"
#include "nrf_log.h"
#include "app_error.h"
#include "app_timer.h"

#include "nrf_gpio.h"
#include "nrf_gpiote.h"
#include "nrf_drv_gpiote.h"

#include "drv_common.h"


/************************************************
* Declaration
************************************************/
#define NRF_GPIOE_PIN_MAIN_NUM		1
#define NRF_GPIOE_PIN_PLUS_NUM		2
#define NRF_GPIOE_PIN_REDUE_NUM		3


/************************************************
* Variable 
************************************************/
static bool g_drv_key_state[kKeyIDMAX];

/************************************************
* Function 
************************************************/
static void key_pressed(keyID key_id)
{
	g_drv_key_state[key_id] = 1;
}

static void key_released(void)
{
	g_drv_key_state[key_id] = 0;
}

static void key_gpiote_event_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
	keyID key_id;
	uint32_t pin_num;
	switch(pin)
	{
		case NRF_GPIOE_PIN_MAIN_NUM:
			key_id = kKeyMain;
			break;

		case NRF_GPIOE_PIN_PLUS_NUM:
			key_id = kKeyPlus;
			break;

		case NRF_GPIOE_PIN_REDUE_NUM:
			key_id = kKeyRedue;
			break;
	}
	
	pin_num = (uint32_t)pin;

	if(acktion == NRF_GPIOTE_POLARITY_TOGGLE)
	{
		if (bsp_gpio_input_is_high(pin_num)){
				key_released(key_id);
			} else {
				key_pressed(key_id);
		}
	}
}

//目前硬件只有一个按键，所以只能初始化一个
int8_t ERT_drv_set_key_pin(keyID key_id)
{
    uint32_t err_code;

	switch(key_id)
	{
		case kKeyMain:
		    nrf_drv_gpiote_in_config_t config = NRFX_GPIOTE_CONFIG_IN_SENSE_TOGGLE(false);
		    config.sense = NRF_GPIOTE_POLARITY_TOGGLE;    
		    config.pull = NRF_GPIO_PIN_PULLUP;
		    err_code = nrf_drv_gpiote_in_init(KEY_PIN_NUM, &config, key_gpiote_event_handler);
		    //APP_ERROR_CHECK(err_code);
		    
		    nrf_drv_gpiote_in_event_enable(KEY_PIN_NUM, true);


			return (int8_t)drv_common_get_error_code(err_code);
			break;

		case kKeyPlus:

			break;

		case kKeyRedue:

			break;
	}

	return 0;
}


bool drv_get_key_status(keyID key_id)
{
	return g_drv_key_state;
}





















