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
**********************************************************************
*/
#include "DIALOG.h"
#include "GUI.h"
#include "ui_common.h"
#include "image_data.h"
#include "string_data.h"
#include "font_data.h"
#include <stdbool.h>
#include "app_scr_set_year_14130.h"
#include <stdio.h>


/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0         (GUI_ID_USER + 0x00)
#define YEAR_ID				(GUI_ID_USER + 0x01)



/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "app_scr_set_year_14130", ID_WINDOW_0, 0, 0, 256, 64, 0, 0x0, 0 },

};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

static void put_set_year(uint8_t year)
{
	char buff[6];
	uint32_t y = year +2000;

	sprintf(buff, "%d", y);
	
	TEXT_SetText(WM_GetDialogItem(ui_get_current_hwin(), YEAR_ID), buff);
}


static void _cbDialog(WM_MESSAGE * pMsg)
{
	uint8_t strlen;
	GUI_RECT rect; 
	const char *ptr;
	WM_HWIN hWin;
	
	switch (pMsg->MsgId) 
	{
		case WM_INIT_DIALOG:
			WINDOW_SetBkColor(pMsg->hWin, GUI_BLACK);

			GUI_SetFont(get_font(14));
			ptr = get_string(kStrReturn);
			strlen = GUI_GetStringDistX(ptr);
			//yes
			hWin = TEXT_CreateEx(strlen, 16, DISPLAY_WIDTH - 2*strlen, DISPLAY_HEIGHT-16, pMsg->hWin, 
				                 WM_CF_SHOW, GUI_TA_VCENTER|GUI_TA_HCENTER,  YEAR_ID, "2019");
			TEXT_SetFont(hWin, get_font(60));
			TEXT_SetBkColor(hWin, GUI_BLACK);
			TEXT_SetTextColor(hWin,  GUI_WHITE);
			break;
	
		case WM_PAINT:
			GUI_SetColor(GUI_WHITE);

			GUI_SetFont(get_font(14));
				
			ptr = get_string(kStrSetYear);
			strlen = GUI_GetStringDistX(ptr);
			ui_rect_init_by_size(rect, 0, 0, strlen, 12);
			GUI_DispStringInRect(ptr, &rect, GUI_TA_LEFT|GUI_TA_VCENTER);

			ptr = get_string(kStrReturn);
			strlen = GUI_GetStringDistX(ptr);
			ui_rect_init_by_size(rect, 0, DISPLAY_HEIGHT-16, strlen, 16);
			GUI_DispStringInRect(ptr, &rect, GUI_TA_LEFT|GUI_TA_VCENTER);

			ptr = get_string(kStrConfirm);
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
**********************************************************************
*/
WM_HWIN app_scr_set_year_14130_create(type_MsgBody4UICtrlMsg *msg) 
{
	WM_HWIN hWin;	
	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}


int app_scr_set_year_14130_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg)
{
//	switch(msg->OpMethod)
//	{
//		case SCR_CURSER_MOVE:
//			put_set_year(msg->CursorIndex);
//			break;
//
//		case SCR_VALUE_ALTER:
//			put_set_year(msg->DItem[0]);
//			break;
//
//		default:
//			break;
//	}

 	return 0;	
}

void app_scr_set_year_14130_destroy(WM_HWIN win_id) 
{
	GUI_EndDialog(win_id, 0);
}

/*************************** End of file ****************************/
