#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define encoderRead(ptrData)    ert_encoderRead(ptrData)
    #ifdef ERT_MAJOR
        #include "ert_encoderRead_major.h"
    #else
        #include "ert_encoderRead_minor.h"
    #endif
#else
    #define encoderRead(ptrData)    sim_encoderRead(ptrData)
    
    int32_T sim_encoderRead(boolean_T data);
#endif
