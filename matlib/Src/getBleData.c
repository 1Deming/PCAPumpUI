#include <stdio.h>
#include <stdlib.h>
#include "getBleData.h"

boolean_T sim_getBleData(uint8_T* data)
{
    for(uint8_T i=0;i<224;i++)
    *data++=i;
    return true;
}