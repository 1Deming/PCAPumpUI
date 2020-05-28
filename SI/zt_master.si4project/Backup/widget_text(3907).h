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


void ud_text_set_font(WM_HWIN hWin, const GUI_FONT *font);
void ud_text_set_mode(WM_HWIN hWin, int mode);
void ud_text_set_style(WM_HWIN hWin, char style);
void ud_text_set_align(WM_HWIN hWin, int align);
void ud_text_set_str(WM_HWIN hWin, const char *str);
WM_HWIN ud_text_create(int x0, int y0, int xSize, int ySize,
								WM_HWIN hWinParent, U32 Style, const char * pText);


#ifdef __cplusplus
}
#endif

