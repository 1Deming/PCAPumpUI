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


WM_HWIN app_init_screen_create(type_MsgBody4UICtrlMsg *msg); 	
int app_init_screen_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_init_screen_destroy(WM_HWIN win_id); 




#ifdef __cplusplus
}
#endif

