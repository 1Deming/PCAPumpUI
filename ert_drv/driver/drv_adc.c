/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "drv_adc.h"
#include "bsp_adc.h"
#include "bsp_gpio.h"
#include "nrf_saadc.h"
#include "drv_common.h"

/************************************************
* Declaration
************************************************/

/************************************************
* Variable 
************************************************/

/************************************************
* Function 
************************************************/
int8_t ERT_drv_adc_init(void)
{
	uint32_t error_code;
	error_code = bsp_adc_init();
	return (int8_t)drv_common_get_error_code(error_code);
}

void ERT_drv_adc_deinit(void)
{
	bsp_adc_deinit();
}

void ERT_drv_adc_battery_current_enable(void)
{
	bsp_gpio_output_clear(BATTERY_CURRENT_AND_FLASH_EN_PIN_NUM);	
}

void ERT_drv_adc_battery_current_disable(void)
{
	bsp_gpio_output_set(BATTERY_CURRENT_AND_FLASH_EN_PIN_NUM);
}


static void drv_adc_config_ADC_channel(ADCChannelChoose channel)
{
	switch(channel)
	{
		case kBatteryVoltageADC:
			bsp_adc_channel_init(kBatteryVoltageADC, NRF_SAADC_INPUT_AIN1);
			break;
			
		case kMotorCurrentADC:
			ERT_drv_adc_battery_current_enable();
			bsp_adc_channel_init(kMotorCurrentADC, NRF_SAADC_INPUT_AIN5); 
			break;
		case kBatteryCurrentADC:
			bsp_adc_channel_init(kBatteryCurrentADC, NRF_SAADC_INPUT_AIN0); 
			break;
	}
}

int ERT_drv_adc_get_ADC_channel_value(ADCChannelChoose channel)
{
	uint16_t adc_value = 0;
	drv_adc_config_ADC_channel(channel);
	bsp_adc_sample_convert(channel, &adc_value);
	return adc_value;
}




int ERT_drv_adc_get_sys_pwr_adc(void)
{
	return ERT_drv_adc_get_ADC_channel_value(kBatteryVoltageADC);
}

int ERT_drv_adc_get_battery_current_adc(void)
{
	return ERT_drv_adc_get_ADC_channel_value(kBatteryCurrentADC);	
}

int ERT_drv_adc_get_motor_current_adc(void)
{
	return ERT_drv_adc_get_ADC_channel_value(kMotorCurrentADC);	
} 





ADCChannelChoose ERT_drv_adc_get_battery_voltage_adc_channel(void)
{
	return kBatteryVoltageADC;
}

ADCChannelChoose ERT_drv_adc_get_battery_current_adc_channel(void)
{
	
	return kBatteryCurrentADC;
}

ADCChannelChoose ERT_drv_adc_get_motor_current_adc_channel(void)
{
	return kMotorCurrentADC;
} 

void ERT_drv_adc_battery_current_disable_or_enable(uint8_t flag)
{
	if(flag == 1)
	{
		ERT_drv_adc_battery_current_enable();
	}
	else if(flag == 0)
	{
		ERT_drv_adc_battery_current_disable();
	}
}


bool ERT_drv_adc_battery_current_switch_state(void)
{
	return bsp_gpio_output_is_high(BATTERY_CURRENT_AND_FLASH_EN_PIN_NUM);	
}




void ert_channelsADC(bool swtich, uint16_t *BattVolADC, uint16_t *BattCurADC, uint16_t *MotorCurADC)
{

	if(swtich == false)
	{
            *BattVolADC = 0;
	    *BattCurADC = 0;
        *MotorCurADC = 0;
	    return;
	}
	//get battvol adc
	*BattVolADC = ERT_drv_adc_get_ADC_channel_value(kBatteryVoltageADC);

	//get battCur adc
	ERT_drv_adc_battery_current_enable();
	*BattCurADC = ERT_drv_adc_get_ADC_channel_value(kBatteryCurrentADC);
	ERT_drv_adc_battery_current_disable();

	//get motor adc 
	*MotorCurADC = ERT_drv_adc_get_ADC_channel_value(kMotorCurrentADC);	

}




















