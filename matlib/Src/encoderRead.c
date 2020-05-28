#include <stdio.h>
#include <stdlib.h>
#include "encoderRead.h"

int32_T sim_encoderRead(boolean_T data)
{
    if(data==true)       //read the real value of encoder register
            return 50000;
    else                //clear the encoder register
            return 0;
}