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


WM_HWIN app_scr_stop_infusion_13100_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_stop_infusion_13100_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_stop_infusion_13100_destroy(WM_HWIN win_id); 



#ifdef __cplusplus
}
#endif

