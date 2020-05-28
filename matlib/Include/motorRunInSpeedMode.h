#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define motorRunInSpeedMode(ptrData1)    ert_motorRunInSpeedMode(ptrData1)
    #include "ert_motorRunInSpeedMode.h"
#else
    #define motorRunInSpeedMode(ptrData1)    sim_motorRunInSpeedMode(ptrData1)
    boolean_T sim_motorRunInSpeedMode(int8_T direction);
#endif

