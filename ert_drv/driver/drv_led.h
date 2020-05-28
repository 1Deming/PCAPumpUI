/************************************************
* DESCRIPTION:
*
*
************************************************/
#pragma once

#include "ssz_def.h"
/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
	kLedRed,
	kLedBlue,
	kLedGreen,
	kLedIDMax,
}LedID;

void drv_led_on(LedID ledid);
void drv_led_off(LedID ledid);


//red led switch
#define ERT_drv_red_led_on()  drv_led_on(kLedRed)
#define ERT_drv_red_led_off() drv_led_off(kLedRed)


//blue led switch
#define ERT_drv_blue_led_on()  drv_led_on(kLedBlue)
#define ERT_drv_blue_led_off() drv_led_off(kLedBlue)

//green led switch
#define ERT_drv_green_led_on()  drv_led_on(kLedGreen)
#define ERT_drv_green_led_off() drv_led_off(kLedGreen)

void ERT_drv_flashing_led(LedID ledid, uint8_t duration, uint8_t interval); 

void ERT_drv_led_all_off(void);
void ERT_drv_led_three_long_two_short_start(void);
void ERT_drv_led_three_long_two_short_stop(void);
void ERT_drv_blue_red_alternate_start(void);
void ERT_drv_blue_red_alternate_stop(void);


#ifdef __cplusplus
}
#endif

