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
#include "app_scr_error_22000.h"
#include <stdio.h>
#include "ssz_common.h"
#include "widget_text.h"
#include "widget_image.h"


/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0     				  (GUI_ID_USER + 0x00)

#define SYSTEM_ALARM_ID_IMG_ALARM	      (GUI_ID_USER + 0x01)	
#define SYSTEM_ALARM_ID_STR_ALARM	      (GUI_ID_USER + 0x02)




/*********************************************************************
*
*       Static data
*
***********************************************************************/

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "app_scr_error_22000", ID_WINDOW_0, 0, 0, 256, 64, 0, 0x0, 0 },

};

/*********************************************************************
*
*       Static code
*
***********************************************************************/

static void  put_error(uint8_t alarm_code)
{
	WM_HWIN  hWin;
	char *p;

	hWin = WM_GetDialogItem(ui_get_current_hwin(), SYSTEM_ALARM_ID_STR_ALARM);
	p = get_dynamic_string(kStrDynamic1);
	strcpy(p, get_string(kStrSystemError));
	strcat(p, ", E");
	sprintf(p + strlen(p), "%02d", alarm_code);
	TEXT_SetText(hWin, p);
}


static void _cbDialog(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin;
	
	switch (pMsg->MsgId) 
	{
		case WM_INIT_DIALOG:
			WINDOW_SetBkColor(pMsg->hWin, GUI_BLACK);

			//alarm string
			hWin = TEXT_CreateEx(36+16, (DISPLAY_HEIGHT -16)/2, DISPLAY_WIDTH - 2*(36+16), 16, pMsg->hWin, 
				                 WM_CF_SHOW, GUI_TA_VCENTER|GUI_TA_HCENTER,  SYSTEM_ALARM_ID_STR_ALARM, "");
			TEXT_SetFont(hWin, get_font(14));
			TEXT_SetBkColor(hWin, GUI_BLACK);
			TEXT_SetTextColor(hWin, GUI_WHITE);
			
			//alarm image
			hWin = IMAGE_CreateEx(16, 12, 36, 36, pMsg->hWin, WM_CF_SHOW,  IMAGE_CF_AUTOSIZE, SYSTEM_ALARM_ID_IMG_ALARM);
			IMAGE_SetBitmap(hWin, get_image(kImgWarningCommon));


			break;
	
		case WM_PAINT:

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
WM_HWIN app_scr_error_22000_create(type_MsgBody4UICtrlMsg *msg) 
{
	WM_HWIN hWin;

	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	
	return hWin;
}


int app_scr_error_22000_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg)
{
//	switch(msg->OpMethod)
//	{
//		case SCR_CURSER_MOVE:
//			put_error(msg->ditem->DataValArray[0]);
//			break;
//
//		case SCR_VALUE_ALTER:
//			put_error(msg->ditem->DataValArray[0]);
//			break;
//		default:
//			break;
//	}
 	return 0;	
}

void app_scr_error_22000_destroy(WM_HWIN win_id) 
{
	GUI_EndDialog(win_id, 0);
}


/*************************** End of file ****************************/
