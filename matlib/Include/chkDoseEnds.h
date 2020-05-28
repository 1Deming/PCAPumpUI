#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define chkDoseEnds(ptrData)    ert_chkDoseEnds(ptrData)
    #include "ert_chkDoseEnds.h"
#else
    #define chkDoseEnds(ptrData)    sim_chkDoseEnds(ptrData)
    void sim_chkDoseEnds(uint32_T* doseTimer);
#endif
 