#include <stdio.h>
#include <stdlib.h>
#include "recordRead.h"

uint8_T sim_recordRead(uint8_T x_majorId,uint16_T* LogIDVector,uint8_T x_channel,uint8_T* x_data)
{
    for(int i=1;i<49;i++){
    *x_data++=i;
    }
    return 1;
   
}