#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define channelsADC(ptrData1,ptrData2,ptrData3,ptrData4,ptrData5)    ert_ChannelsADC(ptrData1,ptrData2,ptrData3,ptrData4,ptrData5)
    #ifdef ERT_MAJOR
        #include "ert_channelsADC_major.h"
    #else
        #include "ert_channelsADC_minor.h"
    #endif
#else
    #define channelsADC(ptrData1,ptrData2,ptrData3,ptrData4,ptrData5)    sim_channelsADC(ptrData1,ptrData2,ptrData3,ptrData4,ptrData5)
    void sim_channelsADC(boolean_T Switch,int16_T* Ch1ADC,int16_T* Ch2ADC,int16_T* Ch3ADC,int16_T* Ch4ADC);
#endif
