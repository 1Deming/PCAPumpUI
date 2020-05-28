#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define getKeyVector(ptrData)    ert_getKeyVector(ptrData)
    #include "ert_getKeyVector.h"
#else
    #define getKeyVector(ptrData)    sim_getKeyVector(ptrData)
    
    void sim_getKeyVector(boolean_T* data);
#endif
