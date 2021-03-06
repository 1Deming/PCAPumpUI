/************************************************
* DESCRIPTION:
*   
************************************************/
#pragma once

#include "ssz_def.h"
#include "GUI.h"
#include "WM.h"
#include "ui_utility.h"
/************************************************
* Declaration
************************************************/

//opcode
#define SCR_CREATE			1
#define SCR_CURSER_MOVE		2
#define SCR_VALUE_ALTER		3
	
#define WM_MSG_CURSOR_MOVE		(WM_USER + 0)
#define WM_MSG_VALUE_ALTER		(WM_USER + 1)

#define UD_CHILD_MAX		5


#define DATA_MODE_NORMOL	0
#define DATA_MODE_SELECT	1
#define DATA_MODE_MODIFY	2


typedef struct
{
	WM_HWIN win_id;
	uint8_t last_cursor;
	uint8_t cur_cursor; 
	uint8_t opcode;
	uint8_t uiid[5];
	uint8_t flag_upate_once;
	WM_HWIN child_id[UD_CHILD_MAX];
}UI_ScreenCommon;
	

extern UI_ScreenCommon g_ui_common_param;




#ifdef __cplusplus
extern "C" {
#endif

void ui_set_init_once_flag(void);
void ui_clear_init_once_flag(void);
uint8_t ui_is_set_once_flag(void);
void ui_set_cursor_index(uint8_t cursor_index);
bool ui_is_current_cursor_index(uint8_t cursor_index);
WM_HWIN ui_get_child_hwin(uint8_t child_index);
void ui_set_child_hwin(uint8_t child_index, WM_HWIN hwin);




#ifdef __cplusplus
}
#endif

