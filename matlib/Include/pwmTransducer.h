#pragma once
#include<rtwtypes.h>

#ifdef ERT
    #define pwmTrans(ptrData1,ptrData2,ptrData3,ptrData4)    ert_pwmTrans(ptrData1,ptrData2,ptrData3,ptrData4)
    #include "ert_pwmTrans.h"
#else
    #define pwmTrans(ptrData1,ptrData2,ptrData3,ptrData4)    sim_pwmTrans(ptrData1,ptrData2,ptrData3,ptrData4)
    
    void sim_pwmTrans(int16_T data,uint16_T fullscale,uint8_T* percent,boolean_T* direction);
#endif
