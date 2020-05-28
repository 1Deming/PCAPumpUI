/*
 * File: test2_SysIntegration_types.h
 *
 * Code generated for Simulink model 'test2_SysIntegration'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Sat Apr 25 22:00:54 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. ROM efficiency
 *    3. Execution efficiency
 *    4. Traceability
 * Validation result: Not run
 */

#ifndef RTW_HEADER_test2_SysIntegration_types_h_
#define RTW_HEADER_test2_SysIntegration_types_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#ifndef DEFINED_TYPEDEF_FOR_type_MsgBody4VoltSampling_
#define DEFINED_TYPEDEF_FOR_type_MsgBody4VoltSampling_

typedef struct {
  /* BattVolt */
  int16_T Ch1;

  /* Batt Current */
  int16_T Ch2;

  /* Motor Current */
  int16_T Ch3;

  /* undesignated */
  int16_T Ch4;
} type_MsgBody4VoltSampling;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_VarBody4AlarmCtrl_
#define DEFINED_TYPEDEF_FOR_type_VarBody4AlarmCtrl_

typedef struct {
  uint8_T AlarmLevel;
  boolean_T boolMaster;
} type_VarBody4AlarmCtrl;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_MsgHead_
#define DEFINED_TYPEDEF_FOR_type_MsgHead_

/* type_CommCtrlDTMsg
   here DT means 'Data Transfer' */
typedef struct {
  uint8_T MsgId;
  uint8_T OpCode;
} type_MsgHead;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_MsgBody4GP1Byte_
#define DEFINED_TYPEDEF_FOR_type_MsgBody4GP1Byte_

typedef struct {
  uint8_T Data;
} type_MsgBody4GP1Byte;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_HMI2SecurityMsg_
#define DEFINED_TYPEDEF_FOR_type_HMI2SecurityMsg_

typedef struct {
  type_MsgHead Head;
  type_MsgBody4GP1Byte Body;
} type_HMI2SecurityMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_MsgBody4RecordInqResponse_
#define DEFINED_TYPEDEF_FOR_type_MsgBody4RecordInqResponse_

typedef struct {
  uint8_T MajorId;
  uint8_T MinorId;
  uint8_T Data[132];
} type_MsgBody4RecordInqResponse;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_CommCtrlRecordInqResponseMsg_
#define DEFINED_TYPEDEF_FOR_type_CommCtrlRecordInqResponseMsg_

typedef struct {
  type_MsgHead Head;
  type_MsgBody4RecordInqResponse Body;
} type_CommCtrlRecordInqResponseMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_MsgBody4BleDriveMsg_
#define DEFINED_TYPEDEF_FOR_type_MsgBody4BleDriveMsg_

typedef struct {
  uint8_T Data[224];
} type_MsgBody4BleDriveMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_BleDriveMsg_
#define DEFINED_TYPEDEF_FOR_type_BleDriveMsg_

typedef struct {
  type_MsgHead Head;
  type_MsgBody4BleDriveMsg Body;
} type_BleDriveMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_MsgBody4GP4Bytes_
#define DEFINED_TYPEDEF_FOR_type_MsgBody4GP4Bytes_

typedef struct {
  uint8_T Data[4];
} type_MsgBody4GP4Bytes;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_CommCtrlFCTestMsg_
#define DEFINED_TYPEDEF_FOR_type_CommCtrlFCTestMsg_

typedef struct {
  type_MsgHead Head;
  type_MsgBody4GP4Bytes Body;
} type_CommCtrlFCTestMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_MsgBody4DoseCtrl_
#define DEFINED_TYPEDEF_FOR_type_MsgBody4DoseCtrl_

/* type_CommCtrlDTMsg
   here DT means 'Data Transfer' */
typedef struct {
  uint8_T Data[48];
} type_MsgBody4DoseCtrl;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_CommCtrlDoseCtrlMsg_
#define DEFINED_TYPEDEF_FOR_type_CommCtrlDoseCtrlMsg_

/* type_CommCtrlDTMsg
   here DT means 'Data Transfer' */
typedef struct {
  type_MsgHead Head;
  type_MsgBody4DoseCtrl Body;
} type_CommCtrlDoseCtrlMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_MsgBody4GP6Bytes_
#define DEFINED_TYPEDEF_FOR_type_MsgBody4GP6Bytes_

typedef struct {
  uint8_T Data[6];
} type_MsgBody4GP6Bytes;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_CommCtrlActCtrlMsg_
#define DEFINED_TYPEDEF_FOR_type_CommCtrlActCtrlMsg_

/* type_CommCtrlDTMsg
   here DT means 'Data Transfer' */
typedef struct {
  type_MsgHead Head;

  /* DataSet should be made more clear */
  type_MsgBody4GP6Bytes Body;
} type_CommCtrlActCtrlMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_MsgBody4GP32Bytes_
#define DEFINED_TYPEDEF_FOR_type_MsgBody4GP32Bytes_

typedef struct {
  uint8_T Data[32];
} type_MsgBody4GP32Bytes;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_CommCtrlAlarmCtrlMsg_
#define DEFINED_TYPEDEF_FOR_type_CommCtrlAlarmCtrlMsg_

/* type_CommCtrlDTMsg
   here DT means 'Data Transfer' */
typedef struct {
  type_MsgHead Head;

  /* DataSet should be made more clear */
  type_MsgBody4GP32Bytes Body;
} type_CommCtrlAlarmCtrlMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_MsgBody4FirmwareCtrl_
#define DEFINED_TYPEDEF_FOR_type_MsgBody4FirmwareCtrl_

/* type_CommCtrlDTMsg
   here DT means 'Data Transfer' */
typedef struct {
  uint8_T Data[132];
} type_MsgBody4FirmwareCtrl;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_CommCtrlFirmwareMsg_
#define DEFINED_TYPEDEF_FOR_type_CommCtrlFirmwareMsg_

/* type_CommCtrlDTMsg
   here DT means 'Data Transfer' */
typedef struct {
  type_MsgHead Head;
  type_MsgBody4FirmwareCtrl Body;
} type_CommCtrlFirmwareMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_CommCtrlSysSettingMsg_
#define DEFINED_TYPEDEF_FOR_type_CommCtrlSysSettingMsg_

typedef struct {
  type_MsgHead Head;
  type_MsgBody4GP1Byte Body;
} type_CommCtrlSysSettingMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_MsgBody4RecordInqRequest_
#define DEFINED_TYPEDEF_FOR_type_MsgBody4RecordInqRequest_

typedef struct {
  uint8_T MajorId;
  uint8_T MinorId;
} type_MsgBody4RecordInqRequest;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_CommCtrlRecordInqRequestMsg_
#define DEFINED_TYPEDEF_FOR_type_CommCtrlRecordInqRequestMsg_

typedef struct {
  type_MsgHead Head;
  type_MsgBody4RecordInqRequest Body;
} type_CommCtrlRecordInqRequestMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_CommCtrlCalibraMsg_
#define DEFINED_TYPEDEF_FOR_type_CommCtrlCalibraMsg_

/* Body.Data domain description:

   for Op==1
   MajorMcuADCOffset Byte[2]
   MinorMcuADCOffset Byte[2]
   for OpCode=3
   null
   for Opcode=4
   CurentCrit Byte[2]
   TimeCrit Byte[2]
   small dose vector Byte[2]:k and d
   large dose vector Byte[2] */
typedef struct {
  type_MsgHead Head;
  type_MsgBody4GP32Bytes Body;
} type_CommCtrlCalibraMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_CommCtrlParam_
#define DEFINED_TYPEDEF_FOR_type_CommCtrlParam_

typedef struct {
  type_CommCtrlDoseCtrlMsg DoseCtrlMsg_IniVal;
  type_CommCtrlActCtrlMsg ActCtrlMsg_IniVal;
  type_CommCtrlAlarmCtrlMsg AlarmCtrlMsg_IniVal;
  type_CommCtrlFirmwareMsg FirmwareMsg_IniVal;
  type_CommCtrlSysSettingMsg SysSettingMsg_IniVal;
  type_CommCtrlRecordInqRequestMsg RecordInqMsg_IniVal;
  type_CommCtrlCalibraMsg CalibraMsg_IniVal;
  type_CommCtrlFCTestMsg FCTestMsg_IniVal;
  uint8_T ScanInterval;
} type_CommCtrlParam;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_MsgBody4GPU32_
#define DEFINED_TYPEDEF_FOR_type_MsgBody4GPU32_

typedef struct {
  uint32_T Data;
} type_MsgBody4GPU32;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_LowPower2RTCtrlMsg_
#define DEFINED_TYPEDEF_FOR_type_LowPower2RTCtrlMsg_

typedef struct {
  type_MsgHead Head;
  type_MsgBody4GPU32 Body;
} type_LowPower2RTCtrlMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_MsgBody4SysStatus_
#define DEFINED_TYPEDEF_FOR_type_MsgBody4SysStatus_

typedef struct {
  boolean_T AlarmStatus;
  boolean_T HMIStatus;
  uint16_T NextHitSec;
  boolean_T RecordStatus;
  boolean_T BleCommStatus;
  boolean_T SerialCommStatus;
} type_MsgBody4SysStatus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_LowPowerCtrlParam_
#define DEFINED_TYPEDEF_FOR_type_LowPowerCtrlParam_

typedef struct {
  uint8_T IO_Off_Delay;
  uint8_T ChipHibDelay;
  uint8_T HibDeadZone;
  uint8_T WakeUpPreFuncSec;
} type_LowPowerCtrlParam;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_VarBody4ActCtrlDailyStat_
#define DEFINED_TYPEDEF_FOR_type_VarBody4ActCtrlDailyStat_

typedef struct {
  uint8_T DayInfo;

  /* uint:0.001U */
  uint32_T ResidueDoseEst;

  /* unit:0.001U */
  uint32_T TotalAmountAcc;

  /* unit:0.001U */
  uint32_T DailyAmountAcc;

  /* unit:0.001U */
  uint32_T LargeAmountAcc;
} type_VarBody4ActCtrlDailyStat;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_MotionCtrl2RecordCtrlDailyStatMsg_
#define DEFINED_TYPEDEF_FOR_type_MotionCtrl2RecordCtrlDailyStatMsg_

typedef struct {
  type_MsgHead Head;
  type_VarBody4ActCtrlDailyStat Body;
} type_MotionCtrl2RecordCtrlDailyStatMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_RT_
#define DEFINED_TYPEDEF_FOR_type_RT_

typedef struct {
  /* the year just keeps the last three digits for its value here, for example, year 2019 just keeps 019 for its value */
  uint8_T Time[6];
} type_RT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_HMICtrlParam_
#define DEFINED_TYPEDEF_FOR_type_HMICtrlParam_

typedef struct {
  /* long press threshold:3
     unit: sec */
  uint16_T LPTh;

  /* key stick threshold:6
     unit: sec */
  uint16_T KSTh;
  uint16_T DeepIdleTime;

  /* 1 FUN1   .....Home
     2 FUN2   .....+
     3 FUN3   .....- */
  uint8_T KeyId;
} type_HMICtrlParam;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_MsgBody4FlashAccessMsg_
#define DEFINED_TYPEDEF_FOR_type_MsgBody4FlashAccessMsg_

typedef struct {
  uint8_T MajorId;
  uint8_T MinorId;
  uint8_T Data[132];
} type_MsgBody4FlashAccessMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_FlashAccessMsg_
#define DEFINED_TYPEDEF_FOR_type_FlashAccessMsg_

typedef struct {
  type_MsgHead Head;
  type_MsgBody4FlashAccessMsg Body;
} type_FlashAccessMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_VarBody4ActCtrlDynVar_
#define DEFINED_TYPEDEF_FOR_type_VarBody4ActCtrlDynVar_

typedef struct {
  /* unit:maybe 0.001U
     or Encoder cnt, depend onthis signal's usage */
  uint32_T TargetDose;

  /* for baserate: TimeInfo is the unique time tag,(year-2000)*12+month*31+day*48+halfhourIndex
     for largedose:TimeInfo is the unique time tag,(year-2000)*12+month*31+day*48+quarterIndex */
  uint16_T TimeInfo;

  /* unit:maybe 0.001U
     or Encoder cnt
     depend onthis signal's usage */
  uint32_T CompleteDose;
} type_VarBody4ActCtrlDynVar;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_MotionCtrl2RecordCtrlDoseInfoMsg_
#define DEFINED_TYPEDEF_FOR_type_MotionCtrl2RecordCtrlDoseInfoMsg_

/* OpCode=01 means dailydose inprocess subelement time hit
   02 means dailydose lastelement time hit
   11 largedose inprocess subelement time hit
   12 largedose last subelement time hit */
typedef struct {
  type_MsgHead Head;
  type_VarBody4ActCtrlDynVar Body;
} type_MotionCtrl2RecordCtrlDoseInfoMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_MsgBody4RecordCtrl2Security_
#define DEFINED_TYPEDEF_FOR_type_MsgBody4RecordCtrl2Security_

typedef struct {
  uint8_T Data[10];
} type_MsgBody4RecordCtrl2Security;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_RecordCtrl2SecurityMsg_
#define DEFINED_TYPEDEF_FOR_type_RecordCtrl2SecurityMsg_

typedef struct {
  type_MsgHead Head;
  type_MsgBody4RecordCtrl2Security Body;
} type_RecordCtrl2SecurityMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_FirmwareCtrlParam_
#define DEFINED_TYPEDEF_FOR_type_FirmwareCtrlParam_

typedef struct {
  uint8_T CurDataBagBytes;
  uint32_T TargetDataBagNo;
  uint32_T CurDataBagNo;
  uint32_T TargetCRC32Val;
  uint32_T PrevCRC32Val;
  boolean_T boolGetHead;
  boolean_T boolGet1Bag;
  boolean_T boolTransIng;
  boolean_T boolBagNoHit;
  boolean_T boolCRC32Hit;
} type_FirmwareCtrlParam;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_VarBody4DoseCtrlDoseCtrlParam_
#define DEFINED_TYPEDEF_FOR_type_VarBody4DoseCtrlDoseCtrlParam_

typedef struct {
  uint8_T Concentration;
  uint8_T LowDoseTHValue;

  /* unit:0.1u */
  uint16_T MaxLargeDose;

  /* unit:0.1U */
  uint16_T MaxBaseRate;

  /* unit:1U */
  uint8_T MaxDailyDose;
} type_VarBody4DoseCtrlDoseCtrlParam;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_VarBody4DoseCtrlLargeDoseConfig_
#define DEFINED_TYPEDEF_FOR_type_VarBody4DoseCtrlLargeDoseConfig_

typedef struct {
  /* unit:0.1U */
  uint16_T LargeDoseTotalAmount;

  /* 0:regular
     1:rectangular
     2:triangular
     3:bar
     4:double wave */
  uint8_T DeliveryConfig;

  /* unit:minute
     minimum value:15 minutes */
  uint8_T PermittedTime;

  /* unit:0.1U
     DWMCase stands for double wave mode case */
  uint16_T RegularDose4DWMCase;

  /* year=rem(year-2000,uint8(255))

     month*96*4+day*96*2+year*96+hour*4+idivide(minute,15)+1
     there are 4*15minute in one hour, so there are 4*24=96 sections to discriminate largedose task
     for on day. */
  uint16_T EffectiveDay;
  uint8_T CustomTimeConfig[20];
  uint8_T CustomDoseConfig[20];
} type_VarBody4DoseCtrlLargeDoseConfig;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_CatBody4DoseCtrl_
#define DEFINED_TYPEDEF_FOR_type_CatBody4DoseCtrl_

/* categorybody4dosectrl */
typedef struct {
  type_VarBody4DoseCtrlDoseCtrlParam DoseCtrlParam;

  /* unit:0.1u */
  uint8_T BaseRateConfig[48];

  /* unit:0.1u */
  uint8_T TempBaseRateConfig[48];
  uint8_T LastTBRConfigDay[3];
  type_VarBody4DoseCtrlLargeDoseConfig LargeDoseConfig;
} type_CatBody4DoseCtrl;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_CatBody4ActCtrl_
#define DEFINED_TYPEDEF_FOR_type_CatBody4ActCtrl_

/* categorybody4actctrl */
typedef struct {
  /* unit:0.1mL */
  uint8_T IniLoadedVol;

  /* unit:0.001
     the first 2 bytes of var(02,02) */
  uint16_T AdjustInputGain;

  /* unit:0.001
     the mid 2 bytes of var(02,02) */
  uint16_T AdjustPositiveOffset;

  /* unit:0.001
     the last 2 bytes of var(02,02) */
  uint16_T AdjustNegativeOffset;

  /* 0 means airexpel/delivery/homing stops
     1 means airexpel starts
     2.measn does delivery starts
     3.means homing starts. */
  uint8_T DeliverSwitch;
  type_VarBody4ActCtrlDynVar BaseRateDynVar;
  type_VarBody4ActCtrlDynVar LargeDoseDynVar;
  type_VarBody4ActCtrlDailyStat DailyDoseStatVar;
} type_CatBody4ActCtrl;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_CatBody4AlarmCtrl_
#define DEFINED_TYPEDEF_FOR_type_CatBody4AlarmCtrl_

typedef struct {
  /* 0:no vibration
     1:low level alarm and above
     2:mid level alarm and above
     3: hight level alarm and above */
  uint8_T AlarmCtrlConfig;

  /* use first 4 int32 elements to form a vector called "SSCurCritPolyFitVect"
     use this vector to polyfit relationship between "current integration" and "DeliveredDose"
     the unit of "current integration" ,represented by CI,is mA*mS, typical value may range from 100*100 to 500*3000
     the unit of "DeliveredDose" is 0.001U,represented by DD, typical value may range from 0.001 to 40U
     therefore, CI and DD can have uint32 datatype.
     the analytical expression is assumed as CI=c3*DD^3+c2*DD^2+c1*DD+c0
     since c0~c3 are not certain to be positive or negative, it is assumed that their LSB=0.001,and has int32 data type.

     use last 4 int32 elements to form a vector called "ProcTimeCritPolyFitVect"
     use this vector to polyfit relationship between "ProcTime" and "DeliveredDose"
     the unit of "current ProcTime" ,represented by PT,is mS, typical value may range from 1~100000
     the unit of "DeliveredDose" is 0.001U,represented by DD, typical value may range from 0.001 to 40U
     therefore, PT and DD can have uint32 datatype.
     the analytical expression is assumed as PT=p3*DD^3+p2*DD^2+p1*DD+p0
     since p0~p3 are not certain to be positive or negative, it is assumed that their LSB=0.001,and has int32 data type. */
  int32_T SSCurAndProcTimeCritPolyFitVect[8];
} type_CatBody4AlarmCtrl;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_CatBody4Firmware_
#define DEFINED_TYPEDEF_FOR_type_CatBody4Firmware_

typedef struct {
  uint32_T FirmwareSize;
  uint32_T FirmwareCRC32;

  /* The following value is the default value when system is started.
     0 means null
     the following value of FirmwareUpgradeCompleteFlag should be assigned accoriding to command received.
     for command 4, opcode 1 assign FirmwareUpgradeCompleteFlag=5
     5 means firmware head received
     for commmand 4 opcode 2,assign FirmwareUpgradeCompleteFlag=4
     4 means firmware uint databag has received.


     the following value of FirmwareUpgradeCompleteFlag should be assigned accoriding to the update result
     of FirmwareParam.
     1 means firmware checksum success
     2 means firmware checksum failure
     3 means firmware transmission timeout */
  uint8_T FirmwareUpgradeCompleteFlag;
} type_CatBody4Firmware;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_CatBody4SysSetting_
#define DEFINED_TYPEDEF_FOR_type_CatBody4SysSetting_

/* categorybody4dosectrl */
typedef struct {
  uint8_T SensitivityLevel;
  uint8_T SerialNo[10];

  /* 1byte:major MCU product version,fixed 20
     1byte:major MCU major version
     1byte:major MCU minor version
     1byte:minor MCU product version,fixed 20
     1byte:minor MCU major version
     1byte:major MCU minor version */
  uint8_T SoftwareVersionInfo[6];

  /* 1byte:major MCU product version,fixed 20
     1byte:major MCU major version, ascii code A~Z
     1byte:major MCU minor version */
  uint8_T HardwareVersionInfo[3];

  /* 175 means configurated by user
     187 means configurated by FCT
     other value means not configurated. */
  uint8_T FlashConfigFlag;
} type_CatBody4SysSetting;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Type_Occlusion_
#define DEFINED_TYPEDEF_FOR_Type_Occlusion_

typedef struct {
  /* (06,01) (06,02) (06,03) */
  uint32_T PT[99];

  /* (06,04) (06,05) (06,06) */
  uint32_T CI[99];
} Type_Occlusion;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_CatBody4Calibra_
#define DEFINED_TYPEDEF_FOR_type_CatBody4Calibra_

typedef struct {
  /* unit:1e-6*mV(mA)/LSB */
  uint32_T MajorMcu4ChADCResolution[4];

  /* unit:1e-6*mV(mA)/LSB */
  uint32_T MinorMcu4ChADCResolution[4];

  /* unit:1LSB */
  int16_T MajorMCU4ChADCOffset[4];

  /* uint:1 LSB */
  int16_T MinorMCU4ChADCOffset[4];
} type_CatBody4Calibra;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_SysVars_
#define DEFINED_TYPEDEF_FOR_type_SysVars_

typedef struct {
  type_CatBody4DoseCtrl DoseCtrl;
  type_CatBody4ActCtrl ActCtrl;
  type_CatBody4AlarmCtrl AlarmCtrl;
  type_CatBody4Firmware Firmware;
  type_CatBody4SysSetting SysSetting;
  Type_Occlusion Occlusion;
  type_CatBody4Calibra Calibra;
} type_SysVars;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_MsgBody4FlashResponseMsg_
#define DEFINED_TYPEDEF_FOR_type_MsgBody4FlashResponseMsg_

typedef struct {
  uint8_T MajorId;
  uint8_T MinorId;
  uint8_T Data[44];
} type_MsgBody4FlashResponseMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_FlashResponseMsg_
#define DEFINED_TYPEDEF_FOR_type_FlashResponseMsg_

typedef struct {
  type_MsgHead Head;
  type_MsgBody4FlashResponseMsg Body;
} type_FlashResponseMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_RecordCtrl2RTCtrlMsg_
#define DEFINED_TYPEDEF_FOR_type_RecordCtrl2RTCtrlMsg_

typedef struct {
  type_MsgHead Head;
  type_RT Body;
} type_RecordCtrl2RTCtrlMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_RecordCtrl2SysDiagMsg_
#define DEFINED_TYPEDEF_FOR_type_RecordCtrl2SysDiagMsg_

/* used to transmit criterion bytes from comm to recordctrl;
 */
typedef struct {
  type_MsgHead Head;
  type_MsgBody4GP1Byte Body;
} type_RecordCtrl2SysDiagMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_RecordCtrlParam_
#define DEFINED_TYPEDEF_FOR_type_RecordCtrlParam_

typedef struct {
  type_CommCtrlRecordInqResponseMsg RecordInqResponseMsg_IniVal;
  type_RecordCtrl2RTCtrlMsg RTCtrlMsg_IniVal;
  type_RecordCtrl2SecurityMsg SecurityMsg_IniVal;
  type_FlashAccessMsg drvFlashAccessMsg_IniVal;
  type_RecordCtrl2SysDiagMsg SysDiagMsg_IniVal;
  uint8_T LargeDoseSubTaskMaxInterval_Minute;
} type_RecordCtrlParam;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_MotionSyn2SecurityMsg_
#define DEFINED_TYPEDEF_FOR_type_MotionSyn2SecurityMsg_

typedef struct {
  type_MsgHead Head;
  type_MsgBody4GPU32 Body;
} type_MotionSyn2SecurityMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_MsgBody4Security2SensorValue_
#define DEFINED_TYPEDEF_FOR_type_MsgBody4Security2SensorValue_

typedef struct {
  uint32_T Data[10];
} type_MsgBody4Security2SensorValue;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_Sensor2SecurityMsg_
#define DEFINED_TYPEDEF_FOR_type_Sensor2SecurityMsg_

typedef struct {
  type_MsgHead Head;
  type_MsgBody4Security2SensorValue Body;
} type_Sensor2SecurityMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_MsgBody4GPInt32_
#define DEFINED_TYPEDEF_FOR_type_MsgBody4GPInt32_

typedef struct {
  int32_T Data;
} type_MsgBody4GPInt32;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Type_CalibraMissionMsg_
#define DEFINED_TYPEDEF_FOR_Type_CalibraMissionMsg_

typedef struct {
  type_MsgHead Head;
  type_MsgBody4GPInt32 Body;
} Type_CalibraMissionMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Type_MsgBody4PerfEval_
#define DEFINED_TYPEDEF_FOR_Type_MsgBody4PerfEval_

typedef struct {
  uint32_T millSec;
  uint32_T mAmSecInteg;
} Type_MsgBody4PerfEval;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_PerfCalibraMsg_
#define DEFINED_TYPEDEF_FOR_type_PerfCalibraMsg_

typedef struct {
  type_MsgHead Head;
  Type_MsgBody4PerfEval Body;
} type_PerfCalibraMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_MsgBody4DoseMission_
#define DEFINED_TYPEDEF_FOR_type_MsgBody4DoseMission_

typedef struct {
  int32_T TargetEncCnt;
  uint32_T PermittedTime;
} type_MsgBody4DoseMission;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_DoseMissionMsg_
#define DEFINED_TYPEDEF_FOR_type_DoseMissionMsg_

typedef struct {
  type_MsgHead Head;
  type_MsgBody4DoseMission Body;
} type_DoseMissionMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_SysDiagMsg_
#define DEFINED_TYPEDEF_FOR_type_SysDiagMsg_

typedef struct {
  uint8_T MsgId;

  /* 1表示报警
     0表示取消 */
  boolean_T OpCode;
  uint8_T FMCode;
} type_SysDiagMsg;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_AlarmCtrlParam_
#define DEFINED_TYPEDEF_FOR_type_AlarmCtrlParam_

typedef struct {
  boolean_T MasterMode;
  uint8_T LowLevelInd[2];

  /* LowLevelInd: [1 2]
     MidLevelInd: [1 2]
     HighLevelInd: [1 2]
     AlarmSuspendTime: [1 2]
     AlarmOpTime: [1 2] */
  uint8_T MidLevelInd[2];

  /* LowLevelInd: [1 2]
     MidLevelInd: [1 2]
     HighLevelInd: [1 2]
     AlarmSuspendTime: [1 2]
     AlarmOpTime: [1 2] */
  uint8_T HighLevelInd[2];
} type_AlarmCtrlParam;

#endif

#ifndef DEFINED_TYPEDEF_FOR_type_AlarmCtrl2CommMsg_
#define DEFINED_TYPEDEF_FOR_type_AlarmCtrl2CommMsg_

typedef struct {
  uint8_T MsgId;
  boolean_T AlarmSwitch;
  uint8_T FMCode;
} type_AlarmCtrl2CommMsg;

#endif

/* Custom Type definition for Chart: '<S108>/Chart' */
#ifndef typedef_struct_T_test2_SysIntegration_T
#define typedef_struct_T_test2_SysIntegration_T

typedef struct {
  char_T Value[6];
} struct_T_test2_SysIntegration_T;

#endif                                 /*typedef_struct_T_test2_SysIntegration_T*/

#ifndef typedef_b_struct_T_test2_SysIntegrati_T
#define typedef_b_struct_T_test2_SysIntegrati_T

typedef struct {
  char_T Value[5];
} b_struct_T_test2_SysIntegrati_T;

#endif                                 /*typedef_b_struct_T_test2_SysIntegrati_T*/

/* Custom Type definition for Chart: '<S63>/Chart' */
#ifndef typedef_cell_wrap_0_test2_SysIntegrat_T
#define typedef_cell_wrap_0_test2_SysIntegrat_T

typedef struct {
  char_T f1[8];
} cell_wrap_0_test2_SysIntegrat_T;

#endif                                 /*typedef_cell_wrap_0_test2_SysIntegrat_T*/

/* Custom Type definition for Chart: '<S65>/Chart' */
#ifndef typedef_struct_T_test2_SysIntegrati_f_T
#define typedef_struct_T_test2_SysIntegrati_f_T

typedef struct {
  char_T Value[5];
} struct_T_test2_SysIntegrati_f_T;

#endif                                 /*typedef_struct_T_test2_SysIntegrati_f_T*/

#ifndef typedef_b_struct_T_test2_SysIntegra_l_T
#define typedef_b_struct_T_test2_SysIntegra_l_T

typedef struct {
  char_T Value[6];
} b_struct_T_test2_SysIntegra_l_T;

#endif                                 /*typedef_b_struct_T_test2_SysIntegra_l_T*/

/* Forward declaration for rtModel */
typedef struct tag_RTM_test2_SysIntegration_T RT_MODEL_test2_SysIntegration_T;

#endif                                 /* RTW_HEADER_test2_SysIntegration_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
