/****************************************************
**接口规则
****************************************************/

1、所有对外提供的驱动的接口API的命名均已ERT开头（必须），后面可接模块名、功能(非必需)。
   例如：获取系统电压ADC值的接口命名为：ERT_Adc_GetSysPower().

2、底层驱动其他的函数不要以ERT开头。