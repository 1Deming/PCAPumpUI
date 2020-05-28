/************************************************
 * DESCRIPTION:
 *
 * 	route for screen show
 *
 ************************************************/
#pragma once

#include "ssz_def.h"
#include "GUI.h"
#include "ui_common.h"

/************************************************
 * Declaration
 ************************************************/


#ifdef __cplusplus
extern "C" {
#endif

typedef WM_HWIN (*ScreenCreateFunc)(type_MsgBody4UICtrlMsg *);
typedef int (*ScreenUpdateFunc)(WM_HWIN , type_MsgBody4UICtrlMsg *);
typedef void (*ScrennDestroyFunc)(WM_HWIN);

typedef struct {
	uint8_t screen_id[5];
	ScreenCreateFunc create_func;
	ScreenUpdateFunc update_fun;
	ScrennDestroyFunc destroy_fun;
} ScreenInfo;


extern const ScreenInfo g_scr_routes[35];

void ert_uiDisp(uint8_t UIOpCode, type_MsgBody4UICtrlMsg *UIDispData);


#ifdef __cplusplus
}
#endif














