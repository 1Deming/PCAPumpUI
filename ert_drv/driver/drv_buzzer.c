/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "drv_buzzer.h"
#include "bsp_buzzer_pwm.h"
#include "drv_common.h"
#include "bsp_gpio.h"

/************************************************
* Declaration
************************************************/

/************************************************
* Variable 
************************************************/

void ERT_drv_buzzer_power_on(void)
{
	bsp_gpio_output_set(M_BUZZER_PWR_PIN_NUM);
}

void ERT_drv_buzzer_power_off(void)
{
	bsp_gpio_output_clear(M_BUZZER_PWR_PIN_NUM);

}

void ERT_drv_buzzer_set_period(int period_in_us)
{
	bsp_buzzer_pwm_set_period(period_in_us);
}

void ERT_drv_buzzer_set_freq(int freq)
{
	int period_in_us = 1000000/freq;
	bsp_buzzer_pwm_set_period(period_in_us);
}

void ERT_drv_buzzer_set_duty(int duty_cycle)
{
	bsp_buzzer_pwm_set_duty(duty_cycle);
}

void ERT_drv_buzzer_deinit(){
	bsp_buzzer_pwm_deinit();
	ERT_drv_buzzer_power_off();
}

void drv_buzzer_enable(){
	bsp_buzzer_pwm_enable();
}

void drv_buzzer_disable(){
	bsp_buzzer_pwm_disable();
}


int8_t ERT_drv_buzzer_init(void)
{
	return (int8_t)drv_common_get_error_code(bsp_buzzer_pwm_init());
	ERT_drv_buzzer_power_on();
}

void ERT_drv_buzzer_action(bool flag)
{
	if(flag == true)
		bsp_buzzer_pwm_enable();
	else if(flag == false)
		bsp_buzzer_pwm_disable();
}


uint16_t ERT_drv_buzzer_get_duty_cycle(void)
{
	return bsp_buzzer_get_duty_cycle();
}




