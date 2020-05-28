#pragma once
#include<rtwtypes.h>
#include"MsgBody4TaskStat.h"
#ifdef ERT
    #define dispUpdate(ptrData1,ptrData2)    ert_dispUpdate(ptrData1,ptrData2)
    #include "ert_dispUpdate.h"
#else
    #define dispUpdate(ptrData1,ptrData2)    sim_dispUpdate(ptrData1,ptrData2)    
    void sim_dispUpdate(uint8_T opCode,type_MsgBody4TaskStat* dispStruct);
#endif
