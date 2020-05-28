/************************************************
 * DESCRIPTION:
 *
 * 	route for screen show
 *
 ************************************************/
#include "app_route.h"
#include "config.h"
#include "WM.h"
#include "ssz_common.h"
#include "app_scr_logo_01000.h"
#include "app_scr_main_menu_11000.h"
#include "app_scr_set_dose_12300.h"
#include "app_scr_unlock_password_12100.h"



/************************************************
 * Declaration
 ************************************************/



/************************************************
 * Variable
 ************************************************/
const ScreenInfo g_scr_routes[SCREEN_NUMBER_TOTAL]= {
 
    {{0,1,0,0,0}, app_logo_01000_create, app_logo_01000_update, app_logo_01000_destroy},  
	{{0,2,0,0,0}, app_main_menu_11000_create, app_main_menu_11000_update, app_main_menu_11000_destroy},
	{{1,2,3,0,0}, app_scr_set_dose_12300_create, app_scr_set_dose_12300_update, app_scr_set_dose_12300_destroy},
    {{1,2,1,0,0}, app_scr_unlock_password_12100_create, app_scr_unlock_password_12100_update, app_scr_unlock_password_12100_destroy},
    //{{1,1,2,0,0}, , , },
    
    //{{1,2,1,0,0}, , , },   
	//{{1,2,2,0,0}, , , },
	//{{1,2,3,0,0}, , , },
};


/************************************************
 * Function
 ************************************************/

void ert_uiDisp(uint8_t UIOpCode, type_MsgBody4UICtrlMsg *UIDispData)
{
  	int i;
	ScreenCreateFunc createfunc;
	ScreenUpdateFunc updatefun;
	ScrennDestroyFunc destroyfun;


	for (i = 0; i < ssz_array_size(g_scr_routes); i++) {
		if (memcmp(UIDispData->UIID, g_scr_routes[i].screen_id, 5) == 0) 
		{
			createfunc = g_scr_routes[i].create_func; 
			updatefun = g_scr_routes[i].update_fun;
			destroyfun = g_scr_routes[i].destroy_fun;
			break;
		}
	}

	if(i == ssz_array_size(g_scr_routes))
	{//no screen is finded
		return;
	}

	if(createfunc == NULL || updatefun== NULL || destroyfun==NULL)
	{//any api is null renturn
		return;
	}

	switch(UIOpCode)
	{
		case SCR_CREATE:
			if((memcmp(g_ui_common_param.uiid, UIDispData->UIID, sizeof(g_ui_common_param.uiid)) != 0))
			{
				if(g_ui_common_param.win_id != 0)
				{
					destroyfun(g_ui_common_param.win_id);	
				}
				g_ui_common_param.win_id = createfunc(UIDispData);
				memcpy(g_ui_common_param.uiid, UIDispData->UIID, 5);
				g_ui_common_param.opcode = UIDispData->OpMethod;
			}
			break;
		
		case SCR_CURSER_MOVE:	
		case SCR_VALUE_ALTER:
			if((memcmp(g_ui_common_param.uiid, UIDispData->UIID, sizeof(g_ui_common_param.uiid)) != 0))
			{
				if(g_ui_common_param.win_id != 0)
				{
					destroyfun(g_ui_common_param.win_id);	
				}
				g_ui_common_param.win_id = createfunc(UIDispData);
				memcpy(g_ui_common_param.uiid, UIDispData->UIID, 5);
			}
			
			updatefun(g_ui_common_param.win_id, UIDispData);
			g_ui_common_param.opcode = UIDispData->OpMethod;
			
			break;
		default:
			break;
	}

}






































