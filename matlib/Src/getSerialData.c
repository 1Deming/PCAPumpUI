#include <stdio.h>
#include <stdlib.h>
#include "getSerialData.h"

boolean_T sim_getSerialData(uint8_T* data)
{
    for(uint8_T i=0;i<14;i++)
    *data++=i;
    return true;
}