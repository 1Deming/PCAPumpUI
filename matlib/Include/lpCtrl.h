#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define lpCtrl(ptrData1,ptrData2)    ert_lpCtrl(ptrData1,ptrData2)
    #ifdef ERT_MAJOR
        #include "ert_lpCtrl_major.h"
    #else
        #include "ert_lpCtrl_minor.h"
    #endif
#else
    #define lpCtrl(ptrData1,ptrData2)    sim_lpCtrl(ptrData1,ptrData2)
    boolean_T sim_lpCtrl(boolean_T data,uint32_T* sleepmSec);
#endif
