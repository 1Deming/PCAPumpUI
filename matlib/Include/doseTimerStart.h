#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define doseTimerStart(ptrData)    ert_doseTimerStart(ptrData)
    #include "ert_doseTimerStart.h"
#else
    #define doseTimerStart(ptrData)    sim_doseTimerStart(ptrData)
    
    void sim_doseTimerStart(uint32_T data);
#endif
