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




