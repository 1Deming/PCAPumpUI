#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define getBleData(ptrData)    ert_getBleData(ptrData)
    #include "ert_getBleData.h"
#else
    #define getBleData(ptrData)    sim_getBleData(ptrData)    
    boolean_T sim_getBleData(uint8_T* data);
#endif
