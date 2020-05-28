/*
 * File: test2_SysIntegration.h
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

#ifndef RTW_HEADER_test2_SysIntegration_h_
#define RTW_HEADER_test2_SysIntegration_h_
#include <float.h>
#include <math.h>
#include <string.h>
#ifndef test2_SysIntegration_COMMON_INCLUDES_
# define test2_SysIntegration_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "alarmIt.h"
#include "channelsADC.h"
#include "chkBleConnection.h"
#include "dataErase.h"
#include "dataRead.h"
#include "dataWrite.h"
#include "encoderRead.h"
#include "forceMotorStop.h"
#include "getBleData.h"
#include "getKeyVector.h"
#include "ioCtrl.h"
#include "lcdCtrl.h"
#include "lpCtrl.h"
#include "motorRunInSpeedMode.h"
#include "motorServoCtrl.h"
#include "readRTChip.h"
#include "recordErase.h"
#include "recordRead.h"
#include "recordWrite.h"
#include "sendBleData.h"
#include "servoStateInquiry.h"
#include "writeRTChip.h"
#endif                                 /* test2_SysIntegration_COMMON_INCLUDES_ */

#include "test2_SysIntegration_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>/MsgRouter1' */
typedef struct {
  struct {
    uint_T is_active_c41_test2_SysIntegrat:1;/* '<Root>/MsgRouter1' */
  } bitsForTID5;

  uint8_T prevMsg1Id;                  /* '<Root>/MsgRouter1' */
  uint8_T prevMsg2Id;                  /* '<Root>/MsgRouter1' */
} DW_MsgRouter1_test2_SysIntegr_T;

/* Block signals (default storage) */
typedef struct {
  type_SysVars VarSet;                 /* '<S63>/Chart' */
  type_BleDriveMsg BleMsgOut;          /* '<S34>/Chart' */
  uint8_T BleMsgOut_c[224];            /* '<S29>/Chart' */
  type_FlashAccessMsg CalibraResult2FlashDrv;/* '<S100>/Chart' */
  type_FlashAccessMsg drvFlashAccessMsgOut;/* '<S65>/Chart' */
  type_FlashAccessMsg Group1FlashAccessMsgOut;/* '<S14>/MsgRouter3' */
  type_FlashAccessMsg Group1FlashAccessMsgOut_d;/* '<S14>/MsgRouter2_100ms' */
  type_FlashAccessMsg Group1FlashAccessMsgOut_c;/* '<S14>/MsgRouter1' */
  type_FlashAccessMsg PCADoseCtrlMsg;  /* '<S52>/PCAMsgSend' */
  type_CommCtrlRecordInqResponseMsg CommVarLogMsgOut;/* '<S65>/Chart' */
  type_CommCtrlFirmwareMsg FirmwareMsgOut;/* '<S29>/Chart' */
  type_FlashResponseMsg LogDataMsg;    /* '<S63>/Chart' */
  type_CommCtrlDoseCtrlMsg DoseCtrlMsgOut;/* '<S29>/Chart' */
  uint8_T VarSizeInfo[42];             /* '<S63>/Chart' */
  type_CommCtrlCalibraMsg CalibraMsgOut;/* '<S29>/Chart' */
  type_CommCtrlAlarmCtrlMsg AlarmCtrlMsgOut;/* '<S29>/Chart' */
  type_MotionCtrl2RecordCtrlDailyStatMsg UnitDelay3;/* '<S65>/Unit Delay3' */
  type_MotionCtrl2RecordCtrlDailyStatMsg DailyStatMsg;/* '<S92>/Chart' */
  type_MotionCtrl2RecordCtrlDailyStatMsg ResidueDoseTrimMsg;/* '<S89>/ResidueDoseEval' */
  type_MotionCtrl2RecordCtrlDailyStatMsg Group1DDSMsgOut;/* '<Root>/MsgRouter6' */
  type_MotionCtrl2RecordCtrlDoseInfoMsg DynDoseInfoMsg;/* '<S92>/Chart' */
  type_RecordCtrl2SysDiagMsg SysDiagMsgOut;/* '<S65>/Chart' */
  type_RecordCtrl2RTCtrlMsg RTTimerSetMsgOut;/* '<S123>/RTMsgRuter' */
  type_RecordCtrl2RTCtrlMsg RTMsgOut;  /* '<S122>/Chart' */
  type_RecordCtrl2RTCtrlMsg RTTimeMsgOut;/* '<S65>/Chart' */
  type_PerfCalibraMsg PerfEvalMsg;     /* '<S83>/Chart' */
  type_MotionSyn2SecurityMsg SynReqMsg;/* '<S108>/Chart' */
  type_MotionSyn2SecurityMsg DoseMissionMsg;/* '<S108>/Chart' */
  type_MotionSyn2SecurityMsg DoseActionResultMsg;/* '<S108>/Chart' */
  type_LowPower2RTCtrlMsg UnitDelay_f; /* '<S42>/Unit Delay' */
  type_LowPower2RTCtrlMsg LP2RTMsgOut; /* '<S49>/Chart' */
  type_LowPower2RTCtrlMsg LP2RTMsgOut_m;/* '<S45>/Chart' */
  type_HMI2SecurityMsg UnitDelay3_d;   /* '<S29>/Unit Delay3' */
  type_HMI2SecurityMsg UnitDelay_p;    /* '<Root>/Unit Delay' */
  type_HMI2SecurityMsg UnitDelay1_c;   /* '<S21>/Unit Delay1' */
  type_HMI2SecurityMsg BusConversion_InsertedFor_MsgAd;
  type_HMI2SecurityMsg RTChipDiagMsg;  /* '<S123>/RTMsgRuter' */
  type_HMI2SecurityMsg TimerCtrlMsg;   /* '<S114>/Chart' */
  type_HMI2SecurityMsg AlarmOpMsgOut;  /* '<S113>/MsgAdaptor' */
  type_HMI2SecurityMsg AlarmACKMsgOut; /* '<S113>/Buffer' */
  type_HMI2SecurityMsg FlashWriteInforMsg;/* '<S19>/SysDiag_ProcessLogMsgRouter' */
  type_HMI2SecurityMsg SysDiagMsg;     /* '<S108>/Chart' */
  type_HMI2SecurityMsg LargeDoseTimeHitMsg;/* '<S108>/Chart' */
  type_HMI2SecurityMsg MotionCtrl2RTMsgOut;/* '<S106>/TaskScheduler' */
  type_HMI2SecurityMsg PerfACKMissionFinishMsg;/* '<S83>/Chart' */
  type_HMI2SecurityMsg OcclusionDiagMsg;/* '<S98>/Chart' */
  type_HMI2SecurityMsg MotorServoStateMsg;/* '<S96>/MotorRunDriver' */
  type_HMI2SecurityMsg ErrMsg;         /* '<S94>/Chart' */
  type_HMI2SecurityMsg ErrDiagMsg;     /* '<S89>/Chart' */
  type_HMI2SecurityMsg MotionStopACKMsg;/* '<S87>/Chart' */
  type_HMI2SecurityMsg Group1AlarmMsgOut;/* '<S17>/MsgRouter2' */
  type_HMI2SecurityMsg BubbleDetectionMsg;/* '<S69>/Chart' */
  type_HMI2SecurityMsg SysDiagMsgOut_k;/* '<S67>/Taskwith10msSamplingTime' */
  type_HMI2SecurityMsg SlaveMCUADCInquiryMsg;/* '<S67>/Taskwith10msSamplingTime' */
  type_HMI2SecurityMsg PressureDiagMsg;/* '<S67>/PressureSingularityDetector' */
  type_HMI2SecurityMsg RelativeTimerApplyMsg;/* '<S65>/Chart' */
  type_HMI2SecurityMsg SysDiagMsgOut_d;/* '<S63>/Chart' */
  type_HMI2SecurityMsg PCAAlarmMsg;    /* '<S52>/PCAMsgSend' */
  type_HMI2SecurityMsg KeyModeMsg;     /* '<S51>/Chart' */
  type_HMI2SecurityMsg KeyAlarmMsg;    /* '<S51>/Chart' */
  type_HMI2SecurityMsg Group1AlarmMsgOut_d;/* '<Root>/MsgRouter5' */
  type_HMI2SecurityMsg Group1AlarmMsgOut_m;/* '<Root>/MsgRouter4' */
  type_HMI2SecurityMsg Group1AlarmMsgOut_b;/* '<Root>/MsgRouter3' */
  type_HMI2SecurityMsg Group1AlarmMsgOut_f;/* '<Root>/MsgRouter2' */
  type_HMI2SecurityMsg Group1AlarmMsgOut_h;/* '<Root>/MsgRouter1' */
  type_HMI2SecurityMsg SecurityMsgOut; /* '<S49>/Chart' */
  type_HMI2SecurityMsg SysDiagMsg_a;   /* '<S49>/Chart' */
  type_DoseMissionMsg DoseMissionMsgOut;/* '<S106>/TaskScheduler' */
  type_DoseMissionMsg DoseCtrlMsgOut_j;/* '<S104>/Buffer' */
  type_CommCtrlSysSettingMsg SysSettingMsgOut;/* '<S29>/Chart' */
  type_CommCtrlRecordInqRequestMsg RecordInqMsgOut;/* '<S29>/Chart' */
  type_CommCtrlFCTestMsg FCTestMsgOut; /* '<S29>/Chart' */
  type_CommCtrlActCtrlMsg ActCtrlMsgOut;/* '<S29>/Chart' */
  Type_CalibraMissionMsg CalibraMsgOut_e;/* '<S100>/Chart' */
  type_VarBody4AlarmCtrl AlarmCtrlData;/* '<S112>/Chart' */
  type_SysDiagMsg BusCreator;          /* '<S112>/Bus Creator' */
  type_RT UnitDelay_a;                 /* '<S65>/Unit Delay' */
  type_RT RTTimeMsgOut_h;              /* '<S126>/Chart' */
  type_MsgBody4VoltSampling MajorSensorOutp;/* '<S1>/Chart' */
  type_MsgBody4SysStatus BusCreator_h; /* '<S49>/Bus Creator' */
  type_AlarmCtrl2CommMsg CommMsgOut;   /* '<S112>/Chart' */
  uint8_T xLevelAlarmPushMsg[8];       /* '<S113>/MemoryFilter' */
  boolean_T KeyVector[5];              /* '<S5>/Chart' */
  uint32_T DataTypeConversion1;        /* '<S83>/Data Type Conversion1' */
  uint32_T DiscreteTimeIntegrator1;    /* '<S103>/Discrete-Time Integrator1' */
  uint32_T DiscreteTimeIntegrator;     /* '<S103>/Discrete-Time Integrator' */
  uint32_T EncRdOutACC;                /* '<S68>/Chart1' */
  real32_T DataTypeConversion;         /* '<S67>/Data Type Conversion' */
  real32_T Enc2DoseGain;               /* '<S106>/TaskScheduler' */
  int32_T targetEncCnt;                /* '<S87>/Chart' */
  int32_T rtEncRdOut;                  /* '<S4>/Chart' */
  struct {
    uint_T boolMissionStop:1;          /* '<S108>/Chart' */
    uint_T EncRstEvt:1;                /* '<S108>/Chart' */
    uint_T boolMonitorEna:1;           /* '<S83>/Chart' */
    uint_T OcclusionJudgeEvt:1;        /* '<S83>/Chart' */
    uint_T boolCalibraEna:1;           /* '<S100>/Chart' */
    uint_T boolMotorForwardEnable:1;   /* '<S96>/MotorRunDriver' */
    uint_T boolMotorHomingEnable:1;    /* '<S96>/MotorRunDriver' */
    uint_T boolMotorServoEnable:1;     /* '<S96>/MotorRunDriver' */
    uint_T boolHomingEvt:1;            /* '<S94>/Chart' */
    uint_T EncClrEvt:1;                /* '<S89>/ResidueDoseEval' */
    uint_T boolTrimEnable:1;           /* '<S89>/Chart' */
    uint_T AirExpelEnaEvt:1;           /* '<S89>/Chart' */
  } bitsForTID0;

  struct {
    uint_T LowPowerMsgOut:1;           /* '<S112>/Chart' */
    uint_T AlarmCtrlEvt:1;             /* '<S112>/Chart' */
    uint_T HighLevelAlarmEvtStart:1;   /* '<S112>/Chart' */
    uint_T HighLevelAlarmEvtStop:1;    /* '<S112>/Chart' */
  } bitsForTID1;

  struct {
    uint_T KeyDownStatus:1;            /* '<S51>/Chart' */
  } bitsForTID2;

  struct {
    uint_T Wait4LPFinish:1;            /* '<S67>/Wait4LPFinish' */
    uint_T LogicalOperator1:1;         /* '<Root>/Logical Operator1' */
    uint_T CastToBoolean1:1;           /* '<S108>/Cast To Boolean1' */
    uint_T DataTypeConversion2:1;      /* '<S92>/Data Type Conversion2' */
    uint_T sendMsgEvt:1;               /* '<S113>/MemoryFilter' */
    uint_T PopAlarmEvt:1;              /* '<S113>/Actuator' */
    uint_T boolBufferEmpty:1;          /* '<S104>/Buffer' */
    uint_T boolDoseCtrlBusy:1;         /* '<S87>/Chart' */
    uint_T ServoOnEvt:1;               /* '<S87>/Chart' */
    uint_T ForceStopEvt:1;             /* '<S87>/Chart' */
    uint_T PopBufEvt:1;                /* '<S87>/Chart' */
    uint_T WorkStatus:1;               /* '<S65>/Chart' */
    uint_T boolAirExpelSwitchOn:1;     /* '<S65>/Chart' */
    uint_T boolNormalDeliverySwitchOn:1;/* '<S65>/Chart' */
    uint_T boolHomingOn:1;             /* '<S65>/Chart' */
    uint_T CalibraStartEvt:1;          /* '<S65>/Chart' */
    uint_T FlashInitFinishEvt:1;       /* '<S63>/Chart' */
    uint_T HomingStartEvt:1;           /* '<S55>/Chart1' */
    uint_T HomingStopEvt:1;            /* '<S55>/Chart1' */
    uint_T AirExpelStartEvt:1;         /* '<S55>/Chart' */
    uint_T AirExpelStopEvt:1;          /* '<S55>/Chart' */
    uint_T IOSwitchCmd:1;              /* '<S49>/Chart' */
    uint_T boolLCDOn:1;                /* '<S49>/Chart' */
    uint_T LCDCtrlEvt:1;               /* '<S49>/Chart' */
    uint_T LPSwitchCtrlEvt:1;          /* '<S49>/Chart' */
    uint_T IOSwitchCtrlEvt:1;          /* '<S49>/Chart' */
    uint_T boolLCDStatus:1;            /* '<S43>/Chart' */
    uint_T getBleDataEvt:1;            /* '<S29>/Chart' */
    uint_T sendBleDataEvt:1;           /* '<S29>/Chart' */
    uint_T BleConnStatus:1;            /* '<S30>/Chart' */
  } bitsForTID4;

  struct {
    uint_T boolBubbleDetected:1;       /* '<S5>/Chart' */
    uint_T boolPCADetected:1;          /* '<S5>/Chart' */
    uint_T boolShaftEnc:1;             /* '<S5>/Chart' */
  } bitsForTID5;

  struct {
    uint_T boolBusy:1;                 /* '<S52>/PCAMsgSend' */
  } bitsForTID6;

  struct {
    uint_T boolAbsTimeHold:1;          /* '<S126>/Chart' */
    uint_T boolRelativeTimerHold:1;    /* '<S126>/Chart' */
    uint_T InitTimerEvt:1;             /* '<S126>/Chart' */
    uint_T RTChipWriteEvt:1;           /* '<S123>/RTMsgRuter' */
    uint_T boolChipErrStatus:1;        /* '<S122>/Chart' */
    uint_T PushDose:1;                 /* '<S106>/TaskScheduler' */
    uint_T ClearQueueEvt:1;            /* '<S106>/TaskScheduler' */
  } bitsForTID7;

  uint8_T SysDiagMsgOut_c[3];          /* '<S112>/Chart' */
  boolean_T LogicalOperator[3];        /* '<S21>/Logical Operator' */
  boolean_T boolAlarmEmpty[3];         /* '<S113>/Buffer' */
  uint16_T UnitDelay_h;                /* '<S52>/Unit Delay' */
  uint16_T UnitDelay1_l;               /* '<S52>/Unit Delay1' */
  uint16_T Gain;                       /* '<S67>/Gain' */
  uint16_T LargeDoseRelativeSec;       /* '<S126>/Chart' */
  uint16_T In1_f;                      /* '<S128>/In1' */
  uint16_T NextHitTime;                /* '<S106>/TaskScheduler' */
  uint16_T rtCurrent;                  /* '<S67>/Taskwith10msSamplingTime' */
  uint16_T rtmAMotorCurrent;           /* '<S67>/Taskwith10msSamplingTime' */
  uint16_T SleepSec;                   /* '<S49>/Chart' */
  int16_T DataTypeConversion1_a;       /* '<S67>/Data Type Conversion1' */
  int16_T PressureADC;                 /* '<S20>/PressureADCRead' */
  int16_T OpMaxPressure;               /* '<S67>/PressureSingularityDetector' */
  int16_T OpMinPressure;               /* '<S67>/PressureSingularityDetector' */
  int16_T IdleMeanValuePressure;       /* '<S67>/PressureSingularityDetector' */
  uint8_T DataTypeConversion1_o;       /* '<S81>/Data Type Conversion1' */
  uint8_T BattEQ;                      /* '<S67>/Taskwith10msSamplingTime' */
  boolean_T UnitDelay_m;               /* '<S126>/Unit Delay' */
  boolean_T RateTransition;            /* '<S42>/Rate Transition' */
  boolean_T RateTransition1;           /* '<S42>/Rate Transition1' */
  boolean_T UnitDelay2_j;              /* '<S21>/Unit Delay2' */
  boolean_T boolSysEnable;             /* '<S126>/Chart' */
  boolean_T OcclusionObservationCancel;/* '<S113>/MsgAdaptor' */
} B_test2_SysIntegration_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  type_SysVars UnitDelay1_DSTATE;      /* '<S65>/Unit Delay1' */
  type_BleDriveMsg UnitDelay1_DSTATE_e;/* '<S29>/Unit Delay1' */
  type_CommCtrlRecordInqResponseMsg UnitDelay4_DSTATE;/* '<S29>/Unit Delay4' */
  uint8_T Data[132];                   /* '<S63>/Chart' */
  int32_T Seq[32];                     /* '<S100>/Chart' */
  uint32_T temp_mAmSecInteg[32];       /* '<S100>/Chart' */
  uint32_T temp_millSec[32];           /* '<S100>/Chart' */
  int32_T TargetEncCntQ[20];           /* '<S104>/Buffer' */
  uint32_T PermitTimeQ[20];            /* '<S104>/Buffer' */
  type_FlashResponseMsg UnitDelay5_DSTATE;/* '<S65>/Unit Delay5' */
  real32_T MemMatrix[10];              /* '<S98>/Chart' */
  int32_T temp_Var2BeKept4[8];         /* '<S63>/Chart' */
  uint8_T AlarmFMCodeMemory[24];       /* '<S113>/MemoryFilter' */
  type_FirmwareCtrlParam FirmwareParam;/* '<S63>/Chart' */
  uint8_T OpCodeQ[20];                 /* '<S104>/Buffer' */
  type_MotionCtrl2RecordCtrlDailyStatMsg UnitDelay3_DSTATE;/* '<S65>/Unit Delay3' */
  uint32_T temp_Var2BeKept7[4];        /* '<S63>/Chart' */
  uint32_T temp_Var2BeKept8[4];        /* '<S63>/Chart' */
  type_MotionCtrl2RecordCtrlDoseInfoMsg UnitDelay4_DSTATE_e;/* '<S65>/Unit Delay4' */
  type_RecordCtrl2SecurityMsg UnitDelay6_DSTATE;/* '<S65>/Unit Delay6' */
  uint8_T prevInpMsgIdVector[12];      /* '<S65>/Chart' */
  boolean_T SwitchOnVector_k[12];      /* '<S65>/Chart' */
  type_PerfCalibraMsg UnitDelay_DSTATE_b;/* '<S100>/Unit Delay' */
  type_PerfCalibraMsg UnitDelay3_DSTATE_c;/* '<S83>/Unit Delay3' */
  boolean_T Wait4LPFinish_DSTATE[10];  /* '<S67>/Wait4LPFinish' */
  uint8_T temp_Var2BeKept5[10];        /* '<S63>/Chart' */
  type_RecordCtrl2RTCtrlMsg UnitDelay1_DSTATE_dc;/* '<S123>/Unit Delay1' */
  real32_T DiscreteTransferFcn_states[2];/* '<S67>/Discrete Transfer Fcn' */
  int16_T temp_Var2BeKept10[4];        /* '<S63>/Chart' */
  int16_T temp_Var2BeKept9[4];         /* '<S63>/Chart' */
  uint16_T TypexLogId[4];              /* '<S63>/Chart' */
  uint8_T prevMsgInIdVector[8];        /* '<S113>/MemoryFilter' */
  uint8_T HighStack[8];                /* '<S113>/Buffer' */
  uint8_T LowStack[8];                 /* '<S113>/Buffer' */
  uint8_T MidStack[8];                 /* '<S113>/Buffer' */
  type_HMICtrlParam HMICtrlParam;      /* '<S51>/Chart' */
  type_AlarmCtrlParam AlarmCtrlParam;  /* '<S112>/Chart' */
  type_CommCtrlFCTestMsg UnitDelay2_DSTATE_p;/* '<S29>/Unit Delay2' */
  type_LowPower2RTCtrlMsg UnitDelay_DSTATE_n;/* '<S42>/Unit Delay' */
  type_LowPower2RTCtrlMsg UnitDelay1_DSTATE_d;/* '<S49>/Unit Delay1' */
  type_MotionSyn2SecurityMsg UnitDelay2_DSTATE_pc;/* '<S87>/Unit Delay2' */
  type_RT UnitDelay_DSTATE_j;          /* '<S65>/Unit Delay' */
  type_RT UnitDelay2_DSTATE_o;         /* '<S126>/Unit Delay2' */
  uint8_T VarMajorIdVect[6];           /* '<S63>/Chart' */
  uint8_T VarMinorIdVect[6];           /* '<S63>/Chart' */
  uint8_T KeyValueAcc[5];              /* '<S51>/Chart' */
  type_LowPowerCtrlParam CtrlParam;    /* '<S49>/Chart' */
  int32_T UnitDelay_DSTATE_i;          /* '<S4>/Unit Delay' */
  uint32_T UnitDelay_DSTATE_k;         /* '<S83>/Unit Delay' */
  uint32_T UnitDelay1_DSTATE_c;        /* '<S83>/Unit Delay1' */
  uint32_T DiscreteTimeIntegrator1_DSTATE;/* '<S103>/Discrete-Time Integrator1' */
  uint32_T DiscreteTimeIntegrator_DSTATE;/* '<S103>/Discrete-Time Integrator' */
  real32_T MemWeight;                  /* '<S98>/Chart' */
  int32_T clockTickCounter;            /* '<S89>/Pulse Generator' */
  int32_T clockTickCounter_l;          /* '<S100>/Pulse Generator' */
  int32_T clockTickCounter_i;          /* '<S94>/Pulse Generator' */
  int32_T clockTickCounter_i3;         /* '<S108>/Pulse Generator' */
  int32_T clockTickCounter_c;          /* '<S69>/Pulse Generator' */
  int32_T clockTickCounter_p;          /* '<S96>/Pulse Generator' */
  int32_T clockTickCounter_m;          /* '<S83>/Pulse Generator' */
  int32_T clockTickCounter_g;          /* '<S67>/Pulse Generator' */
  int32_T clockTickCounter_o;          /* '<S4>/Pulse Generator' */
  int32_T clockTickCounter_a;          /* '<S92>/Pulse Generator' */
  int32_T prevResidueEncCnt;           /* '<S108>/Chart' */
  int32_T targetEncCnt;                /* '<S108>/Chart' */
  int32_T temp_LastDoseEncCnt;         /* '<S106>/TaskScheduler' */
  int32_T temp_LeftDoseEncCnt;         /* '<S106>/TaskScheduler' */
  int32_T sfEvent_o;                   /* '<S65>/Chart' */
  int32_T sfEvent_gn;                  /* '<S63>/Chart' */
  uint32_T InitTimerEvtEventCounter;   /* '<S126>/Chart' */
  uint32_T TotalmSecond;               /* '<S126>/Chart' */
  uint32_T RTChipWriteEvtEventCounter; /* '<S123>/RTMsgRuter' */
  uint32_T OcclusionObservationCancelEvent;/* '<S113>/MsgAdaptor' */
  uint32_T sendMsgEvtEventCounter;     /* '<S113>/MemoryFilter' */
  uint32_T PopAlarmEvtEventCounter;    /* '<S113>/Actuator' */
  uint32_T AlarmCtrlEvtEventCounter;   /* '<S112>/Chart' */
  uint32_T HighLevelAlarmEvtStartEventCoun;/* '<S112>/Chart' */
  uint32_T HighLevelAlarmEvtStopEventCount;/* '<S112>/Chart' */
  uint32_T previousTicks;              /* '<S20>/PressureADCRead' */
  uint32_T EncRstEvtEventCounter;      /* '<S108>/Chart' */
  uint32_T temporalCounter_i2;         /* '<S108>/Chart' */
  uint32_T previousTicks_l;            /* '<S108>/Chart' */
  uint32_T PushDoseEventCounter;       /* '<S106>/TaskScheduler' */
  uint32_T ClearQueueEvtEventCounter;  /* '<S106>/TaskScheduler' */
  uint32_T temporalCounter_i1;         /* '<S106>/TaskScheduler' */
  uint32_T previousTicks_m;            /* '<S106>/TaskScheduler' */
  uint32_T OcclusionJudgeEvtEventCounter;/* '<S83>/Chart' */
  uint32_T boolHomingEvtEventCounter;  /* '<S94>/Chart' */
  uint32_T temporalCounter_i1_m;       /* '<S94>/Chart' */
  uint32_T prevMasterDynEnc;           /* '<S92>/Chart' */
  uint32_T EncClrEvtEventCounter;      /* '<S89>/ResidueDoseEval' */
  uint32_T AirExpelEnaEvtEventCounter; /* '<S89>/Chart' */
  uint32_T ServoOnEvtEventCounter;     /* '<S87>/Chart' */
  uint32_T ForceStopEvtEventCounter;   /* '<S87>/Chart' */
  uint32_T PopBufEvtEventCounter;      /* '<S87>/Chart' */
  uint32_T MotorEncCnt;                /* '<S69>/Chart' */
  uint32_T BattCurInteg;               /* '<S67>/Taskwith10msSamplingTime' */
  uint32_T BattEQMinuteConsumption;    /* '<S67>/Taskwith10msSamplingTime' */
  uint32_T temporalCounter_i1_e;       /* '<S67>/Taskwith10msSamplingTime' */
  uint32_T temp_EncCnt;                /* '<S67>/PressureSingularityDetector' */
  uint32_T temp_Sum;                   /* '<S67>/PressureSingularityDetector' */
  uint32_T CalibraStartEvtEventCounter;/* '<S65>/Chart' */
  uint32_T prevTotalDoseAmount;        /* '<S65>/Chart' */
  uint32_T temporalCounter_i1_g;       /* '<S65>/Chart' */
  uint32_T temporalCounter_i2_c;       /* '<S65>/Chart' */
  uint32_T temporalCounter_i3;         /* '<S65>/Chart' */
  uint32_T FlashInitFinishEvtEventCounter;/* '<S63>/Chart' */
  uint32_T HomingStartEvtEventCounter; /* '<S55>/Chart1' */
  uint32_T HomingStopEvtEventCounter;  /* '<S55>/Chart1' */
  uint32_T AirExpelStartEvtEventCounter;/* '<S55>/Chart' */
  uint32_T AirExpelStopEvtEventCounter;/* '<S55>/Chart' */
  uint32_T Day_mSecond;                /* '<S52>/PCAMsgSend' */
  uint32_T Op_mSecond;                 /* '<S52>/PCAMsgSend' */
  uint32_T temporalCounter_i1_p;       /* '<S51>/Chart' */
  uint32_T LCDCtrlEvtEventCounter;     /* '<S49>/Chart' */
  uint32_T LPSwitchCtrlEvtEventCounter;/* '<S49>/Chart' */
  uint32_T IOSwitchCtrlEvtEventCounter;/* '<S49>/Chart' */
  uint32_T temporalCounter_i1_d;       /* '<S49>/Chart' */
  uint32_T getBleDataEvtEventCounter;  /* '<S29>/Chart' */
  uint32_T sendBleDataEvtEventCounter; /* '<S29>/Chart' */
  uint32_T temporalCounter_i1_po;      /* '<S29>/Chart' */
  struct {
    uint_T is_c30_test2_SysIntegration:3;/* '<S108>/Chart' */
    uint_T is_Wait4Task:3;             /* '<S108>/Chart' */
    uint_T is_Sync:3;                  /* '<S108>/Chart' */
    uint_T is_MotorRun:3;              /* '<S96>/MotorRunDriver' */
    uint_T is_MotorServOn:3;           /* '<S96>/MotorRunDriver' */
    uint_T is_c23_test2_SysIntegration:3;/* '<S94>/Chart' */
    uint_T is_c17_test2_SysIntegration:3;/* '<S89>/Chart' */
    uint_T is_Wait:2;                  /* '<S108>/Chart' */
    uint_T is_Wait4Sync:2;             /* '<S108>/Chart' */
    uint_T is_Wait4Sync_c:2;           /* '<S108>/Chart' */
    uint_T is_PerfAnalysor:2;          /* '<S83>/Chart' */
    uint_T is_ServoAnalyzor:2;         /* '<S83>/Chart' */
    uint_T is_c26_test2_SysIntegration:2;/* '<S100>/Chart' */
    uint_T is_HomingStartSrv:2;        /* '<S94>/Chart' */
    uint_T is_VerifyHomingState:2;     /* '<S94>/Chart' */
    uint_T is_HomingStopSrv:2;         /* '<S94>/Chart' */
    uint_T is_c21_test2_SysIntegration:2;/* '<S92>/Chart' */
    uint_T is_DoseDynInfoMonitor:2;    /* '<S92>/Chart' */
    uint_T is_OpEnd:2;                 /* '<S92>/Chart' */
    uint_T is_c18_test2_SysIntegration:2;/* '<S89>/ResidueDoseEval' */
    uint_T is_Op:2;                    /* '<S89>/ResidueDoseEval' */
    uint_T is_OpEnd_g:2;               /* '<S89>/ResidueDoseEval' */
    uint_T is_OpStart:2;               /* '<S89>/Chart' */
    uint_T is_OpStop:2;                /* '<S89>/Chart' */
    uint_T is_c43_test2_SysIntegration:2;/* '<S69>/Chart' */
    uint_T is_BubbleDetected:2;        /* '<S69>/Chart' */
    uint_T is_c42_test2_SysIntegration:2;/* '<S68>/Chart1' */
    uint_T is_Monitor:2;               /* '<S67>/PressureSingularityDetector' */
    uint_T is_Op_p:2;                  /* '<S67>/PressureSingularityDetector' */
    uint_T is_Monitor_o:2;             /* '<S67>/PressureSingularityDetector' */
    uint_T is_c46_test2_SysIntegration:2;/* '<S14>/MsgRouter1' */
    uint_T UnitDelay1_DSTATE_k:1;      /* '<Root>/Unit Delay1' */
    uint_T EnabledSubsystem_MODE:1;    /* '<S83>/Enabled Subsystem' */
    uint_T is_active_c18_test2_SysIntegrat:1;/* '<S89>/ResidueDoseEval' */
    uint_T is_active_c46_test2_SysIntegrat:1;/* '<S14>/MsgRouter1' */
    uint_T boolNewDeliveryMission:1;   /* '<S108>/Chart' */
    uint_T boolMissionUnfinish:1;      /* '<S108>/Chart' */
    uint_T boolSyn:1;                  /* '<S108>/Chart' */
    uint_T boolCtrlAccuracyFailure:1;  /* '<S108>/Chart' */
    uint_T boolOcclusionStop:1;        /* '<S83>/Chart' */
    uint_T boolSendBleDataEnable:1;    /* '<S100>/Chart' */
    uint_T sendPermitted:1;            /* '<S100>/Chart' */
    uint_T boolCallbackSucceed:1;      /* '<S96>/MotorRunDriver' */
    uint_T temp_ServoState:1;          /* '<S96>/MotorRunDriver' */
    uint_T boolFdbk:1;                 /* '<S94>/Chart' */
    uint_T boolDoseMissionMsgArrived:1;/* '<S92>/Chart' */
    uint_T prevStartUpMsgId:1;         /* '<S92>/Chart' */
    uint_T boolKeepUpdate:1;           /* '<S92>/Chart' */
    uint_T prevSysVarUpdateMsgId:1;    /* '<S89>/ResidueDoseEval' */
    uint_T boolStartUp:1;              /* '<S89>/ResidueDoseEval' */
    uint_T boolFDBK:1;                 /* '<S89>/Chart' */
  } bitsForTID0;

  struct {
    uint_T is_TaskAct:2;               /* '<S112>/Chart' */
    uint_T is_idle:2;                  /* '<S112>/Chart' */
    uint_T was_idle:2;                 /* '<S112>/Chart' */
    uint_T is_idle_g:2;                /* '<S112>/Chart' */
    uint_T was_idle_o:2;               /* '<S112>/Chart' */
    uint_T UnitDelay_DSTATE_f:1;       /* '<S21>/Unit Delay' */
    uint_T UnitDelay_DSTATE_lc:1;      /* '<S112>/Unit Delay' */
    uint_T UnitDelay1_DSTATE_eq:1;     /* '<S112>/Unit Delay1' */
    uint_T UnitDelay2_DSTATE_o1:1;     /* '<S112>/Unit Delay2' */
    uint_T is_active_c19_test2_SysIntegrat:1;/* '<S112>/Chart' */
    uint_T HighAlarmEnable:1;          /* '<S112>/Chart' */
    uint_T LowAlarmEnable:1;           /* '<S112>/Chart' */
    uint_T MidAlarmEnable:1;           /* '<S112>/Chart' */
  } bitsForTID1;

  struct {
    uint_T is_BattEQEstimator:3;       /* '<S67>/Taskwith10msSamplingTime' */
    uint_T is_SingleKeyModeIdent:3;    /* '<S51>/Chart' */
    uint_T is_c44_test2_SysIntegration:2;/* '<S20>/PressureADCRead' */
    uint_T is_c40_test2_SysIntegration:2;/* '<S67>/Taskwith10msSamplingTime' */
    uint_T is_BattEQEst:2;             /* '<S67>/Taskwith10msSamplingTime' */
    uint_T is_BattPowerAlarmManagement:2;/* '<S67>/Taskwith10msSamplingTime' */
    uint_T is_KeyModeIdentification:2; /* '<S51>/Chart' */
    uint_T is_active_c40_test2_SysIntegrat:1;/* '<S67>/Taskwith10msSamplingTime' */
    uint_T is_active_c48_test2_SysIntegrat:1;/* '<S51>/Chart' */
    uint_T boolSerialPortReliable:1;   /* '<S67>/Taskwith10msSamplingTime' */
    uint_T boolHappenMark:1;           /* '<S67>/Taskwith10msSamplingTime' */
    uint_T boolBatteryLow:1;           /* '<S67>/Taskwith10msSamplingTime' */
  } bitsForTID2;

  struct {
    uint_T is_UpgradeAndLogUpLoadManagemen:3;/* '<S63>/Chart' */
    uint_T is_Init:3;                  /* '<S63>/Chart' */
    uint_T was_Init:3;                 /* '<S63>/Chart' */
    uint_T is_LPCtrl:3;                /* '<S49>/Chart' */
    uint_T is_c32_test2_SysIntegration:2;/* '<S113>/MemoryFilter' */
    uint_T is_c38_test2_SysIntegration:2;/* '<S19>/SysDiag_ProcessLogMsgRouter' */
    uint_T is_ActuatorController:2;    /* '<S87>/Chart' */
    uint_T is_Idle:2;                  /* '<S87>/Chart' */
    uint_T is_TaskSynthesizer:2;       /* '<S87>/Chart' */
    uint_T is_c22_test2_SysIntegration:2;/* '<S65>/Chart' */
    uint_T is_TempBaseRateDumpManagement:2;/* '<S65>/Chart' */
    uint_T is_ThreeTypeDoseDeliveryPlanMan:2;/* '<S65>/Chart' */
    uint_T is_LargeDoseMonitor:2;      /* '<S65>/Chart' */
    uint_T is_GeneralDeliveryStateManageme:2;/* '<S65>/Chart' */
    uint_T is_DeliverySwitchOn:2;      /* '<S65>/Chart' */
    uint_T is_c56_test2_SysIntegration:2;/* '<S14>/MsgRouter3' */
    uint_T is_c55_test2_SysIntegration:2;/* '<S14>/MsgRouter2_100ms' */
    uint_T is_c2_test2_SysIntegration:2;/* '<S63>/Chart' */
    uint_T is_FlashDrv:2;              /* '<S63>/Chart' */
    uint_T was_FlashDrv:2;             /* '<S63>/Chart' */
    uint_T is_FlashDriveAct:2;         /* '<S63>/Chart' */
    uint_T is_VarClrService:2;         /* '<S63>/Chart' */
    uint_T was_VarClrService:2;        /* '<S63>/Chart' */
    uint_T is_Op_h:2;                  /* '<S63>/Chart' */
    uint_T is_LogClrService:2;         /* '<S63>/Chart' */
    uint_T was_LogClrService:2;        /* '<S63>/Chart' */
    uint_T is_c35_test2_SysIntegration:2;/* '<S55>/Chart1' */
    uint_T is_c34_test2_SysIntegration:2;/* '<S55>/Chart' */
    uint_T is_c6_test2_SysIntegration:2;/* '<S49>/Chart' */
    uint_T is_HoldStage:2;             /* '<S49>/Chart' */
    uint_T is_IOCtrlStage:2;           /* '<S49>/Chart' */
    uint_T is_c8_test2_SysIntegration:2;/* '<S29>/Chart' */
    uint_T is_Enable:2;                /* '<S29>/Chart' */
    uint_T UnitDelay_DSTATE_o0:1;      /* '<S87>/Unit Delay' */
    uint_T UnitDelay1_DSTATE_i:1;      /* '<S76>/Unit Delay1' */
    uint_T UnitDelay_DSTATE_ft:1;      /* '<S113>/Unit Delay' */
    uint_T is_active_c32_test2_SysIntegrat:1;/* '<S113>/MemoryFilter' */
    uint_T is_active_c15_test2_SysIntegrat:1;/* '<S113>/Actuator' */
    uint_T is_active_c16_test2_SysIntegrat:1;/* '<S87>/Chart' */
    uint_T is_active_c22_test2_SysIntegrat:1;/* '<S65>/Chart' */
    uint_T is_active_TempBaseRateAndLargeD:1;/* '<S65>/Chart' */
    uint_T is_active_LargeDoseDumpManageme:1;/* '<S65>/Chart' */
    uint_T is_active_TempBaseRateDumpManag:1;/* '<S65>/Chart' */
    uint_T is_active_ThreeTypeDoseDelivery:1;/* '<S65>/Chart' */
    uint_T is_active_GeneralDeliveryStateM:1;/* '<S65>/Chart' */
    uint_T is_active_c56_test2_SysIntegrat:1;/* '<S14>/MsgRouter3' */
    uint_T is_active_c2_test2_SysIntegrati:1;/* '<S63>/Chart' */
    uint_T is_active_FlashDriveAct:1;  /* '<S63>/Chart' */
    uint_T is_active_UpgradeAndLogUpLoadMa:1;/* '<S63>/Chart' */
    uint_T is_active_VarClrService:1;  /* '<S63>/Chart' */
    uint_T is_active_LogClrService:1;  /* '<S63>/Chart' */
    uint_T is_active_c35_test2_SysIntegrat:1;/* '<S55>/Chart1' */
    uint_T is_active_c6_test2_SysIntegrati:1;/* '<S49>/Chart' */
    uint_T is_active_c8_test2_SysIntegrati:1;/* '<S29>/Chart' */
    uint_T boolEnterActuatorBusy:1;    /* '<S87>/Chart' */
    uint_T boolLargeDoseMonitorEnable:1;/* '<S65>/Chart' */
    uint_T FlashAccessEnable:1;        /* '<S63>/Chart' */
    uint_T LogUpLoadEnable:1;          /* '<S63>/Chart' */
    uint_T boolLogReadTerminate:1;     /* '<S63>/Chart' */
    uint_T boolLogSend:1;              /* '<S63>/Chart' */
    uint_T FlashAccessErr:1;           /* '<S63>/Chart' */
    uint_T LogUpdateEnable:1;          /* '<S63>/Chart' */
    uint_T boolHibernation:1;          /* '<S49>/Chart' */
    uint_T boolWakeUpSuccess:1;        /* '<S49>/Chart' */
  } bitsForTID4;

  struct {
    uint_T is_active_c33_test2_SysIntegrat:1;/* '<S113>/MsgAdaptor' */
    uint_T is_active_c53_test2_SysIntegrat:1;/* '<Root>/MsgRouter6' */
    uint_T is_active_c52_test2_SysIntegrat:1;/* '<Root>/MsgRouter5' */
  } bitsForTID5;

  struct {
    uint_T is_PCACtrlMsgDetector:2;    /* '<S52>/PCAMsgSend' */
    uint_T is_PCADoseMonitor:2;        /* '<S52>/PCAMsgSend' */
    uint_T is_active_c49_test2_SysIntegrat:1;/* '<S52>/PCAMsgSend' */
    uint_T is_active_PCACtrlMsgDetector:1;/* '<S52>/PCAMsgSend' */
    uint_T is_active_PCADoseMonitor:1; /* '<S52>/PCAMsgSend' */
    uint_T boolPCASatHit:1;            /* '<S52>/PCAMsgSend' */
  } bitsForTID6;

  struct {
    uint_T is_RTCtrl:2;                /* '<S126>/Chart' */
    uint_T is_c29_test2_SysIntegration:2;/* '<S106>/TaskScheduler' */
    uint_T is_DoseTaskScheduler:2;     /* '<S106>/TaskScheduler' */
    uint_T is_LargeDoseTimerRunOrStop:2;/* '<S106>/TaskScheduler' */
    uint_T UnitDelay_DSTATE_b2:1;      /* '<S123>/Unit Delay' */
    uint_T UnitDelay1_DSTATE_m:1;      /* '<S126>/Unit Delay1' */
    uint_T is_active_c5_test2_SysIntegrati:1;/* '<S126>/Chart' */
    uint_T is_active_c4_test2_SysIntegrati:1;/* '<S123>/RTMsgRuter' */
    uint_T TimeSetSwitch1:1;           /* '<S126>/Chart' */
    uint_T TimeSetSwitch2:1;           /* '<S126>/Chart' */
    uint_T boolRelativeTimerEna:1;     /* '<S126>/Chart' */
    uint_T boolLargeDoseTimeHold:1;    /* '<S106>/TaskScheduler' */
    uint_T boolLargeDoseTimeRun:1;     /* '<S106>/TaskScheduler' */
    uint_T boolLastLargeSubDose:1;     /* '<S106>/TaskScheduler' */
  } bitsForTID7;

  type_HMI2SecurityMsg UnitDelay3_DSTATE_a;/* '<S29>/Unit Delay3' */
  type_HMI2SecurityMsg UnitDelay2_DSTATE;/* '<S65>/Unit Delay2' */
  type_HMI2SecurityMsg UnitDelay_DSTATE;/* '<S89>/Unit Delay' */
  type_HMI2SecurityMsg UnitDelay_DSTATE_l;/* '<S63>/Unit Delay' */
  type_HMI2SecurityMsg UnitDelay_DSTATE_o;/* '<S49>/Unit Delay' */
  type_HMI2SecurityMsg UnitDelay_DSTATE_oz;/* '<S94>/Unit Delay' */
  type_HMI2SecurityMsg UnitDelay_DSTATE_h;/* '<Root>/Unit Delay' */
  type_HMI2SecurityMsg UnitDelay1_DSTATE_o;/* '<S21>/Unit Delay1' */
  type_HMI2SecurityMsg UnitDelay2_DSTATE_f;/* '<S83>/Unit Delay2' */
  uint8_T temp_Var2BeKept6[3];         /* '<S63>/Chart' */
  uint8_T prevCommUpMsgIdVector[3];    /* '<S29>/Chart' */
  uint8_T SwitchOnVector[3];           /* '<S29>/Chart' */
  uint16_T UnitDelay_DSTATE_c;         /* '<S52>/Unit Delay' */
  uint16_T UnitDelay1_DSTATE_b;        /* '<S52>/Unit Delay1' */
  int16_T BattVolt;                    /* '<S67>/Taskwith10msSamplingTime' */
  int16_T MasterBattVoltADC;           /* '<S67>/Taskwith10msSamplingTime' */
  uint16_T RateTransition2_Buffer0;    /* '<S42>/Rate Transition2' */
  uint16_T prevYearInfo;               /* '<S126>/Chart' */
  uint16_T temporalCounter_i1_pl;      /* '<S113>/MemoryFilter' */
  uint16_T temporalCounter_i1_di;      /* '<S108>/Chart' */
  uint16_T NextSubBaseDoseTaskTimeHitSec;/* '<S106>/TaskScheduler' */
  uint16_T NextSubLargeDoseTaskTimeHitSec;/* '<S106>/TaskScheduler' */
  uint16_T SubLargeDoseId;             /* '<S106>/TaskScheduler' */
  uint16_T prevSubLargeDoseId;         /* '<S106>/TaskScheduler' */
  uint16_T temporalCounter_i2_d;       /* '<S94>/Chart' */
  uint16_T temporalCounter_i1_i;       /* '<S89>/ResidueDoseEval' */
  uint16_T temporalCounter_i2_k;       /* '<S89>/ResidueDoseEval' */
  uint16_T temporalCounter_i2_f;       /* '<S67>/Taskwith10msSamplingTime' */
  uint16_T prevBufferedLargeDose;      /* '<S65>/Chart' */
  uint16_T temporalCounter_i1_k;       /* '<S14>/MsgRouter1' */
  uint16_T LogId;                      /* '<S63>/Chart' */
  uint16_T LogIdThVal;                 /* '<S63>/Chart' */
  uint16_T temp_Var2BeKept1;           /* '<S63>/Chart' */
  uint16_T temp_Var2BeKept2;           /* '<S63>/Chart' */
  uint16_T temp_Var2BeKept3;           /* '<S63>/Chart' */
  uint16_T PCAACCDose;                 /* '<S52>/PCAMsgSend' */
  uint16_T PCASaturatedDose;           /* '<S52>/PCAMsgSend' */
  uint8_T prevSubBaseDoseId[2];        /* '<S106>/TaskScheduler' */
  boolean_T UnitDelay_DSTATE_o5;       /* '<S126>/Unit Delay' */
  boolean_T UnitDelay2_DSTATE_n;       /* '<S21>/Unit Delay2' */
  uint8_T prevRecordCtrlMsgId;         /* '<S126>/Chart' */
  uint8_T prevLowPowerMsgId;           /* '<S126>/Chart' */
  uint8_T LargeDoseTimerOpDt;          /* '<S126>/Chart' */
  uint8_T prevSysDiagMsgId;            /* '<S126>/Chart' */
  uint8_T prevDayInfo;                 /* '<S126>/Chart' */
  uint8_T prevMonthInfo;               /* '<S126>/Chart' */
  uint8_T tryTime;                     /* '<S126>/Chart' */
  uint8_T prevRelativeTimerApplyMsgId; /* '<S126>/Chart' */
  uint8_T LargeDoseTimerOpMode;        /* '<S126>/Chart' */
  uint8_T temporalCounter_i1_mw;       /* '<S126>/Chart' */
  uint8_T prevMsgIn1Id;                /* '<S123>/RTMsgRuter' */
  uint8_T prevMsgIn2Id;                /* '<S123>/RTMsgRuter' */
  uint8_T prevMsgIn3Id;                /* '<S123>/RTMsgRuter' */
  uint8_T prevInput1MsgId;             /* '<S113>/MsgAdaptor' */
  uint8_T prevInput2MsgId;             /* '<S113>/MsgAdaptor' */
  uint8_T temporalCounter_i1_j;        /* '<S113>/Actuator' */
  uint8_T prevSysDiagMsgId_e;          /* '<S112>/Chart' */
  uint8_T HighAlarmFMCode;             /* '<S112>/Chart' */
  uint8_T LowAlarmFMCode;              /* '<S112>/Chart' */
  uint8_T MidAlarmFMCode;              /* '<S112>/Chart' */
  uint8_T temporalCounter_i1_o;        /* '<S20>/PressureADCRead' */
  uint8_T prevCh1MsgId;                /* '<S19>/SysDiag_ProcessLogMsgRouter' */
  uint8_T prevCh2MsgId;                /* '<S19>/SysDiag_ProcessLogMsgRouter' */
  uint8_T prevDeliveryMissionId;       /* '<S108>/Chart' */
  uint8_T prevSlaveMsgId;              /* '<S108>/Chart' */
  uint8_T errTime;                     /* '<S108>/Chart' */
  uint8_T DoseMode;                    /* '<S108>/Chart' */
  uint8_T prevActuatorMsgId;           /* '<S108>/Chart' */
  uint8_T LargeDoseTaskNo;             /* '<S106>/TaskScheduler' */
  uint8_T QueueDepth;                  /* '<S104>/Buffer' */
  uint8_T prevDrvFdbkMsgId;            /* '<S83>/Chart' */
  uint8_T temp_OpCode;                 /* '<S83>/Chart' */
  uint8_T prevCalibraMsgId;            /* '<S100>/Chart' */
  uint8_T SeqIndex;                    /* '<S100>/Chart' */
  uint8_T i;                           /* '<S100>/Chart' */
  uint8_T CalibraIndex;                /* '<S100>/Chart' */
  uint8_T temporalCounter_i1_l;        /* '<S100>/Chart' */
  uint8_T prevFdbkMsgId;               /* '<S94>/Chart' */
  uint8_T prevDoseMissionMsgId;        /* '<S92>/Chart' */
  uint8_T prevMotionStopACKMsgId;      /* '<S92>/Chart' */
  uint8_T temp_OpCode_l;               /* '<S92>/Chart' */
  uint8_T prevDoseDynMsgId;            /* '<S92>/Chart' */
  uint8_T prevFDBKMsgId;               /* '<S89>/Chart' */
  uint8_T temporalCounter_i1_ig;       /* '<S89>/Chart' */
  uint8_T prevCalibraMsgId_n;          /* '<S87>/Chart' */
  uint8_T prevPerfAckMsgId;            /* '<S87>/Chart' */
  uint8_T prevDoseMsgId;               /* '<S87>/Chart' */
  uint8_T DoseMode_e;                  /* '<S87>/Chart' */
  uint8_T temporalCounter_i1_ob;       /* '<S87>/Chart' */
  uint8_T temporalCounter_i1_js;       /* '<S69>/Chart' */
  uint8_T prevSensorMsgId;             /* '<S67>/Taskwith10msSamplingTime' */
  uint8_T SlaveInfoInquiryRetryTimes;  /* '<S67>/Taskwith10msSamplingTime' */
  uint8_T BattOverLowFlag;             /* '<S67>/Taskwith10msSamplingTime' */
  uint8_T Counter;                     /* '<S67>/PressureSingularityDetector' */
  uint8_T ErrMode;                     /* '<S67>/PressureSingularityDetector' */
  uint8_T temp_i;                      /* '<S67>/PressureSingularityDetector' */
  uint8_T temporalCounter_i1_d5;       /* '<S67>/PressureSingularityDetector' */
  uint8_T inputChannel;                /* '<S65>/Chart' */
  uint8_T prevMsg1Id;                  /* '<S14>/MsgRouter3' */
  uint8_T temporalCounter_i1_ev;       /* '<S14>/MsgRouter3' */
  uint8_T prevMsg1Id_l;                /* '<S14>/MsgRouter2_100ms' */
  uint8_T prevMsg2Id;                  /* '<S14>/MsgRouter2_100ms' */
  uint8_T prevMsg1Id_ld;               /* '<S14>/MsgRouter1' */
  uint8_T prevMsg2Id_l;                /* '<S14>/MsgRouter1' */
  uint8_T prevMsg3Id;                  /* '<S14>/MsgRouter1' */
  uint8_T prevMsg4Id;                  /* '<S14>/MsgRouter1' */
  uint8_T OpCode;                      /* '<S63>/Chart' */
  uint8_T prevFlashAccessMsgId;        /* '<S63>/Chart' */
  uint8_T Channel;                     /* '<S63>/Chart' */
  uint8_T LogWriteMajorId;             /* '<S63>/Chart' */
  uint8_T LogWriteMinorId;             /* '<S63>/Chart' */
  uint8_T ParamExt;                    /* '<S63>/Chart' */
  uint8_T prevAlarmInfoMsgId;          /* '<S63>/Chart' */
  uint8_T LogOpCode;                   /* '<S63>/Chart' */
  uint8_T MinorId;                     /* '<S63>/Chart' */
  uint8_T MajorId;                     /* '<S63>/Chart' */
  uint8_T FlashErrTimes;               /* '<S63>/Chart' */
  uint8_T VarIndex;                    /* '<S63>/Chart' */
  uint8_T varindex;                    /* '<S63>/Chart' */
  uint8_T LogTypeIndex;                /* '<S63>/Chart' */
  uint8_T tempLog_LogWriteMajorId;     /* '<S63>/Chart' */
  uint8_T tempLog_LogWriteMinorId;     /* '<S63>/Chart' */
  uint8_T tempLog_ParamExt;            /* '<S63>/Chart' */
  uint8_T tempVar_LogWriteMajorId;     /* '<S63>/Chart' */
  uint8_T tempVar_LogWriteMinorId;     /* '<S63>/Chart' */
  uint8_T tempVar_ParamExt;            /* '<S63>/Chart' */
  uint8_T temporalCounter_i1_n;        /* '<S63>/Chart' */
  uint8_T temporalCounter_i2_dg;       /* '<S63>/Chart' */
  uint8_T temporalCounter_i3_n;        /* '<S63>/Chart' */
  uint8_T temporalCounter_i4;          /* '<S63>/Chart' */
  uint8_T prevRTCompMsgId;             /* '<S52>/PCAMsgSend' */
  uint8_T temporalCounter_i1_ls;       /* '<S52>/PCAMsgSend' */
  uint8_T prevMsg1Id_c;                /* '<Root>/MsgRouter6' */
  uint8_T prevMsg2Id_g;                /* '<Root>/MsgRouter6' */
  uint8_T prevMsg1Id_la;               /* '<Root>/MsgRouter5' */
  uint8_T prevMsg2Id_f;                /* '<Root>/MsgRouter5' */
  uint8_T prevLPCompTimeMsgId;         /* '<S49>/Chart' */
  uint8_T prevInSecurityMsgId;         /* '<S49>/Chart' */
  uint8_T SleepFailureTimes;           /* '<S49>/Chart' */
  uint8_T WakeUpMode;                  /* '<S49>/Chart' */
  uint8_T temp_errTime;                /* '<S49>/Chart' */
  uint8_T prevBleInMsgId;              /* '<S29>/Chart' */
  uint8_T sendChannel;                 /* '<S29>/Chart' */
  uint8_T BleOutMsgId;                 /* '<S29>/Chart' */
  uint8_T BleDataFrameId;              /* '<S34>/Chart' */
  DW_MsgRouter1_test2_SysIntegr_T sf_MsgRouter2_n;/* '<S17>/MsgRouter2' */
  DW_MsgRouter1_test2_SysIntegr_T sf_MsgRouter4;/* '<Root>/MsgRouter4' */
  DW_MsgRouter1_test2_SysIntegr_T sf_MsgRouter3;/* '<Root>/MsgRouter3' */
  DW_MsgRouter1_test2_SysIntegr_T sf_MsgRouter2;/* '<Root>/MsgRouter2' */
  DW_MsgRouter1_test2_SysIntegr_T sf_MsgRouter1;/* '<Root>/MsgRouter1' */
} DW_test2_SysIntegration_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Chart_Trig_ZCE[2];        /* '<S122>/Chart' */
  ZCSigState Chart_Trig_ZCE_g[2];      /* '<S114>/Chart' */
  ZCSigState Buffer_Trig_ZCE[2];       /* '<S113>/Buffer' */
  ZCSigState Chart_Trig_ZCE_j[2];      /* '<S108>/Chart' */
  ZCSigState Buffer_Trig_ZCE_o[3];     /* '<S104>/Buffer' */
  ZCSigState Chart_Trig_ZCE_n[2];      /* '<S83>/Chart' */
  ZCSigState Chart_Trig_ZCE_h[2];      /* '<S100>/Chart' */
  ZCSigState Chart_Trig_ZCE_p[2];      /* '<S98>/Chart' */
  ZCSigState MotorRunDriver_Trig_ZCE[5];/* '<S96>/MotorRunDriver' */
  ZCSigState Chart_Trig_ZCE_g4[3];     /* '<S94>/Chart' */
  ZCSigState Chart_Trig_ZCE_k[2];      /* '<S92>/Chart' */
  ZCSigState Chart_Trig_ZCE_f[3];      /* '<S89>/Chart' */
  ZCSigState Chart_Trig_ZCE_ff[2];     /* '<S69>/Chart' */
  ZCSigState Chart1_Trig_ZCE[3];       /* '<S68>/Chart1' */
  ZCSigState PressureSingularityDetector_Tri[5];/* '<S67>/PressureSingularityDetector' */
  ZCSigState Chart_Trig_ZCE_nm;        /* '<S47>/Chart' */
  ZCSigState Chart_Trig_ZCE_l;         /* '<S45>/Chart' */
  ZCSigState Chart_Trig_ZCE_d;         /* '<S43>/Chart' */
  ZCSigState Chart_Trig_ZCE_o[3];      /* '<S4>/Chart' */
  ZCSigState Chart_Trig_ZCE_ng;        /* '<S34>/Chart' */
  ZCSigState Chart_Trig_ZCE_lg;        /* '<S32>/Chart' */
  ZCSigState Chart_Trig_ZCE_pt;        /* '<S2>/Chart' */
} PrevZCX_test2_SysIntegration_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: CommCtrlParam
   * Referenced by: '<S29>/CommCtrlParam'
   */
  type_CommCtrlParam CommCtrlParam_Value;

  /* Expression: RecordCtrlParam
   * Referenced by: '<S65>/Constant'
   */
  type_RecordCtrlParam Constant_Value;

  /* Computed Parameter: BattVoltLUTUnitmV_Value
   * Referenced by: '<S67>/BattVoltLUTUnitmV'
   */
  int16_T BattVoltLUTUnitmV_Value[2];
} ConstP_test2_SysIntegration_T;

/* Real-time Model Data Structure */
struct tag_RTM_test2_SysIntegration_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTick2;
    uint32_T clockTick7;
    struct {
      uint16_T TID[8];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_test2_SysIntegration_T test2_SysIntegration_B;

/* Block states (default storage) */
extern DW_test2_SysIntegration_T test2_SysIntegration_DW;

/* External data declarations for dependent source files */
extern const type_HMI2SecurityMsg test2_SysIntegration_rtZtype_HMI2SecurityMsg;/* type_HMI2SecurityMsg ground */
extern const type_CommCtrlFCTestMsg
  test2_SysIntegration_rtZtype_CommCtrlFCTestMsg;/* type_CommCtrlFCTestMsg ground */
extern const type_FlashAccessMsg test2_SysIntegration_rtZtype_FlashAccessMsg;/* type_FlashAccessMsg ground */
extern const type_RecordCtrl2SecurityMsg
  test2_SysIntegration_rtZtype_RecordCtrl2SecurityMsg;/* type_RecordCtrl2SecurityMsg ground */
extern const type_RecordCtrl2RTCtrlMsg
  test2_SysIntegration_rtZtype_RecordCtrl2RTCtrlMsg;/* type_RecordCtrl2RTCtrlMsg ground */
extern const type_MotionSyn2SecurityMsg
  test2_SysIntegration_rtZtype_MotionSyn2SecurityMsg;/* type_MotionSyn2SecurityMsg ground */

/* Constant parameters (default storage) */
extern const ConstP_test2_SysIntegration_T test2_SysIntegration_ConstP;

/* Model entry point functions */
extern void test2_SysIntegration_initialize(void);
extern void test2_SysIntegration_step(void);
extern void test2_SysIntegration_terminate(void);

/* Real-time Model object */
extern RT_MODEL_test2_SysIntegration_T *const test2_SysIntegration_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S26>/Display' : Unused code path elimination
 * Block '<S34>/Display' : Unused code path elimination
 * Block '<S34>/Display1' : Unused code path elimination
 * Block '<S34>/Display2' : Unused code path elimination
 * Block '<S5>/Display1' : Unused code path elimination
 * Block '<S45>/Display' : Unused code path elimination
 * Block '<S45>/Scope' : Unused code path elimination
 * Block '<S45>/Scope1' : Unused code path elimination
 * Block '<S45>/Scope2' : Unused code path elimination
 * Block '<S45>/Scope3' : Unused code path elimination
 * Block '<S47>/Display' : Unused code path elimination
 * Block '<S47>/Scope' : Unused code path elimination
 * Block '<S113>/Display' : Unused code path elimination
 * Block '<S113>/Display1' : Unused code path elimination
 * Block '<S113>/Scope' : Unused code path elimination
 * Block '<S113>/Scope1' : Unused code path elimination
 * Block '<S113>/Scope2' : Unused code path elimination
 * Block '<S122>/Display' : Unused code path elimination
 * Block '<S122>/Display1' : Unused code path elimination
 * Block '<S122>/Display2' : Unused code path elimination
 * Block '<S122>/Display3' : Unused code path elimination
 * Block '<S49>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S42>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S115>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S112>/Data Type Conversion2' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'test2_SysIntegration'
 * '<S1>'   : 'test2_SysIntegration/4Channle_ADC_Value'
 * '<S2>'   : 'test2_SysIntegration/AlarmActuatorDrive'
 * '<S3>'   : 'test2_SysIntegration/CommTask_100ms'
 * '<S4>'   : 'test2_SysIntegration/EncoderDrv'
 * '<S5>'   : 'test2_SysIntegration/KeyRead'
 * '<S6>'   : 'test2_SysIntegration/LowPowerTask'
 * '<S7>'   : 'test2_SysIntegration/MsgRouter1'
 * '<S8>'   : 'test2_SysIntegration/MsgRouter2'
 * '<S9>'   : 'test2_SysIntegration/MsgRouter3'
 * '<S10>'  : 'test2_SysIntegration/MsgRouter4'
 * '<S11>'  : 'test2_SysIntegration/MsgRouter5'
 * '<S12>'  : 'test2_SysIntegration/MsgRouter6'
 * '<S13>'  : 'test2_SysIntegration/PCAManagement'
 * '<S14>'  : 'test2_SysIntegration/RecordCtrlTask_100ms'
 * '<S15>'  : 'test2_SysIntegration/Security'
 * '<S16>'  : 'test2_SysIntegration/SensorCtrl'
 * '<S17>'  : 'test2_SysIntegration/Subsystem'
 * '<S18>'  : 'test2_SysIntegration/Subsystem2'
 * '<S19>'  : 'test2_SysIntegration/Subsystem3'
 * '<S20>'  : 'test2_SysIntegration/Subsystem4'
 * '<S21>'  : 'test2_SysIntegration/SysDiag'
 * '<S22>'  : 'test2_SysIntegration/TimeManagement'
 * '<S23>'  : 'test2_SysIntegration/UI'
 * '<S24>'  : 'test2_SysIntegration/4Channle_ADC_Value/Chart'
 * '<S25>'  : 'test2_SysIntegration/AlarmActuatorDrive/Chart'
 * '<S26>'  : 'test2_SysIntegration/CommTask_100ms/BleConnectionChk'
 * '<S27>'  : 'test2_SysIntegration/CommTask_100ms/BleMsgSendUp'
 * '<S28>'  : 'test2_SysIntegration/CommTask_100ms/BleRecvMsg'
 * '<S29>'  : 'test2_SysIntegration/CommTask_100ms/Commctrl'
 * '<S30>'  : 'test2_SysIntegration/CommTask_100ms/BleConnectionChk/BleConnChk'
 * '<S31>'  : 'test2_SysIntegration/CommTask_100ms/BleConnectionChk/BleConnChk/Chart'
 * '<S32>'  : 'test2_SysIntegration/CommTask_100ms/BleMsgSendUp/BleSend'
 * '<S33>'  : 'test2_SysIntegration/CommTask_100ms/BleMsgSendUp/BleSend/Chart'
 * '<S34>'  : 'test2_SysIntegration/CommTask_100ms/BleRecvMsg/BleRecv'
 * '<S35>'  : 'test2_SysIntegration/CommTask_100ms/BleRecvMsg/BleRecv/Chart'
 * '<S36>'  : 'test2_SysIntegration/CommTask_100ms/Commctrl/Chart'
 * '<S37>'  : 'test2_SysIntegration/EncoderDrv/Chart'
 * '<S38>'  : 'test2_SysIntegration/KeyRead/Chart'
 * '<S39>'  : 'test2_SysIntegration/LowPowerTask/LCDDrive'
 * '<S40>'  : 'test2_SysIntegration/LowPowerTask/LPDrive'
 * '<S41>'  : 'test2_SysIntegration/LowPowerTask/LPIODrive'
 * '<S42>'  : 'test2_SysIntegration/LowPowerTask/Subsystem'
 * '<S43>'  : 'test2_SysIntegration/LowPowerTask/LCDDrive/LCDDrive'
 * '<S44>'  : 'test2_SysIntegration/LowPowerTask/LCDDrive/LCDDrive/Chart'
 * '<S45>'  : 'test2_SysIntegration/LowPowerTask/LPDrive/LPCtrl'
 * '<S46>'  : 'test2_SysIntegration/LowPowerTask/LPDrive/LPCtrl/Chart'
 * '<S47>'  : 'test2_SysIntegration/LowPowerTask/LPIODrive/IOCtrl'
 * '<S48>'  : 'test2_SysIntegration/LowPowerTask/LPIODrive/IOCtrl/Chart'
 * '<S49>'  : 'test2_SysIntegration/LowPowerTask/Subsystem/LowPowerCtrl'
 * '<S50>'  : 'test2_SysIntegration/LowPowerTask/Subsystem/LowPowerCtrl/Chart'
 * '<S51>'  : 'test2_SysIntegration/PCAManagement/HMICtrlTask'
 * '<S52>'  : 'test2_SysIntegration/PCAManagement/Subsystem'
 * '<S53>'  : 'test2_SysIntegration/PCAManagement/HMICtrlTask/Chart'
 * '<S54>'  : 'test2_SysIntegration/PCAManagement/Subsystem/PCAMsgSend'
 * '<S55>'  : 'test2_SysIntegration/RecordCtrlTask_100ms/EvtTransducer_100ms'
 * '<S56>'  : 'test2_SysIntegration/RecordCtrlTask_100ms/FlashDrive'
 * '<S57>'  : 'test2_SysIntegration/RecordCtrlTask_100ms/MsgRouter1'
 * '<S58>'  : 'test2_SysIntegration/RecordCtrlTask_100ms/MsgRouter2_100ms'
 * '<S59>'  : 'test2_SysIntegration/RecordCtrlTask_100ms/MsgRouter3'
 * '<S60>'  : 'test2_SysIntegration/RecordCtrlTask_100ms/RecordCtrlLogic_100ms'
 * '<S61>'  : 'test2_SysIntegration/RecordCtrlTask_100ms/EvtTransducer_100ms/Chart'
 * '<S62>'  : 'test2_SysIntegration/RecordCtrlTask_100ms/EvtTransducer_100ms/Chart1'
 * '<S63>'  : 'test2_SysIntegration/RecordCtrlTask_100ms/FlashDrive/FlashDrive'
 * '<S64>'  : 'test2_SysIntegration/RecordCtrlTask_100ms/FlashDrive/FlashDrive/Chart'
 * '<S65>'  : 'test2_SysIntegration/RecordCtrlTask_100ms/RecordCtrlLogic_100ms/RecordCtrlTask'
 * '<S66>'  : 'test2_SysIntegration/RecordCtrlTask_100ms/RecordCtrlLogic_100ms/RecordCtrlTask/Chart'
 * '<S67>'  : 'test2_SysIntegration/SensorCtrl/ADC'
 * '<S68>'  : 'test2_SysIntegration/SensorCtrl/EncoderCtrl_EvtDriven'
 * '<S69>'  : 'test2_SysIntegration/SensorCtrl/IOSignalUtilization_100ms'
 * '<S70>'  : 'test2_SysIntegration/SensorCtrl/ADC/PressureSingularityDetector'
 * '<S71>'  : 'test2_SysIntegration/SensorCtrl/ADC/Taskwith10msSamplingTime'
 * '<S72>'  : 'test2_SysIntegration/SensorCtrl/EncoderCtrl_EvtDriven/Chart1'
 * '<S73>'  : 'test2_SysIntegration/SensorCtrl/IOSignalUtilization_100ms/Chart'
 * '<S74>'  : 'test2_SysIntegration/Subsystem/MsgRouter2'
 * '<S75>'  : 'test2_SysIntegration/Subsystem2/Subsystem'
 * '<S76>'  : 'test2_SysIntegration/Subsystem2/Subsystem/ActuatorController_100ms'
 * '<S77>'  : 'test2_SysIntegration/Subsystem2/Subsystem/AirExpelService'
 * '<S78>'  : 'test2_SysIntegration/Subsystem2/Subsystem/DoseDynDelteTransmitter'
 * '<S79>'  : 'test2_SysIntegration/Subsystem2/Subsystem/HomingService'
 * '<S80>'  : 'test2_SysIntegration/Subsystem2/Subsystem/MotorRunDriver'
 * '<S81>'  : 'test2_SysIntegration/Subsystem2/Subsystem/OcclusionAnalysis'
 * '<S82>'  : 'test2_SysIntegration/Subsystem2/Subsystem/OcclusionCalibraService'
 * '<S83>'  : 'test2_SysIntegration/Subsystem2/Subsystem/PerformanceAnalysor'
 * '<S84>'  : 'test2_SysIntegration/Subsystem2/Subsystem/TaskBuffer'
 * '<S85>'  : 'test2_SysIntegration/Subsystem2/Subsystem/TaskScheduler'
 * '<S86>'  : 'test2_SysIntegration/Subsystem2/Subsystem/TaskSynchronizer_100ms'
 * '<S87>'  : 'test2_SysIntegration/Subsystem2/Subsystem/ActuatorController_100ms/ActuatorController_100ms'
 * '<S88>'  : 'test2_SysIntegration/Subsystem2/Subsystem/ActuatorController_100ms/ActuatorController_100ms/Chart'
 * '<S89>'  : 'test2_SysIntegration/Subsystem2/Subsystem/AirExpelService/Subsystem'
 * '<S90>'  : 'test2_SysIntegration/Subsystem2/Subsystem/AirExpelService/Subsystem/Chart'
 * '<S91>'  : 'test2_SysIntegration/Subsystem2/Subsystem/AirExpelService/Subsystem/ResidueDoseEval'
 * '<S92>'  : 'test2_SysIntegration/Subsystem2/Subsystem/DoseDynDelteTransmitter/Subsystem'
 * '<S93>'  : 'test2_SysIntegration/Subsystem2/Subsystem/DoseDynDelteTransmitter/Subsystem/Chart'
 * '<S94>'  : 'test2_SysIntegration/Subsystem2/Subsystem/HomingService/Subsystem'
 * '<S95>'  : 'test2_SysIntegration/Subsystem2/Subsystem/HomingService/Subsystem/Chart'
 * '<S96>'  : 'test2_SysIntegration/Subsystem2/Subsystem/MotorRunDriver/MotorRunDriver'
 * '<S97>'  : 'test2_SysIntegration/Subsystem2/Subsystem/MotorRunDriver/MotorRunDriver/MotorRunDriver'
 * '<S98>'  : 'test2_SysIntegration/Subsystem2/Subsystem/OcclusionAnalysis/OcclusionDetector'
 * '<S99>'  : 'test2_SysIntegration/Subsystem2/Subsystem/OcclusionAnalysis/OcclusionDetector/Chart'
 * '<S100>' : 'test2_SysIntegration/Subsystem2/Subsystem/OcclusionCalibraService/Subsystem'
 * '<S101>' : 'test2_SysIntegration/Subsystem2/Subsystem/OcclusionCalibraService/Subsystem/Chart'
 * '<S102>' : 'test2_SysIntegration/Subsystem2/Subsystem/PerformanceAnalysor/Chart'
 * '<S103>' : 'test2_SysIntegration/Subsystem2/Subsystem/PerformanceAnalysor/Enabled Subsystem'
 * '<S104>' : 'test2_SysIntegration/Subsystem2/Subsystem/TaskBuffer/TaskBuffer'
 * '<S105>' : 'test2_SysIntegration/Subsystem2/Subsystem/TaskBuffer/TaskBuffer/Buffer'
 * '<S106>' : 'test2_SysIntegration/Subsystem2/Subsystem/TaskScheduler/Subsystem'
 * '<S107>' : 'test2_SysIntegration/Subsystem2/Subsystem/TaskScheduler/Subsystem/TaskScheduler'
 * '<S108>' : 'test2_SysIntegration/Subsystem2/Subsystem/TaskSynchronizer_100ms/TaskSynchronizer_100ms'
 * '<S109>' : 'test2_SysIntegration/Subsystem2/Subsystem/TaskSynchronizer_100ms/TaskSynchronizer_100ms/Chart'
 * '<S110>' : 'test2_SysIntegration/Subsystem3/SysDiag_ProcessLogMsgRouter'
 * '<S111>' : 'test2_SysIntegration/Subsystem4/PressureADCRead'
 * '<S112>' : 'test2_SysIntegration/SysDiag/AlarmCtrl'
 * '<S113>' : 'test2_SysIntegration/SysDiag/SysDiagCtrl'
 * '<S114>' : 'test2_SysIntegration/SysDiag/TimerActionCtrl'
 * '<S115>' : 'test2_SysIntegration/SysDiag/AlarmCtrl/BusSigTransfermation'
 * '<S116>' : 'test2_SysIntegration/SysDiag/AlarmCtrl/Chart'
 * '<S117>' : 'test2_SysIntegration/SysDiag/SysDiagCtrl/Actuator'
 * '<S118>' : 'test2_SysIntegration/SysDiag/SysDiagCtrl/Buffer'
 * '<S119>' : 'test2_SysIntegration/SysDiag/SysDiagCtrl/MemoryFilter'
 * '<S120>' : 'test2_SysIntegration/SysDiag/SysDiagCtrl/MsgAdaptor'
 * '<S121>' : 'test2_SysIntegration/SysDiag/TimerActionCtrl/Chart'
 * '<S122>' : 'test2_SysIntegration/TimeManagement/RTChipDrive'
 * '<S123>' : 'test2_SysIntegration/TimeManagement/RTCtrlTask'
 * '<S124>' : 'test2_SysIntegration/TimeManagement/RTChipDrive/Chart'
 * '<S125>' : 'test2_SysIntegration/TimeManagement/RTCtrlTask/RTMsgRuter'
 * '<S126>' : 'test2_SysIntegration/TimeManagement/RTCtrlTask/Subsystem'
 * '<S127>' : 'test2_SysIntegration/TimeManagement/RTCtrlTask/Subsystem/AbsoluteTimeHold'
 * '<S128>' : 'test2_SysIntegration/TimeManagement/RTCtrlTask/Subsystem/AbsoluteTimeHold1'
 * '<S129>' : 'test2_SysIntegration/TimeManagement/RTCtrlTask/Subsystem/Chart'
 * '<S130>' : 'test2_SysIntegration/UI/Chart'
 */
#endif                                 /* RTW_HEADER_test2_SysIntegration_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
