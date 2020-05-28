#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define servoStateInquiry(ptrData1)    ert_servoStateInquiry(ptrData1)
    #include "ert_servoStateInquiry.h"
#else
    #define servoStateInquiry(ptrData1)    sim_servoStateInquiry(ptrData1)
    void sim_servoStateInquiry(boolean_T* ServoState);
#endif

