/************************************************
* DESCRIPTION:
*
*
************************************************/
#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>


/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif

int8_t ERT_drv_buzzer_init(void);  //1#
void ERT_drv_buzzer_set_period(int period_in_us);
void ERT_drv_buzzer_set_freq(int freq);
void ERT_drv_buzzer_set_duty(int duty_cycle);
void ERT_drv_buzzer_action(bool flag);
uint16_t ERT_drv_buzzer_get_duty_cycle(void);

void drv_buzzer_enable(void);//2#
void drv_buzzer_disable(void);//3#

void ERT_drv_buzzer_power_off(void);
void ERT_drv_buzzer_power_on(void);



#ifdef __cplusplus
}
#endif

