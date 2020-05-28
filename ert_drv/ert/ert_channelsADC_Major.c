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


//kSysPwrADC,			  //ϵͳ�������
//kPressureADC, 		  //ѹ��������
//kSZDJCurrentADC,		  //��ע����������
//kSTFDJCurrentADC, 	  //��ͨ������������
//kSlaverMCUPwrADC, 	  //�ӵ�Դ��ѹ���














