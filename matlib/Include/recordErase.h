#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define recordErase(ptrData1,ptrData2)    ert_recordErase(ptrData1,ptrData2)
    #include "ert_recordErase.h"
#else
    #define recordErase(ptrData1,ptrData2)    sim_recordErase(ptrData1,ptrData2)
    boolean_T sim_recordErase(uint8_T x_majorId,uint8_T x_channel);
#endif

