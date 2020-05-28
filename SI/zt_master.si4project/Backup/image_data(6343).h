#pragma once
#include "ssz_def.h"
#include "GUI.h"

/************************************************
* Declaration
************************************************/

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
	kImgAc,
	kImgBatteryAc,
	kImgBatteryEmpty,
	kImgBatteryFull,
	kImgBatteryNo,
	kImgBatteryOne,
	kImgBatteryThree,
	kImgBatteryTwo,
	kImgError,
	kImgExhaust,
	kImgExhaustPause,
	kImgExhaustRun,
	kImgFlushMaxDoseSelected,
	kImgFlushMaxDoseUnselected,
	kImgHistoryLog,
	kImgInfoSelect,
	kImgInfoUnselect,
	kImgInfusionPause,
	kImgInfusionRun,
	kImgInfusionStop,
	kImgLeftArrow,
	kImgLock,
	kImgLogo,
	kImgModeSelected,
	kImgModeUnselected,
	kImgMute,
	kImgMuteSmall,
	kImgNewTask,
	kImgPeakSetSelect,
	kImgPeakSetUnselect,
	kImgRightArrow,
	kImgSelectedPointer,
	kImgSelect1,
	kImgSelect2,
	kImgSetArrow,
	kImgSoundPause,
	kImgStopInfusion,
	kImgSystemSetting,
	kImgTimeSelect,
	kImgTimeUnselect,
	kImgUnselectedPointer,
	kImgWarning,
	kImgWarningCommon,
	kImgIDMax,
 }ImgID;

//get image from the image id
GUI_CONST_STORAGE GUI_BITMAP* get_image(ImgID img_id);

#ifdef __cplusplus
}
#endif

