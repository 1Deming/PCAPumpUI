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
**********************************************************************/


#include "DIALOG.h"
#include "GUI.h"
#include "ui_common.h"
#include "image_data.h"
#include "string_data.h"
#include "font_data.h"
#include <stdbool.h>
#include "app_scr_histroy_15100.h"
#include <stdio.h>
#include "ssz_common.h"
#include "widget_text.h"
#include "widget_image.h"
#include "record_log_config.h"
#include "ert_RTC.h"


/*********************************************************************
*
*       Defines
*
***********************************************************************/
#define ID_WINDOW_0     	(GUI_ID_USER + 0x00)

#define HISTROY_ID_TITLE	(GUI_ID_USER + 0x01)
#define HISTROY_ID_ITEM		(GUI_ID_USER + 0x02)
#define HISTROY_ID_INDEX	(GUI_ID_USER + 0x03)

typedef struct{
	int value;
	StrID str_id;
}StrIntItem;

#define LOG_TEXT_MAX_SIZE 128
#define LOG_VAR_TEXT_MAX_SIZE 40

/*********************************************************************
*
*       Static data
*
**********************************************************************/


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "app_scr_histroy_15100", ID_WINDOW_0, 0, 0, 256, 64, 0, 0x0, 0 },
};

/*********************************************************************
*
*       Static code
*
***********************************************************************/

static void put_histroy_index(int cur_index, int total_index)
{
	char *p;
	p = get_dynamic_string(kStrDynamic1);
	sprintf(p, "%d/%d", cur_index, total_index);
	TEXT_SetText(WM_GetDialogItem(ui_get_current_hwin(), HISTROY_ID_INDEX), p);
}


static const char* histroy_log_event_type_to_const_str(uint32_t log_event_type) {
	const StrIntItem items[] = {
		{ LOG_EVENT_TYPE_INFO, kStrLogTypeGeneral },
		{ LOG_EVENT_TYPE_ERROR, kStrLogTypeError },
		{ LOG_EVENT_TYPE_INFUSION, kStrLogTypeInfusion},
		{ LOG_EVENT_TYPE_ALARM, kStrLogTypeAlarm},
	};

	for (int i = 0; i < ssz_array_size(items); i++) {
		if (items[i].value == log_event_type) {
			return get_string(items[i].str_id);
		}
	}

	return "";
}

static void put_histroy_tile(uint32_t log_type, TimeStamp time)
{
	char *p;
	p = get_dynamic_string(kStrDynamic2);
	sprintf(p, "%s %d-%d-%d", histroy_log_event_type_to_const_str(log_type), time.year+2000,time.month, time.day);
	TEXT_SetText(WM_GetDialogItem(ui_get_current_hwin(), HISTROY_ID_TITLE), p);	
}

static const char* histroy_log_event_id_to_const_str(LogEvent log_event_id) {
    const char* ret = "";

	if (log_event_id< kLogEventHistroyEnd) {
		return get_string((StrID)((int)kStrLogEventLost + log_event_id));
	}

	return ret;
}


const char* record_log_var_to_str(const LogVar* one_var, char* buff, int buff_max_size)
{
	switch (one_var->type) {
	case kLogVarNull:
		buff[0] = 0;
		break;
	case kLogVarInteger:
		snprintf(buff, buff_max_size, "%d", one_var->value);
		break;
	case kLogVarFloat:
		snprintf(buff, buff_max_size, "%d.%03d", one_var->value / 1000, one_var->value % 1000);
		break;
	case kLogVarFloatWithOneDecimal:
		snprintf(buff, buff_max_size, "%d.%d", one_var->value / 10, one_var->value % 10);
		break;
	case kLogVarFloatWithTwoDecimal:
		snprintf(buff, buff_max_size, "%d.%02d", one_var->value / 100, one_var->value % 100);
		break;
	case kLogVarString:
		snprintf(buff, buff_max_size, "%s", one_var->str_value);
		break;
	case kLogVarAlarmID:
	{
		/*
		AlarmLevel alarm_level = alarm_id_to_level((AlarmID)(one_var->value));
		if (alarm_level >= kAlarmLevelHighest) {
			snprintf(buff, buff_max_size, "!!!%s", alarm_id_to_const_str((AlarmID)(one_var->value)));
		} else if (alarm_level >= kAlarmLevelHigh) {
			snprintf(buff, buff_max_size, "!!!%s", alarm_id_to_const_str((AlarmID)(one_var->value)));
		} else if (alarm_level >= kAlarmLevelLowest) {
			snprintf(buff, buff_max_size, "!%s", alarm_id_to_const_str((AlarmID)(one_var->value)));
		} else {
			snprintf(buff, buff_max_size, "%s", alarm_id_to_const_str((AlarmID)(one_var->value)));
		}
		*/
		break;
	}
	default:
		buff[0] = 0;
		ssz_assert_fail();
		break;
	}

	return buff;
}

//convert record to str, return the str
const char* record_log_to_str(const LogOneRecord* one_record, char* buff, int buff_max_size) {
	char param_str[4][LOG_VAR_TEXT_MAX_SIZE] = { 0 };
	const char* format = histroy_log_event_id_to_const_str((LogEvent)one_record->event_id);
	LogVar log_var[4];
	int var_size;
	//var_size = record_log_data_to_var(one_record->event_data, log_var, ssz_array_size(log_var));
	//for (int i = 0; i < var_size; i++) {
	//	record_log_var_to_str(&log_var[i], param_str[i], ssz_array_size(param_str[0]));
	//}
	snprintf(buff, buff_max_size, format, param_str[0], param_str[1], param_str[2], param_str[3]);
	return buff;
}


static void put_histroy_item(const LogOneRecord* one_record)
{
	char show_text[128];
	TEXT_SetText(WM_GetDialogItem(ui_get_current_hwin(), HISTROY_ID_ITEM), 
		         record_log_to_str(one_record, show_text, ssz_array_size(show_text)));
}



static void _cbDialog(WM_MESSAGE * pMsg) 
{
	GUI_RECT rect;
	WM_HWIN hWin;
	int strlen, x;
	const char *ptr;

	GUI_SetFont(get_font(14));
	ptr = "1000/1000";
	strlen = GUI_GetStringDistX(ptr);
	x = (DISPLAY_WIDTH - strlen)/2;
	
	switch (pMsg->MsgId) 
	{
		case WM_INIT_DIALOG:
			WINDOW_SetBkColor(pMsg->hWin, GUI_BLACK);
			//tile
			hWin = TEXT_CreateEx(0, 0, DISPLAY_WIDTH/2, 12, pMsg->hWin, 
				                 WM_CF_SHOW, GUI_TA_VCENTER|GUI_TA_LEFT,  HISTROY_ID_TITLE, get_string(kStrLogEventAlarm));
			TEXT_SetFont(hWin, get_font(14));
			TEXT_SetBkColor(hWin, GUI_BLACK);
			TEXT_SetTextColor(hWin, GUI_WHITE);

			
			//item
			hWin = TEXT_CreateEx(0, 16, DISPLAY_WIDTH, DISPLAY_HEIGHT-28, pMsg->hWin, 
				                 WM_CF_SHOW, GUI_TA_LEFT,  HISTROY_ID_ITEM, get_string(kStrLogEventInfusionStart));
			TEXT_SetFont(hWin, get_font(14));
			TEXT_SetBkColor(hWin, GUI_BLACK);
			TEXT_SetTextColor(hWin, GUI_WHITE);
			TEXT_SetWrapMode(hWin, GUI_WRAPMODE_CHAR);

			//index
			hWin = TEXT_CreateEx(x, DISPLAY_HEIGHT-16, strlen, 16, pMsg->hWin, 
				                 WM_CF_SHOW, GUI_TA_VCENTER|GUI_TA_HCENTER,  HISTROY_ID_INDEX, "034/999");
			TEXT_SetFont(hWin, get_font(14));
			TEXT_SetBkColor(hWin, GUI_BLACK);
			TEXT_SetTextColor(hWin, GUI_WHITE);
			break;
	
		case WM_PAINT:
			GUI_SetFont(get_font(14));

			ui_rect_init_by_size(rect, x-8, DISPLAY_HEIGHT-16+4, 8, 16);
			GUI_DrawBitmap(get_image(kImgLeftArrow), rect.x0, rect.y0);
			
			ui_rect_init_by_size(rect, x+strlen, DISPLAY_HEIGHT-16+4, 8, 16);
			GUI_DrawBitmap(get_image(kImgRightArrow), rect.x0, rect.y0);
			
			ptr = get_string(kStrReturn);
			strlen = GUI_GetStringDistX(ptr);
			ui_rect_init_by_size(rect, 0, DISPLAY_HEIGHT-16, strlen, 16);
			GUI_DispStringInRect(ptr, &rect, GUI_TA_LEFT|GUI_TA_BOTTOM);
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
**********************************************************************/
WM_HWIN app_scr_histroy_15100_create(type_MsgBody4UICtrlMsg *msg) 
{
	WM_HWIN hWin;

	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	
	return hWin;
}


int app_scr_histroy_15100_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg)
{
	switch(msg->OpMethod)
	{
		case SCR_CURSER_MOVE:
			
			break;

		case SCR_VALUE_ALTER:

			break;
		default:
			break;
	}
 	return 0;	
}

void app_scr_histroy_15100_destroy(WM_HWIN win_id) 
{
	GUI_EndDialog(win_id, 0);
}


/*************************** End of file ****************************/