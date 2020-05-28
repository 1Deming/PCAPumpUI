/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "ert_channelsADC_Major.h"
#include "mid_adc.h"
/************************************************
* Declaration
************************************************/

/************************************************
* Variable 
************************************************/

/************************************************
* Function 
************************************************/



void ert_channelsADC(bool swtich, 
					uint16_t *SysPwrADC,
					uint16_t *PressureADC,
					uint16_t *SZDJCurrentADC,
					uint16_t *STFDJCurrentADC,
					uint16_t *SlaverMCUPwrADC)
{
	if(swtich == false)
	{
        *SysPwrADC = *PressureADC = *SZDJCurrentADC = *STFDJCurrentADC = 0;
		*SlaverMCUPwrADC = 0;
	    return;
	}

	*SysPwrADC = mid_adc_get_average_ADC_channel_value(kSysPwrADC);
    *PressureADC = mid_adc_get_average_ADC_channel_value(kPressureADC);
	*SZDJCurrentADC =  mid_adc_get_average_ADC_channel_value(kSZDJCurrentADC);
	*STFDJCurrentADC = mid_adc_get_average_ADC_channel_value(kSysPwrADC);
    *SlaverMCUPwrADC = mid_adc_get_average_ADC_channel_value(kPressureADC);
}


//kSysPwrADC,			  //系统电流检测
//kPressureADC, 		  //压力传感器
//kSZDJCurrentADC,		  //输注电机电流检测
//kSTFDJCurrentADC, 	  //三通阀电机电流检测
//kSlaverMCUPwrADC, 	  //从电源电压检测














