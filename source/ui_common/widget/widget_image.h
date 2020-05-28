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
#include "GUI.h"

/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif


WM_HWIN widget_image_create(int x0, int y0, int xSize, int ySize, 
							WM_HWIN hWinParent, U32 wm_mode, const GUI_BITMAP *bitmap);

void widget_image_set(WM_HWIN hWin, const GUI_BITMAP *bitmap);



#ifdef __cplusplus
}
#endif

