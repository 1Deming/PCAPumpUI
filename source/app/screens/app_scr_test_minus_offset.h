/************************************************
* DESCRIPTION:
*
*
************************************************/
#pragma once

#include "ssz_def.h"
#include "uiDisp.h"
/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif

WM_HWIN app_scr_test_minus_offset_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_test_minus_offset_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_test_minus_offset_destroy(WM_HWIN win_id);





#ifdef __cplusplus
}
#endif

