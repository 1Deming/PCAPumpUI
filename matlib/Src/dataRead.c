#include <stdio.h>
#include <stdlib.h>
#include "dataRead.h"

boolean_T sim_dataRead(uint8_T x_majorId,uint8_T x_minorId,uint8_T x_channel,uint8_T* x_data,uint8_T x_size)
{
    for(uint8_T i=0;i<x_size;i++){
    /*x_data[i]=187;*/
    *(x_data++)=187+i;
    }
    return false;
}
