#pragma once
#include<rtwtypes.h>

#ifdef ERT
    #define sendSerialData(ptrData)    ert_sendSerialData(ptrData)
    #ifdef ERT_MAJOR
        #include "ert_sendSerialData_major.h"
    #else
        #include "ert_sendSerialData_minor.h"
    #endif
#else
    #define sendSerialData(ptrData)    sim_sendSerialData(ptrData)  
    void sim_sendSerialData(uint8_T* data);
#endif
