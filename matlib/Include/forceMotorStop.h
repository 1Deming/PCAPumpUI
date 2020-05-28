#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define forceMotorStop(ptrData)    ert_forceMotorStop(ptrData)
    #include "ert_forceMotorStop.h"
#else
    #define forceMotorStop(ptrData)    sim_forceMotorStop(ptrData)
    
    boolean_T sim_forceMotorStop(boolean_T data);
#endif
