#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define dataWrite(ptrData1,ptrData2,ptrData3,ptrData4,ptrData5)    ert_dataWrite(ptrData1,ptrData2,ptrData3,ptrData4,ptrData5)
    #include "ert_dataWrite.h"
#else
    #define dataWrite(ptrData1,ptrData2,ptrData3,ptrData4,ptrData5)    sim_dataWrite(ptrData1,ptrData2,ptrData3,ptrData4,ptrData5)
    boolean_T sim_dataWrite(uint8_T x_majorId,uint8_T x_minorId,uint8_T* x_data,uint8_T x_size,uint8_T x_channel);
#endif