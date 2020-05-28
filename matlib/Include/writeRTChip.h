#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define writeRTChip(ptrData1)    ert_writeRTChip(ptrData1)
    #include "ert_writeRTChip.h"
#else
    #define writeRTChip(ptrData1)    sim_writeRTChip(ptrData1)
    boolean_T sim_writeRTChip(uint8_T* rtTime);
#endif

