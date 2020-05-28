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
#include "app_scr_set_time_14110.h"
#include <stdio.h>


/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0         (GUI_ID_USER + 0x00)
#define HOUR_ID				(GUI_ID_USER + 0x01)	
#define MIN_ID				(GUI_ID_USER + 0x02)
#define TIME_SEL_ID			(GUI_ID_USER + 0x03)



#define TIME_INDEX_HOUR		0
#define TIME_INDEX_MIN		1
/*********************************************************************
*
*       Static data
*
**********************************************************************
*/


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "app_scr_set_time_14110", ID_WINDOW_0, 0, 0, 256, 64, 0, 0x0, 0 },

};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/


static void move_time_cusor(uint8_t index)
{
	WM_HWIN hWin;
	uint8_t strlen, img_len, dlen, x;


	GUI_SetFont(get_font(60));
	strlen = GUI_GetStringDistX("00");
	img_len = GUI_GetStringDistX(":");
	dlen = 16+ 2*strlen + img_len;
	x = (DISPLAY_WIDTH - dlen)/2;
	hWin = WM_GetDialogItem(ui_get_current_hwin(), TIME_SEL_ID);
	if(TIME_INDEX_HOUR == index)
	{
		WM_MoveChildTo(hWin, x, 32);
	}
	else if(TIME_INDEX_MIN == index)
	{
		WM_MoveChildTo(hWin, x+8+strlen+img_len, 32);
	}
}



static void change_time_hour_or_min(uint8_t index, uint8_t data)
{
	WM_HWIN hWin;
	char buff[16];


	if(TIME_INDEX_HOUR == index)
	{
		hWin = WM_GetDialogItem(ui_get_current_hwin(), HOUR_ID);
		sprintf(buff, "%d", data);
		TEXT_SetText(hWin, buff);

	}
	else if(TIME_INDEX_MIN == index)
	{
		hWin = WM_GetDialogItem(ui_get_current_hwin(), MIN_ID);
		sprintf(buff, "%d", data);
		TEXT_SetText(hWin, buff);		
	}
}

static void _cbDialog(WM_MESSAGE * pMsg) 
{
	uint8_t strlen, img_len, dlen, x;
	GUI_RECT rect; 
	const char *ptr;
	WM_HWIN hWin;
	
	
	switch (pMsg->MsgId) 
	{
		case WM_INIT_DIALOG:
			WINDOW_SetBkColor(pMsg->hWin, GUI_BLACK);

			GUI_SetFont(get_font(60));
		    strlen = GUI_GetStringDistX("00");
			img_len = GUI_GetStringDistX(":");
			dlen = 16+ 2*strlen + img_len;
			x = (DISPLAY_WIDTH - dlen)/2;
			
			//hour
			hWin = TEXT_CreateEx(x+8, 16, strlen, DISPLAY_HEIGHT-16, pMsg->hWin, 
				                 WM_CF_SHOW, GUI_TA_VCENTER|GUI_TA_HCENTER,  HOUR_ID, "08");
			TEXT_SetFont(hWin, get_font(60));
			TEXT_SetBkColor(hWin, GUI_BLACK);
			TEXT_SetTextColor(hWin,  GUI_WHITE);


			//minite
			hWin = TEXT_CreateEx(x+16+strlen+img_len, 16, strlen, DISPLAY_HEIGHT-16, pMsg->hWin, 
				                 WM_CF_SHOW, GUI_TA_VCENTER|GUI_TA_HCENTER,  MIN_ID, "30");
			TEXT_SetFont(hWin, get_font(60));
			TEXT_SetBkColor(hWin, GUI_BLACK);
			TEXT_SetTextColor(hWin,  GUI_WHITE);


			//select image
			hWin = IMAGE_CreateEx(x, 16+ (DISPLAY_HEIGHT-16 - 16)/2,16, 8, pMsg->hWin, WM_CF_SHOW,  
			                      IMAGE_CF_AUTOSIZE, TIME_SEL_ID);
			IMAGE_SetBitmap(hWin, get_image(kImgSetArrow));

			
			break;
	
		case WM_PAINT:
			GUI_SetColor(GUI_WHITE);

			GUI_SetFont(get_font(14));
				
			ptr = get_string(kStrSetHour);
			strlen = GUI_GetStringDistX(ptr);
			ui_rect_init_by_size(rect, 0, 0, strlen, 12);
			GUI_DispStringInRect(ptr, &rect, GUI_TA_LEFT|GUI_TA_VCENTER);

			ptr = get_string(kStrPrevious);
			strlen = GUI_GetStringDistX(ptr);
			ui_rect_init_by_size(rect, 0, DISPLAY_HEIGHT-16, strlen, 16);
			GUI_DispStringInRect(ptr, &rect, GUI_TA_LEFT|GUI_TA_VCENTER);

			ptr = get_string(kStrConfirm);
			strlen = GUI_GetStringDistX(ptr);
			ui_rect_init_by_size(rect, DISPLAY_WIDTH-strlen, DISPLAY_HEIGHT-16, strlen, 16);
			GUI_DispStringInRect(ptr, &rect, GUI_TA_RIGHT|GUI_TA_VCENTER);

			GUI_SetFont(get_font(60));
			ptr = ":";
			strlen = GUI_GetStringDistX(ptr);
			ui_rect_init_by_size(rect, (DISPLAY_WIDTH-strlen)/2, 12, strlen, DISPLAY_HEIGHT-16);
			GUI_DispStringInRect(ptr, &rect, GUI_TA_LEFT|GUI_TA_VCENTER);			
			
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


WM_HWIN app_scr_set_time_14110_create(type_MsgBody4UICtrlMsg *msg) 
{
	WM_HWIN hWin;	
	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}


int app_scr_set_time_14110_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg)
{
//	switch(msg->OpMethod)
//	{
//		case SCR_CURSER_MOVE:
//			move_time_cusor(msg->CursorIndex);
//			break;
//
//		case SCR_VALUE_ALTER:
//			change_time_hour_or_min(msg->CursorIndex, msg->DItem[0]);
//			break;
//
//		default:
//			break;
//	}

 	return 0;	
}

void app_scr_set_time_14110_destroy(WM_HWIN win_id) 
{
	GUI_EndDialog(win_id, 0);
}

/*************************** End of file ****************************/