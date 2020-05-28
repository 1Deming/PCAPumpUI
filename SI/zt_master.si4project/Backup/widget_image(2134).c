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
	GUI_BITMAP bitmap;
	GUI_RECT rect, WinRect;
	int x, y;
	switch(pMsg->MsgId)
	{
	  
		case WM_INIT_DIALOG:
		  break;
		case WM_PAINT:
		  WM_GetWindowRectEx(pMsg->hWin, &WinRect);
	 	  GUI_MoveRect(&WinRect, -WinRect.x0, -WinRect.y0);
		  GUI_Clear();
		  WM_GetUserData(pMsg->hWin, (GUI_BITMAP *)&bitmap, sizeof(GUI_BITMAP));
		  WM_GetClientRect(&rect);
		  x = ((rect.x1 - rect.x0 + 1)  - bitmap.XSize)/2;
		  y = ((rect.y1 - rect.y0 + 1)  - bitmap.YSize)/2;
		  GUI_DrawBitmap(&bitmap, rect.x0+x,  rect.y0+y);
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















