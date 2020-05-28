/************************************************
* DESCRIPTION:
*
*
************************************************/
#pragma once

#include "ssz_def.h"
#include "WM.h"
#include <string.h>
#include <stdlib.h>

/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif


void widget_text_set_font(WM_HWIN hWin, const GUI_FONT *font);
void widget_text_set_mode(WM_HWIN hWin, int mode);
void widget_text_set_style(WM_HWIN hWin, char style);
void widget_text_set_align(WM_HWIN hWin, int align);
void widget_text_set_str(WM_HWIN hWin, const char *str);
void widget_text_set_color(WM_HWIN hWin, GUI_COLOR color, GUI_COLOR bkcolor);
WM_HWIN widget_text_create(int x0, int y0, int xSize, int ySize,
                             WM_HWIN hWinParent, U32 wm_mode, const char * pText);



#ifdef __cplusplus
}
#endif

