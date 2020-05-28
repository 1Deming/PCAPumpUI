/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "drv_reset.h"
#include "bsp_gpio.h"
#include "nordic_common.h"
#include "nrf.h"
#include "nrf_log.h"
#include "app_error.h"
#include "app_timer.h"

#include "nrf_gpio.h"
#include "nrf_gpiote.h"
#include "nrf_drv_gpiote.h"
#include "nrf_delay.h"

#include "bsp_gpio.h"


/************************************************
* Declaration
************************************************/

/************************************************
* Variable 
************************************************/

/************************************************
* Function 
************************************************/
void ERT_drv_reset_slaver(void)
{
	bsp_gpio_output_set(SLAVER_NRST_PIN_NUM);
	nrf_delay_ms(100);
	bsp_gpio_output_clear(SLAVER_NRST_PIN_NUM);
	nrf_delay_ms(100);	
}

void ERT_drv_reset_slaver_enable(void)
{
	bsp_gpio_output_clear(SLAVER_NRST_PIN_NUM);
}

void ERT_drv_reset_slaver_disbale(void)
{
	bsp_gpio_output_set(SLAVER_NRST_PIN_NUM);
}





















