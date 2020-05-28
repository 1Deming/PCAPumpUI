/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "ud_text.h"
#include "font_data.h"


/************************************************
* Declaration
************************************************/
typedef struct
{
	int mode;
	char style;
	const GUI_FONT *font;
	GUI_COLOR color;
	int align;
	char str[50];
}UDTextData;

/************************************************
* Variable 
************************************************/

/************************************************
* Function 
************************************************/
static void ud_text_callback(WM_MESSAGE *pMsg)
{
	GUI_RECT WinRect;
	UDTextData text_data;
	int len;

	switch(pMsg->MsgId)
	{
	  
		  //case WM_INIT_DIALOG:
			//WINDOW_SetBkColor(pMsg->hWin, GUI_MAKE_COLOR(0x00000000));	  
			//break;
		case WM_PAINT:
		  WM_GetWindowRectEx(pMsg->hWin, &WinRect);
	 	  GUI_MoveRect(&WinRect, -WinRect.x0, -WinRect.y0);
		  GUI_Clear();
		  WM_GetUserData(pMsg->hWin, &text_data, sizeof(UDTextData));
		  GUI_SetTextMode(text_data.mode);
		  GUI_SetTextStyle(text_data.style);
		  GUI_SetFont(text_data.font);
		  GUI_SetColor(text_data.color);
		  len = strlen(text_data.str);
		  text_data.str[len] = '\0';
		  GUI_DispStringInRect(text_data.str, &WinRect, text_data.align);
		  break;
		  
		default:
		  WM_DefaultProc(pMsg);
		  break;

	}
}


WM_HWIN ud_text_create(int x0, int y0, int xSize, int ySize,
                             WM_HWIN hWinParent, U32 Style, const char * pText)
{
	WM_HWIN hWin;
	UDTextData text_data;
	memset(&text_data, 0, sizeof(UDTextData));

	int len = strlen(pText);
	if(pText)
	{
		strncpy(text_data.str, pText, len);
	}
	text_data.str[len] = '\0';

	
  	hWin = WM_CreateWindowAsChild(x0, y0, xSize, ySize, hWinParent, Style, 
  	                              ud_text_callback, sizeof(UDTextData));
   text_data.align = GUI_TA_VCENTER|GUI_TA_HCENTER;
   text_data.color = GUI_WHITE;
   text_data.font = get_font(14);
   text_data.mode = GUI_TM_NORMAL;
   text_data.style = GUI_TS_NORMAL;
   WM_SetUserData(hWin, &text_data, sizeof(UDTextData));
   return hWin;
}




void ud_text_set_font(WM_HWIN hWin, const GUI_FONT *font)
{
	UDTextData text_data;
	WM_GetUserData(hWin, &text_data, sizeof(UDTextData));
	text_data.font = font;
	WM_SetUserData(hWin, &text_data, sizeof(UDTextData));
	WM_InvalidateWindow(hWin);
}
                        

void ud_text_set_mode(WM_HWIN hWin, int mode)
{
	UDTextData text_data;
	WM_GetUserData(hWin, &text_data, sizeof(UDTextData));
	text_data.mode = mode;
	WM_SetUserData(hWin, &text_data, sizeof(UDTextData));
	WM_InvalidateWindow(hWin);
}


void ud_text_set_style(WM_HWIN hWin, char style)
{
	UDTextData text_data;
	WM_GetUserData(hWin, &text_data, sizeof(UDTextData));
	text_data.style = style;
	WM_SetUserData(hWin, &text_data, sizeof(UDTextData));
	WM_InvalidateWindow(hWin);
}


void ud_text_set_align(WM_HWIN hWin, int align)
{
	UDTextData text_data;
	WM_GetUserData(hWin, &text_data, sizeof(UDTextData));
	text_data.align = align;
	WM_SetUserData(hWin, &text_data, sizeof(UDTextData));
	WM_InvalidateWindow(hWin);
}


void ud_text_set_str(WM_HWIN hWin, const char *str)
{
	UDTextData text_data;
	WM_GetUserData(hWin, &text_data, sizeof(UDTextData));
	
	int len = strlen(str);
	strncpy(text_data.str, str, len);
	text_data.str[len] = '\0';
	
	WM_SetUserData(hWin, &text_data, sizeof(UDTextData));
	WM_InvalidateWindow(hWin);
}








