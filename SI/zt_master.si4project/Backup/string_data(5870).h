#pragma once
#include "ssz_locale.h"

/************************************************
* Declaration
************************************************/

#define  DYNAMIC_STRING_MAX_SIZE 64
#define DYNAMIC_STRING_ID_DEFINE 	\
	kStrDynamicIDStart, \
	kStrDynamic1 = kStrDynamicIDStart, \
	kStrDynamic2, \
	kStrDynamic3, \
	kStrDynamic4, \
	kStrDynamic5, \
	kStrDynamic6, \
	kStrDynamicIDEnd = kStrDynamic6

typedef enum
{
	kStrNull,
	kStrConfirm,
	kStrCancel,
	kStrEnter,
	kStrNewInfusionTask,
	kStrEditInfusionTask,
	kStrClearAir,
	kStrStopInfusion,
	kStrSetting,
	kStrHistoryLog,
	kStrReturn,
	kStrSetTotalDose,
	kStrSetFirstDose,
	kStrSetLimitDose,
	kStrSetInfuseSpeed,
	kStrWhetherToAddPeekMode,
	kStrSetPeekModeDuration,
	kStrPeekSpeed,
	kStrExpectedTimeDuration,
	kStrTimeDuration,
	kStrConfirmInfusionSettingDetails,
	kStrTotalAndFirstDose,
	kStrSpeed,
	kStrInfusionDuration,
	kStrLimitDose,
	kStrInfusionStop,
	kStrInfusing,
	kStrInfusionPause,
	kStrInfusionMedsBag1Pause,
	kStrInfusionMedsBag2Pause,
	kStrInfusedDose,
	kStrInfusionMedsBag1,
	kStrInfusionMedsBag2,
	kStrSelectClearAirMode,
	kStrPressStartToStartClearAir,
	kStrPressPauseToStopClearAir,
	kStrDoNotConnectBody,
	kStrClearAirDone,
	kStrAutoMode,
	kStrManualMode,
	kStrMedsBag1,
	kStrMedsBag2,
	kStrNotice,
	kStrSelectFinishMode,
	kStrDirectlyStopInfuse,
	kStrStopByCleanTube,
	kStrWhetherToStopInfuse,
	kStrWhetherToStopInfuseAndClean,
	kStrWhetherToStopClean,
	kStrYes,
	kStrNo,
	kStrPressPauseToStopCleanTube,
	kStrPressStartToStartCleanTube,
	kStrStop,
	kStrCleanTubeDone,
	kStrOk,
	kStrWarning,
	kStrCaution,
	kStrLowBattery,
	kStrTubeBlocked,
	kStrSystemError,
	kStrPauseAlarmingOk,
	kStrPauseAlarming,
	kStrCloseAlarming,
	kStrInfusionWillBeFinishedInOneHour,
	kStrInfusionNearEmpty,
	kStrBatteryNotExist,
	kStrInstallNotInPlace,
	kStrBatteryExhaustion,
	kStrHaveBubble,
	kStrInfusionEnd,
	kStrInfusionPauseToolLong,
	kStrInputPasswordToUnlock,
	kStrHour,
	kStrMinute,
	kStrMililiter,
	kStrMililiterPerHour1,
	kStrMililiterPerHour2,
	kStrFactoryMode,
	kStrPressureCalibration,
	kStrInfusionPrecisionCalibration,
	kStrBatteryCalibration,
	kStrVersion,
	kStrSave,
	kStrSavedValue,
	kStrCurrentValue,
	kStrCurrentStep,
	kStrCurrentPressure,
	kStrSavedOffsetValue,
	kStrCurrentOffsetValue,
	kStrInfusionDose,
	kStrRealInfusionDose,
	kStrWhetherToContinueInfuse,
	kStrTimeDate,
	kStrSetHour,
	kStrSetMonth,
	kStrSetYear,
	kStrNext,
	kStrPrevious,
	kStrCleanTubeDose,
	kStrWrongPassword,
	kStrTotalDose,
	kStrHourCharacter,
	kStrLogTypeGeneral,
	kStrLogTypeError,
	kStrLogTypeInfusion,
	kStrLogTypeAlarm,
	kStrLogEventLost,
	kStrLogEventSystemError,
	kStrLogEventPowerOn,
	kStrLogEventPowerOff,
	kStrLogEventAlarm,
	kStrLogEventInfusionStart,
	kStrLogEventInfusionPeekSet,
	kStrLogEventInfusionPause,
	kStrLogEventInfusionResume,
	kStrLogEventChangeInfusionSpeed,
	kStrLogEventChangeInfusionVolume,
	kStrLogEventChangeCleanTubeVolume,
	kStrLogEventChangeInfusionPeekSet,
	kStrLogEventCloseInfusionPeekSet,
	kStrLogEventInfusionStop,
	kStrLogEventCleanTubeStart,
	kStrLogEventCleanTubePause,
	kStrLogEventCleanTubeResume,
	kStrLogEventCleanTubeStop,
	kStrLogEventEnterManualClearAir,
	kStrLogEventEnterAutoClearAir,
	kStrLogEventClearAirStart,
	kStrLogEventClearAirStop,
	kStrLogEventChangeToSmallBag,
	kStrLogEventChangeToBigBag,
	kStrPowerOffConfirm,
	kStrIsConfirm,
	kStrPeekModeSwitch,
	kStrOn,
	kStrOff,
	kStrAdapterDisconnected,
	kStrKeyIsLocked,
	kStrKeyIsUnlocked,
	kStrPressKeyToUnlocked,
	kStrPressWrongKey,
	kStrChangePassword,
	kStrDefaultValue,
	kStrInputNewPassword,
	kStrInfusionModeSetting,
	kStrAskEverytimeMode,
	kStrFixMode,
	kStrSetSpeedMode,
	kStrSetTimeMode,
	kStrModeSelection,
	kStrSetInfusionDuration,
	kStrInfusionSpeed,
	kStrInputNewOledBrightness,
	kStrInputNewVoiceVolume,
	kStrChangeOledBrightness,
	kStrOperationLog,
	kStrSetCleanTubeDose,
	kStrSetMaxCleanTubeDose,
	kStrToSetMaxCleanTubeDose,
	kStrPeakModeInfusing,
	kStrSystemInfo,
	kStrBubbleAlarmSwitch,
	kStrBlockThresholdSet,
	kStrPrecesionFactorSet,
	kStrUserDataError,
	kStrUserDataCleared,
	DYNAMIC_STRING_ID_DEFINE,
	kStrIDMax
}StrID;



#ifdef __cplusplus
extern "C" {
#endif

//select string data by the language
bool string_data_select_by_lang(SszLang lang);

//get string from the string id
//Note: the string is encode as UTF8
const char* get_string(StrID str_id);

//get string from the string id and lang
//Note: the string is encode as UTF8
const char* get_string_by_lang(SszLang lang, StrID str_id);

//get dynamic string from the string id
char* get_dynamic_string(StrID str_id);

//set dynamic string
void set_dynamic_string(StrID str_id, const char* str);


#ifdef __cplusplus
}
#endif

