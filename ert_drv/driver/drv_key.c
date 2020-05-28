/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "drv_key.h"
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
#include "ssz_common.h"


/************************************************
* Declaration
************************************************/


/************************************************
* Variable 
************************************************/
static bool g_drv_key_state;


/************************************************
* Function 
************************************************/
static void key_pressed(void)
{
	g_drv_key_state = 1;
}

static void key_released(void)
{
	g_drv_key_state = 0;
}

static void key_gpiote_event_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
	if(pin != KEY_PIN_NUM) return;
	

	switch(action)
	{
		case NRF_GPIOTE_POLARITY_LOTOHI:
			break;

		case NRF_GPIOTE_POLARITY_HITOLO:
			break;

		case NRF_GPIOTE_POLARITY_TOGGLE:
			if (bsp_gpio_input_is_high(KEY_PIN_NUM)){
				key_released();
			} else {
				key_pressed();
			}

			break;
	}

}

int8_t ERT_drv_set_key_pin(void)
{
    uint32_t err_code;
    nrf_drv_gpiote_in_config_t config = NRFX_GPIOTE_CONFIG_IN_SENSE_TOGGLE(false);
    //config.sense = NRF_GPIOTE_POLARITY_TOGGLE;
    config.pull = NRF_GPIO_PIN_PULLUP;
    err_code = nrf_drv_gpiote_in_init(KEY_PIN_NUM, &config, key_gpiote_event_handler);
    //APP_ERROR_CHECK(err_code);
    
    nrf_drv_gpiote_in_event_enable(KEY_PIN_NUM, true);

    return (int8_t)drv_common_get_error_code(err_code);
}


bool ERT_drv_get_key_state(void)
{
	return g_drv_key_state;
}


void ert_getKeyVector(uint8_t *data)
{
	data[0] = (uint8_t)ERT_drv_get_key_state();
	memset(&data[1], 0, 4);
}

















