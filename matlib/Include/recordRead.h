#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define recordRead(ptrData1,ptrData2,ptrData3,ptrData4)    ert_recordRead(ptrData1,ptrData2,ptrData3,ptrData4)
    #include "ert_recordRead.h"
#else
    #define recordRead(ptrData1,ptrData2,ptrData3,ptrData4)    sim_recordRead(ptrData1,ptrData2,ptrData3,ptrData4)
    boolean_T sim_recordRead(uint8_T x_majorId,uint16_T* LogIDVector,uint8_T x_channel,uint8_T* x_data);
#endif

