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
#include "app_scr_class16.h"
#include <stdio.h>


/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0         (GUI_ID_USER + 0x00)
#define SET_IMG_ID1     	(GUI_ID_USER + 0x01)
#define SET_IMG_ID2    		(GUI_ID_USER + 0x02)
#define SET_IMG_ID3     	(GUI_ID_USER + 0x03)
#define SET_IMG_ID4    		(GUI_ID_USER + 0x04)
#define TITLE_ID    		(GUI_ID_USER + 0x04)

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "app_scr_class16", ID_WINDOW_0, 0, 0, 256, 64, 0, 0x0, 0 },
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

static void put_menu_info(uint8_t cursor_index)
{
	const GUI_BITMAP *pbm;
	const char *pstr;
	int x;
	
	switch(cursor_index)
	{
		case 0://exhaust
		{
			pbm = get_image(kImgExhaust);
			pstr = get_string(kStrClearAir);
			break;
		}

		case 1://BKGD
		{
			pbm = get_image(kImgNewTask);
			//pstr = get_string(kStrNewInfusionTask);
			pstr =  "BKGD" ;
			break;
		}

		case 2://PCA
		{
			pbm = get_image(kImgStopInfusion);
			//pstr = get_string(kStrStopInfusion);
			pstr =  "PCA" ;
			break;
		}
		case 3://autoCycle
		{
			pbm = get_image(kImgHistoryLog);
			//pstr = get_string(kStrHistoryLog);
			pstr =  "autoCycle" ;
			break;
		}
		case 4://sysytem setting
		{
			pbm = get_image(kImgSystemSetting);
			pstr = get_string(kStrSetting);
			break;
		}

		case 5://histroy log
		{
			pbm = get_image(kImgHistoryLog);
			pstr = get_string(kStrHistoryLog);
			break;
		}
		
		default:
	  		return;
	}
	
	x = SELECT_ICON_X(cursor_index);

	IMAGE_SetBitmap(WM_GetDialogItem(ui_get_current_hwin(), EXHAUST_ID_IMG_MENU), pbm);
	WM_MoveChildTo(WM_GetDialogItem(ui_get_current_hwin(), EXHAUST_ID_IMG_SELECT), x, SELECT_ICON_Y);
	TEXT_SetText(WM_GetDialogItem(ui_get_current_hwin(), EXHAUST_ID_STR_TITLE), pstr);
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
			
			hWin = TEXT_CreateEx(2, 2, 100, 14, pMsg->hWin, 
				                 WM_CF_SHOW, GUI_TA_VCENTER|GUI_TA_HCENTER, MessageID3, 0);
			TEXT_SetFont(hWin, get_font(14));
			TEXT_SetBkColor(hWin,GUI_BLACK );
			TEXT_SetTextColor(hWin, GUI_WHITE);
			WM_BringToTop(hWin);

			//image1
			hWin = IMAGE_CreateEx(40, 20, 40, 40, pMsg->hWin, WM_CF_SHOW,  
			                      IMAGE_CF_AUTOSIZE, SET_IMG_ID1);
			IMAGE_SetBitmap(hWin, get_image(kImgTimeSelect));

			//image2
			hWin = IMAGE_CreateEx(40, 20, 40, 40, pMsg->hWin, WM_CF_SHOW,  
								  IMAGE_CF_AUTOSIZE, SET_IMG_ID2);
			IMAGE_SetBitmap(hWin, get_image(kImgTimeSelect));

			//image3
			hWin = IMAGE_CreateEx(40, 20, 40, 40, pMsg->hWin, WM_CF_SHOW,  
								  IMAGE_CF_AUTOSIZE, SET_IMG_ID3);
			IMAGE_SetBitmap(hWin, get_image(kImgTimeSelect));

			//image4
			hWin = IMAGE_CreateEx(40, 20, 40, 40, pMsg->hWin, WM_CF_SHOW,  
								  IMAGE_CF_AUTOSIZE, SET_IMG_ID4);
			IMAGE_SetBitmap(hWin, get_image(kImgTimeSelect));
	
		case WM_PAINT:
			GUI_SetColor(GUI_WHITE);

			GUI_SetFont(get_font(14));
				
			ptr = get_string(kStrReturn);
			strlen = GUI_GetStringDistX(ptr);
			ui_rect_init_by_size(rect, 0, DISPLAY_HEIGHT-16, strlen, 16);
			GUI_DispStringInRect(ptr, &rect, GUI_TA_LEFT|GUI_TA_VCENTER);

			ptr = get_string(kStrEnter);
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
WM_HWIN app_scr_class16_create(type_MsgBody4UICtrlMsg *msg) 
{
	WM_HWIN hWin;	
	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}


int app_scr_class16_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg)
{


 	return 0;	
}

void app_scr_class16_destroy(WM_HWIN win_id) 
{
	GUI_EndDialog(win_id, 0);
}

/*************************** End of file ****************************/
