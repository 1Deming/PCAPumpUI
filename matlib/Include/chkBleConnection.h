#pragma once
#include<rtwtypes.h>
#ifdef ERT
    #define chkBleConnection(ptrData)    ert_chkBleConnection(ptrData)
    #include "ert_chkBleConnection.h"
#else
    #define chkBleConnection(ptrData)    sim_chkBleConnection(ptrData)    
    boolean_T sim_chkBleConnection(boolean_T x_check);
#endif
