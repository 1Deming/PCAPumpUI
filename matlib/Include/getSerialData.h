#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define getSerialData(ptrData)    ert_getSerialData(ptrData)
    #ifdef ERT_MAJOR
        #include "ert_getSerialData_major.h"
    #else
        #include "ert_getSerialData_minor.h"
    #endif
#else
    #define getSerialData(ptrData)    sim_getSerialData(ptrData)
    
    boolean_T sim_getSerialData(uint8_T* data);
#endif
