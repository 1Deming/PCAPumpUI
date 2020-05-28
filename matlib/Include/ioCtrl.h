#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define ioCtrl(ptrData)    ert_ioCtrl(ptrData)
    #ifdef ERT_MAJOR
        #include "ert_ioCtrl_major.h"
    #else
        #include "ert_ioCtrl_minor.h"
    #endif
#else
    #define ioCtrl(ptrData)    sim_ioCtrl(ptrData)
    
    boolean_T sim_ioCtrl(boolean_T data);
#endif
