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


/************************************************
 * Declaration
 ************************************************/

/************************************************
 * Variable
 ************************************************/
const ScreenInfo g_scr_routes[35] = {
  /*
    {{0,1,0,0,0}, , , },   
	{{0,2,0,0,0}, , , },
	{{1,1,0,0,0}, , , },
    {{1,1,1,0,0}, , , },
    {{1,1,2,0,0}, , , },
    
    {{1,2,1,0,0}, , , },   
	{{1,2,2,0,0}, , , },
	{{1,2,3,0,0}, , , },
*/
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






































