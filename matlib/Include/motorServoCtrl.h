#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define motorServoCtrl(ptrData1,ptrData2)    ert_motorServoCtrl(ptrData1,ptrData2)
    #include "ert_motorServoCtrl.h"
#else
    #define motorServoCtrl(ptrData1,ptrData2)    sim_motorServoCtrl(ptrData1,ptrData2)
    boolean_T sim_motorServoCtrl(int32_T targetEncCnt,boolean_T boolServoOn);
#endif

