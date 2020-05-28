#include <stdio.h>
#include <stdlib.h>
#include "readRTChip.h"
boolean_T sim_readRTChip(uint8_T* rtTime)
{    
    *(rtTime)= (uint8_T)101;
    *(rtTime+1)= (uint8_T)102;
    *(rtTime+2)= (uint8_T)103;
    *(rtTime+3)= (uint8_T)104;
    *(rtTime+4)= (uint8_T)105;
    *(rtTime+5)= (uint8_T)106;
    return true;
}