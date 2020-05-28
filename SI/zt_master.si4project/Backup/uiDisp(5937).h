#pragma once
#include<rtwtypes.h>

#ifndef DEFINED_TYPEDEF_FOR_Type_MsgBody4UICtrlMsg_
#define DEFINED_TYPEDEF_FOR_Type_MsgBody4UICtrlMsg_

typedef struct {
  uint8_T UIID[5];
  uint8_T OpMethod;
  uint8_T SItem;
  uint8_T DItem[4];
  uint8_T CursorIndex;
  uint8_T Reserved;
} Type_MsgBody4UICtrlMsg;

typedef Type_MsgBody4UICtrlMsg type_MsgBody4UICtrlMsg;

#endif

#ifdef ERT
    #define uiDisp(ptrData1,ptrData2)    ert_uiDisp(ptrData1,ptrData2)
    #include "ert_uiDisp.h"
#else
    #define uiDisp(ptrData1,ptrData2)    sim_uiDisp(ptrData1,ptrData2)  
    void sim_uiDisp(uint8_T UIOpCode, Type_MsgBody4UICtrlMsg* UIDispData);
#endif