#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define alarmIt(ptrData1,ptrData2)    ert_alarmIt(ptrData1,ptrData2)
    #include "ert_alarmIt.h"
#else
    #define alarmIt(ptrData1,ptrData2)    sim_alarmIt(ptrData1,ptrData2)
    void sim_alarmIt(uint8_T alarmLevel,boolean_T boolMaster);
#endif

