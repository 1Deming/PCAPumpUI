#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define lcdCtrl(ptrData)    ert_lcdCtrl(ptrData)
    #ifdef ERT_MAJOR
        #include "ert_lcdCtrl_major.h"
    #else
        #include "ert_lcdCtrl_minor.h"
    #endif
#else
    #define lcdCtrl(ptrData)    sim_lcdCtrl(ptrData)
    
    boolean_T sim_ioCtrl(boolean_T data);
#endif
