/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "drv_wdt.h"
#include "bsp_wdt.h"
#include "nrf_power.h"
#include "drv_common.h"

/************************************************
* Declaration
************************************************/
#define TIME_FEED_WDT_DEFAULT	5000    //default feed dog time 5s


/************************************************
* Variable 
************************************************/



/************************************************
* Function 
************************************************/
int8_t ERT_drv_wdt_init(int feed_time_in_ms)
{
	return (int8_t)drv_common_get_error_code(bsp_wdt_init(feed_time_in_ms));
}

void ERT_drv_feed_wdt(void)
{
	bsp_wdt_feed_wdt();
}

bool ERT_drv_system_reset_by_wdt(void)
{
	bool result = false;
	
	if(NRF_POWER_RESETREAS_DOG_MASK == nrf_power_resetreas_get()){
		result = true;
	}

	return result;
}










