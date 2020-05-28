#include <stdio.h>
#include <stdlib.h>
#include "channelsADC.h"

void sim_channelsADC(boolean_T Switch,int16_T* Ch1ADC,int16_T* Ch2ADC,int16_T* Ch3ADC,int16_T* Ch4ADC)
{
   *Ch1ADC=(Switch)?3000:0;
   *Ch2ADC=(Switch)?4000:0;
   *Ch3ADC=(Switch)?5000:0;
   *Ch4ADC=(Switch)?5000:0;
}