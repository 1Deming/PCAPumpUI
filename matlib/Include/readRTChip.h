#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define readRTChip(ptrData1)    ert_readRTChip(ptrData1)
    #include "ert_readRTChip.h"
#else
    #define readRTChip(ptrData1)    sim_readRTChip(ptrData1)
    boolean_T sim_readRTChip(uint8_T* rtTime);
#endif

