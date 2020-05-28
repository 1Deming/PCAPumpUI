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


/************************************************
* Variable 
************************************************/
//#include "generated_image_data.h"
const static ImgData g_image_data[] =
{
	{kImgAc, &bmAC},
	{kImgBatteryAc, &bmbattery_AC},
	{kImgBatteryEmpty, &bmbattery_empty},
	{kImgBatteryFull, &bmbattery_full},
	{kImgBatteryNo, &bmbattery_no},
	{kImgBatteryOne, &bmbattery_one},
	{kImgBatteryThree, &bmbattery_three},
	{kImgBatteryTwo, &bmbattery_two},
	{kImgError, &bmerror},
	{kImgExhaust, &bmexhaust},
	{kImgExhaustPause, &bmexhaust_pause},
	{kImgExhaustRun, &bmexhaust_run},
	{kImgFlushMaxDoseSelected, &bmflush_max_dose_selected},
	{kImgFlushMaxDoseUnselected, &bmflush_max_dose_unselected},
	{kImgHistoryLog, &bmhistory_log},
	{kImgInfoSelect, &bminfo_select},
	{kImgInfoUnselect, &bminfo_unselect},
	{kImgInfusionPause, &bminfusion_pause},
	{kImgInfusionRun, &bminfusion_run},
	{kImgInfusionStop, &bminfusion_stop},
	{kImgLeftArrow, &bmleft_arrow},
	{kImgLock, &bmlock},
	{kImgLogo, &bmlogo},
	{kImgModeSelected, &bmmode_selected},
	{kImgModeUnselected, &bmmode_unselected},
	{kImgMute, &bmmute},
	{kImgMuteSmall, &bmmute_small},
	{kImgNewTask, &bmnew_task},
	{kImgPeakSetSelect, &bmpeak_set_select},
	{kImgPeakSetUnselect, &bmpeak_set_unselect},
	{kImgRightArrow, &bmright_arrow},
	{kImgSelectedPointer, &bmselected_pointer},
	{kImgSelect1, &bmselect_1},
	{kImgSelect2, &bmselect_2},
	{kImgSetArrow, &bmset_arrow},
	{kImgSoundPause, &bmsound_pause},
	{kImgStopInfusion, &bmstop_infusion},
	{kImgSystemSetting, &bmsystem_setting},
	{kImgTimeSelect, &bmtime_select},
	{kImgTimeUnselect, &bmtime_unselect},
	{kImgUnselectedPointer, &bmunselected_pointer},
	{kImgWarning, &bmwarning},
	{kImgWarningCommon, &bmwarning_common},
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


