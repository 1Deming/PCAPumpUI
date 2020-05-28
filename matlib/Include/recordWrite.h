#pragma once
#include<rtwtypes.h>

#ifndef DEFINED_TYPEDEF_FOR_type_RT_
#define DEFINED_TYPEDEF_FOR_type_RT_

typedef struct {
  /* the year just keeps the last three digits for its value here, for example, year 2019 just keeps 019 for its value */
  uint8_T Time[6];
} type_RT;

#endif

#ifdef ERT
    #define recordWrite(ptrData1,ptrData2,ptrData3,ptrData4,ptrData5)    ert_recordWrite(ptrData1,ptrData2,ptrData3,ptrData4,ptrData5)
    #include "ert_recordWrite.h"
#else
    #define recordWrite(ptrData1,ptrData2,ptrData3,ptrData4,ptrData5)    sim_recordWrite(ptrData1,ptrData2,ptrData3,ptrData4,ptrData5)
    boolean_T sim_recordWrite(type_RT* ptrRT,uint8_T x_majorId,uint8_T x_minorId,uint8_T* x_data,uint8_T x_channel);
#endif

