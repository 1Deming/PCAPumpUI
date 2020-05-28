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


//adc channel
typedef enum
{
	kBatteryVoltageADC, 
	kBatteryCurrentADC,		
	kMotorCurrentADC,	  
	kADCChannelMax,
}ADCChannelChoose;

int8_t ERT_drv_adc_init(void);//1#
void ERT_drv_adc_deinit(void);

void ERT_drv_adc_battery_current_disable_or_enable(uint8_t flag);
bool ERT_drv_adc_battery_current_switch_state(void);

int ERT_drv_adc_get_ADC_channel_value(ADCChannelChoose channel);//2#

//ADCChannelChoose ERT_drv_adc_get_sys_pwr_adc_channel(void);
//ADCChannelChoose ERT_drv_adc_get_battery_current_adc_channel(void);
//ADCChannelChoose ERT_drv_adc_get_motor_current_adc_channel(void);

int ERT_drv_adc_get_sys_pwr_adc(void);//#
int ERT_drv_adc_get_battery_current_adc(void);//#
int ERT_drv_adc_get_motor_current_adc(void);//#




void ERT_drv_adc_battery_current_enable(void);
void ERT_drv_adc_battery_current_disable(void);


void ert_channelsADC(bool swtich, uint16_t *BattVolADC, uint16_t *BattCurADC, uint16_t *MotorCurADC);



//adc refer voltage(mV)
#define ADC_REF_VOLTAGE 3000 

//adc max digit code = 2^(adc's bits)
#define ADC_MAX_DIGIT_CODE 4095

//voltage dadio(real battery voltage/volatge get from mcu)
#define BATTERY_VOLTAGE_RADIO 2

//get real battery voltage(mV) from ADC value
#define ERT_get_battery_voltage_from_adc(adc_value) ((adc_value)*ADC_REF_VOLTAGE*BATTERY_VOLTAGE_RADIO /ADC_MAX_DIGIT_CODE)



#ifdef __cplusplus
}
#endif

