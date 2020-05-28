#pragma once
#include<rtwtypes.h>

#ifdef ERT
    #define sendBleData(ptrData)    ert_sendBleData(ptrData)
    #include "ert_sendBleData.h"
#else
    #define sendBleData(ptrData)    sim_sendBleData(ptrData)
 
    void sim_sendBleData(uint8_T* data);
#endif
