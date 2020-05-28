#include <stdio.h>
#include <stdlib.h>
#include "pwmTransducer.h"

void sim_pwmTrans(int16_T data,uint16_T fullscale,uint8_T* percent,boolean_T* direction)
{
   uint8_T pwm_percent=(data>0)?(data*100/fullscale):(-data*100/fullscale);
   *percent=pwm_percent;
   *direction=(data>0)?true:false;
}