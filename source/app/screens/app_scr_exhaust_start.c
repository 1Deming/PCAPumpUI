/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.44                          *
*        Compiled Nov 10 2017, 08:53:57                              *
*        (c) 2017 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
***********************************************************************/


#include "DIALOG.h"
#include "GUI.h"
#include "ui_common.h"
#include "image_data.h"
#include "string_data.h"
#include "font_data.h"
#include <stdbool.h>
#include "app_scr_exhaust_start.h"
#include <stdio.h>
#include "ssz_common.h"


/*********************************************************************
*
*       Defines
*
***********************************************************************/
#define ID_WINDOW_0     (GUI_ID_USER + 0x00)



/*********************************************************************
*
*       Static data
***********************************************************************
*/

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "app_exhaust_start", ID_WINDOW_0, 0, 0, 256, 64, 0, 0x0, 0 },

};

/*********************************************************************
*
*       Static code
*
***********************************************************************/

static void _cbDialog(WM_MESSAGE * pMsg) 
{
	GUI_RECT rect;
	const char *ptr;
	uint8_t strlen;
	switch (pMsg->MsgId) 
	{
		case WM_INIT_DIALOG:
			WINDOW_SetBkColor(pMsg->hWin, GUI_BLACK);
			break;
	
		case WM_PAINT:
			GUI_SetColor(GUI_WHITE);
			GUI_SetFont(get_font(14));

			ptr = get_string(kStrNotice);
			strlen = GUI_GetStringDistX(ptr);
			
			
			ui_rect_init_by_size(rect, 0, 0, 256, 12);
			GUI_FillRectEx(&rect);
			GUI_SetTextMode(GUI_TM_REV);
			GUI_DispStringInRect(ptr, &rect, GUI_TA_HCENTER|GUI_TA_VCENTER);
			GUI_SetTextMode(GUI_TM_NORMAL);

			//ptr = get_string(kStrDoNotConnectBody);
			ptr = "Exhaust start";
			strlen = GUI_GetStringDistX(ptr);
			ui_rect_init_by_size(rect, (DISPLAY_WIDTH - strlen)/2, 16, strlen, 36);
			GUI_DispStringInRect(ptr, &rect, GUI_TA_LEFT|GUI_TA_VCENTER);
	
			ptr = get_string(kStrOk);
			strlen = GUI_GetStringDistX(ptr);
			ui_rect_init_by_size(rect, DISPLAY_WIDTH-strlen, DISPLAY_HEIGHT-16, strlen, 16);
			GUI_DispStringInRect(ptr, &rect, GUI_TA_RIGHT|GUI_TA_VCENTER);				

			break; 
			
		default:
			  WM_DefaultProc(pMsg);
			  break;
	}

}

/*********************************************************************
*
*       Public code
*
***********************************************************************/

WM_HWIN app_exhaust_start_create(type_MsgBody4UICtrlMsg *msg) 
{
	WM_HWIN hWin;	
	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}


int app_exhaust_start_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg)
{

 	return 0;	

}

void app_exhaust_start_destroy(WM_HWIN win_id) 
{
	GUI_EndDialog(win_id, 0);
}


/*************************** End of file ****************************/