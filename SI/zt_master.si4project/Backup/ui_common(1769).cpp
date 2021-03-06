/************************************************
* DESCRIPTION:
*   
************************************************/
#include "ui_common.h"



/************************************************
* Declaration
************************************************/


/************************************************
* Variable 
************************************************/
UI_ScreenCommon g_ui_common_param;


/************************************************
* Function 
************************************************/
void ui_set_init_once_flag(void)
{
	g_ui_common_param.flag_upate_once = 1;
}


void ui_clear_init_once_flag(void)
{
	g_ui_common_param.flag_upate_once = 0;
}

uint8_t ui_is_set_once_flag(void)
{
	return g_ui_common_param.flag_upate_once;
}


bool ui_is_current_cursor_index(uint8_t cursor_index)
{
	return (cursor_index == g_ui_common_param.cur_cursor)? 1:0;
}

void ui_set_cursor_index(uint8_t cursor_index)
{
	if(cursor_index != g_ui_common_param.cur_cursor)
	{
		g_ui_common_param.last_cursor = g_ui_common_param.cur_cursor;
		g_ui_common_param.cur_cursor = cursor_index;
	}
}



