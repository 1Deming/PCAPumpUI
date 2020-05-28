#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define dataRead(ptrData1,ptrData2,ptrData3,ptrData4,ptrData5)    ert_dataRead(ptrData1,ptrData2,ptrData3,ptrData4,ptrData5)
    #include "ert_dataRead.h"
#else
    #define dataRead(ptrData1,ptrData2,ptrData3,ptrData4,ptrData5)    sim_dataRead(ptrData1,ptrData2,ptrData3,ptrData4,ptrData5)
    boolean_T sim_dataRead(uint8_T x_majorId,uint8_T x_minorId,uint8_T x_channel,uint8_T* x_data,uint8_T x_size);
#endif

