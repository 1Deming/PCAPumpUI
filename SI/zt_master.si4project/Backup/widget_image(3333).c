/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "widget_image.h"

/************************************************
* Declaration
************************************************/

/************************************************
* Variable 
************************************************/

/************************************************
* Function 
************************************************/

static void widget_image_callback(WM_MESSAGE *pMsg)
{
	switch(pMsg->MsgId)
	{
	  
		case WM_INIT_DIALOG:
		  break;
		case WM_PAINT:

		  break;
		  
		default:
		  WM_DefaultProc(pMsg);
		  break;

	}
}



WM_HWIN widget_image_create(int x0, int y0, int xSize, int ySize, 
                                     WM_HWIN hWinParent, U32 wm_mode, const GUI_BITMAP *bitmap)
{

	WM_HWIN hwin;

	hwin = WM_CreateWindowAsChild(x0, y0, xSize, ySize, hWinParent, wm_mode, 
  	                              widget_image_callback, sizeof(GUI_BITMAP));

	WM_SetUserData(hwin, bitmap, sizeof(GUI_BITMAP));
	return hwin;
}



void widget_image_set(WM_HWIN hWin, const GUI_BITMAP *bitmap)
{
	WM_SetUserData(hWin, bitmap, sizeof(GUI_BITMAP));	
	WM_Paint(hWin);
}















