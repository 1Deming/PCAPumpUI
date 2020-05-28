#include <stdio.h>
#include <stdlib.h>
#include "getKeyVector.h"

void sim_getKeyVector(boolean_T* data)
{
    boolean_T x=false;
    for(uint8_T i=0;i<5;i++){
        x=!x;
        *data++=x;
    }
}