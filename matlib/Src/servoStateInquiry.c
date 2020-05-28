#include <stdio.h>
#include <stdlib.h>
#include "servoStateInquiry.h"
void sim_servoStateInquiry(boolean_T* ServoState)
{
    *ServoState=true;
    //true means encoder interrupt has not yet been generated.
    //false means encoder interrupt has been generated.
}