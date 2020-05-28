#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define dataErase(ptrData1)    ert_dataErase(ptrData1)
    #include "ert_dataErase.h"
#else
    #define dataErase(ptrData1)    sim_dataErase(ptrData1)
    boolean_T sim_dataErase(uint8_T x_channel);
#endif

