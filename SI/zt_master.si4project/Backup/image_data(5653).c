/************************************************
*
* NAME: image_data.c
*
* DESCRIPTION:
*
*
* REVISION HISTORY:
*   Rev 1.0 2017-3-2 ryan
* Initial revision.
*
************************************************/
#include "image_data.h"
#include "string.h"

/************************************************
* Declaration
************************************************/
typedef struct
{
	ImgID id;
	GUI_CONST_STORAGE GUI_BITMAP* data;
}ImgData;

extern GUI_CONST_STORAGE GUI_BITMAP bmAC;
extern GUI_CONST_STORAGE GUI_BITMAP bmbattery_AC;
extern GUI_CONST_STORAGE GUI_BITMAP bmbattery_empty;
extern GUI_CONST_STORAGE GUI_BITMAP bmbattery_full;
extern GUI_CONST_STORAGE GUI_BITMAP bmbattery_no;
extern GUI_CONST_STORAGE GUI_BITMAP bmbattery_one;
extern GUI_CONST_STORAGE GUI_BITMAP bmbattery_three;
extern GUI_CONST_STORAGE GUI_BITMAP bmbattery_two;
extern GUI_CONST_STORAGE GUI_BITMAP bmerror;
extern GUI_CONST_STORAGE GUI_BITMAP bmexhaust;
extern GUI_CONST_STORAGE GUI_BITMAP bmexhaust_pause;
extern GUI_CONST_STORAGE GUI_BITMAP bmexhaust_run;
extern GUI_CONST_STORAGE GUI_BITMAP bmflush_max_dose_selected;
extern GUI_CONST_STORAGE GUI_BITMAP bmflush_max_dose_unselected;
extern GUI_CONST_STORAGE GUI_BITMAP bmhistory_log;
extern GUI_CONST_STORAGE GUI_BITMAP bminfo_select;
extern GUI_CONST_STORAGE GUI_BITMAP bminfo_unselect;
extern GUI_CONST_STORAGE GUI_BITMAP bminfusion_pause;
extern GUI_CONST_STORAGE GUI_BITMAP bminfusion_run;
extern GUI_CONST_STORAGE GUI_BITMAP bminfusion_stop;
extern GUI_CONST_STORAGE GUI_BITMAP bmleft_arrow;
extern GUI_CONST_STORAGE GUI_BITMAP bmlock;
extern GUI_CONST_STORAGE GUI_BITMAP bmlogo;
extern GUI_CONST_STORAGE GUI_BITMAP bmmode_selected;
extern GUI_CONST_STORAGE GUI_BITMAP bmmode_unselected;
extern GUI_CONST_STORAGE GUI_BITMAP bmmute;
extern GUI_CONST_STORAGE GUI_BITMAP bmmute_small;
extern GUI_CONST_STORAGE GUI_BITMAP bmnew_task;
extern GUI_CONST_STORAGE GUI_BITMAP bmpeak_set_select;
extern GUI_CONST_STORAGE GUI_BITMAP bmpeak_set_unselect;
extern GUI_CONST_STORAGE GUI_BITMAP bmright_arrow;
extern GUI_CONST_STORAGE GUI_BITMAP bmselected_pointer;
extern GUI_CONST_STORAGE GUI_BITMAP bmselect_1;
extern GUI_CONST_STORAGE GUI_BITMAP bmselect_2;
extern GUI_CONST_STORAGE GUI_BITMAP bmset_arrow;
extern GUI_CONST_STORAGE GUI_BITMAP bmsound_pause;
extern GUI_CONST_STORAGE GUI_BITMAP bmstop_infusion;
extern GUI_CONST_STORAGE GUI_BITMAP bmsystem_setting;
extern GUI_CONST_STORAGE GUI_BITMAP bmtime_select;
extern GUI_CONST_STORAGE GUI_BITMAP bmtime_unselect;
extern GUI_CONST_STORAGE GUI_BITMAP bmunselected_pointer;
extern GUI_CONST_STORAGE GUI_BITMAP bmwarning;
extern GUI_CONST_STORAGE GUI_BITMAP bmwarning_common;


/************************************************
* Variable 
************************************************/
//#include "generated_image_data.h"
ImgData g_image_data[] =
{
	kImgAc, &bmAC,
	kImgBatteryAc, &bmbattery_AC,
	kImgBatteryEmpty, &bmbattery_empty,
	kImgBatteryFull, &bmbattery_full,
	kImgBatteryNo, &bmbattery_no,
	kImgBatteryOne, &bmbattery_one,
	kImgBatteryThree, &bmbattery_three,
	kImgBatteryTwo, &bmbattery_two,
	kImgError, &bmerror,
	kImgExhaust, &bmexhaust,
	kImgExhaustPause, &bmexhaust_pause,
	kImgExhaustRun, &bmexhaust_run,
	kImgFlushMaxDoseSelected, &bmflush_max_dose_selected,
	kImgFlushMaxDoseUnselected, &bmflush_max_dose_unselected,
	kImgHistoryLog, &bmhistory_log,
	kImgInfoSelect, &bminfo_select,
	kImgInfoUnselect, &bminfo_unselect,
	kImgInfusionPause, &bminfusion_pause,
	kImgInfusionRun, &bminfusion_run,
	kImgInfusionStop, &bminfusion_stop,
	kImgLeftArrow, &bmleft_arrow,
	kImgLock, &bmlock,
	kImgLogo, &bmlogo,
	kImgModeSelected, &bmmode_selected,
	kImgModeUnselected, &bmmode_unselected,
	kImgMute, &bmmute,
	kImgMuteSmall, &bmmute_small,
	kImgNewTask, &bmnew_task,
	kImgPeakSetSelect, &bmpeak_set_select,
	kImgPeakSetUnselect, &bmpeak_set_unselect,
	kImgRightArrow, &bmright_arrow,
	kImgSelectedPointer, &bmselected_pointer,
	kImgSelect1, &bmselect_1,
	kImgSelect2, &bmselect_2,
	kImgSetArrow, &bmset_arrow,
	kImgSoundPause, &bmsound_pause,
	kImgStopInfusion, &bmstop_infusion,
	kImgSystemSetting, &bmsystem_setting,
	kImgTimeSelect, &bmtime_select,
	kImgTimeUnselect, &bmtime_unselect,
	kImgUnselectedPointer, &bmunselected_pointer,
	kImgWarning, &bmwarning,
	kImgWarningCommon, &bmwarning_common,
};


/************************************************
* Function 
************************************************/

//get image from the image id
GUI_CONST_STORAGE GUI_BITMAP* get_image(ImgID img_id)
{
    if (img_id >= kImgIDMax)
    {
        return NULL;
    }
    return g_image_data[img_id].data;
}


