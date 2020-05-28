/*
 * File: test2_SysIntegration.c
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

#include "test2_SysIntegration.h"
#include "test2_SysIntegration_private.h"

/* Named constants for Chart: '<S29>/Chart' */
#define test2_SysIntegration_IN_Disable ((uint8_T)1U)
#define test2_SysIntegration_IN_Enable ((uint8_T)2U)
#define test2_SysIntegration_IN_Recv   ((uint8_T)1U)
#define test2_SysIntegration_IN_Send   ((uint8_T)2U)

/* Named constants for Chart: '<S4>/Chart' */
#define test2_SysInteg_event_UpDateTick (2)
#define test2_SysIntegration_event_Rst1 (0)
#define test2_SysIntegration_event_Rst2 (1)

/* Named constants for Chart: '<S49>/Chart' */
#define test2_IN_WaitForRespBeforeSleep ((uint8_T)2U)
#define test2_SysIntegra_IN_IOCtrlStage ((uint8_T)2U)
#define test2_SysIntegra_IN_LPCtrlStage ((uint8_T)4U)
#define test2_SysIntegra_IN_ShallowHold ((uint8_T)2U)
#define test2_SysIntegra_IN_WakeUpSlave ((uint8_T)5U)
#define test2_SysIntegrati_IN_HandShake ((uint8_T)1U)
#define test2_SysIntegrati_IN_HoldStage ((uint8_T)1U)
#define test2_SysIntegratio_IN_DeepHold ((uint8_T)1U)
#define test2_SysIntegration_IN_Idle   ((uint8_T)3U)
#define test2_SysIntegration_IN_Init   ((uint8_T)1U)
#define test2_SysIntegration_IN_LPCtrl ((uint8_T)2U)
#define test2__IN_SlaveMcuWakeUpFailure ((uint8_T)3U)

/* Named constants for Chart: '<S51>/Chart' */
#define test2_SysInteg_IN_NoKeyDetected ((uint8_T)1U)
#define test2_SysIntegr_IN_IdentifyStop ((uint8_T)1U)
#define test2_SysIntegration_IN_KS     ((uint8_T)2U)
#define test2_SysIntegration_IN_LP     ((uint8_T)3U)
#define test2_SysIntegration_IN_SP     ((uint8_T)4U)
#define test2_Sys_IN_SingleKeyModeIdent ((uint8_T)2U)

/* Named constants for Chart: '<S52>/PCAMsgSend' */
#define test2_SysIntegrati_event_PCAEvt (0)
#define test2_SysIntegration_IN_Idle_k ((uint8_T)1U)
#define test2_SysIntegration_IN_None   ((uint8_T)1U)
#define test2_SysIntegration_IN_Op_h   ((uint8_T)2U)
#define test2_SysIntegration_IN_PCA    ((uint8_T)2U)
#define test2_SysIntegration_IN_Sticky ((uint8_T)3U)

/* Named constants for Chart: '<S63>/Chart' */
#define IN_Wait4FirstBag_LogUpLoadReque ((uint8_T)4U)
#define t_IN_InitEachMemberVarFromFlash ((uint8_T)2U)
#define t_IN_KeepFirmwareVarValueConfig ((uint8_T)5U)
#define test2_IN_Wait4VarFlashClrFinish ((uint8_T)2U)
#define test2_S_IN_InitFromFlashSucceed ((uint8_T)4U)
#define test2_Sy_IN_ChkFlashWriteStatus ((uint8_T)1U)
#define test2_Sy_IN_Var0104Write_Update ((uint8_T)2U)
#define test2_SysIn_IN_InitFromFirmware ((uint8_T)3U)
#define test2_SysInt_IN_LogExportCtrlOp ((uint8_T)2U)
#define test2_SysInt_IN_UpdateScreenLog ((uint8_T)3U)
#define test2_SysInteg_IN_GetOneDataBag ((uint8_T)1U)
#define test2_SysIntegr_event_LogClrEvt (0)
#define test2_SysIntegr_event_VarClrEvt (2)
#define test2_SysIntegra_event_LogOpEvt (1)
#define test2_SysIntegrat_IN_FlashDrive ((uint8_T)1U)
#define test2_SysIntegrati_IN_VarAccess ((uint8_T)3U)
#define test2_SysIntegratio_IN_FlashDrv ((uint8_T)2U)
#define test2_SysIntegration_IN_Dead   ((uint8_T)1U)
#define test2_SysIntegration_IN_Init_b ((uint8_T)2U)
#define test2_SysIntegration_IN_Warning ((uint8_T)3U)

/* Named constants for Chart: '<S65>/Chart' */
#define event_LastLargeDoseSubTaskArriv (1)
#define event_ProcessLargeDoseSubTaskAr (2)
#define test2_Sy_event_LargeDoseDumpEvt (0)
#define test2_SysI_IN_DeliverySwitchOff ((uint8_T)1U)
#define test2_SysIn_IN_DeliverySwitchOn ((uint8_T)2U)
#define test2_SysIn_IN_LargeDoseMonitor ((uint8_T)1U)
#define test2_SysInt_IN_LargeDoseCancel ((uint8_T)1U)
#define test2_SysInt_IN_NoLargeDoseTask ((uint8_T)2U)
#define test2_SysInte_IN_Initialization ((uint8_T)1U)
#define test2_SysInteg_event_TBRDumpEvt (3)
#define test2_SysIntegr_IN_MedicineOver ((uint8_T)2U)
#define test2_SysIntegr_IN_MsgInProcess ((uint8_T)2U)
#define test2_SysIntegra_IN_MedicineLow ((uint8_T)1U)
#define test2_SysIntegrati_IN_SwitchOff ((uint8_T)2U)
#define test2_SysIntegratio_IN_SwitchOn ((uint8_T)3U)
#define test2_SysIntegration_IN_Dump   ((uint8_T)1U)
#define test2_SysIntegration_IN_Idle_n ((uint8_T)2U)
#define test2_SysIntegration_IN_Unknown ((uint8_T)3U)

/* Named constants for Chart: '<S67>/PressureSingularityDetector' */
#define test2_S_event_ShaftEncoderPulse (3)
#define test2_SysInte_IN_Sure2Occlusion ((uint8_T)3U)
#define test2_SysInteg_event_UpdateTick (4)
#define test2_SysIntegration_IN_Monitor ((uint8_T)1U)
#define test2_SysIntegration_IN_NoError ((uint8_T)1U)
#define test2_SysIntegration_IN_NotSure ((uint8_T)2U)
#define test2_SysIntegration_IN_Prepare ((uint8_T)2U)
#define test2_SysIntegration_IN_Rest   ((uint8_T)3U)
#define test2__event_AirExpelStopAckEvt (0)
#define test2__event_DeliveryStopAckEvt (2)
#define test2_event_DeliveryStartAckEvt (1)

/* Named constants for Chart: '<S67>/Taskwith10msSamplingTime' */
#define IN_CalibraBattInitLevelByCurren ((uint8_T)2U)
#define test2_IN_BattPowerLowLevelAlarm ((uint8_T)1U)
#define test2_IN_BattPowerMidLevelAlarm ((uint8_T)2U)
#define test2_Sy_FuzzyLogicMotorCurrent ((uint16_T)70U)
#define test2_SysI_FuzzyLogicLCDCurrent ((uint16_T)50U)
#define test2_SysI_IN_SerialPortCommErr ((uint8_T)4U)
#define test2_SysI_IN_SlaveInfoReceived ((uint8_T)5U)
#define test2_SysIn_FuzzyLogicBGCurrent ((uint16_T)50U)
#define test2_SysInt_IN_AskforSlaveInfo ((uint8_T)1U)
#define test2_SysInt_IN_BattEQEstimator ((uint8_T)1U)
#define test2_SysInte_IN_BatteryOverLow ((uint8_T)3U)
#define test2_SysIntegrat_IN_BatteryLow ((uint8_T)2U)
#define test2_SysIntegrati_IN_BattEQEst ((uint8_T)1U)
#define test2_SysIntegration_IN_Init_a ((uint8_T)3U)
#define test2_SysIntegration_IN_Normal ((uint8_T)3U)
#define test2__LowPowerModeCurrentThVal ((uint16_T)2U)
#define test_IN_LowPowerIOSwitchFailure ((uint8_T)2U)

/* Named constants for Chart: '<S68>/Chart1' */
#define test2_SysIntegr_event_EncClrEvt (2)
#define test2_SysIntegr_event_EncRstEvt (1)
#define test2_SysIntegration_IN_Acc    ((uint8_T)1U)
#define test2__event_FlashInitFinishEvt (0)

/* Named constants for Chart: '<S69>/Chart' */
#define MotorEncoderThVal4BubbleDetecti ((uint8_T)20U)
#define ShaftEncoderThVal4BubbleDetecti ((uint8_T)4U)
#define test2_SysIn_IN_NoBubbleDetected ((uint8_T)2U)
#define test2_SysInt_event_UpdateTick_c (1)
#define test2_SysInte_IN_BubbleDetected ((uint8_T)1U)
#define test2_SysInteg_event_ShaftEncIO (0)
#define test2_SysIntegrati_IN_NotSure_i ((uint8_T)1U)
#define test2_SysIntegration_IN_Sure   ((uint8_T)2U)

/* Named constants for Chart: '<S87>/Chart' */
#define test2_SysI_IN_ChkUnfinishedTask ((uint8_T)1U)
#define test2_SysInt_IN_TaskSynthesizer ((uint8_T)2U)
#define test2_SysIntegr_IN_ActuatorBusy ((uint8_T)1U)
#define test2_SysIntegr_IN_Wait4NewTask ((uint8_T)3U)
#define test2_SysIntegra_IN_CalibraMode ((uint8_T)2U)
#define test2_Sys_IN_RecvUnfinishedTask ((uint8_T)2U)

/* Named constants for Chart: '<S89>/Chart' */
#define test2_Sy_event_StartAirExpelEvt (0)
#define test2_SysIntegr_IN_Wait4FdbkMsg ((uint8_T)2U)
#define test2_SysIntegr_event_UpdateEvt (2)
#define test2_SysIntegra_IN_AirExpelErr ((uint8_T)1U)
#define test2_SysIntegration_IN_OpStart ((uint8_T)3U)
#define test2_SysIntegration_IN_OpStop ((uint8_T)4U)
#define test2_Sys_IN_AirExpelCtrlNormal ((uint8_T)1U)
#define test2_Sys_event_StopAirExpelEvt (1)

/* Named constants for Chart: '<S89>/ResidueDoseEval' */
#define test2_Sy_IN_UpdatingResidueDose ((uint8_T)1U)
#define test2_SysI_IN_Wait4EncCntStable ((uint8_T)2U)
#define test2_SysInt_IN_Wait4EncClrSync ((uint8_T)2U)
#define test2_SysIntegr_IN_EncCntStable ((uint8_T)1U)
#define test2_SysIntegration_IN_OpEnd  ((uint8_T)3U)

/* Named constants for Chart: '<S92>/Chart' */
#define IN_Wait4SlaveEncCntSynchronizat ((uint8_T)2U)
#define test2_SysIntegrati_IN_EndAction ((uint8_T)1U)
#define test2_SysIntegration_IN_Init1  ((uint8_T)2U)
#define test2_SysIntegration_IN_Init2  ((uint8_T)3U)
#define test2_Sys_IN_DoseDynInfoMonitor ((uint8_T)1U)

/* Named constants for Chart: '<S94>/Chart' */
#define test2_SysI_IN_VerifyHomingState ((uint8_T)2U)
#define test2_SysI_event_HomingStartEvt (0)
#define test2_SysIn_event_HomingStopEvt (1)
#define test2_SysInte_IN_HomingStartSrv ((uint8_T)3U)
#define test2_SysInteg_IN_HomingStopSrv ((uint8_T)4U)
#define test2_SysIntegra_IN_HomingStart ((uint8_T)1U)
#define test2_SysIntegrat_IN_StopHoming ((uint8_T)2U)
#define test2_SysIntegrati_IN_ErrReport ((uint8_T)1U)
#define test2_SysIntegrati_IN_Unknown_j ((uint8_T)2U)
#define test2_SysIntegratio_IN_Normal_g ((uint8_T)1U)
#define test2_SysIntegration_IN_Finish ((uint8_T)2U)
#define test2_SysIntegration_IN_Init_n ((uint8_T)5U)
#define test2_SysIntegration_IN_Known  ((uint8_T)1U)

/* Named constants for Chart: '<S96>/MotorRunDriver' */
#define test2_SysIn_IN_InProcessInquiry ((uint8_T)2U)
#define test2_SysInt_event_ForceStopEvt (3)
#define test2_SysInte_event_ChargingEvt (1)
#define test2_SysInte_event_MotorServOn (0)
#define test2_SysInte_event_UpdateEvt_h (4)
#define test2_SysInteg_IN_MotorWithdraw ((uint8_T)4U)
#define test2_SysIntegr_event_HomingEvt (2)
#define test2_SysIntegra_IN_MotorAction ((uint8_T)3U)
#define test2_SysIntegra_IN_MotorCharge ((uint8_T)2U)
#define test2_SysIntegra_IN_MotorServOn ((uint8_T)3U)
#define test2_SysIntegrat_SpeedModeStop ((int8_T)0)
#define test2_SysIntegrati_IN_ForceStop ((uint8_T)1U)
#define test2_SysIntegratio_AirExpelDir ((int8_T)1)
#define test2_SysIntegratio_IN_ServoEnd ((uint8_T)4U)
#define test2_SysIntegration_HomingDir ((int8_T)-1)

/* Named constants for Chart: '<S98>/Chart' */
#define test2_SysInte_event_OccJudgeEvt (1)
#define test2_SysInteg_event_DiagClrEvt (0)

/* Named constants for Chart: '<S100>/Chart' */
#define test2_SysIntegr_IN_CalibraStart ((uint8_T)1U)
#define test2_SysIntegra_IN_CalibraStop ((uint8_T)2U)
#define test2_SysIntegra_IN_SendBleData ((uint8_T)3U)
#define test2_SysIntegration_SeqIter   ((uint8_T)32U)
#define test2_Sys_event_CalibraStartEvt (0)

/* Named constants for Chart: '<S83>/Chart' */
#define test2_SysInte_event_PerfEvalEvt (0)
#define test2_SysInte_event_UpdateEvt_e (1)
#define test2_SysInteg_IN_OcclusionStop ((uint8_T)2U)
#define test2_SysInteg_IN_ServoAnalyzor ((uint8_T)2U)
#define test2_SysIntegration_IN_Op_p   ((uint8_T)3U)

/* Named constants for Chart: '<S104>/Buffer' */
#define test2_SysIntegra_event_PushQEvt (1)
#define test2_SysIntegrat_event_ClrQEvt (2)
#define test2_SysIntegrat_event_PopQEvt (0)

/* Named constants for Chart: '<S106>/TaskScheduler' */
#define tes_IN_LargeDoseTimerStopOrHold ((uint8_T)2U)
#define test2_Sy_IN_LargeDoseTaskHitChk ((uint8_T)1U)
#define test2_SysI_IN_DoseTaskScheduler ((uint8_T)1U)
#define test2_SysIntegratio_ScrewLength (0.8F)
#define test2_SysIntegration_SqPiston  (109.358841F)
#define test2_Sys_IN_baseRateTaskHitChk ((uint8_T)2U)
#define test_IN_LargeDoseTimerRunOrStop ((uint8_T)1U)

/* Named constants for Chart: '<S108>/Chart' */
#define test2_Sy_event_dumpLargeDoseEvt (0)
#define test2_SysInt_IN_CtrlAccuracyBad ((uint8_T)2U)
#define test2_SysInt_IN_MissionComplete ((uint8_T)4U)
#define test2_SysInte_IN_CtrlAccuracyOK ((uint8_T)3U)
#define test2_SysInte_IN_Wait4MotorStop ((uint8_T)1U)
#define test2_SysInteg_IN_CommFailure_n ((uint8_T)1U)
#define test2_SysInteg_IN_Wait4Complete ((uint8_T)6U)
#define test2_SysInteg_IN_Wait4Sync_cbe ((uint8_T)3U)
#define test2_SysIntegr_IN_SynInProcess ((uint8_T)4U)
#define test2_SysIntegr_IN_Wait4Sync_cb ((uint8_T)2U)
#define test2_SysIntegra_IN_CommFailure ((uint8_T)2U)
#define test2_SysIntegra_IN_SynComplete ((uint8_T)2U)
#define test2_SysIntegra_IN_Wait4Sync_c ((uint8_T)5U)
#define test2_SysIntegrat_IN_ClrEncoder ((uint8_T)1U)
#define test2_SysIntegrat_IN_Terminate1 ((uint8_T)4U)
#define test2_SysIntegrati_IN_Terminate ((uint8_T)3U)
#define test2_SysIntegrati_IN_Wait4Sync ((uint8_T)1U)
#define test2_SysIntegrati_IN_Wait4Task ((uint8_T)2U)
#define test2_SysIntegration_ErrTimeMax ((uint8_T)10U)
#define test2_SysIntegration_IN_SynEnd ((uint8_T)3U)
#define test2_SysIntegration_IN_Sync   ((uint8_T)2U)
#define test2_SysIntegration_IN_Sync_b ((uint8_T)5U)
#define test2_SysIntegration_IN_Wait   ((uint8_T)5U)

/* Named constants for Chart: '<S19>/SysDiag_ProcessLogMsgRouter' */
#define test2_SysIntegration_IN_Router ((uint8_T)2U)

/* Named constants for Chart: '<S112>/Chart' */
#define test2_SysInte_IN_HighLevelAlarm ((uint8_T)1U)
#define test2_SysInteg_IN_LowLevelAlarm ((uint8_T)1U)
#define test2_SysInteg_IN_MidLevelAlarm ((uint8_T)1U)

/* Named constants for Chart: '<S113>/Buffer' */
#define test2_SysI_event_RecvDiagMsgEvt (1)
#define test2_SysInte_event_PopAlarmEvt (0)

/* Named constants for Chart: '<S113>/MemoryFilter' */
#define test2_SysIntegr_IN_FMCodeMemory ((uint8_T)1U)

/* Named constants for Chart: '<S114>/Chart' */
#define test2_SysIn_event_StartTimerEvt (0)
#define test2_SysInt_event_StopTimerEvt (1)

/* Named constants for Chart: '<S122>/Chart' */
#define test2_SysInte_event_InitChipEvt (0)
#define test2_SysIntegr_event_WriteChip (1)

const type_HMI2SecurityMsg test2_SysIntegration_rtZtype_HMI2SecurityMsg = {
  {
    0U,                                /* MsgId */
    0U                                 /* OpCode */
  },                                   /* Head */

  {
    0U                                 /* Data */
  }                                    /* Body */
} ;                                    /* type_HMI2SecurityMsg ground */

const type_CommCtrlFCTestMsg test2_SysIntegration_rtZtype_CommCtrlFCTestMsg = {
  {
    0U,                                /* MsgId */
    0U                                 /* OpCode */
  },                                   /* Head */

  {
    {
      0U, 0U, 0U, 0U }
    /* Data */
  }                                    /* Body */
} ;                                    /* type_CommCtrlFCTestMsg ground */

const type_FlashAccessMsg test2_SysIntegration_rtZtype_FlashAccessMsg = {
  {
    0U,                                /* MsgId */
    0U                                 /* OpCode */
  },                                   /* Head */

  {
    0U,                                /* MajorId */
    0U,                                /* MinorId */

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    /* Data */
  }                                    /* Body */
} ;                                    /* type_FlashAccessMsg ground */

const type_RecordCtrl2SecurityMsg
  test2_SysIntegration_rtZtype_RecordCtrl2SecurityMsg = {
  {
    0U,                                /* MsgId */
    0U                                 /* OpCode */
  },                                   /* Head */

  {
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    /* Data */
  }                                    /* Body */
} ;                                    /* type_RecordCtrl2SecurityMsg ground */

const type_RecordCtrl2RTCtrlMsg
  test2_SysIntegration_rtZtype_RecordCtrl2RTCtrlMsg = {
  {
    0U,                                /* MsgId */
    0U                                 /* OpCode */
  },                                   /* Head */

  {
    {
      0U, 0U, 0U, 0U, 0U, 0U }
    /* Time */
  }                                    /* Body */
} ;                                    /* type_RecordCtrl2RTCtrlMsg ground */

const type_MotionSyn2SecurityMsg
  test2_SysIntegration_rtZtype_MotionSyn2SecurityMsg = {
  {
    0U,                                /* MsgId */
    0U                                 /* OpCode */
  },                                   /* Head */

  {
    0U                                 /* Data */
  }                                    /* Body */
} ;                                    /* type_MotionSyn2SecurityMsg ground */

/* Block signals (default storage) */
B_test2_SysIntegration_T test2_SysIntegration_B;

/* Block states (default storage) */
DW_test2_SysIntegration_T test2_SysIntegration_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_test2_SysIntegration_T test2_SysIntegration_PrevZCX;

/* Real-time model */
RT_MODEL_test2_SysIntegration_T test2_SysIntegration_M_;
RT_MODEL_test2_SysIntegration_T *const test2_SysIntegration_M =
  &test2_SysIntegration_M_;

/* Forward declaration for local functions */
static void test2_SysIntegrat_BleMsgSendSyn(uint8_T x_Channel, uint8_T
  x_MsgCell_f1_Body_MajorId, uint8_T x_MsgCell_f1_Body_MinorId, const uint8_T
  x_MsgCell_f1_Body_Data[132], uint8_T x_MsgCell_f2_Head_OpCode, uint8_T
  x_MsgCell_f2_Body_Data, uint8_T x_MsgCell_f3_Head_OpCode, const uint8_T
  x_MsgCell_f3_Body_Data[4], uint8_T x_MsgOutId, uint8_T *y_MsgOutId, uint8_T
  y_BleDataOut[224]);
static void test2_SysIntegrat_ReformBleData(const uint8_T bleData[224], uint8_T
  prevMsgCellOut_f1_Head_MsgId, uint8_T prevMsgCellOut_f1_Head_OpCode, const
  uint8_T prevMsgCellOut_f1_Body_Data[48], uint8_T prevMsgCellOut_f2_Head_MsgId,
  uint8_T prevMsgCellOut_f2_Head_OpCode, const uint8_T
  prevMsgCellOut_f2_Body_Data[6], uint8_T prevMsgCellOut_f3_Head_MsgId, uint8_T
  prevMsgCellOut_f3_Head_OpCode, const uint8_T prevMsgCellOut_f3_Body_Data[32],
  uint8_T prevMsgCellOut_f4_Head_MsgId, uint8_T prevMsgCellOut_f4_Head_OpCode,
  const uint8_T prevMsgCellOut_f4_Body_Data[132], uint8_T
  prevMsgCellOut_f5_Head_MsgId, uint8_T prevMsgCellOut_f5_Head_OpCode, uint8_T
  prevMsgCellOut_f5_Body_Data, const type_MsgHead prevMsgCellOut_f6_Head, const
  type_MsgBody4RecordInqRequest prevMsgCellOut_f6_Body, const type_MsgHead
  prevMsgCellOut_f7_Head, const type_MsgBody4GP32Bytes prevMsgCellOut_f7_Body,
  const type_CommCtrlFCTestMsg prevMsgCellOut_f8, type_CommCtrlDoseCtrlMsg
  *y_DoseCtrlMsgOut, type_CommCtrlActCtrlMsg *y_ActCtrlMsgOut,
  type_CommCtrlAlarmCtrlMsg *y_AlarmCtrlMsgOut, type_CommCtrlFirmwareMsg
  *y_FirmwareMsgOut, type_CommCtrlSysSettingMsg *y_SysSettingMsgOut,
  type_CommCtrlRecordInqRequestMsg *y_RecordInqMsgOut, type_CommCtrlCalibraMsg
  *y_CalibraMsgOut, type_CommCtrlFCTestMsg *y_FCTestMsgOut);
static void test_ChkCommUpMsgIdVectorChange(const uint8_T prevMsgIdVector[3],
  uint8_T MsgInCell_f1_Head_MsgId, uint8_T MsgInCell_f2_Head_MsgId, uint8_T
  MsgInCell_f3_Head_MsgId, uint8_T y_SwitchOnVector[3], uint8_T
  y_prevMsgIdVector_newValue[3]);
static void ChkRecordCtrlMsgInIdVectorChang(const uint8_T
  x_prevMsgIdVector_oldValue[12], uint8_T x_MsgInCell_f1_Head_MsgId, uint8_T
  x_MsgInCell_f2_Head_MsgId, uint8_T x_MsgInCell_f3_Head_MsgId, uint8_T
  x_MsgInCell_f4_Head_MsgId, uint8_T x_MsgInCell_f5_Head_MsgId, uint8_T
  x_MsgInCell_f6_Head_MsgId, uint8_T x_MsgInCell_f7_Head_MsgId, uint8_T
  x_MsgInCell_f8_Head_MsgId, uint8_T x_MsgInCell_f9_Head_MsgId, uint8_T
  x_MsgInCell_f10_Head_MsgId, uint8_T x_MsgInCell_f11_Head_MsgId, uint8_T
  x_MsgInCell_f12_Head_MsgId, boolean_T y_SwitchOnVector[12], uint8_T
  y_prevMsgIdVector_newValue[12]);
static void test2_SysIntegr_DoseCtrlMsgProc(uint8_T xx_DoseCtrlMsgIn_Head_OpCode,
  const uint8_T xx_DoseCtrlMsgIn_Body_Data[48], uint8_T
  xx_drvFlashAccessMsgOut_Head_Ms, uint8_T xx_drvFlashAccessMsgOut_Body_Mi,
  const uint8_T xx_drvFlashAccessMsgOut_Body_Da[132], uint8_T
  *yy_drvFlashAccessMsgOut_Head_Ms, uint8_T *yy_drvFlashAccessMsgOut_Head_Op,
  uint8_T *yy_drvFlashAccessMsgOut_Body_Ma, uint8_T
  *yy_drvFlashAccessMsgOut_Body_Mi, uint8_T yy_drvFlashAccessMsgOut_Body_Da[132]);
static void test2_SysIntegra_ActCtrlMsgProc(uint8_T xx_ActCtrlMsgIn_Head_OpCode,
  const uint8_T xx_ActCtrlMsgIn_Body_Data[6], type_FlashAccessMsg
  *xx_drvFlashAccessMsgOut);
static void test2_SysIntegr_FirmwareMsgProc(uint8_T xx_FirmwareMsgIn_Head_OpCode,
  const uint8_T xx_FirmwareMsgIn_Body_Data[132], uint8_T
  xx_drvFlashAccessMsgOut_Head_Ms, uint8_T *yy_drvFlashAccessMsgOut_Head_Ms,
  uint8_T *yy_drvFlashAccessMsgOut_Head_Op, uint8_T
  *yy_drvFlashAccessMsgOut_Body_Ma, uint8_T *yy_drvFlashAccessMsgOut_Body_Mi,
  uint8_T yy_drvFlashAccessMsgOut_Body_Da[132]);
static void test2_SysInt_TransWord2TwoBytes(uint16_T x_Word, uint8_T y_2Bytes[2]);
static void test2_SysI_TransDWord2FourBytes(uint32_T x_DWord, uint8_T
  y_FourBytes[4]);
static void test2_SysIn_GrabSysVar2Bytes132(const type_SysVars *x3_SysVar,
  uint8_T x3_MajorId, uint8_T x3_MinorId, uint8_T SysVarIn132BytesForm[132]);
static void test2_SysIntegratio_GPMsgInProc(uint8_T x_MsgInCell_f1_Head_OpCode,
  const uint8_T x_MsgInCell_f1_Body_Data[48], uint8_T x_MsgInCell_f2_Head_OpCode,
  const uint8_T x_MsgInCell_f2_Body_Data[6], uint8_T x_MsgInCell_f3_Head_OpCode,
  const uint8_T x_MsgInCell_f3_Body_Data[32], uint8_T x_MsgInCell_f4_Head_OpCode,
  const uint8_T x_MsgInCell_f4_Body_Data[132], uint8_T
  x_MsgInCell_f5_Head_OpCode, uint8_T x_MsgInCell_f5_Body_Data, uint8_T
  x_MsgInCell_f6_Head_OpCode, uint8_T x_MsgInCell_f6_Body_MajorId, uint8_T
  x_MsgInCell_f6_Body_MinorId, uint8_T x_MsgInCell_f7_Head_OpCode, const uint8_T
  x_MsgInCell_f7_Body_Data[32], const uint8_T x_MsgInCell_f8_Body_Data[44],
  const type_MotionCtrl2RecordCtrlDoseInfoMsg x_MsgInCell_f9, const
  type_MotionCtrl2RecordCtrlDailyStatMsg x_MsgInCell_f10, const
  type_RecordCtrl2SecurityMsg x_MsgInCell_f11, const type_HMI2SecurityMsg
  x_MsgInCell_f12, uint8_T x_Channel, const type_FlashAccessMsg
  *x_drvFlashAccessMsgOut, const type_CommCtrlRecordInqResponseMsg
  *x_CommVarLogMsgOut, uint16_T x_prevBufferedLargeDose, uint32_T
  x_TotalDoseAmount, const type_SysVars *x_SysVar, boolean_T
  *y_boolSendCalibraEvt, type_FlashAccessMsg *y_CommVarLogMsgOut,
  type_FlashAccessMsg *y_drvFlashAccessMsgOut, uint16_T *y_prevBufferedLargeDose,
  uint32_T *y_TotalDoseAmount, uint8_T *y_LargeDoseSubTaskMode);
static void test_TempBaseRateDumpManagement(void);
static void test2_S_LargeDoseDumpManagement(void);
static void ThreeTypeDoseDeliveryPlanManage(void);
static void test2_SysInteg_DeliverySwitchOn(void);
static void test2_SysIntegrati_MsgInProcess(const
  type_MotionCtrl2RecordCtrlDoseInfoMsg *UnitDelay4, const type_HMI2SecurityMsg *
  UnitDelay2_f);
static void chartstep_c17_test2_SysIntegrat(const type_HMI2SecurityMsg
  *UnitDelay_k, const int32_T *sfEvent_h);
static void test2_SysIntegration_ADCRead(boolean_T x_Switch, int16_T *ADC_Ch1,
  int16_T *ADC_Ch2, int16_T *ADC_Ch3, int16_T *ADC_Ch4);
static void test2_SysIntegration_GetKeyData(boolean_T y_DataOut[8]);
static void test2_SysIn_LargeDoseDataConfig(uint16_T x_PCASaturatedDose,
  uint16_T x_PCAStandardDose, uint8_T x_rtInfoTimeDay, uint8_T
  y_LargeDose48Bytes[48]);
static void test2_SysIntegra_PCADoseMonitor(const int32_T *sfEvent_b);
static void test2_Sy_Trans32Uint32To132Byte(const uint32_T Uint32Array32Element
  [32], uint8_T y_132Byte[132]);
static void test2__enter_atomic_CalibraStop(void);
static void chartstep_c26_test2_SysIntegrat(const int32_T *sfEvent_kx);
static void SynLogDataFromSysVarIn20BytesFo(const type_SysVars *x2_VarSet,
  uint8_T x2_LogMajorId, uint8_T x2_LogMinorId, uint8_T
  LogDataFromSysVarIn20BytesForm[20]);
static void test2_SysIntegration_LogWrite(type_RT x_RTInfo, uint8_T x_LogMajorId,
  uint8_T x_LogMinorId, uint8_T x_Channel, uint8_T x_ParamExt, boolean_T
  *y_FlashAccessErr, uint8_T *y_Channel);
static void test2_SysInt_DeliverySwitchCtrl(uint8_T x_LogWriteMajorId, uint8_T
  x_LogWriteMinorId, uint8_T x_OpCode, uint8_T x_ParamExt, uint8_T *y_MajorId,
  uint8_T *y_MinorId, uint8_T y_Data[132]);
static void test2_SysIntegration_OneLogRead(uint8_T x_MajorId, const uint16_T
  x_LogIdVector[4], uint8_T x_Channel, uint8_T *y_LogAvailableFlag, uint8_T
  y_LogData[44]);
static void Wait4FirstBag_LogUpLoadRequest(void);
static void test2_SysInte_Var0104DataReform(uint8_T x_MinorId, uint8_T
  y_0104Data[3]);
static uint16_T test2_SysI_TransTwoBytes2Uint16(const uint8_T x_twoBytes[2]);
static uint16_T test2_Sy_TransTwoBytes2Uint16_p(const uint8_T x_twoBytes[3]);
static uint32_T test2_SysInt_Trans4Bytes2Uint32(const uint8_T x_FourBytes[4]);
static void test2_Sy_Transfer32ByteTo8Int32(const uint8_T x_32Bytes[32], int32_T
  y_8int32[8]);
static real_T test2_SysIntegration_hex2dec(const char_T s[8]);
static uint32_T test2_SysIntegra_CalculateCRC32(uint32_T x_CRC32Val, const
  uint8_T x_OneBagData[132], uint8_T x_DataBagBytes);
static type_FirmwareCtrlParam test2_SysIn_UpdateFirmwareParam(const
  type_FirmwareCtrlParam x3_oldFirmwareParam, const uint8_T x3_OneBagData[132]);
static void test2_SysIntegratio_VarUpdate_p(const type_SysVars *xx_varSet,
  type_FirmwareCtrlParam *xx_FirmwareParam, uint8_T xx_majorId, uint8_T
  xx_minorId, const uint8_T xx_data[132], type_SysVars *yy_varSet);
static void test2_SysInt_Var0104Write2Flash(uint8_T x_MajorId, uint8_T x_MinorId,
  uint8_T x_Data[3], uint8_T x_Channel, const type_SysVars *x_VarSet, const
  type_FirmwareCtrlParam x_FirmwareParam, boolean_T *y_FlashAccessErr, uint8_T
  *y_Channel, type_SysVars *y_VarSet, type_FirmwareCtrlParam *y_FirmwareParam);
static void test2_SysIntegration_VarUpdate(type_SysVars *xx_varSet, const
  uint8_T xx_data[132]);
static void test2_SysIntegra_VarWrite2Flash(uint8_T x_Data, uint8_T x_Channel,
  const type_SysVars *x_VarSet, const type_FirmwareCtrlParam x_FirmwareParam,
  boolean_T *y_FlashAccessErr, uint8_T *y_Channel, type_SysVars *y_VarSet,
  type_FirmwareCtrlParam *y_FirmwareParam);
static void test2_SysInteg_VarWrite2Flash_a(uint8_T x_MajorId, uint8_T x_MinorId,
  uint8_T x_Data[132], uint8_T x_Channel, const type_SysVars *x_VarSet, const
  type_FirmwareCtrlParam x_FirmwareParam, boolean_T *y_FlashAccessErr, uint8_T
  *y_Channel, type_SysVars *y_VarSet, type_FirmwareCtrlParam *y_FirmwareParam);
static boolean_T test2_SysIntegration_isequal(uint8_T varargin_1, uint8_T
  varargin_2);
static void test2_SysInt_LogSyncWriteAction(uint8_T x_MajorId, uint8_T x_MinorId,
  boolean_T *y_boolLogSyncAction, uint8_T *y_LogWriteMajorId, uint8_T
  *y_LogWriteMinorId);
static boolean_T test2_SysIntegratio_VarFlashClr(uint8_T x_Channel);
static void test2_SysIntegratio_VarClrStep1(const type_SysVars *x_VarSet,
  uint16_T *y_Var2BeKept_sub1, uint16_T *y_Var2BeKept_sub2, uint16_T
  *y_Var2BeKept_sub3, int32_T y_Var2BeKept_sub4[8], uint8_T y_Var2BeKept_sub5[10],
  uint8_T y_Var2BeKept_sub6[3], uint32_T y_Var2BeKept_sub7[4], uint32_T
  y_Var2BeKept_sub8[4], int16_T y_Var2BeKept_sub9[4], int16_T
  y_Var2BeKept_sub10[4]);
static void test2_SysInteg_exit_atomic_Idle(void);
static void test2_SysI_Trans8Int32To32Bytes(const int32_T x_8Int32[8], uint8_T
  y_32Bytes[32]);
static uint16_T test2_SysIntegrati_TransformInt(int16_T x_Obj);
static void test2_SysInte_VarWrite2Flash_ag(uint8_T x_MajorId, uint8_T x_MinorId,
  uint8_T x_Data[48], uint8_T x_Channel, const type_SysVars *x_VarSet, const
  type_FirmwareCtrlParam x_FirmwareParam, boolean_T *y_FlashAccessErr, uint8_T
  *y_Channel, type_SysVars *y_VarSet, type_FirmwareCtrlParam *y_FirmwareParam);
static void test2_SysIntegratio_VarClrStep2(type_SysVars *x_VarSet, uint8_T
  x_MajorId, uint8_T x_MinorId, uint16_T x_Var2BeKept_sub1, uint16_T
  x_Var2BeKept_sub2, uint16_T x_Var2BeKept_sub3, const int32_T
  x_Var2BeKept_sub4[8], const uint8_T x_Var2BeKept_sub5[10], const uint8_T
  x_Var2BeKept_sub6[3], const uint32_T x_Var2BeKept_sub7[4], const uint32_T
  x_Var2BeKept_sub8[4], const int16_T x_Var2BeKept_sub9[4], const int16_T
  x_Var2BeKept_sub10[4], uint8_T x_Channel, const type_FirmwareCtrlParam
  x_FirmwareParam);
static void test2_SysIntegrat_VarClrService(void);
static void test2_SysIntegration_LogClr(uint8_T x_MajorId, uint8_T x_Channel);
static void test2_SysIntegrat_LogClrService(void);
static void test2_SysIntegrat_FlashDriveAct(const type_HMI2SecurityMsg
  *UnitDelay_d);
static void enter_atomic_Wait4FirstBag_LogU(void);
static boolean_T test2_SysInteg_DailyDoseStatClr(type_SysVars *x_VarSet, const
  type_RT x_RTInfo, uint8_T x_DDSVarMajorId, uint8_T x_DDSVarMinorID);
static void test2__exit_internal_FlashDrive(void);
static void test2_enter_internal_FlashDrive(void);
static boolean_T test2_SysIntegr_ValidityChkPass(const uint8_T x_BuffData[132],
  uint8_T x_Size);
static void test_EachVarMemberInitFromFlash(uint8_T x_Channel, type_SysVars
  *x_VarSet, uint8_T x_MajorId, uint8_T x_MinorId, boolean_T *y_FlashAccessErr,
  uint8_T *y_Channel);
static void test2_SysIntegration_Init(const type_HMI2SecurityMsg *UnitDelay_d);
static void test2_Sy_VarSetInitFromFirmware(uint8_T
  *y_VarSet_DoseCtrl_DoseCtrlParam, uint8_T *y_VarSet_DoseCtrl_DoseCtrlPar_0,
  uint16_T *y_VarSet_DoseCtrl_DoseCtrlPar_1, uint16_T
  *y_VarSet_DoseCtrl_DoseCtrlPar_2, uint8_T *y_VarSet_DoseCtrl_DoseCtrlPar_3,
  uint8_T y_VarSet_DoseCtrl_BaseRateConfi[48], uint8_T
  y_VarSet_DoseCtrl_TempBaseRateC[48], uint8_T y_VarSet_DoseCtrl_LastTBRConfig[3],
  uint16_T *y_VarSet_DoseCtrl_LargeDoseConf, uint8_T
  *y_VarSet_DoseCtrl_LargeDoseCo_0, uint8_T *y_VarSet_DoseCtrl_LargeDoseCo_1,
  uint16_T *y_VarSet_DoseCtrl_LargeDoseCo_2, uint16_T
  *y_VarSet_DoseCtrl_LargeDoseCo_3, uint8_T y_VarSet_DoseCtrl_LargeDoseCo_4[20],
  uint8_T y_VarSet_DoseCtrl_LargeDoseCo_5[20], uint8_T
  *y_VarSet_ActCtrl_IniLoadedVol, uint16_T *y_VarSet_ActCtrl_AdjustInputGai,
  uint16_T *y_VarSet_ActCtrl_AdjustPositive, uint16_T
  *y_VarSet_ActCtrl_AdjustNegative, uint8_T *y_VarSet_ActCtrl_DeliverSwitch,
  type_VarBody4ActCtrlDynVar *y_VarSet_ActCtrl_BaseRateDynVar,
  type_VarBody4ActCtrlDynVar *y_VarSet_ActCtrl_LargeDoseDynVa,
  type_VarBody4ActCtrlDailyStat *y_VarSet_ActCtrl_DailyDoseStatV, uint8_T
  *y_VarSet_AlarmCtrl_AlarmCtrlCon, int32_T y_VarSet_AlarmCtrl_SSCurAndProc[8],
  type_CatBody4Firmware *y_VarSet_Firmware, type_CatBody4SysSetting
  *y_VarSet_SysSetting, Type_Occlusion *y_VarSet_Occlusion, type_CatBody4Calibra
  *y_VarSet_Calibra);
static void t_enter_atomic_InitFromFirmware(void);
static void test2_SysIn_enter_internal_Init(void);
static void test2_S_enter_internal_FlashDrv(void);
static uint8_T test2_SysIntegr_findFirstTarget(const uint8_T x_InputVect[5],
  uint8_T x_TargetValue);
static void test2_Sy_enter_atomic_HoldStage(void);
static void test2_SysIntegration_LPCtrl_c(const type_LowPower2RTCtrlMsg
  *UnitDelay1_p, const type_HMI2SecurityMsg *UnitDelay_o);
static boolean_T test2_SysIntegration_LCDCtrl(boolean_T x_boolLCDOn);
static uint32_T test2_SysIntegratio_InitCalibra(int16_T x_BattVolt, const
  int16_T x_BattVoltLUT[2], real32_T x_BattCapEqPresentation);
static uint8_T test2_SysIntegration_BattEQEst(int16_T x_BattVolt, const int16_T
  x_BattVoltLUT[2], uint32_T x_BattCurInteg, real32_T x_BattCapEqPresentation);
static void enter_atomic_SlaveInfoReceived(const int16_T *SlaveBattVoltADC);
static void test2_SysIntegr_BattEQEstimator(const boolean_T *UnitDelay1_o);
static void chartstep_c23_test2_SysIntegrat(const type_HMI2SecurityMsg
  *UnitDelay_i, const int32_T *sfEvent_cd);
static void test_RTChipMsgSubscribeCallback(boolean_T x_boolRTChipErrStatus,
  type_RecordCtrl2RTCtrlMsg *x_RTTimerSetMsgOut, type_HMI2SecurityMsg
  *x_RTChipDiagMsg, const type_RecordCtrl2RTCtrlMsg x_BroadcastMsgIn);
static void test2_SysInte_UpdateDateAndTime(uint16_T x_prevYearInfo, uint8_T
  x_prevMonthInfo, uint8_T x_prevDayInfo, uint32_T x_TotalmSecond, type_RT
  *y_RTTimeMsgOut, uint16_T *y_prevYearInfo, uint8_T *y_prevMonthInfo, uint8_T
  *y_prevDayInfo, uint32_T *y_TotalmSecond);
static uint32_T test2_SysIntegrat_TotalmSecCalc(const uint8_T Time[6]);
static void test2_SysIntegr_enter_atomic_Op(void);
static void test2_SysInt_ActuatorController(const type_MotionSyn2SecurityMsg
  *UnitDelay2, const type_HMI2SecurityMsg *UnitDelay2_o, const boolean_T
  *UnitDelay_m0);
static boolean_T test2_SysIntegration_isequal_d(real32_T varargin_1, real32_T
  varargin_2);
static void test2_SysInte_subBaseTimeHitChk(const type_RT x_RTTime, const
  type_CatBody4DoseCtrl *x_DoseCtrl, boolean_T x_DoseCtrlBusy, uint8_T
  TimeHitTolSec, uint16_T *y_SubDose, uint8_T y_SubDoseId[2], uint16_T
  *y_NextTimeHitSec, boolean_T *y_boolLastElement, uint16_T *y_HalfHourDose);
static void enter_atomic_baseRateTaskHitChk(void);
static void test2_SysInt_subLargeTimeHitChk(uint16_T x_RTSec, const
  type_CatBody4DoseCtrl *x_DoseCtrl, boolean_T x_DoseBusy, uint16_T x_SubDoseId,
  uint8_T x_TimeHitTol, boolean_T x_boolLastElementFound, uint16_T *y_SubDose,
  uint16_T *y_SubDoseId, uint16_T *y_NextTimeHitSec, boolean_T
  *y_boolLastElementFound, uint16_T *y_LargeDose);
static uint8_T test2_SysIntegrati_pushInAction(uint8_T x_QueueDepth, uint8_T
  x_DoseCtrlMsgIn_Head_OpCode, int32_T x_DoseCtrlMsgIn_Body_TargetEncC, uint32_T
  x_DoseCtrlMsgIn_Body_PermittedT, uint8_T x_OpCodeQ[20], int32_T
  x_TargetEncCntQ[20], uint32_T x_PermitTimeQ[20]);
static void test2_SysIntegrati_popOutAction(uint8_T x_QueueDepth, const uint8_T
  x_OpCodeQ[20], const int32_T x_TargetEncCntQ[20], const uint32_T
  x_PermitTimeQ[20], uint8_T x_DoseCtrlMsgOut_Head_MsgId, uint8_T
  x_DoseCtrlMsgOut_Head_OpCode, int32_T x_DoseCtrlMsgOut_Body_TargetEnc,
  uint32_T x_DoseCtrlMsgOut_Body_Permitted, uint8_T *y_QueueDepth, uint8_T
  y_OpCodeQ[20], int32_T y_TargetEncCntQ[20], uint32_T y_PermitTimeQ[20],
  uint8_T *y_DoseCtrlMsgOut_Head_MsgId, uint8_T *y_DoseCtrlMsgOut_Head_OpCode,
  int32_T *y_DoseCtrlMsgOut_Body_TargetEnc, uint32_T
  *y_DoseCtrlMsgOut_Body_Permitted);
static void chartstep_c28_test2_SysIntegrat(const int32_T *sfEvent_e);
static void test2_SysIntegration_Wait4Task(const int32_T *sfEvent_m);
static void te_enter_atomic_MissionComplete(void);
static void test2_SysIntegration_Sync(void);
static void chartstep_c30_test2_SysIntegrat(const int32_T *sfEvent_m);
static void chartstep_c42_test2_SysIntegrat(const int32_T *sfEvent_p);
static void chartstep_c43_test2_SysIntegrat(const int32_T *sfEvent_mr);
static boolean_T test2_SysIn_motorRunInSpeedMode(int8_T x_Direction);
static boolean_T test2_SysInte_ServoStateInquiry(void);
static boolean_T test2_SysIntegra_motorServoCtrl(int32_T x_targetCnt, boolean_T
  x_boolEnable);
static boolean_T test2_SysIntegra_ForceMotorStop(boolean_T x_boolStop);
static void chartstep_c24_test2_SysIntegrat(const int32_T *sfEvent_m2);
static boolean_T test2_SysInt_judgeOcclusionStop(const int32_T x_OccVect[8],
  int32_T x_targetEnct, uint32_T x_rt_milliSecond, uint32_T x_rt_mAmSInteg);
static void chartstep_c27_test2_SysIntegrat(const int32_T *sfEvent_c);
static real32_T test2_SysIntegra_JudgeMemMatrix(const real32_T Matrix1by10[10]);
static void chartstep_c25_test2_SysIntegrat(const int32_T *sfEvent_a);
static void chartstep_c39_test2_SysIntegrat(const int32_T *sfEvent_g);
static void test2_SysIntegration_ShiftUp(const uint8_T x_AlarmFMCodeMemory[24],
  uint8_T y_AlarmFMCodeMemory[24]);
static boolean_T test2_SysIntegration_isequal_o(const uint8_T varargin_1[8],
  const uint8_T varargin_2[8]);
static void test2_SysI_NonZeroElementPushIn(uint8_T x_AlarmFMCodeMemory[24],
  const uint8_T xData[8]);
static void test2_SysIntegr_PopHighestAlarm(type_HMI2SecurityMsg *x_AlarmMsgOut,
  const uint8_T x_HighStack[8], const uint8_T x_MidStack[8], const uint8_T
  x_LowStack[8], uint8_T y_HighStack[8], uint8_T y_MidStack[8], uint8_T
  y_LowStack[8], boolean_T y_boolAlarmEmpty[3]);
static void test2_SysIntegr_PushInAlarmInfo(uint8_T x_HighStack[8], uint8_T
  x_MidStack[8], uint8_T x_LowStack[8], const uint8_T x_AlarmPushInMsg[8],
  boolean_T y_boolAlarmEmpty[3]);
static void chartstep_c31_test2_SysIntegrat(const int32_T *sfEvent_d);
static void test2_Sys_enter_internal_idle_n(void);
static void test2_SysIn_enter_internal_idle(void);
static void test2_SysIntegration_TaskAct(void);
static void test2_SysI_enter_atomic_TaskAct(void);
static void test2_Sy_enter_internal_TaskAct(void);
static void test2_SysIntegration_alarmIt(uint8_T x_alarmCtrlData_AlarmLevel,
  boolean_T x_alarmCtrlData_boolMaster);
static void test2_SysIntegratio_sendBleData(uint8_T x_OutpData[224]);
static boolean_T test2_SysInteg_ChkBleConnection(void);
static void test2_SysIntegration_GetBleData(uint8_T x_BleDataFrameId, boolean_T *
  y_DtRdy, uint8_T y_DataOut[224], uint8_T *y_BleDataFrameId);
static int32_T test2_SysIntegra_EncoderCntRead(boolean_T bool_Switch);
static void chartstep_c45_test2_SysIntegrat(const int32_T *sfEvent_f);
static void test2_SysIntegration_LPCtrl(uint32_T x_SleepmSec, boolean_T
  *y_SwitchStatus, uint32_T *y_Comp_mSec);
static void test2_SysIntegration_IOCtrl(boolean_T x_SwitchCmd);
static uint16_T test2_Sys_BaseRateTimeInfoCrypt(const type_RT x_rtTime);
static uint32_T test2_SysI_TimeTagUniqueIDSynth(const type_RT x_rtTime);
static void chartstep_c21_test2_SysIntegrat(void);
static boolean_T test2_SysIntegr_detectPopAction(const uint8_T
  x_boolAlarmLoadedEmpty[3], const uint8_T x_boolAlarmOccuredEmpty[3]);
static void chartstep_c37_test2_SysIntegrat(const int32_T *sfEvent_k);
static boolean_T test2_SysInteg_ReadChipCallback(type_RecordCtrl2RTCtrlMsg
  *x_RTMsgOut);
static boolean_T test2_SysInte_WriteChipCallback(type_RecordCtrl2RTCtrlMsg
  x_RTMsgIn, type_RecordCtrl2RTCtrlMsg *x_RTMsgOut);
static void chartstep_c1_test2_SysIntegrati(const int32_T *sfEvent);
static void enter_internal_c9_test2_SysInte(void);
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (test2_SysIntegration_M->Timing.TaskCounters.TID[1])++;
  if ((test2_SysIntegration_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.002s, 0.0s] */
    test2_SysIntegration_M->Timing.TaskCounters.TID[1] = 0;
  }

  (test2_SysIntegration_M->Timing.TaskCounters.TID[2])++;
  if ((test2_SysIntegration_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.01s, 0.0s] */
    test2_SysIntegration_M->Timing.TaskCounters.TID[2] = 0;
  }

  (test2_SysIntegration_M->Timing.TaskCounters.TID[3])++;
  if ((test2_SysIntegration_M->Timing.TaskCounters.TID[3]) > 19) {/* Sample time: [0.02s, 0.0s] */
    test2_SysIntegration_M->Timing.TaskCounters.TID[3] = 0;
  }

  (test2_SysIntegration_M->Timing.TaskCounters.TID[4])++;
  if ((test2_SysIntegration_M->Timing.TaskCounters.TID[4]) > 99) {/* Sample time: [0.1s, 0.0s] */
    test2_SysIntegration_M->Timing.TaskCounters.TID[4] = 0;
  }

  (test2_SysIntegration_M->Timing.TaskCounters.TID[5])++;
  if ((test2_SysIntegration_M->Timing.TaskCounters.TID[5]) > 199) {/* Sample time: [0.2s, 0.0s] */
    test2_SysIntegration_M->Timing.TaskCounters.TID[5] = 0;
  }

  (test2_SysIntegration_M->Timing.TaskCounters.TID[6])++;
  if ((test2_SysIntegration_M->Timing.TaskCounters.TID[6]) > 499) {/* Sample time: [0.5s, 0.0s] */
    test2_SysIntegration_M->Timing.TaskCounters.TID[6] = 0;
  }

  (test2_SysIntegration_M->Timing.TaskCounters.TID[7])++;
  if ((test2_SysIntegration_M->Timing.TaskCounters.TID[7]) > 999) {/* Sample time: [1.0s, 0.0s] */
    test2_SysIntegration_M->Timing.TaskCounters.TID[7] = 0;
  }
}

/*
 * System initialize for atomic system:
 *    '<Root>/MsgRouter1'
 *    '<Root>/MsgRouter2'
 *    '<Root>/MsgRouter3'
 *    '<Root>/MsgRouter4'
 *    '<S17>/MsgRouter2'
 */
void test2_SysIntegr_MsgRouter1_Init(DW_MsgRouter1_test2_SysIntegr_T *localDW)
{
  localDW->bitsForTID5.is_active_c41_test2_SysIntegrat = 0;
}

/*
 * Output and update for atomic system:
 *    '<Root>/MsgRouter1'
 *    '<Root>/MsgRouter2'
 *    '<Root>/MsgRouter3'
 *    '<Root>/MsgRouter4'
 *    '<S17>/MsgRouter2'
 */
void test2_SysIntegration_MsgRouter1(const type_HMI2SecurityMsg
  *rtu_Ch1AlarmMsgIn, const type_HMI2SecurityMsg *rtu_Ch2AlarmMsgIn,
  type_HMI2SecurityMsg *rty_Group1AlarmMsgOut, DW_MsgRouter1_test2_SysIntegr_T
  *localDW)
{
  int32_T tmp;

  /* Chart: '<Root>/MsgRouter1' */
  if (localDW->bitsForTID5.is_active_c41_test2_SysIntegrat == 0U) {
    localDW->bitsForTID5.is_active_c41_test2_SysIntegrat = 1;
    rty_Group1AlarmMsgOut->Head.MsgId = 0U;
    rty_Group1AlarmMsgOut->Head.OpCode = 0U;
    rty_Group1AlarmMsgOut->Body.Data = 0U;
    localDW->prevMsg1Id = rtu_Ch1AlarmMsgIn->Head.MsgId;
    localDW->prevMsg2Id = rtu_Ch2AlarmMsgIn->Head.MsgId;
  } else if (localDW->prevMsg1Id != rtu_Ch1AlarmMsgIn->Head.MsgId) {
    localDW->prevMsg1Id = rtu_Ch1AlarmMsgIn->Head.MsgId;
    tmp = (int32_T)(rty_Group1AlarmMsgOut->Head.MsgId + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    rty_Group1AlarmMsgOut->Head.MsgId = (uint8_T)((uint8_T)tmp % MAX_uint8_T);
    rty_Group1AlarmMsgOut->Head.OpCode = rtu_Ch1AlarmMsgIn->Head.OpCode;
    rty_Group1AlarmMsgOut->Body = rtu_Ch1AlarmMsgIn->Body;
  } else {
    if (localDW->prevMsg2Id != rtu_Ch2AlarmMsgIn->Head.MsgId) {
      localDW->prevMsg2Id = rtu_Ch2AlarmMsgIn->Head.MsgId;
      tmp = (int32_T)(rty_Group1AlarmMsgOut->Head.MsgId + 1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      rty_Group1AlarmMsgOut->Head.MsgId = (uint8_T)((uint8_T)tmp % MAX_uint8_T);
      rty_Group1AlarmMsgOut->Head.OpCode = rtu_Ch2AlarmMsgIn->Head.OpCode;
      rty_Group1AlarmMsgOut->Body = rtu_Ch2AlarmMsgIn->Body;
    }
  }

  /* End of Chart: '<Root>/MsgRouter1' */
}

/* Function for Chart: '<S29>/Chart' */
static void test2_SysIntegrat_BleMsgSendSyn(uint8_T x_Channel, uint8_T
  x_MsgCell_f1_Body_MajorId, uint8_T x_MsgCell_f1_Body_MinorId, const uint8_T
  x_MsgCell_f1_Body_Data[132], uint8_T x_MsgCell_f2_Head_OpCode, uint8_T
  x_MsgCell_f2_Body_Data, uint8_T x_MsgCell_f3_Head_OpCode, const uint8_T
  x_MsgCell_f3_Body_Data[4], uint8_T x_MsgOutId, uint8_T *y_MsgOutId, uint8_T
  y_BleDataOut[224])
{
  int32_T tmp;
  memset(&y_BleDataOut[0], 0, 224U * sizeof(uint8_T));
  tmp = (int32_T)(x_MsgOutId + 1U);
  if ((uint32_T)tmp > 255U) {
    tmp = 255;
  }

  *y_MsgOutId = (uint8_T)((uint8_T)tmp % MAX_uint8_T);
  y_BleDataOut[1] = *y_MsgOutId;
  switch (x_Channel) {
   case 1:
    y_BleDataOut[0] = 136U;
    y_BleDataOut[2] = x_MsgCell_f1_Body_MajorId;
    y_BleDataOut[3] = x_MsgCell_f1_Body_MinorId;
    memcpy(&y_BleDataOut[4], &x_MsgCell_f1_Body_Data[0], 132U * sizeof(uint8_T));
    break;

   case 2:
    y_BleDataOut[0] = 5U;
    y_BleDataOut[2] = 250U;
    y_BleDataOut[3] = x_MsgCell_f2_Head_OpCode;
    y_BleDataOut[4] = x_MsgCell_f2_Body_Data;
    break;

   case 3:
    y_BleDataOut[0] = 8U;
    y_BleDataOut[2] = 251U;
    y_BleDataOut[3] = x_MsgCell_f3_Head_OpCode;
    y_BleDataOut[4] = x_MsgCell_f3_Body_Data[0];
    y_BleDataOut[5] = x_MsgCell_f3_Body_Data[1];
    y_BleDataOut[6] = x_MsgCell_f3_Body_Data[2];
    y_BleDataOut[7] = x_MsgCell_f3_Body_Data[3];
    break;
  }
}

/* Function for Chart: '<S29>/Chart' */
static void test2_SysIntegrat_ReformBleData(const uint8_T bleData[224], uint8_T
  prevMsgCellOut_f1_Head_MsgId, uint8_T prevMsgCellOut_f1_Head_OpCode, const
  uint8_T prevMsgCellOut_f1_Body_Data[48], uint8_T prevMsgCellOut_f2_Head_MsgId,
  uint8_T prevMsgCellOut_f2_Head_OpCode, const uint8_T
  prevMsgCellOut_f2_Body_Data[6], uint8_T prevMsgCellOut_f3_Head_MsgId, uint8_T
  prevMsgCellOut_f3_Head_OpCode, const uint8_T prevMsgCellOut_f3_Body_Data[32],
  uint8_T prevMsgCellOut_f4_Head_MsgId, uint8_T prevMsgCellOut_f4_Head_OpCode,
  const uint8_T prevMsgCellOut_f4_Body_Data[132], uint8_T
  prevMsgCellOut_f5_Head_MsgId, uint8_T prevMsgCellOut_f5_Head_OpCode, uint8_T
  prevMsgCellOut_f5_Body_Data, const type_MsgHead prevMsgCellOut_f6_Head, const
  type_MsgBody4RecordInqRequest prevMsgCellOut_f6_Body, const type_MsgHead
  prevMsgCellOut_f7_Head, const type_MsgBody4GP32Bytes prevMsgCellOut_f7_Body,
  const type_CommCtrlFCTestMsg prevMsgCellOut_f8, type_CommCtrlDoseCtrlMsg
  *y_DoseCtrlMsgOut, type_CommCtrlActCtrlMsg *y_ActCtrlMsgOut,
  type_CommCtrlAlarmCtrlMsg *y_AlarmCtrlMsgOut, type_CommCtrlFirmwareMsg
  *y_FirmwareMsgOut, type_CommCtrlSysSettingMsg *y_SysSettingMsgOut,
  type_CommCtrlRecordInqRequestMsg *y_RecordInqMsgOut, type_CommCtrlCalibraMsg
  *y_CalibraMsgOut, type_CommCtrlFCTestMsg *y_FCTestMsgOut)
{
  int32_T i;
  y_DoseCtrlMsgOut->Head.MsgId = prevMsgCellOut_f1_Head_MsgId;
  y_DoseCtrlMsgOut->Head.OpCode = prevMsgCellOut_f1_Head_OpCode;
  for (i = 0; i < 48; i++) {
    y_DoseCtrlMsgOut->Body.Data[i] = prevMsgCellOut_f1_Body_Data[i];
  }

  y_ActCtrlMsgOut->Head.MsgId = prevMsgCellOut_f2_Head_MsgId;
  y_ActCtrlMsgOut->Head.OpCode = prevMsgCellOut_f2_Head_OpCode;
  for (i = 0; i < 6; i++) {
    y_ActCtrlMsgOut->Body.Data[i] = prevMsgCellOut_f2_Body_Data[i];
  }

  y_AlarmCtrlMsgOut->Head.MsgId = prevMsgCellOut_f3_Head_MsgId;
  y_AlarmCtrlMsgOut->Head.OpCode = prevMsgCellOut_f3_Head_OpCode;
  for (i = 0; i < 32; i++) {
    y_AlarmCtrlMsgOut->Body.Data[i] = prevMsgCellOut_f3_Body_Data[i];
  }

  y_FirmwareMsgOut->Head.MsgId = prevMsgCellOut_f4_Head_MsgId;
  y_FirmwareMsgOut->Head.OpCode = prevMsgCellOut_f4_Head_OpCode;
  memcpy(&y_FirmwareMsgOut->Body.Data[0], &prevMsgCellOut_f4_Body_Data[0], 132U *
         sizeof(uint8_T));
  y_SysSettingMsgOut->Head.MsgId = prevMsgCellOut_f5_Head_MsgId;
  y_SysSettingMsgOut->Head.OpCode = prevMsgCellOut_f5_Head_OpCode;
  y_SysSettingMsgOut->Body.Data = prevMsgCellOut_f5_Body_Data;
  y_RecordInqMsgOut->Head = prevMsgCellOut_f6_Head;
  y_RecordInqMsgOut->Body = prevMsgCellOut_f6_Body;
  y_CalibraMsgOut->Head = prevMsgCellOut_f7_Head;
  y_CalibraMsgOut->Body = prevMsgCellOut_f7_Body;
  *y_FCTestMsgOut = prevMsgCellOut_f8;
  switch (bleData[2]) {
   case 1:
    i = (int32_T)(prevMsgCellOut_f1_Head_MsgId + 1U);
    if ((uint32_T)i > 255U) {
      i = 255;
    }

    y_DoseCtrlMsgOut->Head.MsgId = (uint8_T)((uint8_T)i % MAX_uint8_T);
    y_DoseCtrlMsgOut->Head.OpCode = bleData[3];
    for (i = 0; i < 48; i++) {
      y_DoseCtrlMsgOut->Body.Data[i] = bleData[4 + i];
    }
    break;

   case 2:
    i = (int32_T)(prevMsgCellOut_f2_Head_MsgId + 1U);
    if ((uint32_T)i > 255U) {
      i = 255;
    }

    y_ActCtrlMsgOut->Head.MsgId = (uint8_T)((uint8_T)i % MAX_uint8_T);
    y_ActCtrlMsgOut->Head.OpCode = bleData[3];
    for (i = 0; i < 6; i++) {
      y_ActCtrlMsgOut->Body.Data[i] = bleData[4 + i];
    }
    break;

   case 3:
    i = (int32_T)(prevMsgCellOut_f3_Head_MsgId + 1U);
    if ((uint32_T)i > 255U) {
      i = 255;
    }

    y_AlarmCtrlMsgOut->Head.MsgId = (uint8_T)((uint8_T)i % MAX_uint8_T);
    y_AlarmCtrlMsgOut->Head.OpCode = bleData[3];
    for (i = 0; i < 32; i++) {
      y_AlarmCtrlMsgOut->Body.Data[i] = bleData[4 + i];
    }
    break;

   case 4:
    i = (int32_T)(prevMsgCellOut_f4_Head_MsgId + 1U);
    if ((uint32_T)i > 255U) {
      i = 255;
    }

    y_FirmwareMsgOut->Head.MsgId = (uint8_T)((uint8_T)i % MAX_uint8_T);
    y_FirmwareMsgOut->Head.OpCode = bleData[3];
    memcpy(&y_FirmwareMsgOut->Body.Data[0], &bleData[4], 132U * sizeof(uint8_T));
    break;

   case 5:
    i = (int32_T)(prevMsgCellOut_f5_Head_MsgId + 1U);
    if ((uint32_T)i > 255U) {
      i = 255;
    }

    y_SysSettingMsgOut->Head.MsgId = (uint8_T)((uint8_T)i % MAX_uint8_T);
    y_SysSettingMsgOut->Head.OpCode = bleData[3];
    y_SysSettingMsgOut->Body.Data = bleData[4];
    break;

   case 6:
    i = (int32_T)(prevMsgCellOut_f6_Head.MsgId + 1U);
    if ((uint32_T)i > 255U) {
      i = 255;
    }

    y_RecordInqMsgOut->Head.MsgId = (uint8_T)((uint8_T)i % MAX_uint8_T);
    y_RecordInqMsgOut->Head.OpCode = bleData[3];
    y_RecordInqMsgOut->Body.MajorId = bleData[4];
    y_RecordInqMsgOut->Body.MinorId = bleData[5];
    break;

   case 7:
    i = (int32_T)(prevMsgCellOut_f7_Head.MsgId + 1U);
    if ((uint32_T)i > 255U) {
      i = 255;
    }

    y_CalibraMsgOut->Head.MsgId = (uint8_T)((uint8_T)i % MAX_uint8_T);
    y_CalibraMsgOut->Head.OpCode = bleData[3];
    for (i = 0; i < 32; i++) {
      y_CalibraMsgOut->Body.Data[i] = bleData[4 + i];
    }
    break;

   case 8:
    i = (int32_T)(prevMsgCellOut_f8.Head.MsgId + 1U);
    if ((uint32_T)i > 255U) {
      i = 255;
    }

    y_FCTestMsgOut->Head.MsgId = (uint8_T)((uint8_T)i % MAX_uint8_T);
    y_FCTestMsgOut->Head.OpCode = bleData[3];
    y_FCTestMsgOut->Body.Data[0] = bleData[4];
    y_FCTestMsgOut->Body.Data[1] = bleData[5];
    y_FCTestMsgOut->Body.Data[2] = bleData[6];
    y_FCTestMsgOut->Body.Data[3] = bleData[7];
    break;
  }
}

/* Function for Chart: '<S29>/Chart' */
static void test_ChkCommUpMsgIdVectorChange(const uint8_T prevMsgIdVector[3],
  uint8_T MsgInCell_f1_Head_MsgId, uint8_T MsgInCell_f2_Head_MsgId, uint8_T
  MsgInCell_f3_Head_MsgId, uint8_T y_SwitchOnVector[3], uint8_T
  y_prevMsgIdVector_newValue[3])
{
  y_SwitchOnVector[0] = (uint8_T)(MsgInCell_f1_Head_MsgId != prevMsgIdVector[0]);
  y_SwitchOnVector[1] = (uint8_T)(MsgInCell_f2_Head_MsgId != prevMsgIdVector[1]);
  y_SwitchOnVector[2] = (uint8_T)(MsgInCell_f3_Head_MsgId != prevMsgIdVector[2]);
  y_prevMsgIdVector_newValue[0] = MsgInCell_f1_Head_MsgId;
  y_prevMsgIdVector_newValue[1] = MsgInCell_f2_Head_MsgId;
  y_prevMsgIdVector_newValue[2] = MsgInCell_f3_Head_MsgId;
}

/* Function for Chart: '<S65>/Chart' */
static void ChkRecordCtrlMsgInIdVectorChang(const uint8_T
  x_prevMsgIdVector_oldValue[12], uint8_T x_MsgInCell_f1_Head_MsgId, uint8_T
  x_MsgInCell_f2_Head_MsgId, uint8_T x_MsgInCell_f3_Head_MsgId, uint8_T
  x_MsgInCell_f4_Head_MsgId, uint8_T x_MsgInCell_f5_Head_MsgId, uint8_T
  x_MsgInCell_f6_Head_MsgId, uint8_T x_MsgInCell_f7_Head_MsgId, uint8_T
  x_MsgInCell_f8_Head_MsgId, uint8_T x_MsgInCell_f9_Head_MsgId, uint8_T
  x_MsgInCell_f10_Head_MsgId, uint8_T x_MsgInCell_f11_Head_MsgId, uint8_T
  x_MsgInCell_f12_Head_MsgId, boolean_T y_SwitchOnVector[12], uint8_T
  y_prevMsgIdVector_newValue[12])
{
  int32_T i;
  for (i = 0; i < 12; i++) {
    y_prevMsgIdVector_newValue[i] = x_prevMsgIdVector_oldValue[i];
  }

  y_SwitchOnVector[0] = (x_MsgInCell_f1_Head_MsgId !=
    x_prevMsgIdVector_oldValue[0]);
  if (y_SwitchOnVector[0]) {
    y_prevMsgIdVector_newValue[0] = x_MsgInCell_f1_Head_MsgId;
  }

  y_SwitchOnVector[1] = (x_MsgInCell_f2_Head_MsgId !=
    x_prevMsgIdVector_oldValue[1]);
  if (y_SwitchOnVector[1]) {
    y_prevMsgIdVector_newValue[1] = x_MsgInCell_f2_Head_MsgId;
  }

  y_SwitchOnVector[2] = (x_MsgInCell_f3_Head_MsgId !=
    x_prevMsgIdVector_oldValue[2]);
  if (y_SwitchOnVector[2]) {
    y_prevMsgIdVector_newValue[2] = x_MsgInCell_f3_Head_MsgId;
  }

  y_SwitchOnVector[3] = (x_MsgInCell_f4_Head_MsgId !=
    x_prevMsgIdVector_oldValue[3]);
  if (y_SwitchOnVector[3]) {
    y_prevMsgIdVector_newValue[3] = x_MsgInCell_f4_Head_MsgId;
  }

  y_SwitchOnVector[4] = (x_MsgInCell_f5_Head_MsgId !=
    x_prevMsgIdVector_oldValue[4]);
  if (y_SwitchOnVector[4]) {
    y_prevMsgIdVector_newValue[4] = x_MsgInCell_f5_Head_MsgId;
  }

  y_SwitchOnVector[5] = (x_MsgInCell_f6_Head_MsgId !=
    x_prevMsgIdVector_oldValue[5]);
  if (y_SwitchOnVector[5]) {
    y_prevMsgIdVector_newValue[5] = x_MsgInCell_f6_Head_MsgId;
  }

  y_SwitchOnVector[6] = (x_MsgInCell_f7_Head_MsgId !=
    x_prevMsgIdVector_oldValue[6]);
  if (y_SwitchOnVector[6]) {
    y_prevMsgIdVector_newValue[6] = x_MsgInCell_f7_Head_MsgId;
  }

  y_SwitchOnVector[7] = (x_MsgInCell_f8_Head_MsgId !=
    x_prevMsgIdVector_oldValue[7]);
  if (y_SwitchOnVector[7]) {
    y_prevMsgIdVector_newValue[7] = x_MsgInCell_f8_Head_MsgId;
  }

  y_SwitchOnVector[8] = (x_MsgInCell_f9_Head_MsgId !=
    x_prevMsgIdVector_oldValue[8]);
  if (y_SwitchOnVector[8]) {
    y_prevMsgIdVector_newValue[8] = x_MsgInCell_f9_Head_MsgId;
  }

  y_SwitchOnVector[9] = (x_MsgInCell_f10_Head_MsgId !=
    x_prevMsgIdVector_oldValue[9]);
  if (y_SwitchOnVector[9]) {
    y_prevMsgIdVector_newValue[9] = x_MsgInCell_f10_Head_MsgId;
  }

  y_SwitchOnVector[10] = (x_MsgInCell_f11_Head_MsgId !=
    x_prevMsgIdVector_oldValue[10]);
  if (y_SwitchOnVector[10]) {
    y_prevMsgIdVector_newValue[10] = x_MsgInCell_f11_Head_MsgId;
  }

  y_SwitchOnVector[11] = (x_MsgInCell_f12_Head_MsgId !=
    x_prevMsgIdVector_oldValue[11]);
  if (y_SwitchOnVector[11]) {
    y_prevMsgIdVector_newValue[11] = x_MsgInCell_f12_Head_MsgId;
  }
}

/* Function for Chart: '<S65>/Chart' */
static void test2_SysIntegr_DoseCtrlMsgProc(uint8_T xx_DoseCtrlMsgIn_Head_OpCode,
  const uint8_T xx_DoseCtrlMsgIn_Body_Data[48], uint8_T
  xx_drvFlashAccessMsgOut_Head_Ms, uint8_T xx_drvFlashAccessMsgOut_Body_Mi,
  const uint8_T xx_drvFlashAccessMsgOut_Body_Da[132], uint8_T
  *yy_drvFlashAccessMsgOut_Head_Ms, uint8_T *yy_drvFlashAccessMsgOut_Head_Op,
  uint8_T *yy_drvFlashAccessMsgOut_Body_Ma, uint8_T
  *yy_drvFlashAccessMsgOut_Body_Mi, uint8_T yy_drvFlashAccessMsgOut_Body_Da[132])
{
  int32_T i;
  *yy_drvFlashAccessMsgOut_Body_Mi = xx_drvFlashAccessMsgOut_Body_Mi;
  memcpy(&yy_drvFlashAccessMsgOut_Body_Da[0], &xx_drvFlashAccessMsgOut_Body_Da[0],
         132U * sizeof(uint8_T));
  *yy_drvFlashAccessMsgOut_Head_Op = 1U;
  i = (int32_T)(xx_drvFlashAccessMsgOut_Head_Ms + 1U);
  if ((uint32_T)i > 255U) {
    i = 255;
  }

  *yy_drvFlashAccessMsgOut_Head_Ms = (uint8_T)((uint8_T)i % MAX_uint8_T);
  *yy_drvFlashAccessMsgOut_Body_Ma = 1U;
  for (i = 0; i < 48; i++) {
    yy_drvFlashAccessMsgOut_Body_Da[i] = xx_DoseCtrlMsgIn_Body_Data[i];
  }

  if (xx_DoseCtrlMsgIn_Head_OpCode == 1) {
    *yy_drvFlashAccessMsgOut_Body_Mi = 2U;
  } else if ((xx_DoseCtrlMsgIn_Head_OpCode >= 10) &&
             (xx_DoseCtrlMsgIn_Head_OpCode < 42)) {
    *yy_drvFlashAccessMsgOut_Body_Mi = xx_DoseCtrlMsgIn_Head_OpCode;
  } else {
    switch (xx_DoseCtrlMsgIn_Head_OpCode) {
     case 3:
      *yy_drvFlashAccessMsgOut_Body_Mi = 5U;
      break;

     case 4:
      *yy_drvFlashAccessMsgOut_Body_Mi = 1U;
      break;
    }
  }
}

/* Function for Chart: '<S65>/Chart' */
static void test2_SysIntegra_ActCtrlMsgProc(uint8_T xx_ActCtrlMsgIn_Head_OpCode,
  const uint8_T xx_ActCtrlMsgIn_Body_Data[6], type_FlashAccessMsg
  *xx_drvFlashAccessMsgOut)
{
  int32_T i;
  i = (int32_T)(xx_drvFlashAccessMsgOut->Head.MsgId + 1U);
  if ((uint32_T)i > 255U) {
    i = 255;
  }

  xx_drvFlashAccessMsgOut->Head.MsgId = (uint8_T)((uint8_T)i % MAX_uint8_T);
  xx_drvFlashAccessMsgOut->Head.OpCode = 1U;
  xx_drvFlashAccessMsgOut->Body.MajorId = 2U;
  for (i = 0; i < 6; i++) {
    xx_drvFlashAccessMsgOut->Body.Data[i] = xx_ActCtrlMsgIn_Body_Data[i];
  }

  switch (xx_ActCtrlMsgIn_Head_OpCode) {
   case 1:
    xx_drvFlashAccessMsgOut->Body.MinorId = 1U;
    break;

   case 2:
    xx_drvFlashAccessMsgOut->Body.MinorId = 2U;
    break;

   case 3:
    xx_drvFlashAccessMsgOut->Body.MinorId = 3U;
    break;
  }
}

/* Function for Chart: '<S65>/Chart' */
static void test2_SysIntegr_FirmwareMsgProc(uint8_T xx_FirmwareMsgIn_Head_OpCode,
  const uint8_T xx_FirmwareMsgIn_Body_Data[132], uint8_T
  xx_drvFlashAccessMsgOut_Head_Ms, uint8_T *yy_drvFlashAccessMsgOut_Head_Ms,
  uint8_T *yy_drvFlashAccessMsgOut_Head_Op, uint8_T
  *yy_drvFlashAccessMsgOut_Body_Ma, uint8_T *yy_drvFlashAccessMsgOut_Body_Mi,
  uint8_T yy_drvFlashAccessMsgOut_Body_Da[132])
{
  int32_T tmp;
  uint32_T qY_tmp;
  *yy_drvFlashAccessMsgOut_Body_Ma = 4U;
  memcpy(&yy_drvFlashAccessMsgOut_Body_Da[0], &xx_FirmwareMsgIn_Body_Data[0],
         132U * sizeof(uint8_T));
  tmp = (int32_T)(xx_drvFlashAccessMsgOut_Head_Ms + 1U);
  if ((uint32_T)tmp > 255U) {
    tmp = 255;
  }

  *yy_drvFlashAccessMsgOut_Head_Ms = (uint8_T)((uint8_T)tmp % MAX_uint8_T);
  switch (xx_FirmwareMsgIn_Head_OpCode) {
   case 1:
    *yy_drvFlashAccessMsgOut_Body_Mi = xx_FirmwareMsgIn_Head_OpCode;
    *yy_drvFlashAccessMsgOut_Head_Op = 1U;
    break;

   case 3:
    *yy_drvFlashAccessMsgOut_Body_Mi = xx_FirmwareMsgIn_Head_OpCode;
    *yy_drvFlashAccessMsgOut_Head_Op = 1U;
    break;

   case 4:
    *yy_drvFlashAccessMsgOut_Body_Mi = xx_FirmwareMsgIn_Head_OpCode;
    *yy_drvFlashAccessMsgOut_Head_Op = 3U;
    break;

   case 11:
    qY_tmp = xx_FirmwareMsgIn_Head_OpCode - /*MW:OvSatOk*/ 10U;
    if (qY_tmp > xx_FirmwareMsgIn_Head_OpCode) {
      qY_tmp = 0U;
    }

    *yy_drvFlashAccessMsgOut_Body_Mi = (uint8_T)qY_tmp;
    *yy_drvFlashAccessMsgOut_Head_Op = 10U;
    break;

   case 13:
    qY_tmp = xx_FirmwareMsgIn_Head_OpCode - /*MW:OvSatOk*/ 10U;
    if (qY_tmp > xx_FirmwareMsgIn_Head_OpCode) {
      qY_tmp = 0U;
    }

    *yy_drvFlashAccessMsgOut_Body_Mi = (uint8_T)qY_tmp;
    *yy_drvFlashAccessMsgOut_Head_Op = 10U;
    break;

   case 14:
    qY_tmp = xx_FirmwareMsgIn_Head_OpCode - /*MW:OvSatOk*/ 10U;
    if (qY_tmp > xx_FirmwareMsgIn_Head_OpCode) {
      qY_tmp = 0U;
    }

    *yy_drvFlashAccessMsgOut_Body_Mi = (uint8_T)qY_tmp;
    *yy_drvFlashAccessMsgOut_Head_Op = 30U;
    break;

   default:
    if ((xx_FirmwareMsgIn_Head_OpCode > 100) && (xx_FirmwareMsgIn_Head_OpCode <
         233)) {
      *yy_drvFlashAccessMsgOut_Body_Mi = xx_FirmwareMsgIn_Head_OpCode;
      *yy_drvFlashAccessMsgOut_Head_Op = 100U;
    } else {
      *yy_drvFlashAccessMsgOut_Body_Mi = 0U;
      *yy_drvFlashAccessMsgOut_Head_Op = 0U;
    }
    break;
  }

  switch (xx_FirmwareMsgIn_Head_OpCode) {
   case 1:
    *yy_drvFlashAccessMsgOut_Body_Mi = 1U;
    break;

   case 3:
    *yy_drvFlashAccessMsgOut_Body_Mi = 3U;
    break;

   case 4:
    *yy_drvFlashAccessMsgOut_Head_Op = 3U;
    break;

   default:
    if ((xx_FirmwareMsgIn_Head_OpCode > 100) && (xx_FirmwareMsgIn_Head_OpCode <
         233)) {
      *yy_drvFlashAccessMsgOut_Body_Mi = xx_FirmwareMsgIn_Head_OpCode;
    } else {
      *yy_drvFlashAccessMsgOut_Body_Mi = 0U;
    }
    break;
  }
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysInt_TransWord2TwoBytes(uint16_T x_Word, uint8_T y_2Bytes[2])
{
  y_2Bytes[0] = (uint8_T)(x_Word & 255);
  y_2Bytes[1] = (uint8_T)((uint32_T)(x_Word & 65280) >> 8);
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysI_TransDWord2FourBytes(uint32_T x_DWord, uint8_T
  y_FourBytes[4])
{
  y_FourBytes[0] = (uint8_T)(x_DWord & 255U);
  y_FourBytes[1] = (uint8_T)((x_DWord & 65280U) >> 8U);
  y_FourBytes[2] = (uint8_T)((x_DWord & 16711680U) >> 16U);
  y_FourBytes[3] = (uint8_T)((x_DWord & 4278190080U) >> 24U);
}

/* Function for Chart: '<S65>/Chart' */
static void test2_SysIn_GrabSysVar2Bytes132(const type_SysVars *x3_SysVar,
  uint8_T x3_MajorId, uint8_T x3_MinorId, uint8_T SysVarIn132BytesForm[132])
{
  uint8_T temp_y4Bytes[4];
  int32_T i;
  int32_T b_i;
  uint8_T c_y_2Bytes[2];
  uint32_T y_Target;
  uint16_T b_y_Target;
  uint16_T c_y_Target;
  uint16_T d_y_Target;
  uint16_T e_y_Target;
  uint16_T f_y_Target;
  uint16_T g_y_Target;
  uint16_T h_y_Target;
  uint16_T i_y_Target;
  memset(&SysVarIn132BytesForm[0], 0, 132U * sizeof(uint8_T));
  switch (x3_MajorId) {
   case 1:
    switch (x3_MinorId) {
     case 1:
      SysVarIn132BytesForm[0] = x3_SysVar->DoseCtrl.DoseCtrlParam.Concentration;
      SysVarIn132BytesForm[1] = x3_SysVar->DoseCtrl.DoseCtrlParam.LowDoseTHValue;
      test2_SysInt_TransWord2TwoBytes
        (x3_SysVar->DoseCtrl.DoseCtrlParam.MaxLargeDose, c_y_2Bytes);
      SysVarIn132BytesForm[2] = c_y_2Bytes[0];
      SysVarIn132BytesForm[3] = c_y_2Bytes[1];
      test2_SysInt_TransWord2TwoBytes
        (x3_SysVar->DoseCtrl.DoseCtrlParam.MaxBaseRate, c_y_2Bytes);
      SysVarIn132BytesForm[4] = c_y_2Bytes[0];
      SysVarIn132BytesForm[5] = c_y_2Bytes[1];
      SysVarIn132BytesForm[6] = x3_SysVar->DoseCtrl.DoseCtrlParam.MaxDailyDose;
      break;

     case 2:
      for (b_i = 0; b_i < 48; b_i++) {
        SysVarIn132BytesForm[b_i] = x3_SysVar->DoseCtrl.BaseRateConfig[b_i];
      }
      break;

     case 3:
      for (b_i = 0; b_i < 48; b_i++) {
        SysVarIn132BytesForm[b_i] = x3_SysVar->DoseCtrl.TempBaseRateConfig[b_i];
      }
      break;

     case 4:
      SysVarIn132BytesForm[0] = x3_SysVar->DoseCtrl.LastTBRConfigDay[0];
      SysVarIn132BytesForm[1] = x3_SysVar->DoseCtrl.LastTBRConfigDay[1];
      SysVarIn132BytesForm[2] = x3_SysVar->DoseCtrl.LastTBRConfigDay[2];
      break;

     case 5:
      test2_SysInt_TransWord2TwoBytes
        (x3_SysVar->DoseCtrl.LargeDoseConfig.LargeDoseTotalAmount, c_y_2Bytes);
      SysVarIn132BytesForm[2] =
        x3_SysVar->DoseCtrl.LargeDoseConfig.DeliveryConfig;
      SysVarIn132BytesForm[3] =
        x3_SysVar->DoseCtrl.LargeDoseConfig.PermittedTime;
      SysVarIn132BytesForm[0] = c_y_2Bytes[0];
      SysVarIn132BytesForm[4] = (uint8_T)
        (x3_SysVar->DoseCtrl.LargeDoseConfig.RegularDose4DWMCase & 255);
      SysVarIn132BytesForm[6] = (uint8_T)
        (x3_SysVar->DoseCtrl.LargeDoseConfig.EffectiveDay & 255);
      SysVarIn132BytesForm[1] = c_y_2Bytes[1];
      SysVarIn132BytesForm[5] = (uint8_T)((uint32_T)
        (x3_SysVar->DoseCtrl.LargeDoseConfig.RegularDose4DWMCase & 65280) >> 8);
      SysVarIn132BytesForm[7] = (uint8_T)((uint32_T)
        (x3_SysVar->DoseCtrl.LargeDoseConfig.EffectiveDay & 65280) >> 8);
      for (b_i = 0; b_i < 20; b_i++) {
        SysVarIn132BytesForm[8 + b_i] =
          x3_SysVar->DoseCtrl.LargeDoseConfig.CustomTimeConfig[b_i];
        SysVarIn132BytesForm[28 + b_i] =
          x3_SysVar->DoseCtrl.LargeDoseConfig.CustomDoseConfig[b_i];
      }
      break;
    }
    break;

   case 2:
    switch (x3_MinorId) {
     case 1:
      SysVarIn132BytesForm[0] = x3_SysVar->ActCtrl.IniLoadedVol;
      break;

     case 2:
      SysVarIn132BytesForm[0] = (uint8_T)(x3_SysVar->ActCtrl.AdjustInputGain &
        255);
      SysVarIn132BytesForm[2] = (uint8_T)
        (x3_SysVar->ActCtrl.AdjustPositiveOffset & 255);
      SysVarIn132BytesForm[4] = (uint8_T)
        (x3_SysVar->ActCtrl.AdjustNegativeOffset & 255);
      SysVarIn132BytesForm[1] = (uint8_T)((uint32_T)
        (x3_SysVar->ActCtrl.AdjustInputGain & 65280) >> 8);
      SysVarIn132BytesForm[3] = (uint8_T)((uint32_T)
        (x3_SysVar->ActCtrl.AdjustPositiveOffset & 65280) >> 8);
      SysVarIn132BytesForm[5] = (uint8_T)((uint32_T)
        (x3_SysVar->ActCtrl.AdjustNegativeOffset & 65280) >> 8);
      break;

     case 3:
      SysVarIn132BytesForm[0] = x3_SysVar->ActCtrl.DeliverSwitch;
      break;

     case 4:
      test2_SysI_TransDWord2FourBytes
        (x3_SysVar->ActCtrl.BaseRateDynVar.TargetDose, temp_y4Bytes);
      SysVarIn132BytesForm[0] = temp_y4Bytes[0];
      SysVarIn132BytesForm[1] = temp_y4Bytes[1];
      SysVarIn132BytesForm[2] = temp_y4Bytes[2];
      SysVarIn132BytesForm[3] = temp_y4Bytes[3];
      SysVarIn132BytesForm[4] = (uint8_T)
        (x3_SysVar->ActCtrl.BaseRateDynVar.TimeInfo & 255);
      SysVarIn132BytesForm[5] = (uint8_T)((uint32_T)
        (x3_SysVar->ActCtrl.BaseRateDynVar.TimeInfo & 65280) >> 8);
      test2_SysI_TransDWord2FourBytes
        (x3_SysVar->ActCtrl.BaseRateDynVar.CompleteDose, temp_y4Bytes);
      SysVarIn132BytesForm[6] = temp_y4Bytes[0];
      SysVarIn132BytesForm[7] = temp_y4Bytes[1];
      SysVarIn132BytesForm[8] = temp_y4Bytes[2];
      SysVarIn132BytesForm[9] = temp_y4Bytes[3];
      break;

     case 5:
      test2_SysI_TransDWord2FourBytes
        (x3_SysVar->ActCtrl.LargeDoseDynVar.TargetDose, temp_y4Bytes);
      SysVarIn132BytesForm[0] = temp_y4Bytes[0];
      SysVarIn132BytesForm[1] = temp_y4Bytes[1];
      SysVarIn132BytesForm[2] = temp_y4Bytes[2];
      SysVarIn132BytesForm[3] = temp_y4Bytes[3];
      SysVarIn132BytesForm[4] = (uint8_T)
        (x3_SysVar->ActCtrl.LargeDoseDynVar.TimeInfo & 255);
      SysVarIn132BytesForm[5] = (uint8_T)((uint32_T)
        (x3_SysVar->ActCtrl.LargeDoseDynVar.TimeInfo & 65280) >> 8);
      test2_SysI_TransDWord2FourBytes
        (x3_SysVar->ActCtrl.LargeDoseDynVar.CompleteDose, temp_y4Bytes);
      SysVarIn132BytesForm[6] = temp_y4Bytes[0];
      SysVarIn132BytesForm[7] = temp_y4Bytes[1];
      SysVarIn132BytesForm[8] = temp_y4Bytes[2];
      SysVarIn132BytesForm[9] = temp_y4Bytes[3];
      break;

     case 6:
      SysVarIn132BytesForm[0] = x3_SysVar->ActCtrl.DailyDoseStatVar.DayInfo;
      test2_SysI_TransDWord2FourBytes
        (x3_SysVar->ActCtrl.DailyDoseStatVar.ResidueDoseEst, temp_y4Bytes);
      SysVarIn132BytesForm[1] = temp_y4Bytes[0];
      SysVarIn132BytesForm[2] = temp_y4Bytes[1];
      SysVarIn132BytesForm[3] = temp_y4Bytes[2];
      SysVarIn132BytesForm[4] = temp_y4Bytes[3];
      test2_SysI_TransDWord2FourBytes
        (x3_SysVar->ActCtrl.DailyDoseStatVar.TotalAmountAcc, temp_y4Bytes);
      SysVarIn132BytesForm[5] = temp_y4Bytes[0];
      SysVarIn132BytesForm[6] = temp_y4Bytes[1];
      SysVarIn132BytesForm[7] = temp_y4Bytes[2];
      SysVarIn132BytesForm[8] = temp_y4Bytes[3];
      test2_SysI_TransDWord2FourBytes
        (x3_SysVar->ActCtrl.DailyDoseStatVar.DailyAmountAcc, temp_y4Bytes);
      SysVarIn132BytesForm[9] = temp_y4Bytes[0];
      SysVarIn132BytesForm[10] = temp_y4Bytes[1];
      SysVarIn132BytesForm[11] = temp_y4Bytes[2];
      SysVarIn132BytesForm[12] = temp_y4Bytes[3];
      test2_SysI_TransDWord2FourBytes
        (x3_SysVar->ActCtrl.DailyDoseStatVar.LargeAmountAcc, temp_y4Bytes);
      SysVarIn132BytesForm[13] = temp_y4Bytes[0];
      SysVarIn132BytesForm[14] = temp_y4Bytes[1];
      SysVarIn132BytesForm[15] = temp_y4Bytes[2];
      SysVarIn132BytesForm[16] = temp_y4Bytes[3];
      break;
    }
    break;

   case 3:
    switch (x3_MinorId) {
     case 1:
      SysVarIn132BytesForm[0] = x3_SysVar->AlarmCtrl.AlarmCtrlConfig;
      break;

     case 2:
      for (i = 0; i < 8; i++) {
        if (x3_SysVar->AlarmCtrl.SSCurAndProcTimeCritPolyFitVect[i] >= 0) {
          b_i = x3_SysVar->AlarmCtrl.SSCurAndProcTimeCritPolyFitVect[i];
          if (x3_SysVar->AlarmCtrl.SSCurAndProcTimeCritPolyFitVect[i] < 0) {
            b_i = 0;
          }

          y_Target = (uint32_T)b_i;
        } else if ((real_T)x3_SysVar->
                   AlarmCtrl.SSCurAndProcTimeCritPolyFitVect[i] + 4.294967296E+9
                   < 4.294967296E+9) {
          y_Target = (uint32_T)((real_T)
                                x3_SysVar->AlarmCtrl.SSCurAndProcTimeCritPolyFitVect
                                [i] + 4.294967296E+9);
        } else {
          y_Target = MAX_uint32_T;
        }

        SysVarIn132BytesForm[i] = (uint8_T)(y_Target & 255U);
        SysVarIn132BytesForm[i + 1] = (uint8_T)((y_Target & 65280U) >> 8U);
        SysVarIn132BytesForm[i + 2] = (uint8_T)((y_Target & 16711680U) >> 16U);
        SysVarIn132BytesForm[i + 3] = (uint8_T)((y_Target & 4278190080U) >> 24U);
      }
      break;
    }
    break;

   case 4:
    if (x3_MinorId == 1) {
      test2_SysI_TransDWord2FourBytes(x3_SysVar->Firmware.FirmwareSize,
        temp_y4Bytes);
      SysVarIn132BytesForm[0] = temp_y4Bytes[0];
      SysVarIn132BytesForm[1] = temp_y4Bytes[1];
      SysVarIn132BytesForm[2] = temp_y4Bytes[2];
      SysVarIn132BytesForm[3] = temp_y4Bytes[3];
      test2_SysI_TransDWord2FourBytes(x3_SysVar->Firmware.FirmwareCRC32,
        temp_y4Bytes);
      SysVarIn132BytesForm[4] = temp_y4Bytes[0];
      SysVarIn132BytesForm[5] = temp_y4Bytes[1];
      SysVarIn132BytesForm[6] = temp_y4Bytes[2];
      SysVarIn132BytesForm[7] = temp_y4Bytes[3];
      SysVarIn132BytesForm[8] = x3_SysVar->Firmware.FirmwareUpgradeCompleteFlag;
    }
    break;

   case 5:
    switch (x3_MinorId) {
     case 1:
      SysVarIn132BytesForm[0] = x3_SysVar->SysSetting.SensitivityLevel;
      break;

     case 2:
      for (b_i = 0; b_i < 10; b_i++) {
        SysVarIn132BytesForm[b_i] = x3_SysVar->SysSetting.SerialNo[b_i];
      }
      break;

     case 3:
      for (b_i = 0; b_i < 6; b_i++) {
        SysVarIn132BytesForm[b_i] = x3_SysVar->
          SysSetting.SoftwareVersionInfo[b_i];
      }
      break;

     case 4:
      SysVarIn132BytesForm[0] = x3_SysVar->SysSetting.HardwareVersionInfo[0];
      SysVarIn132BytesForm[1] = x3_SysVar->SysSetting.HardwareVersionInfo[1];
      SysVarIn132BytesForm[2] = x3_SysVar->SysSetting.HardwareVersionInfo[2];
      break;

     case 5:
      SysVarIn132BytesForm[0] = x3_SysVar->SysSetting.FlashConfigFlag;
      break;
    }
    break;

   case 6:
    switch (x3_MinorId) {
     case 1:
     case 2:
     case 3:
      for (b_i = 0; b_i < 33; b_i++) {
        test2_SysI_TransDWord2FourBytes(x3_SysVar->Occlusion.PT[(x3_MinorId - 1)
          * 33 + b_i], temp_y4Bytes);
        SysVarIn132BytesForm[b_i << 2] = temp_y4Bytes[0];
        SysVarIn132BytesForm[(b_i << 2) + 1] = temp_y4Bytes[1];
        SysVarIn132BytesForm[(b_i << 2) + 2] = temp_y4Bytes[2];
        SysVarIn132BytesForm[(b_i << 2) + 3] = temp_y4Bytes[3];
      }
      break;

     case 4:
     case 5:
     case 6:
      for (b_i = 0; b_i < 33; b_i++) {
        y_Target = x3_MinorId - /*MW:OvSatOk*/ 3U;
        if (y_Target > x3_MinorId) {
          y_Target = 0U;
        }

        test2_SysI_TransDWord2FourBytes(x3_SysVar->Occlusion.CI[((int32_T)
          y_Target - 1) * 33 + b_i], temp_y4Bytes);
        SysVarIn132BytesForm[b_i << 2] = temp_y4Bytes[0];
        SysVarIn132BytesForm[(b_i << 2) + 1] = temp_y4Bytes[1];
        SysVarIn132BytesForm[(b_i << 2) + 2] = temp_y4Bytes[2];
        SysVarIn132BytesForm[(b_i << 2) + 3] = temp_y4Bytes[3];
      }
      break;
    }
    break;

   case 7:
    if (x3_MinorId == 1) {
      test2_SysI_TransDWord2FourBytes
        (x3_SysVar->Calibra.MajorMcu4ChADCResolution[0], &SysVarIn132BytesForm[0]);
      test2_SysI_TransDWord2FourBytes
        (x3_SysVar->Calibra.MajorMcu4ChADCResolution[1], &SysVarIn132BytesForm[4]);
      test2_SysI_TransDWord2FourBytes
        (x3_SysVar->Calibra.MajorMcu4ChADCResolution[2], &SysVarIn132BytesForm[8]);
      test2_SysI_TransDWord2FourBytes
        (x3_SysVar->Calibra.MajorMcu4ChADCResolution[3], &SysVarIn132BytesForm
         [12]);
      test2_SysI_TransDWord2FourBytes
        (x3_SysVar->Calibra.MinorMcu4ChADCResolution[0], &SysVarIn132BytesForm
         [16]);
      test2_SysI_TransDWord2FourBytes
        (x3_SysVar->Calibra.MinorMcu4ChADCResolution[1], &SysVarIn132BytesForm
         [20]);
      test2_SysI_TransDWord2FourBytes
        (x3_SysVar->Calibra.MinorMcu4ChADCResolution[2], &SysVarIn132BytesForm
         [24]);
      test2_SysI_TransDWord2FourBytes
        (x3_SysVar->Calibra.MinorMcu4ChADCResolution[3], &SysVarIn132BytesForm
         [28]);
      if (x3_SysVar->Calibra.MajorMCU4ChADCOffset[0] >= 0) {
        b_y_Target = (uint16_T)x3_SysVar->Calibra.MajorMCU4ChADCOffset[0];
      } else {
        b_y_Target = (uint16_T)(x3_SysVar->Calibra.MajorMCU4ChADCOffset[0] +
          65536);
      }

      if (x3_SysVar->Calibra.MajorMCU4ChADCOffset[1] >= 0) {
        c_y_Target = (uint16_T)x3_SysVar->Calibra.MajorMCU4ChADCOffset[1];
      } else {
        c_y_Target = (uint16_T)(x3_SysVar->Calibra.MajorMCU4ChADCOffset[1] +
          65536);
      }

      if (x3_SysVar->Calibra.MajorMCU4ChADCOffset[2] >= 0) {
        d_y_Target = (uint16_T)x3_SysVar->Calibra.MajorMCU4ChADCOffset[2];
      } else {
        d_y_Target = (uint16_T)(x3_SysVar->Calibra.MajorMCU4ChADCOffset[2] +
          65536);
      }

      if (x3_SysVar->Calibra.MajorMCU4ChADCOffset[3] >= 0) {
        e_y_Target = (uint16_T)x3_SysVar->Calibra.MajorMCU4ChADCOffset[3];
      } else {
        e_y_Target = (uint16_T)(x3_SysVar->Calibra.MajorMCU4ChADCOffset[3] +
          65536);
      }

      if (x3_SysVar->Calibra.MinorMCU4ChADCOffset[0] >= 0) {
        f_y_Target = (uint16_T)x3_SysVar->Calibra.MinorMCU4ChADCOffset[0];
      } else {
        f_y_Target = (uint16_T)(x3_SysVar->Calibra.MinorMCU4ChADCOffset[0] +
          65536);
      }

      if (x3_SysVar->Calibra.MinorMCU4ChADCOffset[1] >= 0) {
        g_y_Target = (uint16_T)x3_SysVar->Calibra.MinorMCU4ChADCOffset[1];
      } else {
        g_y_Target = (uint16_T)(x3_SysVar->Calibra.MinorMCU4ChADCOffset[1] +
          65536);
      }

      if (x3_SysVar->Calibra.MinorMCU4ChADCOffset[2] >= 0) {
        h_y_Target = (uint16_T)x3_SysVar->Calibra.MinorMCU4ChADCOffset[2];
      } else {
        h_y_Target = (uint16_T)(x3_SysVar->Calibra.MinorMCU4ChADCOffset[2] +
          65536);
      }

      if (x3_SysVar->Calibra.MinorMCU4ChADCOffset[3] >= 0) {
        i_y_Target = (uint16_T)x3_SysVar->Calibra.MinorMCU4ChADCOffset[3];
      } else {
        i_y_Target = (uint16_T)(x3_SysVar->Calibra.MinorMCU4ChADCOffset[3] +
          65536);
      }

      SysVarIn132BytesForm[32] = (uint8_T)(b_y_Target & 255);
      SysVarIn132BytesForm[34] = (uint8_T)(c_y_Target & 255);
      SysVarIn132BytesForm[36] = (uint8_T)(d_y_Target & 255);
      SysVarIn132BytesForm[38] = (uint8_T)(e_y_Target & 255);
      SysVarIn132BytesForm[40] = (uint8_T)(f_y_Target & 255);
      SysVarIn132BytesForm[42] = (uint8_T)(g_y_Target & 255);
      SysVarIn132BytesForm[44] = (uint8_T)(h_y_Target & 255);
      SysVarIn132BytesForm[46] = (uint8_T)(i_y_Target & 255);
      SysVarIn132BytesForm[33] = (uint8_T)((uint32_T)(b_y_Target & 65280) >> 8);
      SysVarIn132BytesForm[35] = (uint8_T)((uint32_T)(c_y_Target & 65280) >> 8);
      SysVarIn132BytesForm[37] = (uint8_T)((uint32_T)(d_y_Target & 65280) >> 8);
      SysVarIn132BytesForm[39] = (uint8_T)((uint32_T)(e_y_Target & 65280) >> 8);
      SysVarIn132BytesForm[41] = (uint8_T)((uint32_T)(f_y_Target & 65280) >> 8);
      SysVarIn132BytesForm[43] = (uint8_T)((uint32_T)(g_y_Target & 65280) >> 8);
      SysVarIn132BytesForm[45] = (uint8_T)((uint32_T)(h_y_Target & 65280) >> 8);
      SysVarIn132BytesForm[47] = (uint8_T)((uint32_T)(i_y_Target & 65280) >> 8);
    }
    break;
  }
}

/* Function for Chart: '<S65>/Chart' */
static void test2_SysIntegratio_GPMsgInProc(uint8_T x_MsgInCell_f1_Head_OpCode,
  const uint8_T x_MsgInCell_f1_Body_Data[48], uint8_T x_MsgInCell_f2_Head_OpCode,
  const uint8_T x_MsgInCell_f2_Body_Data[6], uint8_T x_MsgInCell_f3_Head_OpCode,
  const uint8_T x_MsgInCell_f3_Body_Data[32], uint8_T x_MsgInCell_f4_Head_OpCode,
  const uint8_T x_MsgInCell_f4_Body_Data[132], uint8_T
  x_MsgInCell_f5_Head_OpCode, uint8_T x_MsgInCell_f5_Body_Data, uint8_T
  x_MsgInCell_f6_Head_OpCode, uint8_T x_MsgInCell_f6_Body_MajorId, uint8_T
  x_MsgInCell_f6_Body_MinorId, uint8_T x_MsgInCell_f7_Head_OpCode, const uint8_T
  x_MsgInCell_f7_Body_Data[32], const uint8_T x_MsgInCell_f8_Body_Data[44],
  const type_MotionCtrl2RecordCtrlDoseInfoMsg x_MsgInCell_f9, const
  type_MotionCtrl2RecordCtrlDailyStatMsg x_MsgInCell_f10, const
  type_RecordCtrl2SecurityMsg x_MsgInCell_f11, const type_HMI2SecurityMsg
  x_MsgInCell_f12, uint8_T x_Channel, const type_FlashAccessMsg
  *x_drvFlashAccessMsgOut, const type_CommCtrlRecordInqResponseMsg
  *x_CommVarLogMsgOut, uint16_T x_prevBufferedLargeDose, uint32_T
  x_TotalDoseAmount, const type_SysVars *x_SysVar, boolean_T
  *y_boolSendCalibraEvt, type_FlashAccessMsg *y_CommVarLogMsgOut,
  type_FlashAccessMsg *y_drvFlashAccessMsgOut, uint16_T *y_prevBufferedLargeDose,
  uint32_T *y_TotalDoseAmount, uint8_T *y_LargeDoseSubTaskMode)
{
  type_MsgHead b_y_CommVarLogMsgOut_Head;
  uint16_T TimeInfo;
  uint32_T TargetDose;
  uint32_T CompleteDose;
  boolean_T p;
  boolean_T b_p;
  uint8_T c[132];
  uint8_T d[4];
  uint32_T qY;
  uint32_T qY_0;
  int32_T i;
  *y_boolSendCalibraEvt = false;
  y_CommVarLogMsgOut->Head = x_CommVarLogMsgOut->Head;
  y_CommVarLogMsgOut->Body.MajorId = x_CommVarLogMsgOut->Body.MajorId;
  y_CommVarLogMsgOut->Body.MinorId = x_CommVarLogMsgOut->Body.MinorId;
  memcpy(&y_CommVarLogMsgOut->Body.Data[0], &x_CommVarLogMsgOut->Body.Data[0],
         132U * sizeof(uint8_T));
  *y_drvFlashAccessMsgOut = *x_drvFlashAccessMsgOut;
  *y_prevBufferedLargeDose = x_prevBufferedLargeDose;
  *y_TotalDoseAmount = x_TotalDoseAmount;
  *y_LargeDoseSubTaskMode = 0U;
  switch (x_Channel) {
   case 1:
    test2_SysIntegr_DoseCtrlMsgProc(x_MsgInCell_f1_Head_OpCode,
      x_MsgInCell_f1_Body_Data, x_drvFlashAccessMsgOut->Head.MsgId,
      x_drvFlashAccessMsgOut->Body.MinorId, x_drvFlashAccessMsgOut->Body.Data,
      &y_drvFlashAccessMsgOut->Head.MsgId, &y_drvFlashAccessMsgOut->Head.OpCode,
      &y_drvFlashAccessMsgOut->Body.MajorId,
      &y_drvFlashAccessMsgOut->Body.MinorId, y_drvFlashAccessMsgOut->Body.Data);
    break;

   case 2:
    test2_SysIntegra_ActCtrlMsgProc(x_MsgInCell_f2_Head_OpCode,
      x_MsgInCell_f2_Body_Data, y_drvFlashAccessMsgOut);
    break;

   case 3:
    i = (int32_T)(x_drvFlashAccessMsgOut->Head.MsgId + 1U);
    if ((uint32_T)i > 255U) {
      i = 255;
    }

    y_drvFlashAccessMsgOut->Head.MsgId = (uint8_T)((uint8_T)i % MAX_uint8_T);
    y_drvFlashAccessMsgOut->Head.OpCode = 1U;
    y_drvFlashAccessMsgOut->Body.MajorId = 3U;
    for (i = 0; i < 32; i++) {
      y_drvFlashAccessMsgOut->Body.Data[i] = x_MsgInCell_f3_Body_Data[i];
    }

    switch (x_MsgInCell_f3_Head_OpCode) {
     case 2:
      y_drvFlashAccessMsgOut->Body.MinorId = 1U;
      break;

     case 3:
      y_drvFlashAccessMsgOut->Body.MinorId = 2U;
      break;
    }
    break;

   case 4:
    test2_SysIntegr_FirmwareMsgProc(x_MsgInCell_f4_Head_OpCode,
      x_MsgInCell_f4_Body_Data, x_drvFlashAccessMsgOut->Head.MsgId,
      &y_drvFlashAccessMsgOut->Head.MsgId, &y_drvFlashAccessMsgOut->Head.OpCode,
      &y_drvFlashAccessMsgOut->Body.MajorId,
      &y_drvFlashAccessMsgOut->Body.MinorId, y_drvFlashAccessMsgOut->Body.Data);
    break;

   case 5:
    y_drvFlashAccessMsgOut->Head.OpCode = 1U;
    y_drvFlashAccessMsgOut->Body.MajorId = 5U;
    y_drvFlashAccessMsgOut->Body.Data[0] = x_MsgInCell_f5_Body_Data;
    i = (int32_T)(x_drvFlashAccessMsgOut->Head.MsgId + 1U);
    if ((uint32_T)i > 255U) {
      i = 255;
    }

    y_drvFlashAccessMsgOut->Head.MsgId = (uint8_T)((uint8_T)i % MAX_uint8_T);
    if (x_MsgInCell_f5_Head_OpCode == 1) {
      y_drvFlashAccessMsgOut->Body.MinorId = 1U;
    }
    break;

   case 6:
    b_y_CommVarLogMsgOut_Head = x_CommVarLogMsgOut->Head;
    y_CommVarLogMsgOut->Body.MajorId = x_CommVarLogMsgOut->Body.MajorId;
    y_CommVarLogMsgOut->Body.MinorId = x_CommVarLogMsgOut->Body.MinorId;
    memcpy(&y_CommVarLogMsgOut->Body.Data[0], &x_CommVarLogMsgOut->Body.Data[0],
           132U * sizeof(uint8_T));
    switch (x_MsgInCell_f6_Head_OpCode) {
     case 1:
      b_y_CommVarLogMsgOut_Head.OpCode = 1U;
      y_CommVarLogMsgOut->Body.MajorId = x_MsgInCell_f6_Body_MajorId;
      y_CommVarLogMsgOut->Body.MinorId = x_MsgInCell_f6_Body_MinorId;

      /* UnitDelay: '<S65>/Unit Delay1' */
      test2_SysIn_GrabSysVar2Bytes132(&test2_SysIntegration_DW.UnitDelay1_DSTATE,
        x_MsgInCell_f6_Body_MajorId, x_MsgInCell_f6_Body_MinorId, c);
      memcpy(&y_CommVarLogMsgOut->Body.Data[0], &c[0], 132U * sizeof(uint8_T));
      i = (int32_T)(x_CommVarLogMsgOut->Head.MsgId + 1U);
      if ((uint32_T)i > 255U) {
        i = 255;
      }

      b_y_CommVarLogMsgOut_Head.MsgId = (uint8_T)((uint8_T)i % MAX_uint8_T);
      break;

     case 2:
      y_drvFlashAccessMsgOut->Head.OpCode = 5U;
      y_drvFlashAccessMsgOut->Body.MajorId = x_MsgInCell_f6_Body_MajorId;
      y_drvFlashAccessMsgOut->Body.MinorId = 0U;
      i = (int32_T)(x_drvFlashAccessMsgOut->Head.MsgId + 1U);
      if ((uint32_T)i > 255U) {
        i = 255;
      }

      y_drvFlashAccessMsgOut->Head.MsgId = (uint8_T)((uint8_T)i % MAX_uint8_T);
      break;

     case 3:
      y_drvFlashAccessMsgOut->Head.OpCode = 6U;
      y_drvFlashAccessMsgOut->Body.MajorId = x_MsgInCell_f6_Body_MajorId;
      y_drvFlashAccessMsgOut->Body.MinorId = 0U;
      i = (int32_T)(x_drvFlashAccessMsgOut->Head.MsgId + 1U);
      if ((uint32_T)i > 255U) {
        i = 255;
      }

      y_drvFlashAccessMsgOut->Head.MsgId = (uint8_T)((uint8_T)i % MAX_uint8_T);
      break;

     case 4:
      y_drvFlashAccessMsgOut->Head.OpCode = 7U;
      y_drvFlashAccessMsgOut->Body.MajorId = x_MsgInCell_f6_Body_MajorId;
      y_drvFlashAccessMsgOut->Body.MinorId = 0U;
      i = (int32_T)(x_drvFlashAccessMsgOut->Head.MsgId + 1U);
      if ((uint32_T)i > 255U) {
        i = 255;
      }

      y_drvFlashAccessMsgOut->Head.MsgId = (uint8_T)((uint8_T)i % MAX_uint8_T);
      break;
    }

    y_CommVarLogMsgOut->Head = b_y_CommVarLogMsgOut_Head;
    break;

   case 7:
    for (i = 0; i < 32; i++) {
      y_drvFlashAccessMsgOut->Body.Data[i] = x_MsgInCell_f7_Body_Data[i];
    }

    y_drvFlashAccessMsgOut->Head.OpCode = 1U;
    i = (int32_T)(x_drvFlashAccessMsgOut->Head.MsgId + 1U);
    if ((uint32_T)i > 255U) {
      i = 255;
    }

    y_drvFlashAccessMsgOut->Head.MsgId = (uint8_T)((uint8_T)i % MAX_uint8_T);
    switch (x_MsgInCell_f7_Head_OpCode) {
     case 1:
      y_drvFlashAccessMsgOut->Body.MajorId = 7U;
      y_drvFlashAccessMsgOut->Body.MinorId = 1U;
      break;

     case 3:
      *y_boolSendCalibraEvt = true;
      break;

     case 4:
      y_drvFlashAccessMsgOut->Body.MajorId = 3U;
      y_drvFlashAccessMsgOut->Body.MinorId = 2U;
      break;
    }
    break;

   case 8:
    memset(&c[0], 0, 132U * sizeof(uint8_T));
    for (i = 0; i < 44; i++) {
      c[i] = x_MsgInCell_f8_Body_Data[i];
    }

    i = (int32_T)(x_CommVarLogMsgOut->Head.MsgId + 1U);
    if ((uint32_T)i > 255U) {
      i = 255;
    }

    y_CommVarLogMsgOut->Head.MsgId = (uint8_T)((uint8_T)i % MAX_uint8_T);
    y_CommVarLogMsgOut->Head.OpCode = 2U;
    y_CommVarLogMsgOut->Body.MajorId = 0U;
    y_CommVarLogMsgOut->Body.MinorId = 0U;
    memcpy(&y_CommVarLogMsgOut->Body.Data[0], &c[0], 132U * sizeof(uint8_T));
    break;

   case 9:
    if ((200 > x_MsgInCell_f9.Head.OpCode) && (x_MsgInCell_f9.Head.OpCode >= 100))
    {
      p = false;
      b_p = true;
      if (!(x_SysVar->ActCtrl.BaseRateDynVar.TimeInfo == TimeInfo)) {
        b_p = false;
      }

      if (b_p) {
        p = true;
      }

      if (!p) {
        CompleteDose = x_MsgInCell_f9.Body.CompleteDose;
        TargetDose = x_MsgInCell_f9.Body.TargetDose;
      } else {
        p = false;
        b_p = true;
        if (!(x_MsgInCell_f9.Head.OpCode == 100)) {
          b_p = false;
        }

        if (b_p) {
          p = true;
        }

        if (!p) {
          CompleteDose = x_SysVar->ActCtrl.BaseRateDynVar.CompleteDose +
            /*MW:OvSatOk*/ x_MsgInCell_f9.Body.CompleteDose;
          if (CompleteDose < x_SysVar->ActCtrl.BaseRateDynVar.CompleteDose) {
            CompleteDose = MAX_uint32_T;
          }

          TargetDose = x_SysVar->ActCtrl.BaseRateDynVar.TargetDose +
            /*MW:OvSatOk*/ x_MsgInCell_f9.Body.TargetDose;
          if (TargetDose < x_SysVar->ActCtrl.BaseRateDynVar.TargetDose) {
            TargetDose = MAX_uint32_T;
          }
        } else {
          CompleteDose = 0U;
          TargetDose = 0U;
        }
      }

      y_drvFlashAccessMsgOut->Head.OpCode = 1U;
      y_drvFlashAccessMsgOut->Body.MajorId = 2U;
      y_drvFlashAccessMsgOut->Body.MinorId = 4U;
      test2_SysI_TransDWord2FourBytes(TargetDose, d);
      y_drvFlashAccessMsgOut->Body.Data[0] = d[0];
      y_drvFlashAccessMsgOut->Body.Data[1] = d[1];
      y_drvFlashAccessMsgOut->Body.Data[2] = d[2];
      y_drvFlashAccessMsgOut->Body.Data[3] = d[3];
      y_drvFlashAccessMsgOut->Body.Data[4] = (uint8_T)(TimeInfo & 255);
      y_drvFlashAccessMsgOut->Body.Data[5] = (uint8_T)((uint32_T)(uint16_T)
        (TimeInfo & 65280) >> 8);
      test2_SysI_TransDWord2FourBytes(CompleteDose, d);
      y_drvFlashAccessMsgOut->Body.Data[6] = d[0];
      y_drvFlashAccessMsgOut->Body.Data[7] = d[1];
      y_drvFlashAccessMsgOut->Body.Data[8] = d[2];
      y_drvFlashAccessMsgOut->Body.Data[9] = d[3];
      i = (int32_T)(x_drvFlashAccessMsgOut->Head.MsgId + 1U);
      if ((uint32_T)i > 255U) {
        i = 255;
      }

      y_drvFlashAccessMsgOut->Head.MsgId = (uint8_T)((uint8_T)i % MAX_uint8_T);
    } else {
      if (x_MsgInCell_f9.Head.OpCode >= 200) {
        p = false;
        b_p = true;
        if (!(x_SysVar->ActCtrl.LargeDoseDynVar.TimeInfo == TimeInfo)) {
          b_p = false;
        }

        if (b_p) {
          p = true;
        }

        if (!p) {
          CompleteDose = x_MsgInCell_f9.Body.CompleteDose;
          TargetDose = x_MsgInCell_f9.Body.TargetDose;
        } else {
          p = false;
          b_p = true;
          if (!(x_MsgInCell_f9.Head.OpCode == 200)) {
            b_p = false;
          }

          if (b_p) {
            p = true;
          }

          if (!p) {
            CompleteDose = x_SysVar->ActCtrl.BaseRateDynVar.CompleteDose +
              /*MW:OvSatOk*/ x_MsgInCell_f9.Body.CompleteDose;
            if (CompleteDose < x_SysVar->ActCtrl.BaseRateDynVar.CompleteDose) {
              CompleteDose = MAX_uint32_T;
            }

            TargetDose = x_SysVar->ActCtrl.BaseRateDynVar.TargetDose +
              /*MW:OvSatOk*/ x_MsgInCell_f9.Body.TargetDose;
            if (TargetDose < x_SysVar->ActCtrl.BaseRateDynVar.TargetDose) {
              TargetDose = MAX_uint32_T;
            }
          } else {
            CompleteDose = 0U;
            TargetDose = 0U;
          }
        }

        y_drvFlashAccessMsgOut->Head.OpCode = 1U;
        y_drvFlashAccessMsgOut->Body.MajorId = 2U;
        y_drvFlashAccessMsgOut->Body.MinorId = 5U;
        test2_SysI_TransDWord2FourBytes(TargetDose, d);
        y_drvFlashAccessMsgOut->Body.Data[0] = d[0];
        y_drvFlashAccessMsgOut->Body.Data[1] = d[1];
        y_drvFlashAccessMsgOut->Body.Data[2] = d[2];
        y_drvFlashAccessMsgOut->Body.Data[3] = d[3];
        y_drvFlashAccessMsgOut->Body.Data[4] = (uint8_T)(TimeInfo & 255);
        y_drvFlashAccessMsgOut->Body.Data[5] = (uint8_T)((uint32_T)(uint16_T)
          (TimeInfo & 65280) >> 8);
        test2_SysI_TransDWord2FourBytes(CompleteDose, d);
        y_drvFlashAccessMsgOut->Body.Data[6] = d[0];
        y_drvFlashAccessMsgOut->Body.Data[7] = d[1];
        y_drvFlashAccessMsgOut->Body.Data[8] = d[2];
        y_drvFlashAccessMsgOut->Body.Data[9] = d[3];
        i = (int32_T)(x_drvFlashAccessMsgOut->Head.MsgId + 1U);
        if ((uint32_T)i > 255U) {
          i = 255;
        }

        y_drvFlashAccessMsgOut->Head.MsgId = (uint8_T)((uint8_T)i % MAX_uint8_T);
      }
    }
    break;

   case 10:
    if (x_MsgInCell_f10.Head.OpCode == 3) {
      TargetDose = x_MsgInCell_f10.Body.TotalAmountAcc;
      CompleteDose = x_MsgInCell_f10.Body.DailyAmountAcc;
      qY_0 = x_MsgInCell_f10.Body.LargeAmountAcc;
    } else {
      TargetDose = x_SysVar->ActCtrl.DailyDoseStatVar.TotalAmountAcc +
        /*MW:OvSatOk*/ x_MsgInCell_f10.Body.TotalAmountAcc;
      if (TargetDose < x_SysVar->ActCtrl.DailyDoseStatVar.TotalAmountAcc) {
        TargetDose = MAX_uint32_T;
      }

      CompleteDose = x_SysVar->ActCtrl.DailyDoseStatVar.DailyAmountAcc +
        /*MW:OvSatOk*/ x_MsgInCell_f10.Body.DailyAmountAcc;
      if (CompleteDose < x_SysVar->ActCtrl.DailyDoseStatVar.DailyAmountAcc) {
        CompleteDose = MAX_uint32_T;
      }

      qY_0 = x_SysVar->ActCtrl.DailyDoseStatVar.LargeAmountAcc + /*MW:OvSatOk*/
        x_MsgInCell_f10.Body.LargeAmountAcc;
      if (qY_0 < x_SysVar->ActCtrl.DailyDoseStatVar.LargeAmountAcc) {
        qY_0 = MAX_uint32_T;
      }
    }

    i = (int32_T)(x_drvFlashAccessMsgOut->Head.MsgId + 1U);
    if ((uint32_T)i > 255U) {
      i = 255;
    }

    y_drvFlashAccessMsgOut->Head.MsgId = (uint8_T)((uint8_T)i % MAX_uint8_T);
    y_drvFlashAccessMsgOut->Head.OpCode = 1U;
    y_drvFlashAccessMsgOut->Body.MajorId = 2U;
    y_drvFlashAccessMsgOut->Body.MinorId = 6U;
    y_drvFlashAccessMsgOut->Body.Data[0] = x_MsgInCell_f10.Body.DayInfo;
    qY = x_SysVar->ActCtrl.DailyDoseStatVar.ResidueDoseEst - /*MW:OvSatOk*/
      x_MsgInCell_f10.Body.ResidueDoseEst;
    if (qY > x_SysVar->ActCtrl.DailyDoseStatVar.ResidueDoseEst) {
      qY = 0U;
    }

    test2_SysI_TransDWord2FourBytes(qY, d);
    y_drvFlashAccessMsgOut->Body.Data[1] = d[0];
    y_drvFlashAccessMsgOut->Body.Data[2] = d[1];
    y_drvFlashAccessMsgOut->Body.Data[3] = d[2];
    y_drvFlashAccessMsgOut->Body.Data[4] = d[3];
    test2_SysI_TransDWord2FourBytes(TargetDose, d);
    y_drvFlashAccessMsgOut->Body.Data[5] = d[0];
    y_drvFlashAccessMsgOut->Body.Data[6] = d[1];
    y_drvFlashAccessMsgOut->Body.Data[7] = d[2];
    y_drvFlashAccessMsgOut->Body.Data[8] = d[3];
    test2_SysI_TransDWord2FourBytes(CompleteDose, d);
    y_drvFlashAccessMsgOut->Body.Data[9] = d[0];
    y_drvFlashAccessMsgOut->Body.Data[10] = d[1];
    y_drvFlashAccessMsgOut->Body.Data[11] = d[2];
    y_drvFlashAccessMsgOut->Body.Data[12] = d[3];
    test2_SysI_TransDWord2FourBytes(qY_0, d);
    y_drvFlashAccessMsgOut->Body.Data[13] = d[0];
    y_drvFlashAccessMsgOut->Body.Data[14] = d[1];
    y_drvFlashAccessMsgOut->Body.Data[15] = d[2];
    y_drvFlashAccessMsgOut->Body.Data[16] = d[3];
    break;

   case 11:
    if (x_MsgInCell_f11.Head.OpCode == 4) {
      i = (int32_T)(x_drvFlashAccessMsgOut->Head.MsgId + 1U);
      if ((uint32_T)i > 255U) {
        i = 255;
      }

      y_drvFlashAccessMsgOut->Head.MsgId = (uint8_T)((uint8_T)i % MAX_uint8_T);
      y_drvFlashAccessMsgOut->Head.OpCode = 1U;
      y_drvFlashAccessMsgOut->Body.MajorId = 5U;
      y_drvFlashAccessMsgOut->Body.MinorId = 2U;
      for (i = 0; i < 10; i++) {
        y_drvFlashAccessMsgOut->Body.Data[i] = x_MsgInCell_f11.Body.Data[i];
      }
    }
    break;

   case 12:
    *y_LargeDoseSubTaskMode = x_MsgInCell_f12.Head.OpCode;
    break;
  }
}

/* Function for Chart: '<S65>/Chart' */
static void test_TempBaseRateDumpManagement(void)
{
  int32_T tmp;
  switch (test2_SysIntegration_DW.bitsForTID4.is_TempBaseRateDumpManagement) {
   case test2_SysIntegration_IN_Dump:
    if (test2_SysIntegration_DW.temporalCounter_i1_g >= 100U) {
      test2_SysIntegration_DW.bitsForTID4.is_TempBaseRateDumpManagement =
        test2_SysIntegration_IN_Idle_n;
    }
    break;

   case test2_SysIntegration_IN_Idle_n:
    if (test2_SysIntegration_DW.sfEvent_o == test2_SysInteg_event_TBRDumpEvt) {
      test2_SysIntegration_DW.bitsForTID4.is_TempBaseRateDumpManagement =
        test2_SysIntegration_IN_Dump;
      test2_SysIntegration_DW.temporalCounter_i1_g = 0U;
      tmp = (int32_T)(test2_SysIntegration_B.drvFlashAccessMsgOut.Head.MsgId +
                      1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      test2_SysIntegration_B.drvFlashAccessMsgOut.Head.MsgId = (uint8_T)
        ((uint8_T)tmp % MAX_uint8_T);
      test2_SysIntegration_B.drvFlashAccessMsgOut.Head.OpCode = 10U;
      test2_SysIntegration_B.drvFlashAccessMsgOut.Body.MajorId = 1U;
      test2_SysIntegration_B.drvFlashAccessMsgOut.Body.MinorId = 3U;
      memset(&test2_SysIntegration_B.drvFlashAccessMsgOut.Body.Data[0], 0, 132U *
             sizeof(uint8_T));
    }
    break;
  }
}

/* Function for Chart: '<S65>/Chart' */
static void test2_S_LargeDoseDumpManagement(void)
{
  int32_T tmp;
  if (test2_SysIntegration_DW.sfEvent_o == test2_Sy_event_LargeDoseDumpEvt) {
    tmp = (int32_T)(test2_SysIntegration_B.drvFlashAccessMsgOut.Head.MsgId + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    test2_SysIntegration_B.drvFlashAccessMsgOut.Head.MsgId = (uint8_T)((uint8_T)
      tmp % MAX_uint8_T);
    test2_SysIntegration_B.drvFlashAccessMsgOut.Head.OpCode = 1U;
    test2_SysIntegration_B.drvFlashAccessMsgOut.Body.MajorId = 1U;
    test2_SysIntegration_B.drvFlashAccessMsgOut.Body.MinorId = 5U;
    memset(&test2_SysIntegration_B.drvFlashAccessMsgOut.Body.Data[0], 0, 132U *
           sizeof(uint8_T));
  }
}

/* Function for Chart: '<S65>/Chart' */
static void ThreeTypeDoseDeliveryPlanManage(void)
{
  boolean_T p;
  boolean_T b_p;
  int32_T b_previousEvent;
  boolean_T guard1 = false;

  /* UnitDelay: '<S65>/Unit Delay1' */
  /* Constant: '<S65>/Constant' */
  guard1 = false;
  if ((400U *
       test2_SysIntegration_DW.UnitDelay1_DSTATE.DoseCtrl.LastTBRConfigDay[0] +
       40U *
       test2_SysIntegration_DW.UnitDelay1_DSTATE.DoseCtrl.LastTBRConfigDay[1]) +
      test2_SysIntegration_DW.UnitDelay1_DSTATE.DoseCtrl.LastTBRConfigDay[2] <
      (400U * test2_SysIntegration_B.UnitDelay_a.Time[0] + 40U *
       test2_SysIntegration_B.UnitDelay_a.Time[1]) +
      test2_SysIntegration_B.UnitDelay_a.Time[2]) {
    p = false;
    b_p = true;
    if (!(test2_SysIntegration_B.UnitDelay_a.Time[2] == 0)) {
      b_p = false;
    }

    if (b_p) {
      p = true;
    }

    if (!p) {
      p = false;
      b_p = true;
      if (!((test2_SysIntegration_DW.UnitDelay1_DSTATE.DoseCtrl.LastTBRConfigDay[
             0] +
             test2_SysIntegration_DW.UnitDelay1_DSTATE.DoseCtrl.LastTBRConfigDay[
             1]) +
            test2_SysIntegration_DW.UnitDelay1_DSTATE.DoseCtrl.LastTBRConfigDay
            [2] == 0)) {
        b_p = false;
      }

      if (b_p) {
        p = true;
      }

      if ((!p) &&
          (test2_SysIntegration_DW.bitsForTID4.is_TempBaseRateDumpManagement ==
           test2_SysIntegration_IN_Idle_n)) {
        b_previousEvent = test2_SysIntegration_DW.sfEvent_o;
        test2_SysIntegration_DW.sfEvent_o = test2_SysInteg_event_TBRDumpEvt;
        if (test2_SysIntegration_DW.bitsForTID4.is_active_TempBaseRateDumpManag
            != 0U) {
          test_TempBaseRateDumpManagement();
        }

        test2_SysIntegration_DW.sfEvent_o = b_previousEvent;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    p = false;
    b_p = true;
    if (!(test2_SysIntegration_DW.UnitDelay1_DSTATE.DoseCtrl.LargeDoseConfig.EffectiveDay
          == 0)) {
      b_p = false;
    }

    if (b_p) {
      p = true;
    }

    if ((!p) && (!test2_SysIntegration_DW.bitsForTID4.boolLargeDoseMonitorEnable))
    {
      test2_SysIntegration_DW.bitsForTID4.boolLargeDoseMonitorEnable = true;
    }
  }

  guard1 = false;
  switch (test2_SysIntegration_DW.bitsForTID4.is_ThreeTypeDoseDeliveryPlanMan) {
   case test2_SysIn_IN_LargeDoseMonitor:
    if (test2_SysIntegration_DW.sfEvent_o == event_ProcessLargeDoseSubTaskAr) {
      test2_SysIntegration_DW.bitsForTID4.is_LargeDoseMonitor = 0;
      test2_SysIntegration_DW.bitsForTID4.is_ThreeTypeDoseDeliveryPlanMan =
        test2_SysIn_IN_LargeDoseMonitor;
      if (test2_SysIntegration_DW.bitsForTID4.is_LargeDoseMonitor !=
          test2_SysIntegratio_IN_SwitchOn) {
        test2_SysIntegration_DW.bitsForTID4.is_LargeDoseMonitor =
          test2_SysIntegratio_IN_SwitchOn;
        b_previousEvent = (int32_T)
          (test2_SysIntegration_B.RelativeTimerApplyMsg.Head.MsgId + 1U);
        if ((uint32_T)b_previousEvent > 255U) {
          b_previousEvent = 255;
        }

        test2_SysIntegration_B.RelativeTimerApplyMsg.Head.MsgId = (uint8_T)
          ((uint8_T)b_previousEvent % MAX_uint8_T);
        test2_SysIntegration_B.RelativeTimerApplyMsg.Head.OpCode = 1U;
        test2_SysIntegration_B.RelativeTimerApplyMsg.Body.Data = 1U;
      }
    } else if (test2_SysIntegration_DW.bitsForTID4.is_LargeDoseMonitor ==
               test2_SysInt_IN_LargeDoseCancel) {
      guard1 = true;
    } else {
      p = false;
      b_p = true;

      /* UnitDelay: '<S65>/Unit Delay1' */
      if (!(test2_SysIntegration_DW.UnitDelay1_DSTATE.DoseCtrl.LargeDoseConfig.EffectiveDay
            == 0)) {
        b_p = false;
      }

      if (b_p) {
        p = true;
      }

      if (p || (test2_SysIntegration_DW.sfEvent_o ==
                event_LastLargeDoseSubTaskArriv)) {
        guard1 = true;
      } else {
        switch (test2_SysIntegration_DW.bitsForTID4.is_LargeDoseMonitor) {
         case test2_SysInt_IN_LargeDoseCancel:
          break;

         case test2_SysIntegrati_IN_SwitchOff:
          if (test2_SysIntegration_B.bitsForTID4.boolNormalDeliverySwitchOn) {
            test2_SysIntegration_DW.bitsForTID4.is_LargeDoseMonitor =
              test2_SysIntegratio_IN_SwitchOn;
            b_previousEvent = (int32_T)
              (test2_SysIntegration_B.RelativeTimerApplyMsg.Head.MsgId + 1U);
            if ((uint32_T)b_previousEvent > 255U) {
              b_previousEvent = 255;
            }

            test2_SysIntegration_B.RelativeTimerApplyMsg.Head.MsgId = (uint8_T)
              ((uint8_T)b_previousEvent % MAX_uint8_T);
            test2_SysIntegration_B.RelativeTimerApplyMsg.Head.OpCode = 1U;
            test2_SysIntegration_B.RelativeTimerApplyMsg.Body.Data = 1U;
          } else {
            if (test2_SysIntegration_DW.temporalCounter_i2_c >= 9000U) {
              test2_SysIntegration_DW.bitsForTID4.is_LargeDoseMonitor =
                test2_SysInt_IN_LargeDoseCancel;
            }
          }
          break;

         case test2_SysIntegratio_IN_SwitchOn:
          if (!test2_SysIntegration_B.bitsForTID4.boolNormalDeliverySwitchOn) {
            test2_SysIntegration_DW.bitsForTID4.is_LargeDoseMonitor =
              test2_SysIntegrati_IN_SwitchOff;
            test2_SysIntegration_DW.temporalCounter_i2_c = 0U;
            b_previousEvent = (int32_T)
              (test2_SysIntegration_B.RelativeTimerApplyMsg.Head.MsgId + 1U);
            if ((uint32_T)b_previousEvent > 255U) {
              b_previousEvent = 255;
            }

            test2_SysIntegration_B.RelativeTimerApplyMsg.Head.MsgId = (uint8_T)
              ((uint8_T)b_previousEvent % MAX_uint8_T);
            test2_SysIntegration_B.RelativeTimerApplyMsg.Head.OpCode = 1U;
            test2_SysIntegration_B.RelativeTimerApplyMsg.Body.Data = 0U;
          }
          break;
        }
      }
    }
    break;

   case test2_SysInt_IN_NoLargeDoseTask:
    if (test2_SysIntegration_DW.bitsForTID4.boolLargeDoseMonitorEnable) {
      test2_SysIntegration_DW.bitsForTID4.is_ThreeTypeDoseDeliveryPlanMan =
        test2_SysIn_IN_LargeDoseMonitor;
      if (test2_SysIntegration_DW.bitsForTID4.is_LargeDoseMonitor !=
          test2_SysIntegratio_IN_SwitchOn) {
        test2_SysIntegration_DW.bitsForTID4.is_LargeDoseMonitor =
          test2_SysIntegratio_IN_SwitchOn;
        b_previousEvent = (int32_T)
          (test2_SysIntegration_B.RelativeTimerApplyMsg.Head.MsgId + 1U);
        if ((uint32_T)b_previousEvent > 255U) {
          b_previousEvent = 255;
        }

        test2_SysIntegration_B.RelativeTimerApplyMsg.Head.MsgId = (uint8_T)
          ((uint8_T)b_previousEvent % MAX_uint8_T);
        test2_SysIntegration_B.RelativeTimerApplyMsg.Head.OpCode = 1U;
        test2_SysIntegration_B.RelativeTimerApplyMsg.Body.Data = 1U;
      }
    }
    break;
  }

  if (guard1) {
    b_previousEvent = test2_SysIntegration_DW.sfEvent_o;
    test2_SysIntegration_DW.sfEvent_o = test2_Sy_event_LargeDoseDumpEvt;
    if (test2_SysIntegration_DW.bitsForTID4.is_active_LargeDoseDumpManageme !=
        0U) {
      test2_S_LargeDoseDumpManagement();
    }

    test2_SysIntegration_DW.sfEvent_o = b_previousEvent;
    test2_SysIntegration_DW.bitsForTID4.is_LargeDoseMonitor = 0;
    test2_SysIntegration_DW.bitsForTID4.is_ThreeTypeDoseDeliveryPlanMan =
      test2_SysInt_IN_NoLargeDoseTask;
    test2_SysIntegration_DW.bitsForTID4.boolLargeDoseMonitorEnable = false;
    b_previousEvent = (int32_T)
      (test2_SysIntegration_B.RelativeTimerApplyMsg.Head.MsgId + 1U);
    if ((uint32_T)b_previousEvent > 255U) {
      b_previousEvent = 255;
    }

    test2_SysIntegration_B.RelativeTimerApplyMsg.Head.MsgId = (uint8_T)((uint8_T)
      b_previousEvent % MAX_uint8_T);
    test2_SysIntegration_B.RelativeTimerApplyMsg.Head.OpCode = 0U;
    test2_SysIntegration_B.RelativeTimerApplyMsg.Body.Data = 0U;
  }

  /* End of Constant: '<S65>/Constant' */
}

/* Function for Chart: '<S65>/Chart' */
static void test2_SysInteg_DeliverySwitchOn(void)
{
  boolean_T p;
  boolean_T b_p;
  int32_T tmp;
  boolean_T guard1 = false;
  p = false;
  b_p = true;

  /* UnitDelay: '<S65>/Unit Delay1' */
  if (!(test2_SysIntegration_DW.UnitDelay1_DSTATE.ActCtrl.DeliverSwitch == 0)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  guard1 = false;
  if (p && test2_SysIntegration_B.bitsForTID4.boolNormalDeliverySwitchOn) {
    tmp = (int32_T)(test2_SysIntegration_B.SysDiagMsgOut.Head.MsgId + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    test2_SysIntegration_B.SysDiagMsgOut.Head.MsgId = (uint8_T)((uint8_T)tmp %
      MAX_uint8_T);
    test2_SysIntegration_B.SysDiagMsgOut.Head.OpCode = 1U;
    test2_SysIntegration_B.SysDiagMsgOut.Body.Data = 203U;
    guard1 = true;
  } else {
    if (test2_SysIntegration_B.bitsForTID4.boolNormalDeliverySwitchOn) {
      p = false;
      b_p = true;

      /* UnitDelay: '<S65>/Unit Delay1' */
      if (!(test2_SysIntegration_DW.UnitDelay1_DSTATE.ActCtrl.DeliverSwitch == 0))
      {
        b_p = false;
      }

      if (b_p) {
        p = true;
      }
    } else {
      p = false;
    }

    if (p) {
      tmp = (int32_T)(test2_SysIntegration_B.SysDiagMsgOut.Head.MsgId + 1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      test2_SysIntegration_B.SysDiagMsgOut.Head.MsgId = (uint8_T)((uint8_T)tmp %
        MAX_uint8_T);
      test2_SysIntegration_B.SysDiagMsgOut.Head.OpCode = 1U;
      test2_SysIntegration_B.SysDiagMsgOut.Body.Data = 251U;
      guard1 = true;
    } else {
      p = false;
      b_p = true;

      /* UnitDelay: '<S65>/Unit Delay1' */
      if (!(test2_SysIntegration_DW.UnitDelay1_DSTATE.ActCtrl.DeliverSwitch == 0))
      {
        b_p = false;
      }

      if (b_p) {
        p = true;
      }

      if (p && test2_SysIntegration_B.bitsForTID4.boolAirExpelSwitchOn) {
        tmp = (int32_T)(test2_SysIntegration_B.SysDiagMsgOut.Head.MsgId + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        test2_SysIntegration_B.SysDiagMsgOut.Head.MsgId = (uint8_T)((uint8_T)tmp
          % MAX_uint8_T);
        test2_SysIntegration_B.SysDiagMsgOut.Head.OpCode = 1U;
        test2_SysIntegration_B.SysDiagMsgOut.Body.Data = 107U;
        guard1 = true;
      } else {
        switch (test2_SysIntegration_DW.bitsForTID4.is_DeliverySwitchOn) {
         case test2_SysIntegra_IN_MedicineLow:
          /* UnitDelay: '<S65>/Unit Delay1' */
          if (test2_SysIntegration_DW.UnitDelay1_DSTATE.ActCtrl.DailyDoseStatVar.ResidueDoseEst
              < 1000U) {
            test2_SysIntegration_DW.bitsForTID4.is_DeliverySwitchOn =
              test2_SysIntegr_IN_MedicineOver;
            test2_SysIntegration_DW.temporalCounter_i3 = 0U;
            tmp = (int32_T)(test2_SysIntegration_B.SysDiagMsgOut.Head.MsgId + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            test2_SysIntegration_B.SysDiagMsgOut.Head.MsgId = (uint8_T)((uint8_T)
              tmp % MAX_uint8_T);
            test2_SysIntegration_B.SysDiagMsgOut.Head.OpCode = 1U;
            test2_SysIntegration_B.SysDiagMsgOut.Body.Data = 2U;
          } else {
            if (test2_SysIntegration_DW.temporalCounter_i3 >= 6000U) {
              test2_SysIntegration_DW.bitsForTID4.is_DeliverySwitchOn =
                test2_SysIntegra_IN_MedicineLow;
              test2_SysIntegration_DW.temporalCounter_i3 = 0U;
              tmp = (int32_T)(test2_SysIntegration_B.SysDiagMsgOut.Head.MsgId +
                              1U);
              if ((uint32_T)tmp > 255U) {
                tmp = 255;
              }

              test2_SysIntegration_B.SysDiagMsgOut.Head.MsgId = (uint8_T)
                ((uint8_T)tmp % MAX_uint8_T);
              test2_SysIntegration_B.SysDiagMsgOut.Head.OpCode = 1U;
              test2_SysIntegration_B.SysDiagMsgOut.Body.Data = 202U;
            }
          }
          break;

         case test2_SysIntegr_IN_MedicineOver:
          if (test2_SysIntegration_DW.temporalCounter_i3 >= 600U) {
            test2_SysIntegration_DW.bitsForTID4.is_DeliverySwitchOn =
              test2_SysIntegr_IN_MedicineOver;
            test2_SysIntegration_DW.temporalCounter_i3 = 0U;
            tmp = (int32_T)(test2_SysIntegration_B.SysDiagMsgOut.Head.MsgId + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            test2_SysIntegration_B.SysDiagMsgOut.Head.MsgId = (uint8_T)((uint8_T)
              tmp % MAX_uint8_T);
            test2_SysIntegration_B.SysDiagMsgOut.Head.OpCode = 1U;
            test2_SysIntegration_B.SysDiagMsgOut.Body.Data = 2U;
          }
          break;

         case test2_SysIntegration_IN_Unknown:
          /* UnitDelay: '<S65>/Unit Delay1' */
          if (test2_SysIntegration_DW.UnitDelay1_DSTATE.ActCtrl.DailyDoseStatVar.ResidueDoseEst
              < 1000U) {
            test2_SysIntegration_DW.bitsForTID4.is_DeliverySwitchOn =
              test2_SysIntegr_IN_MedicineOver;
            test2_SysIntegration_DW.temporalCounter_i3 = 0U;
            tmp = (int32_T)(test2_SysIntegration_B.SysDiagMsgOut.Head.MsgId + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            test2_SysIntegration_B.SysDiagMsgOut.Head.MsgId = (uint8_T)((uint8_T)
              tmp % MAX_uint8_T);
            test2_SysIntegration_B.SysDiagMsgOut.Head.OpCode = 1U;
            test2_SysIntegration_B.SysDiagMsgOut.Body.Data = 2U;
          } else {
            if (test2_SysIntegration_DW.UnitDelay1_DSTATE.ActCtrl.DailyDoseStatVar.ResidueDoseEst
                <
                test2_SysIntegration_DW.UnitDelay1_DSTATE.DoseCtrl.DoseCtrlParam.LowDoseTHValue
                * 1000U) {
              test2_SysIntegration_DW.bitsForTID4.is_DeliverySwitchOn =
                test2_SysIntegra_IN_MedicineLow;
              test2_SysIntegration_DW.temporalCounter_i3 = 0U;
              tmp = (int32_T)(test2_SysIntegration_B.SysDiagMsgOut.Head.MsgId +
                              1U);
              if ((uint32_T)tmp > 255U) {
                tmp = 255;
              }

              test2_SysIntegration_B.SysDiagMsgOut.Head.MsgId = (uint8_T)
                ((uint8_T)tmp % MAX_uint8_T);
              test2_SysIntegration_B.SysDiagMsgOut.Head.OpCode = 1U;
              test2_SysIntegration_B.SysDiagMsgOut.Body.Data = 202U;
            }
          }
          break;
        }
      }
    }
  }

  if (guard1) {
    test2_SysIntegration_DW.bitsForTID4.is_DeliverySwitchOn = 0;
    test2_SysIntegration_DW.bitsForTID4.is_GeneralDeliveryStateManageme =
      test2_SysI_IN_DeliverySwitchOff;
    test2_SysIntegration_B.bitsForTID4.boolNormalDeliverySwitchOn = false;
    test2_SysIntegration_B.bitsForTID4.boolAirExpelSwitchOn = false;
    test2_SysIntegration_B.bitsForTID4.boolHomingOn = false;
  }
}

/* Function for Chart: '<S65>/Chart' */
static void test2_SysIntegrati_MsgInProcess(const
  type_MotionCtrl2RecordCtrlDoseInfoMsg *UnitDelay4, const type_HMI2SecurityMsg *
  UnitDelay2_f)
{
  uint8_T LargeDoseSubTaskMode;
  boolean_T p;
  boolean_T b_p;
  int32_T b_previousEvent;
  type_FlashAccessMsg CommVarLogMsgOut;
  uint8_T tmp[12];
  int32_T tmp_0;
  uint16_T tmp_1;
  uint32_T tmp_2;
  boolean_T guard1 = false;
  boolean_T exitg1;
  p = false;
  b_p = true;
  b_previousEvent = 0;
  exitg1 = false;
  while ((!exitg1) && (b_previousEvent < 12)) {
    if (test2_SysIntegration_DW.SwitchOnVector_k[b_previousEvent]) {
      b_p = false;
      exitg1 = true;
    } else {
      b_previousEvent++;
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    test2_SysIntegration_B.bitsForTID4.WorkStatus = true;
    b_previousEvent = (int32_T)(test2_SysIntegration_DW.inputChannel + 1U);
    tmp_0 = b_previousEvent;
    if ((uint32_T)b_previousEvent > 255U) {
      tmp_0 = 255;
    }

    if (test2_SysIntegration_DW.SwitchOnVector_k[tmp_0 - 1]) {
      tmp_0 = b_previousEvent;
      if ((uint32_T)b_previousEvent > 255U) {
        tmp_0 = 255;
      }

      test2_SysIntegration_DW.SwitchOnVector_k[tmp_0 - 1] = false;
      tmp_0 = b_previousEvent;
      if ((uint32_T)b_previousEvent > 255U) {
        tmp_0 = 255;
      }

      /* UnitDelay: '<S65>/Unit Delay6' incorporates:
       *  UnitDelay: '<S65>/Unit Delay1'
       */
      test2_SysIntegratio_GPMsgInProc
        (test2_SysIntegration_B.DoseCtrlMsgOut.Head.OpCode,
         test2_SysIntegration_B.DoseCtrlMsgOut.Body.Data,
         test2_SysIntegration_B.ActCtrlMsgOut.Head.OpCode,
         test2_SysIntegration_B.ActCtrlMsgOut.Body.Data,
         test2_SysIntegration_B.AlarmCtrlMsgOut.Head.OpCode,
         test2_SysIntegration_B.AlarmCtrlMsgOut.Body.Data,
         test2_SysIntegration_B.FirmwareMsgOut.Head.OpCode,
         test2_SysIntegration_B.FirmwareMsgOut.Body.Data,
         test2_SysIntegration_B.SysSettingMsgOut.Head.OpCode,
         test2_SysIntegration_B.SysSettingMsgOut.Body.Data,
         test2_SysIntegration_B.RecordInqMsgOut.Head.OpCode,
         test2_SysIntegration_B.RecordInqMsgOut.Body.MajorId,
         test2_SysIntegration_B.RecordInqMsgOut.Body.MinorId,
         test2_SysIntegration_B.CalibraMsgOut.Head.OpCode,
         test2_SysIntegration_B.CalibraMsgOut.Body.Data,
         test2_SysIntegration_DW.UnitDelay5_DSTATE.Body.Data, *UnitDelay4,
         test2_SysIntegration_B.UnitDelay3,
         test2_SysIntegration_DW.UnitDelay6_DSTATE, *UnitDelay2_f, (uint8_T)
         tmp_0, &test2_SysIntegration_B.drvFlashAccessMsgOut,
         &test2_SysIntegration_B.CommVarLogMsgOut,
         test2_SysIntegration_DW.prevBufferedLargeDose,
         test2_SysIntegration_DW.prevTotalDoseAmount,
         &test2_SysIntegration_DW.UnitDelay1_DSTATE, &p, &CommVarLogMsgOut,
         &test2_SysIntegration_B.drvFlashAccessMsgOut, &tmp_1, &tmp_2,
         &LargeDoseSubTaskMode);
      test2_SysIntegration_DW.prevTotalDoseAmount = tmp_2;
      test2_SysIntegration_DW.prevBufferedLargeDose = tmp_1;
      test2_SysIntegration_B.CommVarLogMsgOut.Head = CommVarLogMsgOut.Head;
      test2_SysIntegration_B.CommVarLogMsgOut.Body.MajorId =
        CommVarLogMsgOut.Body.MajorId;
      test2_SysIntegration_B.CommVarLogMsgOut.Body.MinorId =
        CommVarLogMsgOut.Body.MinorId;
      memcpy(&test2_SysIntegration_B.CommVarLogMsgOut.Body.Data[0],
             &CommVarLogMsgOut.Body.Data[0], 132U * sizeof(uint8_T));
      if (p) {
        test2_SysIntegration_DW.CalibraStartEvtEventCounter++;
      }

      if ((uint32_T)b_previousEvent > 255U) {
        b_previousEvent = 255;
      }

      test2_SysIntegration_DW.inputChannel = (uint8_T)((uint8_T)b_previousEvent %
        12);
      p = false;
      b_p = true;
      if (!(LargeDoseSubTaskMode == 11)) {
        b_p = false;
      }

      if (b_p) {
        p = true;
      }

      if (p) {
        b_previousEvent = test2_SysIntegration_DW.sfEvent_o;
        test2_SysIntegration_DW.sfEvent_o = event_ProcessLargeDoseSubTaskAr;
        if (test2_SysIntegration_DW.bitsForTID4.is_active_ThreeTypeDoseDelivery
            != 0U) {
          ThreeTypeDoseDeliveryPlanManage();
        }

        test2_SysIntegration_DW.sfEvent_o = b_previousEvent;
      } else {
        p = false;
        b_p = true;
        if (!(LargeDoseSubTaskMode == 12)) {
          b_p = false;
        }

        if (b_p) {
          p = true;
        }

        if (p) {
          b_previousEvent = test2_SysIntegration_DW.sfEvent_o;
          test2_SysIntegration_DW.sfEvent_o = event_LastLargeDoseSubTaskArriv;
          if (test2_SysIntegration_DW.bitsForTID4.is_active_ThreeTypeDoseDelivery
              != 0U) {
            ThreeTypeDoseDeliveryPlanManage();
          }

          test2_SysIntegration_DW.sfEvent_o = b_previousEvent;
        }
      }
    }
  } else {
    test2_SysIntegration_B.bitsForTID4.WorkStatus = false;
    for (b_previousEvent = 0; b_previousEvent < 12; b_previousEvent++) {
      tmp[b_previousEvent] =
        test2_SysIntegration_DW.prevInpMsgIdVector[b_previousEvent];
    }

    /* UnitDelay: '<S65>/Unit Delay5' incorporates:
     *  UnitDelay: '<S65>/Unit Delay6'
     */
    ChkRecordCtrlMsgInIdVectorChang(tmp,
      test2_SysIntegration_B.DoseCtrlMsgOut.Head.MsgId,
      test2_SysIntegration_B.ActCtrlMsgOut.Head.MsgId,
      test2_SysIntegration_B.AlarmCtrlMsgOut.Head.MsgId,
      test2_SysIntegration_B.FirmwareMsgOut.Head.MsgId,
      test2_SysIntegration_B.SysSettingMsgOut.Head.MsgId,
      test2_SysIntegration_B.RecordInqMsgOut.Head.MsgId,
      test2_SysIntegration_B.CalibraMsgOut.Head.MsgId,
      test2_SysIntegration_DW.UnitDelay5_DSTATE.Head.MsgId,
      UnitDelay4->Head.MsgId, test2_SysIntegration_B.UnitDelay3.Head.MsgId,
      test2_SysIntegration_DW.UnitDelay6_DSTATE.Head.MsgId,
      UnitDelay2_f->Head.MsgId, test2_SysIntegration_DW.SwitchOnVector_k,
      test2_SysIntegration_DW.prevInpMsgIdVector);
  }

  if (test2_SysIntegration_DW.bitsForTID4.is_active_GeneralDeliveryStateM != 0U)
  {
    guard1 = false;
    switch (test2_SysIntegration_DW.bitsForTID4.is_GeneralDeliveryStateManageme)
    {
     case test2_SysI_IN_DeliverySwitchOff:
      p = false;
      b_p = true;

      /* UnitDelay: '<S65>/Unit Delay1' */
      if (!(test2_SysIntegration_DW.UnitDelay1_DSTATE.ActCtrl.DeliverSwitch == 1))
      {
        b_p = false;
      }

      if (b_p) {
        p = true;
      }

      if (p) {
        test2_SysIntegration_B.bitsForTID4.boolAirExpelSwitchOn = true;
        guard1 = true;
      } else {
        p = false;
        b_p = true;

        /* UnitDelay: '<S65>/Unit Delay1' */
        if (!(test2_SysIntegration_DW.UnitDelay1_DSTATE.ActCtrl.DeliverSwitch ==
              2)) {
          b_p = false;
        }

        if (b_p) {
          p = true;
        }

        if (p) {
          test2_SysIntegration_B.bitsForTID4.boolNormalDeliverySwitchOn = true;
          guard1 = true;
        } else {
          p = false;
          b_p = true;

          /* UnitDelay: '<S65>/Unit Delay1' */
          if (!(test2_SysIntegration_DW.UnitDelay1_DSTATE.ActCtrl.DeliverSwitch ==
                3)) {
            b_p = false;
          }

          if (b_p) {
            p = true;
          }

          if (p) {
            test2_SysIntegration_B.bitsForTID4.boolHomingOn = true;
            guard1 = true;
          }
        }
      }
      break;

     case test2_SysIn_IN_DeliverySwitchOn:
      test2_SysInteg_DeliverySwitchOn();
      break;
    }

    if (guard1) {
      test2_SysIntegration_DW.bitsForTID4.is_GeneralDeliveryStateManageme =
        test2_SysIn_IN_DeliverySwitchOn;
      test2_SysIntegration_DW.bitsForTID4.is_DeliverySwitchOn =
        test2_SysIntegration_IN_Unknown;
    }
  }

  if (test2_SysIntegration_DW.bitsForTID4.is_active_TempBaseRateAndLargeD != 0U)
  {
    if (test2_SysIntegration_DW.bitsForTID4.is_active_ThreeTypeDoseDelivery !=
        0U) {
      ThreeTypeDoseDeliveryPlanManage();
    }

    if (test2_SysIntegration_DW.bitsForTID4.is_active_TempBaseRateDumpManag !=
        0U) {
      test_TempBaseRateDumpManagement();
    }

    if (test2_SysIntegration_DW.bitsForTID4.is_active_LargeDoseDumpManageme !=
        0U) {
      test2_S_LargeDoseDumpManagement();
    }
  }
}

/* Function for Chart: '<S89>/Chart' */
static void chartstep_c17_test2_SysIntegrat(const type_HMI2SecurityMsg
  *UnitDelay_k, const int32_T *sfEvent_h)
{
  boolean_T sf_internal_predicateOutput;
  boolean_T b_p;
  int32_T tmp;
  switch (test2_SysIntegration_DW.bitsForTID0.is_c17_test2_SysIntegration) {
   case test2_SysIntegra_IN_AirExpelErr:
    break;

   case test2_SysIntegration_IN_Init_b:
    if (*sfEvent_h == test2_Sy_event_StartAirExpelEvt) {
      test2_SysIntegration_DW.AirExpelEnaEvtEventCounter++;
      test2_SysIntegration_DW.bitsForTID0.is_c17_test2_SysIntegration =
        test2_SysIntegration_IN_OpStart;
      test2_SysIntegration_DW.temporalCounter_i1_ig = 0U;
      test2_SysIntegration_DW.bitsForTID0.is_OpStart =
        test2_SysIntegr_IN_Wait4FdbkMsg;
      test2_SysIntegration_DW.bitsForTID0.boolFDBK = false;
      test2_SysIntegration_DW.prevFDBKMsgId = UnitDelay_k->Head.MsgId;
    }
    break;

   case test2_SysIntegration_IN_OpStart:
    sf_internal_predicateOutput = ((*sfEvent_h ==
      test2_Sys_event_StopAirExpelEvt) &&
      (test2_SysIntegration_DW.bitsForTID0.is_OpStart ==
       test2_Sys_IN_AirExpelCtrlNormal));
    if (sf_internal_predicateOutput) {
      test2_SysIntegration_DW.AirExpelEnaEvtEventCounter++;
      if (test2_SysIntegration_DW.bitsForTID0.is_OpStart ==
          test2_Sys_IN_AirExpelCtrlNormal) {
        test2_SysIntegration_B.bitsForTID0.boolTrimEnable = false;
        test2_SysIntegration_DW.bitsForTID0.is_OpStart = 0;
      } else {
        test2_SysIntegration_DW.bitsForTID0.is_OpStart = 0;
      }

      test2_SysIntegration_DW.bitsForTID0.is_c17_test2_SysIntegration =
        test2_SysIntegration_IN_OpStop;
      test2_SysIntegration_DW.temporalCounter_i1_ig = 0U;
      test2_SysIntegration_DW.bitsForTID0.is_OpStop =
        test2_SysIntegr_IN_Wait4FdbkMsg;
      test2_SysIntegration_DW.bitsForTID0.boolFDBK = false;
      test2_SysIntegration_DW.prevFDBKMsgId = UnitDelay_k->Head.MsgId;
    } else {
      sf_internal_predicateOutput =
        ((test2_SysIntegration_DW.temporalCounter_i1_ig >= 10) &&
         (!test2_SysIntegration_DW.bitsForTID0.boolFDBK));
      if (sf_internal_predicateOutput) {
        if (test2_SysIntegration_DW.bitsForTID0.is_OpStart ==
            test2_Sys_IN_AirExpelCtrlNormal) {
          test2_SysIntegration_B.bitsForTID0.boolTrimEnable = false;
          test2_SysIntegration_DW.bitsForTID0.is_OpStart = 0;
        } else {
          test2_SysIntegration_DW.bitsForTID0.is_OpStart = 0;
        }

        test2_SysIntegration_DW.bitsForTID0.is_c17_test2_SysIntegration =
          test2_SysIntegra_IN_AirExpelErr;
        tmp = (int32_T)(test2_SysIntegration_B.ErrDiagMsg.Head.MsgId + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        test2_SysIntegration_B.ErrDiagMsg.Head.MsgId = (uint8_T)((uint8_T)tmp %
          MAX_uint8_T);
        test2_SysIntegration_B.ErrDiagMsg.Head.OpCode = 1U;
        test2_SysIntegration_B.ErrDiagMsg.Body.Data = 13U;
      } else {
        switch (test2_SysIntegration_DW.bitsForTID0.is_OpStart) {
         case test2_Sys_IN_AirExpelCtrlNormal:
          break;

         default:
          if (test2_SysIntegration_DW.bitsForTID0.boolFDBK) {
            test2_SysIntegration_DW.bitsForTID0.is_OpStart =
              test2_Sys_IN_AirExpelCtrlNormal;
            test2_SysIntegration_B.bitsForTID0.boolTrimEnable = true;
          } else {
            if (test2_SysIntegration_DW.prevFDBKMsgId != UnitDelay_k->Head.MsgId)
            {
              sf_internal_predicateOutput = false;
              b_p = true;
              if (!(UnitDelay_k->Head.OpCode == 4)) {
                b_p = false;
              }

              if (b_p) {
                sf_internal_predicateOutput = true;
              }

              if (sf_internal_predicateOutput) {
                test2_SysIntegration_DW.prevFDBKMsgId = UnitDelay_k->Head.MsgId;
                test2_SysIntegration_DW.bitsForTID0.boolFDBK = true;
              }
            }
          }
          break;
        }
      }
    }
    break;

   default:
    if ((test2_SysIntegration_DW.bitsForTID0.is_OpStop ==
         test2_Sys_IN_AirExpelCtrlNormal) && (*sfEvent_h ==
         test2_Sy_event_StartAirExpelEvt)) {
      test2_SysIntegration_DW.AirExpelEnaEvtEventCounter++;
      test2_SysIntegration_DW.bitsForTID0.is_OpStop = 0;
      test2_SysIntegration_DW.bitsForTID0.is_c17_test2_SysIntegration =
        test2_SysIntegration_IN_OpStart;
      test2_SysIntegration_DW.temporalCounter_i1_ig = 0U;
      test2_SysIntegration_DW.bitsForTID0.is_OpStart =
        test2_SysIntegr_IN_Wait4FdbkMsg;
      test2_SysIntegration_DW.bitsForTID0.boolFDBK = false;
      test2_SysIntegration_DW.prevFDBKMsgId = UnitDelay_k->Head.MsgId;
    } else {
      sf_internal_predicateOutput =
        ((test2_SysIntegration_DW.temporalCounter_i1_ig >= 10) &&
         (!test2_SysIntegration_DW.bitsForTID0.boolFDBK));
      if (sf_internal_predicateOutput) {
        test2_SysIntegration_DW.bitsForTID0.is_OpStop = 0;
        test2_SysIntegration_DW.bitsForTID0.is_c17_test2_SysIntegration =
          test2_SysIntegra_IN_AirExpelErr;
        tmp = (int32_T)(test2_SysIntegration_B.ErrDiagMsg.Head.MsgId + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        test2_SysIntegration_B.ErrDiagMsg.Head.MsgId = (uint8_T)((uint8_T)tmp %
          MAX_uint8_T);
        test2_SysIntegration_B.ErrDiagMsg.Head.OpCode = 1U;
        test2_SysIntegration_B.ErrDiagMsg.Body.Data = 13U;
      } else {
        switch (test2_SysIntegration_DW.bitsForTID0.is_OpStop) {
         case test2_Sys_IN_AirExpelCtrlNormal:
          break;

         default:
          if (test2_SysIntegration_DW.bitsForTID0.boolFDBK) {
            test2_SysIntegration_DW.bitsForTID0.is_OpStop =
              test2_Sys_IN_AirExpelCtrlNormal;
          } else {
            if (test2_SysIntegration_DW.prevFDBKMsgId != UnitDelay_k->Head.MsgId)
            {
              sf_internal_predicateOutput = false;
              b_p = true;
              if (!(UnitDelay_k->Head.OpCode == 255)) {
                b_p = false;
              }

              if (b_p) {
                sf_internal_predicateOutput = true;
              }

              if (sf_internal_predicateOutput) {
                test2_SysIntegration_DW.prevFDBKMsgId = UnitDelay_k->Head.MsgId;
                test2_SysIntegration_DW.bitsForTID0.boolFDBK = true;
              }
            }
          }
          break;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S1>/Chart' */
static void test2_SysIntegration_ADCRead(boolean_T x_Switch, int16_T *ADC_Ch1,
  int16_T *ADC_Ch2, int16_T *ADC_Ch3, int16_T *ADC_Ch4)
{
  *ADC_Ch1 = 0;
  *ADC_Ch2 = 0;
  *ADC_Ch3 = 0;
  *ADC_Ch4 = 0;
  channelsADC(x_Switch, ADC_Ch1, ADC_Ch2, ADC_Ch3, ADC_Ch4);
}

/* Function for Chart: '<S5>/Chart' */
static void test2_SysIntegration_GetKeyData(boolean_T y_DataOut[8])
{
  getKeyVector(y_DataOut);
}

/* Function for Chart: '<S52>/PCAMsgSend' */
static void test2_SysIn_LargeDoseDataConfig(uint16_T x_PCASaturatedDose,
  uint16_T x_PCAStandardDose, uint8_T x_rtInfoTimeDay, uint8_T
  y_LargeDose48Bytes[48])
{
  int32_T i;
  for (i = 0; i < 48; i++) {
    y_LargeDose48Bytes[i] = 0U;
  }

  y_LargeDose48Bytes[0] = (uint8_T)(x_PCASaturatedDose & 255);
  y_LargeDose48Bytes[4] = (uint8_T)(x_PCAStandardDose & 255);
  y_LargeDose48Bytes[1] = (uint8_T)((uint32_T)(x_PCASaturatedDose & 65280) >> 8);
  y_LargeDose48Bytes[5] = (uint8_T)((uint32_T)(x_PCAStandardDose & 65280) >> 8);
  y_LargeDose48Bytes[6] = x_rtInfoTimeDay;
}

/* Function for Chart: '<S52>/PCAMsgSend' */
static void test2_SysIntegra_PCADoseMonitor(const int32_T *sfEvent_b)
{
  boolean_T sf_internal_predicateOutput;
  int32_T tmp;
  uint32_T qY;
  qY = test2_SysIntegration_DW.Day_mSecond + /*MW:OvSatOk*/ 500U;
  if (qY < test2_SysIntegration_DW.Day_mSecond) {
    qY = MAX_uint32_T;
  }

  test2_SysIntegration_DW.Day_mSecond = qY;
  qY = test2_SysIntegration_DW.Op_mSecond + /*MW:OvSatOk*/ 500U;
  if (qY < test2_SysIntegration_DW.Op_mSecond) {
    qY = MAX_uint32_T;
  }

  test2_SysIntegration_DW.Op_mSecond =
    (test2_SysIntegration_DW.bitsForTID6.is_PCADoseMonitor ==
     test2_SysIntegration_IN_Op_h) * qY;
  if (test2_SysIntegration_DW.prevRTCompMsgId !=
      test2_SysIntegration_B.UnitDelay_f.Head.MsgId) {
    test2_SysIntegration_DW.prevRTCompMsgId =
      test2_SysIntegration_B.UnitDelay_f.Head.MsgId;
    qY = test2_SysIntegration_DW.Day_mSecond + /*MW:OvSatOk*/
      test2_SysIntegration_B.UnitDelay_f.Body.Data;
    if (qY < test2_SysIntegration_DW.Day_mSecond) {
      qY = MAX_uint32_T;
    }

    test2_SysIntegration_DW.Day_mSecond = qY;
    qY = test2_SysIntegration_DW.Op_mSecond + /*MW:OvSatOk*/
      test2_SysIntegration_B.UnitDelay_f.Body.Data;
    if (qY < test2_SysIntegration_DW.Op_mSecond) {
      qY = MAX_uint32_T;
    }

    test2_SysIntegration_DW.Op_mSecond =
      (test2_SysIntegration_DW.bitsForTID6.is_PCADoseMonitor ==
       test2_SysIntegration_IN_Op_h) * qY;
  }

  if (test2_SysIntegration_DW.Day_mSecond > 86400000U) {
    test2_SysIntegration_DW.bitsForTID6.boolPCASatHit = false;
    test2_SysIntegration_DW.PCAACCDose = 0U;
    test2_SysIntegration_DW.Day_mSecond = 0U;
    test2_SysIntegration_DW.bitsForTID6.is_PCADoseMonitor = 0;
    if (test2_SysIntegration_DW.bitsForTID6.is_PCADoseMonitor !=
        test2_SysIntegration_IN_Idle_k) {
      test2_SysIntegration_DW.bitsForTID6.is_PCADoseMonitor =
        test2_SysIntegration_IN_Idle_k;
      qY = (uint32_T)test2_SysIntegration_B.UnitDelay1_l - /*MW:OvSatOk*/
        test2_SysIntegration_DW.PCAACCDose;
      if (qY > test2_SysIntegration_B.UnitDelay1_l) {
        qY = 0U;
      }

      if ((uint16_T)qY < test2_SysIntegration_B.UnitDelay_h) {
        test2_SysIntegration_DW.PCASaturatedDose = (uint16_T)qY;
      } else {
        test2_SysIntegration_DW.PCASaturatedDose =
          test2_SysIntegration_B.UnitDelay_h;
      }
    }
  } else {
    switch (test2_SysIntegration_DW.bitsForTID6.is_PCADoseMonitor) {
     case test2_SysIntegration_IN_Idle_k:
      sf_internal_predicateOutput = ((*sfEvent_b ==
        test2_SysIntegrati_event_PCAEvt) &&
        (!test2_SysIntegration_DW.bitsForTID6.boolPCASatHit));
      if (sf_internal_predicateOutput) {
        test2_SysIntegration_DW.bitsForTID6.is_PCADoseMonitor =
          test2_SysIntegration_IN_Op_h;
        qY = (uint32_T)test2_SysIntegration_B.UnitDelay1_l - /*MW:OvSatOk*/
          test2_SysIntegration_DW.PCAACCDose;
        if (qY > test2_SysIntegration_B.UnitDelay1_l) {
          qY = 0U;
        }

        if ((int32_T)qY <= test2_SysIntegration_B.UnitDelay_h) {
          test2_SysIntegration_DW.bitsForTID6.boolPCASatHit = true;
          tmp = (int32_T)(test2_SysIntegration_B.PCAAlarmMsg.Head.MsgId + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          test2_SysIntegration_B.PCAAlarmMsg.Head.MsgId = (uint8_T)((uint8_T)tmp
            % MAX_uint8_T);
          test2_SysIntegration_B.PCAAlarmMsg.Head.OpCode = 1U;
          test2_SysIntegration_B.PCAAlarmMsg.Body.Data = 230U;
        }

        qY = (uint32_T)test2_SysIntegration_DW.PCAACCDose +
          test2_SysIntegration_DW.PCASaturatedDose;
        if (qY > 65535U) {
          qY = 65535U;
        }

        test2_SysIntegration_DW.PCAACCDose = (uint16_T)qY;
        tmp = (int32_T)(test2_SysIntegration_B.PCADoseCtrlMsg.Head.MsgId + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        test2_SysIntegration_B.PCADoseCtrlMsg.Head.MsgId = (uint8_T)((uint8_T)
          tmp % MAX_uint8_T);
        test2_SysIntegration_B.PCADoseCtrlMsg.Head.OpCode = 1U;

        /* UnitDelay: '<S65>/Unit Delay' */
        test2_SysIn_LargeDoseDataConfig(test2_SysIntegration_DW.PCASaturatedDose,
          test2_SysIntegration_B.UnitDelay_h,
          test2_SysIntegration_DW.UnitDelay_DSTATE_j.Time[2],
          &test2_SysIntegration_B.PCADoseCtrlMsg.Body.Data[0]);
      }
      break;

     case test2_SysIntegration_IN_Op_h:
      if (test2_SysIntegration_DW.Op_mSecond > 3600000U) {
        test2_SysIntegration_DW.bitsForTID6.is_PCADoseMonitor =
          test2_SysIntegration_IN_Idle_k;
        qY = (uint32_T)test2_SysIntegration_B.UnitDelay1_l - /*MW:OvSatOk*/
          test2_SysIntegration_DW.PCAACCDose;
        if (qY > test2_SysIntegration_B.UnitDelay1_l) {
          qY = 0U;
        }

        if ((uint16_T)qY < test2_SysIntegration_B.UnitDelay_h) {
          test2_SysIntegration_DW.PCASaturatedDose = (uint16_T)qY;
        } else {
          test2_SysIntegration_DW.PCASaturatedDose =
            test2_SysIntegration_B.UnitDelay_h;
        }
      }
      break;
    }
  }
}

/* Function for Chart: '<S100>/Chart' */
static void test2_Sy_Trans32Uint32To132Byte(const uint32_T Uint32Array32Element
  [32], uint8_T y_132Byte[132])
{
  int32_T b_index;
  int32_T tmp;
  memset(&y_132Byte[0], 0, 132U * sizeof(uint8_T));
  for (b_index = 0; b_index < 32; b_index++) {
    tmp = ((1 + b_index) << 2) - 4;
    y_132Byte[tmp] = (uint8_T)(Uint32Array32Element[b_index] & 255U);
    y_132Byte[1 + tmp] = (uint8_T)((Uint32Array32Element[b_index] & 65280U) >>
      8U);
    y_132Byte[2 + tmp] = (uint8_T)((Uint32Array32Element[b_index] & 16711680U) >>
      16U);
    y_132Byte[3 + tmp] = (uint8_T)((Uint32Array32Element[b_index] & 4278190080U)
      >> 24U);
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for Chart: '<S100>/Chart' */
static void test2__enter_atomic_CalibraStop(void)
{
  type_MsgBody4FlashAccessMsg b;
  real_T y[32];
  int32_T k;
  test2_SysIntegration_DW.bitsForTID0.boolSendBleDataEnable = false;
  y[31] = 4.5051499783199063;
  y[0] = 1.0;
  for (k = 0; k < 30; k++) {
    y[k + 1] = (1.0 + (real_T)k) * 0.11306935413935182 + 1.0;
  }

  for (k = 0; k < 32; k++) {
    test2_SysIntegration_DW.Seq[k] = (int32_T)rt_roundd_snf(rt_powd_snf(10.0,
      y[k]));
    test2_SysIntegration_DW.temp_millSec[k] = 0U;
    test2_SysIntegration_DW.temp_mAmSecInteg[k] = 0U;
  }

  test2_SysIntegration_B.CalibraMsgOut_e.Head.MsgId = 0U;
  test2_SysIntegration_B.CalibraMsgOut_e.Head.OpCode = 0U;
  test2_SysIntegration_B.CalibraMsgOut_e.Body.Data = 0;
  test2_SysIntegration_B.CalibraResult2FlashDrv.Head.MsgId = 0U;
  test2_SysIntegration_B.CalibraResult2FlashDrv.Head.OpCode = 0U;
  b.MajorId = 0U;
  b.MinorId = 0U;
  memset(&b.Data[0], 0, 132U * sizeof(uint8_T));
  test2_SysIntegration_B.CalibraResult2FlashDrv.Body = b;
}

/* Function for Chart: '<S100>/Chart' */
static void chartstep_c26_test2_SysIntegrat(const int32_T *sfEvent_kx)
{
  boolean_T p;
  boolean_T b_p;
  uint8_T b[132];
  int32_T tmp;
  switch (test2_SysIntegration_DW.bitsForTID0.is_c26_test2_SysIntegration) {
   case test2_SysIntegr_IN_CalibraStart:
    if (!test2_SysIntegration_B.bitsForTID4.boolNormalDeliverySwitchOn) {
      test2_SysIntegration_B.bitsForTID0.boolCalibraEna = false;
      test2_SysIntegration_DW.bitsForTID0.is_c26_test2_SysIntegration =
        test2_SysIntegra_IN_CalibraStop;
      test2__enter_atomic_CalibraStop();
    } else if (test2_SysIntegration_DW.bitsForTID0.boolSendBleDataEnable) {
      test2_SysIntegration_DW.i = 0U;
      test2_SysIntegration_B.bitsForTID0.boolCalibraEna = false;
      test2_SysIntegration_DW.bitsForTID0.is_c26_test2_SysIntegration =
        test2_SysIntegra_IN_SendBleData;
      test2_SysIntegration_DW.temporalCounter_i1_l = 0U;
      tmp = (int32_T)(test2_SysIntegration_DW.i + 1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      test2_SysIntegration_DW.i = (uint8_T)tmp;
      tmp = (int32_T)(test2_SysIntegration_B.CalibraResult2FlashDrv.Head.MsgId +
                      1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      test2_SysIntegration_B.CalibraResult2FlashDrv.Head.MsgId = (uint8_T)
        ((uint8_T)tmp % MAX_uint8_T);
      test2_SysIntegration_B.CalibraResult2FlashDrv.Head.OpCode = 1U;
      test2_SysIntegration_B.CalibraResult2FlashDrv.Body.MajorId = 6U;
      switch (test2_SysIntegration_DW.i) {
       case 1:
        tmp = (int32_T)(1U + test2_SysIntegration_DW.CalibraIndex);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        test2_SysIntegration_B.CalibraResult2FlashDrv.Body.MinorId = (uint8_T)
          tmp;
        test2_Sy_Trans32Uint32To132Byte(test2_SysIntegration_DW.temp_millSec, b);
        memcpy(&test2_SysIntegration_B.CalibraResult2FlashDrv.Body.Data[0], &b[0],
               132U * sizeof(uint8_T));
        break;

       case 2:
        tmp = (int32_T)(3U + test2_SysIntegration_DW.CalibraIndex);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        test2_SysIntegration_B.CalibraResult2FlashDrv.Body.MinorId = (uint8_T)
          tmp;
        test2_Sy_Trans32Uint32To132Byte(test2_SysIntegration_DW.temp_mAmSecInteg,
          b);
        memcpy(&test2_SysIntegration_B.CalibraResult2FlashDrv.Body.Data[0], &b[0],
               132U * sizeof(uint8_T));
        break;
      }
    } else {
      if (test2_SysIntegration_DW.bitsForTID0.sendPermitted &&
          (test2_SysIntegration_DW.SeqIndex < test2_SysIntegration_SeqIter)) {
        test2_SysIntegration_DW.bitsForTID0.sendPermitted = false;
        tmp = (int32_T)(test2_SysIntegration_DW.SeqIndex + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        test2_SysIntegration_DW.SeqIndex = (uint8_T)tmp;
        tmp = (int32_T)(test2_SysIntegration_B.CalibraMsgOut_e.Head.MsgId + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        test2_SysIntegration_B.CalibraMsgOut_e.Head.MsgId = (uint8_T)((uint8_T)
          tmp % MAX_uint8_T);
        test2_SysIntegration_B.CalibraMsgOut_e.Body.Data =
          test2_SysIntegration_DW.Seq[test2_SysIntegration_DW.SeqIndex - 1];

        /* UnitDelay: '<S100>/Unit Delay' */
        test2_SysIntegration_DW.prevCalibraMsgId =
          test2_SysIntegration_DW.UnitDelay_DSTATE_b.Head.MsgId;
      } else {
        if (test2_SysIntegration_DW.bitsForTID0.sendPermitted) {
          p = false;
          b_p = true;
          if (!(test2_SysIntegration_DW.SeqIndex == test2_SysIntegration_SeqIter))
          {
            b_p = false;
          }

          if (b_p) {
            p = true;
          }

          if (p) {
            test2_SysIntegration_DW.bitsForTID0.boolSendBleDataEnable = true;
          }
        }
      }

      /* UnitDelay: '<S100>/Unit Delay' */
      if (test2_SysIntegration_DW.prevCalibraMsgId !=
          test2_SysIntegration_DW.UnitDelay_DSTATE_b.Head.MsgId) {
        test2_SysIntegration_DW.prevCalibraMsgId =
          test2_SysIntegration_DW.UnitDelay_DSTATE_b.Head.MsgId;
        test2_SysIntegration_DW.temp_millSec[test2_SysIntegration_DW.SeqIndex -
          1] = test2_SysIntegration_DW.UnitDelay_DSTATE_b.Body.millSec;
        test2_SysIntegration_DW.temp_mAmSecInteg[test2_SysIntegration_DW.SeqIndex
          - 1] = test2_SysIntegration_DW.UnitDelay_DSTATE_b.Body.mAmSecInteg;
        test2_SysIntegration_DW.bitsForTID0.sendPermitted = true;
      }
    }
    break;

   case test2_SysIntegra_IN_CalibraStop:
    if ((*sfEvent_kx == test2_Sys_event_CalibraStartEvt) &&
        test2_SysIntegration_B.bitsForTID4.boolNormalDeliverySwitchOn) {
      test2_SysIntegration_DW.bitsForTID0.sendPermitted = true;
      test2_SysIntegration_DW.bitsForTID0.is_c26_test2_SysIntegration =
        test2_SysIntegr_IN_CalibraStart;
      test2_SysIntegration_B.bitsForTID0.boolCalibraEna = true;
      test2_SysIntegration_B.CalibraMsgOut_e.Head.OpCode = 1U;
      test2_SysIntegration_DW.SeqIndex = 0U;
    }
    break;

   default:
    if (test2_SysIntegration_DW.i == 2) {
      tmp = (int32_T)(test2_SysIntegration_DW.CalibraIndex + 1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      test2_SysIntegration_DW.CalibraIndex = (uint8_T)((uint8_T)tmp % 3);
      test2_SysIntegration_DW.bitsForTID0.is_c26_test2_SysIntegration =
        test2_SysIntegra_IN_CalibraStop;
      test2__enter_atomic_CalibraStop();
    } else {
      if (test2_SysIntegration_DW.temporalCounter_i1_l >= 6) {
        test2_SysIntegration_DW.bitsForTID0.is_c26_test2_SysIntegration =
          test2_SysIntegra_IN_SendBleData;
        test2_SysIntegration_DW.temporalCounter_i1_l = 0U;
        tmp = (int32_T)(test2_SysIntegration_DW.i + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        test2_SysIntegration_DW.i = (uint8_T)tmp;
        tmp = (int32_T)(test2_SysIntegration_B.CalibraResult2FlashDrv.Head.MsgId
                        + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        test2_SysIntegration_B.CalibraResult2FlashDrv.Head.MsgId = (uint8_T)
          ((uint8_T)tmp % MAX_uint8_T);
        test2_SysIntegration_B.CalibraResult2FlashDrv.Head.OpCode = 1U;
        test2_SysIntegration_B.CalibraResult2FlashDrv.Body.MajorId = 6U;
        switch (test2_SysIntegration_DW.i) {
         case 1:
          tmp = (int32_T)(1U + test2_SysIntegration_DW.CalibraIndex);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          test2_SysIntegration_B.CalibraResult2FlashDrv.Body.MinorId = (uint8_T)
            tmp;
          test2_Sy_Trans32Uint32To132Byte(test2_SysIntegration_DW.temp_millSec,
            b);
          memcpy(&test2_SysIntegration_B.CalibraResult2FlashDrv.Body.Data[0],
                 &b[0], 132U * sizeof(uint8_T));
          break;

         case 2:
          tmp = (int32_T)(3U + test2_SysIntegration_DW.CalibraIndex);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          test2_SysIntegration_B.CalibraResult2FlashDrv.Body.MinorId = (uint8_T)
            tmp;
          test2_Sy_Trans32Uint32To132Byte
            (test2_SysIntegration_DW.temp_mAmSecInteg, b);
          memcpy(&test2_SysIntegration_B.CalibraResult2FlashDrv.Body.Data[0],
                 &b[0], 132U * sizeof(uint8_T));
          break;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S63>/Chart' */
static void SynLogDataFromSysVarIn20BytesFo(const type_SysVars *x2_VarSet,
  uint8_T x2_LogMajorId, uint8_T x2_LogMinorId, uint8_T
  LogDataFromSysVarIn20BytesForm[20])
{
  int32_T i;
  uint8_T tmp[4];
  for (i = 0; i < 20; i++) {
    LogDataFromSysVarIn20BytesForm[i] = 0U;
  }

  if ((x2_LogMajorId == 1) && ((x2_LogMinorId == 1) || (x2_LogMinorId == 2))) {
    LogDataFromSysVarIn20BytesForm[0] = (uint8_T)
      (x2_VarSet->ActCtrl.LargeDoseDynVar.TargetDose & 255U);
    LogDataFromSysVarIn20BytesForm[4] = (uint8_T)
      (x2_VarSet->ActCtrl.LargeDoseDynVar.TimeInfo & 255);
    LogDataFromSysVarIn20BytesForm[8] = (uint8_T)
      (x2_VarSet->ActCtrl.LargeDoseDynVar.CompleteDose & 255U);
    LogDataFromSysVarIn20BytesForm[1] = (uint8_T)
      ((x2_VarSet->ActCtrl.LargeDoseDynVar.TargetDose & 65280U) >> 8U);
    LogDataFromSysVarIn20BytesForm[5] = (uint8_T)((uint32_T)
      (x2_VarSet->ActCtrl.LargeDoseDynVar.TimeInfo & 65280) >> 8);
    LogDataFromSysVarIn20BytesForm[9] = (uint8_T)
      ((x2_VarSet->ActCtrl.LargeDoseDynVar.CompleteDose & 65280U) >> 8U);
    LogDataFromSysVarIn20BytesForm[2] = 0U;
    LogDataFromSysVarIn20BytesForm[6] = 0U;
    LogDataFromSysVarIn20BytesForm[10] = 0U;
    LogDataFromSysVarIn20BytesForm[3] = 0U;
    LogDataFromSysVarIn20BytesForm[7] = 0U;
    LogDataFromSysVarIn20BytesForm[11] = 0U;
  } else if ((x2_LogMajorId == 1) && ((x2_LogMinorId == 3) || (x2_LogMinorId ==
               4))) {
    LogDataFromSysVarIn20BytesForm[0] = (uint8_T)
      (x2_VarSet->ActCtrl.BaseRateDynVar.TargetDose & 255U);
    LogDataFromSysVarIn20BytesForm[4] = (uint8_T)
      (x2_VarSet->ActCtrl.BaseRateDynVar.TimeInfo & 255);
    LogDataFromSysVarIn20BytesForm[8] = (uint8_T)
      (x2_VarSet->ActCtrl.BaseRateDynVar.CompleteDose & 255U);
    LogDataFromSysVarIn20BytesForm[1] = (uint8_T)
      ((x2_VarSet->ActCtrl.BaseRateDynVar.TargetDose & 65280U) >> 8U);
    LogDataFromSysVarIn20BytesForm[5] = (uint8_T)((uint32_T)
      (x2_VarSet->ActCtrl.BaseRateDynVar.TimeInfo & 65280) >> 8);
    LogDataFromSysVarIn20BytesForm[9] = (uint8_T)
      ((x2_VarSet->ActCtrl.BaseRateDynVar.CompleteDose & 65280U) >> 8U);
    LogDataFromSysVarIn20BytesForm[2] = 0U;
    LogDataFromSysVarIn20BytesForm[6] = 0U;
    LogDataFromSysVarIn20BytesForm[10] = 0U;
    LogDataFromSysVarIn20BytesForm[3] = 0U;
    LogDataFromSysVarIn20BytesForm[7] = 0U;
    LogDataFromSysVarIn20BytesForm[11] = 0U;
  } else if ((x2_LogMajorId == 1) && (x2_LogMinorId == 5)) {
    test2_SysI_TransDWord2FourBytes
      (x2_VarSet->ActCtrl.DailyDoseStatVar.TotalAmountAcc, tmp);
    LogDataFromSysVarIn20BytesForm[0] =
      x2_VarSet->ActCtrl.DailyDoseStatVar.DayInfo;
    LogDataFromSysVarIn20BytesForm[4] = tmp[0];
    LogDataFromSysVarIn20BytesForm[1] = 0U;
    LogDataFromSysVarIn20BytesForm[5] = tmp[1];
    LogDataFromSysVarIn20BytesForm[2] = 0U;
    LogDataFromSysVarIn20BytesForm[6] = tmp[2];
    LogDataFromSysVarIn20BytesForm[3] = 0U;
    LogDataFromSysVarIn20BytesForm[7] = tmp[3];
  } else if ((x2_LogMajorId == 3) && (x2_LogMinorId == 2)) {
    LogDataFromSysVarIn20BytesForm[0] = x2_VarSet->ActCtrl.DeliverSwitch;
    LogDataFromSysVarIn20BytesForm[1] = 0U;
    LogDataFromSysVarIn20BytesForm[2] = 0U;
    LogDataFromSysVarIn20BytesForm[3] = 0U;
  } else if ((x2_LogMajorId == 3) && (x2_LogMinorId == 3)) {
    LogDataFromSysVarIn20BytesForm[0] =
      x2_VarSet->DoseCtrl.DoseCtrlParam.Concentration;
    LogDataFromSysVarIn20BytesForm[4] =
      x2_VarSet->DoseCtrl.DoseCtrlParam.LowDoseTHValue;
    LogDataFromSysVarIn20BytesForm[8] = (uint8_T)
      (x2_VarSet->DoseCtrl.DoseCtrlParam.MaxLargeDose & 255);
    LogDataFromSysVarIn20BytesForm[12] = (uint8_T)
      (x2_VarSet->DoseCtrl.DoseCtrlParam.MaxBaseRate & 255);
    LogDataFromSysVarIn20BytesForm[16] =
      x2_VarSet->DoseCtrl.DoseCtrlParam.MaxDailyDose;
    LogDataFromSysVarIn20BytesForm[1] = 0U;
    LogDataFromSysVarIn20BytesForm[5] = 0U;
    LogDataFromSysVarIn20BytesForm[9] = (uint8_T)((uint32_T)
      (x2_VarSet->DoseCtrl.DoseCtrlParam.MaxLargeDose & 65280) >> 8);
    LogDataFromSysVarIn20BytesForm[13] = (uint8_T)((uint32_T)
      (x2_VarSet->DoseCtrl.DoseCtrlParam.MaxBaseRate & 65280) >> 8);
    LogDataFromSysVarIn20BytesForm[17] = 0U;
    LogDataFromSysVarIn20BytesForm[2] = 0U;
    LogDataFromSysVarIn20BytesForm[6] = 0U;
    LogDataFromSysVarIn20BytesForm[10] = 0U;
    LogDataFromSysVarIn20BytesForm[14] = 0U;
    LogDataFromSysVarIn20BytesForm[18] = 0U;
    LogDataFromSysVarIn20BytesForm[3] = 0U;
    LogDataFromSysVarIn20BytesForm[7] = 0U;
    LogDataFromSysVarIn20BytesForm[11] = 0U;
    LogDataFromSysVarIn20BytesForm[15] = 0U;
    LogDataFromSysVarIn20BytesForm[19] = 0U;
  } else {
    if ((x2_LogMajorId == 3) && (x2_LogMinorId == 4)) {
      LogDataFromSysVarIn20BytesForm[0] = x2_VarSet->ActCtrl.IniLoadedVol;
      LogDataFromSysVarIn20BytesForm[1] = 0U;
      LogDataFromSysVarIn20BytesForm[2] = 0U;
      LogDataFromSysVarIn20BytesForm[3] = 0U;
    }
  }
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysIntegration_LogWrite(type_RT x_RTInfo, uint8_T x_LogMajorId,
  uint8_T x_LogMinorId, uint8_T x_Channel, uint8_T x_ParamExt, boolean_T
  *y_FlashAccessErr, uint8_T *y_Channel)
{
  uint8_T x_LogData[60];
  uint8_T temp_data[20];
  int32_T i;
  *y_FlashAccessErr = false;
  *y_Channel = x_Channel;
  for (i = 0; i < 60; i++) {
    x_LogData[i] = MAX_uint8_T;
  }

  switch (x_LogMajorId) {
   case 4:
    if ((x_LogMinorId <= 3) && (x_LogMinorId > 0)) {
      for (i = 0; i < 12; i++) {
        x_LogData[i] = test2_SysIntegration_B.VarSet.DoseCtrl.BaseRateConfig[i];
      }

      for (i = 0; i < 20; i++) {
        temp_data[i] = x_LogData[i];
      }

      recordWrite(&x_RTInfo, x_LogMajorId, 1, temp_data, x_Channel);
      for (i = 0; i < 16; i++) {
        x_LogData[20 + i] =
          test2_SysIntegration_B.VarSet.DoseCtrl.BaseRateConfig[12 + i];
      }

      for (i = 0; i < 20; i++) {
        temp_data[i] = x_LogData[20 + i];
      }

      recordWrite(&x_RTInfo, x_LogMajorId, 2, temp_data, x_Channel);
      for (i = 0; i < 20; i++) {
        temp_data[i] = test2_SysIntegration_B.VarSet.DoseCtrl.BaseRateConfig[28
          + i];
      }

      *y_FlashAccessErr = recordWrite(&x_RTInfo, x_LogMajorId, 3, temp_data,
        x_Channel);
    } else {
      if (x_LogMinorId <= 6) {
        for (i = 0; i < 12; i++) {
          x_LogData[i] =
            test2_SysIntegration_B.VarSet.DoseCtrl.TempBaseRateConfig[i];
        }

        for (i = 0; i < 20; i++) {
          temp_data[i] = x_LogData[i];
        }

        recordWrite(&x_RTInfo, x_LogMajorId, 4, temp_data, x_Channel);
        for (i = 0; i < 16; i++) {
          x_LogData[20 + i] =
            test2_SysIntegration_B.VarSet.DoseCtrl.TempBaseRateConfig[12 + i];
        }

        for (i = 0; i < 20; i++) {
          temp_data[i] = x_LogData[20 + i];
        }

        recordWrite(&x_RTInfo, x_LogMajorId, 5, temp_data, x_Channel);
        for (i = 0; i < 20; i++) {
          temp_data[i] =
            test2_SysIntegration_B.VarSet.DoseCtrl.TempBaseRateConfig[28 + i];
        }

        *y_FlashAccessErr = recordWrite(&x_RTInfo, x_LogMajorId, 6, temp_data,
          x_Channel);
      }
    }
    break;

   case 2:
    if (x_LogMinorId == 1) {
      x_LogData[0] = x_ParamExt;
      for (i = 0; i < 20; i++) {
        temp_data[i] = x_LogData[i];
      }

      *y_FlashAccessErr = recordWrite(&x_RTInfo, x_LogMajorId, 1, temp_data,
        x_Channel);
    }
    break;

   case 3:
    if (x_LogMinorId == 5) {
      x_LogData[0] = x_ParamExt;
      for (i = 0; i < 20; i++) {
        temp_data[i] = x_LogData[i];
      }

      *y_FlashAccessErr = recordWrite(&x_RTInfo, x_LogMajorId, 5, temp_data,
        x_Channel);
    } else {
      SynLogDataFromSysVarIn20BytesFo(&test2_SysIntegration_B.VarSet,
        x_LogMajorId, x_LogMinorId, &x_LogData[0]);
      for (i = 0; i < 20; i++) {
        temp_data[i] = x_LogData[i];
      }

      *y_FlashAccessErr = recordWrite(&x_RTInfo, x_LogMajorId, x_LogMinorId,
        temp_data, x_Channel);
    }
    break;

   case 1:
    SynLogDataFromSysVarIn20BytesFo(&test2_SysIntegration_B.VarSet, x_LogMajorId,
      x_LogMinorId, &x_LogData[0]);
    for (i = 0; i < 20; i++) {
      temp_data[i] = x_LogData[i];
    }

    *y_FlashAccessErr = recordWrite(&x_RTInfo, x_LogMajorId, x_LogMinorId,
      temp_data, x_Channel);
    break;
  }
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysInt_DeliverySwitchCtrl(uint8_T x_LogWriteMajorId, uint8_T
  x_LogWriteMinorId, uint8_T x_OpCode, uint8_T x_ParamExt, uint8_T *y_MajorId,
  uint8_T *y_MinorId, uint8_T y_Data[132])
{
  boolean_T p;
  boolean_T b_p;
  int32_T i;
  uint32_T qY;
  *y_MajorId = 0U;
  *y_MinorId = 0U;
  memset(&y_Data[0], 0, 132U * sizeof(uint8_T));
  p = false;
  b_p = true;
  if (!(x_LogWriteMajorId == 2)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (p) {
    p = false;
    b_p = true;
    if (!(x_LogWriteMinorId == 1)) {
      b_p = false;
    }

    if (b_p) {
      p = true;
    }

    if (p && (x_ParamExt > 0) && (x_ParamExt < 100)) {
      *y_MajorId = 2U;
      *y_MinorId = 3U;
      qY = 1U - /*MW:OvSatOk*/ x_OpCode;
      if (qY > 1U) {
        qY = 0U;
      }

      for (i = 0; i < 132; i++) {
        y_Data[i] = (uint8_T)qY;
      }
    }
  }
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysIntegration_OneLogRead(uint8_T x_MajorId, const uint16_T
  x_LogIdVector[4], uint8_T x_Channel, uint8_T *y_LogAvailableFlag, uint8_T
  y_LogData[44])
{
  int32_T i;
  uint16_T x_LogIdVector_0[4];
  for (i = 0; i < 44; i++) {
    y_LogData[i] = 0U;
  }

  x_LogIdVector_0[0] = x_LogIdVector[0];
  x_LogIdVector_0[1] = x_LogIdVector[1];
  x_LogIdVector_0[2] = x_LogIdVector[2];
  x_LogIdVector_0[3] = x_LogIdVector[3];
  *y_LogAvailableFlag = recordRead(x_MajorId, x_LogIdVector_0, x_Channel,
    y_LogData);
}

/* Function for Chart: '<S63>/Chart' */
static void Wait4FirstBag_LogUpLoadRequest(void)
{
  boolean_T FlashAccessErr;
  boolean_T b_p;
  uint8_T LogAvailableFlag;
  uint8_T LogData[44];
  uint32_T qY;
  int32_T qY_tmp;
  boolean_T guard1 = false;
  if (test2_SysIntegration_DW.bitsForTID4.LogUpLoadEnable) {
    test2_SysIntegration_DW.bitsForTID4.LogUpLoadEnable = false;
    test2_SysIntegration_DW.LogId = 0U;
    test2_SysIntegration_DW.bitsForTID4.boolLogReadTerminate = false;
    test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen =
      test2_SysInt_IN_LogExportCtrlOp;
    test2_SysIntegration_DW.temporalCounter_i1_n = 0U;
    test2_SysIntegration_DW.bitsForTID4.boolLogSend = true;
  } else if (test2_SysIntegration_DW.FirmwareParam.boolGetHead) {
    test2_SysIntegration_DW.FirmwareParam.boolTransIng = true;
    test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen =
      test2_SysInteg_IN_GetOneDataBag;
    test2_SysIntegration_DW.temporalCounter_i1_n = 0U;
  } else if (test2_SysIntegration_DW.bitsForTID4.LogUpdateEnable) {
    test2_SysIntegration_DW.bitsForTID4.LogUpdateEnable = false;
    test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen =
      test2_SysInt_IN_UpdateScreenLog;
    switch (test2_SysIntegration_DW.LogOpCode) {
     case 3:
      qY_tmp = test2_SysIntegration_DW.LogWriteMajorId - 1;
      qY = test2_SysIntegration_DW.TypexLogId[qY_tmp] - /*MW:OvSatOk*/ 1U;
      if (qY >
          test2_SysIntegration_DW.TypexLogId[test2_SysIntegration_DW.LogWriteMajorId
          - 1]) {
        qY = 0U;
      }

      test2_SysIntegration_DW.TypexLogId[qY_tmp] = (uint16_T)qY;
      break;

     case 4:
      qY =
        test2_SysIntegration_DW.TypexLogId[test2_SysIntegration_DW.LogWriteMajorId
        - 1] + 1U;
      if (qY > 65535U) {
        qY = 65535U;
      }

      test2_SysIntegration_DW.TypexLogId[test2_SysIntegration_DW.LogWriteMajorId
        - 1] = (uint16_T)qY;
      break;
    }

    test2_SysIntegration_OneLogRead(test2_SysIntegration_DW.LogWriteMajorId,
      test2_SysIntegration_DW.TypexLogId, test2_SysIntegration_DW.Channel,
      &LogAvailableFlag, LogData);
    switch (LogAvailableFlag) {
     case 0:
      test2_SysIntegration_DW.bitsForTID4.boolLogReadTerminate = true;
      qY_tmp = (int32_T)(test2_SysIntegration_B.SysDiagMsgOut_d.Head.MsgId + 1U);
      if ((uint32_T)qY_tmp > 255U) {
        qY_tmp = 255;
      }

      test2_SysIntegration_B.SysDiagMsgOut_d.Head.MsgId = (uint8_T)((uint8_T)
        qY_tmp % MAX_uint8_T);
      test2_SysIntegration_B.SysDiagMsgOut_d.Head.OpCode = 1U;
      test2_SysIntegration_B.SysDiagMsgOut_d.Body.Data = 209U;
      break;

     case 1:
      qY_tmp = (int32_T)(test2_SysIntegration_B.LogDataMsg.Head.MsgId + 1U);
      if ((uint32_T)qY_tmp > 255U) {
        qY_tmp = 255;
      }

      test2_SysIntegration_B.LogDataMsg.Head.MsgId = (uint8_T)((uint8_T)qY_tmp %
        MAX_uint8_T);
      test2_SysIntegration_B.LogDataMsg.Head.OpCode = 3U;
      test2_SysIntegration_B.LogDataMsg.Body.MajorId = 0U;
      test2_SysIntegration_B.LogDataMsg.Body.MinorId = 0U;
      for (qY_tmp = 0; qY_tmp < 44; qY_tmp++) {
        test2_SysIntegration_B.LogDataMsg.Body.Data[qY_tmp] = LogData[qY_tmp];
      }

      test2_SysIntegration_DW.bitsForTID4.boolLogReadTerminate = true;
      break;

     case MAX_uint8_T:
      test2_SysIntegration_DW.bitsForTID4.FlashAccessErr = true;
      break;
    }
  } else {
    if (test2_SysIntegration_DW.sfEvent_gn == test2_SysIntegra_event_LogOpEvt) {
      guard1 = false;
      switch (test2_SysIntegration_DW.LogOpCode) {
       case 1:
        /* UnitDelay: '<S65>/Unit Delay' */
        test2_SysIntegration_LogWrite(test2_SysIntegration_DW.UnitDelay_DSTATE_j,
          test2_SysIntegration_DW.LogWriteMajorId,
          test2_SysIntegration_DW.LogWriteMinorId,
          test2_SysIntegration_DW.Channel, test2_SysIntegration_DW.ParamExt,
          &FlashAccessErr, &LogAvailableFlag);
        test2_SysIntegration_DW.Channel = LogAvailableFlag;
        test2_SysIntegration_DW.bitsForTID4.FlashAccessErr = FlashAccessErr;
        FlashAccessErr = false;
        b_p = true;
        if (!(test2_SysIntegration_DW.LogWriteMajorId == 1)) {
          b_p = false;
        }

        if (b_p) {
          FlashAccessErr = true;
        }

        if (FlashAccessErr) {
          FlashAccessErr = false;
          b_p = true;
          if (!(test2_SysIntegration_DW.LogWriteMinorId == 5)) {
            b_p = false;
          }

          if (b_p) {
            FlashAccessErr = true;
          }

          if (FlashAccessErr) {
            /* UnitDelay: '<S65>/Unit Delay' */
            test2_SysIntegration_B.VarSet.ActCtrl.DailyDoseStatVar.DayInfo =
              test2_SysIntegration_DW.UnitDelay_DSTATE_j.Time[3];
            test2_SysIntegration_B.VarSet.ActCtrl.DailyDoseStatVar.TotalAmountAcc
              = 0U;
            test2_SysIntegration_B.VarSet.ActCtrl.DailyDoseStatVar.LargeAmountAcc
              = 0U;
            test2_SysIntegration_B.VarSet.ActCtrl.DailyDoseStatVar.DailyAmountAcc
              = 0U;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }
        break;

       case 2:
        test2_SysIntegration_DW.bitsForTID4.LogUpLoadEnable = true;
        test2_SysIntegration_DW.LogIdThVal = 1002U;
        break;

       case 3:
        test2_SysIntegration_DW.bitsForTID4.LogUpdateEnable = true;
        break;

       case 4:
        test2_SysIntegration_DW.bitsForTID4.LogUpdateEnable = true;
        break;
      }

      if (guard1) {
        FlashAccessErr = false;
        b_p = true;
        if (!(test2_SysIntegration_DW.LogWriteMajorId == 2)) {
          b_p = false;
        }

        if (b_p) {
          FlashAccessErr = true;
        }

        if (FlashAccessErr) {
          FlashAccessErr = false;
          b_p = true;
          if (!(test2_SysIntegration_DW.LogWriteMinorId == 1)) {
            b_p = false;
          }

          if (b_p) {
            FlashAccessErr = true;
          }

          if (FlashAccessErr) {
            test2_SysInt_DeliverySwitchCtrl
              (test2_SysIntegration_DW.LogWriteMajorId,
               test2_SysIntegration_DW.LogWriteMinorId,
               test2_SysIntegration_DW.OpCode, test2_SysIntegration_DW.ParamExt,
               &test2_SysIntegration_DW.MajorId,
               &test2_SysIntegration_DW.MinorId, test2_SysIntegration_DW.Data);
            test2_SysIntegration_DW.bitsForTID4.FlashAccessEnable = true;
          }
        }
      }
    }
  }
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysInte_Var0104DataReform(uint8_T x_MinorId, uint8_T
  y_0104Data[3])
{
  uint16_T temp_year;
  uint8_T temp_month;
  uint8_T temp_day;
  uint8_T b_temp_month;
  uint8_T i;
  boolean_T y_boolLeap;
  static const int8_T b[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  static const int8_T c[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  uint32_T qY;
  uint32_T tmp;
  int8_T y_boolLeap_0;
  int32_T tmp_0;
  qY = x_MinorId - /*MW:OvSatOk*/ 10U;
  if (qY > x_MinorId) {
    qY = 0U;
  }

  /* UnitDelay: '<S65>/Unit Delay' */
  temp_year = (uint16_T)(test2_SysIntegration_DW.UnitDelay_DSTATE_j.Time[0] +
    2000);
  temp_month = test2_SysIntegration_DW.UnitDelay_DSTATE_j.Time[1];
  temp_day = test2_SysIntegration_DW.UnitDelay_DSTATE_j.Time[2];
  if ((uint8_T)qY > 0) {
    for (i = 1U; i <= (uint8_T)qY; i++) {
      tmp_0 = (uint16_T)(temp_year % 100);
      if ((tmp_0 != 0) && ((uint16_T)(temp_year % 4) == 0)) {
        y_boolLeap = true;
      } else {
        y_boolLeap = ((tmp_0 == 0) && ((uint16_T)(temp_year % 400) == 0));
      }

      if (y_boolLeap) {
        y_boolLeap_0 = b[temp_month - 1];
      } else {
        y_boolLeap_0 = c[temp_month - 1];
      }

      if (temp_day == y_boolLeap_0) {
        temp_day = 1U;
        b_temp_month = (uint8_T)((uint8_T)(temp_month % 12) + 1);
        tmp = temp_month / 12U + temp_year;
        if (tmp > 65535U) {
          tmp = 65535U;
        }

        temp_year = (uint16_T)tmp;
      } else {
        tmp_0 = (int32_T)(temp_day + 1U);
        if ((uint32_T)tmp_0 > 255U) {
          tmp_0 = 255;
        }

        temp_day = (uint8_T)tmp_0;
        b_temp_month = temp_month;
      }

      temp_month = b_temp_month;
    }
  }

  qY = temp_year - /*MW:OvSatOk*/ 2000U;
  if (qY > temp_year) {
    qY = 0U;
  }

  temp_year = (uint16_T)qY;
  if ((uint16_T)qY > 255) {
    temp_year = 255U;
  }

  y_0104Data[0] = (uint8_T)temp_year;
  y_0104Data[1] = temp_month;
  y_0104Data[2] = temp_day;
}

/* Function for Chart: '<S63>/Chart' */
static uint16_T test2_SysI_TransTwoBytes2Uint16(const uint8_T x_twoBytes[2])
{
  return (uint16_T)((x_twoBytes[1] << 8) + x_twoBytes[0]);
}

/* Function for Chart: '<S63>/Chart' */
static uint16_T test2_Sy_TransTwoBytes2Uint16_p(const uint8_T x_twoBytes[3])
{
  return (uint16_T)((x_twoBytes[1] << 8) + x_twoBytes[0]);
}

/* Function for Chart: '<S63>/Chart' */
static uint32_T test2_SysInt_Trans4Bytes2Uint32(const uint8_T x_FourBytes[4])
{
  return ((((uint32_T)x_FourBytes[1] << 8U) + x_FourBytes[0]) + ((uint32_T)
           x_FourBytes[2] << 16U)) + ((uint32_T)x_FourBytes[3] << 24U);
}

/* Function for Chart: '<S63>/Chart' */
static void test2_Sy_Transfer32ByteTo8Int32(const uint8_T x_32Bytes[32], int32_T
  y_8int32[8])
{
  int32_T i;
  uint32_T y_Uint32;
  for (i = 0; i < 8; i++) {
    y_Uint32 = ((((uint32_T)x_32Bytes[(i << 2) + 1] << 8U) + x_32Bytes[i << 2])
                + ((uint32_T)x_32Bytes[(i << 2) + 2] << 16U)) + ((uint32_T)
      x_32Bytes[(i << 2) + 3] << 24U);
    if (y_Uint32 >= 2147483648U) {
      y_8int32[i] = (int32_T)((real_T)y_Uint32 - 4.294967296E+9);
    } else {
      y_8int32[i] = (int32_T)y_Uint32;
    }
  }
}

/* Function for Chart: '<S63>/Chart' */
static real_T test2_SysIntegration_hex2dec(const char_T s[8])
{
  real_T x;
  real_T p16;
  int32_T j;
  int32_T s_0;
  x = 0.0;
  p16 = 1.0;
  for (j = 0; j < 8; j++) {
    if (s[7 - j] != ' ') {
      s_0 = (uint8_T)s[7 - j];
      if ((s_0 != 0) && (s_0 != 48)) {
        if (!(s_0 <= 57)) {
          if (s_0 > 70) {
            s_0 -= 39;
          } else {
            s_0 -= 7;
          }
        }

        x += ((real_T)s_0 - 48.0) * p16;
      }

      p16 *= 16.0;
    }
  }

  return x;
}

/* Function for Chart: '<S63>/Chart' */
static uint32_T test2_SysIntegra_CalculateCRC32(uint32_T x_CRC32Val, const
  uint8_T x_OneBagData[132], uint8_T x_DataBagBytes)
{
  uint32_T y_CRC32Val;
  uint32_T temp_index;
  uint8_T i;
  cell_wrap_0_test2_SysIntegrat_T g_crc32_table[256];
  cell_wrap_0_test2_SysIntegrat_T b;
  cell_wrap_0_test2_SysIntegrat_T c;
  cell_wrap_0_test2_SysIntegrat_T d;
  cell_wrap_0_test2_SysIntegrat_T e;
  cell_wrap_0_test2_SysIntegrat_T f;
  cell_wrap_0_test2_SysIntegrat_T g;
  cell_wrap_0_test2_SysIntegrat_T h;
  cell_wrap_0_test2_SysIntegrat_T j;
  cell_wrap_0_test2_SysIntegrat_T k;
  cell_wrap_0_test2_SysIntegrat_T l;
  cell_wrap_0_test2_SysIntegrat_T m;
  cell_wrap_0_test2_SysIntegrat_T n;
  cell_wrap_0_test2_SysIntegrat_T o;
  cell_wrap_0_test2_SysIntegrat_T p;
  cell_wrap_0_test2_SysIntegrat_T q;
  cell_wrap_0_test2_SysIntegrat_T r;
  cell_wrap_0_test2_SysIntegrat_T s;
  cell_wrap_0_test2_SysIntegrat_T t;
  cell_wrap_0_test2_SysIntegrat_T u;
  cell_wrap_0_test2_SysIntegrat_T v;
  cell_wrap_0_test2_SysIntegrat_T w;
  cell_wrap_0_test2_SysIntegrat_T x;
  cell_wrap_0_test2_SysIntegrat_T y;
  cell_wrap_0_test2_SysIntegrat_T ab;
  cell_wrap_0_test2_SysIntegrat_T bb;
  cell_wrap_0_test2_SysIntegrat_T cb;
  cell_wrap_0_test2_SysIntegrat_T db;
  cell_wrap_0_test2_SysIntegrat_T eb;
  cell_wrap_0_test2_SysIntegrat_T fb;
  cell_wrap_0_test2_SysIntegrat_T gb;
  cell_wrap_0_test2_SysIntegrat_T hb;
  cell_wrap_0_test2_SysIntegrat_T ib;
  cell_wrap_0_test2_SysIntegrat_T jb;
  cell_wrap_0_test2_SysIntegrat_T kb;
  cell_wrap_0_test2_SysIntegrat_T lb;
  cell_wrap_0_test2_SysIntegrat_T mb;
  cell_wrap_0_test2_SysIntegrat_T nb;
  cell_wrap_0_test2_SysIntegrat_T ob;
  cell_wrap_0_test2_SysIntegrat_T pb;
  cell_wrap_0_test2_SysIntegrat_T qb;
  cell_wrap_0_test2_SysIntegrat_T rb;
  cell_wrap_0_test2_SysIntegrat_T sb;
  cell_wrap_0_test2_SysIntegrat_T tb;
  cell_wrap_0_test2_SysIntegrat_T ub;
  cell_wrap_0_test2_SysIntegrat_T vb;
  cell_wrap_0_test2_SysIntegrat_T wb;
  cell_wrap_0_test2_SysIntegrat_T xb;
  cell_wrap_0_test2_SysIntegrat_T yb;
  cell_wrap_0_test2_SysIntegrat_T ac;
  cell_wrap_0_test2_SysIntegrat_T bc;
  cell_wrap_0_test2_SysIntegrat_T cc;
  cell_wrap_0_test2_SysIntegrat_T dc;
  cell_wrap_0_test2_SysIntegrat_T ec;
  cell_wrap_0_test2_SysIntegrat_T fc;
  cell_wrap_0_test2_SysIntegrat_T gc;
  cell_wrap_0_test2_SysIntegrat_T hc;
  cell_wrap_0_test2_SysIntegrat_T ic;
  cell_wrap_0_test2_SysIntegrat_T jc;
  cell_wrap_0_test2_SysIntegrat_T kc;
  cell_wrap_0_test2_SysIntegrat_T lc;
  cell_wrap_0_test2_SysIntegrat_T mc;
  cell_wrap_0_test2_SysIntegrat_T nc;
  cell_wrap_0_test2_SysIntegrat_T oc;
  cell_wrap_0_test2_SysIntegrat_T pc;
  cell_wrap_0_test2_SysIntegrat_T qc;
  cell_wrap_0_test2_SysIntegrat_T rc;
  cell_wrap_0_test2_SysIntegrat_T sc;
  cell_wrap_0_test2_SysIntegrat_T tc;
  cell_wrap_0_test2_SysIntegrat_T uc;
  cell_wrap_0_test2_SysIntegrat_T vc;
  cell_wrap_0_test2_SysIntegrat_T wc;
  cell_wrap_0_test2_SysIntegrat_T xc;
  cell_wrap_0_test2_SysIntegrat_T yc;
  cell_wrap_0_test2_SysIntegrat_T ad;
  cell_wrap_0_test2_SysIntegrat_T bd;
  cell_wrap_0_test2_SysIntegrat_T cd;
  cell_wrap_0_test2_SysIntegrat_T dd;
  cell_wrap_0_test2_SysIntegrat_T ed;
  cell_wrap_0_test2_SysIntegrat_T fd;
  cell_wrap_0_test2_SysIntegrat_T gd;
  cell_wrap_0_test2_SysIntegrat_T hd;
  cell_wrap_0_test2_SysIntegrat_T id;
  cell_wrap_0_test2_SysIntegrat_T jd;
  cell_wrap_0_test2_SysIntegrat_T kd;
  cell_wrap_0_test2_SysIntegrat_T ld;
  cell_wrap_0_test2_SysIntegrat_T md;
  cell_wrap_0_test2_SysIntegrat_T nd;
  cell_wrap_0_test2_SysIntegrat_T od;
  cell_wrap_0_test2_SysIntegrat_T pd;
  cell_wrap_0_test2_SysIntegrat_T qd;
  cell_wrap_0_test2_SysIntegrat_T rd;
  cell_wrap_0_test2_SysIntegrat_T sd;
  cell_wrap_0_test2_SysIntegrat_T td;
  cell_wrap_0_test2_SysIntegrat_T ud;
  cell_wrap_0_test2_SysIntegrat_T vd;
  cell_wrap_0_test2_SysIntegrat_T wd;
  cell_wrap_0_test2_SysIntegrat_T xd;
  cell_wrap_0_test2_SysIntegrat_T yd;
  cell_wrap_0_test2_SysIntegrat_T ae;
  cell_wrap_0_test2_SysIntegrat_T be;
  cell_wrap_0_test2_SysIntegrat_T ce;
  cell_wrap_0_test2_SysIntegrat_T de;
  cell_wrap_0_test2_SysIntegrat_T ee;
  cell_wrap_0_test2_SysIntegrat_T fe;
  cell_wrap_0_test2_SysIntegrat_T ge;
  cell_wrap_0_test2_SysIntegrat_T he;
  cell_wrap_0_test2_SysIntegrat_T ie;
  cell_wrap_0_test2_SysIntegrat_T je;
  cell_wrap_0_test2_SysIntegrat_T ke;
  cell_wrap_0_test2_SysIntegrat_T le;
  cell_wrap_0_test2_SysIntegrat_T me;
  cell_wrap_0_test2_SysIntegrat_T ne;
  cell_wrap_0_test2_SysIntegrat_T oe;
  cell_wrap_0_test2_SysIntegrat_T pe;
  cell_wrap_0_test2_SysIntegrat_T qe;
  cell_wrap_0_test2_SysIntegrat_T re;
  cell_wrap_0_test2_SysIntegrat_T se;
  cell_wrap_0_test2_SysIntegrat_T te;
  cell_wrap_0_test2_SysIntegrat_T ue;
  cell_wrap_0_test2_SysIntegrat_T ve;
  cell_wrap_0_test2_SysIntegrat_T we;
  cell_wrap_0_test2_SysIntegrat_T xe;
  cell_wrap_0_test2_SysIntegrat_T ye;
  cell_wrap_0_test2_SysIntegrat_T af;
  cell_wrap_0_test2_SysIntegrat_T bf;
  cell_wrap_0_test2_SysIntegrat_T cf;
  cell_wrap_0_test2_SysIntegrat_T df;
  cell_wrap_0_test2_SysIntegrat_T ef;
  cell_wrap_0_test2_SysIntegrat_T ff;
  cell_wrap_0_test2_SysIntegrat_T gf;
  cell_wrap_0_test2_SysIntegrat_T hf;
  cell_wrap_0_test2_SysIntegrat_T jf;
  cell_wrap_0_test2_SysIntegrat_T kf;
  cell_wrap_0_test2_SysIntegrat_T lf;
  cell_wrap_0_test2_SysIntegrat_T mf;
  cell_wrap_0_test2_SysIntegrat_T nf;
  cell_wrap_0_test2_SysIntegrat_T of;
  cell_wrap_0_test2_SysIntegrat_T pf;
  cell_wrap_0_test2_SysIntegrat_T qf;
  cell_wrap_0_test2_SysIntegrat_T rf;
  cell_wrap_0_test2_SysIntegrat_T sf;
  cell_wrap_0_test2_SysIntegrat_T tf;
  cell_wrap_0_test2_SysIntegrat_T uf;
  cell_wrap_0_test2_SysIntegrat_T vf;
  cell_wrap_0_test2_SysIntegrat_T wf;
  cell_wrap_0_test2_SysIntegrat_T xf;
  cell_wrap_0_test2_SysIntegrat_T yf;
  cell_wrap_0_test2_SysIntegrat_T ag;
  cell_wrap_0_test2_SysIntegrat_T bg;
  cell_wrap_0_test2_SysIntegrat_T cg;
  cell_wrap_0_test2_SysIntegrat_T dg;
  cell_wrap_0_test2_SysIntegrat_T eg;
  cell_wrap_0_test2_SysIntegrat_T fg;
  cell_wrap_0_test2_SysIntegrat_T gg;
  cell_wrap_0_test2_SysIntegrat_T hg;
  cell_wrap_0_test2_SysIntegrat_T ig;
  cell_wrap_0_test2_SysIntegrat_T jg;
  cell_wrap_0_test2_SysIntegrat_T kg;
  cell_wrap_0_test2_SysIntegrat_T lg;
  cell_wrap_0_test2_SysIntegrat_T mg;
  cell_wrap_0_test2_SysIntegrat_T ng;
  cell_wrap_0_test2_SysIntegrat_T og;
  cell_wrap_0_test2_SysIntegrat_T pg;
  cell_wrap_0_test2_SysIntegrat_T qg;
  cell_wrap_0_test2_SysIntegrat_T rg;
  cell_wrap_0_test2_SysIntegrat_T sg;
  cell_wrap_0_test2_SysIntegrat_T tg;
  cell_wrap_0_test2_SysIntegrat_T ug;
  cell_wrap_0_test2_SysIntegrat_T vg;
  cell_wrap_0_test2_SysIntegrat_T wg;
  cell_wrap_0_test2_SysIntegrat_T xg;
  cell_wrap_0_test2_SysIntegrat_T yg;
  cell_wrap_0_test2_SysIntegrat_T ah;
  cell_wrap_0_test2_SysIntegrat_T bh;
  cell_wrap_0_test2_SysIntegrat_T ch;
  cell_wrap_0_test2_SysIntegrat_T dh;
  cell_wrap_0_test2_SysIntegrat_T eh;
  cell_wrap_0_test2_SysIntegrat_T fh;
  cell_wrap_0_test2_SysIntegrat_T gh;
  cell_wrap_0_test2_SysIntegrat_T hh;
  cell_wrap_0_test2_SysIntegrat_T ih;
  cell_wrap_0_test2_SysIntegrat_T jh;
  cell_wrap_0_test2_SysIntegrat_T kh;
  cell_wrap_0_test2_SysIntegrat_T lh;
  cell_wrap_0_test2_SysIntegrat_T mh;
  cell_wrap_0_test2_SysIntegrat_T nh;
  cell_wrap_0_test2_SysIntegrat_T oh;
  cell_wrap_0_test2_SysIntegrat_T ph;
  cell_wrap_0_test2_SysIntegrat_T qh;
  cell_wrap_0_test2_SysIntegrat_T rh;
  cell_wrap_0_test2_SysIntegrat_T sh;
  cell_wrap_0_test2_SysIntegrat_T th;
  cell_wrap_0_test2_SysIntegrat_T uh;
  cell_wrap_0_test2_SysIntegrat_T vh;
  cell_wrap_0_test2_SysIntegrat_T wh;
  cell_wrap_0_test2_SysIntegrat_T xh;
  cell_wrap_0_test2_SysIntegrat_T yh;
  cell_wrap_0_test2_SysIntegrat_T ai;
  cell_wrap_0_test2_SysIntegrat_T bi;
  cell_wrap_0_test2_SysIntegrat_T ci;
  cell_wrap_0_test2_SysIntegrat_T di;
  cell_wrap_0_test2_SysIntegrat_T ei;
  cell_wrap_0_test2_SysIntegrat_T fi;
  cell_wrap_0_test2_SysIntegrat_T gi;
  cell_wrap_0_test2_SysIntegrat_T hi;
  cell_wrap_0_test2_SysIntegrat_T ii;
  cell_wrap_0_test2_SysIntegrat_T ji;
  cell_wrap_0_test2_SysIntegrat_T ki;
  cell_wrap_0_test2_SysIntegrat_T li;
  cell_wrap_0_test2_SysIntegrat_T mi;
  cell_wrap_0_test2_SysIntegrat_T ni;
  cell_wrap_0_test2_SysIntegrat_T oi;
  cell_wrap_0_test2_SysIntegrat_T pi;
  cell_wrap_0_test2_SysIntegrat_T qi;
  cell_wrap_0_test2_SysIntegrat_T ri;
  cell_wrap_0_test2_SysIntegrat_T si;
  cell_wrap_0_test2_SysIntegrat_T ti;
  cell_wrap_0_test2_SysIntegrat_T ui;
  cell_wrap_0_test2_SysIntegrat_T vi;
  cell_wrap_0_test2_SysIntegrat_T wi;
  cell_wrap_0_test2_SysIntegrat_T xi;
  cell_wrap_0_test2_SysIntegrat_T yi;
  cell_wrap_0_test2_SysIntegrat_T aj;
  cell_wrap_0_test2_SysIntegrat_T bj;
  cell_wrap_0_test2_SysIntegrat_T cj;
  cell_wrap_0_test2_SysIntegrat_T dj;
  cell_wrap_0_test2_SysIntegrat_T ej;
  cell_wrap_0_test2_SysIntegrat_T fj;
  cell_wrap_0_test2_SysIntegrat_T gj;
  cell_wrap_0_test2_SysIntegrat_T hj;
  cell_wrap_0_test2_SysIntegrat_T ij;
  cell_wrap_0_test2_SysIntegrat_T jj;
  cell_wrap_0_test2_SysIntegrat_T kj;
  cell_wrap_0_test2_SysIntegrat_T lj;
  cell_wrap_0_test2_SysIntegrat_T mj;
  cell_wrap_0_test2_SysIntegrat_T nj;
  cell_wrap_0_test2_SysIntegrat_T oj;
  cell_wrap_0_test2_SysIntegrat_T pj;
  cell_wrap_0_test2_SysIntegrat_T qj;
  cell_wrap_0_test2_SysIntegrat_T rj;
  cell_wrap_0_test2_SysIntegrat_T sj;
  cell_wrap_0_test2_SysIntegrat_T tj;
  cell_wrap_0_test2_SysIntegrat_T uj;
  cell_wrap_0_test2_SysIntegrat_T vj;
  cell_wrap_0_test2_SysIntegrat_T wj;
  cell_wrap_0_test2_SysIntegrat_T xj;
  cell_wrap_0_test2_SysIntegrat_T yj;
  cell_wrap_0_test2_SysIntegrat_T ak;
  cell_wrap_0_test2_SysIntegrat_T bk;
  cell_wrap_0_test2_SysIntegrat_T ck;
  cell_wrap_0_test2_SysIntegrat_T dk;
  cell_wrap_0_test2_SysIntegrat_T ek;
  cell_wrap_0_test2_SysIntegrat_T fk;
  cell_wrap_0_test2_SysIntegrat_T gk;
  cell_wrap_0_test2_SysIntegrat_T hk;
  cell_wrap_0_test2_SysIntegrat_T ik;
  static const char_T jk[8] = { '7', '7', '0', '7', '3', '0', '9', '6' };

  static const char_T kk[8] = { 'e', 'e', '0', 'e', '6', '1', '2', 'c' };

  static const char_T lk[8] = { '9', '9', '0', '9', '5', '1', 'b', 'a' };

  static const char_T mk[8] = { '0', '7', '6', 'd', 'c', '4', '1', '9' };

  static const char_T nk[8] = { '7', '0', '6', 'a', 'f', '4', '8', 'f' };

  static const char_T ok[8] = { 'e', '9', '6', '3', 'a', '5', '3', '5' };

  static const char_T pk[8] = { '9', 'e', '6', '4', '9', '5', 'a', '3' };

  static const char_T qk[8] = { '0', 'e', 'd', 'b', '8', '8', '3', '2' };

  static const char_T rk[8] = { '7', '9', 'd', 'c', 'b', '8', 'a', '4' };

  static const char_T sk[8] = { 'e', '0', 'd', '5', 'e', '9', '1', 'e' };

  static const char_T tk[8] = { '9', '7', 'd', '2', 'd', '9', '8', '8' };

  static const char_T uk[8] = { '0', '9', 'b', '6', '4', 'c', '2', 'b' };

  static const char_T vk[8] = { '7', 'e', 'b', '1', '7', 'c', 'b', 'd' };

  static const char_T wk[8] = { 'e', '7', 'b', '8', '2', 'd', '0', '7' };

  static const char_T xk[8] = { '9', '0', 'b', 'f', '1', 'd', '9', '1' };

  static const char_T yk[8] = { '1', 'd', 'b', '7', '1', '0', '6', '4' };

  static const char_T al[8] = { '6', 'a', 'b', '0', '2', '0', 'f', '2' };

  static const char_T bl[8] = { 'f', '3', 'b', '9', '7', '1', '4', '8' };

  static const char_T cl[8] = { '8', '4', 'b', 'e', '4', '1', 'd', 'e' };

  static const char_T dl[8] = { '1', 'a', 'd', 'a', 'd', '4', '7', 'd' };

  static const char_T el[8] = { '6', 'd', 'd', 'd', 'e', '4', 'e', 'b' };

  static const char_T fl[8] = { 'f', '4', 'd', '4', 'b', '5', '5', '1' };

  static const char_T gl[8] = { '8', '3', 'd', '3', '8', '5', 'c', '7' };

  static const char_T hl[8] = { '1', '3', '6', 'c', '9', '8', '5', '6' };

  static const char_T il[8] = { '6', '4', '6', 'b', 'a', '8', 'c', '0' };

  static const char_T jl[8] = { 'f', 'd', '6', '2', 'f', '9', '7', 'a' };

  static const char_T kl[8] = { '8', 'a', '6', '5', 'c', '9', 'e', 'c' };

  static const char_T ll[8] = { '1', '4', '0', '1', '5', 'c', '4', 'f' };

  static const char_T ml[8] = { '6', '3', '0', '6', '6', 'c', 'd', '9' };

  static const char_T nl[8] = { 'f', 'a', '0', 'f', '3', 'd', '6', '3' };

  static const char_T ol[8] = { '8', 'd', '0', '8', '0', 'd', 'f', '5' };

  static const char_T pl[8] = { '3', 'b', '6', 'e', '2', '0', 'c', '8' };

  static const char_T ql[8] = { '4', 'c', '6', '9', '1', '0', '5', 'e' };

  static const char_T rl[8] = { 'd', '5', '6', '0', '4', '1', 'e', '4' };

  static const char_T sl[8] = { 'a', '2', '6', '7', '7', '1', '7', '2' };

  static const char_T tl[8] = { '3', 'c', '0', '3', 'e', '4', 'd', '1' };

  static const char_T ul[8] = { '4', 'b', '0', '4', 'd', '4', '4', '7' };

  static const char_T vl[8] = { 'd', '2', '0', 'd', '8', '5', 'f', 'd' };

  static const char_T wl[8] = { 'a', '5', '0', 'a', 'b', '5', '6', 'b' };

  static const char_T xl[8] = { '3', '5', 'b', '5', 'a', '8', 'f', 'a' };

  static const char_T yl[8] = { '4', '2', 'b', '2', '9', '8', '6', 'c' };

  static const char_T am[8] = { 'd', 'b', 'b', 'b', 'c', '9', 'd', '6' };

  static const char_T bm[8] = { 'a', 'c', 'b', 'c', 'f', '9', '4', '0' };

  static const char_T cm[8] = { '3', '2', 'd', '8', '6', 'c', 'e', '3' };

  static const char_T dm[8] = { '4', '5', 'd', 'f', '5', 'c', '7', '5' };

  static const char_T em[8] = { 'd', 'c', 'd', '6', '0', 'd', 'c', 'f' };

  static const char_T fm[8] = { 'a', 'b', 'd', '1', '3', 'd', '5', '9' };

  static const char_T gm[8] = { '2', '6', 'd', '9', '3', '0', 'a', 'c' };

  static const char_T hm[8] = { '5', '1', 'd', 'e', '0', '0', '3', 'a' };

  static const char_T im[8] = { 'c', '8', 'd', '7', '5', '1', '8', '0' };

  static const char_T jm[8] = { 'b', 'f', 'd', '0', '6', '1', '1', '6' };

  static const char_T km[8] = { '2', '1', 'b', '4', 'f', '4', 'b', '5' };

  static const char_T lm[8] = { '5', '6', 'b', '3', 'c', '4', '2', '3' };

  static const char_T mm[8] = { 'c', 'f', 'b', 'a', '9', '5', '9', '9' };

  static const char_T nm[8] = { 'b', '8', 'b', 'd', 'a', '5', '0', 'f' };

  static const char_T om[8] = { '2', '8', '0', '2', 'b', '8', '9', 'e' };

  static const char_T pm[8] = { '5', 'f', '0', '5', '8', '8', '0', '8' };

  static const char_T qm[8] = { 'c', '6', '0', 'c', 'd', '9', 'b', '2' };

  static const char_T rm[8] = { 'b', '1', '0', 'b', 'e', '9', '2', '4' };

  static const char_T sm[8] = { '2', 'f', '6', 'f', '7', 'c', '8', '7' };

  static const char_T tm[8] = { '5', '8', '6', '8', '4', 'c', '1', '1' };

  static const char_T um[8] = { 'c', '1', '6', '1', '1', 'd', 'a', 'b' };

  static const char_T vm[8] = { 'b', '6', '6', '6', '2', 'd', '3', 'd' };

  static const char_T wm[8] = { '7', '6', 'd', 'c', '4', '1', '9', '0' };

  static const char_T xm[8] = { '0', '1', 'd', 'b', '7', '1', '0', '6' };

  static const char_T ym[8] = { '9', '8', 'd', '2', '2', '0', 'b', 'c' };

  static const char_T an[8] = { 'e', 'f', 'd', '5', '1', '0', '2', 'a' };

  static const char_T bn[8] = { '7', '1', 'b', '1', '8', '5', '8', '9' };

  static const char_T cn[8] = { '0', '6', 'b', '6', 'b', '5', '1', 'f' };

  static const char_T dn[8] = { '9', 'f', 'b', 'f', 'e', '4', 'a', '5' };

  static const char_T en[8] = { 'e', '8', 'b', '8', 'd', '4', '3', '3' };

  static const char_T fn[8] = { '7', '8', '0', '7', 'c', '9', 'a', '2' };

  static const char_T gn[8] = { '0', 'f', '0', '0', 'f', '9', '3', '4' };

  static const char_T hn[8] = { '9', '6', '0', '9', 'a', '8', '8', 'e' };

  static const char_T in[8] = { 'e', '1', '0', 'e', '9', '8', '1', '8' };

  static const char_T kn[8] = { '7', 'f', '6', 'a', '0', 'd', 'b', 'b' };

  static const char_T ln[8] = { '0', '8', '6', 'd', '3', 'd', '2', 'd' };

  static const char_T mn[8] = { '9', '1', '6', '4', '6', 'c', '9', '7' };

  static const char_T nn[8] = { 'e', '6', '6', '3', '5', 'c', '0', '1' };

  static const char_T on[8] = { '6', 'b', '6', 'b', '5', '1', 'f', '4' };

  static const char_T pn[8] = { '1', 'c', '6', 'c', '6', '1', '6', '2' };

  static const char_T qn[8] = { '8', '5', '6', '5', '3', '0', 'd', '8' };

  static const char_T rn[8] = { 'f', '2', '6', '2', '0', '0', '4', 'e' };

  static const char_T sn[8] = { '6', 'c', '0', '6', '9', '5', 'e', 'd' };

  static const char_T tn[8] = { '1', 'b', '0', '1', 'a', '5', '7', 'b' };

  static const char_T un[8] = { '8', '2', '0', '8', 'f', '4', 'c', '1' };

  static const char_T vn[8] = { 'f', '5', '0', 'f', 'c', '4', '5', '7' };

  static const char_T wn[8] = { '6', '5', 'b', '0', 'd', '9', 'c', '6' };

  static const char_T xn[8] = { '1', '2', 'b', '7', 'e', '9', '5', '0' };

  static const char_T ao[8] = { '8', 'b', 'b', 'e', 'b', '8', 'e', 'a' };

  static const char_T bo[8] = { 'f', 'c', 'b', '9', '8', '8', '7', 'c' };

  static const char_T co[8] = { '6', '2', 'd', 'd', '1', 'd', 'd', 'f' };

  static const char_T eo[8] = { '1', '5', 'd', 'a', '2', 'd', '4', '9' };

  static const char_T fo[8] = { '8', 'c', 'd', '3', '7', 'c', 'f', '3' };

  static const char_T go[8] = { 'f', 'b', 'd', '4', '4', 'c', '6', '5' };

  static const char_T ho[8] = { '4', 'd', 'b', '2', '6', '1', '5', '8' };

  static const char_T io[8] = { '3', 'a', 'b', '5', '5', '1', 'c', 'e' };

  static const char_T jo[8] = { 'a', '3', 'b', 'c', '0', '0', '7', '4' };

  static const char_T ko[8] = { 'd', '4', 'b', 'b', '3', '0', 'e', '2' };

  static const char_T lo[8] = { '4', 'a', 'd', 'f', 'a', '5', '4', '1' };

  static const char_T mo[8] = { '3', 'd', 'd', '8', '9', '5', 'd', '7' };

  static const char_T no[8] = { 'a', '4', 'd', '1', 'c', '4', '6', 'd' };

  static const char_T oo[8] = { 'd', '3', 'd', '6', 'f', '4', 'f', 'b' };

  static const char_T po[8] = { '4', '3', '6', '9', 'e', '9', '6', 'a' };

  static const char_T qo[8] = { '3', '4', '6', 'e', 'd', '9', 'f', 'c' };

  static const char_T ro[8] = { 'a', 'd', '6', '7', '8', '8', '4', '6' };

  static const char_T so[8] = { 'd', 'a', '6', '0', 'b', '8', 'd', '0' };

  static const char_T to[8] = { '4', '4', '0', '4', '2', 'd', '7', '3' };

  static const char_T uo[8] = { '3', '3', '0', '3', '1', 'd', 'e', '5' };

  static const char_T vo[8] = { 'a', 'a', '0', 'a', '4', 'c', '5', 'f' };

  static const char_T wo[8] = { 'd', 'd', '0', 'd', '7', 'c', 'c', '9' };

  static const char_T xo[8] = { '5', '0', '0', '5', '7', '1', '3', 'c' };

  static const char_T yo[8] = { '2', '7', '0', '2', '4', '1', 'a', 'a' };

  static const char_T ap[8] = { 'b', 'e', '0', 'b', '1', '0', '1', '0' };

  static const char_T bp[8] = { 'c', '9', '0', 'c', '2', '0', '8', '6' };

  static const char_T cp[8] = { '5', '7', '6', '8', 'b', '5', '2', '5' };

  static const char_T dp[8] = { '2', '0', '6', 'f', '8', '5', 'b', '3' };

  static const char_T ep[8] = { 'b', '9', '6', '6', 'd', '4', '0', '9' };

  static const char_T fp[8] = { 'c', 'e', '6', '1', 'e', '4', '9', 'f' };

  static const char_T gp[8] = { '5', 'e', 'd', 'e', 'f', '9', '0', 'e' };

  static const char_T hp[8] = { '2', '9', 'd', '9', 'c', '9', '9', '8' };

  static const char_T ip[8] = { 'b', '0', 'd', '0', '9', '8', '2', '2' };

  static const char_T jp[8] = { 'c', '7', 'd', '7', 'a', '8', 'b', '4' };

  static const char_T kp[8] = { '5', '9', 'b', '3', '3', 'd', '1', '7' };

  static const char_T lp[8] = { '2', 'e', 'b', '4', '0', 'd', '8', '1' };

  static const char_T mp[8] = { 'b', '7', 'b', 'd', '5', 'c', '3', 'b' };

  static const char_T np[8] = { 'c', '0', 'b', 'a', '6', 'c', 'a', 'd' };

  static const char_T op[8] = { 'e', 'd', 'b', '8', '8', '3', '2', '0' };

  static const char_T pp[8] = { '9', 'a', 'b', 'f', 'b', '3', 'b', '6' };

  static const char_T qp[8] = { '0', '3', 'b', '6', 'e', '2', '0', 'c' };

  static const char_T rp[8] = { '7', '4', 'b', '1', 'd', '2', '9', 'a' };

  static const char_T sp[8] = { 'e', 'a', 'd', '5', '4', '7', '3', '9' };

  static const char_T tp[8] = { '9', 'd', 'd', '2', '7', '7', 'a', 'f' };

  static const char_T up[8] = { '0', '4', 'd', 'b', '2', '6', '1', '5' };

  static const char_T vp[8] = { '7', '3', 'd', 'c', '1', '6', '8', '3' };

  static const char_T wp[8] = { 'e', '3', '6', '3', '0', 'b', '1', '2' };

  static const char_T xp[8] = { '9', '4', '6', '4', '3', 'b', '8', '4' };

  static const char_T yp[8] = { '0', 'd', '6', 'd', '6', 'a', '3', 'e' };

  static const char_T aq[8] = { '7', 'a', '6', 'a', '5', 'a', 'a', '8' };

  static const char_T bq[8] = { 'e', '4', '0', 'e', 'c', 'f', '0', 'b' };

  static const char_T cq[8] = { '9', '3', '0', '9', 'f', 'f', '9', 'd' };

  static const char_T dq[8] = { '0', 'a', '0', '0', 'a', 'e', '2', '7' };

  static const char_T eq[8] = { '7', 'd', '0', '7', '9', 'e', 'b', '1' };

  static const char_T fq[8] = { 'f', '0', '0', 'f', '9', '3', '4', '4' };

  static const char_T gq[8] = { '8', '7', '0', '8', 'a', '3', 'd', '2' };

  static const char_T hq[8] = { '1', 'e', '0', '1', 'f', '2', '6', '8' };

  static const char_T iq[8] = { '6', '9', '0', '6', 'c', '2', 'f', 'e' };

  static const char_T jq[8] = { 'f', '7', '6', '2', '5', '7', '5', 'd' };

  static const char_T kq[8] = { '8', '0', '6', '5', '6', '7', 'c', 'b' };

  static const char_T lq[8] = { '1', '9', '6', 'c', '3', '6', '7', '1' };

  static const char_T mq[8] = { '6', 'e', '6', 'b', '0', '6', 'e', '7' };

  static const char_T nq[8] = { 'f', 'e', 'd', '4', '1', 'b', '7', '6' };

  static const char_T oq[8] = { '8', '9', 'd', '3', '2', 'b', 'e', '0' };

  static const char_T pq[8] = { '1', '0', 'd', 'a', '7', 'a', '5', 'a' };

  static const char_T qq[8] = { '6', '7', 'd', 'd', '4', 'a', 'c', 'c' };

  static const char_T rq[8] = { 'f', '9', 'b', '9', 'd', 'f', '6', 'f' };

  static const char_T sq[8] = { '8', 'e', 'b', 'e', 'e', 'f', 'f', '9' };

  static const char_T tq[8] = { '1', '7', 'b', '7', 'b', 'e', '4', '3' };

  static const char_T uq[8] = { '6', '0', 'b', '0', '8', 'e', 'd', '5' };

  static const char_T vq[8] = { 'd', '6', 'd', '6', 'a', '3', 'e', '8' };

  static const char_T wq[8] = { 'a', '1', 'd', '1', '9', '3', '7', 'e' };

  static const char_T xq[8] = { '3', '8', 'd', '8', 'c', '2', 'c', '4' };

  static const char_T yq[8] = { '4', 'f', 'd', 'f', 'f', '2', '5', '2' };

  static const char_T ar[8] = { 'd', '1', 'b', 'b', '6', '7', 'f', '1' };

  static const char_T br[8] = { 'a', '6', 'b', 'c', '5', '7', '6', '7' };

  static const char_T cr[8] = { '3', 'f', 'b', '5', '0', '6', 'd', 'd' };

  static const char_T dr[8] = { '4', '8', 'b', '2', '3', '6', '4', 'b' };

  static const char_T er[8] = { 'd', '8', '0', 'd', '2', 'b', 'd', 'a' };

  static const char_T fr[8] = { 'a', 'f', '0', 'a', '1', 'b', '4', 'c' };

  static const char_T gr[8] = { '3', '6', '0', '3', '4', 'a', 'f', '6' };

  static const char_T hr[8] = { '4', '1', '0', '4', '7', 'a', '6', '0' };

  static const char_T ir[8] = { 'd', 'f', '6', '0', 'e', 'f', 'c', '3' };

  static const char_T jr[8] = { 'a', '8', '6', '7', 'd', 'f', '5', '5' };

  static const char_T kr[8] = { '3', '1', '6', 'e', '8', 'e', 'e', 'f' };

  static const char_T lr[8] = { '4', '6', '6', '9', 'b', 'e', '7', '9' };

  static const char_T mr[8] = { 'c', 'b', '6', '1', 'b', '3', '8', 'c' };

  static const char_T nr[8] = { 'b', 'c', '6', '6', '8', '3', '1', 'a' };

  static const char_T or[8] = { '2', '5', '6', 'f', 'd', '2', 'a', '0' };

  static const char_T pr[8] = { '5', '2', '6', '8', 'e', '2', '3', '6' };

  static const char_T qr[8] = { 'c', 'c', '0', 'c', '7', '7', '9', '5' };

  static const char_T rr[8] = { 'b', 'b', '0', 'b', '4', '7', '0', '3' };

  static const char_T sr[8] = { '2', '2', '0', '2', '1', '6', 'b', '9' };

  static const char_T tr[8] = { '5', '5', '0', '5', '2', '6', '2', 'f' };

  static const char_T ur[8] = { 'c', '5', 'b', 'a', '3', 'b', 'b', 'e' };

  static const char_T vr[8] = { 'b', '2', 'b', 'd', '0', 'b', '2', '8' };

  static const char_T wr[8] = { '2', 'b', 'b', '4', '5', 'a', '9', '2' };

  static const char_T xr[8] = { '5', 'c', 'b', '3', '6', 'a', '0', '4' };

  static const char_T yr[8] = { 'c', '2', 'd', '7', 'f', 'f', 'a', '7' };

  static const char_T as[8] = { 'b', '5', 'd', '0', 'c', 'f', '3', '1' };

  static const char_T bs[8] = { '2', 'c', 'd', '9', '9', 'e', '8', 'b' };

  static const char_T cs[8] = { '5', 'b', 'd', 'e', 'a', 'e', '1', 'd' };

  static const char_T ds[8] = { '9', 'b', '6', '4', 'c', '2', 'b', '0' };

  static const char_T es[8] = { 'e', 'c', '6', '3', 'f', '2', '2', '6' };

  static const char_T fs[8] = { '7', '5', '6', 'a', 'a', '3', '9', 'c' };

  static const char_T gs[8] = { '0', '2', '6', 'd', '9', '3', '0', 'a' };

  static const char_T hs[8] = { '9', 'c', '0', '9', '0', '6', 'a', '9' };

  static const char_T is[8] = { 'e', 'b', '0', 'e', '3', '6', '3', 'f' };

  static const char_T js[8] = { '7', '2', '0', '7', '6', '7', '8', '5' };

  static const char_T ks[8] = { '0', '5', '0', '0', '5', '7', '1', '3' };

  static const char_T ls[8] = { '9', '5', 'b', 'f', '4', 'a', '8', '2' };

  static const char_T ms[8] = { 'e', '2', 'b', '8', '7', 'a', '1', '4' };

  static const char_T ns[8] = { '7', 'b', 'b', '1', '2', 'b', 'a', 'e' };

  static const char_T os[8] = { '0', 'c', 'b', '6', '1', 'b', '3', '8' };

  static const char_T ps[8] = { '9', '2', 'd', '2', '8', 'e', '9', 'b' };

  static const char_T qs[8] = { 'e', '5', 'd', '5', 'b', 'e', '0', 'd' };

  static const char_T rs[8] = { '7', 'c', 'd', 'c', 'e', 'f', 'b', '7' };

  static const char_T ss[8] = { '0', 'b', 'd', 'b', 'd', 'f', '2', '1' };

  static const char_T ts[8] = { '8', '6', 'd', '3', 'd', '2', 'd', '4' };

  static const char_T us[8] = { 'f', '1', 'd', '4', 'e', '2', '4', '2' };

  static const char_T vs[8] = { '6', '8', 'd', 'd', 'b', '3', 'f', '8' };

  static const char_T ws[8] = { '1', 'f', 'd', 'a', '8', '3', '6', 'e' };

  static const char_T xs[8] = { '8', '1', 'b', 'e', '1', '6', 'c', 'd' };

  static const char_T ys[8] = { 'f', '6', 'b', '9', '2', '6', '5', 'b' };

  static const char_T at[8] = { '6', 'f', 'b', '0', '7', '7', 'e', '1' };

  static const char_T bt[8] = { '1', '8', 'b', '7', '4', '7', '7', '7' };

  static const char_T ct[8] = { '8', '8', '0', '8', '5', 'a', 'e', '6' };

  static const char_T dt[8] = { 'f', 'f', '0', 'f', '6', 'a', '7', '0' };

  static const char_T et[8] = { '6', '6', '0', '6', '3', 'b', 'c', 'a' };

  static const char_T ft[8] = { '1', '1', '0', '1', '0', 'b', '5', 'c' };

  static const char_T gt[8] = { '8', 'f', '6', '5', '9', 'e', 'f', 'f' };

  static const char_T ht[8] = { 'f', '8', '6', '2', 'a', 'e', '6', '9' };

  static const char_T it[8] = { '6', '1', '6', 'b', 'f', 'f', 'd', '3' };

  static const char_T jt[8] = { '1', '6', '6', 'c', 'c', 'f', '4', '5' };

  static const char_T kt[8] = { 'a', '0', '0', 'a', 'e', '2', '7', '8' };

  static const char_T lt[8] = { 'd', '7', '0', 'd', 'd', '2', 'e', 'e' };

  static const char_T mt[8] = { '4', 'e', '0', '4', '8', '3', '5', '4' };

  static const char_T nt[8] = { '3', '9', '0', '3', 'b', '3', 'c', '2' };

  static const char_T ot[8] = { 'a', '7', '6', '7', '2', '6', '6', '1' };

  static const char_T pt[8] = { 'd', '0', '6', '0', '1', '6', 'f', '7' };

  static const char_T qt[8] = { '4', '9', '6', '9', '4', '7', '4', 'd' };

  static const char_T rt[8] = { '3', 'e', '6', 'e', '7', '7', 'd', 'b' };

  static const char_T st[8] = { 'a', 'e', 'd', '1', '6', 'a', '4', 'a' };

  static const char_T tt[8] = { 'd', '9', 'd', '6', '5', 'a', 'd', 'c' };

  static const char_T ut[8] = { '4', '0', 'd', 'f', '0', 'b', '6', '6' };

  static const char_T vt[8] = { '3', '7', 'd', '8', '3', 'b', 'f', '0' };

  static const char_T wt[8] = { 'a', '9', 'b', 'c', 'a', 'e', '5', '3' };

  static const char_T xt[8] = { 'd', 'e', 'b', 'b', '9', 'e', 'c', '5' };

  static const char_T yt[8] = { '4', '7', 'b', '2', 'c', 'f', '7', 'f' };

  static const char_T au[8] = { '3', '0', 'b', '5', 'f', 'f', 'e', '9' };

  static const char_T bu[8] = { 'b', 'd', 'b', 'd', 'f', '2', '1', 'c' };

  static const char_T cu[8] = { 'c', 'a', 'b', 'a', 'c', '2', '8', 'a' };

  static const char_T du[8] = { '5', '3', 'b', '3', '9', '3', '3', '0' };

  static const char_T eu[8] = { '2', '4', 'b', '4', 'a', '3', 'a', '6' };

  static const char_T fu[8] = { 'b', 'a', 'd', '0', '3', '6', '0', '5' };

  static const char_T gu[8] = { 'c', 'd', 'd', '7', '0', '6', '9', '3' };

  static const char_T hu[8] = { '5', '4', 'd', 'e', '5', '7', '2', '9' };

  static const char_T iu[8] = { '2', '3', 'd', '9', '6', '7', 'b', 'f' };

  static const char_T ju[8] = { 'b', '3', '6', '6', '7', 'a', '2', 'e' };

  static const char_T ku[8] = { 'c', '4', '6', '1', '4', 'a', 'b', '8' };

  static const char_T lu[8] = { '5', 'd', '6', '8', '1', 'b', '0', '2' };

  static const char_T mu[8] = { '2', 'a', '6', 'f', '2', 'b', '9', '4' };

  static const char_T nu[8] = { 'b', '4', '0', 'b', 'b', 'e', '3', '7' };

  static const char_T ou[8] = { 'c', '3', '0', 'c', '8', 'e', 'a', '1' };

  static const char_T pu[8] = { '5', 'a', '0', '5', 'd', 'f', '1', 'b' };

  static const char_T qu[8] = { '2', 'd', '0', '2', 'e', 'f', '8', 'd' };

  int32_T i_0;
  real_T tmp;
  for (i_0 = 0; i_0 < 8; i_0++) {
    b.f1[i_0] = '0';
    c.f1[i_0] = jk[i_0];
    d.f1[i_0] = kk[i_0];
    e.f1[i_0] = lk[i_0];
    f.f1[i_0] = mk[i_0];
    g.f1[i_0] = nk[i_0];
    h.f1[i_0] = ok[i_0];
    j.f1[i_0] = pk[i_0];
    k.f1[i_0] = qk[i_0];
    l.f1[i_0] = rk[i_0];
    m.f1[i_0] = sk[i_0];
    n.f1[i_0] = tk[i_0];
    o.f1[i_0] = uk[i_0];
    p.f1[i_0] = vk[i_0];
    q.f1[i_0] = wk[i_0];
    r.f1[i_0] = xk[i_0];
    s.f1[i_0] = yk[i_0];
    t.f1[i_0] = al[i_0];
    u.f1[i_0] = bl[i_0];
    v.f1[i_0] = cl[i_0];
    w.f1[i_0] = dl[i_0];
    x.f1[i_0] = el[i_0];
    y.f1[i_0] = fl[i_0];
    ab.f1[i_0] = gl[i_0];
    bb.f1[i_0] = hl[i_0];
    cb.f1[i_0] = il[i_0];
    db.f1[i_0] = jl[i_0];
    eb.f1[i_0] = kl[i_0];
    fb.f1[i_0] = ll[i_0];
    gb.f1[i_0] = ml[i_0];
    hb.f1[i_0] = nl[i_0];
    ib.f1[i_0] = ol[i_0];
    jb.f1[i_0] = pl[i_0];
    kb.f1[i_0] = ql[i_0];
    lb.f1[i_0] = rl[i_0];
    mb.f1[i_0] = sl[i_0];
    nb.f1[i_0] = tl[i_0];
    ob.f1[i_0] = ul[i_0];
    pb.f1[i_0] = vl[i_0];
    qb.f1[i_0] = wl[i_0];
    rb.f1[i_0] = xl[i_0];
    sb.f1[i_0] = yl[i_0];
    tb.f1[i_0] = am[i_0];
    ub.f1[i_0] = bm[i_0];
    vb.f1[i_0] = cm[i_0];
    wb.f1[i_0] = dm[i_0];
    xb.f1[i_0] = em[i_0];
    yb.f1[i_0] = fm[i_0];
    ac.f1[i_0] = gm[i_0];
    bc.f1[i_0] = hm[i_0];
    cc.f1[i_0] = im[i_0];
    dc.f1[i_0] = jm[i_0];
    ec.f1[i_0] = km[i_0];
    fc.f1[i_0] = lm[i_0];
    gc.f1[i_0] = mm[i_0];
    hc.f1[i_0] = nm[i_0];
    ic.f1[i_0] = om[i_0];
    jc.f1[i_0] = pm[i_0];
    kc.f1[i_0] = qm[i_0];
    lc.f1[i_0] = rm[i_0];
    mc.f1[i_0] = sm[i_0];
    nc.f1[i_0] = tm[i_0];
    oc.f1[i_0] = um[i_0];
    pc.f1[i_0] = vm[i_0];
    qc.f1[i_0] = wm[i_0];
    rc.f1[i_0] = xm[i_0];
    sc.f1[i_0] = ym[i_0];
    tc.f1[i_0] = an[i_0];
    uc.f1[i_0] = bn[i_0];
    vc.f1[i_0] = cn[i_0];
    wc.f1[i_0] = dn[i_0];
    xc.f1[i_0] = en[i_0];
    yc.f1[i_0] = fn[i_0];
    ad.f1[i_0] = gn[i_0];
    bd.f1[i_0] = hn[i_0];
    cd.f1[i_0] = in[i_0];
    dd.f1[i_0] = kn[i_0];
    ed.f1[i_0] = ln[i_0];
    fd.f1[i_0] = mn[i_0];
    gd.f1[i_0] = nn[i_0];
    hd.f1[i_0] = on[i_0];
    id.f1[i_0] = pn[i_0];
    jd.f1[i_0] = qn[i_0];
    kd.f1[i_0] = rn[i_0];
    ld.f1[i_0] = sn[i_0];
    md.f1[i_0] = tn[i_0];
    nd.f1[i_0] = un[i_0];
    od.f1[i_0] = vn[i_0];
    pd.f1[i_0] = wn[i_0];
    qd.f1[i_0] = xn[i_0];
    rd.f1[i_0] = ao[i_0];
    sd.f1[i_0] = bo[i_0];
    td.f1[i_0] = co[i_0];
    ud.f1[i_0] = eo[i_0];
    vd.f1[i_0] = fo[i_0];
    wd.f1[i_0] = go[i_0];
    xd.f1[i_0] = ho[i_0];
    yd.f1[i_0] = io[i_0];
    ae.f1[i_0] = jo[i_0];
    be.f1[i_0] = ko[i_0];
    ce.f1[i_0] = lo[i_0];
    de.f1[i_0] = mo[i_0];
    ee.f1[i_0] = no[i_0];
    fe.f1[i_0] = oo[i_0];
    ge.f1[i_0] = po[i_0];
    he.f1[i_0] = qo[i_0];
    ie.f1[i_0] = ro[i_0];
    je.f1[i_0] = so[i_0];
    ke.f1[i_0] = to[i_0];
    le.f1[i_0] = uo[i_0];
    me.f1[i_0] = vo[i_0];
    ne.f1[i_0] = wo[i_0];
    oe.f1[i_0] = xo[i_0];
    pe.f1[i_0] = yo[i_0];
    qe.f1[i_0] = ap[i_0];
    re.f1[i_0] = bp[i_0];
    se.f1[i_0] = cp[i_0];
    te.f1[i_0] = dp[i_0];
    ue.f1[i_0] = ep[i_0];
    ve.f1[i_0] = fp[i_0];
    we.f1[i_0] = gp[i_0];
    xe.f1[i_0] = hp[i_0];
    ye.f1[i_0] = ip[i_0];
    af.f1[i_0] = jp[i_0];
    bf.f1[i_0] = kp[i_0];
    cf.f1[i_0] = lp[i_0];
    df.f1[i_0] = mp[i_0];
    ef.f1[i_0] = np[i_0];
    ff.f1[i_0] = op[i_0];
    gf.f1[i_0] = pp[i_0];
    hf.f1[i_0] = qp[i_0];
    jf.f1[i_0] = rp[i_0];
    kf.f1[i_0] = sp[i_0];
    lf.f1[i_0] = tp[i_0];
    mf.f1[i_0] = up[i_0];
    nf.f1[i_0] = vp[i_0];
    of.f1[i_0] = wp[i_0];
    pf.f1[i_0] = xp[i_0];
    qf.f1[i_0] = yp[i_0];
    rf.f1[i_0] = aq[i_0];
    sf.f1[i_0] = bq[i_0];
    tf.f1[i_0] = cq[i_0];
    uf.f1[i_0] = dq[i_0];
    vf.f1[i_0] = eq[i_0];
    wf.f1[i_0] = fq[i_0];
    xf.f1[i_0] = gq[i_0];
    yf.f1[i_0] = hq[i_0];
    ag.f1[i_0] = iq[i_0];
    bg.f1[i_0] = jq[i_0];
    cg.f1[i_0] = kq[i_0];
    dg.f1[i_0] = lq[i_0];
    eg.f1[i_0] = mq[i_0];
    fg.f1[i_0] = nq[i_0];
    gg.f1[i_0] = oq[i_0];
    hg.f1[i_0] = pq[i_0];
    ig.f1[i_0] = qq[i_0];
    jg.f1[i_0] = rq[i_0];
    kg.f1[i_0] = sq[i_0];
    lg.f1[i_0] = tq[i_0];
    mg.f1[i_0] = uq[i_0];
    ng.f1[i_0] = vq[i_0];
    og.f1[i_0] = wq[i_0];
    pg.f1[i_0] = xq[i_0];
    qg.f1[i_0] = yq[i_0];
    rg.f1[i_0] = ar[i_0];
    sg.f1[i_0] = br[i_0];
    tg.f1[i_0] = cr[i_0];
    ug.f1[i_0] = dr[i_0];
    vg.f1[i_0] = er[i_0];
    wg.f1[i_0] = fr[i_0];
    xg.f1[i_0] = gr[i_0];
    yg.f1[i_0] = hr[i_0];
    ah.f1[i_0] = ir[i_0];
    bh.f1[i_0] = jr[i_0];
    ch.f1[i_0] = kr[i_0];
    dh.f1[i_0] = lr[i_0];
    eh.f1[i_0] = mr[i_0];
    fh.f1[i_0] = nr[i_0];
    gh.f1[i_0] = or[i_0];
    hh.f1[i_0] = pr[i_0];
    ih.f1[i_0] = qr[i_0];
    jh.f1[i_0] = rr[i_0];
    kh.f1[i_0] = sr[i_0];
    lh.f1[i_0] = tr[i_0];
    mh.f1[i_0] = ur[i_0];
    nh.f1[i_0] = vr[i_0];
    oh.f1[i_0] = wr[i_0];
    ph.f1[i_0] = xr[i_0];
    qh.f1[i_0] = yr[i_0];
    rh.f1[i_0] = as[i_0];
    sh.f1[i_0] = bs[i_0];
    th.f1[i_0] = cs[i_0];
    uh.f1[i_0] = ds[i_0];
    vh.f1[i_0] = es[i_0];
    wh.f1[i_0] = fs[i_0];
    xh.f1[i_0] = gs[i_0];
    yh.f1[i_0] = hs[i_0];
    ai.f1[i_0] = is[i_0];
    bi.f1[i_0] = js[i_0];
    ci.f1[i_0] = ks[i_0];
    di.f1[i_0] = ls[i_0];
    ei.f1[i_0] = ms[i_0];
    fi.f1[i_0] = ns[i_0];
    gi.f1[i_0] = os[i_0];
    hi.f1[i_0] = ps[i_0];
    ii.f1[i_0] = qs[i_0];
    ji.f1[i_0] = rs[i_0];
    ki.f1[i_0] = ss[i_0];
    li.f1[i_0] = ts[i_0];
    mi.f1[i_0] = us[i_0];
    ni.f1[i_0] = vs[i_0];
    oi.f1[i_0] = ws[i_0];
    pi.f1[i_0] = xs[i_0];
    qi.f1[i_0] = ys[i_0];
    ri.f1[i_0] = at[i_0];
    si.f1[i_0] = bt[i_0];
    ti.f1[i_0] = ct[i_0];
    ui.f1[i_0] = dt[i_0];
    vi.f1[i_0] = et[i_0];
    wi.f1[i_0] = ft[i_0];
    xi.f1[i_0] = gt[i_0];
    yi.f1[i_0] = ht[i_0];
    aj.f1[i_0] = it[i_0];
    bj.f1[i_0] = jt[i_0];
    cj.f1[i_0] = kt[i_0];
    dj.f1[i_0] = lt[i_0];
    ej.f1[i_0] = mt[i_0];
    fj.f1[i_0] = nt[i_0];
    gj.f1[i_0] = ot[i_0];
    hj.f1[i_0] = pt[i_0];
    ij.f1[i_0] = qt[i_0];
    jj.f1[i_0] = rt[i_0];
    kj.f1[i_0] = st[i_0];
    lj.f1[i_0] = tt[i_0];
    mj.f1[i_0] = ut[i_0];
    nj.f1[i_0] = vt[i_0];
    oj.f1[i_0] = wt[i_0];
    pj.f1[i_0] = xt[i_0];
    qj.f1[i_0] = yt[i_0];
    rj.f1[i_0] = au[i_0];
    sj.f1[i_0] = bu[i_0];
    tj.f1[i_0] = cu[i_0];
    uj.f1[i_0] = du[i_0];
    vj.f1[i_0] = eu[i_0];
    wj.f1[i_0] = fu[i_0];
    xj.f1[i_0] = gu[i_0];
    yj.f1[i_0] = hu[i_0];
    ak.f1[i_0] = iu[i_0];
    bk.f1[i_0] = ju[i_0];
    ck.f1[i_0] = ku[i_0];
    dk.f1[i_0] = lu[i_0];
    ek.f1[i_0] = mu[i_0];
    fk.f1[i_0] = nu[i_0];
    gk.f1[i_0] = ou[i_0];
    hk.f1[i_0] = pu[i_0];
    ik.f1[i_0] = qu[i_0];
  }

  g_crc32_table[0] = b;
  g_crc32_table[1] = c;
  g_crc32_table[2] = d;
  g_crc32_table[3] = e;
  g_crc32_table[4] = f;
  g_crc32_table[5] = g;
  g_crc32_table[6] = h;
  g_crc32_table[7] = j;
  g_crc32_table[8] = k;
  g_crc32_table[9] = l;
  g_crc32_table[10] = m;
  g_crc32_table[11] = n;
  g_crc32_table[12] = o;
  g_crc32_table[13] = p;
  g_crc32_table[14] = q;
  g_crc32_table[15] = r;
  g_crc32_table[16] = s;
  g_crc32_table[17] = t;
  g_crc32_table[18] = u;
  g_crc32_table[19] = v;
  g_crc32_table[20] = w;
  g_crc32_table[21] = x;
  g_crc32_table[22] = y;
  g_crc32_table[23] = ab;
  g_crc32_table[24] = bb;
  g_crc32_table[25] = cb;
  g_crc32_table[26] = db;
  g_crc32_table[27] = eb;
  g_crc32_table[28] = fb;
  g_crc32_table[29] = gb;
  g_crc32_table[30] = hb;
  g_crc32_table[31] = ib;
  g_crc32_table[32] = jb;
  g_crc32_table[33] = kb;
  g_crc32_table[34] = lb;
  g_crc32_table[35] = mb;
  g_crc32_table[36] = nb;
  g_crc32_table[37] = ob;
  g_crc32_table[38] = pb;
  g_crc32_table[39] = qb;
  g_crc32_table[40] = rb;
  g_crc32_table[41] = sb;
  g_crc32_table[42] = tb;
  g_crc32_table[43] = ub;
  g_crc32_table[44] = vb;
  g_crc32_table[45] = wb;
  g_crc32_table[46] = xb;
  g_crc32_table[47] = yb;
  g_crc32_table[48] = ac;
  g_crc32_table[49] = bc;
  g_crc32_table[50] = cc;
  g_crc32_table[51] = dc;
  g_crc32_table[52] = ec;
  g_crc32_table[53] = fc;
  g_crc32_table[54] = gc;
  g_crc32_table[55] = hc;
  g_crc32_table[56] = ic;
  g_crc32_table[57] = jc;
  g_crc32_table[58] = kc;
  g_crc32_table[59] = lc;
  g_crc32_table[60] = mc;
  g_crc32_table[61] = nc;
  g_crc32_table[62] = oc;
  g_crc32_table[63] = pc;
  g_crc32_table[64] = qc;
  g_crc32_table[65] = rc;
  g_crc32_table[66] = sc;
  g_crc32_table[67] = tc;
  g_crc32_table[68] = uc;
  g_crc32_table[69] = vc;
  g_crc32_table[70] = wc;
  g_crc32_table[71] = xc;
  g_crc32_table[72] = yc;
  g_crc32_table[73] = ad;
  g_crc32_table[74] = bd;
  g_crc32_table[75] = cd;
  g_crc32_table[76] = dd;
  g_crc32_table[77] = ed;
  g_crc32_table[78] = fd;
  g_crc32_table[79] = gd;
  g_crc32_table[80] = hd;
  g_crc32_table[81] = id;
  g_crc32_table[82] = jd;
  g_crc32_table[83] = kd;
  g_crc32_table[84] = ld;
  g_crc32_table[85] = md;
  g_crc32_table[86] = nd;
  g_crc32_table[87] = od;
  g_crc32_table[88] = pd;
  g_crc32_table[89] = qd;
  g_crc32_table[90] = rd;
  g_crc32_table[91] = sd;
  g_crc32_table[92] = td;
  g_crc32_table[93] = ud;
  g_crc32_table[94] = vd;
  g_crc32_table[95] = wd;
  g_crc32_table[96] = xd;
  g_crc32_table[97] = yd;
  g_crc32_table[98] = ae;
  g_crc32_table[99] = be;
  g_crc32_table[100] = ce;
  g_crc32_table[101] = de;
  g_crc32_table[102] = ee;
  g_crc32_table[103] = fe;
  g_crc32_table[104] = ge;
  g_crc32_table[105] = he;
  g_crc32_table[106] = ie;
  g_crc32_table[107] = je;
  g_crc32_table[108] = ke;
  g_crc32_table[109] = le;
  g_crc32_table[110] = me;
  g_crc32_table[111] = ne;
  g_crc32_table[112] = oe;
  g_crc32_table[113] = pe;
  g_crc32_table[114] = qe;
  g_crc32_table[115] = re;
  g_crc32_table[116] = se;
  g_crc32_table[117] = te;
  g_crc32_table[118] = ue;
  g_crc32_table[119] = ve;
  g_crc32_table[120] = we;
  g_crc32_table[121] = xe;
  g_crc32_table[122] = ye;
  g_crc32_table[123] = af;
  g_crc32_table[124] = bf;
  g_crc32_table[125] = cf;
  g_crc32_table[126] = df;
  g_crc32_table[127] = ef;
  g_crc32_table[128] = ff;
  g_crc32_table[129] = gf;
  g_crc32_table[130] = hf;
  g_crc32_table[131] = jf;
  g_crc32_table[132] = kf;
  g_crc32_table[133] = lf;
  g_crc32_table[134] = mf;
  g_crc32_table[135] = nf;
  g_crc32_table[136] = of;
  g_crc32_table[137] = pf;
  g_crc32_table[138] = qf;
  g_crc32_table[139] = rf;
  g_crc32_table[140] = sf;
  g_crc32_table[141] = tf;
  g_crc32_table[142] = uf;
  g_crc32_table[143] = vf;
  g_crc32_table[144] = wf;
  g_crc32_table[145] = xf;
  g_crc32_table[146] = yf;
  g_crc32_table[147] = ag;
  g_crc32_table[148] = bg;
  g_crc32_table[149] = cg;
  g_crc32_table[150] = dg;
  g_crc32_table[151] = eg;
  g_crc32_table[152] = fg;
  g_crc32_table[153] = gg;
  g_crc32_table[154] = hg;
  g_crc32_table[155] = ig;
  g_crc32_table[156] = jg;
  g_crc32_table[157] = kg;
  g_crc32_table[158] = lg;
  g_crc32_table[159] = mg;
  g_crc32_table[160] = ng;
  g_crc32_table[161] = og;
  g_crc32_table[162] = pg;
  g_crc32_table[163] = qg;
  g_crc32_table[164] = rg;
  g_crc32_table[165] = sg;
  g_crc32_table[166] = tg;
  g_crc32_table[167] = ug;
  g_crc32_table[168] = vg;
  g_crc32_table[169] = wg;
  g_crc32_table[170] = xg;
  g_crc32_table[171] = yg;
  g_crc32_table[172] = ah;
  g_crc32_table[173] = bh;
  g_crc32_table[174] = ch;
  g_crc32_table[175] = dh;
  g_crc32_table[176] = eh;
  g_crc32_table[177] = fh;
  g_crc32_table[178] = gh;
  g_crc32_table[179] = hh;
  g_crc32_table[180] = ih;
  g_crc32_table[181] = jh;
  g_crc32_table[182] = kh;
  g_crc32_table[183] = lh;
  g_crc32_table[184] = mh;
  g_crc32_table[185] = nh;
  g_crc32_table[186] = oh;
  g_crc32_table[187] = ph;
  g_crc32_table[188] = qh;
  g_crc32_table[189] = rh;
  g_crc32_table[190] = sh;
  g_crc32_table[191] = th;
  g_crc32_table[192] = uh;
  g_crc32_table[193] = vh;
  g_crc32_table[194] = wh;
  g_crc32_table[195] = xh;
  g_crc32_table[196] = yh;
  g_crc32_table[197] = ai;
  g_crc32_table[198] = bi;
  g_crc32_table[199] = ci;
  g_crc32_table[200] = di;
  g_crc32_table[201] = ei;
  g_crc32_table[202] = fi;
  g_crc32_table[203] = gi;
  g_crc32_table[204] = hi;
  g_crc32_table[205] = ii;
  g_crc32_table[206] = ji;
  g_crc32_table[207] = ki;
  g_crc32_table[208] = li;
  g_crc32_table[209] = mi;
  g_crc32_table[210] = ni;
  g_crc32_table[211] = oi;
  g_crc32_table[212] = pi;
  g_crc32_table[213] = qi;
  g_crc32_table[214] = ri;
  g_crc32_table[215] = si;
  g_crc32_table[216] = ti;
  g_crc32_table[217] = ui;
  g_crc32_table[218] = vi;
  g_crc32_table[219] = wi;
  g_crc32_table[220] = xi;
  g_crc32_table[221] = yi;
  g_crc32_table[222] = aj;
  g_crc32_table[223] = bj;
  g_crc32_table[224] = cj;
  g_crc32_table[225] = dj;
  g_crc32_table[226] = ej;
  g_crc32_table[227] = fj;
  g_crc32_table[228] = gj;
  g_crc32_table[229] = hj;
  g_crc32_table[230] = ij;
  g_crc32_table[231] = jj;
  g_crc32_table[232] = kj;
  g_crc32_table[233] = lj;
  g_crc32_table[234] = mj;
  g_crc32_table[235] = nj;
  g_crc32_table[236] = oj;
  g_crc32_table[237] = pj;
  g_crc32_table[238] = qj;
  g_crc32_table[239] = rj;
  g_crc32_table[240] = sj;
  g_crc32_table[241] = tj;
  g_crc32_table[242] = uj;
  g_crc32_table[243] = vj;
  g_crc32_table[244] = wj;
  g_crc32_table[245] = xj;
  g_crc32_table[246] = yj;
  g_crc32_table[247] = ak;
  g_crc32_table[248] = bk;
  g_crc32_table[249] = ck;
  g_crc32_table[250] = dk;
  g_crc32_table[251] = ek;
  g_crc32_table[252] = fk;
  g_crc32_table[253] = gk;
  g_crc32_table[254] = hk;
  g_crc32_table[255] = ik;
  y_CRC32Val = x_CRC32Val;
  for (i = 1U; i <= x_DataBagBytes; i++) {
    temp_index = ((x_OneBagData[i - 1] ^ y_CRC32Val) & 255U) ^ y_CRC32Val >> 8U;
    tmp = rt_roundd_snf(test2_SysIntegration_hex2dec(g_crc32_table[(int32_T)
      temp_index - 1].f1));
    if (tmp < 4.294967296E+9) {
      if (tmp >= 0.0) {
        y_CRC32Val = (uint32_T)tmp;
      } else {
        y_CRC32Val = 0U;
      }
    } else {
      y_CRC32Val = MAX_uint32_T;
    }
  }

  return y_CRC32Val;
}

/* Function for Chart: '<S63>/Chart' */
static type_FirmwareCtrlParam test2_SysIn_UpdateFirmwareParam(const
  type_FirmwareCtrlParam x3_oldFirmwareParam, const uint8_T x3_OneBagData[132])
{
  type_FirmwareCtrlParam y3_newFirmwareParam;
  boolean_T b_p;
  boolean_T d_p;
  uint32_T qY;
  y3_newFirmwareParam = x3_oldFirmwareParam;
  y3_newFirmwareParam.boolGet1Bag = true;
  qY = x3_oldFirmwareParam.CurDataBagNo + /*MW:OvSatOk*/ 1U;
  if (qY < x3_oldFirmwareParam.CurDataBagNo) {
    qY = MAX_uint32_T;
  }

  y3_newFirmwareParam.CurDataBagNo = qY;
  y3_newFirmwareParam.boolBagNoHit = false;
  b_p = true;
  if (!(qY == x3_oldFirmwareParam.TargetDataBagNo)) {
    b_p = false;
  }

  if (b_p) {
    y3_newFirmwareParam.boolBagNoHit = true;
  }

  y3_newFirmwareParam.PrevCRC32Val = test2_SysIntegra_CalculateCRC32
    (x3_oldFirmwareParam.PrevCRC32Val, x3_OneBagData,
     x3_oldFirmwareParam.CurDataBagBytes);
  b_p = false;
  d_p = true;
  if (!(y3_newFirmwareParam.PrevCRC32Val == x3_oldFirmwareParam.TargetCRC32Val))
  {
    d_p = false;
  }

  if (d_p) {
    b_p = true;
  }

  y3_newFirmwareParam.boolCRC32Hit = b_p;
  return y3_newFirmwareParam;
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysIntegratio_VarUpdate_p(const type_SysVars *xx_varSet,
  type_FirmwareCtrlParam *xx_FirmwareParam, uint8_T xx_majorId, uint8_T
  xx_minorId, const uint8_T xx_data[132], type_SysVars *yy_varSet)
{
  int32_T i;
  uint16_T y_Uint16;
  uint16_T b_y_Uint16;
  uint16_T c_y_Uint16;
  uint16_T d_y_Uint16;
  int32_T b[8];
  uint8_T xx_data_0[4];
  *yy_varSet = *xx_varSet;
  switch (xx_majorId) {
   case 1:
    switch (xx_minorId) {
     case 1:
      yy_varSet->DoseCtrl.DoseCtrlParam.Concentration = xx_data[0];
      yy_varSet->DoseCtrl.DoseCtrlParam.LowDoseTHValue = xx_data[1];
      yy_varSet->DoseCtrl.DoseCtrlParam.MaxLargeDose =
        test2_SysI_TransTwoBytes2Uint16(&xx_data[2]);
      yy_varSet->DoseCtrl.DoseCtrlParam.MaxBaseRate =
        test2_SysI_TransTwoBytes2Uint16(&xx_data[4]);
      yy_varSet->DoseCtrl.DoseCtrlParam.MaxDailyDose = xx_data[6];
      break;

     case 2:
      for (i = 0; i < 48; i++) {
        yy_varSet->DoseCtrl.BaseRateConfig[i] = xx_data[i];
      }
      break;

     case 3:
      for (i = 0; i < 48; i++) {
        yy_varSet->DoseCtrl.TempBaseRateConfig[i] = xx_data[i];
      }
      break;

     case 4:
      yy_varSet->DoseCtrl.LastTBRConfigDay[0] = xx_data[0];
      yy_varSet->DoseCtrl.LastTBRConfigDay[1] = xx_data[1];
      yy_varSet->DoseCtrl.LastTBRConfigDay[2] = xx_data[2];
      break;

     case 5:
      yy_varSet->DoseCtrl.LargeDoseConfig.LargeDoseTotalAmount =
        test2_Sy_TransTwoBytes2Uint16_p(&xx_data[0]);
      yy_varSet->DoseCtrl.LargeDoseConfig.DeliveryConfig = xx_data[2];
      yy_varSet->DoseCtrl.LargeDoseConfig.PermittedTime = xx_data[3];
      yy_varSet->DoseCtrl.LargeDoseConfig.RegularDose4DWMCase =
        test2_SysI_TransTwoBytes2Uint16(&xx_data[4]);
      yy_varSet->DoseCtrl.LargeDoseConfig.EffectiveDay =
        test2_SysI_TransTwoBytes2Uint16(&xx_data[6]);
      for (i = 0; i < 20; i++) {
        yy_varSet->DoseCtrl.LargeDoseConfig.CustomTimeConfig[i] = xx_data[8 + i];
        yy_varSet->DoseCtrl.LargeDoseConfig.CustomDoseConfig[i] = xx_data[28 + i];
      }
      break;
    }
    break;

   case 2:
    switch (xx_minorId) {
     case 1:
      yy_varSet->ActCtrl.IniLoadedVol = xx_data[0];
      yy_varSet->ActCtrl.DailyDoseStatVar.ResidueDoseEst = 100U * xx_data[0] *
        xx_varSet->DoseCtrl.DoseCtrlParam.Concentration;
      break;

     case 2:
      yy_varSet->ActCtrl.AdjustInputGain = test2_SysI_TransTwoBytes2Uint16
        (&xx_data[0]);
      yy_varSet->ActCtrl.AdjustPositiveOffset = test2_SysI_TransTwoBytes2Uint16(
        &xx_data[2]);
      yy_varSet->ActCtrl.AdjustNegativeOffset = test2_SysI_TransTwoBytes2Uint16(
        &xx_data[4]);
      break;

     case 3:
      yy_varSet->ActCtrl.DeliverSwitch = xx_data[0];
      break;

     case 4:
      yy_varSet->ActCtrl.BaseRateDynVar.TargetDose =
        test2_SysInt_Trans4Bytes2Uint32(&xx_data[0]);
      yy_varSet->ActCtrl.BaseRateDynVar.TimeInfo =
        test2_SysI_TransTwoBytes2Uint16(&xx_data[4]);
      yy_varSet->ActCtrl.BaseRateDynVar.CompleteDose =
        test2_SysInt_Trans4Bytes2Uint32(&xx_data[6]);
      break;

     case 5:
      yy_varSet->ActCtrl.LargeDoseDynVar.TargetDose =
        test2_SysInt_Trans4Bytes2Uint32(&xx_data[0]);
      yy_varSet->ActCtrl.LargeDoseDynVar.TimeInfo = (uint16_T)((xx_data[5] << 8)
        + xx_data[4]);
      yy_varSet->ActCtrl.LargeDoseDynVar.CompleteDose =
        test2_SysInt_Trans4Bytes2Uint32(&xx_data[6]);
      break;

     case 6:
      yy_varSet->ActCtrl.DailyDoseStatVar.DayInfo = xx_data[0];
      yy_varSet->ActCtrl.DailyDoseStatVar.ResidueDoseEst =
        test2_SysInt_Trans4Bytes2Uint32(&xx_data[1]);
      yy_varSet->ActCtrl.DailyDoseStatVar.TotalAmountAcc =
        test2_SysInt_Trans4Bytes2Uint32(&xx_data[5]);
      yy_varSet->ActCtrl.DailyDoseStatVar.DailyAmountAcc =
        test2_SysInt_Trans4Bytes2Uint32(&xx_data[9]);
      yy_varSet->ActCtrl.DailyDoseStatVar.LargeAmountAcc =
        test2_SysInt_Trans4Bytes2Uint32(&xx_data[13]);
      break;
    }
    break;

   case 3:
    switch (xx_minorId) {
     case 1:
      yy_varSet->AlarmCtrl.AlarmCtrlConfig = xx_data[0];
      break;

     case 2:
      test2_Sy_Transfer32ByteTo8Int32(&xx_data[0], b);
      for (i = 0; i < 8; i++) {
        yy_varSet->AlarmCtrl.SSCurAndProcTimeCritPolyFitVect[i] = b[i];
      }
      break;
    }
    break;

   case 4:
    switch (xx_minorId) {
     case 1:
      yy_varSet->Firmware.FirmwareSize = test2_SysInt_Trans4Bytes2Uint32
        (&xx_data[0]);
      yy_varSet->Firmware.FirmwareCRC32 = test2_SysInt_Trans4Bytes2Uint32
        (&xx_data[4]);
      yy_varSet->Firmware.FirmwareUpgradeCompleteFlag = 5U;
      xx_FirmwareParam->TargetDataBagNo = yy_varSet->Firmware.FirmwareSize;
      xx_FirmwareParam->TargetCRC32Val = yy_varSet->Firmware.FirmwareCRC32;
      xx_FirmwareParam->boolGetHead = true;
      break;

     case 2:
      yy_varSet->Firmware.FirmwareUpgradeCompleteFlag = 4U;
      *xx_FirmwareParam = test2_SysIn_UpdateFirmwareParam(*xx_FirmwareParam,
        xx_data);
      if (xx_FirmwareParam->boolCRC32Hit) {
        yy_varSet->Firmware.FirmwareUpgradeCompleteFlag = 1U;
      } else {
        if (xx_FirmwareParam->boolBagNoHit) {
          yy_varSet->Firmware.FirmwareUpgradeCompleteFlag = 2U;
        }
      }
      break;
    }
    break;

   case 5:
    switch (xx_minorId) {
     case 1:
      yy_varSet->SysSetting.SensitivityLevel = xx_data[0];
      break;

     case 2:
      for (i = 0; i < 10; i++) {
        yy_varSet->SysSetting.SerialNo[i] = xx_data[i];
      }
      break;

     case 3:
      for (i = 0; i < 6; i++) {
        yy_varSet->SysSetting.SoftwareVersionInfo[i] = xx_data[i];
      }
      break;

     case 4:
      yy_varSet->SysSetting.HardwareVersionInfo[0] = xx_data[0];
      yy_varSet->SysSetting.HardwareVersionInfo[1] = xx_data[1];
      yy_varSet->SysSetting.HardwareVersionInfo[2] = xx_data[2];
      break;

     case 5:
      yy_varSet->SysSetting.FlashConfigFlag = xx_data[0];
      break;
    }
    break;

   case 6:
    for (i = 0; i < 33; i++) {
      switch (xx_minorId) {
       case 1:
        xx_data_0[0] = xx_data[i << 2];
        xx_data_0[1] = xx_data[(i << 2) + 1];
        xx_data_0[2] = xx_data[(i << 2) + 2];
        xx_data_0[3] = xx_data[(i << 2) + 3];
        yy_varSet->Occlusion.PT[i] = test2_SysInt_Trans4Bytes2Uint32(xx_data_0);
        break;

       case 2:
        xx_data_0[0] = xx_data[i << 2];
        xx_data_0[1] = xx_data[(i << 2) + 1];
        xx_data_0[2] = xx_data[(i << 2) + 2];
        xx_data_0[3] = xx_data[(i << 2) + 3];
        yy_varSet->Occlusion.PT[33 + i] = test2_SysInt_Trans4Bytes2Uint32
          (xx_data_0);
        break;

       case 3:
        xx_data_0[0] = xx_data[i << 2];
        xx_data_0[1] = xx_data[(i << 2) + 1];
        xx_data_0[2] = xx_data[(i << 2) + 2];
        xx_data_0[3] = xx_data[(i << 2) + 3];
        yy_varSet->Occlusion.PT[66 + i] = test2_SysInt_Trans4Bytes2Uint32
          (xx_data_0);
        break;

       case 4:
        xx_data_0[0] = xx_data[i << 2];
        xx_data_0[1] = xx_data[(i << 2) + 1];
        xx_data_0[2] = xx_data[(i << 2) + 2];
        xx_data_0[3] = xx_data[(i << 2) + 3];
        yy_varSet->Occlusion.CI[i] = test2_SysInt_Trans4Bytes2Uint32(xx_data_0);
        break;

       case 5:
        xx_data_0[0] = xx_data[i << 2];
        xx_data_0[1] = xx_data[(i << 2) + 1];
        xx_data_0[2] = xx_data[(i << 2) + 2];
        xx_data_0[3] = xx_data[(i << 2) + 3];
        yy_varSet->Occlusion.CI[33 + i] = test2_SysInt_Trans4Bytes2Uint32
          (xx_data_0);
        break;

       case 6:
        xx_data_0[0] = xx_data[i << 2];
        xx_data_0[1] = xx_data[(i << 2) + 1];
        xx_data_0[2] = xx_data[(i << 2) + 2];
        xx_data_0[3] = xx_data[(i << 2) + 3];
        yy_varSet->Occlusion.CI[66 + i] = test2_SysInt_Trans4Bytes2Uint32
          (xx_data_0);
        break;
      }
    }
    break;

   case 7:
    if (xx_minorId == 1) {
      yy_varSet->Calibra.MajorMcu4ChADCResolution[0] =
        test2_SysInt_Trans4Bytes2Uint32(&xx_data[0]);
      yy_varSet->Calibra.MajorMcu4ChADCResolution[1] =
        test2_SysInt_Trans4Bytes2Uint32(&xx_data[4]);
      yy_varSet->Calibra.MajorMcu4ChADCResolution[2] = ((((uint32_T)xx_data[9] <<
        8U) + xx_data[8]) + ((uint32_T)xx_data[10] << 16U)) + ((uint32_T)
        xx_data[11] << 24U);
      yy_varSet->Calibra.MajorMcu4ChADCResolution[3] = ((((uint32_T)xx_data[13] <<
        8U) + xx_data[12]) + ((uint32_T)xx_data[14] << 16U)) + ((uint32_T)
        xx_data[15] << 24U);
      yy_varSet->Calibra.MinorMcu4ChADCResolution[0] = ((((uint32_T)xx_data[17] <<
        8U) + xx_data[16]) + ((uint32_T)xx_data[18] << 16U)) + ((uint32_T)
        xx_data[19] << 24U);
      yy_varSet->Calibra.MinorMcu4ChADCResolution[1] = ((((uint32_T)xx_data[21] <<
        8U) + xx_data[20]) + ((uint32_T)xx_data[22] << 16U)) + ((uint32_T)
        xx_data[23] << 24U);
      yy_varSet->Calibra.MinorMcu4ChADCResolution[2] = ((((uint32_T)xx_data[25] <<
        8U) + xx_data[24]) + ((uint32_T)xx_data[26] << 16U)) + ((uint32_T)
        xx_data[27] << 24U);
      yy_varSet->Calibra.MinorMcu4ChADCResolution[3] = ((((uint32_T)xx_data[29] <<
        8U) + xx_data[28]) + ((uint32_T)xx_data[30] << 16U)) + ((uint32_T)
        xx_data[31] << 24U);
      y_Uint16 = (uint16_T)((xx_data[33] << 8) + xx_data[32]);
      b_y_Uint16 = (uint16_T)((xx_data[35] << 8) + xx_data[34]);
      c_y_Uint16 = (uint16_T)((xx_data[37] << 8) + xx_data[36]);
      d_y_Uint16 = (uint16_T)((xx_data[39] << 8) + xx_data[38]);
      if (y_Uint16 >= 32768) {
        yy_varSet->Calibra.MajorMCU4ChADCOffset[0] = (int16_T)(y_Uint16 - 65536);
      } else {
        yy_varSet->Calibra.MajorMCU4ChADCOffset[0] = (int16_T)y_Uint16;
      }

      if (b_y_Uint16 >= 32768) {
        yy_varSet->Calibra.MajorMCU4ChADCOffset[1] = (int16_T)(b_y_Uint16 -
          65536);
      } else {
        yy_varSet->Calibra.MajorMCU4ChADCOffset[1] = (int16_T)b_y_Uint16;
      }

      if (c_y_Uint16 >= 32768) {
        yy_varSet->Calibra.MajorMCU4ChADCOffset[2] = (int16_T)(c_y_Uint16 -
          65536);
      } else {
        yy_varSet->Calibra.MajorMCU4ChADCOffset[2] = (int16_T)c_y_Uint16;
      }

      if (d_y_Uint16 >= 32768) {
        yy_varSet->Calibra.MajorMCU4ChADCOffset[3] = (int16_T)(d_y_Uint16 -
          65536);
      } else {
        yy_varSet->Calibra.MajorMCU4ChADCOffset[3] = (int16_T)d_y_Uint16;
      }

      y_Uint16 = (uint16_T)((xx_data[41] << 8) + xx_data[40]);
      b_y_Uint16 = (uint16_T)((xx_data[43] << 8) + xx_data[42]);
      c_y_Uint16 = (uint16_T)((xx_data[45] << 8) + xx_data[44]);
      d_y_Uint16 = (uint16_T)((xx_data[47] << 8) + xx_data[46]);
      if (y_Uint16 >= 32768) {
        yy_varSet->Calibra.MinorMCU4ChADCOffset[0] = (int16_T)(y_Uint16 - 65536);
      } else {
        yy_varSet->Calibra.MinorMCU4ChADCOffset[0] = (int16_T)y_Uint16;
      }

      if (b_y_Uint16 >= 32768) {
        yy_varSet->Calibra.MinorMCU4ChADCOffset[1] = (int16_T)(b_y_Uint16 -
          65536);
      } else {
        yy_varSet->Calibra.MinorMCU4ChADCOffset[1] = (int16_T)b_y_Uint16;
      }

      if (c_y_Uint16 >= 32768) {
        yy_varSet->Calibra.MinorMCU4ChADCOffset[2] = (int16_T)(c_y_Uint16 -
          65536);
      } else {
        yy_varSet->Calibra.MinorMCU4ChADCOffset[2] = (int16_T)c_y_Uint16;
      }

      if (d_y_Uint16 >= 32768) {
        yy_varSet->Calibra.MinorMCU4ChADCOffset[3] = (int16_T)(d_y_Uint16 -
          65536);
      } else {
        yy_varSet->Calibra.MinorMCU4ChADCOffset[3] = (int16_T)d_y_Uint16;
      }
    }
    break;
  }
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysInt_Var0104Write2Flash(uint8_T x_MajorId, uint8_T x_MinorId,
  uint8_T x_Data[3], uint8_T x_Channel, const type_SysVars *x_VarSet, const
  type_FirmwareCtrlParam x_FirmwareParam, boolean_T *y_FlashAccessErr, uint8_T
  *y_Channel, type_SysVars *y_VarSet, type_FirmwareCtrlParam *y_FirmwareParam)
{
  uint8_T trimLength;
  uint8_T new_x_MajorId;
  uint8_T new_x_MinorId;
  boolean_T p;
  boolean_T b_p;
  int32_T tmp;
  *y_Channel = x_Channel;
  p = false;
  b_p = true;
  if (!(x_MajorId == 4)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (p && (x_MinorId > 100)) {
    tmp = (int32_T)(x_FirmwareParam.CurDataBagBytes + 4U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    trimLength = (uint8_T)tmp;
    new_x_MajorId = x_MajorId;
    new_x_MinorId = 2U;
  } else {
    p = false;
    b_p = true;
    if (!(x_MajorId == 1)) {
      b_p = false;
    }

    if (b_p) {
      p = true;
    }

    if (p && (x_MinorId >= 10) && (x_MinorId < 42)) {
      new_x_MajorId = x_MajorId;
      new_x_MinorId = 3U;
      trimLength = test2_SysIntegration_B.VarSizeInfo[x_MajorId + 13];
    } else if ((x_MinorId <= 6) && (x_MajorId <= 7)) {
      trimLength = test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 +
        x_MajorId) - 1];
      new_x_MinorId = x_MinorId;
      new_x_MajorId = x_MajorId;
    } else {
      trimLength = 1U;
      new_x_MinorId = 0U;
      new_x_MajorId = 0U;
    }
  }

  *y_FlashAccessErr = dataWrite(new_x_MajorId, new_x_MinorId, x_Data, trimLength,
    x_Channel);
  *y_FirmwareParam = x_FirmwareParam;
  test2_SysIntegratio_VarUpdate_p(x_VarSet, y_FirmwareParam, new_x_MajorId,
    new_x_MinorId, &x_Data[0], y_VarSet);
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysIntegration_VarUpdate(type_SysVars *xx_varSet, const
  uint8_T xx_data[132])
{
  xx_varSet->SysSetting.FlashConfigFlag = xx_data[0];
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysIntegra_VarWrite2Flash(uint8_T x_Data, uint8_T x_Channel,
  const type_SysVars *x_VarSet, const type_FirmwareCtrlParam x_FirmwareParam,
  boolean_T *y_FlashAccessErr, uint8_T *y_Channel, type_SysVars *y_VarSet,
  type_FirmwareCtrlParam *y_FirmwareParam)
{
  uint8_T x_Data_0[132];
  int32_T i;
  *y_Channel = x_Channel;
  *y_FlashAccessErr = dataWrite(5, 5, &x_Data,
    test2_SysIntegration_B.VarSizeInfo[32], x_Channel);
  *y_VarSet = *x_VarSet;
  *y_FirmwareParam = x_FirmwareParam;
  for (i = 0; i < 132; i++) {
    x_Data_0[i] = x_Data;
  }

  test2_SysIntegration_VarUpdate(y_VarSet, x_Data_0);
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysInteg_VarWrite2Flash_a(uint8_T x_MajorId, uint8_T x_MinorId,
  uint8_T x_Data[132], uint8_T x_Channel, const type_SysVars *x_VarSet, const
  type_FirmwareCtrlParam x_FirmwareParam, boolean_T *y_FlashAccessErr, uint8_T
  *y_Channel, type_SysVars *y_VarSet, type_FirmwareCtrlParam *y_FirmwareParam)
{
  uint8_T trimLength;
  uint8_T new_x_MajorId;
  uint8_T new_x_MinorId;
  boolean_T p;
  boolean_T b_p;
  int32_T tmp;
  *y_Channel = x_Channel;
  p = false;
  b_p = true;
  if (!(x_MajorId == 4)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (p && (x_MinorId > 100)) {
    tmp = (int32_T)(x_FirmwareParam.CurDataBagBytes + 4U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    trimLength = (uint8_T)tmp;
    new_x_MajorId = x_MajorId;
    new_x_MinorId = 2U;
  } else {
    p = false;
    b_p = true;
    if (!(x_MajorId == 1)) {
      b_p = false;
    }

    if (b_p) {
      p = true;
    }

    if (p && (x_MinorId >= 10) && (x_MinorId < 42)) {
      new_x_MajorId = x_MajorId;
      new_x_MinorId = 3U;
      trimLength = test2_SysIntegration_B.VarSizeInfo[x_MajorId + 13];
    } else if ((x_MinorId <= 6) && (x_MajorId <= 7)) {
      trimLength = test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 +
        x_MajorId) - 1];
      new_x_MinorId = x_MinorId;
      new_x_MajorId = x_MajorId;
    } else {
      trimLength = 1U;
      new_x_MinorId = 0U;
      new_x_MajorId = 0U;
    }
  }

  *y_FlashAccessErr = dataWrite(new_x_MajorId, new_x_MinorId, x_Data, trimLength,
    x_Channel);
  *y_FirmwareParam = x_FirmwareParam;
  test2_SysIntegratio_VarUpdate_p(x_VarSet, y_FirmwareParam, new_x_MajorId,
    new_x_MinorId, x_Data, y_VarSet);
}

/* Function for Chart: '<S63>/Chart' */
static boolean_T test2_SysIntegration_isequal(uint8_T varargin_1, uint8_T
  varargin_2)
{
  boolean_T p;
  boolean_T b_p;
  p = false;
  b_p = true;
  if (!(varargin_1 == varargin_2)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  return p;
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysInt_LogSyncWriteAction(uint8_T x_MajorId, uint8_T x_MinorId,
  boolean_T *y_boolLogSyncAction, uint8_T *y_LogWriteMajorId, uint8_T
  *y_LogWriteMinorId)
{
  boolean_T p;
  boolean_T b_p;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  boolean_T guard8 = false;
  boolean_T guard9 = false;
  if (test2_SysIntegration_isequal(x_MajorId, 1) && test2_SysIntegration_isequal
      (x_MinorId, 1)) {
    *y_boolLogSyncAction = true;
    *y_LogWriteMajorId = 3U;
    *y_LogWriteMinorId = 3U;
  } else {
    p = false;
    b_p = true;
    if (!(x_MajorId == 1)) {
      b_p = false;
    }

    if (b_p) {
      p = true;
    }

    guard1 = false;
    guard2 = false;
    guard3 = false;
    guard4 = false;
    guard5 = false;
    guard6 = false;
    guard7 = false;
    guard8 = false;
    guard9 = false;
    if (p) {
      p = false;
      b_p = true;
      if (!(x_MinorId == 2)) {
        b_p = false;
      }

      if (b_p) {
        p = true;
      }

      if (p) {
        *y_boolLogSyncAction = true;
        *y_LogWriteMajorId = 4U;
        *y_LogWriteMinorId = 1U;
      } else {
        guard9 = true;
      }
    } else {
      guard9 = true;
    }

    if (guard9) {
      p = false;
      b_p = true;
      if (!(x_MajorId == 1)) {
        b_p = false;
      }

      if (b_p) {
        p = true;
      }

      if (p) {
        p = false;
        b_p = true;
        if (!(x_MinorId == 3)) {
          b_p = false;
        }

        if (b_p) {
          p = true;
        }

        if (p) {
          *y_boolLogSyncAction = true;
          *y_LogWriteMajorId = 4U;
          *y_LogWriteMinorId = 2U;
        } else {
          guard8 = true;
        }
      } else {
        guard8 = true;
      }
    }

    if (guard8) {
      p = false;
      b_p = true;
      if (!(x_MajorId == 1)) {
        b_p = false;
      }

      if (b_p) {
        p = true;
      }

      if (p) {
        p = false;
        b_p = true;
        if (!(x_MinorId == 5)) {
          b_p = false;
        }

        if (b_p) {
          p = true;
        }

        if (p) {
          *y_boolLogSyncAction = true;
          *y_LogWriteMajorId = 1U;
          *y_LogWriteMinorId = 1U;
        } else {
          guard7 = true;
        }
      } else {
        guard7 = true;
      }
    }

    if (guard7) {
      p = false;
      b_p = true;
      if (!(x_MajorId == 2)) {
        b_p = false;
      }

      if (b_p) {
        p = true;
      }

      if (p) {
        p = false;
        b_p = true;
        if (!(x_MinorId == 1)) {
          b_p = false;
        }

        if (b_p) {
          p = true;
        }

        if (p) {
          *y_boolLogSyncAction = true;
          *y_LogWriteMajorId = 3U;
          *y_LogWriteMinorId = 4U;
        } else {
          guard6 = true;
        }
      } else {
        guard6 = true;
      }
    }

    if (guard6) {
      p = false;
      b_p = true;
      if (!(x_MajorId == 2)) {
        b_p = false;
      }

      if (b_p) {
        p = true;
      }

      if (p) {
        p = false;
        b_p = true;
        if (!(x_MinorId == 3)) {
          b_p = false;
        }

        if (b_p) {
          p = true;
        }

        if (p) {
          *y_boolLogSyncAction = true;
          *y_LogWriteMajorId = 3U;
          *y_LogWriteMinorId = 2U;
        } else {
          guard5 = true;
        }
      } else {
        guard5 = true;
      }
    }

    if (guard5) {
      p = false;
      b_p = true;
      if (!(x_MajorId == 2)) {
        b_p = false;
      }

      if (b_p) {
        p = true;
      }

      if (p) {
        p = false;
        b_p = true;
        if (!(x_MinorId == 4)) {
          b_p = false;
        }

        if (b_p) {
          p = true;
        }

        if (p) {
          *y_boolLogSyncAction = true;
          *y_LogWriteMajorId = 1U;
          *y_LogWriteMinorId = 4U;
        } else {
          guard4 = true;
        }
      } else {
        guard4 = true;
      }
    }

    if (guard4) {
      p = false;
      b_p = true;
      if (!(x_MajorId == 2)) {
        b_p = false;
      }

      if (b_p) {
        p = true;
      }

      if (p) {
        p = false;
        b_p = true;
        if (!(x_MinorId == 5)) {
          b_p = false;
        }

        if (b_p) {
          p = true;
        }

        if (p) {
          *y_boolLogSyncAction = true;
          *y_LogWriteMajorId = 1U;
          *y_LogWriteMinorId = 2U;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }
    }

    if (guard3) {
      p = false;
      b_p = true;
      if (!(x_MajorId == 2)) {
        b_p = false;
      }

      if (b_p) {
        p = true;
      }

      if (p) {
        p = false;
        b_p = true;
        if (!(x_MinorId == 6)) {
          b_p = false;
        }

        if (b_p) {
          p = true;
        }

        if (p) {
          *y_boolLogSyncAction = true;
          *y_LogWriteMajorId = 1U;
          *y_LogWriteMinorId = 5U;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }
    }

    if (guard2) {
      p = false;
      b_p = true;
      if (!(x_MajorId == 4)) {
        b_p = false;
      }

      if (b_p) {
        p = true;
      }

      if (p) {
        p = false;
        b_p = true;
        if (!(x_MinorId == 4)) {
          b_p = false;
        }

        if (b_p) {
          p = true;
        }

        if (p) {
          *y_boolLogSyncAction = true;
          *y_LogWriteMajorId = 3U;
          *y_LogWriteMinorId = 5U;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    }

    if (guard1) {
      *y_boolLogSyncAction = false;
      *y_LogWriteMajorId = 0U;
      *y_LogWriteMinorId = 0U;
    }
  }
}

/* Function for Chart: '<S63>/Chart' */
static boolean_T test2_SysIntegratio_VarFlashClr(uint8_T x_Channel)
{
  return dataErase(x_Channel);
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysIntegratio_VarClrStep1(const type_SysVars *x_VarSet,
  uint16_T *y_Var2BeKept_sub1, uint16_T *y_Var2BeKept_sub2, uint16_T
  *y_Var2BeKept_sub3, int32_T y_Var2BeKept_sub4[8], uint8_T y_Var2BeKept_sub5[10],
  uint8_T y_Var2BeKept_sub6[3], uint32_T y_Var2BeKept_sub7[4], uint32_T
  y_Var2BeKept_sub8[4], int16_T y_Var2BeKept_sub9[4], int16_T
  y_Var2BeKept_sub10[4])
{
  int32_T i;
  *y_Var2BeKept_sub1 = x_VarSet->ActCtrl.AdjustInputGain;
  *y_Var2BeKept_sub2 = x_VarSet->ActCtrl.AdjustPositiveOffset;
  *y_Var2BeKept_sub3 = x_VarSet->ActCtrl.AdjustNegativeOffset;
  for (i = 0; i < 8; i++) {
    y_Var2BeKept_sub4[i] = x_VarSet->AlarmCtrl.SSCurAndProcTimeCritPolyFitVect[i];
  }

  for (i = 0; i < 10; i++) {
    y_Var2BeKept_sub5[i] = x_VarSet->SysSetting.SerialNo[i];
  }

  y_Var2BeKept_sub6[0] = x_VarSet->SysSetting.HardwareVersionInfo[0];
  y_Var2BeKept_sub6[1] = x_VarSet->SysSetting.HardwareVersionInfo[1];
  y_Var2BeKept_sub6[2] = x_VarSet->SysSetting.HardwareVersionInfo[2];
  y_Var2BeKept_sub7[0] = x_VarSet->Calibra.MajorMcu4ChADCResolution[0];
  y_Var2BeKept_sub8[0] = x_VarSet->Calibra.MinorMcu4ChADCResolution[0];
  y_Var2BeKept_sub9[0] = x_VarSet->Calibra.MajorMCU4ChADCOffset[0];
  y_Var2BeKept_sub10[0] = x_VarSet->Calibra.MinorMCU4ChADCOffset[0];
  y_Var2BeKept_sub7[1] = x_VarSet->Calibra.MajorMcu4ChADCResolution[1];
  y_Var2BeKept_sub8[1] = x_VarSet->Calibra.MinorMcu4ChADCResolution[1];
  y_Var2BeKept_sub9[1] = x_VarSet->Calibra.MajorMCU4ChADCOffset[1];
  y_Var2BeKept_sub10[1] = x_VarSet->Calibra.MinorMCU4ChADCOffset[1];
  y_Var2BeKept_sub7[2] = x_VarSet->Calibra.MajorMcu4ChADCResolution[2];
  y_Var2BeKept_sub8[2] = x_VarSet->Calibra.MinorMcu4ChADCResolution[2];
  y_Var2BeKept_sub9[2] = x_VarSet->Calibra.MajorMCU4ChADCOffset[2];
  y_Var2BeKept_sub10[2] = x_VarSet->Calibra.MinorMCU4ChADCOffset[2];
  y_Var2BeKept_sub7[3] = x_VarSet->Calibra.MajorMcu4ChADCResolution[3];
  y_Var2BeKept_sub8[3] = x_VarSet->Calibra.MinorMcu4ChADCResolution[3];
  y_Var2BeKept_sub9[3] = x_VarSet->Calibra.MajorMCU4ChADCOffset[3];
  y_Var2BeKept_sub10[3] = x_VarSet->Calibra.MinorMCU4ChADCOffset[3];
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysInteg_exit_atomic_Idle(void)
{
  static const type_SysVars b = { { { 100U,/* Concentration */
        5U,                            /* LowDoseTHValue */
        480U,                          /* MaxLargeDose */
        240U,                          /* MaxBaseRate */
        80U                            /* MaxDailyDose */
      },                               /* DoseCtrlParam */
      { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },/* BaseRateConfig */
      { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },/* TempBaseRateConfig */
      { 0U, 0U, 0U },                  /* LastTBRConfigDay */
      { 0U,                            /* LargeDoseTotalAmount */
        0U,                            /* DeliveryConfig */
        15U,                           /* PermittedTime */
        0U,                            /* RegularDose4DWMCase */
        0U,                            /* EffectiveDay */
        { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U },                    /* CustomTimeConfig */
        { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
          0U, 0U }                     /* CustomDoseConfig */
      }                                /* LargeDoseConfig */
    },                                 /* DoseCtrl */
    { 30U,                             /* IniLoadedVol */
      1000U,                           /* AdjustInputGain */
      0U,                              /* AdjustPositiveOffset */
      0U,                              /* AdjustNegativeOffset */
      0U,                              /* DeliverSwitch */
      { 0U,                            /* TargetDose */
        0U,                            /* TimeInfo */
        0U                             /* CompleteDose */
      },                               /* BaseRateDynVar */
      { 0U,                            /* TargetDose */
        0U,                            /* TimeInfo */
        0U                             /* CompleteDose */
      },                               /* LargeDoseDynVar */
      { 0U,                            /* DayInfo */
        MAX_uint32_T,                  /* ResidueDoseEst */
        0U,                            /* TotalAmountAcc */
        0U,                            /* DailyAmountAcc */
        0U                             /* LargeAmountAcc */
      }                                /* DailyDoseStatVar */
    },                                 /* ActCtrl */
    { 0U,                              /* AlarmCtrlConfig */
      { MAX_int32_T, MAX_int32_T, MAX_int32_T, MAX_int32_T, MAX_int32_T,
        MAX_int32_T, MAX_int32_T, MAX_int32_T }/* SSCurAndProcTimeCritPolyFitVect */
    },                                 /* AlarmCtrl */
    { MAX_uint32_T,                    /* FirmwareSize */
      0U,                              /* FirmwareCRC32 */
      0U                               /* FirmwareUpgradeCompleteFlag */
    },                                 /* Firmware */
    { 3U,                              /* SensitivityLevel */
      { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },/* SerialNo */
      { 20U, 1U, 0U, 20U, 1U, 0U },    /* SoftwareVersionInfo */
      { 0U, 0U, 0U },                  /* HardwareVersionInfo */
      187U                             /* FlashConfigFlag */
    },                                 /* SysSetting */
    { { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },/* PT */
      { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }/* CI */
    },                                 /* Occlusion */
    { { 0U, 0U, 0U, 0U },              /* MajorMcu4ChADCResolution */
      { 0U, 0U, 0U, 0U },              /* MinorMcu4ChADCResolution */
      { 0, 0, 0, 0 },                  /* MajorMCU4ChADCOffset */
      { 0, 0, 0, 0 }                   /* MinorMCU4ChADCOffset */
    }                                  /* Calibra */
  };

  test2_SysIntegration_DW.bitsForTID4.FlashAccessErr =
    test2_SysIntegratio_VarFlashClr(test2_SysIntegration_DW.Channel);
  test2_SysIntegratio_VarClrStep1(&test2_SysIntegration_B.VarSet,
    &test2_SysIntegration_DW.temp_Var2BeKept1,
    &test2_SysIntegration_DW.temp_Var2BeKept2,
    &test2_SysIntegration_DW.temp_Var2BeKept3,
    test2_SysIntegration_DW.temp_Var2BeKept4,
    test2_SysIntegration_DW.temp_Var2BeKept5,
    test2_SysIntegration_DW.temp_Var2BeKept6,
    test2_SysIntegration_DW.temp_Var2BeKept7,
    test2_SysIntegration_DW.temp_Var2BeKept8,
    test2_SysIntegration_DW.temp_Var2BeKept9,
    test2_SysIntegration_DW.temp_Var2BeKept10);
  test2_SysIntegration_B.VarSet = b;
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysI_Trans8Int32To32Bytes(const int32_T x_8Int32[8], uint8_T
  y_32Bytes[32])
{
  int32_T i;
  uint32_T y_Target;
  int32_T tmp;
  for (i = 0; i < 8; i++) {
    if (x_8Int32[i] >= 0) {
      tmp = x_8Int32[i];
      if (x_8Int32[i] < 0) {
        tmp = 0;
      }

      y_Target = (uint32_T)tmp;
    } else if ((real_T)x_8Int32[i] + 4.294967296E+9 < 4.294967296E+9) {
      y_Target = (uint32_T)((real_T)x_8Int32[i] + 4.294967296E+9);
    } else {
      y_Target = MAX_uint32_T;
    }

    y_32Bytes[i << 2] = (uint8_T)(y_Target & 255U);
    y_32Bytes[(i << 2) + 1] = (uint8_T)((y_Target & 65280U) >> 8U);
    y_32Bytes[(i << 2) + 2] = (uint8_T)((y_Target & 16711680U) >> 16U);
    y_32Bytes[(i << 2) + 3] = (uint8_T)((y_Target & 4278190080U) >> 24U);
  }
}

/* Function for Chart: '<S63>/Chart' */
static uint16_T test2_SysIntegrati_TransformInt(int16_T x_Obj)
{
  uint16_T y_Target;
  if (x_Obj >= 0) {
    y_Target = (uint16_T)x_Obj;
  } else {
    y_Target = (uint16_T)(x_Obj + 65536);
  }

  return y_Target;
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysInte_VarWrite2Flash_ag(uint8_T x_MajorId, uint8_T x_MinorId,
  uint8_T x_Data[48], uint8_T x_Channel, const type_SysVars *x_VarSet, const
  type_FirmwareCtrlParam x_FirmwareParam, boolean_T *y_FlashAccessErr, uint8_T
  *y_Channel, type_SysVars *y_VarSet, type_FirmwareCtrlParam *y_FirmwareParam)
{
  uint8_T trimLength;
  uint8_T new_x_MajorId;
  uint8_T new_x_MinorId;
  boolean_T p;
  boolean_T b_p;
  int32_T tmp;
  *y_Channel = x_Channel;
  p = false;
  b_p = true;
  if (!(x_MajorId == 4)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (p && (x_MinorId > 100)) {
    tmp = (int32_T)(x_FirmwareParam.CurDataBagBytes + 4U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    trimLength = (uint8_T)tmp;
    new_x_MajorId = x_MajorId;
    new_x_MinorId = 2U;
  } else {
    p = false;
    b_p = true;
    if (!(x_MajorId == 1)) {
      b_p = false;
    }

    if (b_p) {
      p = true;
    }

    if (p && (x_MinorId >= 10) && (x_MinorId < 42)) {
      new_x_MajorId = x_MajorId;
      new_x_MinorId = 3U;
      trimLength = test2_SysIntegration_B.VarSizeInfo[x_MajorId + 13];
    } else if ((x_MinorId <= 6) && (x_MajorId <= 7)) {
      trimLength = test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 +
        x_MajorId) - 1];
      new_x_MinorId = x_MinorId;
      new_x_MajorId = x_MajorId;
    } else {
      trimLength = 1U;
      new_x_MinorId = 0U;
      new_x_MajorId = 0U;
    }
  }

  *y_FlashAccessErr = dataWrite(new_x_MajorId, new_x_MinorId, x_Data, trimLength,
    x_Channel);
  *y_FirmwareParam = x_FirmwareParam;
  test2_SysIntegratio_VarUpdate_p(x_VarSet, y_FirmwareParam, new_x_MajorId,
    new_x_MinorId, &x_Data[0], y_VarSet);
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysIntegratio_VarClrStep2(type_SysVars *x_VarSet, uint8_T
  x_MajorId, uint8_T x_MinorId, uint16_T x_Var2BeKept_sub1, uint16_T
  x_Var2BeKept_sub2, uint16_T x_Var2BeKept_sub3, const int32_T
  x_Var2BeKept_sub4[8], const uint8_T x_Var2BeKept_sub5[10], const uint8_T
  x_Var2BeKept_sub6[3], const uint32_T x_Var2BeKept_sub7[4], const uint32_T
  x_Var2BeKept_sub8[4], const int16_T x_Var2BeKept_sub9[4], const int16_T
  x_Var2BeKept_sub10[4], uint8_T x_Channel, const type_FirmwareCtrlParam
  x_FirmwareParam)
{
  boolean_T unusedU0;
  uint8_T unusedU1;
  uint8_T Data132Byte[132];
  static const uint8_T b[132] = { 187U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U };

  type_FirmwareCtrlParam unusedU2;
  type_SysVars x_VarSet_0;
  uint8_T tmp[2];
  uint8_T tmp_0[2];
  uint8_T tmp_1[2];
  type_SysVars x_VarSet_1;
  type_SysVars x_VarSet_2;
  type_SysVars x_VarSet_3;
  type_SysVars x_VarSet_4;
  uint8_T tmp_2[4];
  uint8_T tmp_3[4];
  uint8_T tmp_4[4];
  uint8_T tmp_5[4];
  uint8_T tmp_6[4];
  uint8_T tmp_7[4];
  uint8_T tmp_8[4];
  uint8_T tmp_9[4];
  uint8_T tmp_a[2];
  uint8_T tmp_b[2];
  uint8_T tmp_c[2];
  uint8_T tmp_d[2];
  uint8_T tmp_e[2];
  uint8_T tmp_f[48];
  type_SysVars x_VarSet_5;
  int32_T i;
  switch (x_MajorId) {
   case 2:
    if (x_MinorId == 2) {
      memset(&Data132Byte[0], 0, 132U * sizeof(uint8_T));
      test2_SysInt_TransWord2TwoBytes(x_Var2BeKept_sub1, tmp);
      test2_SysInt_TransWord2TwoBytes(x_Var2BeKept_sub2, tmp_0);
      test2_SysInt_TransWord2TwoBytes(x_Var2BeKept_sub3, tmp_1);
      Data132Byte[0] = tmp[0];
      Data132Byte[2] = tmp_0[0];
      Data132Byte[4] = tmp_1[0];
      Data132Byte[1] = tmp[1];
      Data132Byte[3] = tmp_0[1];
      Data132Byte[5] = tmp_1[1];
      x_VarSet_0 = *x_VarSet;
      test2_SysInteg_VarWrite2Flash_a(x_MajorId, 2, Data132Byte, x_Channel,
        &x_VarSet_0, x_FirmwareParam, &unusedU0, &unusedU1, x_VarSet, &unusedU2);
    }
    break;

   case 3:
    if (x_MinorId == 2) {
      memset(&Data132Byte[0], 0, 132U * sizeof(uint8_T));
      test2_SysI_Trans8Int32To32Bytes(x_Var2BeKept_sub4, &Data132Byte[0]);
      x_VarSet_1 = *x_VarSet;
      test2_SysInteg_VarWrite2Flash_a(x_MajorId, 2, Data132Byte, x_Channel,
        &x_VarSet_1, x_FirmwareParam, &unusedU0, &unusedU1, x_VarSet, &unusedU2);
    }
    break;

   case 5:
    switch (x_MinorId) {
     case 2:
      memset(&Data132Byte[0], 0, 132U * sizeof(uint8_T));
      for (i = 0; i < 10; i++) {
        Data132Byte[i] = x_Var2BeKept_sub5[i];
      }

      x_VarSet_2 = *x_VarSet;
      test2_SysInteg_VarWrite2Flash_a(x_MajorId, x_MinorId, Data132Byte,
        x_Channel, &x_VarSet_2, x_FirmwareParam, &unusedU0, &unusedU1, x_VarSet,
        &unusedU2);
      break;

     case 4:
      memset(&Data132Byte[0], 0, 132U * sizeof(uint8_T));
      Data132Byte[0] = x_Var2BeKept_sub6[0];
      Data132Byte[1] = x_Var2BeKept_sub6[1];
      Data132Byte[2] = x_Var2BeKept_sub6[2];
      x_VarSet_3 = *x_VarSet;
      test2_SysInteg_VarWrite2Flash_a(x_MajorId, x_MinorId, Data132Byte,
        x_Channel, &x_VarSet_3, x_FirmwareParam, &unusedU0, &unusedU1, x_VarSet,
        &unusedU2);
      break;

     case 5:
      memcpy(&Data132Byte[0], &b[0], 132U * sizeof(uint8_T));
      x_VarSet_4 = *x_VarSet;
      test2_SysInteg_VarWrite2Flash_a(x_MajorId, x_MinorId, Data132Byte,
        x_Channel, &x_VarSet_4, x_FirmwareParam, &unusedU0, &unusedU1, x_VarSet,
        &unusedU2);
      break;
    }
    break;

   case 7:
    if (x_MinorId == 1) {
      test2_SysI_TransDWord2FourBytes(x_Var2BeKept_sub7[0], tmp_2);
      test2_SysI_TransDWord2FourBytes(x_Var2BeKept_sub7[1], tmp_3);
      test2_SysI_TransDWord2FourBytes(x_Var2BeKept_sub7[2], tmp_4);
      test2_SysI_TransDWord2FourBytes(x_Var2BeKept_sub7[3], tmp_5);
      test2_SysI_TransDWord2FourBytes(x_Var2BeKept_sub8[0], tmp_6);
      test2_SysI_TransDWord2FourBytes(x_Var2BeKept_sub8[1], tmp_7);
      test2_SysI_TransDWord2FourBytes(x_Var2BeKept_sub8[2], tmp_8);
      test2_SysI_TransDWord2FourBytes(x_Var2BeKept_sub8[3], tmp_9);
      test2_SysInt_TransWord2TwoBytes(test2_SysIntegrati_TransformInt
        (x_Var2BeKept_sub9[0]), tmp);
      test2_SysInt_TransWord2TwoBytes(test2_SysIntegrati_TransformInt
        (x_Var2BeKept_sub9[1]), tmp_0);
      test2_SysInt_TransWord2TwoBytes(test2_SysIntegrati_TransformInt
        (x_Var2BeKept_sub9[2]), tmp_1);
      test2_SysInt_TransWord2TwoBytes(test2_SysIntegrati_TransformInt
        (x_Var2BeKept_sub9[3]), tmp_a);
      test2_SysInt_TransWord2TwoBytes(test2_SysIntegrati_TransformInt
        (x_Var2BeKept_sub10[0]), tmp_b);
      test2_SysInt_TransWord2TwoBytes(test2_SysIntegrati_TransformInt
        (x_Var2BeKept_sub10[1]), tmp_c);
      test2_SysInt_TransWord2TwoBytes(test2_SysIntegrati_TransformInt
        (x_Var2BeKept_sub10[2]), tmp_d);
      test2_SysInt_TransWord2TwoBytes(test2_SysIntegrati_TransformInt
        (x_Var2BeKept_sub10[3]), tmp_e);
      tmp_f[0] = tmp_2[0];
      tmp_f[4] = tmp_3[0];
      tmp_f[8] = tmp_4[0];
      tmp_f[12] = tmp_5[0];
      tmp_f[16] = tmp_6[0];
      tmp_f[20] = tmp_7[0];
      tmp_f[24] = tmp_8[0];
      tmp_f[28] = tmp_9[0];
      tmp_f[1] = tmp_2[1];
      tmp_f[5] = tmp_3[1];
      tmp_f[9] = tmp_4[1];
      tmp_f[13] = tmp_5[1];
      tmp_f[17] = tmp_6[1];
      tmp_f[21] = tmp_7[1];
      tmp_f[25] = tmp_8[1];
      tmp_f[29] = tmp_9[1];
      tmp_f[2] = tmp_2[2];
      tmp_f[6] = tmp_3[2];
      tmp_f[10] = tmp_4[2];
      tmp_f[14] = tmp_5[2];
      tmp_f[18] = tmp_6[2];
      tmp_f[22] = tmp_7[2];
      tmp_f[26] = tmp_8[2];
      tmp_f[30] = tmp_9[2];
      tmp_f[3] = tmp_2[3];
      tmp_f[7] = tmp_3[3];
      tmp_f[11] = tmp_4[3];
      tmp_f[15] = tmp_5[3];
      tmp_f[19] = tmp_6[3];
      tmp_f[23] = tmp_7[3];
      tmp_f[27] = tmp_8[3];
      tmp_f[31] = tmp_9[3];
      tmp_f[32] = tmp[0];
      tmp_f[34] = tmp_0[0];
      tmp_f[36] = tmp_1[0];
      tmp_f[38] = tmp_a[0];
      tmp_f[40] = tmp_b[0];
      tmp_f[42] = tmp_c[0];
      tmp_f[44] = tmp_d[0];
      tmp_f[46] = tmp_e[0];
      tmp_f[33] = tmp[1];
      tmp_f[35] = tmp_0[1];
      tmp_f[37] = tmp_1[1];
      tmp_f[39] = tmp_a[1];
      tmp_f[41] = tmp_b[1];
      tmp_f[43] = tmp_c[1];
      tmp_f[45] = tmp_d[1];
      tmp_f[47] = tmp_e[1];
      x_VarSet_5 = *x_VarSet;
      test2_SysInte_VarWrite2Flash_ag(x_MajorId, 1, tmp_f, x_Channel,
        &x_VarSet_5, x_FirmwareParam, &unusedU0, &unusedU1, x_VarSet, &unusedU2);
    }
    break;
  }
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysIntegrat_VarClrService(void)
{
  boolean_T boolLogSyncAction;
  boolean_T b_p;
  int32_T b_previousEvent;
  static const uint8_T b[6] = { 2U, 2U, 2U, 4U, 5U, 1U };

  static const uint8_T c[6] = { 2U, 3U, 5U, 5U, 5U, 7U };

  int32_T tmp;
  switch (test2_SysIntegration_DW.bitsForTID4.is_VarClrService) {
   case test2_SysIntegration_IN_Idle_k:
    if (test2_SysIntegration_DW.sfEvent_gn == test2_SysIntegr_event_VarClrEvt) {
      test2_SysIntegration_DW.varindex = 0U;
      if (test2_SysIntegration_DW.bitsForTID4.is_VarClrService ==
          test2_SysIntegration_IN_Idle_k) {
        test2_SysInteg_exit_atomic_Idle();
        test2_SysIntegration_DW.bitsForTID4.is_VarClrService = 0;
      }

      if (test2_SysIntegration_DW.bitsForTID4.is_VarClrService !=
          test2_SysIntegration_IN_Op_h) {
        test2_SysIntegration_DW.bitsForTID4.is_VarClrService =
          test2_SysIntegration_IN_Op_h;
        test2_SysIntegration_DW.bitsForTID4.was_VarClrService =
          test2_SysIntegration_IN_Op_h;
        test2_SysInt_LogSyncWriteAction(test2_SysIntegration_DW.MajorId,
          test2_SysIntegration_DW.MinorId, &boolLogSyncAction,
          &test2_SysIntegration_DW.LogWriteMajorId,
          &test2_SysIntegration_DW.LogWriteMinorId);
        test2_SysIntegration_DW.LogOpCode = 1U;
        test2_SysIntegration_DW.tempVar_ParamExt =
          test2_SysIntegration_DW.ParamExt;
        test2_SysIntegration_DW.tempVar_LogWriteMajorId =
          test2_SysIntegration_DW.LogWriteMajorId;
        test2_SysIntegration_DW.tempVar_LogWriteMinorId =
          test2_SysIntegration_DW.LogWriteMinorId;
      }

      if (test2_SysIntegration_DW.bitsForTID4.is_Op_h !=
          test2_IN_Wait4VarFlashClrFinish) {
        test2_SysIntegration_DW.bitsForTID4.is_Op_h =
          test2_IN_Wait4VarFlashClrFinish;
        test2_SysIntegration_DW.temporalCounter_i2_dg = 0U;
      }
    }
    break;

   case test2_SysIntegration_IN_Op_h:
    boolLogSyncAction = false;
    b_p = true;
    if (!(test2_SysIntegration_DW.varindex == 5)) {
      b_p = false;
    }

    if (b_p) {
      boolLogSyncAction = true;
    }

    if (boolLogSyncAction) {
      test2_SysIntegration_DW.ParamExt =
        test2_SysIntegration_DW.tempVar_ParamExt;
      test2_SysIntegration_DW.LogWriteMajorId =
        test2_SysIntegration_DW.tempVar_LogWriteMajorId;
      test2_SysIntegration_DW.LogWriteMinorId =
        test2_SysIntegration_DW.tempVar_LogWriteMinorId;
      b_previousEvent = test2_SysIntegration_DW.sfEvent_gn;
      test2_SysIntegration_DW.sfEvent_gn = test2_SysIntegra_event_LogOpEvt;
      if (test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen ==
          IN_Wait4FirstBag_LogUpLoadReque) {
        Wait4FirstBag_LogUpLoadRequest();
      }

      test2_SysIntegration_DW.sfEvent_gn = b_previousEvent;
      test2_SysIntegration_DW.bitsForTID4.is_Op_h = 0;
      test2_SysIntegration_DW.bitsForTID4.is_VarClrService =
        test2_SysIntegration_IN_Idle_k;
      test2_SysIntegration_DW.bitsForTID4.was_VarClrService =
        test2_SysIntegration_IN_Idle_k;
      for (b_previousEvent = 0; b_previousEvent < 6; b_previousEvent++) {
        test2_SysIntegration_DW.VarMajorIdVect[b_previousEvent] =
          c[b_previousEvent];
        test2_SysIntegration_DW.VarMinorIdVect[b_previousEvent] =
          b[b_previousEvent];
      }
    } else {
      switch (test2_SysIntegration_DW.bitsForTID4.is_Op_h) {
       case 1:
        if (test2_SysIntegration_DW.temporalCounter_i2_dg >= 1U) {
          b_previousEvent = (int32_T)(test2_SysIntegration_DW.varindex + 1U);
          if ((uint32_T)b_previousEvent > 255U) {
            b_previousEvent = 255;
          }

          test2_SysIntegration_DW.varindex = (uint8_T)((uint8_T)b_previousEvent %
            6);
          test2_SysIntegration_DW.bitsForTID4.is_Op_h = 1;
          test2_SysIntegration_DW.temporalCounter_i2_dg = 0U;
          b_previousEvent = (int32_T)(test2_SysIntegration_DW.varindex + 1U);
          tmp = b_previousEvent;
          if ((uint32_T)b_previousEvent > 255U) {
            tmp = 255;
            b_previousEvent = 255;
          }

          test2_SysIntegratio_VarClrStep2(&test2_SysIntegration_B.VarSet,
            test2_SysIntegration_DW.VarMajorIdVect[tmp - 1],
            test2_SysIntegration_DW.VarMinorIdVect[b_previousEvent - 1],
            test2_SysIntegration_DW.temp_Var2BeKept1,
            test2_SysIntegration_DW.temp_Var2BeKept2,
            test2_SysIntegration_DW.temp_Var2BeKept3,
            test2_SysIntegration_DW.temp_Var2BeKept4,
            test2_SysIntegration_DW.temp_Var2BeKept5,
            test2_SysIntegration_DW.temp_Var2BeKept6,
            test2_SysIntegration_DW.temp_Var2BeKept7,
            test2_SysIntegration_DW.temp_Var2BeKept8,
            test2_SysIntegration_DW.temp_Var2BeKept9,
            test2_SysIntegration_DW.temp_Var2BeKept10,
            test2_SysIntegration_DW.Channel,
            test2_SysIntegration_DW.FirmwareParam);
        }
        break;

       case test2_IN_Wait4VarFlashClrFinish:
        if (test2_SysIntegration_DW.temporalCounter_i2_dg >= 30U) {
          test2_SysIntegration_DW.bitsForTID4.is_Op_h = 1;
          test2_SysIntegration_DW.temporalCounter_i2_dg = 0U;
          b_previousEvent = (int32_T)(test2_SysIntegration_DW.varindex + 1U);
          if ((uint32_T)b_previousEvent > 255U) {
            b_previousEvent = 255;
          }

          tmp = (int32_T)(test2_SysIntegration_DW.varindex + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          test2_SysIntegratio_VarClrStep2(&test2_SysIntegration_B.VarSet,
            test2_SysIntegration_DW.VarMajorIdVect[b_previousEvent - 1],
            test2_SysIntegration_DW.VarMinorIdVect[tmp - 1],
            test2_SysIntegration_DW.temp_Var2BeKept1,
            test2_SysIntegration_DW.temp_Var2BeKept2,
            test2_SysIntegration_DW.temp_Var2BeKept3,
            test2_SysIntegration_DW.temp_Var2BeKept4,
            test2_SysIntegration_DW.temp_Var2BeKept5,
            test2_SysIntegration_DW.temp_Var2BeKept6,
            test2_SysIntegration_DW.temp_Var2BeKept7,
            test2_SysIntegration_DW.temp_Var2BeKept8,
            test2_SysIntegration_DW.temp_Var2BeKept9,
            test2_SysIntegration_DW.temp_Var2BeKept10,
            test2_SysIntegration_DW.Channel,
            test2_SysIntegration_DW.FirmwareParam);
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysIntegration_LogClr(uint8_T x_MajorId, uint8_T x_Channel)
{
  recordErase(x_MajorId, x_Channel);
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysIntegrat_LogClrService(void)
{
  boolean_T boolLogSyncAction;
  boolean_T b_p;
  int32_T b_previousEvent;
  switch (test2_SysIntegration_DW.bitsForTID4.is_LogClrService) {
   case test2_SysIntegration_IN_Idle_k:
    if (test2_SysIntegration_DW.sfEvent_gn == test2_SysIntegr_event_LogClrEvt) {
      test2_SysIntegration_DW.LogTypeIndex = 0U;
      test2_SysInt_LogSyncWriteAction(test2_SysIntegration_DW.MajorId,
        test2_SysIntegration_DW.MinorId, &boolLogSyncAction,
        &test2_SysIntegration_DW.LogWriteMajorId,
        &test2_SysIntegration_DW.LogWriteMinorId);
      test2_SysIntegration_DW.LogOpCode = 1U;
      test2_SysIntegration_DW.tempLog_ParamExt =
        test2_SysIntegration_DW.ParamExt;
      test2_SysIntegration_DW.tempLog_LogWriteMajorId =
        test2_SysIntegration_DW.LogWriteMajorId;
      test2_SysIntegration_DW.tempLog_LogWriteMinorId =
        test2_SysIntegration_DW.LogWriteMinorId;
      test2_SysIntegration_DW.bitsForTID4.is_LogClrService =
        test2_SysIntegration_IN_Op_h;
      test2_SysIntegration_DW.bitsForTID4.was_LogClrService =
        test2_SysIntegration_IN_Op_h;
      test2_SysIntegration_DW.temporalCounter_i3_n = 0U;
      b_previousEvent = (int32_T)(test2_SysIntegration_DW.LogTypeIndex + 1U);
      if ((uint32_T)b_previousEvent > 255U) {
        b_previousEvent = 255;
      }

      test2_SysIntegration_LogClr((uint8_T)b_previousEvent,
        test2_SysIntegration_DW.Channel);
    }
    break;

   case test2_SysIntegration_IN_Op_h:
    boolLogSyncAction = false;
    b_p = true;
    if (!(test2_SysIntegration_DW.LogTypeIndex == 2)) {
      b_p = false;
    }

    if (b_p) {
      boolLogSyncAction = true;
    }

    if (boolLogSyncAction) {
      test2_SysIntegration_DW.ParamExt =
        test2_SysIntegration_DW.tempLog_ParamExt;
      test2_SysIntegration_DW.LogWriteMajorId =
        test2_SysIntegration_DW.tempLog_LogWriteMajorId;
      test2_SysIntegration_DW.LogWriteMinorId =
        test2_SysIntegration_DW.tempLog_LogWriteMinorId;
      b_previousEvent = test2_SysIntegration_DW.sfEvent_gn;
      test2_SysIntegration_DW.sfEvent_gn = test2_SysIntegra_event_LogOpEvt;
      if (test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen ==
          IN_Wait4FirstBag_LogUpLoadReque) {
        Wait4FirstBag_LogUpLoadRequest();
      }

      test2_SysIntegration_DW.sfEvent_gn = b_previousEvent;
      test2_SysIntegration_DW.bitsForTID4.is_LogClrService =
        test2_SysIntegration_IN_Idle_k;
      test2_SysIntegration_DW.bitsForTID4.was_LogClrService =
        test2_SysIntegration_IN_Idle_k;
      test2_SysIntegration_DW.LogTypeIndex = 0U;
    } else {
      if (test2_SysIntegration_DW.temporalCounter_i3_n >= 30U) {
        b_previousEvent = (int32_T)(test2_SysIntegration_DW.LogTypeIndex + 1U);
        if ((uint32_T)b_previousEvent > 255U) {
          b_previousEvent = 255;
        }

        test2_SysIntegration_DW.LogTypeIndex = (uint8_T)((uint8_T)
          b_previousEvent % 2);
        test2_SysIntegration_DW.bitsForTID4.is_LogClrService =
          test2_SysIntegration_IN_Op_h;
        test2_SysIntegration_DW.bitsForTID4.was_LogClrService =
          test2_SysIntegration_IN_Op_h;
        test2_SysIntegration_DW.temporalCounter_i3_n = 0U;
        b_previousEvent = (int32_T)(test2_SysIntegration_DW.LogTypeIndex + 1U);
        if ((uint32_T)b_previousEvent > 255U) {
          b_previousEvent = 255;
        }

        test2_SysIntegration_LogClr((uint8_T)b_previousEvent,
          test2_SysIntegration_DW.Channel);
      }
    }
    break;
  }
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysIntegrat_FlashDriveAct(const type_HMI2SecurityMsg
  *UnitDelay_d)
{
  boolean_T sf_internal_predicateOutput;
  int32_T b_previousEvent;
  boolean_T b_p;
  uint8_T Var0104Data[3];
  uint8_T tmp[132];
  type_FirmwareCtrlParam tmp_0;
  type_FirmwareCtrlParam tmp_1;
  type_FirmwareCtrlParam tmp_2;
  uint8_T tmp_3;
  boolean_T guard1 = false;
  if (test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Head.MsgId !=
      test2_SysIntegration_DW.prevFlashAccessMsgId) {
    test2_SysIntegration_DW.prevFlashAccessMsgId =
      test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Head.MsgId;
    test2_SysIntegration_DW.bitsForTID4.FlashAccessEnable = true;
    test2_SysIntegration_DW.OpCode =
      test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Head.OpCode;
    test2_SysIntegration_DW.MajorId =
      test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Body.MajorId;
    test2_SysIntegration_DW.MinorId =
      test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Body.MinorId;
    memcpy(&test2_SysIntegration_DW.Data[0],
           &test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Body.Data[0], 132U *
           sizeof(uint8_T));
  } else {
    if (UnitDelay_d->Head.MsgId != test2_SysIntegration_DW.prevAlarmInfoMsgId) {
      test2_SysIntegration_DW.prevAlarmInfoMsgId = UnitDelay_d->Head.MsgId;
      test2_SysIntegration_DW.OpCode = UnitDelay_d->Head.OpCode;
      test2_SysIntegration_DW.ParamExt = UnitDelay_d->Body.Data;
      test2_SysIntegration_DW.LogOpCode = 1U;
      switch (test2_SysIntegration_DW.OpCode) {
       case 1:
        test2_SysIntegration_DW.LogWriteMajorId = 2U;
        test2_SysIntegration_DW.LogWriteMinorId = 1U;
        break;

       case 2:
        test2_SysIntegration_DW.LogWriteMajorId = 1U;
        test2_SysIntegration_DW.LogWriteMinorId =
          test2_SysIntegration_DW.ParamExt;
        break;
      }

      b_previousEvent = test2_SysIntegration_DW.sfEvent_gn;
      test2_SysIntegration_DW.sfEvent_gn = test2_SysIntegra_event_LogOpEvt;
      if (test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen ==
          IN_Wait4FirstBag_LogUpLoadReque) {
        Wait4FirstBag_LogUpLoadRequest();
      }

      test2_SysIntegration_DW.sfEvent_gn = b_previousEvent;
    }
  }

  if (test2_SysIntegration_DW.bitsForTID4.FlashAccessEnable &&
      test2_SysIntegration_DW.bitsForTID4.boolLogReadTerminate &&
      (!test2_SysIntegration_DW.FirmwareParam.boolTransIng)) {
    sf_internal_predicateOutput = false;
    b_p = true;
    if (!(test2_SysIntegration_DW.MajorId == 4)) {
      b_p = false;
    }

    if (b_p) {
      sf_internal_predicateOutput = true;
    }

    if (sf_internal_predicateOutput) {
      sf_internal_predicateOutput = false;
      b_p = true;
      if (!(test2_SysIntegration_DW.MinorId == 2)) {
        b_p = false;
      }

      if (b_p) {
        sf_internal_predicateOutput = true;
      }
    } else {
      sf_internal_predicateOutput = false;
    }

    sf_internal_predicateOutput = !sf_internal_predicateOutput;
  } else {
    sf_internal_predicateOutput = false;
  }

  guard1 = false;
  if (sf_internal_predicateOutput) {
    test2_SysIntegration_DW.bitsForTID4.FlashAccessEnable = false;
    guard1 = true;
  } else {
    if (test2_SysIntegration_DW.FirmwareParam.boolTransIng &&
        test2_SysIntegration_DW.bitsForTID4.FlashAccessEnable) {
      sf_internal_predicateOutput = false;
      b_p = true;
      if (!(test2_SysIntegration_DW.MajorId == 4)) {
        b_p = false;
      }

      if (b_p) {
        sf_internal_predicateOutput = true;
      }

      if (sf_internal_predicateOutput) {
        sf_internal_predicateOutput = false;
        b_p = true;
        if (!(test2_SysIntegration_DW.MinorId == 2)) {
          b_p = false;
        }

        if (b_p) {
          sf_internal_predicateOutput = true;
        }

        sf_internal_predicateOutput = (sf_internal_predicateOutput &&
          test2_SysIntegration_DW.bitsForTID4.boolLogReadTerminate);
      } else {
        sf_internal_predicateOutput = false;
      }
    } else {
      sf_internal_predicateOutput = false;
    }

    if (sf_internal_predicateOutput) {
      test2_SysIntegration_DW.bitsForTID4.FlashAccessEnable = false;
      guard1 = true;
    } else {
      if (test2_SysIntegration_DW.bitsForTID4.is_FlashDriveAct ==
          test2_SysIntegrati_IN_VarAccess) {
        sf_internal_predicateOutput = false;
        b_p = true;
        if (!(test2_SysIntegration_DW.MajorId == 1)) {
          b_p = false;
        }

        if (b_p) {
          sf_internal_predicateOutput = true;
        }

        if (sf_internal_predicateOutput && (test2_SysIntegration_DW.MinorId >=
             10) && (test2_SysIntegration_DW.MinorId < 42)) {
          test2_SysIntegration_DW.bitsForTID4.is_FlashDriveAct =
            test2_Sy_IN_Var0104Write_Update;
          test2_SysInte_Var0104DataReform(test2_SysIntegration_DW.MinorId,
            Var0104Data);
          test2_SysInt_Var0104Write2Flash(1, 4, Var0104Data,
            test2_SysIntegration_DW.Channel, &test2_SysIntegration_B.VarSet,
            test2_SysIntegration_DW.FirmwareParam, &sf_internal_predicateOutput,
            &tmp_3, &test2_SysIntegration_B.VarSet, &tmp_2);
          test2_SysIntegration_DW.Channel = tmp_3;
          test2_SysIntegration_DW.FirmwareParam = tmp_2;
          test2_SysIntegration_DW.bitsForTID4.FlashAccessErr =
            sf_internal_predicateOutput;
        }
      }
    }
  }

  if (guard1) {
    test2_SysIntegration_DW.bitsForTID4.is_FlashDriveAct = 0;
    if (test2_SysIntegration_DW.bitsForTID4.is_FlashDriveAct ==
        test2_SysIntegrati_IN_VarAccess) {
    } else {
      test2_SysIntegration_DW.bitsForTID4.is_FlashDriveAct =
        test2_SysIntegrati_IN_VarAccess;
      switch (test2_SysIntegration_DW.OpCode) {
       case 1:
       case 100:
        if (test2_SysIntegration_B.VarSet.SysSetting.FlashConfigFlag != 175) {
          test2_SysIntegra_VarWrite2Flash(175, test2_SysIntegration_DW.Channel,
            &test2_SysIntegration_B.VarSet,
            test2_SysIntegration_DW.FirmwareParam, &sf_internal_predicateOutput,
            &tmp_3, &test2_SysIntegration_B.VarSet, &tmp_1);
          test2_SysIntegration_DW.Channel = tmp_3;
          test2_SysIntegration_DW.FirmwareParam = tmp_1;
          test2_SysIntegration_DW.bitsForTID4.FlashAccessErr =
            sf_internal_predicateOutput;
        }

        memcpy(&tmp[0], &test2_SysIntegration_DW.Data[0], 132U * sizeof(uint8_T));
        test2_SysInteg_VarWrite2Flash_a(test2_SysIntegration_DW.MajorId,
          test2_SysIntegration_DW.MinorId, tmp, test2_SysIntegration_DW.Channel,
          &test2_SysIntegration_B.VarSet, test2_SysIntegration_DW.FirmwareParam,
          &sf_internal_predicateOutput, &tmp_3, &test2_SysIntegration_B.VarSet,
          &tmp_0);
        test2_SysIntegration_DW.Channel = tmp_3;
        test2_SysIntegration_DW.FirmwareParam = tmp_0;
        test2_SysIntegration_DW.bitsForTID4.FlashAccessErr =
          sf_internal_predicateOutput;
        test2_SysInt_LogSyncWriteAction(test2_SysIntegration_DW.MajorId,
          test2_SysIntegration_DW.MinorId, &sf_internal_predicateOutput,
          &test2_SysIntegration_DW.LogWriteMajorId,
          &test2_SysIntegration_DW.LogWriteMinorId);
        if (sf_internal_predicateOutput) {
          test2_SysIntegration_DW.LogOpCode = 1U;
          test2_SysIntegration_DW.ParamExt = 0U;
          b_previousEvent = test2_SysIntegration_DW.sfEvent_gn;
          test2_SysIntegration_DW.sfEvent_gn = test2_SysIntegra_event_LogOpEvt;
          if (test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen
              == IN_Wait4FirstBag_LogUpLoadReque) {
            Wait4FirstBag_LogUpLoadRequest();
          }

          test2_SysIntegration_DW.sfEvent_gn = b_previousEvent;
        }
        break;

       case 3:
        test2_SysIntegration_DW.ParamExt = test2_SysIntegration_DW.Data[0];
        test2_SysIntegration_DW.MajorId = 4U;
        test2_SysIntegration_DW.MinorId = 4U;
        switch (test2_SysIntegration_DW.ParamExt) {
         case 1:
          b_previousEvent = test2_SysIntegration_DW.sfEvent_gn;
          test2_SysIntegration_DW.sfEvent_gn = test2_SysIntegr_event_VarClrEvt;
          if (test2_SysIntegration_DW.bitsForTID4.is_active_VarClrService != 0U)
          {
            test2_SysIntegrat_VarClrService();
          }

          test2_SysIntegration_DW.sfEvent_gn = b_previousEvent;
          break;

         case 2:
          b_previousEvent = test2_SysIntegration_DW.sfEvent_gn;
          test2_SysIntegration_DW.sfEvent_gn = test2_SysIntegr_event_LogClrEvt;
          if (test2_SysIntegration_DW.bitsForTID4.is_active_LogClrService != 0U)
          {
            test2_SysIntegrat_LogClrService();
          }

          test2_SysIntegration_DW.sfEvent_gn = b_previousEvent;
          break;
        }
        break;

       case 5:
        test2_SysIntegration_DW.LogWriteMajorId = 0U;
        test2_SysIntegration_DW.LogWriteMinorId = 0U;
        test2_SysIntegration_DW.LogOpCode = 2U;
        b_previousEvent = test2_SysIntegration_DW.sfEvent_gn;
        test2_SysIntegration_DW.sfEvent_gn = test2_SysIntegra_event_LogOpEvt;
        if (test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen ==
            IN_Wait4FirstBag_LogUpLoadReque) {
          Wait4FirstBag_LogUpLoadRequest();
        }

        test2_SysIntegration_DW.sfEvent_gn = b_previousEvent;
        break;

       case 6:
        test2_SysIntegration_DW.LogWriteMajorId =
          test2_SysIntegration_DW.MajorId;
        test2_SysIntegration_DW.LogWriteMinorId = 0U;
        test2_SysIntegration_DW.LogOpCode = 3U;
        b_previousEvent = test2_SysIntegration_DW.sfEvent_gn;
        test2_SysIntegration_DW.sfEvent_gn = test2_SysIntegra_event_LogOpEvt;
        if (test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen ==
            IN_Wait4FirstBag_LogUpLoadReque) {
          Wait4FirstBag_LogUpLoadRequest();
        }

        test2_SysIntegration_DW.sfEvent_gn = b_previousEvent;
        break;

       case 7:
        test2_SysIntegration_DW.LogWriteMajorId =
          test2_SysIntegration_DW.MajorId;
        test2_SysIntegration_DW.LogWriteMinorId = 0U;
        test2_SysIntegration_DW.LogOpCode = 4U;
        b_previousEvent = test2_SysIntegration_DW.sfEvent_gn;
        test2_SysIntegration_DW.sfEvent_gn = test2_SysIntegra_event_LogOpEvt;
        if (test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen ==
            IN_Wait4FirstBag_LogUpLoadReque) {
          Wait4FirstBag_LogUpLoadRequest();
        }

        test2_SysIntegration_DW.sfEvent_gn = b_previousEvent;
        break;
      }
    }
  }
}

/* Function for Chart: '<S63>/Chart' */
static void enter_atomic_Wait4FirstBag_LogU(void)
{
  int32_T tmp;
  switch (test2_SysIntegration_B.VarSet.Firmware.FirmwareUpgradeCompleteFlag) {
   case 3:
    tmp = (int32_T)(test2_SysIntegration_B.SysDiagMsgOut_d.Head.MsgId + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    test2_SysIntegration_B.SysDiagMsgOut_d.Head.MsgId = (uint8_T)((uint8_T)tmp %
      MAX_uint8_T);
    test2_SysIntegration_B.SysDiagMsgOut_d.Head.OpCode = 1U;
    test2_SysIntegration_B.SysDiagMsgOut_d.Body.Data = 206U;
    break;

   case 1:
    tmp = (int32_T)(test2_SysIntegration_B.SysDiagMsgOut_d.Head.MsgId + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    test2_SysIntegration_B.SysDiagMsgOut_d.Head.MsgId = (uint8_T)((uint8_T)tmp %
      MAX_uint8_T);
    test2_SysIntegration_B.SysDiagMsgOut_d.Head.OpCode = 1U;
    test2_SysIntegration_B.SysDiagMsgOut_d.Body.Data = 207U;
    break;

   case 2:
    tmp = (int32_T)(test2_SysIntegration_B.SysDiagMsgOut_d.Head.MsgId + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    test2_SysIntegration_B.SysDiagMsgOut_d.Head.MsgId = (uint8_T)((uint8_T)tmp %
      MAX_uint8_T);
    test2_SysIntegration_B.SysDiagMsgOut_d.Head.OpCode = 1U;
    test2_SysIntegration_B.SysDiagMsgOut_d.Body.Data = 205U;
    break;
  }
}

/* Function for Chart: '<S63>/Chart' */
static boolean_T test2_SysInteg_DailyDoseStatClr(type_SysVars *x_VarSet, const
  type_RT x_RTInfo, uint8_T x_DDSVarMajorId, uint8_T x_DDSVarMinorID)
{
  boolean_T y_FlashAccessErr;
  uint8_T x_Data[17];
  int32_T i;
  y_FlashAccessErr = false;
  if (x_VarSet->ActCtrl.DailyDoseStatVar.DayInfo != x_RTInfo.Time[2]) {
    x_Data[0] = x_RTInfo.Time[2];
    for (i = 0; i < 16; i++) {
      x_Data[i + 1] = 0U;
    }

    y_FlashAccessErr = dataWrite(x_DDSVarMajorId, x_DDSVarMinorID, x_Data, 17, 1);
    x_VarSet->ActCtrl.DailyDoseStatVar.DayInfo = x_RTInfo.Time[2];
    x_VarSet->ActCtrl.DailyDoseStatVar.ResidueDoseEst = 0U;
    x_VarSet->ActCtrl.DailyDoseStatVar.TotalAmountAcc = 0U;
    x_VarSet->ActCtrl.DailyDoseStatVar.DailyAmountAcc = 0U;
    x_VarSet->ActCtrl.DailyDoseStatVar.LargeAmountAcc = 0U;
  }

  return y_FlashAccessErr;
}

/* Function for Chart: '<S63>/Chart' */
static void test2__exit_internal_FlashDrive(void)
{
  test2_SysIntegration_DW.bitsForTID4.is_LogClrService = 0;
  test2_SysIntegration_DW.bitsForTID4.is_active_LogClrService = 0;
  if (test2_SysIntegration_DW.bitsForTID4.is_VarClrService ==
      test2_SysIntegration_IN_Idle_k) {
    test2_SysInteg_exit_atomic_Idle();
    test2_SysIntegration_DW.bitsForTID4.is_VarClrService = 0;
  } else {
    test2_SysIntegration_DW.bitsForTID4.is_Op_h = 0;
    test2_SysIntegration_DW.bitsForTID4.is_VarClrService = 0;
  }

  test2_SysIntegration_DW.bitsForTID4.is_active_VarClrService = 0;
  if (test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen ==
      test2_SysInt_IN_LogExportCtrlOp) {
    test2_SysIntegration_DW.bitsForTID4.boolLogSend = false;
    test2_SysIntegration_DW.bitsForTID4.boolLogReadTerminate = true;
    test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen = 0;
  } else {
    test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen = 0;
  }

  if (test2_SysIntegration_DW.bitsForTID4.is_active_UpgradeAndLogUpLoadMa != 0U)
  {
    test2_SysIntegration_DW.FirmwareParam.boolTransIng = false;
    test2_SysIntegration_DW.bitsForTID4.is_active_UpgradeAndLogUpLoadMa = 0;
  }

  test2_SysIntegration_DW.bitsForTID4.is_FlashDriveAct = 0;
  test2_SysIntegration_DW.bitsForTID4.is_active_FlashDriveAct = 0;
}

/* Function for Chart: '<S63>/Chart' */
static void test2_enter_internal_FlashDrive(void)
{
  int32_T b_previousEvent;
  boolean_T boolLogSyncAction;
  static const uint8_T b[6] = { 2U, 3U, 5U, 5U, 5U, 7U };

  static const uint8_T c[6] = { 2U, 2U, 2U, 4U, 5U, 1U };

  if (test2_SysIntegration_DW.bitsForTID4.is_active_FlashDriveAct != 1U) {
    test2_SysIntegration_DW.bitsForTID4.is_active_FlashDriveAct = 1;
  }

  if (test2_SysIntegration_DW.bitsForTID4.is_FlashDriveAct !=
      test2_SysIntegration_IN_Idle_k) {
    test2_SysIntegration_DW.bitsForTID4.is_FlashDriveAct =
      test2_SysIntegration_IN_Idle_k;
    test2_SysIntegration_DW.FlashInitFinishEvtEventCounter++;

    /* UnitDelay: '<S65>/Unit Delay' */
    if (test2_SysIntegration_DW.UnitDelay_DSTATE_j.Time[2] !=
        test2_SysIntegration_B.VarSet.ActCtrl.DailyDoseStatVar.DayInfo) {
      test2_SysIntegration_DW.LogOpCode = 1U;
      test2_SysIntegration_DW.LogWriteMajorId = 1U;
      test2_SysIntegration_DW.LogWriteMinorId = 5U;
      b_previousEvent = test2_SysIntegration_DW.sfEvent_gn;
      test2_SysIntegration_DW.sfEvent_gn = test2_SysIntegra_event_LogOpEvt;
      if (test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen ==
          IN_Wait4FirstBag_LogUpLoadReque) {
        Wait4FirstBag_LogUpLoadRequest();
      }

      test2_SysIntegration_DW.sfEvent_gn = b_previousEvent;
    }

    /* End of UnitDelay: '<S65>/Unit Delay' */
  }

  if (test2_SysIntegration_DW.bitsForTID4.is_active_UpgradeAndLogUpLoadMa != 1U)
  {
    test2_SysIntegration_DW.bitsForTID4.is_active_UpgradeAndLogUpLoadMa = 1;
  }

  if (test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen !=
      IN_Wait4FirstBag_LogUpLoadReque) {
    test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen =
      IN_Wait4FirstBag_LogUpLoadReque;
    enter_atomic_Wait4FirstBag_LogU();
  }

  test2_SysIntegration_DW.bitsForTID4.is_active_VarClrService = 1;
  switch (test2_SysIntegration_DW.bitsForTID4.was_VarClrService) {
   case test2_SysIntegration_IN_Idle_k:
    if (test2_SysIntegration_DW.bitsForTID4.is_VarClrService !=
        test2_SysIntegration_IN_Idle_k) {
      test2_SysIntegration_DW.bitsForTID4.is_VarClrService =
        test2_SysIntegration_IN_Idle_k;
      test2_SysIntegration_DW.bitsForTID4.was_VarClrService =
        test2_SysIntegration_IN_Idle_k;
      for (b_previousEvent = 0; b_previousEvent < 6; b_previousEvent++) {
        test2_SysIntegration_DW.VarMajorIdVect[b_previousEvent] =
          b[b_previousEvent];
        test2_SysIntegration_DW.VarMinorIdVect[b_previousEvent] =
          c[b_previousEvent];
      }
    }
    break;

   case test2_SysIntegration_IN_Op_h:
    if (test2_SysIntegration_DW.bitsForTID4.is_VarClrService !=
        test2_SysIntegration_IN_Op_h) {
      test2_SysIntegration_DW.bitsForTID4.is_VarClrService =
        test2_SysIntegration_IN_Op_h;
      test2_SysIntegration_DW.bitsForTID4.was_VarClrService =
        test2_SysIntegration_IN_Op_h;
      test2_SysInt_LogSyncWriteAction(test2_SysIntegration_DW.MajorId,
        test2_SysIntegration_DW.MinorId, &boolLogSyncAction,
        &test2_SysIntegration_DW.LogWriteMajorId,
        &test2_SysIntegration_DW.LogWriteMinorId);
      test2_SysIntegration_DW.LogOpCode = 1U;
      test2_SysIntegration_DW.tempVar_ParamExt =
        test2_SysIntegration_DW.ParamExt;
      test2_SysIntegration_DW.tempVar_LogWriteMajorId =
        test2_SysIntegration_DW.LogWriteMajorId;
      test2_SysIntegration_DW.tempVar_LogWriteMinorId =
        test2_SysIntegration_DW.LogWriteMinorId;
    }

    if (test2_SysIntegration_DW.bitsForTID4.is_Op_h !=
        test2_IN_Wait4VarFlashClrFinish) {
      test2_SysIntegration_DW.bitsForTID4.is_Op_h =
        test2_IN_Wait4VarFlashClrFinish;
      test2_SysIntegration_DW.temporalCounter_i2_dg = 0U;
    }
    break;

   default:
    if (test2_SysIntegration_DW.bitsForTID4.is_VarClrService !=
        test2_SysIntegration_IN_Idle_k) {
      test2_SysIntegration_DW.bitsForTID4.is_VarClrService =
        test2_SysIntegration_IN_Idle_k;
      test2_SysIntegration_DW.bitsForTID4.was_VarClrService =
        test2_SysIntegration_IN_Idle_k;
      for (b_previousEvent = 0; b_previousEvent < 6; b_previousEvent++) {
        test2_SysIntegration_DW.VarMajorIdVect[b_previousEvent] =
          b[b_previousEvent];
        test2_SysIntegration_DW.VarMinorIdVect[b_previousEvent] =
          c[b_previousEvent];
      }
    }
    break;
  }

  test2_SysIntegration_DW.bitsForTID4.is_active_LogClrService = 1;
  switch (test2_SysIntegration_DW.bitsForTID4.was_LogClrService) {
   case test2_SysIntegration_IN_Idle_k:
    if (test2_SysIntegration_DW.bitsForTID4.is_LogClrService !=
        test2_SysIntegration_IN_Idle_k) {
      test2_SysIntegration_DW.bitsForTID4.is_LogClrService =
        test2_SysIntegration_IN_Idle_k;
      test2_SysIntegration_DW.bitsForTID4.was_LogClrService =
        test2_SysIntegration_IN_Idle_k;
      test2_SysIntegration_DW.LogTypeIndex = 0U;
    }
    break;

   case test2_SysIntegration_IN_Op_h:
    if (test2_SysIntegration_DW.bitsForTID4.is_LogClrService !=
        test2_SysIntegration_IN_Op_h) {
      test2_SysIntegration_DW.bitsForTID4.is_LogClrService =
        test2_SysIntegration_IN_Op_h;
      test2_SysIntegration_DW.bitsForTID4.was_LogClrService =
        test2_SysIntegration_IN_Op_h;
      test2_SysIntegration_DW.temporalCounter_i3_n = 0U;
      b_previousEvent = (int32_T)(test2_SysIntegration_DW.LogTypeIndex + 1U);
      if ((uint32_T)b_previousEvent > 255U) {
        b_previousEvent = 255;
      }

      test2_SysIntegration_LogClr((uint8_T)b_previousEvent,
        test2_SysIntegration_DW.Channel);
    }
    break;

   default:
    if (test2_SysIntegration_DW.bitsForTID4.is_LogClrService !=
        test2_SysIntegration_IN_Idle_k) {
      test2_SysIntegration_DW.bitsForTID4.is_LogClrService =
        test2_SysIntegration_IN_Idle_k;
      test2_SysIntegration_DW.bitsForTID4.was_LogClrService =
        test2_SysIntegration_IN_Idle_k;
      test2_SysIntegration_DW.LogTypeIndex = 0U;
    }
    break;
  }
}

/* Function for Chart: '<S63>/Chart' */
static boolean_T test2_SysIntegr_ValidityChkPass(const uint8_T x_BuffData[132],
  uint8_T x_Size)
{
  boolean_T y_boolChkPass;
  uint8_T checksum;
  uint8_T i;
  y_boolChkPass = false;
  checksum = 0U;
  for (i = 1U; i <= x_Size; i++) {
    checksum = (uint8_T)(255 - x_BuffData[i - 1]);
  }

  if (checksum != 0) {
    y_boolChkPass = true;
  }

  return y_boolChkPass;
}

/* Function for Chart: '<S63>/Chart' */
static void test_EachVarMemberInitFromFlash(uint8_T x_Channel, type_SysVars
  *x_VarSet, uint8_T x_MajorId, uint8_T x_MinorId, boolean_T *y_FlashAccessErr,
  uint8_T *y_Channel)
{
  uint8_T temp_buff[132];
  uint16_T y_Uint16;
  uint16_T b_y_Uint16;
  uint16_T c_y_Uint16;
  uint16_T d_y_Uint16;
  int32_T f[8];
  int32_T i;
  uint32_T tmp;
  uint32_T tmp_0;
  uint32_T tmp_1;
  uint32_T tmp_2;
  *y_FlashAccessErr = false;
  *y_Channel = x_Channel;
  memset(&temp_buff[0], 0, 132U * sizeof(uint8_T));
  switch (x_MajorId) {
   case 1:
    switch (x_MinorId) {
     case 1:
      *y_FlashAccessErr = dataRead(x_MajorId, x_MinorId, x_Channel, temp_buff,
        test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId) - 1]);
      if ((!*y_FlashAccessErr) && test2_SysIntegr_ValidityChkPass(temp_buff,
           test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId)
           - 1])) {
        x_VarSet->DoseCtrl.DoseCtrlParam.Concentration = temp_buff[0];
        x_VarSet->DoseCtrl.DoseCtrlParam.LowDoseTHValue = temp_buff[1];
        x_VarSet->DoseCtrl.DoseCtrlParam.MaxLargeDose = (uint16_T)((temp_buff[3]
          << 8) + temp_buff[2]);
        x_VarSet->DoseCtrl.DoseCtrlParam.MaxBaseRate = (uint16_T)((temp_buff[5] <<
          8) + temp_buff[4]);
        x_VarSet->DoseCtrl.DoseCtrlParam.MaxDailyDose = temp_buff[6];
      }
      break;

     case 2:
      *y_FlashAccessErr = dataRead(x_MajorId, x_MinorId, x_Channel, temp_buff,
        test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId) - 1]);
      if ((!*y_FlashAccessErr) && test2_SysIntegr_ValidityChkPass(temp_buff,
           test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId)
           - 1])) {
        for (i = 0; i < 48; i++) {
          x_VarSet->DoseCtrl.BaseRateConfig[i] = temp_buff[i];
        }
      }
      break;

     case 3:
      *y_FlashAccessErr = dataRead(x_MajorId, x_MinorId, x_Channel, temp_buff,
        test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId) - 1]);
      if ((!*y_FlashAccessErr) && test2_SysIntegr_ValidityChkPass(temp_buff,
           test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId)
           - 1])) {
        for (i = 0; i < 48; i++) {
          x_VarSet->DoseCtrl.TempBaseRateConfig[i] = temp_buff[i];
        }
      }
      break;

     case 4:
      *y_FlashAccessErr = dataRead(x_MajorId, x_MinorId, x_Channel, temp_buff,
        test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId) - 1]);
      if ((!*y_FlashAccessErr) && test2_SysIntegr_ValidityChkPass(temp_buff,
           test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId)
           - 1])) {
        x_VarSet->DoseCtrl.LastTBRConfigDay[0] = temp_buff[0];
        x_VarSet->DoseCtrl.LastTBRConfigDay[1] = temp_buff[1];
        x_VarSet->DoseCtrl.LastTBRConfigDay[2] = temp_buff[2];
      }
      break;

     case 5:
      *y_FlashAccessErr = dataRead(x_MajorId, x_MinorId, x_Channel, temp_buff,
        test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId) - 1]);
      if ((!*y_FlashAccessErr) && test2_SysIntegr_ValidityChkPass(temp_buff,
           test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId)
           - 1])) {
        x_VarSet->DoseCtrl.LargeDoseConfig.LargeDoseTotalAmount = (uint16_T)
          ((temp_buff[1] << 8) + temp_buff[0]);
        x_VarSet->DoseCtrl.LargeDoseConfig.DeliveryConfig = temp_buff[2];
        x_VarSet->DoseCtrl.LargeDoseConfig.PermittedTime = temp_buff[3];
        x_VarSet->DoseCtrl.LargeDoseConfig.RegularDose4DWMCase = (uint16_T)
          ((temp_buff[5] << 8) + temp_buff[4]);
        x_VarSet->DoseCtrl.LargeDoseConfig.EffectiveDay = (uint16_T)((temp_buff
          [7] << 8) + temp_buff[6]);
        for (i = 0; i < 20; i++) {
          x_VarSet->DoseCtrl.LargeDoseConfig.CustomTimeConfig[i] = temp_buff[8 +
            i];
          x_VarSet->DoseCtrl.LargeDoseConfig.CustomDoseConfig[i] = temp_buff[28
            + i];
        }
      }
      break;

     case 6:
      break;
    }
    break;

   case 2:
    switch (x_MinorId) {
     case 1:
      *y_FlashAccessErr = dataRead(x_MajorId, x_MinorId, x_Channel, temp_buff,
        test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId) - 1]);
      if ((!*y_FlashAccessErr) && test2_SysIntegr_ValidityChkPass(temp_buff,
           test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId)
           - 1])) {
        x_VarSet->ActCtrl.IniLoadedVol = temp_buff[0];
      }
      break;

     case 2:
      *y_FlashAccessErr = dataRead(x_MajorId, x_MinorId, x_Channel, temp_buff,
        test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId) - 1]);
      if ((!*y_FlashAccessErr) && test2_SysIntegr_ValidityChkPass(temp_buff,
           test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId)
           - 1])) {
        x_VarSet->ActCtrl.AdjustInputGain = test2_SysI_TransTwoBytes2Uint16
          (&temp_buff[0]);
        x_VarSet->ActCtrl.AdjustPositiveOffset = test2_SysI_TransTwoBytes2Uint16
          (&temp_buff[2]);
        x_VarSet->ActCtrl.AdjustNegativeOffset = test2_SysI_TransTwoBytes2Uint16
          (&temp_buff[4]);
      }
      break;

     case 3:
      *y_FlashAccessErr = dataRead(x_MajorId, x_MinorId, x_Channel, temp_buff,
        test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId) - 1]);
      if ((!*y_FlashAccessErr) && test2_SysIntegr_ValidityChkPass(temp_buff,
           test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId)
           - 1])) {
        x_VarSet->ActCtrl.DeliverSwitch = temp_buff[0];
      }
      break;

     case 4:
      *y_FlashAccessErr = dataRead(x_MajorId, x_MinorId, x_Channel, temp_buff,
        test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId) - 1]);
      if ((!*y_FlashAccessErr) && test2_SysIntegr_ValidityChkPass(temp_buff,
           test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId)
           - 1])) {
        x_VarSet->ActCtrl.BaseRateDynVar.TargetDose =
          test2_SysInt_Trans4Bytes2Uint32(&temp_buff[0]);
        x_VarSet->ActCtrl.BaseRateDynVar.TimeInfo =
          test2_SysI_TransTwoBytes2Uint16(&temp_buff[4]);
        x_VarSet->ActCtrl.BaseRateDynVar.CompleteDose =
          test2_SysInt_Trans4Bytes2Uint32(&temp_buff[6]);
      }
      break;

     case 5:
      *y_FlashAccessErr = dataRead(x_MajorId, x_MinorId, x_Channel, temp_buff,
        test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId) - 1]);
      if ((!*y_FlashAccessErr) && test2_SysIntegr_ValidityChkPass(temp_buff,
           test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId)
           - 1])) {
        x_VarSet->ActCtrl.LargeDoseDynVar.TargetDose =
          test2_SysInt_Trans4Bytes2Uint32(&temp_buff[0]);
        x_VarSet->ActCtrl.LargeDoseDynVar.TimeInfo =
          test2_SysI_TransTwoBytes2Uint16(&temp_buff[4]);
        x_VarSet->ActCtrl.LargeDoseDynVar.CompleteDose =
          test2_SysInt_Trans4Bytes2Uint32(&temp_buff[6]);
      }
      break;

     case 6:
      *y_FlashAccessErr = dataRead(x_MajorId, x_MinorId, x_Channel, temp_buff,
        test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId) - 1]);
      if ((!*y_FlashAccessErr) && test2_SysIntegr_ValidityChkPass(temp_buff,
           test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId)
           - 1])) {
        x_VarSet->ActCtrl.DailyDoseStatVar.DayInfo = temp_buff[0];
        x_VarSet->ActCtrl.DailyDoseStatVar.ResidueDoseEst = ((((uint32_T)
          temp_buff[2] << 8U) + temp_buff[1]) + ((uint32_T)temp_buff[3] << 16U))
          + ((uint32_T)temp_buff[4] << 24U);
        x_VarSet->ActCtrl.DailyDoseStatVar.TotalAmountAcc = ((((uint32_T)
          temp_buff[6] << 8U) + temp_buff[5]) + ((uint32_T)temp_buff[7] << 16U))
          + ((uint32_T)temp_buff[8] << 24U);
        x_VarSet->ActCtrl.DailyDoseStatVar.DailyAmountAcc = ((((uint32_T)
          temp_buff[10] << 8U) + temp_buff[9]) + ((uint32_T)temp_buff[11] << 16U))
          + ((uint32_T)temp_buff[12] << 24U);
        x_VarSet->ActCtrl.DailyDoseStatVar.LargeAmountAcc = ((((uint32_T)
          temp_buff[14] << 8U) + temp_buff[13]) + ((uint32_T)temp_buff[15] <<
          16U)) + ((uint32_T)temp_buff[16] << 24U);
      }
      break;
    }
    break;

   case 3:
    switch (x_MinorId) {
     case 1:
      *y_FlashAccessErr = dataRead(x_MajorId, x_MinorId, x_Channel, temp_buff,
        test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId) - 1]);
      if ((!*y_FlashAccessErr) && test2_SysIntegr_ValidityChkPass(temp_buff,
           test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId)
           - 1])) {
        x_VarSet->AlarmCtrl.AlarmCtrlConfig = temp_buff[0];
      }
      break;

     case 2:
      *y_FlashAccessErr = dataRead(x_MajorId, x_MinorId, x_Channel, temp_buff,
        test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId) - 1]);
      if ((!*y_FlashAccessErr) && test2_SysIntegr_ValidityChkPass(temp_buff,
           test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId)
           - 1])) {
        test2_Sy_Transfer32ByteTo8Int32(&temp_buff[0], f);
        for (i = 0; i < 8; i++) {
          x_VarSet->AlarmCtrl.SSCurAndProcTimeCritPolyFitVect[i] = f[i];
        }
      }
      break;
    }
    break;

   case 4:
   case 6:
    break;

   case 5:
    switch (x_MinorId) {
     case 1:
      *y_FlashAccessErr = dataRead(x_MajorId, x_MinorId, x_Channel, temp_buff,
        test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId) - 1]);
      if ((!*y_FlashAccessErr) && test2_SysIntegr_ValidityChkPass(temp_buff,
           test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId)
           - 1])) {
        x_VarSet->SysSetting.SensitivityLevel = temp_buff[0];
      }
      break;

     case 2:
      *y_FlashAccessErr = dataRead(x_MajorId, x_MinorId, x_Channel, temp_buff,
        test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId) - 1]);
      if ((!*y_FlashAccessErr) && test2_SysIntegr_ValidityChkPass(temp_buff,
           test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId)
           - 1])) {
        for (i = 0; i < 10; i++) {
          x_VarSet->SysSetting.SerialNo[i] = temp_buff[i];
        }
      }
      break;

     case 3:
      *y_FlashAccessErr = dataRead(x_MajorId, x_MinorId, x_Channel, temp_buff,
        test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId) - 1]);
      if ((!*y_FlashAccessErr) && test2_SysIntegr_ValidityChkPass(temp_buff,
           test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId)
           - 1])) {
        for (i = 0; i < 6; i++) {
          x_VarSet->SysSetting.SoftwareVersionInfo[i] = temp_buff[i];
        }
      }
      break;

     case 4:
      *y_FlashAccessErr = dataRead(x_MajorId, x_MinorId, x_Channel, temp_buff,
        test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId) - 1]);
      if ((!*y_FlashAccessErr) && test2_SysIntegr_ValidityChkPass(temp_buff,
           test2_SysIntegration_B.VarSizeInfo[((x_MinorId - 1) * 7 + x_MajorId)
           - 1])) {
        x_VarSet->SysSetting.HardwareVersionInfo[0] = temp_buff[0];
        x_VarSet->SysSetting.HardwareVersionInfo[1] = temp_buff[1];
        x_VarSet->SysSetting.HardwareVersionInfo[2] = temp_buff[2];
      }
      break;

     case 5:
     case 6:
      break;
    }
    break;

   case 7:
    if (x_MinorId == 1) {
      *y_FlashAccessErr = dataRead(x_MajorId, 1, x_Channel, temp_buff,
        test2_SysIntegration_B.VarSizeInfo[x_MajorId - 1]);
      if ((!*y_FlashAccessErr) && test2_SysIntegr_ValidityChkPass(temp_buff,
           test2_SysIntegration_B.VarSizeInfo[x_MajorId - 1])) {
        tmp = test2_SysInt_Trans4Bytes2Uint32(&temp_buff[0]);
        tmp_0 = test2_SysInt_Trans4Bytes2Uint32(&temp_buff[4]);
        tmp_1 = test2_SysInt_Trans4Bytes2Uint32(&temp_buff[8]);
        tmp_2 = test2_SysInt_Trans4Bytes2Uint32(&temp_buff[12]);
        x_VarSet->Calibra.MajorMcu4ChADCResolution[0] = tmp;
        x_VarSet->Calibra.MajorMcu4ChADCResolution[1] = tmp_0;
        x_VarSet->Calibra.MajorMcu4ChADCResolution[2] = tmp_1;
        x_VarSet->Calibra.MajorMcu4ChADCResolution[3] = tmp_2;
        x_VarSet->Calibra.MinorMcu4ChADCResolution[0] = ((((uint32_T)temp_buff
          [17] << 8U) + temp_buff[16]) + ((uint32_T)temp_buff[18] << 16U)) +
          ((uint32_T)temp_buff[19] << 24U);
        x_VarSet->Calibra.MinorMcu4ChADCResolution[1] = ((((uint32_T)temp_buff
          [21] << 8U) + temp_buff[20]) + ((uint32_T)temp_buff[22] << 16U)) +
          ((uint32_T)temp_buff[23] << 24U);
        x_VarSet->Calibra.MinorMcu4ChADCResolution[2] = ((((uint32_T)temp_buff
          [25] << 8U) + temp_buff[24]) + ((uint32_T)temp_buff[26] << 16U)) +
          ((uint32_T)temp_buff[27] << 24U);
        x_VarSet->Calibra.MinorMcu4ChADCResolution[3] = ((((uint32_T)temp_buff
          [29] << 8U) + temp_buff[28]) + ((uint32_T)temp_buff[30] << 16U)) +
          ((uint32_T)temp_buff[31] << 24U);
        y_Uint16 = (uint16_T)((temp_buff[33] << 8) + temp_buff[32]);
        b_y_Uint16 = (uint16_T)((temp_buff[35] << 8) + temp_buff[34]);
        c_y_Uint16 = (uint16_T)((temp_buff[37] << 8) + temp_buff[36]);
        d_y_Uint16 = (uint16_T)((temp_buff[39] << 8) + temp_buff[38]);
        if (y_Uint16 >= 32768) {
          x_VarSet->Calibra.MajorMCU4ChADCOffset[0] = (int16_T)(y_Uint16 - 65536);
        } else {
          x_VarSet->Calibra.MajorMCU4ChADCOffset[0] = (int16_T)y_Uint16;
        }

        if (b_y_Uint16 >= 32768) {
          x_VarSet->Calibra.MajorMCU4ChADCOffset[1] = (int16_T)(b_y_Uint16 -
            65536);
        } else {
          x_VarSet->Calibra.MajorMCU4ChADCOffset[1] = (int16_T)b_y_Uint16;
        }

        if (c_y_Uint16 >= 32768) {
          x_VarSet->Calibra.MajorMCU4ChADCOffset[2] = (int16_T)(c_y_Uint16 -
            65536);
        } else {
          x_VarSet->Calibra.MajorMCU4ChADCOffset[2] = (int16_T)c_y_Uint16;
        }

        if (d_y_Uint16 >= 32768) {
          x_VarSet->Calibra.MajorMCU4ChADCOffset[3] = (int16_T)(d_y_Uint16 -
            65536);
        } else {
          x_VarSet->Calibra.MajorMCU4ChADCOffset[3] = (int16_T)d_y_Uint16;
        }

        y_Uint16 = (uint16_T)((temp_buff[41] << 8) + temp_buff[40]);
        b_y_Uint16 = (uint16_T)((temp_buff[43] << 8) + temp_buff[42]);
        c_y_Uint16 = (uint16_T)((temp_buff[45] << 8) + temp_buff[44]);
        d_y_Uint16 = (uint16_T)((temp_buff[47] << 8) + temp_buff[46]);
        if (y_Uint16 >= 32768) {
          x_VarSet->Calibra.MinorMCU4ChADCOffset[0] = (int16_T)(y_Uint16 - 65536);
        } else {
          x_VarSet->Calibra.MinorMCU4ChADCOffset[0] = (int16_T)y_Uint16;
        }

        if (b_y_Uint16 >= 32768) {
          x_VarSet->Calibra.MinorMCU4ChADCOffset[1] = (int16_T)(b_y_Uint16 -
            65536);
        } else {
          x_VarSet->Calibra.MinorMCU4ChADCOffset[1] = (int16_T)b_y_Uint16;
        }

        if (c_y_Uint16 >= 32768) {
          x_VarSet->Calibra.MinorMCU4ChADCOffset[2] = (int16_T)(c_y_Uint16 -
            65536);
        } else {
          x_VarSet->Calibra.MinorMCU4ChADCOffset[2] = (int16_T)c_y_Uint16;
        }

        if (d_y_Uint16 >= 32768) {
          x_VarSet->Calibra.MinorMCU4ChADCOffset[3] = (int16_T)(d_y_Uint16 -
            65536);
        } else {
          x_VarSet->Calibra.MinorMCU4ChADCOffset[3] = (int16_T)d_y_Uint16;
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysIntegration_Init(const type_HMI2SecurityMsg *UnitDelay_d)
{
  boolean_T sf_internal_predicateOutput;
  boolean_T b_p;
  int32_T tmp;
  uint8_T tmp_0;
  sf_internal_predicateOutput = ((test2_SysIntegration_DW.temporalCounter_i1_n >=
    30U) && ((test2_SysIntegration_DW.bitsForTID4.is_Init ==
              t_IN_KeepFirmwareVarValueConfig) ||
             (test2_SysIntegration_DW.bitsForTID4.is_Init ==
              test2_S_IN_InitFromFlashSucceed)) &&
    test2_SysIntegration_B.UnitDelay_m);
  if (sf_internal_predicateOutput) {
    test2_SysIntegration_DW.prevFlashAccessMsgId =
      test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Head.MsgId;
    test2_SysIntegration_DW.prevAlarmInfoMsgId = UnitDelay_d->Head.MsgId;
    test2_SysIntegration_DW.bitsForTID4.is_Init = 0;
    test2_SysIntegration_DW.bitsForTID4.is_FlashDrv =
      test2_SysIntegrat_IN_FlashDrive;
    test2_SysIntegration_DW.bitsForTID4.was_FlashDrv =
      test2_SysIntegrat_IN_FlashDrive;
    test2_SysIntegration_DW.temporalCounter_i4 = 0U;
    test2_enter_internal_FlashDrive();
  } else {
    switch (test2_SysIntegration_DW.bitsForTID4.is_Init) {
     case test2_Sy_IN_ChkFlashWriteStatus:
      sf_internal_predicateOutput = false;
      b_p = true;
      if (!(test2_SysIntegration_B.VarSet.SysSetting.FlashConfigFlag == 175)) {
        b_p = false;
      }

      if (b_p) {
        sf_internal_predicateOutput = true;
      }

      if (sf_internal_predicateOutput) {
        test2_SysIntegration_DW.VarIndex = 0U;
        test2_SysIntegration_DW.bitsForTID4.is_Init =
          t_IN_InitEachMemberVarFromFlash;
        test2_SysIntegration_DW.bitsForTID4.was_Init =
          t_IN_InitEachMemberVarFromFlash;
        test2_SysIntegration_DW.MajorId = (uint8_T)((int32_T)
          (test2_SysIntegration_DW.VarIndex / 6U) + 1);
        test2_SysIntegration_DW.MinorId = (uint8_T)((uint8_T)
          (test2_SysIntegration_DW.VarIndex % 6) + 1);
        test_EachVarMemberInitFromFlash(test2_SysIntegration_DW.Channel,
          &test2_SysIntegration_B.VarSet, test2_SysIntegration_DW.MajorId,
          test2_SysIntegration_DW.MinorId, &sf_internal_predicateOutput, &tmp_0);
        test2_SysIntegration_DW.Channel = tmp_0;
        test2_SysIntegration_DW.bitsForTID4.FlashAccessErr =
          sf_internal_predicateOutput;
      } else {
        sf_internal_predicateOutput = false;
        b_p = true;
        if (!(test2_SysIntegration_B.VarSet.SysSetting.FlashConfigFlag == 175))
        {
          b_p = false;
        }

        if (b_p) {
          sf_internal_predicateOutput = true;
        }

        if (!sf_internal_predicateOutput) {
          test2_SysIntegration_DW.bitsForTID4.is_Init =
            t_IN_KeepFirmwareVarValueConfig;
          test2_SysIntegration_DW.bitsForTID4.was_Init =
            t_IN_KeepFirmwareVarValueConfig;
        }
      }
      break;

     case t_IN_InitEachMemberVarFromFlash:
      if (test2_SysIntegration_DW.VarIndex < 41) {
        tmp = (int32_T)(test2_SysIntegration_DW.VarIndex + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        test2_SysIntegration_DW.VarIndex = (uint8_T)((uint8_T)tmp % 42);
        test2_SysIntegration_DW.bitsForTID4.is_Init =
          t_IN_InitEachMemberVarFromFlash;
        test2_SysIntegration_DW.bitsForTID4.was_Init =
          t_IN_InitEachMemberVarFromFlash;
        test2_SysIntegration_DW.MajorId = (uint8_T)((int32_T)
          (test2_SysIntegration_DW.VarIndex / 6U) + 1);
        test2_SysIntegration_DW.MinorId = (uint8_T)((uint8_T)
          (test2_SysIntegration_DW.VarIndex % 6) + 1);
        test_EachVarMemberInitFromFlash(test2_SysIntegration_DW.Channel,
          &test2_SysIntegration_B.VarSet, test2_SysIntegration_DW.MajorId,
          test2_SysIntegration_DW.MinorId, &sf_internal_predicateOutput, &tmp_0);
        test2_SysIntegration_DW.Channel = tmp_0;
        test2_SysIntegration_DW.bitsForTID4.FlashAccessErr =
          sf_internal_predicateOutput;
      } else {
        sf_internal_predicateOutput = false;
        b_p = true;
        if (!(test2_SysIntegration_DW.VarIndex == 41)) {
          b_p = false;
        }

        if (b_p) {
          sf_internal_predicateOutput = true;
        }

        if (sf_internal_predicateOutput) {
          test2_SysIntegration_DW.bitsForTID4.is_Init =
            test2_S_IN_InitFromFlashSucceed;
          test2_SysIntegration_DW.bitsForTID4.was_Init =
            test2_S_IN_InitFromFlashSucceed;
        }
      }
      break;

     case test2_SysIn_IN_InitFromFirmware:
      test2_SysIntegration_DW.bitsForTID4.is_Init =
        test2_Sy_IN_ChkFlashWriteStatus;
      test2_SysIntegration_DW.bitsForTID4.was_Init =
        test2_Sy_IN_ChkFlashWriteStatus;
      test2_SysIntegration_DW.MajorId = 5U;
      test2_SysIntegration_DW.MinorId = 5U;
      test2_SysIntegration_DW.Channel = 1U;
      test_EachVarMemberInitFromFlash(test2_SysIntegration_DW.Channel,
        &test2_SysIntegration_B.VarSet, test2_SysIntegration_DW.MajorId,
        test2_SysIntegration_DW.MinorId, &sf_internal_predicateOutput, &tmp_0);
      test2_SysIntegration_DW.Channel = tmp_0;
      test2_SysIntegration_DW.bitsForTID4.FlashAccessErr =
        sf_internal_predicateOutput;
      break;

     case test2_S_IN_InitFromFlashSucceed:
     case t_IN_KeepFirmwareVarValueConfig:
      break;
    }
  }
}

/* Function for Chart: '<S63>/Chart' */
static void test2_Sy_VarSetInitFromFirmware(uint8_T
  *y_VarSet_DoseCtrl_DoseCtrlParam, uint8_T *y_VarSet_DoseCtrl_DoseCtrlPar_0,
  uint16_T *y_VarSet_DoseCtrl_DoseCtrlPar_1, uint16_T
  *y_VarSet_DoseCtrl_DoseCtrlPar_2, uint8_T *y_VarSet_DoseCtrl_DoseCtrlPar_3,
  uint8_T y_VarSet_DoseCtrl_BaseRateConfi[48], uint8_T
  y_VarSet_DoseCtrl_TempBaseRateC[48], uint8_T y_VarSet_DoseCtrl_LastTBRConfig[3],
  uint16_T *y_VarSet_DoseCtrl_LargeDoseConf, uint8_T
  *y_VarSet_DoseCtrl_LargeDoseCo_0, uint8_T *y_VarSet_DoseCtrl_LargeDoseCo_1,
  uint16_T *y_VarSet_DoseCtrl_LargeDoseCo_2, uint16_T
  *y_VarSet_DoseCtrl_LargeDoseCo_3, uint8_T y_VarSet_DoseCtrl_LargeDoseCo_4[20],
  uint8_T y_VarSet_DoseCtrl_LargeDoseCo_5[20], uint8_T
  *y_VarSet_ActCtrl_IniLoadedVol, uint16_T *y_VarSet_ActCtrl_AdjustInputGai,
  uint16_T *y_VarSet_ActCtrl_AdjustPositive, uint16_T
  *y_VarSet_ActCtrl_AdjustNegative, uint8_T *y_VarSet_ActCtrl_DeliverSwitch,
  type_VarBody4ActCtrlDynVar *y_VarSet_ActCtrl_BaseRateDynVar,
  type_VarBody4ActCtrlDynVar *y_VarSet_ActCtrl_LargeDoseDynVa,
  type_VarBody4ActCtrlDailyStat *y_VarSet_ActCtrl_DailyDoseStatV, uint8_T
  *y_VarSet_AlarmCtrl_AlarmCtrlCon, int32_T y_VarSet_AlarmCtrl_SSCurAndProc[8],
  type_CatBody4Firmware *y_VarSet_Firmware, type_CatBody4SysSetting
  *y_VarSet_SysSetting, Type_Occlusion *y_VarSet_Occlusion, type_CatBody4Calibra
  *y_VarSet_Calibra)
{
  static const uint8_T b[6] = { 20U, 1U, 0U, 20U, 1U, 0U };

  int32_T i;
  *y_VarSet_DoseCtrl_DoseCtrlParam = 100U;
  *y_VarSet_DoseCtrl_DoseCtrlPar_0 = 5U;
  *y_VarSet_DoseCtrl_DoseCtrlPar_1 = 480U;
  *y_VarSet_DoseCtrl_DoseCtrlPar_2 = 240U;
  *y_VarSet_DoseCtrl_DoseCtrlPar_3 = 80U;
  for (i = 0; i < 48; i++) {
    y_VarSet_DoseCtrl_BaseRateConfi[i] = 0U;
    y_VarSet_DoseCtrl_TempBaseRateC[i] = 0U;
  }

  y_VarSet_DoseCtrl_LastTBRConfig[0] = 0U;
  y_VarSet_DoseCtrl_LastTBRConfig[1] = 0U;
  y_VarSet_DoseCtrl_LastTBRConfig[2] = 0U;
  *y_VarSet_DoseCtrl_LargeDoseConf = 0U;
  *y_VarSet_DoseCtrl_LargeDoseCo_0 = 0U;
  *y_VarSet_DoseCtrl_LargeDoseCo_1 = 15U;
  *y_VarSet_DoseCtrl_LargeDoseCo_2 = 0U;
  *y_VarSet_DoseCtrl_LargeDoseCo_3 = 0U;
  for (i = 0; i < 20; i++) {
    y_VarSet_DoseCtrl_LargeDoseCo_4[i] = 0U;
    y_VarSet_DoseCtrl_LargeDoseCo_5[i] = 0U;
  }

  *y_VarSet_ActCtrl_IniLoadedVol = 30U;
  *y_VarSet_ActCtrl_AdjustInputGai = 1000U;
  *y_VarSet_ActCtrl_AdjustPositive = 0U;
  *y_VarSet_ActCtrl_AdjustNegative = 0U;
  *y_VarSet_ActCtrl_DeliverSwitch = 0U;
  y_VarSet_ActCtrl_BaseRateDynVar->TargetDose = 0U;
  y_VarSet_ActCtrl_BaseRateDynVar->TimeInfo = 0U;
  y_VarSet_ActCtrl_BaseRateDynVar->CompleteDose = 0U;
  y_VarSet_ActCtrl_LargeDoseDynVa->TargetDose = 0U;
  y_VarSet_ActCtrl_LargeDoseDynVa->TimeInfo = 0U;
  y_VarSet_ActCtrl_LargeDoseDynVa->CompleteDose = 0U;
  y_VarSet_ActCtrl_DailyDoseStatV->DayInfo = 0U;
  y_VarSet_ActCtrl_DailyDoseStatV->ResidueDoseEst = MAX_uint32_T;
  y_VarSet_ActCtrl_DailyDoseStatV->TotalAmountAcc = 0U;
  y_VarSet_ActCtrl_DailyDoseStatV->DailyAmountAcc = 0U;
  y_VarSet_ActCtrl_DailyDoseStatV->LargeAmountAcc = 0U;
  *y_VarSet_AlarmCtrl_AlarmCtrlCon = 0U;
  for (i = 0; i < 8; i++) {
    y_VarSet_AlarmCtrl_SSCurAndProc[i] = MAX_int32_T;
  }

  y_VarSet_Firmware->FirmwareSize = MAX_uint32_T;
  y_VarSet_Firmware->FirmwareCRC32 = 0U;
  y_VarSet_Firmware->FirmwareUpgradeCompleteFlag = 0U;
  y_VarSet_SysSetting->SensitivityLevel = 3U;
  for (i = 0; i < 10; i++) {
    y_VarSet_SysSetting->SerialNo[i] = 0U;
  }

  for (i = 0; i < 6; i++) {
    y_VarSet_SysSetting->SoftwareVersionInfo[i] = b[i];
  }

  y_VarSet_SysSetting->HardwareVersionInfo[0] = 0U;
  y_VarSet_SysSetting->HardwareVersionInfo[1] = 0U;
  y_VarSet_SysSetting->HardwareVersionInfo[2] = 0U;
  y_VarSet_SysSetting->FlashConfigFlag = 187U;
  memset(&y_VarSet_Occlusion->PT[0], 0, 99U * sizeof(uint32_T));
  memset(&y_VarSet_Occlusion->CI[0], 0, 99U * sizeof(uint32_T));
  y_VarSet_Calibra->MajorMcu4ChADCResolution[0] = 0U;
  y_VarSet_Calibra->MinorMcu4ChADCResolution[0] = 0U;
  y_VarSet_Calibra->MajorMCU4ChADCOffset[0] = 0;
  y_VarSet_Calibra->MinorMCU4ChADCOffset[0] = 0;
  y_VarSet_Calibra->MajorMcu4ChADCResolution[1] = 0U;
  y_VarSet_Calibra->MinorMcu4ChADCResolution[1] = 0U;
  y_VarSet_Calibra->MajorMCU4ChADCOffset[1] = 0;
  y_VarSet_Calibra->MinorMCU4ChADCOffset[1] = 0;
  y_VarSet_Calibra->MajorMcu4ChADCResolution[2] = 0U;
  y_VarSet_Calibra->MinorMcu4ChADCResolution[2] = 0U;
  y_VarSet_Calibra->MajorMCU4ChADCOffset[2] = 0;
  y_VarSet_Calibra->MinorMCU4ChADCOffset[2] = 0;
  y_VarSet_Calibra->MajorMcu4ChADCResolution[3] = 0U;
  y_VarSet_Calibra->MinorMcu4ChADCResolution[3] = 0U;
  y_VarSet_Calibra->MajorMCU4ChADCOffset[3] = 0;
  y_VarSet_Calibra->MinorMCU4ChADCOffset[3] = 0;
}

/* Function for Chart: '<S63>/Chart' */
static void t_enter_atomic_InitFromFirmware(void)
{
  type_MsgBody4FlashResponseMsg b;
  static const uint8_T tmp[42] = { 7U, 1U, 1U, 8U, 1U, 132U, 48U, 48U, 6U, 32U,
    132U, 10U, 132U, 0U, 48U, 1U, 0U, 0U, 6U, 132U, 0U, 3U, 10U, 0U, 1U, 3U,
    132U, 0U, 48U, 10U, 0U, 0U, 1U, 132U, 0U, 0U, 17U, 0U, 0U, 0U, 132U, 0U };

  int32_T i;
  for (i = 0; i < 42; i++) {
    test2_SysIntegration_B.VarSizeInfo[i] = tmp[i];
  }

  test2_SysIntegration_B.SysDiagMsgOut_d.Head.MsgId = 0U;
  test2_SysIntegration_B.SysDiagMsgOut_d.Head.OpCode = 0U;
  test2_SysIntegration_B.SysDiagMsgOut_d.Body.Data = 0U;
  test2_Sy_VarSetInitFromFirmware
    (&test2_SysIntegration_B.VarSet.DoseCtrl.DoseCtrlParam.Concentration,
     &test2_SysIntegration_B.VarSet.DoseCtrl.DoseCtrlParam.LowDoseTHValue,
     &test2_SysIntegration_B.VarSet.DoseCtrl.DoseCtrlParam.MaxLargeDose,
     &test2_SysIntegration_B.VarSet.DoseCtrl.DoseCtrlParam.MaxBaseRate,
     &test2_SysIntegration_B.VarSet.DoseCtrl.DoseCtrlParam.MaxDailyDose,
     test2_SysIntegration_B.VarSet.DoseCtrl.BaseRateConfig,
     test2_SysIntegration_B.VarSet.DoseCtrl.TempBaseRateConfig,
     test2_SysIntegration_B.VarSet.DoseCtrl.LastTBRConfigDay,
     &test2_SysIntegration_B.VarSet.DoseCtrl.LargeDoseConfig.LargeDoseTotalAmount,
     &test2_SysIntegration_B.VarSet.DoseCtrl.LargeDoseConfig.DeliveryConfig,
     &test2_SysIntegration_B.VarSet.DoseCtrl.LargeDoseConfig.PermittedTime,
     &test2_SysIntegration_B.VarSet.DoseCtrl.LargeDoseConfig.RegularDose4DWMCase,
     &test2_SysIntegration_B.VarSet.DoseCtrl.LargeDoseConfig.EffectiveDay,
     test2_SysIntegration_B.VarSet.DoseCtrl.LargeDoseConfig.CustomTimeConfig,
     test2_SysIntegration_B.VarSet.DoseCtrl.LargeDoseConfig.CustomDoseConfig,
     &test2_SysIntegration_B.VarSet.ActCtrl.IniLoadedVol,
     &test2_SysIntegration_B.VarSet.ActCtrl.AdjustInputGain,
     &test2_SysIntegration_B.VarSet.ActCtrl.AdjustPositiveOffset,
     &test2_SysIntegration_B.VarSet.ActCtrl.AdjustNegativeOffset,
     &test2_SysIntegration_B.VarSet.ActCtrl.DeliverSwitch,
     &test2_SysIntegration_B.VarSet.ActCtrl.BaseRateDynVar,
     &test2_SysIntegration_B.VarSet.ActCtrl.LargeDoseDynVar,
     &test2_SysIntegration_B.VarSet.ActCtrl.DailyDoseStatVar,
     &test2_SysIntegration_B.VarSet.AlarmCtrl.AlarmCtrlConfig,
     test2_SysIntegration_B.VarSet.AlarmCtrl.SSCurAndProcTimeCritPolyFitVect,
     &test2_SysIntegration_B.VarSet.Firmware,
     &test2_SysIntegration_B.VarSet.SysSetting,
     &test2_SysIntegration_B.VarSet.Occlusion,
     &test2_SysIntegration_B.VarSet.Calibra);
  test2_SysIntegration_B.LogDataMsg.Head.MsgId = 0U;
  test2_SysIntegration_B.LogDataMsg.Head.OpCode = 0U;
  b.MajorId = 0U;
  b.MinorId = 0U;
  for (i = 0; i < 44; i++) {
    b.Data[i] = 0U;
  }

  test2_SysIntegration_B.LogDataMsg.Body = b;
  test2_SysIntegration_DW.FirmwareParam.CurDataBagBytes = 0U;
  test2_SysIntegration_DW.FirmwareParam.TargetDataBagNo = MAX_uint32_T;
  test2_SysIntegration_DW.FirmwareParam.CurDataBagNo = 0U;
  test2_SysIntegration_DW.FirmwareParam.TargetCRC32Val = MAX_uint32_T;
  test2_SysIntegration_DW.FirmwareParam.PrevCRC32Val = MAX_uint32_T;
  test2_SysIntegration_DW.FirmwareParam.boolGetHead = false;
  test2_SysIntegration_DW.FirmwareParam.boolGet1Bag = false;
  test2_SysIntegration_DW.FirmwareParam.boolTransIng = false;
  test2_SysIntegration_DW.FirmwareParam.boolBagNoHit = false;
  test2_SysIntegration_DW.FirmwareParam.boolCRC32Hit = false;
  test2_SysIntegration_DW.TypexLogId[0] = 0U;
  test2_SysIntegration_DW.TypexLogId[1] = 0U;
  test2_SysIntegration_DW.TypexLogId[2] = 0U;
  test2_SysIntegration_DW.TypexLogId[3] = 0U;
}

/* Function for Chart: '<S63>/Chart' */
static void test2_SysIn_enter_internal_Init(void)
{
  boolean_T FlashAccessErr;
  uint8_T tmp;
  switch (test2_SysIntegration_DW.bitsForTID4.was_Init) {
   case test2_Sy_IN_ChkFlashWriteStatus:
    if (test2_SysIntegration_DW.bitsForTID4.is_Init !=
        test2_Sy_IN_ChkFlashWriteStatus) {
      test2_SysIntegration_DW.bitsForTID4.is_Init =
        test2_Sy_IN_ChkFlashWriteStatus;
      test2_SysIntegration_DW.bitsForTID4.was_Init =
        test2_Sy_IN_ChkFlashWriteStatus;
      test2_SysIntegration_DW.MajorId = 5U;
      test2_SysIntegration_DW.MinorId = 5U;
      test2_SysIntegration_DW.Channel = 1U;
      test_EachVarMemberInitFromFlash(test2_SysIntegration_DW.Channel,
        &test2_SysIntegration_B.VarSet, test2_SysIntegration_DW.MajorId,
        test2_SysIntegration_DW.MinorId, &FlashAccessErr, &tmp);
      test2_SysIntegration_DW.Channel = tmp;
      test2_SysIntegration_DW.bitsForTID4.FlashAccessErr = FlashAccessErr;
    }
    break;

   case t_IN_InitEachMemberVarFromFlash:
    if (test2_SysIntegration_DW.bitsForTID4.is_Init !=
        t_IN_InitEachMemberVarFromFlash) {
      test2_SysIntegration_DW.bitsForTID4.is_Init =
        t_IN_InitEachMemberVarFromFlash;
      test2_SysIntegration_DW.bitsForTID4.was_Init =
        t_IN_InitEachMemberVarFromFlash;
      test2_SysIntegration_DW.MajorId = (uint8_T)((int32_T)
        (test2_SysIntegration_DW.VarIndex / 6U) + 1);
      test2_SysIntegration_DW.MinorId = (uint8_T)((uint8_T)
        (test2_SysIntegration_DW.VarIndex % 6) + 1);
      test_EachVarMemberInitFromFlash(test2_SysIntegration_DW.Channel,
        &test2_SysIntegration_B.VarSet, test2_SysIntegration_DW.MajorId,
        test2_SysIntegration_DW.MinorId, &FlashAccessErr, &tmp);
      test2_SysIntegration_DW.Channel = tmp;
      test2_SysIntegration_DW.bitsForTID4.FlashAccessErr = FlashAccessErr;
    }
    break;

   case test2_SysIn_IN_InitFromFirmware:
    if (test2_SysIntegration_DW.bitsForTID4.is_Init !=
        test2_SysIn_IN_InitFromFirmware) {
      test2_SysIntegration_DW.bitsForTID4.is_Init =
        test2_SysIn_IN_InitFromFirmware;
      test2_SysIntegration_DW.bitsForTID4.was_Init =
        test2_SysIn_IN_InitFromFirmware;
      t_enter_atomic_InitFromFirmware();
    }
    break;

   case test2_S_IN_InitFromFlashSucceed:
    test2_SysIntegration_DW.bitsForTID4.is_Init =
      test2_S_IN_InitFromFlashSucceed;
    test2_SysIntegration_DW.bitsForTID4.was_Init =
      test2_S_IN_InitFromFlashSucceed;
    break;

   case t_IN_KeepFirmwareVarValueConfig:
    if (test2_SysIntegration_DW.bitsForTID4.is_Init !=
        t_IN_KeepFirmwareVarValueConfig) {
      test2_SysIntegration_DW.bitsForTID4.is_Init =
        t_IN_KeepFirmwareVarValueConfig;
      test2_SysIntegration_DW.bitsForTID4.was_Init =
        t_IN_KeepFirmwareVarValueConfig;
    }
    break;

   default:
    if (test2_SysIntegration_DW.bitsForTID4.is_Init !=
        test2_SysIn_IN_InitFromFirmware) {
      test2_SysIntegration_DW.bitsForTID4.is_Init =
        test2_SysIn_IN_InitFromFirmware;
      test2_SysIntegration_DW.bitsForTID4.was_Init =
        test2_SysIn_IN_InitFromFirmware;
      t_enter_atomic_InitFromFirmware();
    }
    break;
  }
}

/* Function for Chart: '<S63>/Chart' */
static void test2_S_enter_internal_FlashDrv(void)
{
  switch (test2_SysIntegration_DW.bitsForTID4.was_FlashDrv) {
   case test2_SysIntegrat_IN_FlashDrive:
    if (test2_SysIntegration_DW.bitsForTID4.is_FlashDrv !=
        test2_SysIntegrat_IN_FlashDrive) {
      test2_SysIntegration_DW.bitsForTID4.is_FlashDrv =
        test2_SysIntegrat_IN_FlashDrive;
      test2_SysIntegration_DW.bitsForTID4.was_FlashDrv =
        test2_SysIntegrat_IN_FlashDrive;
      test2_SysIntegration_DW.temporalCounter_i4 = 0U;
    }

    test2_enter_internal_FlashDrive();
    break;

   case test2_SysIntegration_IN_Init_b:
    if (test2_SysIntegration_DW.bitsForTID4.is_FlashDrv !=
        test2_SysIntegration_IN_Init_b) {
      test2_SysIntegration_DW.bitsForTID4.is_FlashDrv =
        test2_SysIntegration_IN_Init_b;
      test2_SysIntegration_DW.bitsForTID4.was_FlashDrv =
        test2_SysIntegration_IN_Init_b;
      test2_SysIntegration_DW.temporalCounter_i1_n = 0U;
    }

    test2_SysIn_enter_internal_Init();
    break;

   default:
    if (test2_SysIntegration_DW.bitsForTID4.is_FlashDrv !=
        test2_SysIntegration_IN_Init_b) {
      test2_SysIntegration_DW.bitsForTID4.is_FlashDrv =
        test2_SysIntegration_IN_Init_b;
      test2_SysIntegration_DW.bitsForTID4.was_FlashDrv =
        test2_SysIntegration_IN_Init_b;
      test2_SysIntegration_DW.temporalCounter_i1_n = 0U;
    }

    test2_SysIn_enter_internal_Init();
    break;
  }
}

/* Function for Chart: '<S51>/Chart' */
static uint8_T test2_SysIntegr_findFirstTarget(const uint8_T x_InputVect[5],
  uint8_T x_TargetValue)
{
  uint8_T y_TargetValueIndex;
  int32_T i;
  boolean_T p;
  boolean_T b_p;
  boolean_T exitg1;
  y_TargetValueIndex = 0U;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 5)) {
    p = false;
    b_p = true;
    if (!(x_InputVect[i] == x_TargetValue)) {
      b_p = false;
    }

    if (b_p) {
      p = true;
    }

    if (p) {
      y_TargetValueIndex = (uint8_T)(1 + i);
      exitg1 = true;
    } else {
      i++;
    }
  }

  return y_TargetValueIndex;
}

/* Function for Chart: '<S49>/Chart' */
static void test2_Sy_enter_atomic_HoldStage(void)
{
  int32_T tmp;
  switch (test2_SysIntegration_DW.WakeUpMode) {
   case 0:
   case 2:
   case 3:
    test2_SysIntegration_B.bitsForTID4.boolLCDOn = true;
    test2_SysIntegration_DW.LCDCtrlEvtEventCounter++;
    test2_SysIntegration_B.bitsForTID4.IOSwitchCmd = true;
    test2_SysIntegration_DW.IOSwitchCtrlEvtEventCounter++;
    break;

   case 1:
    test2_SysIntegration_B.bitsForTID4.IOSwitchCmd = true;
    test2_SysIntegration_DW.IOSwitchCtrlEvtEventCounter++;
    break;
  }

  if (test2_SysIntegration_DW.SleepFailureTimes > 5) {
    test2_SysIntegration_DW.SleepFailureTimes = 0U;
    test2_SysIntegration_B.SysDiagMsg_a.Head.OpCode = 1U;
    tmp = (int32_T)(test2_SysIntegration_B.SysDiagMsg_a.Head.MsgId + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    test2_SysIntegration_B.SysDiagMsg_a.Head.MsgId = (uint8_T)((uint8_T)tmp %
      MAX_uint8_T);
    test2_SysIntegration_B.SysDiagMsg_a.Body.Data = 102U;
  }
}

/* Function for Chart: '<S49>/Chart' */
static void test2_SysIntegration_LPCtrl_c(const type_LowPower2RTCtrlMsg
  *UnitDelay1_p, const type_HMI2SecurityMsg *UnitDelay_o)
{
  boolean_T sf_internal_predicateOutput;
  boolean_T b_p;
  int32_T tmp;
  uint32_T b_sf_internal_predicateOutput_t;
  boolean_T guard1 = false;
  if (test2_SysIntegration_DW.temp_errTime > 3) {
    switch (test2_SysIntegration_DW.bitsForTID4.is_LPCtrl) {
     case test2_SysIntegration_IN_Idle:
      test2_SysIntegration_DW.bitsForTID4.is_LPCtrl = 0;
      break;

     case test2_SysIntegra_IN_LPCtrlStage:
      test2_SysIntegration_DW.bitsForTID4.boolWakeUpSuccess = false;
      test2_SysIntegration_DW.bitsForTID4.is_LPCtrl = 0;
      break;

     default:
      test2_SysIntegration_DW.bitsForTID4.is_HoldStage = 0;
      test2_SysIntegration_DW.bitsForTID4.is_LPCtrl = 0;
      test2_SysIntegration_DW.bitsForTID4.is_IOCtrlStage = 0;
      break;
    }

    test2_SysIntegration_DW.bitsForTID4.is_c6_test2_SysIntegration =
      test2__IN_SlaveMcuWakeUpFailure;
    test2_SysIntegration_DW.temp_errTime = 0U;
    test2_SysIntegration_B.SysDiagMsg_a.Head.OpCode = 1U;
    tmp = (int32_T)(test2_SysIntegration_B.SysDiagMsg_a.Head.MsgId + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    test2_SysIntegration_B.SysDiagMsg_a.Head.MsgId = (uint8_T)((uint8_T)tmp %
      MAX_uint8_T);
    test2_SysIntegration_B.SysDiagMsg_a.Body.Data = 19U;
  } else {
    if (test2_SysIntegration_DW.bitsForTID4.boolHibernation) {
      test2_SysIntegration_DW.bitsForTID4.boolHibernation = false;
      test2_SysIntegration_B.SleepSec = 0U;
      test2_SysIntegration_DW.LPSwitchCtrlEvtEventCounter++;
    }

    if (UnitDelay1_p->Head.MsgId != test2_SysIntegration_DW.prevLPCompTimeMsgId)
    {
      tmp = (int32_T)(test2_SysIntegration_B.LP2RTMsgOut.Head.MsgId + 1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      test2_SysIntegration_B.LP2RTMsgOut.Head.MsgId = (uint8_T)((uint8_T)tmp %
        MAX_uint8_T);
      test2_SysIntegration_B.LP2RTMsgOut.Head.OpCode = 1U;
      test2_SysIntegration_B.LP2RTMsgOut.Body = UnitDelay1_p->Body;
      test2_SysIntegration_DW.WakeUpMode = UnitDelay1_p->Head.OpCode;
      test2_SysIntegration_DW.prevLPCompTimeMsgId = UnitDelay1_p->Head.MsgId;
    }

    guard1 = false;
    switch (test2_SysIntegration_DW.bitsForTID4.is_LPCtrl) {
     case test2_SysIntegrati_IN_HoldStage:
      if (test2_SysIntegration_DW.bitsForTID4.is_HoldStage ==
          test2_SysIntegratio_IN_DeepHold) {
        test2_SysIntegration_DW.bitsForTID4.is_HoldStage = 0;
        test2_SysIntegration_DW.bitsForTID4.is_LPCtrl =
          test2_SysIntegra_IN_IOCtrlStage;
        test2_SysIntegration_DW.temporalCounter_i1_d = 0U;
        test2_SysIntegration_DW.bitsForTID4.is_IOCtrlStage =
          test2_IN_WaitForRespBeforeSleep;
        test2_SysIntegration_B.bitsForTID4.IOSwitchCmd = false;
        test2_SysIntegration_DW.IOSwitchCtrlEvtEventCounter++;
        test2_SysIntegration_B.bitsForTID4.boolLCDOn = false;
        test2_SysIntegration_DW.LCDCtrlEvtEventCounter++;
        test2_SysIntegration_B.SecurityMsgOut.Head.OpCode = MAX_uint8_T;
        tmp = (int32_T)(test2_SysIntegration_B.SecurityMsgOut.Head.MsgId + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        test2_SysIntegration_B.SecurityMsgOut.Head.MsgId = (uint8_T)((uint8_T)
          tmp % MAX_uint8_T);
        test2_SysIntegration_DW.prevInSecurityMsgId = UnitDelay_o->Head.MsgId;
      } else {
        switch (test2_SysIntegration_DW.bitsForTID4.is_HoldStage) {
         case test2_SysIntegratio_IN_DeepHold:
          break;

         default:
          if (test2_SysIntegration_DW.temporalCounter_i1_d >= (uint8_T)
              (test2_SysIntegration_DW.CtrlParam.IO_Off_Delay * 10U)) {
            test2_SysIntegration_DW.bitsForTID4.is_HoldStage =
              test2_SysIntegratio_IN_DeepHold;
          } else {
            if (test2_SysIntegration_B.BusCreator_h.AlarmStatus ||
                test2_SysIntegration_B.BusCreator_h.HMIStatus ||
                test2_SysIntegration_B.BusCreator_h.RecordStatus ||
                test2_SysIntegration_B.BusCreator_h.BleCommStatus ||
                test2_SysIntegration_B.BusCreator_h.SerialCommStatus ||
                (test2_SysIntegration_B.BusCreator_h.NextHitSec <=
                 test2_SysIntegration_DW.CtrlParam.HibDeadZone)) {
              test2_SysIntegration_DW.bitsForTID4.is_HoldStage =
                test2_SysIntegra_IN_ShallowHold;
              test2_SysIntegration_DW.temporalCounter_i1_d = 0U;
            }
          }
          break;
        }
      }
      break;

     case test2_SysIntegra_IN_IOCtrlStage:
      b_sf_internal_predicateOutput_t = (uint8_T)
        (test2_SysIntegration_DW.CtrlParam.ChipHibDelay * 10U);
      sf_internal_predicateOutput =
        ((test2_SysIntegration_DW.temporalCounter_i1_d >=
          b_sf_internal_predicateOutput_t) &&
         (test2_SysIntegration_DW.bitsForTID4.is_IOCtrlStage ==
          test2_SysIntegrati_IN_HandShake));
      if (sf_internal_predicateOutput) {
        test2_SysIntegration_DW.SleepFailureTimes = 0U;
        test2_SysIntegration_DW.bitsForTID4.is_IOCtrlStage = 0;
        test2_SysIntegration_DW.bitsForTID4.is_LPCtrl =
          test2_SysIntegra_IN_LPCtrlStage;
        test2_SysIntegration_DW.bitsForTID4.boolHibernation = true;
        b_sf_internal_predicateOutput_t = (uint32_T)
          test2_SysIntegration_B.BusCreator_h.NextHitSec - /*MW:OvSatOk*/
          test2_SysIntegration_DW.CtrlParam.WakeUpPreFuncSec;
        if (b_sf_internal_predicateOutput_t >
            test2_SysIntegration_B.BusCreator_h.NextHitSec) {
          b_sf_internal_predicateOutput_t = 0U;
        }

        test2_SysIntegration_B.SleepSec = (uint16_T)
          b_sf_internal_predicateOutput_t;
        test2_SysIntegration_DW.LPSwitchCtrlEvtEventCounter++;
      } else {
        sf_internal_predicateOutput =
          ((test2_SysIntegration_DW.temporalCounter_i1_d >=
            b_sf_internal_predicateOutput_t) &&
           (!(test2_SysIntegration_DW.bitsForTID4.is_IOCtrlStage ==
              test2_SysIntegrati_IN_HandShake)));
        if (sf_internal_predicateOutput) {
          tmp = (int32_T)(test2_SysIntegration_DW.SleepFailureTimes + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          test2_SysIntegration_DW.SleepFailureTimes = (uint8_T)tmp;
          guard1 = true;
        } else if (test2_SysIntegration_B.BusCreator_h.AlarmStatus) {
          test2_SysIntegration_DW.WakeUpMode = 3U;
          guard1 = true;
        } else {
          switch (test2_SysIntegration_DW.bitsForTID4.is_IOCtrlStage) {
           case test2_SysIntegrati_IN_HandShake:
            break;

           default:
            if (UnitDelay_o->Head.MsgId !=
                test2_SysIntegration_DW.prevInSecurityMsgId) {
              sf_internal_predicateOutput = false;
              b_p = true;
              if (!(UnitDelay_o->Head.OpCode == 255)) {
                b_p = false;
              }

              if (b_p) {
                sf_internal_predicateOutput = true;
              }
            } else {
              sf_internal_predicateOutput = false;
            }

            if (sf_internal_predicateOutput) {
              test2_SysIntegration_DW.prevInSecurityMsgId =
                UnitDelay_o->Head.MsgId;
              test2_SysIntegration_DW.bitsForTID4.is_IOCtrlStage =
                test2_SysIntegrati_IN_HandShake;
            }
            break;
          }
        }
      }
      break;

     case test2_SysIntegration_IN_Idle:
      if (test2_SysIntegration_DW.temporalCounter_i1_d >= 30U) {
        test2_SysIntegration_DW.bitsForTID4.is_LPCtrl =
          test2_SysIntegrati_IN_HoldStage;
        test2_Sy_enter_atomic_HoldStage();
        test2_SysIntegration_DW.bitsForTID4.is_HoldStage =
          test2_SysIntegra_IN_ShallowHold;
        test2_SysIntegration_DW.temporalCounter_i1_d = 0U;
      }
      break;

     case test2_SysIntegra_IN_LPCtrlStage:
      if (!test2_SysIntegration_DW.bitsForTID4.boolHibernation) {
        test2_SysIntegration_DW.bitsForTID4.boolWakeUpSuccess = false;
        test2_SysIntegration_DW.bitsForTID4.is_LPCtrl =
          test2_SysIntegra_IN_WakeUpSlave;
        test2_SysIntegration_DW.temporalCounter_i1_d = 0U;
        test2_SysIntegration_B.SecurityMsgOut.Head.OpCode = 254U;
        tmp = (int32_T)(test2_SysIntegration_B.SecurityMsgOut.Head.MsgId + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        test2_SysIntegration_B.SecurityMsgOut.Head.MsgId = (uint8_T)((uint8_T)
          tmp % MAX_uint8_T);
        test2_SysIntegration_DW.prevInSecurityMsgId = UnitDelay_o->Head.MsgId;
      }
      break;

     default:
      if (test2_SysIntegration_DW.bitsForTID4.boolWakeUpSuccess) {
        test2_SysIntegration_DW.temp_errTime = 0U;
        test2_SysIntegration_DW.bitsForTID4.is_LPCtrl =
          test2_SysIntegrati_IN_HoldStage;
        test2_Sy_enter_atomic_HoldStage();
        test2_SysIntegration_DW.bitsForTID4.is_HoldStage =
          test2_SysIntegra_IN_ShallowHold;
        test2_SysIntegration_DW.temporalCounter_i1_d = 0U;
      } else {
        sf_internal_predicateOutput =
          ((test2_SysIntegration_DW.temporalCounter_i1_d >= 10U) &&
           (!test2_SysIntegration_DW.bitsForTID4.boolWakeUpSuccess));
        if (sf_internal_predicateOutput) {
          tmp = (int32_T)(test2_SysIntegration_DW.temp_errTime + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          test2_SysIntegration_DW.temp_errTime = (uint8_T)tmp;
          test2_SysIntegration_DW.bitsForTID4.is_LPCtrl =
            test2_SysIntegra_IN_WakeUpSlave;
          test2_SysIntegration_DW.temporalCounter_i1_d = 0U;
          test2_SysIntegration_B.SecurityMsgOut.Head.OpCode = 254U;
          tmp = (int32_T)(test2_SysIntegration_B.SecurityMsgOut.Head.MsgId + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          test2_SysIntegration_B.SecurityMsgOut.Head.MsgId = (uint8_T)((uint8_T)
            tmp % MAX_uint8_T);
          test2_SysIntegration_DW.prevInSecurityMsgId = UnitDelay_o->Head.MsgId;
        } else {
          sf_internal_predicateOutput = false;
          b_p = true;
          if (!(UnitDelay_o->Head.MsgId ==
                test2_SysIntegration_DW.prevInSecurityMsgId)) {
            b_p = false;
          }

          if (b_p) {
            sf_internal_predicateOutput = true;
          }

          if (!sf_internal_predicateOutput) {
            test2_SysIntegration_DW.prevInSecurityMsgId =
              UnitDelay_o->Head.MsgId;
            sf_internal_predicateOutput = false;
            b_p = true;
            if (!(UnitDelay_o->Head.OpCode == 254)) {
              b_p = false;
            }

            if (b_p) {
              sf_internal_predicateOutput = true;
            }

            if (sf_internal_predicateOutput) {
              test2_SysIntegration_DW.bitsForTID4.boolWakeUpSuccess = true;
            }
          }
        }
      }
      break;
    }

    if (guard1) {
      test2_SysIntegration_DW.bitsForTID4.is_IOCtrlStage = 0;
      test2_SysIntegration_DW.bitsForTID4.is_LPCtrl =
        test2_SysIntegrati_IN_HoldStage;
      test2_Sy_enter_atomic_HoldStage();
      test2_SysIntegration_DW.bitsForTID4.is_HoldStage =
        test2_SysIntegra_IN_ShallowHold;
      test2_SysIntegration_DW.temporalCounter_i1_d = 0U;
    }
  }
}

/* Function for Chart: '<S43>/Chart' */
static boolean_T test2_SysIntegration_LCDCtrl(boolean_T x_boolLCDOn)
{
  return lcdCtrl(x_boolLCDOn);
}

/* Function for Chart: '<S67>/Taskwith10msSamplingTime' */
static uint32_T test2_SysIntegratio_InitCalibra(int16_T x_BattVolt, const
  int16_T x_BattVoltLUT[2], real32_T x_BattCapEqPresentation)
{
  int16_T maxval;
  int16_T b_maxval;
  int16_T minval;
  int32_T u1;
  maxval = x_BattVoltLUT[0];
  if (x_BattVoltLUT[0] < x_BattVoltLUT[1]) {
    maxval = x_BattVoltLUT[1];
  }

  b_maxval = x_BattVoltLUT[0];
  if (x_BattVoltLUT[0] < x_BattVoltLUT[1]) {
    b_maxval = x_BattVoltLUT[1];
  }

  minval = x_BattVoltLUT[0];
  if (x_BattVoltLUT[0] > x_BattVoltLUT[1]) {
    minval = x_BattVoltLUT[1];
  }

  u1 = maxval - x_BattVolt;
  if (0 > u1) {
    u1 = 0;
  }

  return (uint32_T)roundf(x_BattCapEqPresentation * (real32_T)u1 / (real32_T)
    (int16_T)(b_maxval - minval));
}

/* Function for Chart: '<S67>/Taskwith10msSamplingTime' */
static uint8_T test2_SysIntegration_BattEQEst(int16_T x_BattVolt, const int16_T
  x_BattVoltLUT[2], uint32_T x_BattCurInteg, real32_T x_BattCapEqPresentation)
{
  uint8_T y_BattEQ;
  int16_T minval;
  int16_T b_minval;
  int16_T varargin_1_idx_0;
  uint8_T u0;
  minval = x_BattVoltLUT[0];
  if (x_BattVoltLUT[0] > x_BattVoltLUT[1]) {
    minval = x_BattVoltLUT[1];
  }

  minval = (int16_T)(x_BattVolt - minval);
  b_minval = x_BattVoltLUT[0];
  if (x_BattVoltLUT[0] > x_BattVoltLUT[1]) {
    b_minval = x_BattVoltLUT[1];
  }

  varargin_1_idx_0 = (int16_T)(x_BattVoltLUT[0] - b_minval);
  b_minval = (int16_T)(x_BattVoltLUT[1] - b_minval);
  if (varargin_1_idx_0 < b_minval) {
    varargin_1_idx_0 = b_minval;
  }

  if (minval < 0) {
    minval = (int16_T)-minval;
  }

  u0 = (uint8_T)roundf(fminf(1.0F, (real32_T)minval / (real32_T)varargin_1_idx_0)
                       * 100.0F);
  y_BattEQ = (uint8_T)roundf(fminf(1.0F, (x_BattCapEqPresentation - (real32_T)
    x_BattCurInteg) / x_BattCapEqPresentation) * 100.0F);
  if (u0 > y_BattEQ) {
    y_BattEQ = u0;
  }

  return y_BattEQ;
}

/* Function for Chart: '<S67>/Taskwith10msSamplingTime' */
static void enter_atomic_SlaveInfoReceived(const int16_T *SlaveBattVoltADC)
{
  uint32_T u0;
  int16_T SlaveBattVoltADC_0;
  test2_SysIntegration_DW.SlaveInfoInquiryRetryTimes = 0U;
  test2_SysIntegration_DW.bitsForTID2.boolSerialPortReliable = true;
  if (*SlaveBattVoltADC < test2_SysIntegration_DW.MasterBattVoltADC) {
    SlaveBattVoltADC_0 = *SlaveBattVoltADC;
  } else {
    SlaveBattVoltADC_0 = test2_SysIntegration_DW.MasterBattVoltADC;
  }

  test2_SysIntegration_DW.BattVolt = (int16_T)roundf((real32_T)
    test2_SysIntegration_B.VarSet.Calibra.MajorMcu4ChADCResolution[0] / 1.0E+6F *
    (real32_T)SlaveBattVoltADC_0);
  if (test2_SysIntegration_DW.BattVolt > 10000) {
    test2_SysIntegration_B.SysDiagMsgOut_k.Head.MsgId = (uint8_T)((uint8_T)
      (test2_SysIntegration_B.SysDiagMsgOut_k.Head.MsgId + 1U) % MAX_uint8_T);
    test2_SysIntegration_B.SysDiagMsgOut_k.Head.OpCode = 1U;
    test2_SysIntegration_B.SysDiagMsgOut_k.Body.Data = 5U;
  }

  /* Constant: '<S67>/BattVoltLUTUnitmV' incorporates:
   *  Constant: '<S67>/BattCapUintmAmS'
   */
  u0 = test2_SysIntegratio_InitCalibra(test2_SysIntegration_DW.BattVolt,
    test2_SysIntegration_ConstP.BattVoltLUTUnitmV_Value, 1.152E+9F);
  if (u0 < test2_SysIntegration_DW.BattCurInteg) {
    test2_SysIntegration_DW.BattCurInteg = u0;
  }

  /* Constant: '<S67>/BattVoltLUTUnitmV' incorporates:
   *  Constant: '<S67>/BattCapUintmAmS'
   */
  test2_SysIntegration_B.BattEQ = test2_SysIntegration_BattEQEst
    (test2_SysIntegration_DW.BattVolt,
     test2_SysIntegration_ConstP.BattVoltLUTUnitmV_Value,
     test2_SysIntegration_DW.BattCurInteg, 1.152E+9F);
}

/* Function for Chart: '<S67>/Taskwith10msSamplingTime' */
static void test2_SysIntegr_BattEQEstimator(const boolean_T *UnitDelay1_o)
{
  boolean_T b_sf_internal_predicateOutput;
  boolean_T b_p;
  int16_T SlaveBattVoltADC;
  if (test2_SysIntegration_DW.temporalCounter_i1_e >= 6000U) {
    test2_SysIntegration_DW.BattCurInteg +=
      test2_SysIntegration_DW.BattEQMinuteConsumption;
    test2_SysIntegration_DW.BattEQMinuteConsumption = 0U;
    test2_SysIntegration_DW.bitsForTID2.is_c40_test2_SysIntegration =
      test2_SysInt_IN_BattEQEstimator;
    test2_SysIntegration_DW.temporalCounter_i1_e = 0U;
    test2_SysIntegration_B.rtmAMotorCurrent = (uint16_T)roundf((real32_T)
      (int16_T)(test2_SysIntegration_B.MajorSensorOutp.Ch3 +
                test2_SysIntegration_B.VarSet.Calibra.MajorMCU4ChADCOffset[2]) /
      1.0E+6F * (real32_T)
      test2_SysIntegration_B.VarSet.Calibra.MajorMcu4ChADCResolution[1]);
    test2_SysIntegration_DW.BattEQMinuteConsumption =
      ((test2_SysIn_FuzzyLogicBGCurrent *
        test2_SysIntegration_B.bitsForTID4.LogicalOperator1 * 10 +
        test2_SysIntegration_DW.BattEQMinuteConsumption) +
       test2_SysI_FuzzyLogicLCDCurrent *
       test2_SysIntegration_B.bitsForTID4.boolLCDStatus * 10) +
      test2_Sy_FuzzyLogicMotorCurrent * *UnitDelay1_o * 10;
    test2_SysIntegration_DW.bitsForTID2.is_BattEQEstimator =
      test2_SysInt_IN_AskforSlaveInfo;
    test2_SysIntegration_DW.temporalCounter_i2_f = 0U;
    test2_SysIntegration_B.SlaveMCUADCInquiryMsg.Head.MsgId = (uint8_T)((uint8_T)
      (test2_SysIntegration_B.SlaveMCUADCInquiryMsg.Head.MsgId + 1U) %
      MAX_uint8_T);
    test2_SysIntegration_B.SlaveMCUADCInquiryMsg.Head.OpCode = 1U;
    test2_SysIntegration_DW.prevSensorMsgId = 0U;
    test2_SysIntegration_DW.MasterBattVoltADC = (int16_T)
      (test2_SysIntegration_B.MajorSensorOutp.Ch1 +
       test2_SysIntegration_B.VarSet.Calibra.MajorMCU4ChADCOffset[0]);
  } else {
    test2_SysIntegration_B.rtmAMotorCurrent = (uint16_T)roundf((real32_T)
      (int16_T)(test2_SysIntegration_B.MajorSensorOutp.Ch3 +
                test2_SysIntegration_B.VarSet.Calibra.MajorMCU4ChADCOffset[2]) /
      1.0E+6F * (real32_T)
      test2_SysIntegration_B.VarSet.Calibra.MajorMcu4ChADCResolution[1]);
    test2_SysIntegration_DW.BattEQMinuteConsumption =
      ((test2_SysIn_FuzzyLogicBGCurrent *
        test2_SysIntegration_B.bitsForTID4.LogicalOperator1 * 10 +
        test2_SysIntegration_DW.BattEQMinuteConsumption) +
       test2_SysI_FuzzyLogicLCDCurrent *
       test2_SysIntegration_B.bitsForTID4.boolLCDStatus * 10) +
      test2_Sy_FuzzyLogicMotorCurrent * *UnitDelay1_o * 10;
    if (test2_SysIntegration_DW.temporalCounter_i1_e >= 90000U) {
      test2_SysIntegration_DW.bitsForTID2.boolBatteryLow = false;
      test2_SysIntegration_DW.bitsForTID2.is_BattEQEstimator =
        test2_SysInt_IN_AskforSlaveInfo;
      test2_SysIntegration_DW.temporalCounter_i2_f = 0U;
      test2_SysIntegration_B.SlaveMCUADCInquiryMsg.Head.MsgId = (uint8_T)
        ((uint8_T)(test2_SysIntegration_B.SlaveMCUADCInquiryMsg.Head.MsgId + 1U)
         % MAX_uint8_T);
      test2_SysIntegration_B.SlaveMCUADCInquiryMsg.Head.OpCode = 1U;
      test2_SysIntegration_DW.prevSensorMsgId = 0U;
      test2_SysIntegration_DW.MasterBattVoltADC = (int16_T)
        (test2_SysIntegration_B.MajorSensorOutp.Ch1 +
         test2_SysIntegration_B.VarSet.Calibra.MajorMCU4ChADCOffset[0]);
    } else {
      switch (test2_SysIntegration_DW.bitsForTID2.is_BattEQEstimator) {
       case test2_SysInt_IN_AskforSlaveInfo:
        if (test2_SysIntegration_DW.prevSensorMsgId != 0) {
          test2_SysIntegration_DW.prevSensorMsgId = 0U;
          SlaveBattVoltADC =
            test2_SysIntegration_B.VarSet.Calibra.MinorMCU4ChADCOffset[0];
          test2_SysIntegration_DW.bitsForTID2.is_BattEQEstimator =
            test2_SysI_IN_SlaveInfoReceived;
          enter_atomic_SlaveInfoReceived(&SlaveBattVoltADC);
        } else if (test2_SysIntegration_DW.temporalCounter_i2_f >= 300U) {
          test2_SysIntegration_DW.SlaveInfoInquiryRetryTimes++;
          test2_SysIntegration_DW.bitsForTID2.is_BattEQEstimator =
            test2_SysInt_IN_AskforSlaveInfo;
          test2_SysIntegration_DW.temporalCounter_i2_f = 0U;
          test2_SysIntegration_B.SlaveMCUADCInquiryMsg.Head.MsgId = (uint8_T)
            ((uint8_T)(test2_SysIntegration_B.SlaveMCUADCInquiryMsg.Head.MsgId +
                       1U) % MAX_uint8_T);
          test2_SysIntegration_B.SlaveMCUADCInquiryMsg.Head.OpCode = 1U;
          test2_SysIntegration_DW.prevSensorMsgId = 0U;
          test2_SysIntegration_DW.MasterBattVoltADC = (int16_T)
            (test2_SysIntegration_B.MajorSensorOutp.Ch1 +
             test2_SysIntegration_B.VarSet.Calibra.MajorMCU4ChADCOffset[0]);
        } else {
          b_sf_internal_predicateOutput = false;
          b_p = true;
          if (!(test2_SysIntegration_DW.SlaveInfoInquiryRetryTimes == 3)) {
            b_p = false;
          }

          if (b_p) {
            b_sf_internal_predicateOutput = true;
          }

          if (b_sf_internal_predicateOutput) {
            test2_SysIntegration_DW.SlaveInfoInquiryRetryTimes = 0U;
            test2_SysIntegration_DW.bitsForTID2.is_BattEQEstimator =
              test2_SysI_IN_SerialPortCommErr;
            test2_SysIntegration_B.SysDiagMsgOut_k.Head.MsgId = (uint8_T)
              ((uint8_T)(test2_SysIntegration_B.SysDiagMsgOut_k.Head.MsgId + 1U)
               % MAX_uint8_T);
            test2_SysIntegration_B.SysDiagMsgOut_k.Head.OpCode = 1U;
            test2_SysIntegration_B.SysDiagMsgOut_k.Body.Data = 8U;
          }
        }
        break;

       case test2_SysIntegrat_IN_BatteryLow:
       case test2_SysInte_IN_BatteryOverLow:
        break;

       case test2_SysI_IN_SerialPortCommErr:
        SlaveBattVoltADC = MAX_int16_T;
        test2_SysIntegration_DW.bitsForTID2.is_BattEQEstimator =
          test2_SysI_IN_SlaveInfoReceived;
        enter_atomic_SlaveInfoReceived(&SlaveBattVoltADC);
        break;

       default:
        b_sf_internal_predicateOutput =
          ((!test2_SysIntegration_DW.bitsForTID2.boolBatteryLow) &&
           (test2_SysIntegration_B.BattEQ < 10) &&
           (test2_SysIntegration_B.BattEQ > 5));
        if (b_sf_internal_predicateOutput) {
          test2_SysIntegration_DW.bitsForTID2.is_BattEQEstimator =
            test2_SysIntegrat_IN_BatteryLow;
          test2_SysIntegration_B.SysDiagMsgOut_k.Head.MsgId = (uint8_T)((uint8_T)
            (test2_SysIntegration_B.SysDiagMsgOut_k.Head.MsgId + 1U) %
            MAX_uint8_T);
          test2_SysIntegration_B.SysDiagMsgOut_k.Head.OpCode = 1U;
          test2_SysIntegration_B.SysDiagMsgOut_k.Body.Data = 201U;
          test2_SysIntegration_DW.bitsForTID2.boolBatteryLow = true;
        } else {
          if (test2_SysIntegration_B.BattEQ <= 5) {
            test2_SysIntegration_DW.BattOverLowFlag = (uint8_T)((uint8_T)
              (test2_SysIntegration_DW.BattOverLowFlag + 1U) % 5);
            test2_SysIntegration_DW.bitsForTID2.is_BattEQEstimator =
              test2_SysInte_IN_BatteryOverLow;
            if (test2_SysIntegration_DW.BattOverLowFlag == 1) {
              test2_SysIntegration_B.SysDiagMsgOut_k.Head.MsgId = (uint8_T)
                ((uint8_T)(test2_SysIntegration_B.SysDiagMsgOut_k.Head.MsgId +
                           1U) % MAX_uint8_T);
              test2_SysIntegration_B.SysDiagMsgOut_k.Head.OpCode = 1U;
              test2_SysIntegration_B.SysDiagMsgOut_k.Body.Data = 102U;
            }
          }
        }
        break;
      }
    }
  }
}

/* Function for Chart: '<S94>/Chart' */
static void chartstep_c23_test2_SysIntegrat(const type_HMI2SecurityMsg
  *UnitDelay_i, const int32_T *sfEvent_cd)
{
  boolean_T b_p;
  boolean_T sf_internal_predicateOutput_tmp;
  int32_T tmp;
  switch (test2_SysIntegration_DW.bitsForTID0.is_c23_test2_SysIntegration) {
   case test2_SysIntegrati_IN_ErrReport:
    break;

   case test2_SysIntegration_IN_Finish:
    if (*sfEvent_cd == test2_SysI_event_HomingStartEvt) {
      test2_SysIntegration_DW.bitsForTID0.is_c23_test2_SysIntegration =
        test2_SysInte_IN_HomingStartSrv;
      test2_SysIntegration_DW.temporalCounter_i2_d = 0U;
      test2_SysIntegration_DW.bitsForTID0.boolFdbk = false;
      test2_SysIntegration_DW.boolHomingEvtEventCounter++;
      test2_SysIntegration_DW.prevFdbkMsgId = UnitDelay_i->Head.MsgId;
      test2_SysIntegration_DW.bitsForTID0.is_HomingStartSrv =
        test2_SysIntegra_IN_HomingStart;
    }
    break;

   case test2_SysInte_IN_HomingStartSrv:
    if (*sfEvent_cd == test2_SysIn_event_HomingStopEvt) {
      test2_SysIntegration_DW.bitsForTID0.is_HomingStartSrv = 0;
      test2_SysIntegration_DW.bitsForTID0.is_VerifyHomingState = 0;
      test2_SysIntegration_DW.bitsForTID0.is_c23_test2_SysIntegration =
        test2_SysInteg_IN_HomingStopSrv;
      test2_SysIntegration_DW.temporalCounter_i1_m = 0U;
      test2_SysIntegration_DW.bitsForTID0.is_HomingStopSrv =
        test2_SysIntegrat_IN_StopHoming;
      test2_SysIntegration_DW.bitsForTID0.boolFdbk = false;
      test2_SysIntegration_DW.boolHomingEvtEventCounter++;
      test2_SysIntegration_DW.prevFdbkMsgId = UnitDelay_i->Head.MsgId;
    } else if (test2_SysIntegration_DW.bitsForTID0.is_VerifyHomingState ==
               test2_SysIntegration_IN_Known) {
      test2_SysIntegration_DW.bitsForTID0.is_HomingStartSrv = 0;
      test2_SysIntegration_DW.bitsForTID0.is_VerifyHomingState = 0;
      test2_SysIntegration_DW.bitsForTID0.is_c23_test2_SysIntegration =
        test2_SysIntegration_IN_Finish;
      test2_SysIntegration_DW.boolHomingEvtEventCounter++;
    } else {
      sf_internal_predicateOutput_tmp =
        !test2_SysIntegration_DW.bitsForTID0.boolFdbk;
      if ((test2_SysIntegration_DW.temporalCounter_i1_m >= 500U) &&
          sf_internal_predicateOutput_tmp) {
        test2_SysIntegration_DW.bitsForTID0.is_HomingStartSrv = 0;
        test2_SysIntegration_DW.bitsForTID0.is_VerifyHomingState = 0;
        test2_SysIntegration_DW.bitsForTID0.is_c23_test2_SysIntegration =
          test2_SysIntegrati_IN_ErrReport;
        tmp = (int32_T)(test2_SysIntegration_B.ErrMsg.Head.MsgId + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        test2_SysIntegration_B.ErrMsg.Head.MsgId = (uint8_T)((uint8_T)tmp %
          MAX_uint8_T);
        test2_SysIntegration_B.ErrMsg.Head.OpCode = 1U;
        test2_SysIntegration_B.ErrMsg.Body.Data = 14U;
      } else {
        if (test2_SysIntegration_DW.prevFdbkMsgId != UnitDelay_i->Head.MsgId) {
          sf_internal_predicateOutput_tmp = false;
          b_p = true;
          if (!(UnitDelay_i->Head.OpCode == 5)) {
            b_p = false;
          }

          if (b_p) {
            sf_internal_predicateOutput_tmp = true;
          }

          if (sf_internal_predicateOutput_tmp) {
            test2_SysIntegration_DW.prevFdbkMsgId = UnitDelay_i->Head.MsgId;
            test2_SysIntegration_DW.bitsForTID0.boolFdbk = true;
          }
        }

        if (test2_SysIntegration_DW.bitsForTID0.is_HomingStartSrv ==
            test2_SysIntegra_IN_HomingStart) {
          /* Constant: '<S75>/mS' */
          sf_internal_predicateOutput_tmp =
            ((test2_SysIntegration_B.rtmAMotorCurrent > 1000) &&
             test2_SysIntegration_DW.bitsForTID0.boolFdbk);
          if (sf_internal_predicateOutput_tmp) {
            test2_SysIntegration_DW.bitsForTID0.is_HomingStartSrv =
              test2_SysI_IN_VerifyHomingState;
            test2_SysIntegration_DW.bitsForTID0.is_VerifyHomingState =
              test2_SysIntegrati_IN_Unknown_j;
            test2_SysIntegration_DW.temporalCounter_i1_m = 0U;
          }
        } else if (test2_SysIntegration_B.rtmAMotorCurrent <= 1000) {
          test2_SysIntegration_DW.bitsForTID0.is_VerifyHomingState = 0;
          test2_SysIntegration_DW.bitsForTID0.is_HomingStartSrv =
            test2_SysIntegra_IN_HomingStart;
        } else {
          switch (test2_SysIntegration_DW.bitsForTID0.is_VerifyHomingState) {
           case test2_SysIntegration_IN_Known:
            break;

           default:
            if ((*sfEvent_cd == test2_SysIntegr_event_UpdateEvt) &&
                (test2_SysIntegration_DW.temporalCounter_i1_m >= 40U)) {
              test2_SysIntegration_DW.bitsForTID0.is_VerifyHomingState =
                test2_SysIntegration_IN_Known;
            }
            break;
          }
        }
      }
    }
    break;

   case test2_SysInteg_IN_HomingStopSrv:
    sf_internal_predicateOutput_tmp =
      !test2_SysIntegration_DW.bitsForTID0.boolFdbk;
    if ((test2_SysIntegration_DW.temporalCounter_i1_m >= 500U) &&
        sf_internal_predicateOutput_tmp) {
      test2_SysIntegration_DW.bitsForTID0.is_HomingStopSrv = 0;
      test2_SysIntegration_DW.bitsForTID0.is_c23_test2_SysIntegration =
        test2_SysIntegrati_IN_ErrReport;
      tmp = (int32_T)(test2_SysIntegration_B.ErrMsg.Head.MsgId + 1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      test2_SysIntegration_B.ErrMsg.Head.MsgId = (uint8_T)((uint8_T)tmp %
        MAX_uint8_T);
      test2_SysIntegration_B.ErrMsg.Head.OpCode = 1U;
      test2_SysIntegration_B.ErrMsg.Body.Data = 14U;
    } else {
      switch (test2_SysIntegration_DW.bitsForTID0.is_HomingStopSrv) {
       case test2_SysIntegratio_IN_Normal_g:
        break;

       default:
        if (test2_SysIntegration_DW.bitsForTID0.boolFdbk) {
          test2_SysIntegration_DW.bitsForTID0.is_HomingStopSrv =
            test2_SysIntegratio_IN_Normal_g;
        } else {
          if (test2_SysIntegration_DW.prevFdbkMsgId != UnitDelay_i->Head.MsgId)
          {
            sf_internal_predicateOutput_tmp = false;
            b_p = true;
            if (!(UnitDelay_i->Head.OpCode == 255)) {
              b_p = false;
            }

            if (b_p) {
              sf_internal_predicateOutput_tmp = true;
            }

            if (sf_internal_predicateOutput_tmp) {
              test2_SysIntegration_DW.prevFdbkMsgId = UnitDelay_i->Head.MsgId;
              test2_SysIntegration_DW.bitsForTID0.boolFdbk = true;
            }
          }
        }
        break;
      }
    }
    break;

   default:
    if (*sfEvent_cd == test2_SysI_event_HomingStartEvt) {
      test2_SysIntegration_DW.bitsForTID0.is_c23_test2_SysIntegration =
        test2_SysInte_IN_HomingStartSrv;
      test2_SysIntegration_DW.temporalCounter_i2_d = 0U;
      test2_SysIntegration_DW.bitsForTID0.boolFdbk = false;
      test2_SysIntegration_DW.boolHomingEvtEventCounter++;
      test2_SysIntegration_DW.prevFdbkMsgId = UnitDelay_i->Head.MsgId;
      test2_SysIntegration_DW.bitsForTID0.is_HomingStartSrv =
        test2_SysIntegra_IN_HomingStart;
    }
    break;
  }
}

/* Function for Chart: '<S123>/RTMsgRuter' */
static void test_RTChipMsgSubscribeCallback(boolean_T x_boolRTChipErrStatus,
  type_RecordCtrl2RTCtrlMsg *x_RTTimerSetMsgOut, type_HMI2SecurityMsg
  *x_RTChipDiagMsg, const type_RecordCtrl2RTCtrlMsg x_BroadcastMsgIn)
{
  int32_T tmp;
  if (!x_boolRTChipErrStatus) {
    tmp = (int32_T)(x_RTTimerSetMsgOut->Head.MsgId + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    x_RTTimerSetMsgOut->Head.MsgId = (uint8_T)((uint8_T)tmp % MAX_uint8_T);
    x_RTTimerSetMsgOut->Head.OpCode = 1U;
    x_RTTimerSetMsgOut->Body = x_BroadcastMsgIn.Body;
  } else {
    tmp = (int32_T)(x_RTChipDiagMsg->Head.MsgId + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    x_RTChipDiagMsg->Head.MsgId = (uint8_T)((uint8_T)tmp % MAX_uint8_T);
    x_RTChipDiagMsg->Head.OpCode = 1U;
    x_RTChipDiagMsg->Body.Data = 16U;
  }
}

/* Function for Chart: '<S126>/Chart' */
static void test2_SysInte_UpdateDateAndTime(uint16_T x_prevYearInfo, uint8_T
  x_prevMonthInfo, uint8_T x_prevDayInfo, uint32_T x_TotalmSecond, type_RT
  *y_RTTimeMsgOut, uint16_T *y_prevYearInfo, uint8_T *y_prevMonthInfo, uint8_T
  *y_prevDayInfo, uint32_T *y_TotalmSecond)
{
  boolean_T y_boolLeap;
  static const int8_T d[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  static const int8_T e[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  uint16_T tmp;
  uint32_T qY;
  uint32_T qY_0;
  int32_T tmp_0;
  uint32_T y;
  uint32_T y_0;
  int8_T y_boolLeap_0;
  tmp_0 = (int32_T)rt_roundd_snf((real_T)x_TotalmSecond / 1000.0);
  y_0 = tmp_0 % 60U;
  qY_0 = (uint32_T)tmp_0 - /*MW:OvSatOk*/ (uint8_T)y_0;
  if (qY_0 > (uint32_T)tmp_0) {
    qY_0 = 0U;
  }

  y = (int32_T)rt_roundd_snf((real_T)qY_0 / 60.0) % 60U;
  qY_0 = (uint32_T)tmp_0 - /*MW:OvSatOk*/ (uint8_T)y_0;
  if (qY_0 > (uint32_T)tmp_0) {
    qY_0 = 0U;
  }

  qY = qY_0 - /*MW:OvSatOk*/ (uint8_T)y * 60U;
  if (qY > qY_0) {
    qY = 0U;
  }

  y_RTTimeMsgOut->Time[3] = (uint8_T)((int32_T)rt_roundd_snf((real_T)qY / 3600.0)
    % 24U);
  y_RTTimeMsgOut->Time[4] = (uint8_T)y;
  y_RTTimeMsgOut->Time[5] = (uint8_T)y_0;
  qY_0 = (uint32_T)tmp_0 - /*MW:OvSatOk*/ (uint8_T)y_0;
  if (qY_0 > (uint32_T)tmp_0) {
    qY_0 = 0U;
  }

  qY = qY_0 - /*MW:OvSatOk*/ (uint8_T)y * 60U;
  if (qY > qY_0) {
    qY = 0U;
  }

  if (trunc((real_T)(int32_T)rt_roundd_snf((real_T)qY / 3600.0) / 24.0) != 0.0)
  {
    tmp_0 = (uint16_T)(x_prevYearInfo % 100);
    if ((tmp_0 != 0) && ((uint16_T)(x_prevYearInfo % 4) == 0)) {
      y_boolLeap = true;
    } else {
      y_boolLeap = ((tmp_0 == 0) && ((uint16_T)(x_prevYearInfo % 400) == 0));
    }

    if (y_boolLeap) {
      y_boolLeap_0 = e[x_prevMonthInfo - 1];
    } else {
      y_boolLeap_0 = d[x_prevMonthInfo - 1];
    }

    if (x_prevDayInfo == y_boolLeap_0) {
      *y_prevDayInfo = 1U;
      *y_prevMonthInfo = (uint8_T)((uint8_T)(x_prevMonthInfo % 12) + 1);
      qY_0 = x_prevMonthInfo / 12U + x_prevYearInfo;
      if (qY_0 > 65535U) {
        qY_0 = 65535U;
      }

      *y_prevYearInfo = (uint16_T)qY_0;
    } else {
      tmp_0 = (int32_T)(x_prevDayInfo + 1U);
      if ((uint32_T)tmp_0 > 255U) {
        tmp_0 = 255;
      }

      *y_prevDayInfo = (uint8_T)tmp_0;
      *y_prevMonthInfo = x_prevMonthInfo;
      *y_prevYearInfo = x_prevYearInfo;
    }

    *y_TotalmSecond = 0U;
  } else {
    *y_prevYearInfo = x_prevYearInfo;
    *y_prevMonthInfo = x_prevMonthInfo;
    *y_prevDayInfo = x_prevDayInfo;
    *y_TotalmSecond = x_TotalmSecond;
  }

  qY_0 = *y_prevYearInfo - /*MW:OvSatOk*/ 2000U;
  if (qY_0 > *y_prevYearInfo) {
    qY_0 = 0U;
  }

  tmp = (uint16_T)qY_0;
  if ((uint16_T)qY_0 > 255) {
    tmp = 255U;
  }

  y_RTTimeMsgOut->Time[0] = (uint8_T)tmp;
  y_RTTimeMsgOut->Time[1] = *y_prevMonthInfo;
  y_RTTimeMsgOut->Time[2] = *y_prevDayInfo;
}

/* Function for Chart: '<S126>/Chart' */
static uint32_T test2_SysIntegrat_TotalmSecCalc(const uint8_T Time[6])
{
  return ((Time[3] * 60 + Time[4]) * 60U + Time[5]) * 1000U;
}

/* Function for Chart: '<S126>/Chart' */
static void test2_SysIntegr_enter_atomic_Op(void)
{
  uint32_T qY;
  int32_T tmp;
  uint32_T tmp_0;
  uint16_T tmp_1;
  uint8_T tmp_2;
  uint8_T tmp_3;
  qY = test2_SysIntegration_B.LargeDoseRelativeSec + 1U;
  if (qY > 65535U) {
    qY = 65535U;
  }

  tmp = (int32_T)rt_roundd_snf((real_T)
    test2_SysIntegration_B.UnitDelay_f.Body.Data / 1000.0);
  tmp_0 = (uint32_T)tmp;
  if ((uint32_T)tmp > 65535U) {
    tmp_0 = 65535U;
  }

  qY += test2_SysIntegration_DW.bitsForTID7.TimeSetSwitch2 * (int32_T)tmp_0;
  if (qY > 65535U) {
    qY = 65535U;
  }

  test2_SysIntegration_B.LargeDoseRelativeSec = (uint16_T)
    (test2_SysIntegration_DW.bitsForTID7.boolRelativeTimerEna * (int32_T)qY);
  if (test2_SysIntegration_DW.bitsForTID7.TimeSetSwitch1) {
    test2_SysIntegration_DW.bitsForTID7.TimeSetSwitch1 = false;
    if (test2_SysIntegration_B.RTTimerSetMsgOut.Head.OpCode == 1) {
      test2_SysIntegration_B.RTTimeMsgOut_h =
        test2_SysIntegration_B.RTTimerSetMsgOut.Body;
      test2_SysIntegration_DW.TotalmSecond = test2_SysIntegrat_TotalmSecCalc
        (test2_SysIntegration_B.RTTimeMsgOut_h.Time);
    }

    test2_SysIntegration_DW.prevDayInfo =
      test2_SysIntegration_B.RTTimeMsgOut_h.Time[2];
    test2_SysIntegration_DW.prevMonthInfo =
      test2_SysIntegration_B.RTTimeMsgOut_h.Time[1];
    test2_SysIntegration_DW.prevYearInfo = (uint16_T)(2000 +
      test2_SysIntegration_B.RTTimeMsgOut_h.Time[0]);
  } else {
    if (test2_SysIntegration_DW.bitsForTID7.TimeSetSwitch2) {
      test2_SysIntegration_DW.bitsForTID7.TimeSetSwitch2 = false;
      if (test2_SysIntegration_B.UnitDelay_f.Head.OpCode == 1) {
        qY = test2_SysIntegration_B.UnitDelay_f.Body.Data + /*MW:OvSatOk*/
          test2_SysIntegration_DW.TotalmSecond;
        if (qY < test2_SysIntegration_B.UnitDelay_f.Body.Data) {
          qY = MAX_uint32_T;
        }

        test2_SysIntegration_DW.TotalmSecond = qY + /*MW:OvSatOk*/ 1000U;
        if (test2_SysIntegration_DW.TotalmSecond < qY) {
          test2_SysIntegration_DW.TotalmSecond = MAX_uint32_T;
        }

        test2_SysInte_UpdateDateAndTime(test2_SysIntegration_DW.prevYearInfo,
          test2_SysIntegration_DW.prevMonthInfo,
          test2_SysIntegration_DW.prevDayInfo,
          test2_SysIntegration_DW.TotalmSecond,
          &test2_SysIntegration_B.RTTimeMsgOut_h, &tmp_1, &tmp_2, &tmp_3, &tmp_0);
        test2_SysIntegration_DW.TotalmSecond = tmp_0;
        test2_SysIntegration_DW.prevDayInfo = tmp_3;
        test2_SysIntegration_DW.prevMonthInfo = tmp_2;
        test2_SysIntegration_DW.prevYearInfo = tmp_1;
      }

      test2_SysIntegration_DW.InitTimerEvtEventCounter++;
    }
  }
}

/* Function for Chart: '<S87>/Chart' */
static void test2_SysInt_ActuatorController(const type_MotionSyn2SecurityMsg
  *UnitDelay2, const type_HMI2SecurityMsg *UnitDelay2_o, const boolean_T
  *UnitDelay_m0)
{
  boolean_T sf_internal_predicateOutput;
  boolean_T b_p;
  uint32_T tmp;
  int32_T tmp_0;
  boolean_T guard1 = false;
  guard1 = false;
  switch (test2_SysIntegration_DW.bitsForTID4.is_ActuatorController) {
   case test2_SysIntegr_IN_ActuatorBusy:
    if (!test2_SysIntegration_DW.bitsForTID4.boolEnterActuatorBusy) {
      guard1 = true;
    } else {
      if (!test2_SysIntegration_B.bitsForTID4.boolNormalDeliverySwitchOn) {
        sf_internal_predicateOutput = false;
        b_p = true;
        if (!(test2_SysIntegration_DW.DoseMode_e == 2)) {
          b_p = false;
        }

        if (b_p) {
          sf_internal_predicateOutput = true;
        }
      } else {
        sf_internal_predicateOutput = false;
      }

      if (sf_internal_predicateOutput) {
        test2_SysIntegration_DW.ForceStopEvtEventCounter++;
        guard1 = true;
      } else {
        if (test2_SysIntegration_DW.prevPerfAckMsgId != UnitDelay2_o->Head.MsgId)
        {
          test2_SysIntegration_DW.prevPerfAckMsgId = UnitDelay2_o->Head.MsgId;
          if (UnitDelay2_o->Head.OpCode == 1) {
            test2_SysIntegration_DW.ForceStopEvtEventCounter++;
          }

          test2_SysIntegration_DW.bitsForTID4.boolEnterActuatorBusy = false;
          tmp_0 = (int32_T)(test2_SysIntegration_B.MotionStopACKMsg.Head.MsgId +
                            1U);
          if ((uint32_T)tmp_0 > 255U) {
            tmp_0 = 255;
          }

          test2_SysIntegration_B.MotionStopACKMsg.Head.MsgId = (uint8_T)
            ((uint8_T)tmp_0 % MAX_uint8_T);
          test2_SysIntegration_B.MotionStopACKMsg.Head.OpCode = 1U;
        }
      }
    }
    break;

   case test2_SysIntegra_IN_CalibraMode:
    if (!test2_SysIntegration_B.bitsForTID0.boolCalibraEna) {
      test2_SysIntegration_DW.bitsForTID4.is_ActuatorController =
        test2_SysIntegration_IN_Idle;
      test2_SysIntegration_B.bitsForTID4.boolDoseCtrlBusy = false;
      test2_SysIntegration_DW.bitsForTID4.is_Idle =
        test2_SysIntegration_IN_Idle_k;
      test2_SysIntegration_DW.bitsForTID4.boolEnterActuatorBusy = false;
      test2_SysIntegration_B.targetEncCnt = 0;
    } else {
      if (test2_SysIntegration_DW.prevCalibraMsgId_n !=
          test2_SysIntegration_B.CalibraMsgOut_e.Head.MsgId) {
        test2_SysIntegration_DW.prevCalibraMsgId_n =
          test2_SysIntegration_B.CalibraMsgOut_e.Head.MsgId;
        test2_SysIntegration_B.targetEncCnt =
          test2_SysIntegration_B.CalibraMsgOut_e.Body.Data;
        test2_SysIntegration_DW.ServoOnEvtEventCounter++;
      }
    }
    break;

   default:
    if (test2_SysIntegration_B.bitsForTID0.boolCalibraEna) {
      test2_SysIntegration_DW.bitsForTID4.is_Idle = 0;
      test2_SysIntegration_DW.bitsForTID4.is_TaskSynthesizer = 0;
      test2_SysIntegration_B.bitsForTID4.boolDoseCtrlBusy = true;
      test2_SysIntegration_DW.bitsForTID4.is_ActuatorController =
        test2_SysIntegra_IN_CalibraMode;
      test2_SysIntegration_DW.prevCalibraMsgId_n =
        test2_SysIntegration_B.CalibraMsgOut_e.Head.MsgId;
    } else if (test2_SysIntegration_DW.bitsForTID4.boolEnterActuatorBusy) {
      test2_SysIntegration_DW.bitsForTID4.is_Idle = 0;
      test2_SysIntegration_DW.bitsForTID4.is_TaskSynthesizer = 0;
      test2_SysIntegration_B.bitsForTID4.boolDoseCtrlBusy = true;
      test2_SysIntegration_DW.bitsForTID4.is_ActuatorController =
        test2_SysIntegr_IN_ActuatorBusy;
      test2_SysIntegration_DW.prevPerfAckMsgId = UnitDelay2_o->Head.MsgId;
    } else if (test2_SysIntegration_DW.bitsForTID4.is_Idle ==
               test2_SysIntegration_IN_Idle_k) {
      if (test2_SysIntegration_B.bitsForTID4.boolNormalDeliverySwitchOn) {
        test2_SysIntegration_DW.bitsForTID4.is_Idle =
          test2_SysInt_IN_TaskSynthesizer;
        test2_SysIntegration_DW.bitsForTID4.is_TaskSynthesizer =
          test2_SysI_IN_ChkUnfinishedTask;
        test2_SysIntegration_DW.temporalCounter_i1_ob = 0U;
      }
    } else if (!test2_SysIntegration_B.bitsForTID4.boolNormalDeliverySwitchOn) {
      test2_SysIntegration_DW.bitsForTID4.is_TaskSynthesizer = 0;
      test2_SysIntegration_DW.bitsForTID4.is_Idle =
        test2_SysIntegration_IN_Idle_k;
      test2_SysIntegration_DW.bitsForTID4.boolEnterActuatorBusy = false;
      test2_SysIntegration_B.targetEncCnt = 0;
    } else {
      switch (test2_SysIntegration_DW.bitsForTID4.is_TaskSynthesizer) {
       case test2_SysI_IN_ChkUnfinishedTask:
        if ((test2_SysIntegration_DW.temporalCounter_i1_ob >= 30U) &&
            (!*UnitDelay_m0)) {
          sf_internal_predicateOutput = false;
          b_p = true;
          if (!(test2_SysIntegration_DW.prevDoseMsgId == UnitDelay2->Head.MsgId))
          {
            b_p = false;
          }

          if (b_p) {
            sf_internal_predicateOutput = true;
          }
        } else {
          sf_internal_predicateOutput = false;
        }

        if (sf_internal_predicateOutput) {
          test2_SysIntegration_DW.bitsForTID4.is_TaskSynthesizer =
            test2_SysIntegr_IN_Wait4NewTask;
          test2_SysIntegration_DW.temporalCounter_i1_ob = 0U;
          test2_SysIntegration_DW.prevDoseMsgId = UnitDelay2->Head.MsgId;
          test2_SysIntegration_DW.PopBufEvtEventCounter++;
        } else {
          sf_internal_predicateOutput = false;
          b_p = true;
          if (!(test2_SysIntegration_DW.prevDoseMsgId == UnitDelay2->Head.MsgId))
          {
            b_p = false;
          }

          if (b_p) {
            sf_internal_predicateOutput = true;
          }

          if (!sf_internal_predicateOutput) {
            test2_SysIntegration_DW.bitsForTID4.is_TaskSynthesizer =
              test2_Sys_IN_RecvUnfinishedTask;
            test2_SysIntegration_DW.prevDoseMsgId = UnitDelay2->Head.MsgId;
            test2_SysIntegration_DW.DoseMode_e = (uint8_T)
              (UnitDelay2->Head.OpCode / 100U);
            if (UnitDelay2->Body.Data >= 2147483648U) {
              if ((real_T)UnitDelay2->Body.Data - 4.294967296E+9 >=
                  -2.147483648E+9) {
                test2_SysIntegration_B.targetEncCnt = (int32_T)((real_T)
                  UnitDelay2->Body.Data - 4.294967296E+9);
              } else {
                test2_SysIntegration_B.targetEncCnt = MIN_int32_T;
              }
            } else {
              tmp = UnitDelay2->Body.Data;
              if (UnitDelay2->Body.Data > 2147483647U) {
                tmp = 2147483647U;
              }

              test2_SysIntegration_B.targetEncCnt = (int32_T)tmp;
            }

            test2_SysIntegration_DW.bitsForTID4.boolEnterActuatorBusy = true;
            test2_SysIntegration_DW.ServoOnEvtEventCounter++;
          }
        }
        break;

       case test2_Sys_IN_RecvUnfinishedTask:
        break;

       default:
        if (test2_SysIntegration_DW.temporalCounter_i1_ob >= 100U) {
          test2_SysIntegration_DW.bitsForTID4.is_TaskSynthesizer =
            test2_SysIntegr_IN_Wait4NewTask;
          test2_SysIntegration_DW.temporalCounter_i1_ob = 0U;
          test2_SysIntegration_DW.prevDoseMsgId = UnitDelay2->Head.MsgId;
          test2_SysIntegration_DW.PopBufEvtEventCounter++;
        } else {
          if (test2_SysIntegration_DW.prevDoseMsgId != UnitDelay2->Head.MsgId) {
            test2_SysIntegration_DW.prevDoseMsgId = UnitDelay2->Head.MsgId;
            test2_SysIntegration_DW.DoseMode_e = (uint8_T)
              (UnitDelay2->Head.OpCode / 100U);
            if (UnitDelay2->Body.Data >= 2147483648U) {
              if ((real_T)UnitDelay2->Body.Data - 4.294967296E+9 >=
                  -2.147483648E+9) {
                test2_SysIntegration_B.targetEncCnt = (int32_T)((real_T)
                  UnitDelay2->Body.Data - 4.294967296E+9);
              } else {
                test2_SysIntegration_B.targetEncCnt = MIN_int32_T;
              }
            } else {
              tmp = UnitDelay2->Body.Data;
              if (UnitDelay2->Body.Data > 2147483647U) {
                tmp = 2147483647U;
              }

              test2_SysIntegration_B.targetEncCnt = (int32_T)tmp;
            }

            test2_SysIntegration_DW.bitsForTID4.boolEnterActuatorBusy = true;
            test2_SysIntegration_DW.ServoOnEvtEventCounter++;
          }
        }
        break;
      }
    }
    break;
  }

  if (guard1) {
    test2_SysIntegration_DW.bitsForTID4.is_ActuatorController =
      test2_SysIntegration_IN_Idle;
    test2_SysIntegration_B.bitsForTID4.boolDoseCtrlBusy = false;
    test2_SysIntegration_DW.bitsForTID4.is_Idle = test2_SysIntegration_IN_Idle_k;
    test2_SysIntegration_DW.bitsForTID4.boolEnterActuatorBusy = false;
    test2_SysIntegration_B.targetEncCnt = 0;
  }
}

real32_T rt_remf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  real32_T q;
  if (!((!rtIsNaNF(u0)) && (!rtIsInfF(u0)) && ((!rtIsNaNF(u1)) && (!rtIsInfF(u1)))))
  {
    y = (rtNaNF);
  } else if ((u1 != 0.0F) && (u1 != truncf(u1))) {
    q = fabsf(u0 / u1);
    if (fabsf(q - floorf(q + 0.5F)) <= FLT_EPSILON * q) {
      y = 0.0F * u0;
    } else {
      y = fmodf(u0, u1);
    }
  } else {
    y = fmodf(u0, u1);
  }

  return y;
}

/* Function for Chart: '<S106>/TaskScheduler' */
static boolean_T test2_SysIntegration_isequal_d(real32_T varargin_1, real32_T
  varargin_2)
{
  boolean_T p;
  boolean_T b_p;
  p = false;
  b_p = true;
  if (!(varargin_1 == varargin_2)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  return p;
}

/* Function for Chart: '<S106>/TaskScheduler' */
static void test2_SysInte_subBaseTimeHitChk(const type_RT x_RTTime, const
  type_CatBody4DoseCtrl *x_DoseCtrl, boolean_T x_DoseCtrlBusy, uint8_T
  TimeHitTolSec, uint16_T *y_SubDose, uint8_T y_SubDoseId[2], uint16_T
  *y_NextTimeHitSec, boolean_T *y_boolLastElement, uint16_T *y_HalfHourDose)
{
  uint16_T RelativeTimeSec;
  uint16_T SeqSize;
  real32_T SectTimeLength;
  uint8_T y_SubDoseId_tmp;
  int32_T tmp;
  *y_boolLastElement = false;
  SeqSize = (uint16_T)trunc((real_T)(x_RTTime.Time[3] * 60 + x_RTTime.Time[4]) /
    30.0);
  y_SubDoseId_tmp = (uint8_T)(SeqSize + 1);
  y_SubDoseId[0] = y_SubDoseId_tmp;
  RelativeTimeSec = (uint16_T)((uint8_T)(x_RTTime.Time[4] % 30) * 60 +
    x_RTTime.Time[5]);
  tmp = y_SubDoseId_tmp - 1;
  if (x_DoseCtrl->TempBaseRateConfig[tmp] != 0) {
    *y_HalfHourDose = (uint16_T)(x_DoseCtrl->TempBaseRateConfig[(uint8_T)
      (SeqSize + 1) - 1] * 50);
  } else {
    *y_HalfHourDose = (uint16_T)(x_DoseCtrl->BaseRateConfig[tmp] * 50);
  }

  if (*y_HalfHourDose >= 500) {
    *y_SubDose = 50U;
  } else {
    *y_SubDose = 25U;
  }

  SeqSize = (uint16_T)(((uint16_T)(*y_HalfHourDose % *y_SubDose) != 0) +
                       (int32_T)((uint32_T)*y_HalfHourDose / *y_SubDose));
  SectTimeLength = 1800.0F / ((real32_T)SeqSize + 1.0F);
  if (SeqSize != 0) {
    if ((rt_remf_snf((real32_T)RelativeTimeSec, SectTimeLength) <= TimeHitTolSec)
        && ((RelativeTimeSec >= SectTimeLength) && (RelativeTimeSec <=
          SectTimeLength * (real32_T)SeqSize + (real32_T)TimeHitTolSec))) {
      y_SubDoseId[1] = (uint8_T)floorf((real32_T)RelativeTimeSec /
        SectTimeLength);
      *y_NextTimeHitSec = 0U;
      if (test2_SysIntegration_isequal_d(floorf((real32_T)RelativeTimeSec /
            SectTimeLength), (real32_T)SeqSize)) {
        *y_boolLastElement = true;
      }
    } else if ((SectTimeLength - rt_remf_snf((real32_T)RelativeTimeSec,
                 SectTimeLength) <= TimeHitTolSec) && ((RelativeTimeSec >=
                 SectTimeLength - (real32_T)TimeHitTolSec) && (RelativeTimeSec <=
      SectTimeLength * (real32_T)SeqSize))) {
      y_SubDoseId[1] = (uint8_T)ceilf((real32_T)RelativeTimeSec / SectTimeLength);
      *y_NextTimeHitSec = 0U;
      if (test2_SysIntegration_isequal_d(ceilf((real32_T)RelativeTimeSec /
            SectTimeLength), (real32_T)SeqSize)) {
        *y_boolLastElement = true;
      }
    } else {
      y_SubDoseId[1] = 0U;
      if (RelativeTimeSec <= SectTimeLength * (real32_T)SeqSize - (real32_T)
          TimeHitTolSec) {
        *y_NextTimeHitSec = (uint16_T)roundf((SectTimeLength - rt_remf_snf
          ((real32_T)RelativeTimeSec, SectTimeLength)) * (real32_T)
          !x_DoseCtrlBusy);
      } else {
        *y_NextTimeHitSec = (uint16_T)((uint16_T)(1800U - RelativeTimeSec) *
          !x_DoseCtrlBusy);
      }
    }
  } else {
    y_SubDoseId[1] = 0U;
    *y_NextTimeHitSec = (uint16_T)((uint16_T)(1800U - RelativeTimeSec) *
      !x_DoseCtrlBusy);
  }
}

/* Function for Chart: '<S106>/TaskScheduler' */
static void enter_atomic_baseRateTaskHitChk(void)
{
  uint16_T SubBaseDose;
  uint8_T SubBaseDoseId[2];
  boolean_T boolLastBaseSubDose;
  uint16_T HalfHourDose;
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  int32_T u1;
  boolean_T exitg1;

  /* UnitDelay: '<S65>/Unit Delay' */
  test2_SysInte_subBaseTimeHitChk(test2_SysIntegration_DW.UnitDelay_DSTATE_j,
    &test2_SysIntegration_B.VarSet.DoseCtrl,
    test2_SysIntegration_B.bitsForTID4.boolDoseCtrlBusy, 3, &SubBaseDose,
    SubBaseDoseId, &test2_SysIntegration_DW.NextSubBaseDoseTaskTimeHitSec,
    &boolLastBaseSubDose, &HalfHourDose);
  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(SubBaseDoseId[k] == test2_SysIntegration_DW.prevSubBaseDoseId[k])) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    p = false;
    b_p = true;
    if (!(SubBaseDoseId[1] == 0)) {
      b_p = false;
    }

    if (b_p) {
      p = true;
    }

    if (!p) {
      test2_SysIntegration_DW.prevSubBaseDoseId[0] = SubBaseDoseId[0];
      test2_SysIntegration_DW.prevSubBaseDoseId[1] = SubBaseDoseId[1];
      if (boolLastBaseSubDose) {
        test2_SysIntegration_B.DoseMissionMsgOut.Head.OpCode = 100U;
        if (test2_SysIntegration_DW.temp_LeftDoseEncCnt >
            test2_SysIntegration_DW.temp_LastDoseEncCnt) {
          k = test2_SysIntegration_DW.temp_LeftDoseEncCnt;
        } else {
          k = test2_SysIntegration_DW.temp_LastDoseEncCnt;
        }

        u1 = (int32_T)roundf((real32_T)
                             test2_SysIntegration_DW.temp_LastDoseEncCnt * 1.05F);
        if (k < u1) {
          test2_SysIntegration_B.DoseMissionMsgOut.Body.TargetEncCnt = k;
        } else {
          test2_SysIntegration_B.DoseMissionMsgOut.Body.TargetEncCnt = u1;
        }
      } else {
        test2_SysIntegration_B.DoseMissionMsgOut.Head.OpCode = (uint8_T)(100U +
          SubBaseDoseId[0]);
        test2_SysIntegration_B.DoseMissionMsgOut.Body.TargetEncCnt = (int32_T)
          floorf((real32_T)SubBaseDose * test2_SysIntegration_B.Enc2DoseGain);
      }

      test2_SysIntegration_B.DoseMissionMsgOut.Head.MsgId = (uint8_T)((uint8_T)
        (test2_SysIntegration_B.DoseMissionMsgOut.Head.MsgId + 1U) % MAX_uint8_T);
      test2_SysIntegration_DW.PushDoseEventCounter++;
    }
  }
}

/* Function for Chart: '<S106>/TaskScheduler' */
static void test2_SysInt_subLargeTimeHitChk(uint16_T x_RTSec, const
  type_CatBody4DoseCtrl *x_DoseCtrl, boolean_T x_DoseBusy, uint16_T x_SubDoseId,
  uint8_T x_TimeHitTol, boolean_T x_boolLastElementFound, uint16_T *y_SubDose,
  uint16_T *y_SubDoseId, uint16_T *y_NextTimeHitSec, boolean_T
  *y_boolLastElementFound, uint16_T *y_LargeDose)
{
  uint16_T TimeLength;
  uint16_T DWMDose;
  uint16_T SeqSize;
  real32_T SectTimeLength;
  uint16_T y;
  uint16_T b_y;
  boolean_T b_p;
  boolean_T c_p;
  int32_T tmp;
  *y_LargeDose = (uint16_T)(x_DoseCtrl->LargeDoseConfig.LargeDoseTotalAmount *
    100U);
  TimeLength = (uint16_T)(x_DoseCtrl->LargeDoseConfig.PermittedTime * 60);
  DWMDose = (uint16_T)(x_DoseCtrl->LargeDoseConfig.RegularDose4DWMCase * 100U);
  *y_boolLastElementFound = false;
  if (*y_LargeDose != 0) {
    switch (x_DoseCtrl->LargeDoseConfig.DeliveryConfig) {
     case 0:
      SeqSize = 2U;
      SectTimeLength = TimeLength;
      *y_SubDose = 0U;
      break;

     case 1:
      SeqSize = (uint16_T)((int32_T)trunc((real_T)*y_LargeDose / 500.0) + 1);
      SectTimeLength = (real32_T)TimeLength / ((real32_T)SeqSize - 1.0F);
      *y_SubDose = (uint16_T)(*y_LargeDose % 500);
      break;

     case 2:
      SeqSize = 10U;
      SectTimeLength = (real32_T)TimeLength / 9.0F;
      y = (uint16_T)(*y_LargeDose << 1);
      b_y = (uint16_T)(y / 10U);
      y = (uint16_T)((uint32_T)y - (uint16_T)(b_y * 10U));
      if ((y > 0) && (y >= 5)) {
        b_y++;
      }

      *y_SubDose = (uint16_T)((uint16_T)(*y_LargeDose - (uint32_T)rt_roundd_snf
        ((real_T)(uint16_T)((uint16_T)(b_y - 50U) / 9U * 72U) / 2.0)) - 225U);
      break;

     case 3:
      SeqSize = 2U;
      SectTimeLength = TimeLength;
      *y_SubDose = (uint16_T)rt_roundd_snf((real_T)*y_LargeDose / 2.0);
      break;

     case 4:
      b_y = (uint16_T)((uint32_T)*y_LargeDose - DWMDose);
      SeqSize = (uint16_T)((int32_T)trunc((real_T)b_y / 500.0) + 2);
      SectTimeLength = (real32_T)TimeLength / ((real32_T)SeqSize - 1.0F);
      *y_SubDose = (uint16_T)(b_y % 500);
      break;
    }

    tmp = x_RTSec - 5;
    if ((x_RTSec >= 5) && (tmp <= TimeLength + x_TimeHitTol) && (rt_remf_snf
         ((real32_T)x_RTSec - 5.0F, SectTimeLength) <= x_TimeHitTol)) {
      *y_SubDoseId = (uint16_T)(floorf(((real32_T)x_RTSec - 5.0F) /
        SectTimeLength) + 1.0F);
      *y_NextTimeHitSec = 0U;
      if (test2_SysIntegration_isequal_d(floorf(((real32_T)x_RTSec - 5.0F) /
            SectTimeLength), (real32_T)SeqSize - 1.0F)) {
        *y_boolLastElementFound = true;
      }
    } else if ((x_RTSec >= 5) && (tmp < TimeLength) && (SectTimeLength -
                rt_remf_snf((real32_T)x_RTSec - 5.0F, SectTimeLength) <=
                x_TimeHitTol)) {
      *y_SubDoseId = (uint16_T)(ceilf(((real32_T)x_RTSec - 5.0F) /
        SectTimeLength) + 1.0F);
      *y_NextTimeHitSec = 0U;
      if (test2_SysIntegration_isequal_d(ceilf(((real32_T)x_RTSec - 5.0F) /
            SectTimeLength), (real32_T)SeqSize - 1.0F)) {
        *y_boolLastElementFound = true;
      }
    } else {
      *y_SubDoseId = x_SubDoseId;
      if ((x_RTSec >= 5) && (tmp <= (uint16_T)((uint32_T)TimeLength -
            x_TimeHitTol))) {
        *y_NextTimeHitSec = (uint16_T)((uint16_T)((uint32_T)(uint16_T)roundf
          (SectTimeLength) - (uint16_T)roundf(rt_remf_snf((real32_T)x_RTSec -
          5.0F, SectTimeLength))) * !x_DoseBusy);
      } else if (x_RTSec < 5) {
        *y_NextTimeHitSec = (uint16_T)((5 - x_RTSec) * !x_DoseBusy);
      } else {
        *y_NextTimeHitSec = (uint16_T)(65535 * !x_DoseBusy);
      }
    }

    if ((*y_SubDoseId < SeqSize) && (*y_SubDoseId > 0)) {
      switch (x_DoseCtrl->LargeDoseConfig.DeliveryConfig) {
       case 0:
        *y_SubDose = *y_LargeDose;
        break;

       case 1:
        *y_SubDose = 500U;
        break;

       case 2:
        *y_SubDose = (uint16_T)((uint16_T)((uint32_T)(uint16_T)((uint16_T)
          ((uint16_T)((uint32_T)(uint16_T)((uint32_T)*y_LargeDose - *y_SubDose)
                      - (SeqSize - 1) * 25) << 1) / ((SeqSize - 1) * (SeqSize -
          2U))) * (*y_SubDoseId - 1)) + 25U);
        break;

       case 3:
        *y_SubDose = (uint16_T)rt_roundd_snf((real_T)*y_LargeDose / 2.0);
        break;

       case 4:
        b_p = false;
        c_p = true;
        if (!(*y_SubDoseId == 1)) {
          c_p = false;
        }

        if (c_p) {
          b_p = true;
        }

        if (b_p) {
          *y_SubDose = DWMDose;
        } else {
          *y_SubDose = 500U;
        }
        break;
      }
    } else {
      b_p = false;
      c_p = true;
      if (!(*y_SubDoseId == SeqSize)) {
        c_p = false;
      }

      if (c_p) {
        b_p = true;
      }

      if (!b_p) {
        *y_SubDose = 0U;
      }
    }
  } else {
    *y_SubDose = 0U;
    *y_SubDoseId = 0U;
    *y_NextTimeHitSec = MAX_uint16_T;
  }

  if (x_boolLastElementFound) {
    *y_boolLastElementFound = true;
  }
}

/* Function for Chart: '<S104>/Buffer' */
static uint8_T test2_SysIntegrati_pushInAction(uint8_T x_QueueDepth, uint8_T
  x_DoseCtrlMsgIn_Head_OpCode, int32_T x_DoseCtrlMsgIn_Body_TargetEncC, uint32_T
  x_DoseCtrlMsgIn_Body_PermittedT, uint8_T x_OpCodeQ[20], int32_T
  x_TargetEncCntQ[20], uint32_T x_PermitTimeQ[20])
{
  uint8_T y_QueueDepth;
  int32_T tmp;
  y_QueueDepth = (uint8_T)(x_QueueDepth + 1U);
  if (!(y_QueueDepth < 20)) {
    y_QueueDepth = 20U;
  }

  tmp = y_QueueDepth - 1;
  x_OpCodeQ[tmp] = x_DoseCtrlMsgIn_Head_OpCode;
  x_TargetEncCntQ[tmp] = x_DoseCtrlMsgIn_Body_TargetEncC;
  x_PermitTimeQ[tmp] = x_DoseCtrlMsgIn_Body_PermittedT;
  return y_QueueDepth;
}

/* Function for Chart: '<S104>/Buffer' */
static void test2_SysIntegrati_popOutAction(uint8_T x_QueueDepth, const uint8_T
  x_OpCodeQ[20], const int32_T x_TargetEncCntQ[20], const uint32_T
  x_PermitTimeQ[20], uint8_T x_DoseCtrlMsgOut_Head_MsgId, uint8_T
  x_DoseCtrlMsgOut_Head_OpCode, int32_T x_DoseCtrlMsgOut_Body_TargetEnc,
  uint32_T x_DoseCtrlMsgOut_Body_Permitted, uint8_T *y_QueueDepth, uint8_T
  y_OpCodeQ[20], int32_T y_TargetEncCntQ[20], uint32_T y_PermitTimeQ[20],
  uint8_T *y_DoseCtrlMsgOut_Head_MsgId, uint8_T *y_DoseCtrlMsgOut_Head_OpCode,
  int32_T *y_DoseCtrlMsgOut_Body_TargetEnc, uint32_T
  *y_DoseCtrlMsgOut_Body_Permitted)
{
  int32_T i;
  if (x_QueueDepth == 0) {
    *y_QueueDepth = 0U;
    *y_DoseCtrlMsgOut_Head_MsgId = x_DoseCtrlMsgOut_Head_MsgId;
    *y_DoseCtrlMsgOut_Head_OpCode = x_DoseCtrlMsgOut_Head_OpCode;
    *y_DoseCtrlMsgOut_Body_TargetEnc = x_DoseCtrlMsgOut_Body_TargetEnc;
    *y_DoseCtrlMsgOut_Body_Permitted = x_DoseCtrlMsgOut_Body_Permitted;
    memcpy(&y_TargetEncCntQ[0], &x_TargetEncCntQ[0], 20U * sizeof(int32_T));
    memcpy(&y_PermitTimeQ[0], &x_PermitTimeQ[0], 20U * sizeof(uint32_T));
    for (i = 0; i < 20; i++) {
      y_OpCodeQ[i] = x_OpCodeQ[i];
    }
  } else {
    *y_QueueDepth = (uint8_T)(x_QueueDepth - 1);
    *y_DoseCtrlMsgOut_Head_OpCode = x_OpCodeQ[0];
    *y_DoseCtrlMsgOut_Body_TargetEnc = x_TargetEncCntQ[0];
    *y_DoseCtrlMsgOut_Body_Permitted = x_PermitTimeQ[0];
    *y_DoseCtrlMsgOut_Head_MsgId = (uint8_T)((uint8_T)
      (x_DoseCtrlMsgOut_Head_MsgId + 1U) % MAX_uint8_T);
    y_OpCodeQ[19] = 0U;
    y_TargetEncCntQ[19] = 0;
    memcpy(&y_TargetEncCntQ[0], &x_TargetEncCntQ[1], 19U * sizeof(int32_T));
    memcpy(&y_PermitTimeQ[0], &x_PermitTimeQ[1], 19U * sizeof(uint32_T));
    for (i = 0; i < 19; i++) {
      y_OpCodeQ[i] = x_OpCodeQ[i + 1];
    }

    y_PermitTimeQ[19] = 0U;
  }
}

/* Function for Chart: '<S104>/Buffer' */
static void chartstep_c28_test2_SysIntegrat(const int32_T *sfEvent_e)
{
  int32_T i;
  uint8_T tmp[20];
  int32_T tmp_0[20];
  uint32_T tmp_1[20];
  uint8_T tmp_2;
  uint8_T tmp_3;
  uint8_T tmp_4;
  uint32_T tmp_5;
  if (*sfEvent_e == test2_SysIntegrat_event_ClrQEvt) {
    test2_SysIntegration_DW.QueueDepth = 0U;
    memset(&test2_SysIntegration_DW.TargetEncCntQ[0], 0, 20U * sizeof(int32_T));
    memset(&test2_SysIntegration_DW.PermitTimeQ[0], 0, 20U * sizeof(uint32_T));
    for (i = 0; i < 20; i++) {
      test2_SysIntegration_DW.OpCodeQ[i] = 0U;
    }

    test2_SysIntegration_B.bitsForTID4.boolBufferEmpty = true;
  } else {
    if (*sfEvent_e == test2_SysIntegra_event_PushQEvt) {
      test2_SysIntegration_DW.QueueDepth = test2_SysIntegrati_pushInAction
        (test2_SysIntegration_DW.QueueDepth,
         test2_SysIntegration_B.DoseMissionMsgOut.Head.OpCode,
         test2_SysIntegration_B.DoseMissionMsgOut.Body.TargetEncCnt,
         test2_SysIntegration_B.DoseMissionMsgOut.Body.PermittedTime,
         test2_SysIntegration_DW.OpCodeQ, test2_SysIntegration_DW.TargetEncCntQ,
         test2_SysIntegration_DW.PermitTimeQ);
      test2_SysIntegration_B.bitsForTID4.boolBufferEmpty =
        !(test2_SysIntegration_DW.QueueDepth != 0);
    }

    if ((*sfEvent_e == test2_SysIntegrat_event_PopQEvt) &&
        (!test2_SysIntegration_B.bitsForTID4.boolBufferEmpty)) {
      memcpy(&tmp_0[0], &test2_SysIntegration_DW.TargetEncCntQ[0], 20U * sizeof
             (int32_T));
      memcpy(&tmp_1[0], &test2_SysIntegration_DW.PermitTimeQ[0], 20U * sizeof
             (uint32_T));
      for (i = 0; i < 20; i++) {
        tmp[i] = test2_SysIntegration_DW.OpCodeQ[i];
      }

      test2_SysIntegrati_popOutAction(test2_SysIntegration_DW.QueueDepth, tmp,
        tmp_0, tmp_1, test2_SysIntegration_B.DoseCtrlMsgOut_j.Head.MsgId,
        test2_SysIntegration_B.DoseCtrlMsgOut_j.Head.OpCode,
        test2_SysIntegration_B.DoseCtrlMsgOut_j.Body.TargetEncCnt,
        test2_SysIntegration_B.DoseCtrlMsgOut_j.Body.PermittedTime, &tmp_2,
        test2_SysIntegration_DW.OpCodeQ, test2_SysIntegration_DW.TargetEncCntQ,
        test2_SysIntegration_DW.PermitTimeQ, &tmp_3, &tmp_4, &i, &tmp_5);
      test2_SysIntegration_B.DoseCtrlMsgOut_j.Body.PermittedTime = tmp_5;
      test2_SysIntegration_B.DoseCtrlMsgOut_j.Body.TargetEncCnt = i;
      test2_SysIntegration_B.DoseCtrlMsgOut_j.Head.OpCode = tmp_4;
      test2_SysIntegration_B.DoseCtrlMsgOut_j.Head.MsgId = tmp_3;
      test2_SysIntegration_DW.QueueDepth = tmp_2;
      test2_SysIntegration_B.bitsForTID4.boolBufferEmpty =
        !(test2_SysIntegration_DW.QueueDepth != 0);
    }
  }
}

/* Function for Chart: '<S108>/Chart' */
static void test2_SysIntegration_Wait4Task(const int32_T *sfEvent_m)
{
  boolean_T sf_internal_predicateOutput;
  boolean_T b_sf_internal_predicateOutput;
  int32_T tmp;
  boolean_T guard1 = false;
  sf_internal_predicateOutput = ((*sfEvent_m == test2_Sy_event_dumpLargeDoseEvt)
    && test2_SysIntegration_DW.bitsForTID0.boolMissionUnfinish &&
    (test2_SysIntegration_DW.DoseMode >= 200));
  if (sf_internal_predicateOutput) {
    test2_SysIntegration_DW.bitsForTID0.boolMissionUnfinish = false;
    test2_SysIntegration_DW.prevResidueEncCnt = 0;
    test2_SysIntegration_DW.bitsForTID0.is_Wait4Sync = 0;
    test2_SysIntegration_DW.bitsForTID0.is_Wait =
      test2_SysIntegrati_IN_Wait4Task;
    test2_SysIntegration_DW.errTime = 0U;
    test2_SysIntegration_DW.bitsForTID0.is_Wait4Task =
      test2_SysIntegrat_IN_ClrEncoder;
    test2_SysIntegration_DW.EncRstEvtEventCounter++;
    test2_SysIntegration_DW.prevDeliveryMissionId =
      test2_SysIntegration_B.DoseCtrlMsgOut_j.Head.MsgId;
    test2_SysIntegration_DW.bitsForTID0.boolNewDeliveryMission = false;
  } else {
    sf_internal_predicateOutput =
      !test2_SysIntegration_B.bitsForTID4.boolDoseCtrlBusy;
    b_sf_internal_predicateOutput =
      (test2_SysIntegration_DW.bitsForTID0.boolNewDeliveryMission &&
       test2_SysIntegration_B.bitsForTID4.boolNormalDeliverySwitchOn &&
       sf_internal_predicateOutput);
    guard1 = false;
    if (b_sf_internal_predicateOutput) {
      test2_SysIntegration_DW.bitsForTID0.boolNewDeliveryMission = false;
      guard1 = true;
    } else {
      sf_internal_predicateOutput =
        (test2_SysIntegration_B.bitsForTID4.boolNormalDeliverySwitchOn &&
         sf_internal_predicateOutput &&
         (test2_SysIntegration_DW.bitsForTID0.is_Wait4Task ==
          test2_SysIntegration_IN_SynEnd));
      if (sf_internal_predicateOutput) {
        guard1 = true;
      } else {
        switch (test2_SysIntegration_DW.bitsForTID0.is_Wait4Task) {
         case test2_SysIntegrat_IN_ClrEncoder:
          sf_internal_predicateOutput =
            (test2_SysIntegration_DW.bitsForTID0.boolMissionUnfinish &&
             (!test2_SysIntegration_DW.bitsForTID0.boolSyn));
          if (sf_internal_predicateOutput) {
            test2_SysIntegration_DW.bitsForTID0.boolMissionUnfinish = false;
            test2_SysIntegration_DW.bitsForTID0.is_Wait4Task =
              test2_SysIntegra_IN_Wait4Sync_c;
            test2_SysIntegration_DW.bitsForTID0.is_Wait4Sync =
              test2_SysInte_IN_Wait4MotorStop;
            test2_SysIntegration_DW.temporalCounter_i2 = 0U;
          } else {
            if (test2_SysIntegration_DW.prevDeliveryMissionId !=
                test2_SysIntegration_B.DoseCtrlMsgOut_j.Head.MsgId) {
              test2_SysIntegration_DW.prevDeliveryMissionId =
                test2_SysIntegration_B.DoseCtrlMsgOut_j.Head.MsgId;
              test2_SysIntegration_DW.bitsForTID0.boolNewDeliveryMission = true;
              if ((test2_SysIntegration_B.DoseCtrlMsgOut_j.Body.TargetEncCnt < 0)
                  && (test2_SysIntegration_DW.prevResidueEncCnt < MIN_int32_T
                      - test2_SysIntegration_B.DoseCtrlMsgOut_j.Body.TargetEncCnt))
              {
                test2_SysIntegration_DW.targetEncCnt = MIN_int32_T;
              } else if
                  ((test2_SysIntegration_B.DoseCtrlMsgOut_j.Body.TargetEncCnt >
                    0) && (test2_SysIntegration_DW.prevResidueEncCnt >
                           MAX_int32_T
                           - test2_SysIntegration_B.DoseCtrlMsgOut_j.Body.TargetEncCnt))
              {
                test2_SysIntegration_DW.targetEncCnt = MAX_int32_T;
              } else {
                test2_SysIntegration_DW.targetEncCnt =
                  test2_SysIntegration_B.DoseCtrlMsgOut_j.Body.TargetEncCnt +
                  test2_SysIntegration_DW.prevResidueEncCnt;
              }

              test2_SysIntegration_DW.DoseMode =
                test2_SysIntegration_B.DoseCtrlMsgOut_j.Head.OpCode;
            }
          }
          break;

         case test2_SysIntegra_IN_CommFailure:
         case test2_SysIntegration_IN_SynEnd:
          break;

         case test2_SysIntegr_IN_SynInProcess:
          if (test2_SysIntegration_DW.targetEncCnt <= 0) {
            test2_SysIntegration_DW.bitsForTID0.is_Wait4Task =
              test2_SysIntegrat_IN_ClrEncoder;
            test2_SysIntegration_DW.EncRstEvtEventCounter++;
            test2_SysIntegration_DW.prevDeliveryMissionId =
              test2_SysIntegration_B.DoseCtrlMsgOut_j.Head.MsgId;
            test2_SysIntegration_DW.bitsForTID0.boolNewDeliveryMission = false;
          } else {
            if (test2_SysIntegration_DW.targetEncCnt > 0) {
              test2_SysIntegration_DW.bitsForTID0.is_Wait4Task =
                test2_SysIntegration_IN_SynEnd;
            }
          }
          break;

         default:
          if (test2_SysIntegration_DW.bitsForTID0.boolSyn) {
            test2_SysIntegration_DW.bitsForTID0.boolSyn = false;
            test2_SysIntegration_DW.bitsForTID0.is_Wait4Sync = 0;
            test2_SysIntegration_DW.bitsForTID0.is_Wait4Task =
              test2_SysIntegr_IN_SynInProcess;
            test2_SysIntegration_DW.prevResidueEncCnt =
              test2_SysIntegration_DW.targetEncCnt;
            test2_SysIntegration_DW.targetEncCnt = 0;
            if ((test2_SysIntegration_DW.targetEncCnt < 0) &&
                (test2_SysIntegration_DW.prevResidueEncCnt < MIN_int32_T
                 - test2_SysIntegration_DW.targetEncCnt)) {
              test2_SysIntegration_DW.targetEncCnt = MIN_int32_T;
            } else if ((test2_SysIntegration_DW.targetEncCnt > 0) &&
                       (test2_SysIntegration_DW.prevResidueEncCnt > MAX_int32_T
                        - test2_SysIntegration_DW.targetEncCnt)) {
              test2_SysIntegration_DW.targetEncCnt = MAX_int32_T;
            } else {
              test2_SysIntegration_DW.targetEncCnt +=
                test2_SysIntegration_DW.prevResidueEncCnt;
            }
          } else {
            sf_internal_predicateOutput = false;
            b_sf_internal_predicateOutput = true;
            if (!(test2_SysIntegration_DW.errTime ==
                  test2_SysIntegration_ErrTimeMax)) {
              b_sf_internal_predicateOutput = false;
            }

            if (b_sf_internal_predicateOutput) {
              sf_internal_predicateOutput = true;
            }

            if (sf_internal_predicateOutput) {
              test2_SysIntegration_DW.bitsForTID0.is_Wait4Sync = 0;
              test2_SysIntegration_DW.bitsForTID0.is_Wait4Task =
                test2_SysIntegra_IN_CommFailure;
            } else if (test2_SysIntegration_DW.bitsForTID0.is_Wait4Sync ==
                       test2_SysInte_IN_Wait4MotorStop) {
              if ((*sfEvent_m == test2_SysInte_event_UpdateEvt_e) &&
                  (test2_SysIntegration_DW.temporalCounter_i2 >= 10U)) {
                test2_SysIntegration_DW.bitsForTID0.is_Wait4Sync =
                  test2_SysIntegr_IN_Wait4Sync_cb;
                test2_SysIntegration_DW.temporalCounter_i2 = 0U;
                tmp = (int32_T)(test2_SysIntegration_B.SynReqMsg.Head.MsgId + 1U);
                if ((uint32_T)tmp > 255U) {
                  tmp = 255;
                }

                test2_SysIntegration_B.SynReqMsg.Head.MsgId = (uint8_T)((uint8_T)
                  tmp % MAX_uint8_T);
                test2_SysIntegration_B.SynReqMsg.Head.OpCode = 2U;
                test2_SysIntegration_B.SynReqMsg.Body.Data = 0U;
                test2_SysIntegration_DW.prevSlaveMsgId = 0U;
                test2_SysIntegration_DW.bitsForTID0.boolSyn = false;
              }
            } else if ((*sfEvent_m == test2_SysInte_event_UpdateEvt_e) &&
                       (test2_SysIntegration_DW.temporalCounter_i2 >= 40U)) {
              tmp = (int32_T)(test2_SysIntegration_DW.errTime + 1U);
              if ((uint32_T)tmp > 255U) {
                tmp = 255;
              }

              test2_SysIntegration_DW.errTime = (uint8_T)tmp;
              test2_SysIntegration_DW.bitsForTID0.is_Wait4Sync =
                test2_SysIntegr_IN_Wait4Sync_cb;
              test2_SysIntegration_DW.temporalCounter_i2 = 0U;
              tmp = (int32_T)(test2_SysIntegration_B.SynReqMsg.Head.MsgId + 1U);
              if ((uint32_T)tmp > 255U) {
                tmp = 255;
              }

              test2_SysIntegration_B.SynReqMsg.Head.MsgId = (uint8_T)((uint8_T)
                tmp % MAX_uint8_T);
              test2_SysIntegration_B.SynReqMsg.Head.OpCode = 2U;
              test2_SysIntegration_B.SynReqMsg.Body.Data = 0U;
              test2_SysIntegration_DW.prevSlaveMsgId = 0U;
              test2_SysIntegration_DW.bitsForTID0.boolSyn = false;
            } else {
              if (test2_SysIntegration_DW.prevSlaveMsgId != 0) {
                test2_SysIntegration_DW.prevSlaveMsgId = 0U;
              }
            }
          }
          break;
        }
      }
    }

    if (guard1) {
      test2_SysIntegration_DW.bitsForTID0.is_Wait4Task = 0;
      test2_SysIntegration_DW.bitsForTID0.is_Wait4Sync = 0;
      test2_SysIntegration_DW.bitsForTID0.is_Wait =
        test2_SysIntegrati_IN_Wait4Sync;
      test2_SysIntegration_DW.errTime = 0U;
      test2_SysIntegration_DW.bitsForTID0.is_Wait4Sync_c =
        test2_SysInteg_IN_Wait4Sync_cbe;
      test2_SysIntegration_DW.temporalCounter_i1_di = 0U;
      tmp = (int32_T)(test2_SysIntegration_B.SynReqMsg.Head.MsgId + 1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      test2_SysIntegration_B.SynReqMsg.Head.MsgId = (uint8_T)((uint8_T)tmp %
        MAX_uint8_T);
      test2_SysIntegration_B.SynReqMsg.Head.OpCode = 1U;
      test2_SysIntegration_B.SynReqMsg.Body.Data = 0U;
      test2_SysIntegration_DW.prevSlaveMsgId = 0U;
      test2_SysIntegration_DW.bitsForTID0.boolSyn = false;
    }
  }
}

/* Function for Chart: '<S108>/Chart' */
static void te_enter_atomic_MissionComplete(void)
{
  boolean_T p;
  boolean_T b_p;
  int32_T tmp;
  p = false;
  b_p = true;
  if (!(test2_SysIntegration_DW.DoseMode == 200)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (p) {
    tmp = (int32_T)(test2_SysIntegration_B.LargeDoseTimeHitMsg.Head.MsgId + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    test2_SysIntegration_B.LargeDoseTimeHitMsg.Head.MsgId = (uint8_T)((uint8_T)
      tmp % MAX_uint8_T);
    test2_SysIntegration_B.LargeDoseTimeHitMsg.Head.OpCode = 12U;
  }

  tmp = (int32_T)(test2_SysIntegration_B.SynReqMsg.Head.MsgId + 1U);
  if ((uint32_T)tmp > 255U) {
    tmp = 255;
  }

  test2_SysIntegration_B.SynReqMsg.Head.MsgId = (uint8_T)((uint8_T)tmp %
    MAX_uint8_T);
  test2_SysIntegration_B.SynReqMsg.Head.OpCode = 2U;
  test2_SysIntegration_B.SynReqMsg.Body.Data = 0U;
  test2_SysIntegration_DW.prevSlaveMsgId = 0U;
  test2_SysIntegration_DW.bitsForTID0.boolSyn = false;
}

/* Function for Chart: '<S108>/Chart' */
static void test2_SysIntegration_Sync(void)
{
  boolean_T sf_internal_predicateOutput;
  boolean_T b_p;
  int32_T tmp;
  boolean_T guard1 = false;
  sf_internal_predicateOutput = ((test2_SysIntegration_DW.bitsForTID0.is_Sync ==
    test2_SysInteg_IN_Wait4Complete) &&
    (!test2_SysIntegration_B.bitsForTID4.boolNormalDeliverySwitchOn) &&
    (test2_SysIntegration_DW.DoseMode >= 200));
  guard1 = false;
  if (sf_internal_predicateOutput) {
    test2_SysIntegration_DW.bitsForTID0.boolMissionUnfinish = true;
    guard1 = true;
  } else if (test2_SysIntegration_DW.bitsForTID0.is_Sync ==
             test2_SysInte_IN_CtrlAccuracyOK) {
    guard1 = true;
  } else if (test2_SysIntegration_DW.bitsForTID0.is_Sync ==
             test2_SysInteg_IN_CommFailure_n) {
    test2_SysIntegration_DW.bitsForTID0.is_Sync = 0;
    test2_SysIntegration_B.bitsForTID0.boolMissionStop = true;
    test2_SysIntegration_DW.errTime = 0U;
    test2_SysIntegration_DW.bitsForTID0.is_c30_test2_SysIntegration =
      test2_SysIntegrati_IN_Terminate;
    tmp = (int32_T)(test2_SysIntegration_B.SysDiagMsg.Head.MsgId + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    test2_SysIntegration_B.SysDiagMsg.Head.MsgId = (uint8_T)((uint8_T)tmp %
      MAX_uint8_T);
    test2_SysIntegration_B.SysDiagMsg.Head.OpCode = 1U;
    test2_SysIntegration_B.SysDiagMsg.Body.Data = 8U;
    test2_SysIntegration_B.DoseMissionMsg.Head.OpCode = 0U;
    test2_SysIntegration_B.DoseMissionMsg.Body.Data = 0U;
  } else if (test2_SysIntegration_DW.bitsForTID0.is_Sync ==
             test2_SysInt_IN_CtrlAccuracyBad) {
    test2_SysIntegration_DW.bitsForTID0.is_Sync = 0;
    test2_SysIntegration_B.bitsForTID0.boolMissionStop = true;
    test2_SysIntegration_DW.errTime = 0U;
    test2_SysIntegration_DW.bitsForTID0.is_c30_test2_SysIntegration =
      test2_SysIntegrat_IN_Terminate1;
    tmp = (int32_T)(test2_SysIntegration_B.SysDiagMsg.Head.MsgId + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    test2_SysIntegration_B.SysDiagMsg.Head.MsgId = (uint8_T)((uint8_T)tmp %
      MAX_uint8_T);
    test2_SysIntegration_B.SysDiagMsg.Head.OpCode = 1U;
    test2_SysIntegration_B.SysDiagMsg.Body.Data = 18U;
    test2_SysIntegration_B.DoseMissionMsg.Head.OpCode = 0U;
    test2_SysIntegration_B.DoseMissionMsg.Body.Data = 0U;
  } else {
    switch (test2_SysIntegration_DW.bitsForTID0.is_Sync) {
     case test2_SysInteg_IN_CommFailure_n:
     case test2_SysInt_IN_CtrlAccuracyBad:
     case test2_SysInte_IN_CtrlAccuracyOK:
      break;

     case test2_SysInt_IN_MissionComplete:
      if (test2_SysIntegration_DW.bitsForTID0.boolSyn) {
        test2_SysIntegration_DW.bitsForTID0.boolSyn = false;
        test2_SysIntegration_DW.bitsForTID0.is_Sync =
          test2_SysIntegration_IN_Sync_b;
        test2_SysIntegration_DW.prevResidueEncCnt =
          test2_SysIntegration_DW.targetEncCnt;
        tmp = (int32_T)(test2_SysIntegration_B.DoseActionResultMsg.Head.MsgId +
                        1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        test2_SysIntegration_B.DoseActionResultMsg.Head.MsgId = (uint8_T)
          ((uint8_T)tmp % MAX_uint8_T);
        test2_SysIntegration_B.DoseActionResultMsg.Head.OpCode =
          test2_SysIntegration_DW.DoseMode;
        test2_SysIntegration_B.DoseActionResultMsg.Body =
          test2_SysIntegration_rtZtype_MotionSyn2SecurityMsg.Body;
        if (test2_SysIntegration_DW.targetEncCnt > 50) {
          test2_SysIntegration_DW.bitsForTID0.boolCtrlAccuracyFailure =
            ((real32_T)test2_SysIntegration_DW.prevResidueEncCnt / (real32_T)
             test2_SysIntegration_DW.targetEncCnt > 0.2F);
        } else {
          test2_SysIntegration_DW.bitsForTID0.boolCtrlAccuracyFailure = false;
        }
      } else {
        sf_internal_predicateOutput = false;
        b_p = true;
        if (!(test2_SysIntegration_DW.errTime == test2_SysIntegration_ErrTimeMax))
        {
          b_p = false;
        }

        if (b_p) {
          sf_internal_predicateOutput = true;
        }

        if (sf_internal_predicateOutput) {
          test2_SysIntegration_DW.bitsForTID0.is_Sync =
            test2_SysInteg_IN_CommFailure_n;
        } else if (test2_SysIntegration_DW.temporalCounter_i1_di >= 4000U) {
          tmp = (int32_T)(test2_SysIntegration_DW.errTime + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          test2_SysIntegration_DW.errTime = (uint8_T)tmp;
          test2_SysIntegration_DW.bitsForTID0.is_Sync =
            test2_SysInt_IN_MissionComplete;
          test2_SysIntegration_DW.temporalCounter_i1_di = 0U;
          te_enter_atomic_MissionComplete();
        } else {
          if (test2_SysIntegration_DW.prevSlaveMsgId != 0) {
            test2_SysIntegration_DW.prevSlaveMsgId = 0U;
          }
        }
      }
      break;

     case test2_SysIntegration_IN_Sync_b:
      if (!test2_SysIntegration_DW.bitsForTID0.boolCtrlAccuracyFailure) {
        test2_SysIntegration_DW.bitsForTID0.is_Sync =
          test2_SysInte_IN_CtrlAccuracyOK;
      } else {
        test2_SysIntegration_DW.bitsForTID0.is_Sync =
          test2_SysInt_IN_CtrlAccuracyBad;
      }
      break;

     default:
      if (test2_SysIntegration_B.bitsForTID0.boolMissionStop) {
        test2_SysIntegration_DW.bitsForTID0.is_Sync =
          test2_SysInt_IN_MissionComplete;
        test2_SysIntegration_DW.temporalCounter_i1_di = 0U;
        te_enter_atomic_MissionComplete();
      } else {
        if (test2_SysIntegration_DW.prevActuatorMsgId !=
            test2_SysIntegration_B.MotionStopACKMsg.Head.MsgId) {
          test2_SysIntegration_DW.prevActuatorMsgId =
            test2_SysIntegration_B.MotionStopACKMsg.Head.MsgId;
          sf_internal_predicateOutput = false;
          b_p = true;
          if (!(test2_SysIntegration_B.MotionStopACKMsg.Head.OpCode == 1)) {
            b_p = false;
          }

          if (b_p) {
            sf_internal_predicateOutput = true;
          }

          if (sf_internal_predicateOutput &&
              (!test2_SysIntegration_B.bitsForTID0.boolMissionStop)) {
            test2_SysIntegration_B.bitsForTID0.boolMissionStop = true;
          }
        }
      }
      break;
    }
  }

  if (guard1) {
    test2_SysIntegration_DW.bitsForTID0.is_Sync = 0;
    test2_SysIntegration_B.bitsForTID0.boolMissionStop = true;
    test2_SysIntegration_DW.bitsForTID0.is_c30_test2_SysIntegration =
      test2_SysIntegration_IN_Wait;
    test2_SysIntegration_DW.bitsForTID0.is_Wait =
      test2_SysIntegrati_IN_Wait4Task;
    test2_SysIntegration_DW.errTime = 0U;
    test2_SysIntegration_DW.bitsForTID0.is_Wait4Task =
      test2_SysIntegrat_IN_ClrEncoder;
    test2_SysIntegration_DW.EncRstEvtEventCounter++;
    test2_SysIntegration_DW.prevDeliveryMissionId =
      test2_SysIntegration_B.DoseCtrlMsgOut_j.Head.MsgId;
    test2_SysIntegration_DW.bitsForTID0.boolNewDeliveryMission = false;
  }
}

/* Function for Chart: '<S108>/Chart' */
static void chartstep_c30_test2_SysIntegrat(const int32_T *sfEvent_m)
{
  boolean_T p;
  boolean_T b_p;
  int32_T tmp;
  boolean_T guard1 = false;
  guard1 = false;
  switch (test2_SysIntegration_DW.bitsForTID0.is_c30_test2_SysIntegration) {
   case test2_SysIntegration_IN_Init:
    test2_SysIntegration_DW.bitsForTID0.is_c30_test2_SysIntegration =
      test2_SysIntegration_IN_Wait;
    test2_SysIntegration_DW.bitsForTID0.is_Wait =
      test2_SysIntegrati_IN_Wait4Task;
    test2_SysIntegration_DW.errTime = 0U;
    test2_SysIntegration_DW.bitsForTID0.is_Wait4Task =
      test2_SysIntegrat_IN_ClrEncoder;
    test2_SysIntegration_DW.EncRstEvtEventCounter++;
    test2_SysIntegration_DW.prevDeliveryMissionId =
      test2_SysIntegration_B.DoseCtrlMsgOut_j.Head.MsgId;
    test2_SysIntegration_DW.bitsForTID0.boolNewDeliveryMission = false;
    break;

   case test2_SysIntegration_IN_Sync:
    test2_SysIntegration_Sync();
    break;

   case test2_SysIntegrati_IN_Terminate:
   case test2_SysIntegrat_IN_Terminate1:
    break;

   default:
    if (test2_SysIntegration_DW.bitsForTID0.is_Wait4Sync_c ==
        test2_SysInteg_IN_CommFailure_n) {
      guard1 = true;
    } else if (test2_SysIntegration_DW.bitsForTID0.is_Wait4Sync_c ==
               test2_SysIntegra_IN_SynComplete) {
      switch (test2_SysIntegration_DW.bitsForTID0.is_Wait) {
       case test2_SysIntegrati_IN_Wait4Sync:
        test2_SysIntegration_DW.bitsForTID0.is_Wait4Sync_c = 0;
        test2_SysIntegration_DW.errTime = 0U;
        test2_SysIntegration_DW.bitsForTID0.is_Wait = 0;
        break;

       case test2_SysIntegrati_IN_Wait4Task:
        test2_SysIntegration_DW.bitsForTID0.is_Wait4Task = 0;
        test2_SysIntegration_DW.bitsForTID0.is_Wait4Sync = 0;
        test2_SysIntegration_DW.errTime = 0U;
        test2_SysIntegration_DW.bitsForTID0.is_Wait = 0;
        break;
      }

      test2_SysIntegration_DW.bitsForTID0.is_c30_test2_SysIntegration =
        test2_SysIntegration_IN_Sync;
      test2_SysIntegration_B.bitsForTID0.boolMissionStop = false;
      test2_SysIntegration_DW.errTime = 0U;
      test2_SysIntegration_DW.bitsForTID0.is_Sync =
        test2_SysInteg_IN_Wait4Complete;
      if (test2_SysIntegration_DW.DoseMode >= 200) {
        tmp = (int32_T)(test2_SysIntegration_B.LargeDoseTimeHitMsg.Head.MsgId +
                        1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        test2_SysIntegration_B.LargeDoseTimeHitMsg.Head.MsgId = (uint8_T)
          ((uint8_T)tmp % MAX_uint8_T);
        test2_SysIntegration_B.LargeDoseTimeHitMsg.Head.OpCode = 11U;
      }
    } else if (test2_SysIntegration_DW.bitsForTID0.is_Wait4Task ==
               test2_SysIntegra_IN_CommFailure) {
      guard1 = true;
    } else if (test2_SysIntegration_DW.bitsForTID0.is_Wait ==
               test2_SysIntegrati_IN_Wait4Sync) {
      switch (test2_SysIntegration_DW.bitsForTID0.is_Wait4Sync_c) {
       case test2_SysInteg_IN_CommFailure_n:
       case test2_SysIntegra_IN_SynComplete:
        break;

       default:
        if (test2_SysIntegration_DW.bitsForTID0.boolSyn) {
          test2_SysIntegration_DW.bitsForTID0.boolSyn = false;
          test2_SysIntegration_DW.bitsForTID0.is_Wait4Sync_c =
            test2_SysIntegra_IN_SynComplete;
          tmp = (int32_T)(test2_SysIntegration_B.DoseMissionMsg.Head.MsgId + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          test2_SysIntegration_B.DoseMissionMsg.Head.MsgId = (uint8_T)((uint8_T)
            tmp % MAX_uint8_T);
          test2_SysIntegration_B.DoseMissionMsg.Head.OpCode =
            test2_SysIntegration_DW.DoseMode;
          tmp = test2_SysIntegration_DW.targetEncCnt;
          if (test2_SysIntegration_DW.targetEncCnt < 0) {
            tmp = 0;
          }

          test2_SysIntegration_B.DoseMissionMsg.Body.Data = (uint32_T)tmp;
          test2_SysIntegration_DW.prevActuatorMsgId =
            test2_SysIntegration_B.MotionStopACKMsg.Head.MsgId;
        } else {
          p = false;
          b_p = true;
          if (!(test2_SysIntegration_DW.errTime ==
                test2_SysIntegration_ErrTimeMax)) {
            b_p = false;
          }

          if (b_p) {
            p = true;
          }

          if (p) {
            test2_SysIntegration_DW.bitsForTID0.is_Wait4Sync_c =
              test2_SysInteg_IN_CommFailure_n;
          } else if (test2_SysIntegration_DW.temporalCounter_i1_di >= 4000U) {
            tmp = (int32_T)(test2_SysIntegration_DW.errTime + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            test2_SysIntegration_DW.errTime = (uint8_T)tmp;
            test2_SysIntegration_DW.bitsForTID0.is_Wait4Sync_c =
              test2_SysInteg_IN_Wait4Sync_cbe;
            test2_SysIntegration_DW.temporalCounter_i1_di = 0U;
            tmp = (int32_T)(test2_SysIntegration_B.SynReqMsg.Head.MsgId + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            test2_SysIntegration_B.SynReqMsg.Head.MsgId = (uint8_T)((uint8_T)tmp
              % MAX_uint8_T);
            test2_SysIntegration_B.SynReqMsg.Head.OpCode = 1U;
            test2_SysIntegration_B.SynReqMsg.Body.Data = 0U;
            test2_SysIntegration_DW.prevSlaveMsgId = 0U;
            test2_SysIntegration_DW.bitsForTID0.boolSyn = false;
          } else {
            if (test2_SysIntegration_DW.prevSlaveMsgId != 0) {
              test2_SysIntegration_DW.prevSlaveMsgId = 0U;
            }
          }
        }
        break;
      }
    } else {
      test2_SysIntegration_Wait4Task(sfEvent_m);
    }
    break;
  }

  if (guard1) {
    switch (test2_SysIntegration_DW.bitsForTID0.is_Wait) {
     case test2_SysIntegrati_IN_Wait4Sync:
      test2_SysIntegration_DW.bitsForTID0.is_Wait4Sync_c = 0;
      test2_SysIntegration_DW.errTime = 0U;
      test2_SysIntegration_DW.bitsForTID0.is_Wait = 0;
      break;

     case test2_SysIntegrati_IN_Wait4Task:
      test2_SysIntegration_DW.bitsForTID0.is_Wait4Task = 0;
      test2_SysIntegration_DW.bitsForTID0.is_Wait4Sync = 0;
      test2_SysIntegration_DW.errTime = 0U;
      test2_SysIntegration_DW.bitsForTID0.is_Wait = 0;
      break;
    }

    test2_SysIntegration_DW.bitsForTID0.is_c30_test2_SysIntegration =
      test2_SysIntegrati_IN_Terminate;
    tmp = (int32_T)(test2_SysIntegration_B.SysDiagMsg.Head.MsgId + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    test2_SysIntegration_B.SysDiagMsg.Head.MsgId = (uint8_T)((uint8_T)tmp %
      MAX_uint8_T);
    test2_SysIntegration_B.SysDiagMsg.Head.OpCode = 1U;
    test2_SysIntegration_B.SysDiagMsg.Body.Data = 8U;
    test2_SysIntegration_B.DoseMissionMsg.Head.OpCode = 0U;
    test2_SysIntegration_B.DoseMissionMsg.Body.Data = 0U;
  }
}

/* Function for Chart: '<S68>/Chart1' */
static void chartstep_c42_test2_SysIntegrat(const int32_T *sfEvent_p)
{
  uint32_T qY;
  int32_T tmp;
  if (test2_SysIntegration_DW.bitsForTID0.is_c42_test2_SysIntegration ==
      test2_SysIntegration_IN_Acc) {
    if (*sfEvent_p == test2_SysIntegr_event_EncRstEvt) {
      /* UnitDelay: '<S4>/Unit Delay' */
      tmp = test2_SysIntegration_DW.UnitDelay_DSTATE_i;
      if (tmp < 0) {
        tmp = 0;
      }

      qY = test2_SysIntegration_B.EncRdOutACC + /*MW:OvSatOk*/ tmp;
      if (qY < test2_SysIntegration_B.EncRdOutACC) {
        qY = MAX_uint32_T;
      }

      test2_SysIntegration_B.EncRdOutACC = qY % MAX_uint32_T;
    }

    if (*sfEvent_p == test2_SysIntegr_event_EncClrEvt) {
      test2_SysIntegration_B.EncRdOutACC = 0U;
    }
  } else {
    if (*sfEvent_p == test2__event_FlashInitFinishEvt) {
      test2_SysIntegration_DW.bitsForTID0.is_c42_test2_SysIntegration =
        test2_SysIntegration_IN_Acc;
      test2_SysIntegration_B.EncRdOutACC = 0U;
    }
  }
}

/* Function for Chart: '<S69>/Chart' */
static void chartstep_c43_test2_SysIntegrat(const int32_T *sfEvent_mr)
{
  boolean_T sf_internal_predicateOutput;
  int32_T tmp;
  uint32_T qY;
  if (test2_SysIntegration_DW.bitsForTID0.is_c43_test2_SysIntegration ==
      test2_SysInte_IN_BubbleDetected) {
    sf_internal_predicateOutput =
      ((test2_SysIntegration_DW.bitsForTID0.is_BubbleDetected ==
        test2_SysIntegrati_IN_NotSure_i) &&
       (!test2_SysIntegration_B.bitsForTID5.boolBubbleDetected));
    if (sf_internal_predicateOutput ||
        (test2_SysIntegration_DW.bitsForTID0.is_BubbleDetected ==
         test2_SysIntegration_IN_Sure)) {
      test2_SysIntegration_DW.bitsForTID0.is_BubbleDetected = 0;
      test2_SysIntegration_DW.bitsForTID0.is_c43_test2_SysIntegration =
        test2_SysIn_IN_NoBubbleDetected;
      test2_SysIntegration_B.BubbleDetectionMsg.Head.MsgId = 0U;
      test2_SysIntegration_B.BubbleDetectionMsg.Head.OpCode = 1U;
      test2_SysIntegration_B.BubbleDetectionMsg.Body.Data = 0U;
    } else {
      if (test2_SysIntegration_DW.bitsForTID0.is_BubbleDetected ==
          test2_SysIntegrati_IN_NotSure_i) {
        qY = test2_SysIntegration_B.EncRdOutACC - /*MW:OvSatOk*/
          test2_SysIntegration_DW.MotorEncCnt;
        if (qY > test2_SysIntegration_B.EncRdOutACC) {
          qY = 0U;
        }

        if ((qY > MotorEncoderThVal4BubbleDetecti) || ((*sfEvent_mr ==
              test2_SysInteg_event_ShaftEncIO) &&
             (test2_SysIntegration_DW.temporalCounter_i1_js >=
              ShaftEncoderThVal4BubbleDetecti))) {
          test2_SysIntegration_DW.bitsForTID0.is_BubbleDetected =
            test2_SysIntegration_IN_Sure;
          tmp = (int32_T)(test2_SysIntegration_B.BubbleDetectionMsg.Head.MsgId +
                          1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          test2_SysIntegration_B.BubbleDetectionMsg.Head.MsgId = (uint8_T)
            ((uint8_T)tmp % MAX_uint8_T);
          test2_SysIntegration_B.BubbleDetectionMsg.Head.OpCode = 1U;
          test2_SysIntegration_B.BubbleDetectionMsg.Body.Data = 28U;
        }
      }
    }
  } else {
    if (test2_SysIntegration_B.bitsForTID5.boolBubbleDetected) {
      test2_SysIntegration_DW.bitsForTID0.is_c43_test2_SysIntegration =
        test2_SysInte_IN_BubbleDetected;
      test2_SysIntegration_DW.bitsForTID0.is_BubbleDetected =
        test2_SysIntegrati_IN_NotSure_i;
      test2_SysIntegration_DW.temporalCounter_i1_js = 0U;
      test2_SysIntegration_DW.MotorEncCnt = test2_SysIntegration_B.EncRdOutACC;
    }
  }
}

/* Function for Chart: '<S96>/MotorRunDriver' */
static boolean_T test2_SysIn_motorRunInSpeedMode(int8_T x_Direction)
{
  return motorRunInSpeedMode(x_Direction);
}

/* Function for Chart: '<S96>/MotorRunDriver' */
static boolean_T test2_SysInte_ServoStateInquiry(void)
{
  boolean_T y_boolStatus;
  y_boolStatus = true;
  servoStateInquiry(&y_boolStatus);
  return y_boolStatus;
}

/* Function for Chart: '<S96>/MotorRunDriver' */
static boolean_T test2_SysIntegra_motorServoCtrl(int32_T x_targetCnt, boolean_T
  x_boolEnable)
{
  return motorServoCtrl(x_targetCnt, x_boolEnable);
}

/* Function for Chart: '<S96>/MotorRunDriver' */
static boolean_T test2_SysIntegra_ForceMotorStop(boolean_T x_boolStop)
{
  return forceMotorStop(x_boolStop);
}

/* Function for Chart: '<S96>/MotorRunDriver' */
static void chartstep_c24_test2_SysIntegrat(const int32_T *sfEvent_m2)
{
  boolean_T d_sf_internal_predicateOutput;
  boolean_T tmp;
  int32_T tmp_0;
  boolean_T guard1 = false;
  d_sf_internal_predicateOutput =
    !test2_SysIntegration_B.bitsForTID0.boolMotorHomingEnable;
  tmp = !test2_SysIntegration_B.bitsForTID0.boolMotorServoEnable;
  guard1 = false;
  if ((*sfEvent_m2 == test2_SysInte_event_MotorServOn) &&
      test2_SysIntegration_B.bitsForTID4.boolNormalDeliverySwitchOn &&
      d_sf_internal_predicateOutput && tmp) {
    test2_SysIntegration_B.bitsForTID0.boolMotorServoEnable = true;
    guard1 = true;
  } else if (*sfEvent_m2 == test2_SysInt_event_ForceStopEvt) {
    test2_SysIntegration_B.bitsForTID0.boolMotorForwardEnable = false;
    test2_SysIntegration_B.bitsForTID0.boolMotorHomingEnable = false;
    test2_SysIntegration_B.bitsForTID0.boolMotorServoEnable = false;
    guard1 = true;
  } else if ((*sfEvent_m2 == test2_SysInte_event_ChargingEvt) &&
             d_sf_internal_predicateOutput && tmp) {
    test2_SysIntegration_DW.bitsForTID0.is_MotorServOn = 0;
    test2_SysIntegration_DW.bitsForTID0.is_MotorRun =
      test2_SysIntegra_IN_MotorCharge;
    test2_SysIntegration_B.bitsForTID0.boolMotorForwardEnable =
      !test2_SysIntegration_B.bitsForTID0.boolMotorForwardEnable;
    test2_SysIntegration_DW.bitsForTID0.boolCallbackSucceed = false;
  } else if ((*sfEvent_m2 == test2_SysIntegr_event_HomingEvt) &&
             (!test2_SysIntegration_B.bitsForTID0.boolMotorForwardEnable) && tmp)
  {
    test2_SysIntegration_DW.bitsForTID0.is_MotorServOn = 0;
    test2_SysIntegration_DW.bitsForTID0.is_MotorRun =
      test2_SysInteg_IN_MotorWithdraw;
    test2_SysIntegration_B.bitsForTID0.boolMotorHomingEnable =
      d_sf_internal_predicateOutput;
    test2_SysIntegration_DW.bitsForTID0.boolCallbackSucceed = false;
  } else {
    switch (test2_SysIntegration_DW.bitsForTID0.is_MotorRun) {
     case test2_SysIntegration_IN_Init:
      break;

     case test2_SysIntegra_IN_MotorCharge:
      if (!test2_SysIntegration_DW.bitsForTID0.boolCallbackSucceed) {
        if (test2_SysIntegration_B.bitsForTID0.boolMotorForwardEnable) {
          test2_SysIntegration_DW.bitsForTID0.boolCallbackSucceed =
            test2_SysIn_motorRunInSpeedMode(test2_SysIntegratio_AirExpelDir);
          if (test2_SysIntegration_DW.bitsForTID0.boolCallbackSucceed) {
            tmp_0 = (int32_T)
              (test2_SysIntegration_B.MotorServoStateMsg.Head.MsgId + 1U);
            if ((uint32_T)tmp_0 > 255U) {
              tmp_0 = 255;
            }

            test2_SysIntegration_B.MotorServoStateMsg.Head.MsgId = (uint8_T)
              ((uint8_T)tmp_0 % MAX_uint8_T);
            test2_SysIntegration_B.MotorServoStateMsg.Head.OpCode = 4U;
          }
        } else {
          test2_SysIntegration_DW.bitsForTID0.boolCallbackSucceed =
            test2_SysIn_motorRunInSpeedMode(test2_SysIntegrat_SpeedModeStop);
          if (test2_SysIntegration_DW.bitsForTID0.boolCallbackSucceed) {
            tmp_0 = (int32_T)
              (test2_SysIntegration_B.MotorServoStateMsg.Head.MsgId + 1U);
            if ((uint32_T)tmp_0 > 255U) {
              tmp_0 = 255;
            }

            test2_SysIntegration_B.MotorServoStateMsg.Head.MsgId = (uint8_T)
              ((uint8_T)tmp_0 % MAX_uint8_T);
            test2_SysIntegration_B.MotorServoStateMsg.Head.OpCode = MAX_uint8_T;
          }
        }
      }
      break;

     case test2_SysIntegra_IN_MotorServOn:
      switch (test2_SysIntegration_DW.bitsForTID0.is_MotorServOn) {
       case test2_SysIntegrati_IN_ForceStop:
        break;

       case test2_SysIn_IN_InProcessInquiry:
        if (!test2_SysIntegration_DW.bitsForTID0.temp_ServoState) {
          test2_SysIntegration_DW.bitsForTID0.is_MotorServOn =
            test2_SysIntegratio_IN_ServoEnd;
          tmp_0 = (int32_T)(test2_SysIntegration_B.MotorServoStateMsg.Head.MsgId
                            + 1U);
          if ((uint32_T)tmp_0 > 255U) {
            tmp_0 = 255;
          }

          test2_SysIntegration_B.MotorServoStateMsg.Head.MsgId = (uint8_T)
            ((uint8_T)tmp_0 % MAX_uint8_T);
          test2_SysIntegration_B.MotorServoStateMsg.Head.OpCode = 2U;
        } else {
          test2_SysIntegration_DW.bitsForTID0.temp_ServoState =
            test2_SysInte_ServoStateInquiry();
        }
        break;

       case test2_SysIntegra_IN_MotorAction:
        d_sf_internal_predicateOutput =
          (test2_SysIntegration_DW.bitsForTID0.boolCallbackSucceed &&
           test2_SysIntegration_B.bitsForTID0.boolMotorServoEnable);
        if (d_sf_internal_predicateOutput) {
          test2_SysIntegration_DW.bitsForTID0.temp_ServoState = true;
          test2_SysIntegration_DW.bitsForTID0.is_MotorServOn =
            test2_SysIn_IN_InProcessInquiry;
          tmp_0 = (int32_T)(test2_SysIntegration_B.MotorServoStateMsg.Head.MsgId
                            + 1U);
          if ((uint32_T)tmp_0 > 255U) {
            tmp_0 = 255;
          }

          test2_SysIntegration_B.MotorServoStateMsg.Head.MsgId = (uint8_T)
            ((uint8_T)tmp_0 % MAX_uint8_T);
          test2_SysIntegration_B.MotorServoStateMsg.Head.OpCode = 1U;
        } else if (!test2_SysIntegration_B.bitsForTID0.boolMotorServoEnable) {
          test2_SysIntegration_DW.bitsForTID0.is_MotorServOn =
            test2_SysIntegrati_IN_ForceStop;
          if (test2_SysIntegra_ForceMotorStop(true)) {
            tmp_0 = (int32_T)
              (test2_SysIntegration_B.MotorServoStateMsg.Head.MsgId + 1U);
            if ((uint32_T)tmp_0 > 255U) {
              tmp_0 = 255;
            }

            test2_SysIntegration_B.MotorServoStateMsg.Head.MsgId = (uint8_T)
              ((uint8_T)tmp_0 % MAX_uint8_T);
            test2_SysIntegration_B.MotorServoStateMsg.Head.OpCode = 3U;
          }
        } else {
          if (!test2_SysIntegration_DW.bitsForTID0.boolCallbackSucceed) {
            test2_SysIntegration_DW.bitsForTID0.boolCallbackSucceed =
              test2_SysIntegra_motorServoCtrl
              (test2_SysIntegration_B.targetEncCnt,
               test2_SysIntegration_B.bitsForTID0.boolMotorServoEnable);
          }
        }
        break;
      }
      break;

     default:
      if (!test2_SysIntegration_DW.bitsForTID0.boolCallbackSucceed) {
        if (test2_SysIntegration_B.bitsForTID0.boolMotorHomingEnable) {
          test2_SysIntegration_DW.bitsForTID0.boolCallbackSucceed =
            test2_SysIn_motorRunInSpeedMode(test2_SysIntegration_HomingDir);
          if (test2_SysIntegration_DW.bitsForTID0.boolCallbackSucceed) {
            tmp_0 = (int32_T)
              (test2_SysIntegration_B.MotorServoStateMsg.Head.MsgId + 1U);
            if ((uint32_T)tmp_0 > 255U) {
              tmp_0 = 255;
            }

            test2_SysIntegration_B.MotorServoStateMsg.Head.MsgId = (uint8_T)
              ((uint8_T)tmp_0 % MAX_uint8_T);
            test2_SysIntegration_B.MotorServoStateMsg.Head.OpCode = 5U;
          }
        } else {
          test2_SysIntegration_DW.bitsForTID0.boolCallbackSucceed =
            test2_SysIn_motorRunInSpeedMode(test2_SysIntegrat_SpeedModeStop);
          if (test2_SysIntegration_DW.bitsForTID0.boolCallbackSucceed) {
            tmp_0 = (int32_T)
              (test2_SysIntegration_B.MotorServoStateMsg.Head.MsgId + 1U);
            if ((uint32_T)tmp_0 > 255U) {
              tmp_0 = 255;
            }

            test2_SysIntegration_B.MotorServoStateMsg.Head.MsgId = (uint8_T)
              ((uint8_T)tmp_0 % MAX_uint8_T);
            test2_SysIntegration_B.MotorServoStateMsg.Head.OpCode = MAX_uint8_T;
          }
        }
      }
      break;
    }
  }

  if (guard1) {
    test2_SysIntegration_DW.bitsForTID0.is_MotorRun =
      test2_SysIntegra_IN_MotorServOn;
    test2_SysIntegration_DW.bitsForTID0.is_MotorServOn =
      test2_SysIntegra_IN_MotorAction;
    test2_SysIntegration_DW.bitsForTID0.boolCallbackSucceed = false;
  }
}

/* Function for Chart: '<S83>/Chart' */
static boolean_T test2_SysInt_judgeOcclusionStop(const int32_T x_OccVect[8],
  int32_T x_targetEnct, uint32_T x_rt_milliSecond, uint32_T x_rt_mAmSInteg)
{
  real32_T y_boolOcclusionStop_tmp;
  real32_T y_boolOcclusionStop_tmp_0;
  y_boolOcclusionStop_tmp = powf((real32_T)x_targetEnct, 3.0F);
  y_boolOcclusionStop_tmp_0 = (real32_T)x_targetEnct * (real32_T)x_targetEnct;
  return (x_rt_milliSecond > (((real32_T)x_OccVect[0] * 0.001F *
            y_boolOcclusionStop_tmp + (real32_T)x_OccVect[1] * 0.001F *
            y_boolOcclusionStop_tmp_0) + (real32_T)x_OccVect[2] * 0.001F *
           (real32_T)x_targetEnct) + (real32_T)x_OccVect[3] * 0.001F) ||
    (x_rt_mAmSInteg > (((real32_T)x_OccVect[4] * 0.001F *
                        y_boolOcclusionStop_tmp + (real32_T)x_OccVect[5] *
                        0.001F * y_boolOcclusionStop_tmp_0) + (real32_T)
                       x_OccVect[6] * 0.001F * (real32_T)x_targetEnct) +
     (real32_T)x_OccVect[7] * 0.001F);
}

/* Function for Chart: '<S83>/Chart' */
static void chartstep_c27_test2_SysIntegrat(const int32_T *sfEvent_c)
{
  boolean_T p;
  boolean_T b_p;
  int32_T tmp;
  if (*sfEvent_c == test2_SysInte_event_PerfEvalEvt) {
    if (test2_SysIntegration_DW.bitsForTID0.is_PerfAnalysor ==
        test2_SysInteg_IN_ServoAnalyzor) {
      if (test2_SysIntegration_DW.bitsForTID0.is_ServoAnalyzor ==
          test2_SysIntegration_IN_Op_p) {
        test2_SysIntegration_B.bitsForTID0.boolMonitorEna = false;
        test2_SysIntegration_DW.bitsForTID0.is_ServoAnalyzor = 0;
      } else {
        test2_SysIntegration_DW.bitsForTID0.is_ServoAnalyzor = 0;
      }

      test2_SysIntegration_DW.bitsForTID0.is_PerfAnalysor = 0;
    } else {
      test2_SysIntegration_DW.bitsForTID0.is_PerfAnalysor = 0;
    }

    test2_SysIntegration_DW.bitsForTID0.is_PerfAnalysor =
      test2_SysInteg_IN_ServoAnalyzor;
    test2_SysIntegration_DW.prevDrvFdbkMsgId =
      test2_SysIntegration_B.MotorServoStateMsg.Head.MsgId;
    test2_SysIntegration_DW.bitsForTID0.is_ServoAnalyzor =
      test2_SysIntegration_IN_Idle_k;
    test2_SysIntegration_DW.temp_OpCode = 0U;
  } else {
    switch (test2_SysIntegration_DW.bitsForTID0.is_PerfAnalysor) {
     case test2_SysIntegration_IN_Idle_k:
      break;

     default:
      if (test2_SysIntegration_DW.prevDrvFdbkMsgId !=
          test2_SysIntegration_B.MotorServoStateMsg.Head.MsgId) {
        test2_SysIntegration_DW.prevDrvFdbkMsgId =
          test2_SysIntegration_B.MotorServoStateMsg.Head.MsgId;
        test2_SysIntegration_DW.temp_OpCode =
          test2_SysIntegration_B.MotorServoStateMsg.Head.OpCode;
      }

      switch (test2_SysIntegration_DW.bitsForTID0.is_ServoAnalyzor) {
       case test2_SysIntegration_IN_Idle_k:
        p = false;
        b_p = true;
        if (!(test2_SysIntegration_DW.temp_OpCode == 1)) {
          b_p = false;
        }

        if (b_p) {
          p = true;
        }

        if (p) {
          test2_SysIntegration_DW.bitsForTID0.is_ServoAnalyzor =
            test2_SysIntegration_IN_Op_p;
          test2_SysIntegration_B.bitsForTID0.boolMonitorEna = true;
        }
        break;

       case test2_SysInteg_IN_OcclusionStop:
        test2_SysIntegration_DW.bitsForTID0.is_ServoAnalyzor =
          test2_SysIntegration_IN_Idle_k;
        test2_SysIntegration_DW.temp_OpCode = 0U;
        break;

       default:
        p = false;
        b_p = true;
        if (!(test2_SysIntegration_DW.temp_OpCode == 2)) {
          b_p = false;
        }

        if (b_p) {
          p = true;
        }

        if (p) {
          p = false;
          b_p = true;
          if (!(test2_SysIntegration_DW.temp_OpCode == 3)) {
            b_p = false;
          }

          if (b_p) {
            p = true;
          }
        } else {
          p = false;
        }

        if (p) {
          tmp = (int32_T)
            (test2_SysIntegration_B.PerfACKMissionFinishMsg.Head.MsgId + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          test2_SysIntegration_B.PerfACKMissionFinishMsg.Head.MsgId = (uint8_T)
            ((uint8_T)tmp % MAX_uint8_T);
          test2_SysIntegration_B.PerfACKMissionFinishMsg.Head.OpCode = 0U;
          tmp = (int32_T)(test2_SysIntegration_B.PerfEvalMsg.Head.MsgId + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          test2_SysIntegration_B.PerfEvalMsg.Head.MsgId = (uint8_T)((uint8_T)tmp
            % MAX_uint8_T);
          test2_SysIntegration_B.PerfEvalMsg.Head.OpCode = 1U;

          /* UnitDelay: '<S83>/Unit Delay' */
          test2_SysIntegration_B.PerfEvalMsg.Body.millSec =
            test2_SysIntegration_DW.UnitDelay_DSTATE_k;

          /* UnitDelay: '<S83>/Unit Delay1' */
          test2_SysIntegration_B.PerfEvalMsg.Body.mAmSecInteg =
            test2_SysIntegration_DW.UnitDelay1_DSTATE_c;
          test2_SysIntegration_B.bitsForTID0.boolMonitorEna = false;
          test2_SysIntegration_DW.bitsForTID0.is_ServoAnalyzor =
            test2_SysIntegration_IN_Idle_k;
          test2_SysIntegration_DW.temp_OpCode = 0U;
        } else if (test2_SysIntegration_DW.bitsForTID0.boolOcclusionStop) {
          test2_SysIntegration_DW.OcclusionJudgeEvtEventCounter++;
          test2_SysIntegration_DW.bitsForTID0.boolOcclusionStop = false;
          test2_SysIntegration_B.bitsForTID0.boolMonitorEna = false;
          test2_SysIntegration_DW.bitsForTID0.is_ServoAnalyzor =
            test2_SysInteg_IN_OcclusionStop;
          tmp = (int32_T)
            (test2_SysIntegration_B.PerfACKMissionFinishMsg.Head.MsgId + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          test2_SysIntegration_B.PerfACKMissionFinishMsg.Head.MsgId = (uint8_T)
            ((uint8_T)tmp % MAX_uint8_T);
          test2_SysIntegration_B.PerfACKMissionFinishMsg.Head.OpCode = 1U;
          test2_SysIntegration_B.PerfACKMissionFinishMsg.Body.Data = 2U;
        } else {
          /* UnitDelay: '<S83>/Unit Delay' incorporates:
           *  UnitDelay: '<S83>/Unit Delay1'
           */
          test2_SysIntegration_DW.bitsForTID0.boolOcclusionStop =
            test2_SysInt_judgeOcclusionStop
            (test2_SysIntegration_B.VarSet.AlarmCtrl.SSCurAndProcTimeCritPolyFitVect,
             test2_SysIntegration_B.targetEncCnt,
             test2_SysIntegration_DW.UnitDelay_DSTATE_k,
             test2_SysIntegration_DW.UnitDelay1_DSTATE_c);
        }
        break;
      }
      break;
    }
  }
}

/* Function for Chart: '<S98>/Chart' */
static real32_T test2_SysIntegra_JudgeMemMatrix(const real32_T Matrix1by10[10])
{
  real32_T temp_ResidueProbability;
  int32_T i;
  temp_ResidueProbability = 1.0F;
  for (i = 0; i < 10; i++) {
    temp_ResidueProbability *= 1.0F - Matrix1by10[i];
  }

  return 1.0F - temp_ResidueProbability;
}

/* Function for Chart: '<S98>/Chart' */
static void chartstep_c25_test2_SysIntegrat(const int32_T *sfEvent_a)
{
  real32_T tempProbability;
  real32_T tmp[10];
  real32_T tmp_0[10];
  int32_T i;
  if (*sfEvent_a == test2_SysInte_event_OccJudgeEvt) {
    /* UnitDelay: '<S4>/Unit Delay' */
    if (test2_SysIntegration_DW.UnitDelay_DSTATE_i <=
        test2_SysIntegration_B.targetEncCnt) {
      tempProbability = fminf(1.0F, ((real32_T)
        test2_SysIntegration_B.targetEncCnt - (real32_T)
        test2_SysIntegration_DW.UnitDelay_DSTATE_i) / (real32_T)
        test2_SysIntegration_B.targetEncCnt + 0.9F);
    } else {
      tempProbability = fmaxf(0.0F, 0.9F - ((real32_T)
        test2_SysIntegration_DW.UnitDelay_DSTATE_i - (real32_T)
        test2_SysIntegration_B.targetEncCnt) * 9.0F / (real32_T)
        test2_SysIntegration_B.targetEncCnt);
    }

    /* End of UnitDelay: '<S4>/Unit Delay' */
    if (test2_SysIntegration_B.targetEncCnt <= 50) {
      tempProbability *= 0.5F;
    }

    tmp[9] = 0.0F;
    for (i = 0; i < 9; i++) {
      tmp[i] = test2_SysIntegration_DW.MemMatrix[1 + i];
      tmp_0[i] = 0.0F;
    }

    tmp_0[9] = tempProbability;
    for (i = 0; i < 10; i++) {
      test2_SysIntegration_DW.MemMatrix[i] = tmp[i] + tmp_0[i];
    }

    if (test2_SysIntegra_JudgeMemMatrix(test2_SysIntegration_DW.MemMatrix) >=
        (real32_T)test2_SysIntegration_B.DataTypeConversion1_o / 100.0F) {
      i = (int32_T)(test2_SysIntegration_B.OcclusionDiagMsg.Head.MsgId + 1U);
      if ((uint32_T)i > 255U) {
        i = 255;
      }

      test2_SysIntegration_B.OcclusionDiagMsg.Head.MsgId = (uint8_T)((uint8_T)i %
        MAX_uint8_T);
      test2_SysIntegration_B.OcclusionDiagMsg.Head.OpCode = 1U;
      test2_SysIntegration_B.OcclusionDiagMsg.Body.Data = 2U;
    }
  }

  if (*sfEvent_a == test2_SysInteg_event_DiagClrEvt) {
    for (i = 0; i < 10; i++) {
      test2_SysIntegration_DW.MemMatrix[i] *= test2_SysIntegration_DW.MemWeight;
    }
  }
}

/* Function for Chart: '<S67>/PressureSingularityDetector' */
static void chartstep_c39_test2_SysIntegrat(const int32_T *sfEvent_g)
{
  uint32_T x;
  uint32_T qY;
  int16_T tmp;
  int32_T tmp_0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  if (*sfEvent_g == test2__event_AirExpelStopAckEvt) {
    test2_SysIntegration_DW.bitsForTID0.is_Monitor_o = 0;
    test2_SysIntegration_DW.bitsForTID0.is_Monitor =
      test2_SysIntegration_IN_Op_h;
    test2_SysIntegration_DW.bitsForTID0.is_Op_p =
      test2_SysIntegration_IN_Prepare;
    test2_SysIntegration_DW.temp_i = 0U;
    test2_SysIntegration_DW.temp_Sum = 0U;
  } else {
    switch (test2_SysIntegration_DW.bitsForTID0.is_Monitor) {
     case test2_SysIntegration_IN_Idle_k:
      break;

     default:
      guard1 = false;
      guard2 = false;
      guard3 = false;
      switch (test2_SysIntegration_DW.bitsForTID0.is_Op_p) {
       case test2_SysIntegration_IN_Monitor:
        if (*sfEvent_g == test2__event_DeliveryStopAckEvt) {
          test2_SysIntegration_DW.bitsForTID0.is_Monitor_o = 0;
          test2_SysIntegration_DW.bitsForTID0.is_Op_p =
            test2_SysIntegration_IN_Rest;
        } else {
          if (!(test2_SysIntegration_B.OpMaxPressure >
                test2_SysIntegration_B.DataTypeConversion1_a)) {
            test2_SysIntegration_B.OpMaxPressure =
              test2_SysIntegration_B.DataTypeConversion1_a;
          }

          if (!(test2_SysIntegration_B.OpMinPressure <
                test2_SysIntegration_B.DataTypeConversion1_a)) {
            test2_SysIntegration_B.OpMinPressure =
              test2_SysIntegration_B.DataTypeConversion1_a;
          }

          switch (test2_SysIntegration_DW.bitsForTID0.is_Monitor_o) {
           case test2_SysIntegration_IN_NoError:
            tmp_0 = test2_SysIntegration_B.OpMaxPressure -
              test2_SysIntegration_B.IdleMeanValuePressure;
            if (tmp_0 > 32767) {
              tmp_0 = 32767;
            } else {
              if (tmp_0 < -32768) {
                tmp_0 = -32768;
              }
            }

            if (tmp_0 > test2_SysIntegration_B.Gain) {
              test2_SysIntegration_DW.ErrMode = 20U;
              guard1 = true;
            } else {
              if (test2_SysIntegration_B.OpMinPressure < (int16_T)(int32_T)
                  roundf(0.7F * (real32_T)
                         test2_SysIntegration_B.IdleMeanValuePressure)) {
                test2_SysIntegration_DW.ErrMode = 21U;
                guard1 = true;
              }
            }
            break;

           case test2_SysIntegration_IN_NotSure:
            if ((test2_SysIntegration_DW.ErrMode == 20) &&
                (test2_SysIntegration_DW.Counter > 4)) {
              guard2 = true;
            } else {
              tmp_0 = test2_SysIntegration_B.OpMaxPressure -
                test2_SysIntegration_B.IdleMeanValuePressure;
              if (tmp_0 > 32767) {
                tmp_0 = 32767;
              } else {
                if (tmp_0 < -32768) {
                  tmp_0 = -32768;
                }
              }

              if (tmp_0 <= test2_SysIntegration_B.Gain) {
                guard3 = true;
              } else {
                qY = test2_SysIntegration_B.EncRdOutACC - /*MW:OvSatOk*/
                  test2_SysIntegration_DW.temp_EncCnt;
                if (qY > test2_SysIntegration_B.EncRdOutACC) {
                  qY = 0U;
                }

                if ((test2_SysIntegration_DW.ErrMode == 20) && (qY > 20U)) {
                  guard2 = true;
                } else if (test2_SysIntegration_B.OpMinPressure >= (int16_T)
                           (int32_T)roundf(0.9F * (real32_T)
                            test2_SysIntegration_B.IdleMeanValuePressure)) {
                  guard3 = true;
                } else if ((*sfEvent_g == test2_SysInteg_event_UpdateTick) &&
                           (test2_SysIntegration_DW.temporalCounter_i1_d5 >= 200)
                           && (test2_SysIntegration_DW.ErrMode == 21)) {
                  guard2 = true;
                } else {
                  if (*sfEvent_g == test2_S_event_ShaftEncoderPulse) {
                    tmp_0 = (int32_T)(test2_SysIntegration_DW.Counter + 1U);
                    if ((uint32_T)tmp_0 > 255U) {
                      tmp_0 = 255;
                    }

                    test2_SysIntegration_DW.Counter = (uint8_T)tmp_0;
                  }
                }
              }
            }
            break;
          }
        }
        break;

       case test2_SysIntegration_IN_Prepare:
        if (test2_SysIntegration_DW.temp_i > 200) {
          qY = test2_SysIntegration_DW.temp_Sum / 200U;
          x = test2_SysIntegration_DW.temp_Sum - qY * 200U;
          if ((x > 0U) && (x >= 100U)) {
            qY++;
          }

          if (qY > 32767U) {
            qY = 32767U;
          }

          test2_SysIntegration_B.IdleMeanValuePressure = (int16_T)qY;
          test2_SysIntegration_DW.bitsForTID0.is_Op_p =
            test2_SysIntegration_IN_Prepare;
          test2_SysIntegration_DW.temp_i = 0U;
          test2_SysIntegration_DW.temp_Sum = 0U;
        } else if (*sfEvent_g == test2_event_DeliveryStartAckEvt) {
          test2_SysIntegration_DW.bitsForTID0.is_Op_p =
            test2_SysIntegration_IN_Monitor;
          test2_SysIntegration_B.OpMaxPressure =
            test2_SysIntegration_B.DataTypeConversion1_a;
          test2_SysIntegration_B.OpMinPressure =
            test2_SysIntegration_B.DataTypeConversion1_a;
          test2_SysIntegration_DW.bitsForTID0.is_Monitor_o =
            test2_SysIntegration_IN_NoError;
          test2_SysIntegration_DW.ErrMode = 0U;
        } else {
          tmp_0 = (int32_T)(test2_SysIntegration_DW.temp_i + 1U);
          if ((uint32_T)tmp_0 > 255U) {
            tmp_0 = 255;
          }

          test2_SysIntegration_DW.temp_i = (uint8_T)tmp_0;
          tmp = test2_SysIntegration_B.DataTypeConversion1_a;
          if (test2_SysIntegration_B.DataTypeConversion1_a < 0) {
            tmp = 0;
          }

          qY = test2_SysIntegration_DW.temp_Sum + /*MW:OvSatOk*/ tmp;
          if (qY < test2_SysIntegration_DW.temp_Sum) {
            qY = MAX_uint32_T;
          }

          test2_SysIntegration_DW.temp_Sum = qY;
        }
        break;

       default:
        if (*sfEvent_g == test2_event_DeliveryStartAckEvt) {
          test2_SysIntegration_DW.bitsForTID0.is_Op_p =
            test2_SysIntegration_IN_Monitor;
          test2_SysIntegration_B.OpMaxPressure =
            test2_SysIntegration_B.DataTypeConversion1_a;
          test2_SysIntegration_B.OpMinPressure =
            test2_SysIntegration_B.DataTypeConversion1_a;
          test2_SysIntegration_DW.bitsForTID0.is_Monitor_o =
            test2_SysIntegration_IN_NoError;
          test2_SysIntegration_DW.ErrMode = 0U;
        }
        break;
      }

      if (guard3) {
        test2_SysIntegration_DW.bitsForTID0.is_Monitor_o =
          test2_SysIntegration_IN_NoError;
        test2_SysIntegration_DW.ErrMode = 0U;
      }

      if (guard2) {
        test2_SysIntegration_DW.bitsForTID0.is_Monitor_o =
          test2_SysInte_IN_Sure2Occlusion;
        test2_SysIntegration_DW.temp_EncCnt = 0U;
        test2_SysIntegration_DW.Counter = 0U;
        tmp_0 = (int32_T)(test2_SysIntegration_B.PressureDiagMsg.Head.MsgId + 1U);
        if ((uint32_T)tmp_0 > 255U) {
          tmp_0 = 255;
        }

        test2_SysIntegration_B.PressureDiagMsg.Head.MsgId = (uint8_T)((uint8_T)
          tmp_0 % MAX_uint8_T);
        test2_SysIntegration_B.PressureDiagMsg.Body.Data =
          test2_SysIntegration_DW.ErrMode;
      }

      if (guard1) {
        test2_SysIntegration_DW.bitsForTID0.is_Monitor_o =
          test2_SysIntegration_IN_NotSure;
        test2_SysIntegration_DW.temporalCounter_i1_d5 = 0U;
        test2_SysIntegration_DW.Counter = 0U;
        test2_SysIntegration_DW.temp_EncCnt = test2_SysIntegration_B.EncRdOutACC;
      }
      break;
    }
  }
}

/* Function for Chart: '<S113>/MemoryFilter' */
static void test2_SysIntegration_ShiftUp(const uint8_T x_AlarmFMCodeMemory[24],
  uint8_T y_AlarmFMCodeMemory[24])
{
  int32_T i;
  for (i = 0; i < 8; i++) {
    y_AlarmFMCodeMemory[3 * i] = x_AlarmFMCodeMemory[3 * i + 1];
    y_AlarmFMCodeMemory[1 + 3 * i] = x_AlarmFMCodeMemory[3 * i + 2];
    y_AlarmFMCodeMemory[2 + 3 * i] = 0U;
  }
}

/* Function for Chart: '<S113>/Buffer' */
static boolean_T test2_SysIntegration_isequal_o(const uint8_T varargin_1[8],
  const uint8_T varargin_2[8])
{
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  boolean_T exitg1;
  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 8)) {
    if (!(varargin_1[k] == varargin_2[k])) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

/* Function for Chart: '<S113>/MemoryFilter' */
static void test2_SysI_NonZeroElementPushIn(uint8_T x_AlarmFMCodeMemory[24],
  const uint8_T xData[8])
{
  int32_T i;
  uint8_T x_AlarmFMCodeMemory_idx_1;
  for (i = 0; i < 8; i++) {
    if (xData[i] != 0) {
      x_AlarmFMCodeMemory_idx_1 = x_AlarmFMCodeMemory[3 * i + 2];
      x_AlarmFMCodeMemory[3 * i] = x_AlarmFMCodeMemory[3 * i + 1];
      x_AlarmFMCodeMemory[1 + 3 * i] = x_AlarmFMCodeMemory_idx_1;
      x_AlarmFMCodeMemory[2 + 3 * i] = xData[i];
    }
  }
}

/* Function for Chart: '<S113>/Buffer' */
static void test2_SysIntegr_PopHighestAlarm(type_HMI2SecurityMsg *x_AlarmMsgOut,
  const uint8_T x_HighStack[8], const uint8_T x_MidStack[8], const uint8_T
  x_LowStack[8], uint8_T y_HighStack[8], uint8_T y_MidStack[8], uint8_T
  y_LowStack[8], boolean_T y_boolAlarmEmpty[3])
{
  uint8_T temp_HighestLevelAlarm;
  boolean_T p;
  boolean_T b_p;
  int32_T i;
  uint8_T tmp[8];
  temp_HighestLevelAlarm = 0U;
  for (i = 0; i < 8; i++) {
    y_HighStack[i] = x_HighStack[i];
    y_MidStack[i] = x_MidStack[i];
    y_LowStack[i] = x_LowStack[i];
    tmp[i] = 0U;
  }

  if (!test2_SysIntegration_isequal_o(x_HighStack, tmp)) {
    temp_HighestLevelAlarm = x_HighStack[0];
    for (i = 0; i < 7; i++) {
      y_HighStack[i] = x_HighStack[i + 1];
    }

    y_HighStack[7] = 0U;
  } else {
    for (i = 0; i < 8; i++) {
      tmp[i] = 0U;
    }

    if (!test2_SysIntegration_isequal_o(x_MidStack, tmp)) {
      temp_HighestLevelAlarm = x_MidStack[0];
      for (i = 0; i < 7; i++) {
        y_MidStack[i] = x_MidStack[i + 1];
      }

      y_MidStack[7] = 0U;
    } else {
      for (i = 0; i < 8; i++) {
        tmp[i] = 0U;
      }

      if (!test2_SysIntegration_isequal_o(x_LowStack, tmp)) {
        temp_HighestLevelAlarm = x_LowStack[0];
        for (i = 0; i < 7; i++) {
          y_LowStack[i] = x_LowStack[i + 1];
        }

        y_LowStack[7] = 0U;
      }
    }
  }

  p = false;
  b_p = true;
  if (!(temp_HighestLevelAlarm == 0)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    x_AlarmMsgOut->Head.MsgId = (uint8_T)((uint8_T)(x_AlarmMsgOut->Head.MsgId +
      1U) % MAX_uint8_T);
    x_AlarmMsgOut->Head.OpCode = 1U;
    x_AlarmMsgOut->Body.Data = temp_HighestLevelAlarm;
  }

  for (i = 0; i < 8; i++) {
    tmp[i] = 0U;
  }

  y_boolAlarmEmpty[0] = test2_SysIntegration_isequal_o(y_HighStack, tmp);
  for (i = 0; i < 8; i++) {
    tmp[i] = 0U;
  }

  y_boolAlarmEmpty[1] = test2_SysIntegration_isequal_o(y_MidStack, tmp);
  for (i = 0; i < 8; i++) {
    tmp[i] = 0U;
  }

  y_boolAlarmEmpty[2] = test2_SysIntegration_isequal_o(y_LowStack, tmp);
}

/* Function for Chart: '<S113>/Buffer' */
static void test2_SysIntegr_PushInAlarmInfo(uint8_T x_HighStack[8], uint8_T
  x_MidStack[8], uint8_T x_LowStack[8], const uint8_T x_AlarmPushInMsg[8],
  boolean_T y_boolAlarmEmpty[3])
{
  int32_T i;
  boolean_T p;
  boolean_T b_p;
  uint8_T x2_Stack[8];
  int32_T i_0;
  uint8_T tmp[8];
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  for (i = 0; i < 8; i++) {
    guard1 = false;
    guard2 = false;
    if (x_AlarmPushInMsg[i] < 100) {
      p = false;
      b_p = true;
      if (!(x_AlarmPushInMsg[i] == 0)) {
        b_p = false;
      }

      if (b_p) {
        p = true;
      }

      if (!p) {
        for (i_0 = 0; i_0 < 8; i_0++) {
          x2_Stack[i_0] = x_HighStack[i_0];
        }

        x_HighStack[0] = x_AlarmPushInMsg[i];
        for (i_0 = 0; i_0 < 7; i_0++) {
          x_HighStack[1 + i_0] = x2_Stack[i_0];
        }
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2) {
      if (x_AlarmPushInMsg[i] < 200) {
        p = false;
        b_p = true;
        if (!(x_AlarmPushInMsg[i] == 0)) {
          b_p = false;
        }

        if (b_p) {
          p = true;
        }

        if (!p) {
          for (i_0 = 0; i_0 < 8; i_0++) {
            x2_Stack[i_0] = x_MidStack[i_0];
          }

          x_MidStack[0] = x_AlarmPushInMsg[i];
          for (i_0 = 0; i_0 < 7; i_0++) {
            x_MidStack[1 + i_0] = x2_Stack[i_0];
          }
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    }

    if (guard1) {
      if (x_AlarmPushInMsg[i] < 255) {
        p = false;
        b_p = true;
        if (!(x_AlarmPushInMsg[i] == 0)) {
          b_p = false;
        }

        if (b_p) {
          p = true;
        }

        if (!p) {
          for (i_0 = 0; i_0 < 8; i_0++) {
            x2_Stack[i_0] = x_LowStack[i_0];
          }

          x_LowStack[0] = x_AlarmPushInMsg[i];
          for (i_0 = 0; i_0 < 7; i_0++) {
            x_LowStack[1 + i_0] = x2_Stack[i_0];
          }
        }
      }
    }

    tmp[i] = 0U;
  }

  y_boolAlarmEmpty[0] = test2_SysIntegration_isequal_o(x_HighStack, tmp);
  for (i_0 = 0; i_0 < 8; i_0++) {
    tmp[i_0] = 0U;
  }

  y_boolAlarmEmpty[1] = test2_SysIntegration_isequal_o(x_MidStack, tmp);
  for (i_0 = 0; i_0 < 8; i_0++) {
    tmp[i_0] = 0U;
  }

  y_boolAlarmEmpty[2] = test2_SysIntegration_isequal_o(x_LowStack, tmp);
}

/* Function for Chart: '<S113>/Buffer' */
static void chartstep_c31_test2_SysIntegrat(const int32_T *sfEvent_d)
{
  uint8_T HighStack[8];
  uint8_T MidStack[8];
  uint8_T LowStack[8];
  int32_T i;
  if (*sfEvent_d == test2_SysInte_event_PopAlarmEvt) {
    test2_SysIntegr_PopHighestAlarm(&test2_SysIntegration_B.AlarmACKMsgOut,
      test2_SysIntegration_DW.HighStack, test2_SysIntegration_DW.MidStack,
      test2_SysIntegration_DW.LowStack, HighStack, MidStack, LowStack,
      test2_SysIntegration_B.boolAlarmEmpty);
    for (i = 0; i < 8; i++) {
      test2_SysIntegration_DW.HighStack[i] = HighStack[i];
      test2_SysIntegration_DW.MidStack[i] = MidStack[i];
      test2_SysIntegration_DW.LowStack[i] = LowStack[i];
    }
  }

  if (*sfEvent_d == test2_SysI_event_RecvDiagMsgEvt) {
    test2_SysIntegr_PushInAlarmInfo(test2_SysIntegration_DW.HighStack,
      test2_SysIntegration_DW.MidStack, test2_SysIntegration_DW.LowStack,
      test2_SysIntegration_B.xLevelAlarmPushMsg,
      test2_SysIntegration_B.boolAlarmEmpty);
  }
}

/* Function for Chart: '<S112>/Chart' */
static void test2_Sys_enter_internal_idle_n(void)
{
  int32_T tmp;
  switch (test2_SysIntegration_DW.bitsForTID1.was_idle_o) {
   case test2_SysInteg_IN_LowLevelAlarm:
    test2_SysIntegration_DW.bitsForTID1.is_idle_g =
      test2_SysInteg_IN_LowLevelAlarm;
    test2_SysIntegration_DW.bitsForTID1.was_idle_o =
      test2_SysInteg_IN_LowLevelAlarm;
    test2_SysIntegration_B.SysDiagMsgOut_c[0] = (uint8_T)
      (test2_SysIntegration_B.SysDiagMsgOut_c[0] > 0);
    test2_SysIntegration_B.SysDiagMsgOut_c[1] = (uint8_T)
      (test2_SysIntegration_B.SysDiagMsgOut_c[1] > 0);
    test2_SysIntegration_B.SysDiagMsgOut_c[2] = 1U;
    test2_SysIntegration_B.CommMsgOut.FMCode =
      test2_SysIntegration_DW.LowAlarmFMCode;
    tmp = (int32_T)(test2_SysIntegration_B.CommMsgOut.MsgId + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    test2_SysIntegration_B.CommMsgOut.MsgId = (uint8_T)((uint8_T)tmp %
      MAX_uint8_T);
    test2_SysIntegration_B.AlarmCtrlData.AlarmLevel = 1U;
    test2_SysIntegration_DW.AlarmCtrlEvtEventCounter++;
    break;

   case 2:
    test2_SysIntegration_DW.bitsForTID1.is_idle_g = 2;
    test2_SysIntegration_DW.bitsForTID1.was_idle_o = 2;
    break;

   default:
    test2_SysIntegration_DW.bitsForTID1.is_idle_g = 2;
    test2_SysIntegration_DW.bitsForTID1.was_idle_o = 2;
    break;
  }
}

/* Function for Chart: '<S112>/Chart' */
static void test2_SysIn_enter_internal_idle(void)
{
  int32_T tmp;
  switch (test2_SysIntegration_DW.bitsForTID1.was_idle) {
   case test2_SysInteg_IN_MidLevelAlarm:
    test2_SysIntegration_DW.bitsForTID1.is_idle =
      test2_SysInteg_IN_MidLevelAlarm;
    test2_SysIntegration_DW.bitsForTID1.was_idle =
      test2_SysInteg_IN_MidLevelAlarm;
    test2_SysIntegration_B.SysDiagMsgOut_c[0] = (uint8_T)
      (test2_SysIntegration_B.SysDiagMsgOut_c[0] > 0);
    test2_SysIntegration_B.SysDiagMsgOut_c[1] = 1U;
    test2_SysIntegration_B.SysDiagMsgOut_c[2] = (uint8_T)
      (test2_SysIntegration_B.SysDiagMsgOut_c[2] > 0);
    test2_SysIntegration_B.CommMsgOut.FMCode =
      test2_SysIntegration_DW.MidAlarmFMCode;
    tmp = (int32_T)(test2_SysIntegration_B.CommMsgOut.MsgId + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    test2_SysIntegration_B.CommMsgOut.MsgId = (uint8_T)((uint8_T)tmp %
      MAX_uint8_T);
    test2_SysIntegration_B.AlarmCtrlData.AlarmLevel = 2U;
    test2_SysIntegration_DW.AlarmCtrlEvtEventCounter++;
    break;

   case 2:
    test2_SysIntegration_DW.bitsForTID1.is_idle = 2;
    test2_SysIntegration_DW.bitsForTID1.was_idle = 2;
    test2_Sys_enter_internal_idle_n();
    break;

   default:
    test2_SysIntegration_DW.bitsForTID1.is_idle = 2;
    test2_SysIntegration_DW.bitsForTID1.was_idle = 2;
    test2_Sys_enter_internal_idle_n();
    break;
  }
}

/* Function for Chart: '<S112>/Chart' */
static void test2_SysIntegration_TaskAct(void)
{
  int32_T qY;
  uint32_T qY_tmp;
  test2_SysIntegration_B.bitsForTID1.LowPowerMsgOut =
    ((test2_SysIntegration_DW.bitsForTID1.is_idle_g ==
      test2_SysInteg_IN_LowLevelAlarm) ||
     (test2_SysIntegration_DW.bitsForTID1.is_idle ==
      test2_SysInteg_IN_MidLevelAlarm) ||
     (test2_SysIntegration_DW.bitsForTID1.is_TaskAct ==
      test2_SysInte_IN_HighLevelAlarm));
  if (test2_SysIntegration_B.BusCreator.MsgId !=
      test2_SysIntegration_DW.prevSysDiagMsgId_e) {
    if ((test2_SysIntegration_DW.AlarmCtrlParam.LowLevelInd[0] <=
         test2_SysIntegration_B.BusCreator.FMCode) &&
        (test2_SysIntegration_B.BusCreator.FMCode <=
         test2_SysIntegration_DW.AlarmCtrlParam.LowLevelInd[1])) {
      test2_SysIntegration_DW.bitsForTID1.LowAlarmEnable =
        test2_SysIntegration_B.BusCreator.OpCode;
      test2_SysIntegration_DW.LowAlarmFMCode =
        test2_SysIntegration_B.BusCreator.FMCode;
    } else if ((test2_SysIntegration_DW.AlarmCtrlParam.MidLevelInd[0] <=
                test2_SysIntegration_B.BusCreator.FMCode) &&
               (test2_SysIntegration_B.BusCreator.FMCode <=
                test2_SysIntegration_DW.AlarmCtrlParam.MidLevelInd[1])) {
      test2_SysIntegration_DW.bitsForTID1.MidAlarmEnable =
        test2_SysIntegration_B.BusCreator.OpCode;
      test2_SysIntegration_DW.MidAlarmFMCode =
        test2_SysIntegration_B.BusCreator.FMCode;
    } else {
      if ((test2_SysIntegration_DW.AlarmCtrlParam.HighLevelInd[0] <=
           test2_SysIntegration_B.BusCreator.FMCode) &&
          (test2_SysIntegration_B.BusCreator.FMCode <=
           test2_SysIntegration_DW.AlarmCtrlParam.HighLevelInd[1])) {
        test2_SysIntegration_DW.bitsForTID1.HighAlarmEnable =
          test2_SysIntegration_B.BusCreator.OpCode;
        test2_SysIntegration_DW.HighAlarmFMCode =
          test2_SysIntegration_B.BusCreator.FMCode;
      }
    }

    test2_SysIntegration_DW.prevSysDiagMsgId_e =
      test2_SysIntegration_B.BusCreator.MsgId;
  }

  if (test2_SysIntegration_DW.bitsForTID1.is_TaskAct ==
      test2_SysInte_IN_HighLevelAlarm) {
    if (!test2_SysIntegration_DW.bitsForTID1.HighAlarmEnable) {
      test2_SysIntegration_B.CommMsgOut.AlarmSwitch = false;
      test2_SysIntegration_B.AlarmCtrlData.AlarmLevel = 0U;
      qY_tmp = test2_SysIntegration_B.SysDiagMsgOut_c[0] - /*MW:OvSatOk*/ 1U;
      if (qY_tmp > test2_SysIntegration_B.SysDiagMsgOut_c[0]) {
        qY_tmp = 0U;
      }

      test2_SysIntegration_B.SysDiagMsgOut_c[0] = (uint8_T)qY_tmp;
      qY = test2_SysIntegration_B.SysDiagMsgOut_c[1];
      test2_SysIntegration_B.SysDiagMsgOut_c[1] = (uint8_T)qY;
      qY = test2_SysIntegration_B.SysDiagMsgOut_c[2];
      test2_SysIntegration_B.SysDiagMsgOut_c[2] = (uint8_T)qY;
      test2_SysIntegration_DW.AlarmCtrlEvtEventCounter++;
      test2_SysIntegration_DW.HighLevelAlarmEvtStopEventCount++;
      test2_SysIntegration_DW.bitsForTID1.is_TaskAct = 2;
      test2_SysIn_enter_internal_idle();
    }
  } else if (test2_SysIntegration_DW.bitsForTID1.HighAlarmEnable) {
    switch (test2_SysIntegration_DW.bitsForTID1.is_idle) {
     case test2_SysInteg_IN_MidLevelAlarm:
      test2_SysIntegration_B.CommMsgOut.AlarmSwitch = false;
      test2_SysIntegration_B.AlarmCtrlData.AlarmLevel = 0U;
      qY = test2_SysIntegration_B.SysDiagMsgOut_c[0];
      test2_SysIntegration_B.SysDiagMsgOut_c[0] = (uint8_T)qY;
      qY_tmp = test2_SysIntegration_B.SysDiagMsgOut_c[1] - /*MW:OvSatOk*/ 1U;
      if (qY_tmp > test2_SysIntegration_B.SysDiagMsgOut_c[1]) {
        qY_tmp = 0U;
      }

      test2_SysIntegration_B.SysDiagMsgOut_c[1] = (uint8_T)qY_tmp;
      qY = test2_SysIntegration_B.SysDiagMsgOut_c[2];
      test2_SysIntegration_B.SysDiagMsgOut_c[2] = (uint8_T)qY;
      test2_SysIntegration_DW.bitsForTID1.is_idle = 0;
      break;

     case 2:
      if (test2_SysIntegration_DW.bitsForTID1.is_idle_g ==
          test2_SysInteg_IN_LowLevelAlarm) {
        test2_SysIntegration_B.CommMsgOut.AlarmSwitch = false;
        test2_SysIntegration_B.AlarmCtrlData.AlarmLevel = 0U;
        qY = test2_SysIntegration_B.SysDiagMsgOut_c[0];
        test2_SysIntegration_B.SysDiagMsgOut_c[0] = (uint8_T)qY;
        qY = test2_SysIntegration_B.SysDiagMsgOut_c[1];
        test2_SysIntegration_B.SysDiagMsgOut_c[1] = (uint8_T)qY;
        qY_tmp = test2_SysIntegration_B.SysDiagMsgOut_c[2] - /*MW:OvSatOk*/ 1U;
        if (qY_tmp > test2_SysIntegration_B.SysDiagMsgOut_c[2]) {
          qY_tmp = 0U;
        }

        test2_SysIntegration_B.SysDiagMsgOut_c[2] = (uint8_T)qY_tmp;
        test2_SysIntegration_DW.bitsForTID1.is_idle_g = 0;
      } else {
        test2_SysIntegration_DW.bitsForTID1.is_idle_g = 0;
      }

      test2_SysIntegration_DW.bitsForTID1.is_idle = 0;
      break;
    }

    test2_SysIntegration_B.CommMsgOut.AlarmSwitch = true;
    test2_SysIntegration_DW.bitsForTID1.is_TaskAct =
      test2_SysInte_IN_HighLevelAlarm;
    test2_SysIntegration_B.SysDiagMsgOut_c[0] = 1U;
    test2_SysIntegration_B.SysDiagMsgOut_c[1] = (uint8_T)
      (test2_SysIntegration_B.SysDiagMsgOut_c[1] > 0);
    test2_SysIntegration_B.SysDiagMsgOut_c[2] = (uint8_T)
      (test2_SysIntegration_B.SysDiagMsgOut_c[2] > 0);
    test2_SysIntegration_B.CommMsgOut.FMCode =
      test2_SysIntegration_DW.HighAlarmFMCode;
    qY = (int32_T)(test2_SysIntegration_B.CommMsgOut.MsgId + 1U);
    if ((uint32_T)qY > 255U) {
      qY = 255;
    }

    test2_SysIntegration_B.CommMsgOut.MsgId = (uint8_T)((uint8_T)qY %
      MAX_uint8_T);
    test2_SysIntegration_B.AlarmCtrlData.AlarmLevel = 3U;
    test2_SysIntegration_DW.AlarmCtrlEvtEventCounter++;
    test2_SysIntegration_DW.HighLevelAlarmEvtStartEventCoun++;
  } else if (test2_SysIntegration_DW.bitsForTID1.is_idle ==
             test2_SysInteg_IN_MidLevelAlarm) {
    if (!test2_SysIntegration_DW.bitsForTID1.MidAlarmEnable) {
      test2_SysIntegration_DW.AlarmCtrlEvtEventCounter++;
      test2_SysIntegration_B.CommMsgOut.AlarmSwitch = false;
      test2_SysIntegration_B.AlarmCtrlData.AlarmLevel = 0U;
      qY = test2_SysIntegration_B.SysDiagMsgOut_c[0];
      test2_SysIntegration_B.SysDiagMsgOut_c[0] = (uint8_T)qY;
      qY_tmp = test2_SysIntegration_B.SysDiagMsgOut_c[1] - /*MW:OvSatOk*/ 1U;
      if (qY_tmp > test2_SysIntegration_B.SysDiagMsgOut_c[1]) {
        qY_tmp = 0U;
      }

      test2_SysIntegration_B.SysDiagMsgOut_c[1] = (uint8_T)qY_tmp;
      qY = test2_SysIntegration_B.SysDiagMsgOut_c[2];
      test2_SysIntegration_B.SysDiagMsgOut_c[2] = (uint8_T)qY;
      test2_SysIntegration_DW.bitsForTID1.is_idle = 2;
      test2_SysIntegration_DW.bitsForTID1.was_idle = 2;
      test2_Sys_enter_internal_idle_n();
    }
  } else if (test2_SysIntegration_DW.bitsForTID1.MidAlarmEnable) {
    if (test2_SysIntegration_DW.bitsForTID1.is_idle_g ==
        test2_SysInteg_IN_LowLevelAlarm) {
      test2_SysIntegration_B.CommMsgOut.AlarmSwitch = false;
      test2_SysIntegration_B.AlarmCtrlData.AlarmLevel = 0U;
      qY = test2_SysIntegration_B.SysDiagMsgOut_c[0];
      test2_SysIntegration_B.SysDiagMsgOut_c[0] = (uint8_T)qY;
      qY = test2_SysIntegration_B.SysDiagMsgOut_c[1];
      test2_SysIntegration_B.SysDiagMsgOut_c[1] = (uint8_T)qY;
      qY_tmp = test2_SysIntegration_B.SysDiagMsgOut_c[2] - /*MW:OvSatOk*/ 1U;
      if (qY_tmp > test2_SysIntegration_B.SysDiagMsgOut_c[2]) {
        qY_tmp = 0U;
      }

      test2_SysIntegration_B.SysDiagMsgOut_c[2] = (uint8_T)qY_tmp;
      test2_SysIntegration_DW.bitsForTID1.is_idle_g = 0;
    } else {
      test2_SysIntegration_DW.bitsForTID1.is_idle_g = 0;
    }

    test2_SysIntegration_B.CommMsgOut.AlarmSwitch = true;
    test2_SysIntegration_DW.bitsForTID1.is_idle =
      test2_SysInteg_IN_MidLevelAlarm;
    test2_SysIntegration_DW.bitsForTID1.was_idle =
      test2_SysInteg_IN_MidLevelAlarm;
    test2_SysIntegration_B.SysDiagMsgOut_c[0] = (uint8_T)
      (test2_SysIntegration_B.SysDiagMsgOut_c[0] > 0);
    test2_SysIntegration_B.SysDiagMsgOut_c[1] = 1U;
    test2_SysIntegration_B.SysDiagMsgOut_c[2] = (uint8_T)
      (test2_SysIntegration_B.SysDiagMsgOut_c[2] > 0);
    test2_SysIntegration_B.CommMsgOut.FMCode =
      test2_SysIntegration_DW.MidAlarmFMCode;
    qY = (int32_T)(test2_SysIntegration_B.CommMsgOut.MsgId + 1U);
    if ((uint32_T)qY > 255U) {
      qY = 255;
    }

    test2_SysIntegration_B.CommMsgOut.MsgId = (uint8_T)((uint8_T)qY %
      MAX_uint8_T);
    test2_SysIntegration_B.AlarmCtrlData.AlarmLevel = 2U;
    test2_SysIntegration_DW.AlarmCtrlEvtEventCounter++;
  } else if (test2_SysIntegration_DW.bitsForTID1.is_idle_g ==
             test2_SysInteg_IN_LowLevelAlarm) {
    if (!test2_SysIntegration_DW.bitsForTID1.LowAlarmEnable) {
      test2_SysIntegration_DW.AlarmCtrlEvtEventCounter++;
      test2_SysIntegration_B.CommMsgOut.AlarmSwitch = false;
      test2_SysIntegration_B.AlarmCtrlData.AlarmLevel = 0U;
      qY = test2_SysIntegration_B.SysDiagMsgOut_c[0];
      test2_SysIntegration_B.SysDiagMsgOut_c[0] = (uint8_T)qY;
      qY = test2_SysIntegration_B.SysDiagMsgOut_c[1];
      test2_SysIntegration_B.SysDiagMsgOut_c[1] = (uint8_T)qY;
      qY_tmp = test2_SysIntegration_B.SysDiagMsgOut_c[2] - /*MW:OvSatOk*/ 1U;
      if (qY_tmp > test2_SysIntegration_B.SysDiagMsgOut_c[2]) {
        qY_tmp = 0U;
      }

      test2_SysIntegration_B.SysDiagMsgOut_c[2] = (uint8_T)qY_tmp;
      test2_SysIntegration_DW.bitsForTID1.is_idle_g = 2;
      test2_SysIntegration_DW.bitsForTID1.was_idle_o = 2;
    }
  } else {
    if (test2_SysIntegration_DW.bitsForTID1.LowAlarmEnable) {
      test2_SysIntegration_B.CommMsgOut.AlarmSwitch = true;
      test2_SysIntegration_DW.bitsForTID1.is_idle_g =
        test2_SysInteg_IN_LowLevelAlarm;
      test2_SysIntegration_DW.bitsForTID1.was_idle_o =
        test2_SysInteg_IN_LowLevelAlarm;
      test2_SysIntegration_B.SysDiagMsgOut_c[0] = (uint8_T)
        (test2_SysIntegration_B.SysDiagMsgOut_c[0] > 0);
      test2_SysIntegration_B.SysDiagMsgOut_c[1] = (uint8_T)
        (test2_SysIntegration_B.SysDiagMsgOut_c[1] > 0);
      test2_SysIntegration_B.SysDiagMsgOut_c[2] = 1U;
      test2_SysIntegration_B.CommMsgOut.FMCode =
        test2_SysIntegration_DW.LowAlarmFMCode;
      qY = (int32_T)(test2_SysIntegration_B.CommMsgOut.MsgId + 1U);
      if ((uint32_T)qY > 255U) {
        qY = 255;
      }

      test2_SysIntegration_B.CommMsgOut.MsgId = (uint8_T)((uint8_T)qY %
        MAX_uint8_T);
      test2_SysIntegration_B.AlarmCtrlData.AlarmLevel = 1U;
      test2_SysIntegration_DW.AlarmCtrlEvtEventCounter++;
    }
  }
}

/* Function for Chart: '<S112>/Chart' */
static void test2_SysI_enter_atomic_TaskAct(void)
{
  test2_SysIntegration_DW.AlarmCtrlParam.MasterMode = true;
  test2_SysIntegration_DW.AlarmCtrlParam.LowLevelInd[0] = 201U;
  test2_SysIntegration_DW.AlarmCtrlParam.MidLevelInd[0] = 101U;
  test2_SysIntegration_DW.AlarmCtrlParam.HighLevelInd[0] = 1U;
  test2_SysIntegration_DW.AlarmCtrlParam.LowLevelInd[1] = MAX_uint8_T;
  test2_SysIntegration_DW.AlarmCtrlParam.MidLevelInd[1] = 199U;
  test2_SysIntegration_DW.AlarmCtrlParam.HighLevelInd[1] = 99U;
  test2_SysIntegration_B.CommMsgOut.MsgId = 0U;
  test2_SysIntegration_B.CommMsgOut.AlarmSwitch = false;
  test2_SysIntegration_B.CommMsgOut.FMCode = 0U;
  test2_SysIntegration_B.AlarmCtrlData.AlarmLevel = 0U;
  test2_SysIntegration_B.AlarmCtrlData.boolMaster = true;
  test2_SysIntegration_B.bitsForTID1.LowPowerMsgOut =
    ((test2_SysIntegration_DW.bitsForTID1.is_idle_g ==
      test2_SysInteg_IN_LowLevelAlarm) ||
     (test2_SysIntegration_DW.bitsForTID1.is_idle ==
      test2_SysInteg_IN_MidLevelAlarm) ||
     (test2_SysIntegration_DW.bitsForTID1.is_TaskAct ==
      test2_SysInte_IN_HighLevelAlarm));
  if (test2_SysIntegration_B.BusCreator.MsgId !=
      test2_SysIntegration_DW.prevSysDiagMsgId_e) {
    if ((test2_SysIntegration_DW.AlarmCtrlParam.LowLevelInd[0] <=
         test2_SysIntegration_B.BusCreator.FMCode) &&
        (test2_SysIntegration_B.BusCreator.FMCode <=
         test2_SysIntegration_DW.AlarmCtrlParam.LowLevelInd[1])) {
      test2_SysIntegration_DW.bitsForTID1.LowAlarmEnable =
        test2_SysIntegration_B.BusCreator.OpCode;
      test2_SysIntegration_DW.LowAlarmFMCode =
        test2_SysIntegration_B.BusCreator.FMCode;
    } else if ((test2_SysIntegration_DW.AlarmCtrlParam.MidLevelInd[0] <=
                test2_SysIntegration_B.BusCreator.FMCode) &&
               (test2_SysIntegration_B.BusCreator.FMCode <=
                test2_SysIntegration_DW.AlarmCtrlParam.MidLevelInd[1])) {
      test2_SysIntegration_DW.bitsForTID1.MidAlarmEnable =
        test2_SysIntegration_B.BusCreator.OpCode;
      test2_SysIntegration_DW.MidAlarmFMCode =
        test2_SysIntegration_B.BusCreator.FMCode;
    } else {
      if ((test2_SysIntegration_DW.AlarmCtrlParam.HighLevelInd[0] <=
           test2_SysIntegration_B.BusCreator.FMCode) &&
          (test2_SysIntegration_B.BusCreator.FMCode <=
           test2_SysIntegration_DW.AlarmCtrlParam.HighLevelInd[1])) {
        test2_SysIntegration_DW.bitsForTID1.HighAlarmEnable =
          test2_SysIntegration_B.BusCreator.OpCode;
        test2_SysIntegration_DW.HighAlarmFMCode =
          test2_SysIntegration_B.BusCreator.FMCode;
      }
    }

    test2_SysIntegration_DW.prevSysDiagMsgId_e =
      test2_SysIntegration_B.BusCreator.MsgId;
  }
}

/* Function for Chart: '<S112>/Chart' */
static void test2_Sy_enter_internal_TaskAct(void)
{
  test2_SysIntegration_DW.bitsForTID1.is_TaskAct = 2;
  test2_SysIn_enter_internal_idle();
}

/* Function for Chart: '<S2>/Chart' */
static void test2_SysIntegration_alarmIt(uint8_T x_alarmCtrlData_AlarmLevel,
  boolean_T x_alarmCtrlData_boolMaster)
{
  alarmIt(x_alarmCtrlData_AlarmLevel, x_alarmCtrlData_boolMaster);
}

/* Function for Chart: '<S32>/Chart' */
static void test2_SysIntegratio_sendBleData(uint8_T x_OutpData[224])
{
  sendBleData(x_OutpData);
}

/* Function for Chart: '<S30>/Chart' */
static boolean_T test2_SysInteg_ChkBleConnection(void)
{
  return chkBleConnection(true);
}

/* Function for Chart: '<S34>/Chart' */
static void test2_SysIntegration_GetBleData(uint8_T x_BleDataFrameId, boolean_T *
  y_DtRdy, uint8_T y_DataOut[224], uint8_T *y_BleDataFrameId)
{
  *y_BleDataFrameId = x_BleDataFrameId;
  *y_DtRdy = getBleData(y_DataOut);
  if (*y_DtRdy) {
    if (y_DataOut[1] != x_BleDataFrameId) {
      *y_BleDataFrameId = y_DataOut[1];
    } else {
      *y_DtRdy = false;
    }
  }
}

/* Function for Chart: '<S4>/Chart' */
static int32_T test2_SysIntegra_EncoderCntRead(boolean_T bool_Switch)
{
  return encoderRead(bool_Switch);
}

/* Function for Chart: '<S4>/Chart' */
static void chartstep_c45_test2_SysIntegrat(const int32_T *sfEvent_f)
{
  if (*sfEvent_f == test2_SysIntegration_event_Rst1) {
    test2_SysIntegration_B.rtEncRdOut = test2_SysIntegra_EncoderCntRead(false);
  }

  if (*sfEvent_f == test2_SysIntegration_event_Rst2) {
    test2_SysIntegration_B.rtEncRdOut = test2_SysIntegra_EncoderCntRead(false);
  }

  if (*sfEvent_f == test2_SysInteg_event_UpDateTick) {
    test2_SysIntegration_B.rtEncRdOut = test2_SysIntegra_EncoderCntRead(true);
  }
}

/* Function for Chart: '<S45>/Chart' */
static void test2_SysIntegration_LPCtrl(uint32_T x_SleepmSec, boolean_T
  *y_SwitchStatus, uint32_T *y_Comp_mSec)
{
  if (x_SleepmSec > 0U) {
    *y_SwitchStatus = lpCtrl(true, &x_SleepmSec);
    *y_Comp_mSec = 0U;
  } else {
    *y_SwitchStatus = lpCtrl(false, y_Comp_mSec);
  }
}

/* Function for Chart: '<S47>/Chart' */
static void test2_SysIntegration_IOCtrl(boolean_T x_SwitchCmd)
{
  ioCtrl(x_SwitchCmd);
}

/* Function for Chart: '<S92>/Chart' */
static uint16_T test2_Sys_BaseRateTimeInfoCrypt(const type_RT x_rtTime)
{
  uint32_T tmp;
  int32_T tmp_0;
  uint8_T x_rtTime_0;
  tmp = x_rtTime.Time[1] * 48 * 31U;
  if (tmp > 65535U) {
    tmp = 65535U;
  }

  tmp += x_rtTime.Time[2] * 48;
  if (tmp > 65535U) {
    tmp = 65535U;
  }

  if (x_rtTime.Time[3] > 63) {
    x_rtTime_0 = MAX_uint8_T;
  } else {
    x_rtTime_0 = (uint8_T)(x_rtTime.Time[3] << 2);
  }

  tmp_0 = (int32_T)(x_rtTime.Time[4] / 30U + x_rtTime_0);
  if ((uint32_T)tmp_0 > 255U) {
    tmp_0 = 255;
  }

  tmp_0++;
  if ((uint32_T)tmp_0 > 255U) {
    tmp_0 = 255;
  }

  tmp += tmp_0;
  if (tmp > 65535U) {
    tmp = 65535U;
  }

  return (uint16_T)tmp;
}

/* Function for Chart: '<S92>/Chart' */
static uint32_T test2_SysI_TimeTagUniqueIDSynth(const type_RT x_rtTime)
{
  return (((x_rtTime.Time[1] * 2678400U + x_rtTime.Time[2] * 86400U) +
           x_rtTime.Time[3] * 3600U) + x_rtTime.Time[4] * 60U) + x_rtTime.Time[5];
}

/* Function for Chart: '<S92>/Chart' */
static void chartstep_c21_test2_SysIntegrat(void)
{
  boolean_T boolNewDay;
  real32_T tmp;
  uint32_T qY;
  int32_T tmp_0;
  switch (test2_SysIntegration_DW.bitsForTID0.is_c21_test2_SysIntegration) {
   case test2_Sys_IN_DoseDynInfoMonitor:
    /* UnitDelay: '<S65>/Unit Delay' */
    boolNewDay = (test2_SysIntegration_B.VarSet.ActCtrl.DailyDoseStatVar.DayInfo
                  != test2_SysIntegration_DW.UnitDelay_DSTATE_j.Time[2]);
    switch (test2_SysIntegration_DW.bitsForTID0.is_DoseDynInfoMonitor) {
     case test2_SysIntegration_IN_Idle_k:
      if (test2_SysIntegration_DW.bitsForTID0.boolDoseMissionMsgArrived) {
        test2_SysIntegration_DW.bitsForTID0.boolDoseMissionMsgArrived = false;
        test2_SysIntegration_DW.bitsForTID0.is_DoseDynInfoMonitor =
          test2_SysIntegration_IN_Op_h;
        test2_SysIntegration_DW.prevMotionStopACKMsgId =
          test2_SysIntegration_B.MotionStopACKMsg.Head.MsgId;
        test2_SysIntegration_DW.prevDoseDynMsgId =
          test2_SysIntegration_B.DoseActionResultMsg.Head.MsgId;
        test2_SysIntegration_DW.bitsForTID0.boolKeepUpdate =
          (test2_SysIntegration_DW.temp_OpCode_l >= 200);
        test2_SysIntegration_DW.prevMasterDynEnc = 0U;
      } else {
        if (test2_SysIntegration_DW.prevDoseMissionMsgId !=
            test2_SysIntegration_B.DoseMissionMsg.Head.MsgId) {
          test2_SysIntegration_DW.prevDoseMissionMsgId =
            test2_SysIntegration_B.DoseMissionMsg.Head.MsgId;
          test2_SysIntegration_DW.temp_OpCode_l =
            test2_SysIntegration_B.DoseMissionMsg.Head.OpCode;
          test2_SysIntegration_DW.bitsForTID0.boolDoseMissionMsgArrived = true;
        }
      }
      break;

     case test2_SysIntegration_IN_Op_h:
      if (test2_SysIntegration_DW.prevMotionStopACKMsgId !=
          test2_SysIntegration_B.MotionStopACKMsg.Head.MsgId) {
        test2_SysIntegration_DW.prevMotionStopACKMsgId =
          test2_SysIntegration_B.MotionStopACKMsg.Head.MsgId;
        test2_SysIntegration_DW.bitsForTID0.is_DoseDynInfoMonitor =
          test2_SysIntegration_IN_OpEnd;
        test2_SysIntegration_DW.bitsForTID0.is_OpEnd =
          IN_Wait4SlaveEncCntSynchronizat;
      } else {
        if (test2_SysIntegration_DW.bitsForTID0.boolKeepUpdate) {
          tmp_0 = (int32_T)(test2_SysIntegration_B.DynDoseInfoMsg.Head.MsgId +
                            1U);
          if ((uint32_T)tmp_0 > 255U) {
            tmp_0 = 255;
          }

          test2_SysIntegration_B.DynDoseInfoMsg.Head.MsgId = (uint8_T)((uint8_T)
            tmp_0 % MAX_uint8_T);
          test2_SysIntegration_B.DynDoseInfoMsg.Body.TimeInfo =
            test2_SysIntegration_B.VarSet.DoseCtrl.LargeDoseConfig.EffectiveDay;

          /* UnitDelay: '<S4>/Unit Delay' */
          tmp_0 = test2_SysIntegration_DW.UnitDelay_DSTATE_i;
          if (tmp_0 < 0) {
            tmp_0 = 0;
          }

          qY = tmp_0 - /*MW:OvSatOk*/ test2_SysIntegration_DW.prevMasterDynEnc;
          if (qY > (uint32_T)tmp_0) {
            qY = 0U;
          }

          test2_SysIntegration_B.DynDoseInfoMsg.Body.CompleteDose = qY;

          /* UnitDelay: '<S65>/Unit Delay' */
          test2_SysIntegration_B.DynDoseInfoMsg.Body.TargetDose =
            test2_SysI_TimeTagUniqueIDSynth
            (test2_SysIntegration_DW.UnitDelay_DSTATE_j);

          /* UnitDelay: '<S4>/Unit Delay' */
          tmp_0 = test2_SysIntegration_DW.UnitDelay_DSTATE_i;
          if (tmp_0 < 0) {
            tmp_0 = 0;
          }

          test2_SysIntegration_DW.prevMasterDynEnc = (uint32_T)tmp_0;
          tmp_0 = (int32_T)(test2_SysIntegration_B.DailyStatMsg.Head.MsgId + 1U);
          if ((uint32_T)tmp_0 > 255U) {
            tmp_0 = 255;
          }

          test2_SysIntegration_B.DailyStatMsg.Head.MsgId = (uint8_T)((uint8_T)
            tmp_0 % MAX_uint8_T);
          test2_SysIntegration_B.DailyStatMsg.Head.OpCode =
            test2_SysIntegration_DW.temp_OpCode_l;
          test2_SysIntegration_B.DailyStatMsg.Body.DailyAmountAcc = 0U;

          /* UnitDelay: '<S4>/Unit Delay' */
          tmp = roundf((real32_T)test2_SysIntegration_DW.UnitDelay_DSTATE_i /
                       test2_SysIntegration_B.Enc2DoseGain);
          if (tmp < 4.2949673E+9F) {
            if (tmp >= 0.0F) {
              test2_SysIntegration_B.DailyStatMsg.Body.LargeAmountAcc =
                (uint32_T)tmp;
            } else {
              test2_SysIntegration_B.DailyStatMsg.Body.LargeAmountAcc = 0U;
            }
          } else {
            test2_SysIntegration_B.DailyStatMsg.Body.LargeAmountAcc =
              MAX_uint32_T;
          }

          qY = test2_SysIntegration_B.DailyStatMsg.Body.DailyAmountAcc +
            /*MW:OvSatOk*/
            test2_SysIntegration_B.DailyStatMsg.Body.LargeAmountAcc;
          if (qY < test2_SysIntegration_B.DailyStatMsg.Body.DailyAmountAcc) {
            qY = MAX_uint32_T;
          }

          test2_SysIntegration_B.DailyStatMsg.Body.TotalAmountAcc = qY;
          test2_SysIntegration_B.DailyStatMsg.Body.ResidueDoseEst =
            test2_SysIntegration_B.DailyStatMsg.Body.TotalAmountAcc;
          if (boolNewDay) {
            test2_SysIntegration_B.DailyStatMsg.Head.OpCode = 3U;

            /* UnitDelay: '<S65>/Unit Delay' */
            test2_SysIntegration_B.DailyStatMsg.Body.DayInfo =
              test2_SysIntegration_DW.UnitDelay_DSTATE_j.Time[2];
          }
        }
      }
      break;

     default:
      if (test2_SysIntegration_DW.bitsForTID0.is_OpEnd ==
          test2_SysIntegrati_IN_EndAction) {
        test2_SysIntegration_DW.bitsForTID0.is_OpEnd = 0;
        test2_SysIntegration_DW.bitsForTID0.is_DoseDynInfoMonitor =
          test2_SysIntegration_IN_Idle_k;
        test2_SysIntegration_DW.prevDoseMissionMsgId =
          test2_SysIntegration_B.DoseMissionMsg.Head.MsgId;
      } else {
        switch (test2_SysIntegration_DW.bitsForTID0.is_OpEnd) {
         case test2_SysIntegrati_IN_EndAction:
          break;

         default:
          if (test2_SysIntegration_DW.prevDoseDynMsgId !=
              test2_SysIntegration_B.DoseActionResultMsg.Head.MsgId) {
            test2_SysIntegration_DW.prevDoseDynMsgId =
              test2_SysIntegration_B.DoseActionResultMsg.Head.MsgId;
            test2_SysIntegration_DW.bitsForTID0.is_OpEnd =
              test2_SysIntegrati_IN_EndAction;
            tmp_0 = (int32_T)(test2_SysIntegration_B.DynDoseInfoMsg.Head.MsgId +
                              1U);
            if ((uint32_T)tmp_0 > 255U) {
              tmp_0 = 255;
            }

            test2_SysIntegration_B.DynDoseInfoMsg.Head.MsgId = (uint8_T)
              ((uint8_T)tmp_0 % MAX_uint8_T);
            if (test2_SysIntegration_DW.bitsForTID0.boolKeepUpdate) {
              test2_SysIntegration_B.DynDoseInfoMsg.Body.TimeInfo =
                test2_SysIntegration_B.VarSet.DoseCtrl.LargeDoseConfig.EffectiveDay;
            } else {
              /* UnitDelay: '<S65>/Unit Delay' */
              test2_SysIntegration_B.DynDoseInfoMsg.Body.TimeInfo =
                test2_Sys_BaseRateTimeInfoCrypt
                (test2_SysIntegration_DW.UnitDelay_DSTATE_j);
            }

            qY = test2_SysIntegration_B.DoseActionResultMsg.Body.Data -
              /*MW:OvSatOk*/ test2_SysIntegration_DW.prevMasterDynEnc;
            if (qY > test2_SysIntegration_B.DoseActionResultMsg.Body.Data) {
              qY = 0U;
            }

            test2_SysIntegration_B.DynDoseInfoMsg.Body.CompleteDose = qY;

            /* UnitDelay: '<S65>/Unit Delay' */
            test2_SysIntegration_B.DynDoseInfoMsg.Body.TargetDose =
              test2_SysI_TimeTagUniqueIDSynth
              (test2_SysIntegration_DW.UnitDelay_DSTATE_j);
            tmp_0 = (int32_T)(test2_SysIntegration_B.DailyStatMsg.Head.MsgId +
                              1U);
            if ((uint32_T)tmp_0 > 255U) {
              tmp_0 = 255;
            }

            test2_SysIntegration_B.DailyStatMsg.Head.MsgId = (uint8_T)((uint8_T)
              tmp_0 % MAX_uint8_T);
            test2_SysIntegration_B.DailyStatMsg.Head.OpCode =
              test2_SysIntegration_DW.temp_OpCode_l;
            tmp = roundf((real32_T)
                         (test2_SysIntegration_B.DynDoseInfoMsg.Body.CompleteDose
                          * !test2_SysIntegration_DW.bitsForTID0.boolKeepUpdate)
                         / test2_SysIntegration_B.Enc2DoseGain);
            if (tmp < 4.2949673E+9F) {
              if (tmp >= 0.0F) {
                test2_SysIntegration_B.DailyStatMsg.Body.DailyAmountAcc =
                  (uint32_T)tmp;
              } else {
                test2_SysIntegration_B.DailyStatMsg.Body.DailyAmountAcc = 0U;
              }
            } else {
              test2_SysIntegration_B.DailyStatMsg.Body.DailyAmountAcc =
                MAX_uint32_T;
            }

            tmp = roundf((real32_T)
                         (test2_SysIntegration_B.DynDoseInfoMsg.Body.CompleteDose
                          * test2_SysIntegration_DW.bitsForTID0.boolKeepUpdate) /
                         test2_SysIntegration_B.Enc2DoseGain);
            if (tmp < 4.2949673E+9F) {
              if (tmp >= 0.0F) {
                test2_SysIntegration_B.DailyStatMsg.Body.LargeAmountAcc =
                  (uint32_T)tmp;
              } else {
                test2_SysIntegration_B.DailyStatMsg.Body.LargeAmountAcc = 0U;
              }
            } else {
              test2_SysIntegration_B.DailyStatMsg.Body.LargeAmountAcc =
                MAX_uint32_T;
            }

            qY = test2_SysIntegration_B.DailyStatMsg.Body.DailyAmountAcc +
              /*MW:OvSatOk*/
              test2_SysIntegration_B.DailyStatMsg.Body.LargeAmountAcc;
            if (qY < test2_SysIntegration_B.DailyStatMsg.Body.DailyAmountAcc) {
              qY = MAX_uint32_T;
            }

            test2_SysIntegration_B.DailyStatMsg.Body.TotalAmountAcc = qY;
            test2_SysIntegration_B.DailyStatMsg.Body.ResidueDoseEst =
              test2_SysIntegration_B.DailyStatMsg.Body.TotalAmountAcc;
            if (boolNewDay) {
              test2_SysIntegration_B.DailyStatMsg.Head.OpCode = 3U;

              /* UnitDelay: '<S65>/Unit Delay' */
              test2_SysIntegration_B.DailyStatMsg.Body.DayInfo =
                test2_SysIntegration_DW.UnitDelay_DSTATE_j.Time[2];
            }
          }
          break;
        }
      }
      break;
    }
    break;

   case test2_SysIntegration_IN_Init1:
    test2_SysIntegration_DW.bitsForTID0.prevStartUpMsgId =
      test2_SysIntegration_B.bitsForTID4.FlashInitFinishEvt;
    test2_SysIntegration_DW.bitsForTID0.is_c21_test2_SysIntegration =
      test2_SysIntegration_IN_Init2;
    break;

   default:
    if (test2_SysIntegration_DW.bitsForTID0.prevStartUpMsgId !=
        test2_SysIntegration_B.bitsForTID4.FlashInitFinishEvt) {
      test2_SysIntegration_DW.bitsForTID0.prevStartUpMsgId =
        test2_SysIntegration_B.bitsForTID4.FlashInitFinishEvt;
      test2_SysIntegration_DW.bitsForTID0.is_c21_test2_SysIntegration =
        test2_Sys_IN_DoseDynInfoMonitor;
      test2_SysIntegration_DW.bitsForTID0.is_DoseDynInfoMonitor =
        test2_SysIntegration_IN_Idle_k;
      test2_SysIntegration_DW.prevDoseMissionMsgId =
        test2_SysIntegration_B.DoseMissionMsg.Head.MsgId;
    }
    break;
  }
}

/* Function for Chart: '<S113>/Actuator' */
static boolean_T test2_SysIntegr_detectPopAction(const uint8_T
  x_boolAlarmLoadedEmpty[3], const uint8_T x_boolAlarmOccuredEmpty[3])
{
  boolean_T y_boolPop;
  uint8_T i;
  int32_T tmp;
  boolean_T exitg1;
  y_boolPop = false;
  i = 0U;
  exitg1 = false;
  while ((!exitg1) && (i < 3)) {
    i++;
    tmp = i - 1;
    if (x_boolAlarmOccuredEmpty[tmp] < x_boolAlarmLoadedEmpty[tmp]) {
      y_boolPop = true;
    }

    if (y_boolPop) {
      exitg1 = true;
    }
  }

  return y_boolPop;
}

/* Function for Chart: '<S114>/Chart' */
static void chartstep_c37_test2_SysIntegrat(const int32_T *sfEvent_k)
{
  int32_T tmp;
  if (*sfEvent_k == test2_SysIn_event_StartTimerEvt) {
    tmp = (int32_T)(test2_SysIntegration_B.TimerCtrlMsg.Head.MsgId + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    test2_SysIntegration_B.TimerCtrlMsg.Head.MsgId = (uint8_T)((uint8_T)tmp %
      MAX_uint8_T);
    test2_SysIntegration_B.TimerCtrlMsg.Head.OpCode = 0U;
  }

  if (*sfEvent_k == test2_SysInt_event_StopTimerEvt) {
    tmp = (int32_T)(test2_SysIntegration_B.TimerCtrlMsg.Head.MsgId + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    test2_SysIntegration_B.TimerCtrlMsg.Head.MsgId = (uint8_T)((uint8_T)tmp %
      MAX_uint8_T);
    test2_SysIntegration_B.TimerCtrlMsg.Head.OpCode = 1U;
  }
}

/* Function for Chart: '<S122>/Chart' */
static boolean_T test2_SysInteg_ReadChipCallback(type_RecordCtrl2RTCtrlMsg
  *x_RTMsgOut)
{
  boolean_T y_boolChipErrStatus;
  int32_T tmp;
  y_boolChipErrStatus = readRTChip(x_RTMsgOut->Body.Time);
  tmp = (int32_T)(x_RTMsgOut->Head.MsgId + 1U);
  if ((uint32_T)tmp > 255U) {
    tmp = 255;
  }

  x_RTMsgOut->Head.MsgId = (uint8_T)((uint8_T)tmp % MAX_uint8_T);
  return y_boolChipErrStatus;
}

/* Function for Chart: '<S122>/Chart' */
static boolean_T test2_SysInte_WriteChipCallback(type_RecordCtrl2RTCtrlMsg
  x_RTMsgIn, type_RecordCtrl2RTCtrlMsg *x_RTMsgOut)
{
  boolean_T y_boolChipErrStatus;
  int32_T tmp;
  y_boolChipErrStatus = writeRTChip(x_RTMsgIn.Body.Time);
  tmp = (int32_T)(x_RTMsgOut->Head.MsgId + 1U);
  if ((uint32_T)tmp > 255U) {
    tmp = 255;
  }

  x_RTMsgOut->Head.MsgId = (uint8_T)((uint8_T)tmp % MAX_uint8_T);
  return y_boolChipErrStatus;
}

/* Function for Chart: '<S122>/Chart' */
static void chartstep_c1_test2_SysIntegrati(const int32_T *sfEvent)
{
  if (*sfEvent == test2_SysInte_event_InitChipEvt) {
    test2_SysIntegration_B.bitsForTID7.boolChipErrStatus =
      test2_SysInteg_ReadChipCallback(&test2_SysIntegration_B.RTMsgOut);
  }

  if (*sfEvent == test2_SysIntegr_event_WriteChip) {
    test2_SysIntegration_B.bitsForTID7.boolChipErrStatus =
      test2_SysInte_WriteChipCallback(test2_SysIntegration_B.RTTimerSetMsgOut,
      &test2_SysIntegration_B.RTMsgOut);
  }
}

/* Function for Chart: '<S34>/Chart' */
static void enter_internal_c9_test2_SysInte(void)
{
  type_MsgBody4BleDriveMsg b;

  /* Chart: '<S34>/Chart' */
  test2_SysIntegration_B.BleMsgOut.Head.MsgId = 0U;
  test2_SysIntegration_B.BleMsgOut.Head.OpCode = 0U;
  memset(&b.Data[0], 0, 224U * sizeof(uint8_T));
  test2_SysIntegration_B.BleMsgOut.Body = b;
}

/* Model step function */
void test2_SysIntegration_step(void)
{
  boolean_T IOStatus[8];
  type_MsgBody4FlashAccessMsg d;
  type_MsgBody4FlashAccessMsg b;
  uint8_T LogAvailableFlag;
  uint8_T LogData[44];
  type_RT d_0;
  uint16_T SubLargeDose;
  uint16_T temp_LargeDose;
  boolean_T d_tf;
  boolean_T f_tf;
  boolean_T g_tf;
  boolean_T h_tf;
  uint8_T currMsgInIdVector[8];
  uint8_T DataOut[224];
  type_MsgBody4FlashAccessMsg b_0;
  real32_T denAccum;
  type_MsgBody4GP1Byte rtb_Body_n;
  uint8_T rtb_BusConversion_InsertedFor_0;
  uint8_T rtb_BusConversion_InsertedFor_1;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_HiddenBuf_InsertedFor_Motor[5];
  boolean_T zcEvent[5];
  int8_T rtb_inputevents_at[5];
  boolean_T rtb_PopAlarmEvt;
  boolean_T rtb_UnitDelay_p;
  boolean_T rtb_UnitDelay1_j;
  boolean_T rtb_UnitDelay2_k;
  int32_T sfEvent_h;
  uint32_T elapsedTicks_d;
  type_CommCtrlRecordInqResponseMsg expl_temp;
  int32_T i;
  uint8_T tmp[3];
  uint8_T tmp_0[24];
  uint16_T a[4];
  uint8_T tmp_1[3];
  uint8_T tmp_2[48];
  uint8_T tmp_3[6];
  uint8_T tmp_4[32];
  uint8_T tmp_5[132];
  boolean_T zcEvent_idx_1;
  boolean_T zcEvent_idx_0;
  boolean_T rtb_HiddenBuf_InsertedFor_Cha_0;
  uint32_T tmp_6;
  uint16_T tmp_7;
  uint8_T tmp_8;
  boolean_T guard1 = false;
  boolean_T exitg1;
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[1] == 0) {
    /* UnitDelay: '<S29>/Unit Delay3' */
    test2_SysIntegration_B.UnitDelay3_d =
      test2_SysIntegration_DW.UnitDelay3_DSTATE_a;
  }

  /* UnitDelay: '<S126>/Unit Delay' */
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    if (test2_SysIntegration_M->Timing.TaskCounters.TID[7] == 0) {
      test2_SysIntegration_B.UnitDelay_m =
        test2_SysIntegration_DW.UnitDelay_DSTATE_o5;
    }

    /* Chart: '<S29>/Chart' incorporates:
     *  Constant: '<S29>/CommCtrlParam'
     *  UnitDelay: '<S29>/Unit Delay1'
     *  UnitDelay: '<S29>/Unit Delay2'
     *  UnitDelay: '<S29>/Unit Delay4'
     */
    if (test2_SysIntegration_DW.temporalCounter_i1_po < MAX_uint32_T) {
      test2_SysIntegration_DW.temporalCounter_i1_po++;
    }

    if (test2_SysIntegration_DW.bitsForTID4.is_active_c8_test2_SysIntegrati ==
        0U) {
      test2_SysIntegration_DW.bitsForTID4.is_active_c8_test2_SysIntegrati = 1;
      test2_SysIntegration_DW.bitsForTID4.is_c8_test2_SysIntegration =
        test2_SysIntegration_IN_Disable;
      test2_SysIntegration_B.DoseCtrlMsgOut =
        test2_SysIntegration_ConstP.CommCtrlParam_Value.DoseCtrlMsg_IniVal;
      test2_SysIntegration_B.ActCtrlMsgOut =
        test2_SysIntegration_ConstP.CommCtrlParam_Value.ActCtrlMsg_IniVal;
      test2_SysIntegration_B.AlarmCtrlMsgOut =
        test2_SysIntegration_ConstP.CommCtrlParam_Value.AlarmCtrlMsg_IniVal;
      test2_SysIntegration_B.FirmwareMsgOut =
        test2_SysIntegration_ConstP.CommCtrlParam_Value.FirmwareMsg_IniVal;
      test2_SysIntegration_B.SysSettingMsgOut =
        test2_SysIntegration_ConstP.CommCtrlParam_Value.SysSettingMsg_IniVal;
      test2_SysIntegration_B.RecordInqMsgOut =
        test2_SysIntegration_ConstP.CommCtrlParam_Value.RecordInqMsg_IniVal;
      test2_SysIntegration_B.CalibraMsgOut =
        test2_SysIntegration_ConstP.CommCtrlParam_Value.CalibraMsg_IniVal;
      test2_SysIntegration_B.FCTestMsgOut =
        test2_SysIntegration_ConstP.CommCtrlParam_Value.FCTestMsg_IniVal;
      test2_SysIntegration_DW.SwitchOnVector[0] = 0U;
      test2_SysIntegration_DW.prevCommUpMsgIdVector[0] = 0U;
      test2_SysIntegration_DW.SwitchOnVector[1] = 0U;
      test2_SysIntegration_DW.prevCommUpMsgIdVector[1] = 0U;
      test2_SysIntegration_DW.SwitchOnVector[2] = 0U;
      test2_SysIntegration_DW.prevCommUpMsgIdVector[2] = 0U;
    } else if (test2_SysIntegration_DW.bitsForTID4.is_c8_test2_SysIntegration ==
               test2_SysIntegration_IN_Disable) {
      if (test2_SysIntegration_B.UnitDelay_m) {
        test2_SysIntegration_DW.bitsForTID4.is_c8_test2_SysIntegration =
          test2_SysIntegration_IN_Enable;
        test2_SysIntegration_DW.bitsForTID4.is_Enable =
          test2_SysIntegration_IN_Recv;
        test2_SysIntegration_DW.temporalCounter_i1_po = 0U;
        test2_SysIntegration_DW.prevBleInMsgId =
          test2_SysIntegration_DW.UnitDelay1_DSTATE_e.Head.MsgId;
        test2_SysIntegration_DW.getBleDataEvtEventCounter++;
      }
    } else if (test2_SysIntegration_DW.bitsForTID4.is_Enable ==
               test2_SysIntegration_IN_Recv) {
      if (test2_SysIntegration_DW.temporalCounter_i1_po * 100U >= 255U) {
        test2_SysIntegration_DW.bitsForTID4.is_Enable =
          test2_SysIntegration_IN_Send;
        test2_SysIntegration_DW.temporalCounter_i1_po = 0U;
        tmp_1[0] = test2_SysIntegration_DW.prevCommUpMsgIdVector[0];
        tmp_1[1] = test2_SysIntegration_DW.prevCommUpMsgIdVector[1];
        tmp_1[2] = test2_SysIntegration_DW.prevCommUpMsgIdVector[2];
        test_ChkCommUpMsgIdVectorChange(tmp_1,
          test2_SysIntegration_DW.UnitDelay4_DSTATE.Head.MsgId,
          test2_SysIntegration_B.UnitDelay3_d.Head.MsgId,
          test2_SysIntegration_DW.UnitDelay2_DSTATE_p.Head.MsgId,
          test2_SysIntegration_DW.SwitchOnVector,
          test2_SysIntegration_DW.prevCommUpMsgIdVector);
        test2_SysIntegration_DW.sendChannel = 0U;
        memset(&test2_SysIntegration_B.BleMsgOut_c[0], 0, 224U * sizeof(uint8_T));
      } else {
        if (test2_SysIntegration_DW.prevBleInMsgId !=
            test2_SysIntegration_DW.UnitDelay1_DSTATE_e.Head.MsgId) {
          test2_SysIntegration_DW.prevBleInMsgId =
            test2_SysIntegration_DW.UnitDelay1_DSTATE_e.Head.MsgId;
          for (i = 0; i < 48; i++) {
            tmp_2[i] = test2_SysIntegration_B.DoseCtrlMsgOut.Body.Data[i];
          }

          for (i = 0; i < 6; i++) {
            tmp_3[i] = test2_SysIntegration_B.ActCtrlMsgOut.Body.Data[i];
          }

          for (i = 0; i < 32; i++) {
            tmp_4[i] = test2_SysIntegration_B.AlarmCtrlMsgOut.Body.Data[i];
          }

          memcpy(&tmp_5[0], &test2_SysIntegration_B.FirmwareMsgOut.Body.Data[0],
                 132U * sizeof(uint8_T));
          test2_SysIntegrat_ReformBleData
            (test2_SysIntegration_DW.UnitDelay1_DSTATE_e.Body.Data,
             test2_SysIntegration_B.DoseCtrlMsgOut.Head.MsgId,
             test2_SysIntegration_B.DoseCtrlMsgOut.Head.OpCode, tmp_2,
             test2_SysIntegration_B.ActCtrlMsgOut.Head.MsgId,
             test2_SysIntegration_B.ActCtrlMsgOut.Head.OpCode, tmp_3,
             test2_SysIntegration_B.AlarmCtrlMsgOut.Head.MsgId,
             test2_SysIntegration_B.AlarmCtrlMsgOut.Head.OpCode, tmp_4,
             test2_SysIntegration_B.FirmwareMsgOut.Head.MsgId,
             test2_SysIntegration_B.FirmwareMsgOut.Head.OpCode, tmp_5,
             test2_SysIntegration_B.SysSettingMsgOut.Head.MsgId,
             test2_SysIntegration_B.SysSettingMsgOut.Head.OpCode,
             test2_SysIntegration_B.SysSettingMsgOut.Body.Data,
             test2_SysIntegration_B.RecordInqMsgOut.Head,
             test2_SysIntegration_B.RecordInqMsgOut.Body,
             test2_SysIntegration_B.CalibraMsgOut.Head,
             test2_SysIntegration_B.CalibraMsgOut.Body,
             test2_SysIntegration_B.FCTestMsgOut,
             &test2_SysIntegration_B.DoseCtrlMsgOut,
             &test2_SysIntegration_B.ActCtrlMsgOut,
             &test2_SysIntegration_B.AlarmCtrlMsgOut,
             &test2_SysIntegration_B.FirmwareMsgOut,
             &test2_SysIntegration_B.SysSettingMsgOut,
             &test2_SysIntegration_B.RecordInqMsgOut,
             &test2_SysIntegration_B.CalibraMsgOut,
             &test2_SysIntegration_B.FCTestMsgOut);
        }
      }
    } else {
      zcEvent_idx_1 = false;
      zcEvent_idx_0 = true;
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 3)) {
        if (!(test2_SysIntegration_DW.SwitchOnVector[i] == 0)) {
          zcEvent_idx_0 = false;
          exitg1 = true;
        } else {
          i++;
        }
      }

      if (zcEvent_idx_0) {
        zcEvent_idx_1 = true;
      }

      if (zcEvent_idx_1 || (test2_SysIntegration_DW.temporalCounter_i1_po * 100U
                            >= 255U)) {
        test2_SysIntegration_DW.bitsForTID4.is_Enable =
          test2_SysIntegration_IN_Recv;
        test2_SysIntegration_DW.temporalCounter_i1_po = 0U;
        test2_SysIntegration_DW.prevBleInMsgId =
          test2_SysIntegration_DW.UnitDelay1_DSTATE_e.Head.MsgId;
        test2_SysIntegration_DW.getBleDataEvtEventCounter++;
      } else {
        i = (int32_T)(test2_SysIntegration_DW.sendChannel + 1U);
        sfEvent_h = i;
        if ((uint32_T)i > 255U) {
          sfEvent_h = 255;
        }

        if (test2_SysIntegration_DW.SwitchOnVector[sfEvent_h - 1] == 1) {
          sfEvent_h = i;
          if ((uint32_T)i > 255U) {
            sfEvent_h = 255;
          }

          test2_SysIntegration_DW.SwitchOnVector[sfEvent_h - 1] = 0U;
          expl_temp = test2_SysIntegration_DW.UnitDelay4_DSTATE;
          sfEvent_h = i;
          if ((uint32_T)i > 255U) {
            sfEvent_h = 255;
          }

          test2_SysIntegrat_BleMsgSendSyn((uint8_T)sfEvent_h,
            expl_temp.Body.MajorId, expl_temp.Body.MinorId, expl_temp.Body.Data,
            test2_SysIntegration_B.UnitDelay3_d.Head.OpCode,
            test2_SysIntegration_B.UnitDelay3_d.Body.Data,
            test2_SysIntegration_DW.UnitDelay2_DSTATE_p.Head.OpCode,
            test2_SysIntegration_DW.UnitDelay2_DSTATE_p.Body.Data,
            test2_SysIntegration_DW.BleOutMsgId, &LogAvailableFlag,
            test2_SysIntegration_B.BleMsgOut_c);
          test2_SysIntegration_DW.BleOutMsgId = LogAvailableFlag;
          test2_SysIntegration_DW.sendBleDataEvtEventCounter++;
        }

        if ((uint32_T)i > 255U) {
          i = 255;
        }

        test2_SysIntegration_DW.sendChannel = (uint8_T)((uint8_T)i % 3);
      }
    }

    if (test2_SysIntegration_DW.getBleDataEvtEventCounter > 0U) {
      test2_SysIntegration_B.bitsForTID4.getBleDataEvt =
        !test2_SysIntegration_B.bitsForTID4.getBleDataEvt;
      test2_SysIntegration_DW.getBleDataEvtEventCounter--;
    }

    if (test2_SysIntegration_DW.sendBleDataEvtEventCounter > 0U) {
      test2_SysIntegration_B.bitsForTID4.sendBleDataEvt =
        !test2_SysIntegration_B.bitsForTID4.sendBleDataEvt;
      test2_SysIntegration_DW.sendBleDataEvtEventCounter--;
    }

    /* End of Chart: '<S29>/Chart' */
  }

  /* End of UnitDelay: '<S126>/Unit Delay' */
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[5] == 0) {
    /* UnitDelay: '<S65>/Unit Delay3' */
    test2_SysIntegration_B.UnitDelay3 =
      test2_SysIntegration_DW.UnitDelay3_DSTATE;
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[7] == 0) {
    /* UnitDelay: '<S65>/Unit Delay' */
    test2_SysIntegration_B.UnitDelay_a =
      test2_SysIntegration_DW.UnitDelay_DSTATE_j;
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    /* Chart: '<S65>/Chart' incorporates:
     *  Constant: '<S65>/Constant'
     */
    if (test2_SysIntegration_DW.temporalCounter_i1_g < MAX_uint32_T) {
      test2_SysIntegration_DW.temporalCounter_i1_g++;
    }

    if (test2_SysIntegration_DW.temporalCounter_i2_c < MAX_uint32_T) {
      test2_SysIntegration_DW.temporalCounter_i2_c++;
    }

    if (test2_SysIntegration_DW.temporalCounter_i3 < MAX_uint32_T) {
      test2_SysIntegration_DW.temporalCounter_i3++;
    }

    test2_SysIntegration_DW.sfEvent_o = -1;
    if (test2_SysIntegration_DW.bitsForTID4.is_active_c22_test2_SysIntegrat ==
        0U) {
      test2_SysIntegration_DW.bitsForTID4.is_active_c22_test2_SysIntegrat = 1;
      if (test2_SysIntegration_DW.bitsForTID4.is_c22_test2_SysIntegration !=
          test2_SysInte_IN_Initialization) {
        test2_SysIntegration_DW.bitsForTID4.is_c22_test2_SysIntegration =
          test2_SysInte_IN_Initialization;
        test2_SysIntegration_DW.temporalCounter_i1_g = 0U;
        test2_SysIntegration_B.CommVarLogMsgOut =
          test2_SysIntegration_ConstP.Constant_Value.RecordInqResponseMsg_IniVal;
        test2_SysIntegration_B.RTTimeMsgOut =
          test2_SysIntegration_ConstP.Constant_Value.RTCtrlMsg_IniVal;
        test2_SysIntegration_B.drvFlashAccessMsgOut =
          test2_SysIntegration_ConstP.Constant_Value.drvFlashAccessMsg_IniVal;
        test2_SysIntegration_B.SysDiagMsgOut =
          test2_SysIntegration_ConstP.Constant_Value.SysDiagMsg_IniVal;
        test2_SysIntegration_B.bitsForTID4.WorkStatus = false;
        for (i = 0; i < 12; i++) {
          test2_SysIntegration_DW.prevInpMsgIdVector[i] = 0U;
          test2_SysIntegration_DW.SwitchOnVector_k[i] =
            (test2_SysIntegration_DW.prevInpMsgIdVector[i] != 0);
        }

        test2_SysIntegration_B.RelativeTimerApplyMsg.Head =
          test2_SysIntegration_ConstP.Constant_Value.SysDiagMsg_IniVal.Head;
        test2_SysIntegration_B.RelativeTimerApplyMsg.Body =
          test2_SysIntegration_ConstP.Constant_Value.SysDiagMsg_IniVal.Body;
      }
    } else {
      switch (test2_SysIntegration_DW.bitsForTID4.is_c22_test2_SysIntegration) {
       case test2_SysInte_IN_Initialization:
        if (test2_SysIntegration_DW.temporalCounter_i1_g >= 30U) {
          test2_SysIntegration_DW.bitsForTID4.is_c22_test2_SysIntegration =
            test2_SysIntegr_IN_MsgInProcess;
          test2_SysIntegration_DW.bitsForTID4.is_active_GeneralDeliveryStateM =
            1;
          if (test2_SysIntegration_DW.bitsForTID4.is_GeneralDeliveryStateManageme
              != test2_SysI_IN_DeliverySwitchOff) {
            test2_SysIntegration_DW.bitsForTID4.is_GeneralDeliveryStateManageme =
              test2_SysI_IN_DeliverySwitchOff;
            test2_SysIntegration_B.bitsForTID4.boolNormalDeliverySwitchOn =
              false;
            test2_SysIntegration_B.bitsForTID4.boolAirExpelSwitchOn = false;
            test2_SysIntegration_B.bitsForTID4.boolHomingOn = false;
          }

          if (test2_SysIntegration_DW.bitsForTID4.is_active_TempBaseRateAndLargeD
              != 1U) {
            test2_SysIntegration_DW.bitsForTID4.is_active_TempBaseRateAndLargeD =
              1;
          }

          if (test2_SysIntegration_DW.bitsForTID4.is_active_ThreeTypeDoseDelivery
              != 1U) {
            test2_SysIntegration_DW.bitsForTID4.is_active_ThreeTypeDoseDelivery =
              1;
          }

          if (test2_SysIntegration_DW.bitsForTID4.is_ThreeTypeDoseDeliveryPlanMan
              != test2_SysInt_IN_NoLargeDoseTask) {
            test2_SysIntegration_DW.bitsForTID4.is_ThreeTypeDoseDeliveryPlanMan =
              test2_SysInt_IN_NoLargeDoseTask;
            test2_SysIntegration_DW.bitsForTID4.boolLargeDoseMonitorEnable =
              false;
            i = (int32_T)
              (test2_SysIntegration_B.RelativeTimerApplyMsg.Head.MsgId + 1U);
            if ((uint32_T)i > 255U) {
              i = 255;
            }

            test2_SysIntegration_B.RelativeTimerApplyMsg.Head.MsgId = (uint8_T)
              ((uint8_T)i % MAX_uint8_T);
            test2_SysIntegration_B.RelativeTimerApplyMsg.Head.OpCode = 0U;
            test2_SysIntegration_B.RelativeTimerApplyMsg.Body.Data = 0U;
          }

          if (test2_SysIntegration_DW.bitsForTID4.is_active_TempBaseRateDumpManag
              != 1U) {
            test2_SysIntegration_DW.bitsForTID4.is_active_TempBaseRateDumpManag =
              1;
          }

          test2_SysIntegration_DW.bitsForTID4.is_TempBaseRateDumpManagement =
            test2_SysIntegration_IN_Idle_n;
          test2_SysIntegration_DW.bitsForTID4.is_active_LargeDoseDumpManageme =
            1;
        }
        break;

       case test2_SysIntegr_IN_MsgInProcess:
        test2_SysIntegrati_MsgInProcess
          (&test2_SysIntegration_DW.UnitDelay4_DSTATE_e,
           &test2_SysIntegration_DW.UnitDelay2_DSTATE);
        break;
      }
    }

    if (test2_SysIntegration_DW.CalibraStartEvtEventCounter > 0U) {
      test2_SysIntegration_B.bitsForTID4.CalibraStartEvt =
        !test2_SysIntegration_B.bitsForTID4.CalibraStartEvt;
      test2_SysIntegration_DW.CalibraStartEvtEventCounter--;
    }

    /* End of Chart: '<S65>/Chart' */

    /* BusCreator: '<S113>/BusConversion_InsertedFor_MemoryFilter_at_inport_0' */
    rtb_BusConversion_InsertedFor_0 =
      test2_SysIntegration_B.SysDiagMsgOut.Head.MsgId;
    rtb_BusConversion_InsertedFor_1 =
      test2_SysIntegration_B.SysDiagMsgOut.Body.Data;

    /* Chart: '<S55>/Chart' */
    if (test2_SysIntegration_DW.bitsForTID4.is_c34_test2_SysIntegration ==
        test2_SysIntegration_IN_Idle_k) {
      if (test2_SysIntegration_B.bitsForTID4.boolAirExpelSwitchOn) {
        test2_SysIntegration_DW.bitsForTID4.is_c34_test2_SysIntegration =
          test2_SysIntegration_IN_Op_h;
        test2_SysIntegration_DW.AirExpelStartEvtEventCounter++;
      }
    } else {
      if (!test2_SysIntegration_B.bitsForTID4.boolAirExpelSwitchOn) {
        test2_SysIntegration_DW.AirExpelStopEvtEventCounter++;
        test2_SysIntegration_DW.bitsForTID4.is_c34_test2_SysIntegration =
          test2_SysIntegration_IN_Idle_k;
      }
    }

    if (test2_SysIntegration_DW.AirExpelStartEvtEventCounter > 0U) {
      test2_SysIntegration_B.bitsForTID4.AirExpelStartEvt =
        !test2_SysIntegration_B.bitsForTID4.AirExpelStartEvt;
      test2_SysIntegration_DW.AirExpelStartEvtEventCounter--;
    }

    if (test2_SysIntegration_DW.AirExpelStopEvtEventCounter > 0U) {
      test2_SysIntegration_B.bitsForTID4.AirExpelStopEvt =
        !test2_SysIntegration_B.bitsForTID4.AirExpelStopEvt;
      test2_SysIntegration_DW.AirExpelStopEvtEventCounter--;
    }

    /* End of Chart: '<S55>/Chart' */
  }

  /* DiscretePulseGenerator: '<S89>/Pulse Generator' */
  i = ((test2_SysIntegration_DW.clockTickCounter < 500) &&
       (test2_SysIntegration_DW.clockTickCounter >= 0));
  if (test2_SysIntegration_DW.clockTickCounter >= 999) {
    test2_SysIntegration_DW.clockTickCounter = 0;
  } else {
    test2_SysIntegration_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S89>/Pulse Generator' */

  /* SignalConversion: '<S89>/HiddenBuf_InsertedFor_Chart_at_inport_1' incorporates:
   *  DataTypeConversion: '<S89>/Data Type Conversion'
   */
  rtb_HiddenBuf_InsertedFor_Cha_0 = (i != 0);

  /* Chart: '<S89>/Chart' incorporates:
   *  TriggerPort: '<S90>/input events'
   */
  rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_f[0] ==
                       POS_ZCSIG) != (int32_T)
                      test2_SysIntegration_B.bitsForTID4.AirExpelStartEvt) &&
                     (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_f[0] !=
                      UNINITIALIZED_ZCSIG));
  d_tf = rtb_PopAlarmEvt;
  zcEvent_idx_0 = rtb_PopAlarmEvt;

  /* SignalConversion: '<S89>/HiddenBuf_InsertedFor_Chart_at_inport_1' */
  rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_f[1] ==
                       POS_ZCSIG) != (int32_T)
                      test2_SysIntegration_B.bitsForTID4.AirExpelStopEvt) &&
                     (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_f[1] !=
                      UNINITIALIZED_ZCSIG));
  d_tf = (d_tf || rtb_PopAlarmEvt);
  zcEvent_idx_1 = rtb_PopAlarmEvt;
  rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_f[2] ==
                       POS_ZCSIG) != (int32_T)rtb_HiddenBuf_InsertedFor_Cha_0) &&
                     (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_f[2] !=
                      UNINITIALIZED_ZCSIG));
  d_tf = (d_tf || rtb_PopAlarmEvt);
  if (d_tf) {
    i = 0;

    /* SignalConversion: '<S89>/HiddenBuf_InsertedFor_Chart_at_inport_1' */
    if ((int8_T)(zcEvent_idx_0 ?
                 test2_SysIntegration_B.bitsForTID4.AirExpelStartEvt ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      i = 1;
      sfEvent_h = test2_Sy_event_StartAirExpelEvt;
      chartstep_c17_test2_SysIntegrat(&test2_SysIntegration_DW.UnitDelay_DSTATE,
        &sfEvent_h);
    }

    if ((int8_T)(zcEvent_idx_1 ?
                 test2_SysIntegration_B.bitsForTID4.AirExpelStopEvt ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      i = 1;
      sfEvent_h = test2_Sys_event_StopAirExpelEvt;
      chartstep_c17_test2_SysIntegrat(&test2_SysIntegration_DW.UnitDelay_DSTATE,
        &sfEvent_h);
    }

    if ((int8_T)(rtb_PopAlarmEvt ? rtb_HiddenBuf_InsertedFor_Cha_0 ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      i = 1;
      if (test2_SysIntegration_DW.temporalCounter_i1_ig < 15U) {
        test2_SysIntegration_DW.temporalCounter_i1_ig++;
      }

      sfEvent_h = test2_SysIntegr_event_UpdateEvt;
      chartstep_c17_test2_SysIntegrat(&test2_SysIntegration_DW.UnitDelay_DSTATE,
        &sfEvent_h);
    }

    if ((i != 0) && (test2_SysIntegration_DW.AirExpelEnaEvtEventCounter > 0U)) {
      test2_SysIntegration_B.bitsForTID0.AirExpelEnaEvt =
        !test2_SysIntegration_B.bitsForTID0.AirExpelEnaEvt;
      test2_SysIntegration_DW.AirExpelEnaEvtEventCounter--;
    }
  }

  /* SignalConversion: '<S89>/HiddenBuf_InsertedFor_Chart_at_inport_1' */
  test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_f[0] =
    test2_SysIntegration_B.bitsForTID4.AirExpelStartEvt;
  test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_f[1] =
    test2_SysIntegration_B.bitsForTID4.AirExpelStopEvt;
  test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_f[2] =
    rtb_HiddenBuf_InsertedFor_Cha_0;
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[2] == 0) {
    /* Chart: '<S1>/Chart' */
    test2_SysIntegration_ADCRead(true,
      &test2_SysIntegration_B.MajorSensorOutp.Ch1,
      &test2_SysIntegration_B.MajorSensorOutp.Ch2,
      &test2_SysIntegration_B.MajorSensorOutp.Ch3,
      &test2_SysIntegration_B.MajorSensorOutp.Ch4);
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    /* UnitDelay: '<S52>/Unit Delay' */
    test2_SysIntegration_B.UnitDelay_h =
      test2_SysIntegration_DW.UnitDelay_DSTATE_c;
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[5] == 0) {
    /* Chart: '<S5>/Chart' */
    test2_SysIntegration_GetKeyData(IOStatus);
    for (i = 0; i < 5; i++) {
      test2_SysIntegration_B.KeyVector[i] = IOStatus[i];
    }

    test2_SysIntegration_B.bitsForTID5.boolBubbleDetected = IOStatus[5];
    test2_SysIntegration_B.bitsForTID5.boolPCADetected = IOStatus[6];
    test2_SysIntegration_B.bitsForTID5.boolShaftEnc = IOStatus[7];

    /* End of Chart: '<S5>/Chart' */
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    /* UnitDelay: '<S52>/Unit Delay1' */
    test2_SysIntegration_B.UnitDelay1_l =
      test2_SysIntegration_DW.UnitDelay1_DSTATE_b;

    /* UnitDelay: '<S42>/Unit Delay' */
    test2_SysIntegration_B.UnitDelay_f =
      test2_SysIntegration_DW.UnitDelay_DSTATE_n;
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[7] == 0) {
    /* UnitDelay: '<S126>/Unit Delay2' incorporates:
     *  UnitDelay: '<S65>/Unit Delay'
     */
    test2_SysIntegration_DW.UnitDelay_DSTATE_j =
      test2_SysIntegration_DW.UnitDelay2_DSTATE_o;
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[6] == 0) {
    /* Chart: '<S52>/PCAMsgSend' */
    if (test2_SysIntegration_DW.temporalCounter_i1_ls < 31U) {
      test2_SysIntegration_DW.temporalCounter_i1_ls++;
    }

    sfEvent_h = -1;
    if (test2_SysIntegration_DW.bitsForTID6.is_active_c49_test2_SysIntegrat ==
        0U) {
      test2_SysIntegration_DW.bitsForTID6.is_active_c49_test2_SysIntegrat = 1;
      if (test2_SysIntegration_DW.bitsForTID6.is_active_PCACtrlMsgDetector != 1U)
      {
        test2_SysIntegration_DW.bitsForTID6.is_active_PCACtrlMsgDetector = 1;
        test2_SysIntegration_B.PCAAlarmMsg.Head.MsgId = 0U;
        test2_SysIntegration_B.PCAAlarmMsg.Head.OpCode = 0U;
        test2_SysIntegration_B.PCAAlarmMsg.Body.Data = 0U;
      }

      if (test2_SysIntegration_DW.bitsForTID6.is_PCACtrlMsgDetector !=
          test2_SysIntegration_IN_None) {
        test2_SysIntegration_DW.bitsForTID6.is_PCACtrlMsgDetector =
          test2_SysIntegration_IN_None;
        test2_SysIntegration_B.bitsForTID6.boolBusy = false;
      }

      if (test2_SysIntegration_DW.bitsForTID6.is_active_PCADoseMonitor != 1U) {
        test2_SysIntegration_DW.bitsForTID6.is_active_PCADoseMonitor = 1;
        test2_SysIntegration_B.PCADoseCtrlMsg.Head.MsgId = 0U;
        test2_SysIntegration_B.PCADoseCtrlMsg.Head.OpCode = 0U;
        d.MajorId = 1U;
        d.MinorId = 3U;
        memset(&d.Data[0], 0, 132U * sizeof(uint8_T));
        test2_SysIntegration_B.PCADoseCtrlMsg.Body = d;
        test2_SysIntegration_DW.prevRTCompMsgId =
          test2_SysIntegration_B.UnitDelay_f.Head.MsgId;
        test2_SysIntegration_DW.Day_mSecond = 0U;
        test2_SysIntegration_DW.Op_mSecond = 0U;
      }

      if (test2_SysIntegration_DW.bitsForTID6.is_PCADoseMonitor !=
          test2_SysIntegration_IN_Idle_k) {
        test2_SysIntegration_DW.bitsForTID6.is_PCADoseMonitor =
          test2_SysIntegration_IN_Idle_k;
        elapsedTicks_d = (uint32_T)test2_SysIntegration_B.UnitDelay1_l -
          /*MW:OvSatOk*/ test2_SysIntegration_DW.PCAACCDose;
        if (elapsedTicks_d > test2_SysIntegration_B.UnitDelay1_l) {
          elapsedTicks_d = 0U;
        }

        if ((uint16_T)elapsedTicks_d < test2_SysIntegration_B.UnitDelay_h) {
          test2_SysIntegration_DW.PCASaturatedDose = (uint16_T)elapsedTicks_d;
        } else {
          test2_SysIntegration_DW.PCASaturatedDose =
            test2_SysIntegration_B.UnitDelay_h;
        }
      }
    } else {
      if (test2_SysIntegration_DW.bitsForTID6.is_active_PCACtrlMsgDetector != 0U)
      {
        guard1 = false;
        switch (test2_SysIntegration_DW.bitsForTID6.is_PCACtrlMsgDetector) {
         case test2_SysIntegration_IN_None:
          if (test2_SysIntegration_B.bitsForTID5.boolPCADetected) {
            if (test2_SysIntegration_DW.bitsForTID6.is_PCACtrlMsgDetector ==
                test2_SysIntegration_IN_None) {
              test2_SysIntegration_B.bitsForTID6.boolBusy = true;
              test2_SysIntegration_DW.bitsForTID6.is_PCACtrlMsgDetector = 0;
            }

            if (test2_SysIntegration_DW.bitsForTID6.is_PCACtrlMsgDetector !=
                test2_SysIntegration_IN_PCA) {
              test2_SysIntegration_DW.bitsForTID6.is_PCACtrlMsgDetector =
                test2_SysIntegration_IN_PCA;
              test2_SysIntegration_DW.temporalCounter_i1_ls = 0U;
            }
          }
          break;

         case test2_SysIntegration_IN_PCA:
          if ((test2_SysIntegration_DW.temporalCounter_i1_ls >= 20U) &&
              test2_SysIntegration_B.bitsForTID5.boolPCADetected) {
            test2_SysIntegration_DW.bitsForTID6.is_PCACtrlMsgDetector =
              test2_SysIntegration_IN_Sticky;
            i = (int32_T)(test2_SysIntegration_B.PCAAlarmMsg.Head.MsgId + 1U);
            if ((uint32_T)i > 255U) {
              i = 255;
            }

            test2_SysIntegration_B.PCAAlarmMsg.Head.MsgId = (uint8_T)((uint8_T)i
              % MAX_uint8_T);
            test2_SysIntegration_B.PCAAlarmMsg.Head.OpCode = 1U;
            test2_SysIntegration_B.PCAAlarmMsg.Body.Data = 29U;
          } else if ((test2_SysIntegration_DW.temporalCounter_i1_ls < 6U) &&
                     (!test2_SysIntegration_B.bitsForTID5.boolPCADetected)) {
            guard1 = true;
          } else {
            if ((test2_SysIntegration_DW.temporalCounter_i1_ls >= 6U) &&
                (!test2_SysIntegration_B.bitsForTID5.boolPCADetected)) {
              sfEvent_h = test2_SysIntegrati_event_PCAEvt;
              if (test2_SysIntegration_DW.bitsForTID6.is_active_PCADoseMonitor
                  != 0U) {
                test2_SysIntegra_PCADoseMonitor(&sfEvent_h);
              }

              sfEvent_h = -1;
              guard1 = true;
            }
          }
          break;

         case test2_SysIntegration_IN_Sticky:
          if (!test2_SysIntegration_B.bitsForTID5.boolPCADetected) {
            test2_SysIntegration_DW.bitsForTID6.is_PCACtrlMsgDetector =
              test2_SysIntegration_IN_None;
            test2_SysIntegration_B.bitsForTID6.boolBusy = false;
          }
          break;
        }

        if (guard1) {
          test2_SysIntegration_DW.bitsForTID6.is_PCACtrlMsgDetector =
            test2_SysIntegration_IN_None;
          test2_SysIntegration_B.bitsForTID6.boolBusy = false;
        }
      }

      if (test2_SysIntegration_DW.bitsForTID6.is_active_PCADoseMonitor != 0U) {
        test2_SysIntegra_PCADoseMonitor(&sfEvent_h);
      }
    }

    /* End of Chart: '<S52>/PCAMsgSend' */
  }

  /* DiscretePulseGenerator: '<S100>/Pulse Generator' */
  i = ((test2_SysIntegration_DW.clockTickCounter_l < 500) &&
       (test2_SysIntegration_DW.clockTickCounter_l >= 0));
  if (test2_SysIntegration_DW.clockTickCounter_l >= 999) {
    test2_SysIntegration_DW.clockTickCounter_l = 0;
  } else {
    test2_SysIntegration_DW.clockTickCounter_l++;
  }

  /* End of DiscretePulseGenerator: '<S100>/Pulse Generator' */

  /* SignalConversion: '<S100>/HiddenBuf_InsertedFor_Chart_at_inport_2' incorporates:
   *  DataTypeConversion: '<S100>/Data Type Conversion'
   */
  rtb_HiddenBuf_InsertedFor_Cha_0 = (i != 0);

  /* Chart: '<S100>/Chart' incorporates:
   *  TriggerPort: '<S101>/input events'
   */
  rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_h[0] ==
                       POS_ZCSIG) != (int32_T)
                      test2_SysIntegration_B.bitsForTID4.CalibraStartEvt) &&
                     (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_h[0] !=
                      UNINITIALIZED_ZCSIG));
  d_tf = rtb_PopAlarmEvt;
  zcEvent_idx_0 = rtb_PopAlarmEvt;
  rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_h[1] ==
                       POS_ZCSIG) != (int32_T)rtb_HiddenBuf_InsertedFor_Cha_0) &&
                     (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_h[1] !=
                      UNINITIALIZED_ZCSIG));
  d_tf = (d_tf || rtb_PopAlarmEvt);
  if (d_tf) {
    /* SignalConversion: '<S100>/HiddenBuf_InsertedFor_Chart_at_inport_2' */
    if ((int8_T)(zcEvent_idx_0 ?
                 test2_SysIntegration_B.bitsForTID4.CalibraStartEvt ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      i = test2_Sys_event_CalibraStartEvt;
      chartstep_c26_test2_SysIntegrat(&i);
    }

    if ((int8_T)(rtb_PopAlarmEvt ? rtb_HiddenBuf_InsertedFor_Cha_0 ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      if (test2_SysIntegration_DW.temporalCounter_i1_l < 7U) {
        test2_SysIntegration_DW.temporalCounter_i1_l++;
      }

      i = test2_SysInt_event_UpdateTick_c;
      chartstep_c26_test2_SysIntegrat(&i);
    }
  }

  /* SignalConversion: '<S100>/HiddenBuf_InsertedFor_Chart_at_inport_2' */
  test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_h[0] =
    test2_SysIntegration_B.bitsForTID4.CalibraStartEvt;
  test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_h[1] =
    rtb_HiddenBuf_InsertedFor_Cha_0;

  /* Chart: '<S14>/MsgRouter1' */
  if (test2_SysIntegration_DW.temporalCounter_i1_k < 4095U) {
    test2_SysIntegration_DW.temporalCounter_i1_k++;
  }

  if (test2_SysIntegration_DW.bitsForTID0.is_active_c46_test2_SysIntegrat == 0U)
  {
    test2_SysIntegration_DW.bitsForTID0.is_active_c46_test2_SysIntegrat = 1;
    test2_SysIntegration_DW.bitsForTID0.is_c46_test2_SysIntegration =
      test2_SysIntegration_IN_Init_b;
    test2_SysIntegration_DW.temporalCounter_i1_k = 0U;
    test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Head.MsgId = 0U;
    test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Head.OpCode = 0U;
    b.MajorId = 0U;
    b.MinorId = 0U;
    memset(&b.Data[0], 0, 132U * sizeof(uint8_T));
    test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Body = b;
    test2_SysIntegration_DW.prevMsg1Id_ld = 0U;
    test2_SysIntegration_DW.prevMsg2Id_l = 0U;
    test2_SysIntegration_DW.prevMsg3Id = 0U;
    test2_SysIntegration_DW.prevMsg4Id = 0U;
  } else if (test2_SysIntegration_DW.bitsForTID0.is_c46_test2_SysIntegration ==
             1) {
    if (test2_SysIntegration_DW.prevMsg1Id_ld !=
        test2_SysIntegration_B.drvFlashAccessMsgOut.Head.MsgId) {
      test2_SysIntegration_DW.prevMsg1Id_ld =
        test2_SysIntegration_B.drvFlashAccessMsgOut.Head.MsgId;
      zcEvent_idx_0 = false;
      zcEvent_idx_1 = true;
      if (!(test2_SysIntegration_B.drvFlashAccessMsgOut.Head.OpCode == 100)) {
        zcEvent_idx_1 = false;
      }

      if (zcEvent_idx_1) {
        zcEvent_idx_0 = true;
      }

      if (!zcEvent_idx_0) {
        i = (int32_T)
          (test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Head.MsgId + 1U);
        if ((uint32_T)i > 255U) {
          i = 255;
        }

        test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Head.MsgId = (uint8_T)
          ((uint8_T)i % MAX_uint8_T);
        test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Head.OpCode =
          test2_SysIntegration_B.drvFlashAccessMsgOut.Head.OpCode;
        test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Body =
          test2_SysIntegration_B.drvFlashAccessMsgOut.Body;
      }
    } else if (test2_SysIntegration_DW.prevMsg2Id_l !=
               test2_SysIntegration_B.PCADoseCtrlMsg.Head.MsgId) {
      test2_SysIntegration_DW.prevMsg2Id_l =
        test2_SysIntegration_B.PCADoseCtrlMsg.Head.MsgId;
      i = (int32_T)(test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Head.MsgId
                    + 1U);
      if ((uint32_T)i > 255U) {
        i = 255;
      }

      test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Head.MsgId = (uint8_T)
        ((uint8_T)i % MAX_uint8_T);
      test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Head.OpCode =
        test2_SysIntegration_B.PCADoseCtrlMsg.Head.OpCode;
      test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Body =
        test2_SysIntegration_B.PCADoseCtrlMsg.Body;
    } else if (test2_SysIntegration_DW.prevMsg3Id !=
               test2_SysIntegration_B.CalibraResult2FlashDrv.Head.MsgId) {
      test2_SysIntegration_DW.prevMsg3Id =
        test2_SysIntegration_B.CalibraResult2FlashDrv.Head.MsgId;
      i = (int32_T)(test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Head.MsgId
                    + 1U);
      if ((uint32_T)i > 255U) {
        i = 255;
      }

      test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Head.MsgId = (uint8_T)
        ((uint8_T)i % MAX_uint8_T);
      test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Head.OpCode =
        test2_SysIntegration_B.CalibraResult2FlashDrv.Head.OpCode;
      test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Body =
        test2_SysIntegration_B.CalibraResult2FlashDrv.Body;
    } else {
      if (test2_SysIntegration_DW.prevMsg4Id != 0) {
        test2_SysIntegration_DW.prevMsg4Id = 0U;
        i = (int32_T)
          (test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Head.MsgId + 1U);
        if ((uint32_T)i > 255U) {
          i = 255;
        }

        test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Head.MsgId = (uint8_T)
          ((uint8_T)i % MAX_uint8_T);
        test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Head.OpCode = 0U;
        test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Body =
          test2_SysIntegration_rtZtype_FlashAccessMsg.Body;
      }
    }
  } else {
    if (test2_SysIntegration_DW.temporalCounter_i1_k >= 3000U) {
      test2_SysIntegration_DW.bitsForTID0.is_c46_test2_SysIntegration = 1;
      test2_SysIntegration_DW.prevMsg1Id_ld =
        test2_SysIntegration_B.drvFlashAccessMsgOut.Head.MsgId;
      test2_SysIntegration_DW.prevMsg2Id_l =
        test2_SysIntegration_B.PCADoseCtrlMsg.Head.MsgId;
      test2_SysIntegration_DW.prevMsg3Id =
        test2_SysIntegration_B.CalibraResult2FlashDrv.Head.MsgId;
    }
  }

  /* End of Chart: '<S14>/MsgRouter1' */
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    /* Chart: '<S63>/Chart' incorporates:
     *  UnitDelay: '<S65>/Unit Delay'
     */
    if (test2_SysIntegration_DW.temporalCounter_i1_n < 127U) {
      test2_SysIntegration_DW.temporalCounter_i1_n++;
    }

    if (test2_SysIntegration_DW.temporalCounter_i2_dg < 31U) {
      test2_SysIntegration_DW.temporalCounter_i2_dg++;
    }

    if (test2_SysIntegration_DW.temporalCounter_i3_n < 31U) {
      test2_SysIntegration_DW.temporalCounter_i3_n++;
    }

    if (test2_SysIntegration_DW.temporalCounter_i4 < 127U) {
      test2_SysIntegration_DW.temporalCounter_i4++;
    }

    test2_SysIntegration_DW.sfEvent_gn = -1;
    if (test2_SysIntegration_DW.bitsForTID4.is_active_c2_test2_SysIntegrati ==
        0U) {
      test2_SysIntegration_DW.bitsForTID4.is_active_c2_test2_SysIntegrati = 1;
      test2_SysIntegration_DW.bitsForTID4.is_c2_test2_SysIntegration =
        test2_SysIntegratio_IN_FlashDrv;
      test2_S_enter_internal_FlashDrv();
    } else {
      switch (test2_SysIntegration_DW.bitsForTID4.is_c2_test2_SysIntegration) {
       case test2_SysIntegration_IN_Dead:
        break;

       case test2_SysIntegratio_IN_FlashDrv:
        if (test2_SysIntegration_DW.bitsForTID4.FlashAccessErr) {
          if (test2_SysIntegration_DW.bitsForTID4.is_FlashDrv ==
              test2_SysIntegrat_IN_FlashDrive) {
            test2__exit_internal_FlashDrive();
            test2_SysIntegration_DW.bitsForTID4.is_FlashDrv = 0;
          } else {
            test2_SysIntegration_DW.bitsForTID4.is_Init = 0;
            test2_SysIntegration_DW.bitsForTID4.is_FlashDrv = 0;
          }

          test2_SysIntegration_DW.bitsForTID4.is_c2_test2_SysIntegration =
            test2_SysIntegration_IN_Warning;
          i = (int32_T)(test2_SysIntegration_DW.FlashErrTimes + 1U);
          if ((uint32_T)i > 255U) {
            i = 255;
          }

          test2_SysIntegration_DW.FlashErrTimes = (uint8_T)i;
          i = (int32_T)(test2_SysIntegration_B.SysDiagMsgOut_d.Head.MsgId + 1U);
          if ((uint32_T)i > 255U) {
            i = 255;
          }

          test2_SysIntegration_B.SysDiagMsgOut_d.Head.MsgId = (uint8_T)((uint8_T)
            i % MAX_uint8_T);
          test2_SysIntegration_B.SysDiagMsgOut_d.Head.OpCode = 1U;
          test2_SysIntegration_B.SysDiagMsgOut_d.Body.Data = 7U;
        } else {
          switch (test2_SysIntegration_DW.bitsForTID4.is_FlashDrv) {
           case test2_SysIntegrat_IN_FlashDrive:
            if (test2_SysIntegration_DW.temporalCounter_i4 >= 100U) {
              test2_SysIntegration_DW.FlashErrTimes = 0U;
              zcEvent_idx_0 = test2_SysInteg_DailyDoseStatClr
                (&test2_SysIntegration_B.VarSet,
                 test2_SysIntegration_DW.UnitDelay_DSTATE_j, 2, 6);
              test2_SysIntegration_DW.bitsForTID4.FlashAccessErr = zcEvent_idx_0;
              test2__exit_internal_FlashDrive();
              test2_enter_internal_FlashDrive();
            } else {
              if (test2_SysIntegration_DW.bitsForTID4.is_active_FlashDriveAct !=
                  0U) {
                test2_SysIntegrat_FlashDriveAct
                  (&test2_SysIntegration_DW.UnitDelay_DSTATE_l);
              }

              if (test2_SysIntegration_DW.bitsForTID4.is_active_UpgradeAndLogUpLoadMa
                  != 0U) {
                guard1 = false;
                switch
                  (test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen)
                {
                 case test2_SysInteg_IN_GetOneDataBag:
                  if ((!test2_SysIntegration_DW.FirmwareParam.boolBagNoHit) &&
                      test2_SysIntegration_DW.FirmwareParam.boolGet1Bag) {
                    test2_SysIntegration_DW.FirmwareParam.boolGet1Bag = false;
                    test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen
                      = test2_SysInteg_IN_GetOneDataBag;
                    test2_SysIntegration_DW.temporalCounter_i1_n = 0U;
                  } else if (test2_SysIntegration_DW.temporalCounter_i1_n >=
                             100U) {
                    test2_SysIntegration_B.VarSet.Firmware.FirmwareUpgradeCompleteFlag
                      = 3U;
                    test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen
                      = IN_Wait4FirstBag_LogUpLoadReque;
                    enter_atomic_Wait4FirstBag_LogU();
                  } else if (test2_SysIntegration_DW.FirmwareParam.boolBagNoHit &&
                             test2_SysIntegration_DW.FirmwareParam.boolCRC32Hit)
                  {
                    test2_SysIntegration_B.VarSet.Firmware.FirmwareUpgradeCompleteFlag
                      = 1U;
                    guard1 = true;
                  } else {
                    if (test2_SysIntegration_DW.FirmwareParam.boolBagNoHit &&
                        (!test2_SysIntegration_DW.FirmwareParam.boolCRC32Hit)) {
                      test2_SysIntegration_B.VarSet.Firmware.FirmwareUpgradeCompleteFlag
                        = 2U;
                      guard1 = true;
                    }
                  }
                  break;

                 case test2_SysInt_IN_LogExportCtrlOp:
                  if (test2_SysIntegration_DW.bitsForTID4.boolLogReadTerminate)
                  {
                    if (test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen
                        == test2_SysInt_IN_LogExportCtrlOp) {
                      test2_SysIntegration_DW.bitsForTID4.boolLogSend = false;
                      test2_SysIntegration_DW.bitsForTID4.boolLogReadTerminate =
                        true;
                      test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen
                        = 0;
                    }

                    if (test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen
                        != IN_Wait4FirstBag_LogUpLoadReque) {
                      test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen
                        = IN_Wait4FirstBag_LogUpLoadReque;
                      enter_atomic_Wait4FirstBag_LogU();
                    }
                  } else {
                    if (test2_SysIntegration_DW.bitsForTID4.boolLogSend) {
                      test2_SysIntegration_DW.bitsForTID4.boolLogSend = false;
                      elapsedTicks_d = test2_SysIntegration_DW.LogId + 1U;
                      tmp_6 = elapsedTicks_d;
                      if (elapsedTicks_d > 65535U) {
                        tmp_6 = 65535U;
                      }

                      a[0] = (uint16_T)tmp_6;
                      a[1] = (uint16_T)tmp_6;
                      a[2] = (uint16_T)tmp_6;
                      a[3] = (uint16_T)tmp_6;
                      test2_SysIntegration_OneLogRead
                        (test2_SysIntegration_DW.LogWriteMajorId, a,
                         test2_SysIntegration_DW.Channel, &LogAvailableFlag,
                         LogData);
                      switch (LogAvailableFlag) {
                       case 0:
                        test2_SysIntegration_DW.bitsForTID4.boolLogReadTerminate
                          = true;
                        i = (int32_T)
                          (test2_SysIntegration_B.SysDiagMsgOut_d.Head.MsgId +
                           1U);
                        if ((uint32_T)i > 255U) {
                          i = 255;
                        }

                        test2_SysIntegration_B.SysDiagMsgOut_d.Head.MsgId =
                          (uint8_T)((uint8_T)i % MAX_uint8_T);
                        test2_SysIntegration_B.SysDiagMsgOut_d.Head.OpCode = 1U;
                        test2_SysIntegration_B.SysDiagMsgOut_d.Body.Data = 209U;
                        break;

                       case 1:
                        i = (int32_T)
                          (test2_SysIntegration_B.LogDataMsg.Head.MsgId + 1U);
                        if ((uint32_T)i > 255U) {
                          i = 255;
                        }

                        test2_SysIntegration_B.LogDataMsg.Head.MsgId = (uint8_T)
                          ((uint8_T)i % MAX_uint8_T);
                        test2_SysIntegration_B.LogDataMsg.Head.OpCode = 2U;
                        test2_SysIntegration_B.LogDataMsg.Body.MajorId = 0U;
                        test2_SysIntegration_B.LogDataMsg.Body.MinorId = 0U;
                        for (i = 0; i < 44; i++) {
                          test2_SysIntegration_B.LogDataMsg.Body.Data[i] =
                            LogData[i];
                        }

                        if (elapsedTicks_d > 65535U) {
                          elapsedTicks_d = 65535U;
                        }

                        test2_SysIntegration_DW.LogId = (uint16_T)elapsedTicks_d;
                        if (test2_SysIntegration_DW.LogId >
                            test2_SysIntegration_DW.LogIdThVal) {
                          test2_SysIntegration_DW.bitsForTID4.boolLogReadTerminate
                            = true;
                        }
                        break;

                       case MAX_uint8_T:
                        test2_SysIntegration_DW.bitsForTID4.FlashAccessErr =
                          true;
                        break;
                      }
                    }

                    if (test2_SysIntegration_DW.temporalCounter_i1_n >= 1U) {
                      test2_SysIntegration_DW.bitsForTID4.boolLogSend = true;
                    }
                  }
                  break;

                 case test2_SysInt_IN_UpdateScreenLog:
                  if (test2_SysIntegration_DW.bitsForTID4.boolLogReadTerminate)
                  {
                    test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen
                      = IN_Wait4FirstBag_LogUpLoadReque;
                    enter_atomic_Wait4FirstBag_LogU();
                  }
                  break;

                 case IN_Wait4FirstBag_LogUpLoadReque:
                  Wait4FirstBag_LogUpLoadRequest();
                  break;
                }

                if (guard1) {
                  test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen
                    = IN_Wait4FirstBag_LogUpLoadReque;
                  enter_atomic_Wait4FirstBag_LogU();
                }
              }

              if (test2_SysIntegration_DW.bitsForTID4.is_active_VarClrService !=
                  0U) {
                test2_SysIntegrat_VarClrService();
              }

              if (test2_SysIntegration_DW.bitsForTID4.is_active_LogClrService !=
                  0U) {
                test2_SysIntegrat_LogClrService();
              }
            }
            break;

           case test2_SysIntegration_IN_Init_b:
            test2_SysIntegration_Init
              (&test2_SysIntegration_DW.UnitDelay_DSTATE_l);
            break;
          }
        }
        break;

       case test2_SysIntegration_IN_Warning:
        if (test2_SysIntegration_DW.FlashErrTimes < 2) {
          test2_SysIntegration_DW.bitsForTID4.FlashAccessErr = false;
          test2_SysIntegration_DW.bitsForTID4.is_c2_test2_SysIntegration =
            test2_SysIntegratio_IN_FlashDrv;
          test2_S_enter_internal_FlashDrv();
        } else {
          if (test2_SysIntegration_DW.FlashErrTimes > 1) {
            test2_SysIntegration_DW.bitsForTID4.is_c2_test2_SysIntegration =
              test2_SysIntegration_IN_Dead;
            i = (int32_T)(test2_SysIntegration_B.SysDiagMsgOut_d.Head.MsgId + 1U);
            if ((uint32_T)i > 255U) {
              i = 255;
            }

            test2_SysIntegration_B.SysDiagMsgOut_d.Head.MsgId = (uint8_T)
              ((uint8_T)i % MAX_uint8_T);
            test2_SysIntegration_B.SysDiagMsgOut_d.Head.OpCode = 1U;
            test2_SysIntegration_B.SysDiagMsgOut_d.Body.Data = 91U;
          }
        }
        break;
      }
    }

    if (test2_SysIntegration_DW.FlashInitFinishEvtEventCounter > 0U) {
      test2_SysIntegration_B.bitsForTID4.FlashInitFinishEvt =
        !test2_SysIntegration_B.bitsForTID4.FlashInitFinishEvt;
      test2_SysIntegration_DW.FlashInitFinishEvtEventCounter--;
    }

    /* End of Chart: '<S63>/Chart' */

    /* Delay: '<S67>/Wait4LPFinish' */
    test2_SysIntegration_B.bitsForTID4.Wait4LPFinish =
      test2_SysIntegration_DW.Wait4LPFinish_DSTATE[0];
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[1] == 0) {
    /* RateTransition: '<S42>/Rate Transition' incorporates:
     *  UnitDelay: '<S21>/Unit Delay'
     */
    if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
      test2_SysIntegration_B.RateTransition =
        test2_SysIntegration_DW.bitsForTID1.UnitDelay_DSTATE_f;
    }

    /* End of RateTransition: '<S42>/Rate Transition' */
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[2] == 0) {
    /* Chart: '<S51>/Chart' */
    if (test2_SysIntegration_DW.temporalCounter_i1_p < MAX_uint32_T) {
      test2_SysIntegration_DW.temporalCounter_i1_p++;
    }

    if (test2_SysIntegration_DW.bitsForTID2.is_active_c48_test2_SysIntegrat ==
        0U) {
      test2_SysIntegration_DW.bitsForTID2.is_active_c48_test2_SysIntegrat = 1;
      test2_SysIntegration_DW.HMICtrlParam.LPTh = 3000U;
      test2_SysIntegration_DW.HMICtrlParam.KSTh = 12000U;
      test2_SysIntegration_DW.HMICtrlParam.DeepIdleTime = 10000U;
      test2_SysIntegration_DW.HMICtrlParam.KeyId = 0U;
      test2_SysIntegration_B.KeyModeMsg.Head.MsgId = 0U;
      test2_SysIntegration_B.KeyModeMsg.Head.OpCode = 0U;
      test2_SysIntegration_B.KeyModeMsg.Body.Data = 0U;
      test2_SysIntegration_B.KeyAlarmMsg = test2_SysIntegration_B.KeyModeMsg;
      test2_SysIntegration_DW.bitsForTID2.is_KeyModeIdentification =
        test2_SysInteg_IN_NoKeyDetected;
    } else {
      test2_SysIntegration_B.bitsForTID2.KeyDownStatus =
        (test2_SysIntegration_DW.bitsForTID2.is_KeyModeIdentification ==
         test2_Sys_IN_SingleKeyModeIdent);
      if (test2_SysIntegration_DW.bitsForTID2.is_KeyModeIdentification ==
          test2_SysInteg_IN_NoKeyDetected) {
        if (test2_SysIntegration_DW.HMICtrlParam.KeyId != 0) {
          for (i = 0; i < 5; i++) {
            test2_SysIntegration_DW.KeyValueAcc[i] = 0U;
          }

          test2_SysIntegration_DW.bitsForTID2.is_KeyModeIdentification =
            test2_Sys_IN_SingleKeyModeIdent;
          test2_SysIntegration_B.KeyModeMsg.Body.Data =
            test2_SysIntegration_DW.HMICtrlParam.KeyId;
          test2_SysIntegration_DW.bitsForTID2.is_SingleKeyModeIdent =
            test2_SysIntegration_IN_SP;
          test2_SysIntegration_DW.temporalCounter_i1_p = 0U;
        } else {
          for (i = 0; i < 5; i++) {
            test2_SysIntegration_DW.KeyValueAcc[i] = (uint8_T)((uint32_T)
              test2_SysIntegration_DW.KeyValueAcc[i] +
              test2_SysIntegration_B.KeyVector[i]);
          }

          test2_SysIntegration_DW.HMICtrlParam.KeyId =
            test2_SysIntegr_findFirstTarget(test2_SysIntegration_DW.KeyValueAcc,
            5);
        }
      } else if (test2_SysIntegration_DW.bitsForTID2.is_SingleKeyModeIdent ==
                 test2_SysIntegr_IN_IdentifyStop) {
        test2_SysIntegration_DW.bitsForTID2.is_SingleKeyModeIdent = 0;
        test2_SysIntegration_DW.bitsForTID2.is_KeyModeIdentification =
          test2_SysInteg_IN_NoKeyDetected;
      } else {
        switch (test2_SysIntegration_DW.bitsForTID2.is_SingleKeyModeIdent) {
         case test2_SysIntegr_IN_IdentifyStop:
          break;

         case test2_SysIntegration_IN_KS:
          if ((test2_SysIntegration_DW.temporalCounter_i1_p * 10U >= (uint16_T)
               ((uint32_T)test2_SysIntegration_DW.HMICtrlParam.KSTh +
                test2_SysIntegration_DW.HMICtrlParam.LPTh)) &&
              test2_SysIntegration_B.KeyVector[test2_SysIntegration_DW.HMICtrlParam.KeyId
              - 1]) {
            test2_SysIntegration_DW.bitsForTID2.is_SingleKeyModeIdent =
              test2_SysIntegration_IN_KS;
            test2_SysIntegration_DW.temporalCounter_i1_p = 0U;
            test2_SysIntegration_B.KeyAlarmMsg.Body.Data = 204U;
            test2_SysIntegration_B.KeyAlarmMsg.Head.OpCode = 1U;
            test2_SysIntegration_B.KeyAlarmMsg.Head.MsgId = (uint8_T)((uint8_T)
              (test2_SysIntegration_B.KeyAlarmMsg.Head.MsgId + 1U) % MAX_uint8_T);
          } else {
            if (!test2_SysIntegration_B.KeyVector[test2_SysIntegration_DW.HMICtrlParam.KeyId
                - 1]) {
              test2_SysIntegration_DW.bitsForTID2.is_SingleKeyModeIdent =
                test2_SysIntegr_IN_IdentifyStop;
            }
          }
          break;

         case test2_SysIntegration_IN_LP:
          if (test2_SysIntegration_DW.temporalCounter_i1_p * 10U >=
              test2_SysIntegration_DW.HMICtrlParam.KSTh) {
            test2_SysIntegration_DW.bitsForTID2.is_SingleKeyModeIdent =
              test2_SysIntegration_IN_KS;
            test2_SysIntegration_DW.temporalCounter_i1_p = 0U;
            test2_SysIntegration_B.KeyAlarmMsg.Body.Data = 204U;
            test2_SysIntegration_B.KeyAlarmMsg.Head.OpCode = 1U;
            test2_SysIntegration_B.KeyAlarmMsg.Head.MsgId = (uint8_T)((uint8_T)
              (test2_SysIntegration_B.KeyAlarmMsg.Head.MsgId + 1U) % MAX_uint8_T);
          } else {
            if ((!test2_SysIntegration_B.KeyVector[test2_SysIntegration_DW.HMICtrlParam.KeyId
                 - 1]) && (test2_SysIntegration_DW.temporalCounter_i1_p * 10U <
                           test2_SysIntegration_DW.HMICtrlParam.KSTh)) {
              test2_SysIntegration_B.KeyModeMsg.Head.OpCode = 2U;
              test2_SysIntegration_B.KeyModeMsg.Head.MsgId = (uint8_T)((uint8_T)
                (test2_SysIntegration_B.KeyModeMsg.Head.MsgId + 1U) %
                MAX_uint8_T);
              test2_SysIntegration_DW.bitsForTID2.is_SingleKeyModeIdent =
                test2_SysIntegr_IN_IdentifyStop;
            }
          }
          break;

         default:
          if (test2_SysIntegration_DW.temporalCounter_i1_p * 10U >=
              test2_SysIntegration_DW.HMICtrlParam.LPTh) {
            test2_SysIntegration_DW.bitsForTID2.is_SingleKeyModeIdent =
              test2_SysIntegration_IN_LP;
            test2_SysIntegration_DW.temporalCounter_i1_p = 0U;
          } else {
            if ((!test2_SysIntegration_B.KeyVector[test2_SysIntegration_DW.HMICtrlParam.KeyId
                 - 1]) && (test2_SysIntegration_DW.temporalCounter_i1_p * 10U <
                           test2_SysIntegration_DW.HMICtrlParam.LPTh)) {
              test2_SysIntegration_B.KeyModeMsg.Head.OpCode = 1U;
              test2_SysIntegration_B.KeyModeMsg.Head.MsgId = (uint8_T)((uint8_T)
                (test2_SysIntegration_B.KeyModeMsg.Head.MsgId + 1U) %
                MAX_uint8_T);
              test2_SysIntegration_DW.bitsForTID2.is_SingleKeyModeIdent =
                test2_SysIntegr_IN_IdentifyStop;
            }
          }
          break;
        }
      }
    }

    /* End of Chart: '<S51>/Chart' */

    /* Logic: '<S13>/Logical Operator' */
    zcEvent_idx_0 = (test2_SysIntegration_B.bitsForTID2.KeyDownStatus ||
                     test2_SysIntegration_B.bitsForTID6.boolBusy);

    /* RateTransition: '<S42>/Rate Transition1' */
    if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
      test2_SysIntegration_B.RateTransition1 = zcEvent_idx_0;
    }

    /* End of RateTransition: '<S42>/Rate Transition1' */
  }

  /* RateTransition: '<S42>/Rate Transition2' */
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    if (test2_SysIntegration_M->Timing.TaskCounters.TID[7] == 0) {
      test2_SysIntegration_B.BusCreator_h.NextHitSec =
        test2_SysIntegration_DW.RateTransition2_Buffer0;
    }

    /* BusCreator: '<S49>/Bus Creator' */
    test2_SysIntegration_B.BusCreator_h.AlarmStatus =
      test2_SysIntegration_B.RateTransition;
    test2_SysIntegration_B.BusCreator_h.HMIStatus =
      test2_SysIntegration_B.RateTransition1;
    test2_SysIntegration_B.BusCreator_h.RecordStatus =
      test2_SysIntegration_B.bitsForTID4.WorkStatus;
    test2_SysIntegration_B.BusCreator_h.BleCommStatus = false;
    test2_SysIntegration_B.BusCreator_h.SerialCommStatus = false;

    /* Chart: '<S49>/Chart' */
    if (test2_SysIntegration_DW.temporalCounter_i1_d < MAX_uint32_T) {
      test2_SysIntegration_DW.temporalCounter_i1_d++;
    }

    if (test2_SysIntegration_DW.bitsForTID4.is_active_c6_test2_SysIntegrati ==
        0U) {
      test2_SysIntegration_DW.bitsForTID4.is_active_c6_test2_SysIntegrati = 1;
      test2_SysIntegration_DW.bitsForTID4.is_c6_test2_SysIntegration =
        test2_SysIntegration_IN_Init;
      test2_SysIntegration_B.SecurityMsgOut.Head.MsgId = 0U;
      test2_SysIntegration_B.SecurityMsgOut.Head.OpCode = 0U;
      test2_SysIntegration_B.SecurityMsgOut.Body.Data = 0U;
      test2_SysIntegration_B.SysDiagMsg_a.Head.MsgId = 0U;
      test2_SysIntegration_B.SysDiagMsg_a.Head.OpCode = 0U;
      test2_SysIntegration_B.SysDiagMsg_a.Body.Data = 0U;
      test2_SysIntegration_DW.temp_errTime = 0U;
    } else {
      switch (test2_SysIntegration_DW.bitsForTID4.is_c6_test2_SysIntegration) {
       case test2_SysIntegration_IN_Init:
        test2_SysIntegration_DW.bitsForTID4.is_c6_test2_SysIntegration =
          test2_SysIntegration_IN_LPCtrl;
        test2_SysIntegration_DW.CtrlParam.IO_Off_Delay = 10U;
        test2_SysIntegration_DW.CtrlParam.ChipHibDelay = 3U;
        test2_SysIntegration_DW.CtrlParam.HibDeadZone = 10U;
        test2_SysIntegration_DW.CtrlParam.WakeUpPreFuncSec = 3U;
        test2_SysIntegration_B.LP2RTMsgOut.Head.MsgId = 0U;
        test2_SysIntegration_B.LP2RTMsgOut.Head.OpCode = 0U;
        test2_SysIntegration_B.LP2RTMsgOut.Body.Data = 0U;
        test2_SysIntegration_DW.bitsForTID4.is_LPCtrl =
          test2_SysIntegration_IN_Idle;
        test2_SysIntegration_DW.temporalCounter_i1_d = 0U;
        test2_SysIntegration_DW.WakeUpMode = 0U;
        break;

       case test2_SysIntegration_IN_LPCtrl:
        test2_SysIntegration_LPCtrl_c
          (&test2_SysIntegration_DW.UnitDelay1_DSTATE_d,
           &test2_SysIntegration_DW.UnitDelay_DSTATE_o);
        break;
      }
    }

    if (test2_SysIntegration_DW.LCDCtrlEvtEventCounter > 0U) {
      test2_SysIntegration_B.bitsForTID4.LCDCtrlEvt =
        !test2_SysIntegration_B.bitsForTID4.LCDCtrlEvt;
      test2_SysIntegration_DW.LCDCtrlEvtEventCounter--;
    }

    if (test2_SysIntegration_DW.LPSwitchCtrlEvtEventCounter > 0U) {
      test2_SysIntegration_B.bitsForTID4.LPSwitchCtrlEvt =
        !test2_SysIntegration_B.bitsForTID4.LPSwitchCtrlEvt;
      test2_SysIntegration_DW.LPSwitchCtrlEvtEventCounter--;
    }

    if (test2_SysIntegration_DW.IOSwitchCtrlEvtEventCounter > 0U) {
      test2_SysIntegration_B.bitsForTID4.IOSwitchCtrlEvt =
        !test2_SysIntegration_B.bitsForTID4.IOSwitchCtrlEvt;
      test2_SysIntegration_DW.IOSwitchCtrlEvtEventCounter--;
    }

    /* End of Chart: '<S49>/Chart' */

    /* Logic: '<Root>/Logical Operator' */
    rtb_LogicalOperator = !test2_SysIntegration_B.bitsForTID4.IOSwitchCmd;

    /* Logic: '<Root>/Logical Operator1' */
    test2_SysIntegration_B.bitsForTID4.LogicalOperator1 = !rtb_LogicalOperator;

    /* Chart: '<S43>/Chart' incorporates:
     *  TriggerPort: '<S44>/PushEvent'
     */
    if (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_d == POS_ZCSIG) !=
         (int32_T)test2_SysIntegration_B.bitsForTID4.LCDCtrlEvt) &&
        (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_d != UNINITIALIZED_ZCSIG))
    {
      test2_SysIntegration_B.bitsForTID4.boolLCDStatus =
        test2_SysIntegration_LCDCtrl
        (test2_SysIntegration_B.bitsForTID4.boolLCDOn);
    }

    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_d =
      test2_SysIntegration_B.bitsForTID4.LCDCtrlEvt;
  }

  /* End of RateTransition: '<S42>/Rate Transition2' */

  /* UnitDelay: '<Root>/Unit Delay1' */
  zcEvent_idx_0 = test2_SysIntegration_DW.bitsForTID0.UnitDelay1_DSTATE_k;
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[2] == 0) {
    /* Chart: '<S67>/Taskwith10msSamplingTime' incorporates:
     *  Constant: '<S67>/BattCapUintmAmS'
     *  Constant: '<S67>/BattVoltLUTUnitmV'
     *  UnitDelay: '<Root>/Unit Delay1'
     */
    if (test2_SysIntegration_DW.temporalCounter_i1_e < MAX_uint32_T) {
      test2_SysIntegration_DW.temporalCounter_i1_e++;
    }

    if (test2_SysIntegration_DW.temporalCounter_i2_f < 511U) {
      test2_SysIntegration_DW.temporalCounter_i2_f++;
    }

    if (test2_SysIntegration_DW.bitsForTID2.is_active_c40_test2_SysIntegrat ==
        0U) {
      test2_SysIntegration_DW.bitsForTID2.is_active_c40_test2_SysIntegrat = 1;
      test2_SysIntegration_DW.bitsForTID2.is_c40_test2_SysIntegration =
        test2_SysIntegration_IN_Init_a;
      test2_SysIntegration_DW.temporalCounter_i1_e = 0U;
      test2_SysIntegration_B.SysDiagMsgOut_k.Head.MsgId = 0U;
      test2_SysIntegration_B.SysDiagMsgOut_k.Head.OpCode = 1U;
      test2_SysIntegration_B.SysDiagMsgOut_k.Body.Data = 0U;
      test2_SysIntegration_B.SlaveMCUADCInquiryMsg =
        test2_SysIntegration_B.SysDiagMsgOut_k;
      test2_SysIntegration_DW.BattCurInteg = MAX_uint32_T;
      test2_SysIntegration_DW.bitsForTID2.boolSerialPortReliable = false;
      test2_SysIntegration_DW.SlaveInfoInquiryRetryTimes = 0U;
      test2_SysIntegration_DW.BattEQMinuteConsumption = 0U;
    } else {
      switch (test2_SysIntegration_DW.bitsForTID2.is_c40_test2_SysIntegration) {
       case test2_SysInt_IN_BattEQEstimator:
        test2_SysIntegr_BattEQEstimator(&zcEvent_idx_0);
        break;

       case IN_CalibraBattInitLevelByCurren:
        if (test2_SysIntegration_DW.temporalCounter_i1_e >= 6000U) {
          test2_SysIntegration_DW.bitsForTID2.boolHappenMark = false;
          test2_SysIntegration_DW.bitsForTID2.is_BattPowerAlarmManagement = 0;
          if (test2_SysIntegration_DW.bitsForTID2.is_BattEQEst ==
              test2_SysIntegrati_IN_BattEQEst) {
            test2_SysIntegration_B.rtCurrent = (uint16_T)roundf((real32_T)
              (int16_T)(test2_SysIntegration_B.MajorSensorOutp.Ch2 +
                        test2_SysIntegration_B.VarSet.Calibra.MajorMCU4ChADCOffset
                        [1]) / 1.0E+6F * (real32_T)
              test2_SysIntegration_B.VarSet.Calibra.MajorMcu4ChADCResolution[1]);
            test2_SysIntegration_B.rtmAMotorCurrent = (uint16_T)roundf((real32_T)
              (int16_T)(test2_SysIntegration_B.MajorSensorOutp.Ch3 +
                        test2_SysIntegration_B.VarSet.Calibra.MajorMCU4ChADCOffset
                        [2]) / 1.0E+6F * (real32_T)
              test2_SysIntegration_B.VarSet.Calibra.MajorMcu4ChADCResolution[1]);
            test2_SysIntegration_DW.BattCurInteg +=
              test2_SysIntegration_B.rtCurrent * 10U;
            test2_SysIntegration_B.BattEQ = test2_SysIntegration_BattEQEst
              (test2_SysIntegration_DW.BattVolt,
               test2_SysIntegration_ConstP.BattVoltLUTUnitmV_Value,
               test2_SysIntegration_DW.BattCurInteg, 1.152E+9F);
            test2_SysIntegration_DW.bitsForTID2.is_BattEQEst = 0;
          } else {
            test2_SysIntegration_DW.bitsForTID2.is_BattEQEst = 0;
          }

          test2_SysIntegration_DW.bitsForTID2.is_c40_test2_SysIntegration =
            IN_CalibraBattInitLevelByCurren;
          test2_SysIntegration_DW.temporalCounter_i1_e = 0U;
          test2_SysIntegration_DW.bitsForTID2.is_BattEQEst =
            test2_SysIntegrati_IN_BattEQEst;
          test2_SysIntegration_B.rtCurrent = (uint16_T)roundf((real32_T)(int16_T)
            (test2_SysIntegration_B.MajorSensorOutp.Ch2 +
             test2_SysIntegration_B.VarSet.Calibra.MajorMCU4ChADCOffset[1]) /
            1.0E+6F * (real32_T)
            test2_SysIntegration_B.VarSet.Calibra.MajorMcu4ChADCResolution[1]);
          test2_SysIntegration_B.rtmAMotorCurrent = (uint16_T)roundf((real32_T)
            (int16_T)(test2_SysIntegration_B.MajorSensorOutp.Ch3 +
                      test2_SysIntegration_B.VarSet.Calibra.MajorMCU4ChADCOffset[
                      2]) / 1.0E+6F * (real32_T)
            test2_SysIntegration_B.VarSet.Calibra.MajorMcu4ChADCResolution[1]);
          test2_SysIntegration_DW.BattCurInteg +=
            test2_SysIntegration_B.rtCurrent * 10U;
          test2_SysIntegration_B.BattEQ = test2_SysIntegration_BattEQEst
            (test2_SysIntegration_DW.BattVolt,
             test2_SysIntegration_ConstP.BattVoltLUTUnitmV_Value,
             test2_SysIntegration_DW.BattCurInteg, 1.152E+9F);
          test2_SysIntegration_DW.bitsForTID2.is_BattPowerAlarmManagement =
            test2_SysIntegration_IN_Normal;
        } else {
          if (test2_SysIntegration_DW.bitsForTID2.is_BattEQEst ==
              test2_SysIntegrati_IN_BattEQEst) {
            zcEvent_idx_0 =
              ((!test2_SysIntegration_DW.bitsForTID2.boolHappenMark) &&
               test2_SysIntegration_B.bitsForTID4.Wait4LPFinish &&
               (test2_SysIntegration_B.rtCurrent >
                test2__LowPowerModeCurrentThVal));
            if (zcEvent_idx_0) {
              test2_SysIntegration_B.rtCurrent = (uint16_T)roundf((real32_T)
                (int16_T)(test2_SysIntegration_B.MajorSensorOutp.Ch2 +
                          test2_SysIntegration_B.VarSet.Calibra.MajorMCU4ChADCOffset
                          [1]) / 1.0E+6F * (real32_T)
                test2_SysIntegration_B.VarSet.Calibra.MajorMcu4ChADCResolution[1]);
              test2_SysIntegration_B.rtmAMotorCurrent = (uint16_T)roundf
                ((real32_T)(int16_T)(test2_SysIntegration_B.MajorSensorOutp.Ch3
                  + test2_SysIntegration_B.VarSet.Calibra.MajorMCU4ChADCOffset[2])
                 / 1.0E+6F * (real32_T)
                 test2_SysIntegration_B.VarSet.Calibra.MajorMcu4ChADCResolution
                 [1]);
              test2_SysIntegration_DW.BattCurInteg +=
                test2_SysIntegration_B.rtCurrent * 10U;
              test2_SysIntegration_B.BattEQ = test2_SysIntegration_BattEQEst
                (test2_SysIntegration_DW.BattVolt,
                 test2_SysIntegration_ConstP.BattVoltLUTUnitmV_Value,
                 test2_SysIntegration_DW.BattCurInteg, 1.152E+9F);
              test2_SysIntegration_DW.bitsForTID2.is_BattEQEst =
                test_IN_LowPowerIOSwitchFailure;
              test2_SysIntegration_DW.bitsForTID2.boolHappenMark = true;
              test2_SysIntegration_B.SysDiagMsgOut_k.Head.MsgId = (uint8_T)
                ((uint8_T)(test2_SysIntegration_B.SysDiagMsgOut_k.Head.MsgId +
                           1U) % MAX_uint8_T);
              test2_SysIntegration_B.SysDiagMsgOut_k.Head.OpCode = 1U;
              test2_SysIntegration_B.SysDiagMsgOut_k.Body.Data = 101U;
            } else {
              test2_SysIntegration_B.rtCurrent = (uint16_T)roundf((real32_T)
                (int16_T)(test2_SysIntegration_B.MajorSensorOutp.Ch2 +
                          test2_SysIntegration_B.VarSet.Calibra.MajorMCU4ChADCOffset
                          [1]) / 1.0E+6F * (real32_T)
                test2_SysIntegration_B.VarSet.Calibra.MajorMcu4ChADCResolution[1]);
              test2_SysIntegration_B.rtmAMotorCurrent = (uint16_T)roundf
                ((real32_T)(int16_T)(test2_SysIntegration_B.MajorSensorOutp.Ch3
                  + test2_SysIntegration_B.VarSet.Calibra.MajorMCU4ChADCOffset[2])
                 / 1.0E+6F * (real32_T)
                 test2_SysIntegration_B.VarSet.Calibra.MajorMcu4ChADCResolution
                 [1]);
              test2_SysIntegration_DW.BattCurInteg +=
                test2_SysIntegration_B.rtCurrent * 10U;
              test2_SysIntegration_B.BattEQ = test2_SysIntegration_BattEQEst
                (test2_SysIntegration_DW.BattVolt,
                 test2_SysIntegration_ConstP.BattVoltLUTUnitmV_Value,
                 test2_SysIntegration_DW.BattCurInteg, 1.152E+9F);
            }
          } else {
            test2_SysIntegration_DW.bitsForTID2.is_BattEQEst =
              test2_SysIntegrati_IN_BattEQEst;
            test2_SysIntegration_B.rtCurrent = (uint16_T)roundf((real32_T)
              (int16_T)(test2_SysIntegration_B.MajorSensorOutp.Ch2 +
                        test2_SysIntegration_B.VarSet.Calibra.MajorMCU4ChADCOffset
                        [1]) / 1.0E+6F * (real32_T)
              test2_SysIntegration_B.VarSet.Calibra.MajorMcu4ChADCResolution[1]);
            test2_SysIntegration_B.rtmAMotorCurrent = (uint16_T)roundf((real32_T)
              (int16_T)(test2_SysIntegration_B.MajorSensorOutp.Ch3 +
                        test2_SysIntegration_B.VarSet.Calibra.MajorMCU4ChADCOffset
                        [2]) / 1.0E+6F * (real32_T)
              test2_SysIntegration_B.VarSet.Calibra.MajorMcu4ChADCResolution[1]);
            test2_SysIntegration_DW.BattCurInteg +=
              test2_SysIntegration_B.rtCurrent * 10U;
            test2_SysIntegration_B.BattEQ = test2_SysIntegration_BattEQEst
              (test2_SysIntegration_DW.BattVolt,
               test2_SysIntegration_ConstP.BattVoltLUTUnitmV_Value,
               test2_SysIntegration_DW.BattCurInteg, 1.152E+9F);
          }

          switch
            (test2_SysIntegration_DW.bitsForTID2.is_BattPowerAlarmManagement) {
           case test2_IN_BattPowerLowLevelAlarm:
           case test2_IN_BattPowerMidLevelAlarm:
            break;

           default:
            if ((test2_SysIntegration_B.BattEQ > 5) &&
                (test2_SysIntegration_B.BattEQ < 10)) {
              test2_SysIntegration_DW.bitsForTID2.is_BattPowerAlarmManagement =
                test2_IN_BattPowerLowLevelAlarm;
              test2_SysIntegration_B.SysDiagMsgOut_k.Head.MsgId = (uint8_T)
                ((uint8_T)(test2_SysIntegration_B.SysDiagMsgOut_k.Head.MsgId +
                           1U) % MAX_uint8_T);
              test2_SysIntegration_B.SysDiagMsgOut_k.Head.OpCode = 1U;
              test2_SysIntegration_B.SysDiagMsgOut_k.Body.Data = 201U;
            } else {
              if (test2_SysIntegration_B.BattEQ <= 5) {
                test2_SysIntegration_DW.bitsForTID2.is_BattPowerAlarmManagement =
                  test2_IN_BattPowerMidLevelAlarm;
                test2_SysIntegration_B.SysDiagMsgOut_k.Head.MsgId = (uint8_T)
                  ((uint8_T)(test2_SysIntegration_B.SysDiagMsgOut_k.Head.MsgId +
                             1U) % MAX_uint8_T);
                test2_SysIntegration_B.SysDiagMsgOut_k.Head.OpCode = 1U;
                test2_SysIntegration_B.SysDiagMsgOut_k.Body.Data = 102U;
              }
            }
            break;
          }
        }
        break;

       default:
        if (test2_SysIntegration_DW.temporalCounter_i1_e >= 200U) {
          test2_SysIntegration_DW.bitsForTID2.is_c40_test2_SysIntegration =
            test2_SysInt_IN_BattEQEstimator;
          test2_SysIntegration_DW.temporalCounter_i1_e = 0U;
          test2_SysIntegration_B.rtmAMotorCurrent = (uint16_T)roundf((real32_T)
            (int16_T)(test2_SysIntegration_B.MajorSensorOutp.Ch3 +
                      test2_SysIntegration_B.VarSet.Calibra.MajorMCU4ChADCOffset[
                      2]) / 1.0E+6F * (real32_T)
            test2_SysIntegration_B.VarSet.Calibra.MajorMcu4ChADCResolution[1]);
          test2_SysIntegration_DW.BattEQMinuteConsumption =
            ((test2_SysIn_FuzzyLogicBGCurrent *
              test2_SysIntegration_B.bitsForTID4.LogicalOperator1 * 10 +
              test2_SysIntegration_DW.BattEQMinuteConsumption) +
             test2_SysI_FuzzyLogicLCDCurrent *
             test2_SysIntegration_B.bitsForTID4.boolLCDStatus * 10) +
            test2_Sy_FuzzyLogicMotorCurrent *
            test2_SysIntegration_DW.bitsForTID0.UnitDelay1_DSTATE_k * 10;
          test2_SysIntegration_DW.bitsForTID2.is_BattEQEstimator =
            test2_SysInt_IN_AskforSlaveInfo;
          test2_SysIntegration_DW.temporalCounter_i2_f = 0U;
          test2_SysIntegration_B.SlaveMCUADCInquiryMsg.Head.MsgId = (uint8_T)
            ((uint8_T)(test2_SysIntegration_B.SlaveMCUADCInquiryMsg.Head.MsgId +
                       1U) % MAX_uint8_T);
          test2_SysIntegration_B.SlaveMCUADCInquiryMsg.Head.OpCode = 1U;
          test2_SysIntegration_DW.prevSensorMsgId = 0U;
          test2_SysIntegration_DW.MasterBattVoltADC = (int16_T)
            (test2_SysIntegration_B.MajorSensorOutp.Ch1 +
             test2_SysIntegration_B.VarSet.Calibra.MajorMCU4ChADCOffset[0]);
        }
        break;
      }
    }

    /* End of Chart: '<S67>/Taskwith10msSamplingTime' */
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    /* Chart: '<S55>/Chart1' */
    if (test2_SysIntegration_DW.bitsForTID4.is_active_c35_test2_SysIntegrat ==
        0U) {
      test2_SysIntegration_DW.bitsForTID4.is_active_c35_test2_SysIntegrat = 1;
      test2_SysIntegration_DW.bitsForTID4.is_c35_test2_SysIntegration =
        test2_SysIntegration_IN_Idle_k;
    } else if (test2_SysIntegration_DW.bitsForTID4.is_c35_test2_SysIntegration ==
               test2_SysIntegration_IN_Idle_k) {
      if (test2_SysIntegration_B.bitsForTID4.boolHomingOn) {
        test2_SysIntegration_DW.bitsForTID4.is_c35_test2_SysIntegration =
          test2_SysIntegration_IN_Op_h;
        test2_SysIntegration_DW.HomingStartEvtEventCounter++;
      }
    } else {
      if (!test2_SysIntegration_B.bitsForTID4.boolHomingOn) {
        test2_SysIntegration_DW.HomingStopEvtEventCounter++;
        test2_SysIntegration_DW.bitsForTID4.is_c35_test2_SysIntegration =
          test2_SysIntegration_IN_Idle_k;
      }
    }

    if (test2_SysIntegration_DW.HomingStartEvtEventCounter > 0U) {
      test2_SysIntegration_B.bitsForTID4.HomingStartEvt =
        !test2_SysIntegration_B.bitsForTID4.HomingStartEvt;
      test2_SysIntegration_DW.HomingStartEvtEventCounter--;
    }

    if (test2_SysIntegration_DW.HomingStopEvtEventCounter > 0U) {
      test2_SysIntegration_B.bitsForTID4.HomingStopEvt =
        !test2_SysIntegration_B.bitsForTID4.HomingStopEvt;
      test2_SysIntegration_DW.HomingStopEvtEventCounter--;
    }

    /* End of Chart: '<S55>/Chart1' */
  }

  /* DiscretePulseGenerator: '<S94>/Pulse Generator' */
  i = ((test2_SysIntegration_DW.clockTickCounter_i < 5) &&
       (test2_SysIntegration_DW.clockTickCounter_i >= 0));
  if (test2_SysIntegration_DW.clockTickCounter_i >= 9) {
    test2_SysIntegration_DW.clockTickCounter_i = 0;
  } else {
    test2_SysIntegration_DW.clockTickCounter_i++;
  }

  /* End of DiscretePulseGenerator: '<S94>/Pulse Generator' */

  /* SignalConversion: '<S94>/HiddenBuf_InsertedFor_Chart_at_inport_4' incorporates:
   *  DataTypeConversion: '<S94>/Data Type Conversion'
   */
  rtb_HiddenBuf_InsertedFor_Cha_0 = (i != 0);

  /* Chart: '<S94>/Chart' incorporates:
   *  TriggerPort: '<S95>/input events'
   */
  rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_g4[0] ==
                       POS_ZCSIG) != (int32_T)
                      test2_SysIntegration_B.bitsForTID4.HomingStartEvt) &&
                     (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_g4[0] !=
                      UNINITIALIZED_ZCSIG));
  d_tf = rtb_PopAlarmEvt;
  zcEvent_idx_0 = rtb_PopAlarmEvt;

  /* SignalConversion: '<S94>/HiddenBuf_InsertedFor_Chart_at_inport_4' */
  rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_g4[1] ==
                       POS_ZCSIG) != (int32_T)
                      test2_SysIntegration_B.bitsForTID4.HomingStopEvt) &&
                     (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_g4[1] !=
                      UNINITIALIZED_ZCSIG));
  d_tf = (d_tf || rtb_PopAlarmEvt);
  zcEvent_idx_1 = rtb_PopAlarmEvt;
  rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_g4[2] ==
                       POS_ZCSIG) != (int32_T)rtb_HiddenBuf_InsertedFor_Cha_0) &&
                     (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_g4[2] !=
                      UNINITIALIZED_ZCSIG));
  d_tf = (d_tf || rtb_PopAlarmEvt);
  if (d_tf) {
    i = 0;

    /* SignalConversion: '<S94>/HiddenBuf_InsertedFor_Chart_at_inport_4' */
    if ((int8_T)(zcEvent_idx_0 ?
                 test2_SysIntegration_B.bitsForTID4.HomingStartEvt ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      i = 1;
      sfEvent_h = test2_SysI_event_HomingStartEvt;
      chartstep_c23_test2_SysIntegrat
        (&test2_SysIntegration_DW.UnitDelay_DSTATE_oz, &sfEvent_h);
    }

    if ((int8_T)(zcEvent_idx_1 ?
                 test2_SysIntegration_B.bitsForTID4.HomingStopEvt ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      i = 1;
      sfEvent_h = test2_SysIn_event_HomingStopEvt;
      chartstep_c23_test2_SysIntegrat
        (&test2_SysIntegration_DW.UnitDelay_DSTATE_oz, &sfEvent_h);
    }

    if ((int8_T)(rtb_PopAlarmEvt ? rtb_HiddenBuf_InsertedFor_Cha_0 ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      i = 1;
      if (test2_SysIntegration_DW.temporalCounter_i1_m < MAX_uint32_T) {
        test2_SysIntegration_DW.temporalCounter_i1_m++;
      }

      if (test2_SysIntegration_DW.temporalCounter_i2_d < 511U) {
        test2_SysIntegration_DW.temporalCounter_i2_d++;
      }

      sfEvent_h = test2_SysIntegr_event_UpdateEvt;
      chartstep_c23_test2_SysIntegrat
        (&test2_SysIntegration_DW.UnitDelay_DSTATE_oz, &sfEvent_h);
    }

    if ((i != 0) && (test2_SysIntegration_DW.boolHomingEvtEventCounter > 0U)) {
      test2_SysIntegration_B.bitsForTID0.boolHomingEvt =
        !test2_SysIntegration_B.bitsForTID0.boolHomingEvt;
      test2_SysIntegration_DW.boolHomingEvtEventCounter--;
    }
  }

  /* SignalConversion: '<S94>/HiddenBuf_InsertedFor_Chart_at_inport_4' */
  test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_g4[0] =
    test2_SysIntegration_B.bitsForTID4.HomingStartEvt;
  test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_g4[1] =
    test2_SysIntegration_B.bitsForTID4.HomingStopEvt;
  test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_g4[2] =
    rtb_HiddenBuf_InsertedFor_Cha_0;
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[5] == 0) {
    /* Chart: '<Root>/MsgRouter2' */
    test2_SysIntegration_MsgRouter1(&test2_SysIntegration_B.ErrDiagMsg,
      &test2_SysIntegration_B.ErrMsg,
      &test2_SysIntegration_B.Group1AlarmMsgOut_f,
      &test2_SysIntegration_DW.sf_MsgRouter2);

    /* Chart: '<Root>/MsgRouter1' */
    test2_SysIntegration_MsgRouter1(&test2_SysIntegration_B.KeyAlarmMsg,
      &test2_SysIntegration_B.PCAAlarmMsg,
      &test2_SysIntegration_B.Group1AlarmMsgOut_h,
      &test2_SysIntegration_DW.sf_MsgRouter1);
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[7] == 0) {
    /* Chart: '<S123>/RTMsgRuter' incorporates:
     *  UnitDelay: '<S123>/Unit Delay'
     *  UnitDelay: '<S123>/Unit Delay1'
     */
    if (test2_SysIntegration_DW.bitsForTID7.is_active_c4_test2_SysIntegrati ==
        0U) {
      test2_SysIntegration_DW.bitsForTID7.is_active_c4_test2_SysIntegrati = 1;
      test2_SysIntegration_B.RTTimerSetMsgOut.Head.MsgId = 0U;
      test2_SysIntegration_B.RTTimerSetMsgOut.Head.OpCode = 0U;
      for (i = 0; i < 6; i++) {
        d_0.Time[i] = 0U;
      }

      test2_SysIntegration_B.RTTimerSetMsgOut.Body = d_0;
      test2_SysIntegration_B.RTChipDiagMsg.Head.MsgId = 0U;
      test2_SysIntegration_B.RTChipDiagMsg.Head.OpCode = 0U;
      test2_SysIntegration_B.RTChipDiagMsg.Body.Data = 0U;
    } else if (test2_SysIntegration_DW.prevMsgIn1Id !=
               test2_SysIntegration_B.RTTimeMsgOut.Head.MsgId) {
      test2_SysIntegration_DW.prevMsgIn1Id =
        test2_SysIntegration_B.RTTimeMsgOut.Head.MsgId;
      i = (int32_T)(test2_SysIntegration_B.RTTimerSetMsgOut.Head.MsgId + 1U);
      if ((uint32_T)i > 255U) {
        i = 255;
      }

      test2_SysIntegration_B.RTTimerSetMsgOut.Head.MsgId = (uint8_T)((uint8_T)i %
        MAX_uint8_T);
      test2_SysIntegration_B.RTTimerSetMsgOut.Head.OpCode =
        test2_SysIntegration_B.RTTimeMsgOut.Head.OpCode;
      test2_SysIntegration_B.RTTimerSetMsgOut.Body =
        test2_SysIntegration_B.RTTimeMsgOut.Body;
      test2_SysIntegration_DW.RTChipWriteEvtEventCounter++;
    } else if (test2_SysIntegration_DW.prevMsgIn2Id != 0) {
      test2_SysIntegration_DW.prevMsgIn2Id = 0U;
      i = (int32_T)(test2_SysIntegration_B.RTTimerSetMsgOut.Head.MsgId + 1U);
      if ((uint32_T)i > 255U) {
        i = 255;
      }

      test2_SysIntegration_B.RTTimerSetMsgOut.Head.MsgId = (uint8_T)((uint8_T)i %
        MAX_uint8_T);
      test2_SysIntegration_B.RTTimerSetMsgOut.Head.OpCode = 0U;
      test2_SysIntegration_B.RTTimerSetMsgOut.Body =
        test2_SysIntegration_rtZtype_RecordCtrl2RTCtrlMsg.Body;
      test2_SysIntegration_DW.RTChipWriteEvtEventCounter++;
    } else {
      if (test2_SysIntegration_DW.prevMsgIn3Id !=
          test2_SysIntegration_DW.UnitDelay1_DSTATE_dc.Head.MsgId) {
        test2_SysIntegration_DW.prevMsgIn3Id =
          test2_SysIntegration_DW.UnitDelay1_DSTATE_dc.Head.MsgId;
        test_RTChipMsgSubscribeCallback
          (test2_SysIntegration_DW.bitsForTID7.UnitDelay_DSTATE_b2,
           &test2_SysIntegration_B.RTTimerSetMsgOut,
           &test2_SysIntegration_B.RTChipDiagMsg,
           test2_SysIntegration_DW.UnitDelay1_DSTATE_dc);
      }
    }

    if (test2_SysIntegration_DW.RTChipWriteEvtEventCounter > 0U) {
      test2_SysIntegration_B.bitsForTID7.RTChipWriteEvt =
        !test2_SysIntegration_B.bitsForTID7.RTChipWriteEvt;
      test2_SysIntegration_DW.RTChipWriteEvtEventCounter--;
    }

    /* End of Chart: '<S123>/RTMsgRuter' */
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[5] == 0) {
    /* Chart: '<Root>/MsgRouter3' */
    test2_SysIntegration_MsgRouter1(&test2_SysIntegration_B.SysDiagMsgOut_d,
      &test2_SysIntegration_B.RTChipDiagMsg,
      &test2_SysIntegration_B.Group1AlarmMsgOut_b,
      &test2_SysIntegration_DW.sf_MsgRouter3);
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[7] == 0) {
    /* UnitDelay: '<Root>/Unit Delay' */
    test2_SysIntegration_B.UnitDelay_p =
      test2_SysIntegration_DW.UnitDelay_DSTATE_h;
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[5] == 0) {
    /* Chart: '<S17>/MsgRouter2' */
    test2_SysIntegration_MsgRouter1
      (&test2_SysIntegration_B.RelativeTimerApplyMsg,
       &test2_SysIntegration_B.UnitDelay_p,
       &test2_SysIntegration_B.Group1AlarmMsgOut,
       &test2_SysIntegration_DW.sf_MsgRouter2_n);
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[1] == 0) {
    /* UnitDelay: '<S21>/Unit Delay1' */
    test2_SysIntegration_B.UnitDelay1_c =
      test2_SysIntegration_DW.UnitDelay1_DSTATE_o;
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[7] == 0) {
    /* Chart: '<S126>/Chart' */
    if (test2_SysIntegration_DW.temporalCounter_i1_mw < 7U) {
      test2_SysIntegration_DW.temporalCounter_i1_mw++;
    }

    if (test2_SysIntegration_DW.bitsForTID7.is_active_c5_test2_SysIntegrati ==
        0U) {
      test2_SysIntegration_DW.bitsForTID7.is_active_c5_test2_SysIntegrati = 1;
      for (i = 0; i < 6; i++) {
        test2_SysIntegration_B.RTTimeMsgOut_h.Time[i] = 0U;
      }

      test2_SysIntegration_DW.prevRecordCtrlMsgId =
        test2_SysIntegration_B.RTTimerSetMsgOut.Head.MsgId;
      test2_SysIntegration_DW.prevLowPowerMsgId =
        test2_SysIntegration_B.UnitDelay_f.Head.MsgId;
      test2_SysIntegration_DW.prevRelativeTimerApplyMsgId =
        test2_SysIntegration_B.Group1AlarmMsgOut.Head.MsgId;
      test2_SysIntegration_DW.prevSysDiagMsgId =
        test2_SysIntegration_B.UnitDelay1_c.Head.MsgId;
      test2_SysIntegration_DW.bitsForTID7.is_RTCtrl =
        test2_SysIntegration_IN_Idle_k;
      test2_SysIntegration_DW.temporalCounter_i1_mw = 0U;
      test2_SysIntegration_DW.InitTimerEvtEventCounter++;
    } else {
      if (test2_SysIntegration_B.RTTimerSetMsgOut.Head.MsgId !=
          test2_SysIntegration_DW.prevRecordCtrlMsgId) {
        test2_SysIntegration_DW.bitsForTID7.TimeSetSwitch1 =
          (test2_SysIntegration_B.RTTimerSetMsgOut.Head.OpCode != 0);
        test2_SysIntegration_DW.prevRecordCtrlMsgId =
          test2_SysIntegration_B.RTTimerSetMsgOut.Head.MsgId;
      } else if (test2_SysIntegration_B.UnitDelay_f.Head.MsgId !=
                 test2_SysIntegration_DW.prevLowPowerMsgId) {
        test2_SysIntegration_DW.bitsForTID7.TimeSetSwitch2 =
          (test2_SysIntegration_B.UnitDelay_f.Head.OpCode != 0);
        test2_SysIntegration_DW.prevLowPowerMsgId =
          test2_SysIntegration_B.UnitDelay_f.Head.MsgId;
      } else if (test2_SysIntegration_B.Group1AlarmMsgOut.Head.MsgId !=
                 test2_SysIntegration_DW.prevRelativeTimerApplyMsgId) {
        test2_SysIntegration_DW.LargeDoseTimerOpMode =
          test2_SysIntegration_B.Group1AlarmMsgOut.Head.OpCode;
        test2_SysIntegration_DW.LargeDoseTimerOpDt =
          test2_SysIntegration_B.Group1AlarmMsgOut.Body.Data;
        test2_SysIntegration_DW.prevRelativeTimerApplyMsgId =
          test2_SysIntegration_B.Group1AlarmMsgOut.Head.MsgId;
      } else {
        if (test2_SysIntegration_B.UnitDelay1_c.Head.MsgId !=
            test2_SysIntegration_DW.prevSysDiagMsgId) {
          test2_SysIntegration_DW.prevSysDiagMsgId =
            test2_SysIntegration_B.UnitDelay1_c.Head.MsgId;
          switch (test2_SysIntegration_B.UnitDelay1_c.Head.OpCode) {
           case 0:
            test2_SysIntegration_B.bitsForTID7.boolAbsTimeHold = false;
            test2_SysIntegration_B.bitsForTID7.boolRelativeTimerHold = false;
            break;

           case 1:
            test2_SysIntegration_B.bitsForTID7.boolAbsTimeHold = true;
            test2_SysIntegration_B.bitsForTID7.boolRelativeTimerHold = true;
            break;

           case 2:
            test2_SysIntegration_B.bitsForTID7.boolAbsTimeHold = false;
            break;

           case 3:
            test2_SysIntegration_B.bitsForTID7.boolRelativeTimerHold = false;
            break;
          }
        }
      }

      if (test2_SysIntegration_DW.bitsForTID7.is_RTCtrl ==
          test2_SysIntegration_IN_Idle_k) {
        if (test2_SysIntegration_DW.bitsForTID7.TimeSetSwitch1) {
          test2_SysIntegration_B.boolSysEnable = true;
          test2_SysIntegration_DW.bitsForTID7.is_RTCtrl =
            test2_SysIntegration_IN_Op_h;
          test2_SysIntegr_enter_atomic_Op();
        } else {
          if ((test2_SysIntegration_DW.temporalCounter_i1_mw >= 3U) &&
              (test2_SysIntegration_DW.tryTime < 5)) {
            i = (int32_T)(test2_SysIntegration_DW.tryTime + 1U);
            if ((uint32_T)i > 255U) {
              i = 255;
            }

            test2_SysIntegration_DW.tryTime = (uint8_T)i;
            test2_SysIntegration_DW.bitsForTID7.is_RTCtrl =
              test2_SysIntegration_IN_Idle_k;
            test2_SysIntegration_DW.temporalCounter_i1_mw = 0U;
            test2_SysIntegration_DW.InitTimerEvtEventCounter++;
          }
        }
      } else {
        zcEvent_idx_0 = (test2_SysIntegration_DW.bitsForTID7.TimeSetSwitch1 ||
                         test2_SysIntegration_DW.bitsForTID7.TimeSetSwitch2);
        if (zcEvent_idx_0) {
          test2_SysIntegration_DW.bitsForTID7.is_RTCtrl =
            test2_SysIntegration_IN_Op_h;
          test2_SysIntegr_enter_atomic_Op();
        } else {
          elapsedTicks_d = test2_SysIntegration_DW.TotalmSecond + /*MW:OvSatOk*/
            1000U;
          if (elapsedTicks_d < test2_SysIntegration_DW.TotalmSecond) {
            elapsedTicks_d = MAX_uint32_T;
          }

          test2_SysIntegration_DW.TotalmSecond = elapsedTicks_d;
          test2_SysInte_UpdateDateAndTime(test2_SysIntegration_DW.prevYearInfo,
            test2_SysIntegration_DW.prevMonthInfo,
            test2_SysIntegration_DW.prevDayInfo,
            test2_SysIntegration_DW.TotalmSecond,
            &test2_SysIntegration_B.RTTimeMsgOut_h, &tmp_7, &LogAvailableFlag,
            &tmp_8, &tmp_6);
          test2_SysIntegration_DW.TotalmSecond = tmp_6;
          test2_SysIntegration_DW.prevDayInfo = tmp_8;
          test2_SysIntegration_DW.prevMonthInfo = LogAvailableFlag;
          test2_SysIntegration_DW.prevYearInfo = tmp_7;
          elapsedTicks_d = (uint32_T)test2_SysIntegration_B.LargeDoseRelativeSec
            + test2_SysIntegration_DW.LargeDoseTimerOpDt;
          if (elapsedTicks_d > 65535U) {
            elapsedTicks_d = 65535U;
          }

          elapsedTicks_d *= test2_SysIntegration_DW.LargeDoseTimerOpMode;
          if (elapsedTicks_d > 65535U) {
            elapsedTicks_d = 65535U;
          }

          test2_SysIntegration_B.LargeDoseRelativeSec = (uint16_T)elapsedTicks_d;
        }
      }
    }

    if (test2_SysIntegration_DW.InitTimerEvtEventCounter > 0U) {
      test2_SysIntegration_B.bitsForTID7.InitTimerEvt =
        !test2_SysIntegration_B.bitsForTID7.InitTimerEvt;
      test2_SysIntegration_DW.InitTimerEvtEventCounter--;
    }

    /* End of Chart: '<S126>/Chart' */

    /* Outputs for Enabled SubSystem: '<S126>/AbsoluteTimeHold1' incorporates:
     *  EnablePort: '<S128>/Enable'
     */
    /* S-Function (sfix_bitop): '<S126>/Bitwise NOT1' incorporates:
     *  Inport: '<S128>/In1'
     */
    if (!test2_SysIntegration_B.bitsForTID7.boolRelativeTimerHold) {
      test2_SysIntegration_B.In1_f = test2_SysIntegration_B.LargeDoseRelativeSec;
    }

    /* End of S-Function (sfix_bitop): '<S126>/Bitwise NOT1' */
    /* End of Outputs for SubSystem: '<S126>/AbsoluteTimeHold1' */
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    /* UnitDelay: '<S87>/Unit Delay' */
    zcEvent_idx_0 = test2_SysIntegration_DW.bitsForTID4.UnitDelay_DSTATE_o0;

    /* Chart: '<S87>/Chart' */
    if (test2_SysIntegration_DW.temporalCounter_i1_ob < 127U) {
      test2_SysIntegration_DW.temporalCounter_i1_ob++;
    }

    if (test2_SysIntegration_DW.bitsForTID4.is_active_c16_test2_SysIntegrat ==
        0U) {
      test2_SysIntegration_DW.bitsForTID4.is_active_c16_test2_SysIntegrat = 1;
      test2_SysIntegration_B.MotionStopACKMsg.Head.MsgId = 0U;
      test2_SysIntegration_B.MotionStopACKMsg.Head.OpCode = 0U;
      test2_SysIntegration_B.MotionStopACKMsg.Body.Data = 0U;
      test2_SysIntegration_DW.bitsForTID4.is_ActuatorController =
        test2_SysIntegration_IN_Idle;
      test2_SysIntegration_B.bitsForTID4.boolDoseCtrlBusy = false;
      test2_SysIntegration_DW.bitsForTID4.is_Idle =
        test2_SysIntegration_IN_Idle_k;
      test2_SysIntegration_DW.bitsForTID4.boolEnterActuatorBusy = false;
      test2_SysIntegration_B.targetEncCnt = 0;
    } else {
      test2_SysInt_ActuatorController
        (&test2_SysIntegration_DW.UnitDelay2_DSTATE_pc,
         &test2_SysIntegration_DW.UnitDelay2_DSTATE_f, &zcEvent_idx_0);
    }

    if (test2_SysIntegration_DW.ServoOnEvtEventCounter > 0U) {
      test2_SysIntegration_B.bitsForTID4.ServoOnEvt =
        !test2_SysIntegration_B.bitsForTID4.ServoOnEvt;
      test2_SysIntegration_DW.ServoOnEvtEventCounter--;
    }

    if (test2_SysIntegration_DW.ForceStopEvtEventCounter > 0U) {
      test2_SysIntegration_B.bitsForTID4.ForceStopEvt =
        !test2_SysIntegration_B.bitsForTID4.ForceStopEvt;
      test2_SysIntegration_DW.ForceStopEvtEventCounter--;
    }

    if (test2_SysIntegration_DW.PopBufEvtEventCounter > 0U) {
      test2_SysIntegration_B.bitsForTID4.PopBufEvt =
        !test2_SysIntegration_B.bitsForTID4.PopBufEvt;
      test2_SysIntegration_DW.PopBufEvtEventCounter--;
    }

    /* End of Chart: '<S87>/Chart' */
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[7] == 0) {
    /* Chart: '<S106>/TaskScheduler' */
    elapsedTicks_d = test2_SysIntegration_M->Timing.clockTick7 -
      test2_SysIntegration_DW.previousTicks_m;
    test2_SysIntegration_DW.previousTicks_m =
      test2_SysIntegration_M->Timing.clockTick7;
    test2_SysIntegration_DW.temporalCounter_i1 += elapsedTicks_d;
    if (test2_SysIntegration_DW.bitsForTID7.is_c29_test2_SysIntegration ==
        test2_SysI_IN_DoseTaskScheduler) {
      if (test2_SysIntegration_DW.NextSubBaseDoseTaskTimeHitSec <
          test2_SysIntegration_DW.NextSubLargeDoseTaskTimeHitSec) {
        test2_SysIntegration_B.NextHitTime =
          test2_SysIntegration_DW.NextSubBaseDoseTaskTimeHitSec;
      } else {
        test2_SysIntegration_B.NextHitTime =
          test2_SysIntegration_DW.NextSubLargeDoseTaskTimeHitSec;
      }

      zcEvent_idx_0 = false;
      zcEvent_idx_1 = true;
      if (!(test2_SysIntegration_B.VarSet.DoseCtrl.LargeDoseConfig.EffectiveDay ==
            0)) {
        zcEvent_idx_1 = false;
      }

      if (zcEvent_idx_1) {
        zcEvent_idx_0 = true;
      }

      if (zcEvent_idx_0) {
        test2_SysIntegration_DW.bitsForTID7.boolLastLargeSubDose = false;
      }

      if (test2_SysIntegration_DW.bitsForTID7.is_DoseTaskScheduler ==
          test_IN_LargeDoseTimerRunOrStop) {
        if (!test2_SysIntegration_B.bitsForTID4.boolNormalDeliverySwitchOn) {
          test2_SysIntegration_DW.bitsForTID7.is_LargeDoseTimerRunOrStop = 0;
          test2_SysIntegration_DW.bitsForTID7.boolLargeDoseTimeRun = false;
          test2_SysIntegration_DW.bitsForTID7.is_DoseTaskScheduler =
            tes_IN_LargeDoseTimerStopOrHold;
          test2_SysIntegration_B.NextHitTime = MAX_uint16_T;
          test2_SysIntegration_DW.ClearQueueEvtEventCounter++;
        } else {
          zcEvent_idx_0 = false;
          zcEvent_idx_1 = true;
          if (!(test2_SysIntegration_B.VarSet.DoseCtrl.LargeDoseConfig.EffectiveDay
                == 0)) {
            zcEvent_idx_1 = false;
          }

          if (zcEvent_idx_1) {
            zcEvent_idx_0 = true;
          }

          if ((!zcEvent_idx_0) &&
              (!test2_SysIntegration_DW.bitsForTID7.boolLargeDoseTimeRun) &&
              (!test2_SysIntegration_DW.bitsForTID7.boolLastLargeSubDose)) {
            test2_SysIntegration_DW.bitsForTID7.boolLargeDoseTimeRun = true;
            test2_SysIntegration_B.MotionCtrl2RTMsgOut.Head.MsgId = (uint8_T)
              ((uint8_T)(test2_SysIntegration_B.MotionCtrl2RTMsgOut.Head.MsgId +
                         1U) % MAX_uint8_T);
            test2_SysIntegration_B.MotionCtrl2RTMsgOut.Head.OpCode = 1U;
            test2_SysIntegration_B.MotionCtrl2RTMsgOut.Body.Data = 1U;
          } else {
            if (test2_SysIntegration_DW.bitsForTID7.boolLastLargeSubDose &&
                test2_SysIntegration_DW.bitsForTID7.boolLargeDoseTimeRun) {
              test2_SysIntegration_DW.bitsForTID7.boolLargeDoseTimeRun = false;
              test2_SysIntegration_B.MotionCtrl2RTMsgOut.Head.MsgId = (uint8_T)
                ((uint8_T)(test2_SysIntegration_B.MotionCtrl2RTMsgOut.Head.MsgId
                           + 1U) % MAX_uint8_T);
              test2_SysIntegration_B.MotionCtrl2RTMsgOut.Head.OpCode = 0U;
              test2_SysIntegration_B.MotionCtrl2RTMsgOut.Body.Data = 0U;
            }
          }

          if (test2_SysIntegration_DW.bitsForTID7.is_LargeDoseTimerRunOrStop ==
              test2_Sy_IN_LargeDoseTaskHitChk) {
            if (test2_SysIntegration_DW.temporalCounter_i1 >= 1U) {
              test2_SysIntegration_DW.bitsForTID7.is_LargeDoseTimerRunOrStop =
                test2_Sys_IN_baseRateTaskHitChk;
              test2_SysIntegration_DW.temporalCounter_i1 = 0U;
              enter_atomic_baseRateTaskHitChk();
            }
          } else {
            zcEvent_idx_0 = ((test2_SysIntegration_DW.temporalCounter_i1 >= 1U) &&
                             test2_SysIntegration_DW.bitsForTID7.boolLargeDoseTimeRun);
            if (zcEvent_idx_0) {
              test2_SysIntegration_DW.bitsForTID7.is_LargeDoseTimerRunOrStop =
                test2_Sy_IN_LargeDoseTaskHitChk;
              test2_SysIntegration_DW.temporalCounter_i1 = 0U;
              if (test2_SysIntegration_DW.bitsForTID7.boolLargeDoseTimeRun) {
                test2_SysInt_subLargeTimeHitChk(test2_SysIntegration_B.In1_f,
                  &test2_SysIntegration_B.VarSet.DoseCtrl,
                  test2_SysIntegration_B.bitsForTID4.boolDoseCtrlBusy,
                  test2_SysIntegration_DW.SubLargeDoseId, 3,
                  test2_SysIntegration_DW.bitsForTID7.boolLastLargeSubDose,
                  &SubLargeDose, &tmp_7,
                  &test2_SysIntegration_DW.NextSubLargeDoseTaskTimeHitSec,
                  &zcEvent_idx_0, &temp_LargeDose);
                test2_SysIntegration_DW.SubLargeDoseId = tmp_7;
                test2_SysIntegration_DW.bitsForTID7.boolLastLargeSubDose =
                  zcEvent_idx_0;
                if (test2_SysIntegration_DW.prevSubLargeDoseId !=
                    test2_SysIntegration_DW.SubLargeDoseId) {
                  zcEvent_idx_0 = false;
                  zcEvent_idx_1 = true;
                  if (!(test2_SysIntegration_DW.SubLargeDoseId == 0)) {
                    zcEvent_idx_1 = false;
                  }

                  if (zcEvent_idx_1) {
                    zcEvent_idx_0 = true;
                  }

                  if (!zcEvent_idx_0) {
                    test2_SysIntegration_DW.prevSubLargeDoseId =
                      test2_SysIntegration_DW.SubLargeDoseId;
                    if (test2_SysIntegration_DW.bitsForTID7.boolLastLargeSubDose)
                    {
                      test2_SysIntegration_B.DoseMissionMsgOut.Head.OpCode =
                        200U;
                      test2_SysIntegration_DW.LargeDoseTaskNo = 0U;
                      sfEvent_h = (int32_T)floorf((real32_T)SubLargeDose *
                        test2_SysIntegration_B.Enc2DoseGain);
                      i = (int32_T)floorf((real32_T)temp_LargeDose *
                                          test2_SysIntegration_B.Enc2DoseGain) -
                        (int32_T)
                        test2_SysIntegration_B.VarSet.ActCtrl.LargeDoseDynVar.CompleteDose;
                      if (!(i > 0)) {
                        i = 0;
                      }

                      if (!(i > sfEvent_h)) {
                        i = sfEvent_h;
                      }

                      sfEvent_h = (int32_T)roundf((real32_T)sfEvent_h * 1.05F);
                      if (i < sfEvent_h) {
                        test2_SysIntegration_B.DoseMissionMsgOut.Body.TargetEncCnt
                          = i;
                      } else {
                        test2_SysIntegration_B.DoseMissionMsgOut.Body.TargetEncCnt
                          = sfEvent_h;
                      }
                    } else {
                      test2_SysIntegration_B.DoseMissionMsgOut.Head.OpCode =
                        (uint8_T)(201U + test2_SysIntegration_DW.LargeDoseTaskNo);
                      test2_SysIntegration_DW.LargeDoseTaskNo = (uint8_T)
                        ((uint8_T)(test2_SysIntegration_DW.LargeDoseTaskNo + 1U)
                         % 55);
                      test2_SysIntegration_B.DoseMissionMsgOut.Body.TargetEncCnt
                        = (int32_T)floorf((real32_T)SubLargeDose *
                                          test2_SysIntegration_B.Enc2DoseGain);
                    }

                    test2_SysIntegration_B.DoseMissionMsgOut.Head.MsgId =
                      (uint8_T)((uint8_T)
                                (test2_SysIntegration_B.DoseMissionMsgOut.Head.MsgId
                                 + 1U) % MAX_uint8_T);
                    test2_SysIntegration_DW.PushDoseEventCounter++;
                  }
                }
              } else {
                test2_SysIntegration_DW.NextSubLargeDoseTaskTimeHitSec =
                  MAX_uint16_T;
              }
            } else {
              zcEvent_idx_0 = ((test2_SysIntegration_DW.temporalCounter_i1 >= 2U)
                               &&
                               (!test2_SysIntegration_DW.bitsForTID7.boolLargeDoseTimeRun));
              if (zcEvent_idx_0) {
                test2_SysIntegration_DW.bitsForTID7.is_LargeDoseTimerRunOrStop =
                  test2_Sys_IN_baseRateTaskHitChk;
                test2_SysIntegration_DW.temporalCounter_i1 = 0U;
                enter_atomic_baseRateTaskHitChk();
              }
            }
          }
        }
      } else if (test2_SysIntegration_B.bitsForTID4.boolNormalDeliverySwitchOn)
      {
        test2_SysIntegration_DW.bitsForTID7.boolLargeDoseTimeHold = false;
        test2_SysIntegration_DW.bitsForTID7.is_DoseTaskScheduler =
          test_IN_LargeDoseTimerRunOrStop;
        test2_SysIntegration_DW.bitsForTID7.is_LargeDoseTimerRunOrStop =
          test2_Sys_IN_baseRateTaskHitChk;
        test2_SysIntegration_DW.temporalCounter_i1 = 0U;
        enter_atomic_baseRateTaskHitChk();
      } else {
        zcEvent_idx_0 = false;
        zcEvent_idx_1 = true;
        if (!(test2_SysIntegration_B.VarSet.DoseCtrl.LargeDoseConfig.EffectiveDay
              == 0)) {
          zcEvent_idx_1 = false;
        }

        if (zcEvent_idx_1) {
          zcEvent_idx_0 = true;
        }

        if ((!zcEvent_idx_0) &&
            (!test2_SysIntegration_DW.bitsForTID7.boolLargeDoseTimeHold)) {
          test2_SysIntegration_DW.bitsForTID7.boolLargeDoseTimeHold = true;
          test2_SysIntegration_B.MotionCtrl2RTMsgOut.Head.MsgId = (uint8_T)
            ((uint8_T)(test2_SysIntegration_B.MotionCtrl2RTMsgOut.Head.MsgId +
                       1U) % MAX_uint8_T);
          test2_SysIntegration_B.MotionCtrl2RTMsgOut.Head.OpCode = 1U;
          test2_SysIntegration_B.MotionCtrl2RTMsgOut.Body.Data = 0U;
        } else {
          zcEvent_idx_0 = false;
          zcEvent_idx_1 = true;
          if (!(test2_SysIntegration_B.VarSet.DoseCtrl.LargeDoseConfig.EffectiveDay
                == 0)) {
            zcEvent_idx_1 = false;
          }

          if (zcEvent_idx_1) {
            zcEvent_idx_0 = true;
          }

          if (zcEvent_idx_0 &&
              test2_SysIntegration_DW.bitsForTID7.boolLargeDoseTimeHold) {
            test2_SysIntegration_DW.bitsForTID7.boolLargeDoseTimeHold = false;
            test2_SysIntegration_B.MotionCtrl2RTMsgOut.Head.MsgId = (uint8_T)
              ((uint8_T)(test2_SysIntegration_B.MotionCtrl2RTMsgOut.Head.MsgId +
                         1U) % MAX_uint8_T);
            test2_SysIntegration_B.MotionCtrl2RTMsgOut.Head.OpCode = 0U;
            test2_SysIntegration_B.MotionCtrl2RTMsgOut.Body.Data = 0U;
            test2_SysIntegration_DW.prevSubLargeDoseId = 0U;
          }
        }
      }
    } else {
      if (test2_SysIntegration_DW.temporalCounter_i1 >= 3U) {
        test2_SysIntegration_DW.bitsForTID7.is_c29_test2_SysIntegration =
          test2_SysI_IN_DoseTaskScheduler;
        test2_SysIntegration_B.Enc2DoseGain = 20480.0F / ((real32_T)
          test2_SysIntegration_B.VarSet.DoseCtrl.DoseCtrlParam.Concentration *
          test2_SysIntegratio_ScrewLength * test2_SysIntegration_SqPiston);
        test2_SysIntegration_DW.bitsForTID7.is_DoseTaskScheduler =
          tes_IN_LargeDoseTimerStopOrHold;
        test2_SysIntegration_B.NextHitTime = MAX_uint16_T;
        test2_SysIntegration_DW.ClearQueueEvtEventCounter++;
      }
    }

    if (test2_SysIntegration_DW.PushDoseEventCounter > 0U) {
      test2_SysIntegration_B.bitsForTID7.PushDose =
        !test2_SysIntegration_B.bitsForTID7.PushDose;
      test2_SysIntegration_DW.PushDoseEventCounter--;
    }

    if (test2_SysIntegration_DW.ClearQueueEvtEventCounter > 0U) {
      test2_SysIntegration_B.bitsForTID7.ClearQueueEvt =
        !test2_SysIntegration_B.bitsForTID7.ClearQueueEvt;
      test2_SysIntegration_DW.ClearQueueEvtEventCounter--;
    }

    /* End of Chart: '<S106>/TaskScheduler' */
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    /* SignalConversion: '<S104>/HiddenBuf_InsertedFor_Buffer_at_inport_1' incorporates:
     *  UnitDelay: '<S76>/Unit Delay1'
     */
    rtb_HiddenBuf_InsertedFor_Cha_0 =
      test2_SysIntegration_DW.bitsForTID4.UnitDelay1_DSTATE_i;

    /* Chart: '<S104>/Buffer' incorporates:
     *  TriggerPort: '<S105>/input events'
     */
    rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.Buffer_Trig_ZCE_o[0] ==
                         POS_ZCSIG) != (int32_T)rtb_HiddenBuf_InsertedFor_Cha_0)
                       && (test2_SysIntegration_PrevZCX.Buffer_Trig_ZCE_o[0] !=
      UNINITIALIZED_ZCSIG));
    d_tf = rtb_PopAlarmEvt;
    zcEvent_idx_0 = rtb_PopAlarmEvt;

    /* SignalConversion: '<S104>/HiddenBuf_InsertedFor_Buffer_at_inport_1' */
    rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.Buffer_Trig_ZCE_o[1] ==
                         POS_ZCSIG) != (int32_T)
                        test2_SysIntegration_B.bitsForTID7.PushDose) &&
                       (test2_SysIntegration_PrevZCX.Buffer_Trig_ZCE_o[1] !=
                        UNINITIALIZED_ZCSIG));
    d_tf = (d_tf || rtb_PopAlarmEvt);
    zcEvent_idx_1 = rtb_PopAlarmEvt;

    /* SignalConversion: '<S104>/HiddenBuf_InsertedFor_Buffer_at_inport_1' */
    rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.Buffer_Trig_ZCE_o[2] ==
                         POS_ZCSIG) != (int32_T)
                        test2_SysIntegration_B.bitsForTID7.ClearQueueEvt) &&
                       (test2_SysIntegration_PrevZCX.Buffer_Trig_ZCE_o[2] !=
                        UNINITIALIZED_ZCSIG));
    d_tf = (d_tf || rtb_PopAlarmEvt);
    if (d_tf) {
      if ((int8_T)(zcEvent_idx_0 ? rtb_HiddenBuf_InsertedFor_Cha_0 ?
                   RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
        i = test2_SysIntegrat_event_PopQEvt;
        chartstep_c28_test2_SysIntegrat(&i);
      }

      /* SignalConversion: '<S104>/HiddenBuf_InsertedFor_Buffer_at_inport_1' */
      if ((int8_T)(zcEvent_idx_1 ? test2_SysIntegration_B.bitsForTID7.PushDose ?
                   RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
        i = test2_SysIntegra_event_PushQEvt;
        chartstep_c28_test2_SysIntegrat(&i);
      }

      if ((int8_T)(rtb_PopAlarmEvt ?
                   test2_SysIntegration_B.bitsForTID7.ClearQueueEvt ?
                   RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
        i = test2_SysIntegrat_event_ClrQEvt;
        chartstep_c28_test2_SysIntegrat(&i);
      }
    }

    test2_SysIntegration_PrevZCX.Buffer_Trig_ZCE_o[0] =
      rtb_HiddenBuf_InsertedFor_Cha_0;

    /* SignalConversion: '<S104>/HiddenBuf_InsertedFor_Buffer_at_inport_1' */
    test2_SysIntegration_PrevZCX.Buffer_Trig_ZCE_o[1] =
      test2_SysIntegration_B.bitsForTID7.PushDose;
    test2_SysIntegration_PrevZCX.Buffer_Trig_ZCE_o[2] =
      test2_SysIntegration_B.bitsForTID7.ClearQueueEvt;

    /* DataTypeConversion: '<S108>/Cast To Boolean1' */
    test2_SysIntegration_B.bitsForTID4.CastToBoolean1 =
      (test2_SysIntegration_B.VarSet.DoseCtrl.LargeDoseConfig.EffectiveDay != 0);
  }

  /* DiscretePulseGenerator: '<S108>/Pulse Generator' */
  i = ((test2_SysIntegration_DW.clockTickCounter_i3 < 100) &&
       (test2_SysIntegration_DW.clockTickCounter_i3 >= 0));
  if (test2_SysIntegration_DW.clockTickCounter_i3 >= 199) {
    test2_SysIntegration_DW.clockTickCounter_i3 = 0;
  } else {
    test2_SysIntegration_DW.clockTickCounter_i3++;
  }

  /* End of DiscretePulseGenerator: '<S108>/Pulse Generator' */

  /* SignalConversion: '<S108>/HiddenBuf_InsertedFor_Chart_at_inport_5' incorporates:
   *  DataTypeConversion: '<S108>/Cast To Boolean2'
   */
  rtb_HiddenBuf_InsertedFor_Cha_0 = (i != 0);

  /* Chart: '<S108>/Chart' incorporates:
   *  TriggerPort: '<S109>/input events'
   */
  rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_j[0] ==
                       POS_ZCSIG) != (int32_T)
                      test2_SysIntegration_B.bitsForTID4.CastToBoolean1) &&
                     (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_j[0] !=
                      UNINITIALIZED_ZCSIG));
  d_tf = rtb_PopAlarmEvt;
  zcEvent_idx_0 = rtb_PopAlarmEvt;
  rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_j[1] ==
                       POS_ZCSIG) != (int32_T)rtb_HiddenBuf_InsertedFor_Cha_0) &&
                     (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_j[1] !=
                      UNINITIALIZED_ZCSIG));
  d_tf = (d_tf || rtb_PopAlarmEvt);
  if (d_tf) {
    elapsedTicks_d = test2_SysIntegration_M->Timing.clockTick0 -
      test2_SysIntegration_DW.previousTicks_l;
    test2_SysIntegration_DW.previousTicks_l =
      test2_SysIntegration_M->Timing.clockTick0;
    if (test2_SysIntegration_DW.temporalCounter_i1_di + elapsedTicks_d <= 4095U)
    {
      test2_SysIntegration_DW.temporalCounter_i1_di = (uint16_T)
        (test2_SysIntegration_DW.temporalCounter_i1_di + elapsedTicks_d);
    } else {
      test2_SysIntegration_DW.temporalCounter_i1_di = 4095U;
    }

    i = 0;

    /* SignalConversion: '<S108>/HiddenBuf_InsertedFor_Chart_at_inport_5' */
    if ((int8_T)(zcEvent_idx_0 ?
                 test2_SysIntegration_B.bitsForTID4.CastToBoolean1 ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) == -1) {
      i = 1;
      sfEvent_h = test2_Sy_event_dumpLargeDoseEvt;
      chartstep_c30_test2_SysIntegrat(&sfEvent_h);
    }

    if ((int8_T)(rtb_PopAlarmEvt ? rtb_HiddenBuf_InsertedFor_Cha_0 ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      i = 1;
      if (test2_SysIntegration_DW.temporalCounter_i2 < MAX_uint32_T) {
        test2_SysIntegration_DW.temporalCounter_i2++;
      }

      sfEvent_h = test2_SysInte_event_UpdateEvt_e;
      chartstep_c30_test2_SysIntegrat(&sfEvent_h);
    }

    if ((i != 0) && (test2_SysIntegration_DW.EncRstEvtEventCounter > 0U)) {
      test2_SysIntegration_B.bitsForTID0.EncRstEvt =
        !test2_SysIntegration_B.bitsForTID0.EncRstEvt;
      test2_SysIntegration_DW.EncRstEvtEventCounter--;
    }
  }

  /* SignalConversion: '<S108>/HiddenBuf_InsertedFor_Chart_at_inport_5' */
  test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_j[0] =
    test2_SysIntegration_B.bitsForTID4.CastToBoolean1;
  test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_j[1] =
    rtb_HiddenBuf_InsertedFor_Cha_0;
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[5] == 0) {
    /* Chart: '<Root>/MsgRouter4' */
    test2_SysIntegration_MsgRouter1(&test2_SysIntegration_B.SysDiagMsg_a,
      &test2_SysIntegration_B.SysDiagMsg,
      &test2_SysIntegration_B.Group1AlarmMsgOut_m,
      &test2_SysIntegration_DW.sf_MsgRouter4);
  }

  /* Chart: '<S89>/ResidueDoseEval' incorporates:
   *  UnitDelay: '<S4>/Unit Delay'
   */
  if (test2_SysIntegration_DW.temporalCounter_i1_i < 2047U) {
    test2_SysIntegration_DW.temporalCounter_i1_i++;
  }

  if (test2_SysIntegration_DW.temporalCounter_i2_k < 511U) {
    test2_SysIntegration_DW.temporalCounter_i2_k++;
  }

  if (test2_SysIntegration_DW.bitsForTID0.is_active_c18_test2_SysIntegrat == 0U)
  {
    test2_SysIntegration_DW.bitsForTID0.is_active_c18_test2_SysIntegrat = 1;
    test2_SysIntegration_DW.bitsForTID0.is_c18_test2_SysIntegration =
      test2_SysIntegration_IN_Init;
    test2_SysIntegration_DW.bitsForTID0.prevSysVarUpdateMsgId =
      test2_SysIntegration_B.bitsForTID4.FlashInitFinishEvt;
    test2_SysIntegration_B.ResidueDoseTrimMsg.Head.MsgId = 0U;
    test2_SysIntegration_B.ResidueDoseTrimMsg.Head.OpCode = 0U;
    test2_SysIntegration_B.ResidueDoseTrimMsg.Body.DayInfo = 0U;
    test2_SysIntegration_B.ResidueDoseTrimMsg.Body.ResidueDoseEst = 0U;
    test2_SysIntegration_B.ResidueDoseTrimMsg.Body.TotalAmountAcc = 0U;
    test2_SysIntegration_B.ResidueDoseTrimMsg.Body.DailyAmountAcc = 0U;
    test2_SysIntegration_B.ResidueDoseTrimMsg.Body.LargeAmountAcc = 0U;
  } else {
    switch (test2_SysIntegration_DW.bitsForTID0.is_c18_test2_SysIntegration) {
     case test2_SysIntegration_IN_Init:
      if (test2_SysIntegration_DW.bitsForTID0.boolStartUp &&
          test2_SysIntegration_B.bitsForTID0.boolTrimEnable) {
        test2_SysIntegration_DW.bitsForTID0.is_c18_test2_SysIntegration =
          test2_SysIntegration_IN_Op_h;
        test2_SysIntegration_DW.temporalCounter_i2_k = 0U;
        test2_SysIntegration_DW.bitsForTID0.is_Op =
          test2_SysInt_IN_Wait4EncClrSync;
        test2_SysIntegration_DW.temporalCounter_i1_i = 0U;
        test2_SysIntegration_DW.EncClrEvtEventCounter++;
      } else {
        if ((test2_SysIntegration_DW.bitsForTID0.prevSysVarUpdateMsgId !=
             test2_SysIntegration_B.bitsForTID4.FlashInitFinishEvt) &&
            (!test2_SysIntegration_DW.bitsForTID0.boolStartUp)) {
          test2_SysIntegration_DW.bitsForTID0.prevSysVarUpdateMsgId =
            test2_SysIntegration_B.bitsForTID4.FlashInitFinishEvt;
          test2_SysIntegration_DW.bitsForTID0.boolStartUp = true;
        }
      }
      break;

     case test2_SysIntegration_IN_Op_h:
      if (test2_SysIntegration_DW.temporalCounter_i2_k >= 500U) {
        test2_SysIntegration_DW.bitsForTID0.is_c18_test2_SysIntegration =
          test2_SysIntegration_IN_Op_h;
        test2_SysIntegration_DW.temporalCounter_i2_k = 0U;
        test2_SysIntegration_DW.bitsForTID0.is_Op =
          test2_SysInt_IN_Wait4EncClrSync;
        test2_SysIntegration_DW.temporalCounter_i1_i = 0U;
        test2_SysIntegration_DW.EncClrEvtEventCounter++;
      } else {
        zcEvent_idx_0 = ((!test2_SysIntegration_B.bitsForTID0.boolTrimEnable) &&
                         (test2_SysIntegration_DW.bitsForTID0.is_Op ==
                          test2_Sy_IN_UpdatingResidueDose));
        if (zcEvent_idx_0) {
          test2_SysIntegration_DW.EncClrEvtEventCounter++;
          test2_SysIntegration_DW.bitsForTID0.is_Op = 0;
          test2_SysIntegration_DW.bitsForTID0.is_c18_test2_SysIntegration =
            test2_SysIntegration_IN_OpEnd;
          test2_SysIntegration_DW.bitsForTID0.is_OpEnd_g =
            test2_SysI_IN_Wait4EncCntStable;
          test2_SysIntegration_DW.temporalCounter_i1_i = 0U;
        } else {
          switch (test2_SysIntegration_DW.bitsForTID0.is_Op) {
           case test2_Sy_IN_UpdatingResidueDose:
            break;

           default:
            if (test2_SysIntegration_DW.temporalCounter_i1_i >= 500U) {
              test2_SysIntegration_DW.bitsForTID0.is_Op =
                test2_Sy_IN_UpdatingResidueDose;
              i = (int32_T)(test2_SysIntegration_B.ResidueDoseTrimMsg.Head.MsgId
                            + 1U);
              if ((uint32_T)i > 255U) {
                i = 255;
              }

              test2_SysIntegration_B.ResidueDoseTrimMsg.Head.MsgId = (uint8_T)
                ((uint8_T)i % MAX_uint8_T);
              test2_SysIntegration_B.ResidueDoseTrimMsg.Head.OpCode = 12U;
              denAccum = roundf((real32_T)
                                test2_SysIntegration_DW.UnitDelay_DSTATE_i /
                                test2_SysIntegration_B.Enc2DoseGain);
              if (denAccum < 4.2949673E+9F) {
                if (denAccum >= 0.0F) {
                  test2_SysIntegration_B.ResidueDoseTrimMsg.Body.ResidueDoseEst =
                    (uint32_T)denAccum;
                } else {
                  test2_SysIntegration_B.ResidueDoseTrimMsg.Body.ResidueDoseEst =
                    0U;
                }
              } else {
                test2_SysIntegration_B.ResidueDoseTrimMsg.Body.ResidueDoseEst =
                  MAX_uint32_T;
              }
            }
            break;
          }
        }
      }
      break;

     default:
      if ((test2_SysIntegration_DW.bitsForTID0.is_OpEnd_g ==
           test2_SysIntegr_IN_EncCntStable) &&
          test2_SysIntegration_B.bitsForTID0.boolTrimEnable) {
        test2_SysIntegration_DW.bitsForTID0.is_OpEnd_g = 0;
        test2_SysIntegration_DW.bitsForTID0.is_c18_test2_SysIntegration =
          test2_SysIntegration_IN_Op_h;
        test2_SysIntegration_DW.temporalCounter_i2_k = 0U;
        test2_SysIntegration_DW.bitsForTID0.is_Op =
          test2_SysInt_IN_Wait4EncClrSync;
        test2_SysIntegration_DW.temporalCounter_i1_i = 0U;
        test2_SysIntegration_DW.EncClrEvtEventCounter++;
      } else {
        switch (test2_SysIntegration_DW.bitsForTID0.is_OpEnd_g) {
         case test2_SysIntegr_IN_EncCntStable:
          break;

         default:
          if (test2_SysIntegration_DW.temporalCounter_i1_i >= 2000U) {
            test2_SysIntegration_DW.bitsForTID0.is_OpEnd_g =
              test2_SysIntegr_IN_EncCntStable;
            i = (int32_T)(test2_SysIntegration_B.ResidueDoseTrimMsg.Head.MsgId +
                          1U);
            if ((uint32_T)i > 255U) {
              i = 255;
            }

            test2_SysIntegration_B.ResidueDoseTrimMsg.Head.MsgId = (uint8_T)
              ((uint8_T)i % MAX_uint8_T);
            test2_SysIntegration_B.ResidueDoseTrimMsg.Head.OpCode = 102U;
            denAccum = roundf((real32_T)
                              test2_SysIntegration_DW.UnitDelay_DSTATE_i /
                              test2_SysIntegration_B.Enc2DoseGain);
            if (denAccum < 4.2949673E+9F) {
              if (denAccum >= 0.0F) {
                test2_SysIntegration_B.ResidueDoseTrimMsg.Body.ResidueDoseEst =
                  (uint32_T)denAccum;
              } else {
                test2_SysIntegration_B.ResidueDoseTrimMsg.Body.ResidueDoseEst =
                  0U;
              }
            } else {
              test2_SysIntegration_B.ResidueDoseTrimMsg.Body.ResidueDoseEst =
                MAX_uint32_T;
            }
          }
          break;
        }
      }
      break;
    }
  }

  if (test2_SysIntegration_DW.EncClrEvtEventCounter > 0U) {
    test2_SysIntegration_B.bitsForTID0.EncClrEvt =
      !test2_SysIntegration_B.bitsForTID0.EncClrEvt;
    test2_SysIntegration_DW.EncClrEvtEventCounter--;
  }

  /* End of Chart: '<S89>/ResidueDoseEval' */

  /* Chart: '<S68>/Chart1' incorporates:
   *  TriggerPort: '<S72>/input events'
   */
  /* SignalConversion: '<S68>/HiddenBuf_InsertedFor_Chart1_at_inport_1' */
  rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.Chart1_Trig_ZCE[0] ==
                       POS_ZCSIG) != (int32_T)
                      test2_SysIntegration_B.bitsForTID4.FlashInitFinishEvt) &&
                     (test2_SysIntegration_PrevZCX.Chart1_Trig_ZCE[0] !=
                      UNINITIALIZED_ZCSIG));
  d_tf = rtb_PopAlarmEvt;
  zcEvent_idx_0 = rtb_PopAlarmEvt;

  /* SignalConversion: '<S68>/HiddenBuf_InsertedFor_Chart1_at_inport_1' */
  rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.Chart1_Trig_ZCE[1] ==
                       POS_ZCSIG) != (int32_T)
                      test2_SysIntegration_B.bitsForTID0.EncRstEvt) &&
                     (test2_SysIntegration_PrevZCX.Chart1_Trig_ZCE[1] !=
                      UNINITIALIZED_ZCSIG));
  d_tf = (d_tf || rtb_PopAlarmEvt);
  zcEvent_idx_1 = rtb_PopAlarmEvt;

  /* SignalConversion: '<S68>/HiddenBuf_InsertedFor_Chart1_at_inport_1' */
  rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.Chart1_Trig_ZCE[2] ==
                       POS_ZCSIG) != (int32_T)
                      test2_SysIntegration_B.bitsForTID0.EncClrEvt) &&
                     (test2_SysIntegration_PrevZCX.Chart1_Trig_ZCE[2] !=
                      UNINITIALIZED_ZCSIG));
  d_tf = (d_tf || rtb_PopAlarmEvt);
  if (d_tf) {
    /* SignalConversion: '<S68>/HiddenBuf_InsertedFor_Chart1_at_inport_1' */
    if ((int8_T)(zcEvent_idx_0 ?
                 test2_SysIntegration_B.bitsForTID4.FlashInitFinishEvt ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      i = test2__event_FlashInitFinishEvt;
      chartstep_c42_test2_SysIntegrat(&i);
    }

    if ((int8_T)(zcEvent_idx_1 ? test2_SysIntegration_B.bitsForTID0.EncRstEvt ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      i = test2_SysIntegr_event_EncRstEvt;
      chartstep_c42_test2_SysIntegrat(&i);
    }

    if ((int8_T)(rtb_PopAlarmEvt ? test2_SysIntegration_B.bitsForTID0.EncClrEvt ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      i = test2_SysIntegr_event_EncClrEvt;
      chartstep_c42_test2_SysIntegrat(&i);
    }
  }

  /* SignalConversion: '<S68>/HiddenBuf_InsertedFor_Chart1_at_inport_1' */
  test2_SysIntegration_PrevZCX.Chart1_Trig_ZCE[0] =
    test2_SysIntegration_B.bitsForTID4.FlashInitFinishEvt;
  test2_SysIntegration_PrevZCX.Chart1_Trig_ZCE[1] =
    test2_SysIntegration_B.bitsForTID0.EncRstEvt;
  test2_SysIntegration_PrevZCX.Chart1_Trig_ZCE[2] =
    test2_SysIntegration_B.bitsForTID0.EncClrEvt;

  /* DiscretePulseGenerator: '<S69>/Pulse Generator' */
  i = ((test2_SysIntegration_DW.clockTickCounter_c < 100) &&
       (test2_SysIntegration_DW.clockTickCounter_c >= 0));
  if (test2_SysIntegration_DW.clockTickCounter_c >= 199) {
    test2_SysIntegration_DW.clockTickCounter_c = 0;
  } else {
    test2_SysIntegration_DW.clockTickCounter_c++;
  }

  /* End of DiscretePulseGenerator: '<S69>/Pulse Generator' */

  /* SignalConversion: '<S69>/HiddenBuf_InsertedFor_Chart_at_inport_2' incorporates:
   *  DataTypeConversion: '<S69>/Data Type Conversion'
   */
  rtb_HiddenBuf_InsertedFor_Cha_0 = (i != 0);

  /* Chart: '<S69>/Chart' incorporates:
   *  TriggerPort: '<S73>/input events'
   */
  rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_ff[0] ==
                       POS_ZCSIG) != (int32_T)
                      test2_SysIntegration_B.bitsForTID5.boolShaftEnc) &&
                     (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_ff[0] !=
                      UNINITIALIZED_ZCSIG));
  d_tf = rtb_PopAlarmEvt;
  zcEvent_idx_0 = rtb_PopAlarmEvt;
  rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_ff[1] ==
                       POS_ZCSIG) != (int32_T)rtb_HiddenBuf_InsertedFor_Cha_0) &&
                     (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_ff[1] !=
                      UNINITIALIZED_ZCSIG));
  d_tf = (d_tf || rtb_PopAlarmEvt);
  if (d_tf) {
    /* SignalConversion: '<S69>/HiddenBuf_InsertedFor_Chart_at_inport_2' */
    if ((int8_T)(zcEvent_idx_0 ? test2_SysIntegration_B.bitsForTID5.boolShaftEnc
                 ? RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      if (test2_SysIntegration_DW.temporalCounter_i1_js < 7U) {
        test2_SysIntegration_DW.temporalCounter_i1_js++;
      }

      i = test2_SysInteg_event_ShaftEncIO;
      chartstep_c43_test2_SysIntegrat(&i);
    }

    if ((int8_T)(rtb_PopAlarmEvt ? rtb_HiddenBuf_InsertedFor_Cha_0 ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      i = test2_SysInt_event_UpdateTick_c;
      chartstep_c43_test2_SysIntegrat(&i);
    }
  }

  /* SignalConversion: '<S69>/HiddenBuf_InsertedFor_Chart_at_inport_2' */
  test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_ff[0] =
    test2_SysIntegration_B.bitsForTID5.boolShaftEnc;
  test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_ff[1] =
    rtb_HiddenBuf_InsertedFor_Cha_0;
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    /* DataTypeConversion: '<S81>/Data Type Conversion1' incorporates:
     *  DataTypeConversion: '<S81>/Data Type Conversion'
     *  Fcn: '<S81>/LUT'
     */
    i = (int32_T)fmod((int32_T)100.0 -
                      test2_SysIntegration_B.VarSet.SysSetting.SensitivityLevel *
                      (int32_T)2.0, 256.0);
    test2_SysIntegration_B.DataTypeConversion1_o = (uint8_T)(i < 0 ? (int32_T)
      (uint8_T)-(int8_T)(uint8_T)-(real_T)i : (int32_T)(uint8_T)i);
  }

  /* UnitDelay: '<S21>/Unit Delay2' */
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[5] == 0) {
    test2_SysIntegration_B.UnitDelay2_j =
      test2_SysIntegration_DW.UnitDelay2_DSTATE_n;
  }

  /* End of UnitDelay: '<S21>/Unit Delay2' */

  /* DiscretePulseGenerator: '<S96>/Pulse Generator' */
  i = ((test2_SysIntegration_DW.clockTickCounter_p < 1) &&
       (test2_SysIntegration_DW.clockTickCounter_p >= 0));
  if (test2_SysIntegration_DW.clockTickCounter_p >= 1) {
    test2_SysIntegration_DW.clockTickCounter_p = 0;
  } else {
    test2_SysIntegration_DW.clockTickCounter_p++;
  }

  /* End of DiscretePulseGenerator: '<S96>/Pulse Generator' */

  /* SignalConversion: '<S96>/HiddenBuf_InsertedFor_MotorRunDriver_at_inport_2' incorporates:
   *  DataTypeConversion: '<S96>/Data Type Conversion'
   */
  rtb_HiddenBuf_InsertedFor_Motor[0] =
    test2_SysIntegration_B.bitsForTID4.ServoOnEvt;
  rtb_HiddenBuf_InsertedFor_Motor[1] =
    test2_SysIntegration_B.bitsForTID0.AirExpelEnaEvt;
  rtb_HiddenBuf_InsertedFor_Motor[2] =
    test2_SysIntegration_B.bitsForTID0.boolHomingEvt;
  rtb_HiddenBuf_InsertedFor_Motor[3] =
    test2_SysIntegration_B.bitsForTID4.ForceStopEvt;
  rtb_HiddenBuf_InsertedFor_Motor[4] = (i != 0);

  /* Chart: '<S96>/MotorRunDriver' incorporates:
   *  TriggerPort: '<S97>/input events'
   */
  d_tf = false;
  for (i = 0; i < 5; i++) {
    rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.MotorRunDriver_Trig_ZCE[i]
                         == POS_ZCSIG) != (int32_T)
                        rtb_HiddenBuf_InsertedFor_Motor[i]) &&
                       (test2_SysIntegration_PrevZCX.MotorRunDriver_Trig_ZCE[i]
                        != UNINITIALIZED_ZCSIG));
    d_tf = (d_tf || rtb_PopAlarmEvt);
    zcEvent[i] = rtb_PopAlarmEvt;
  }

  if (d_tf) {
    for (i = 0; i < 5; i++) {
      rtb_inputevents_at[i] = (int8_T)(zcEvent[i] ?
        rtb_HiddenBuf_InsertedFor_Motor[i] ? RISING_ZCEVENT : FALLING_ZCEVENT :
        NO_ZCEVENT);
    }

    if (rtb_inputevents_at[0U] != 0) {
      i = test2_SysInte_event_MotorServOn;
      chartstep_c24_test2_SysIntegrat(&i);
    }

    if (rtb_inputevents_at[1U] != 0) {
      i = test2_SysInte_event_ChargingEvt;
      chartstep_c24_test2_SysIntegrat(&i);
    }

    if (rtb_inputevents_at[2U] != 0) {
      i = test2_SysIntegr_event_HomingEvt;
      chartstep_c24_test2_SysIntegrat(&i);
    }

    if (rtb_inputevents_at[3U] != 0) {
      i = test2_SysInt_event_ForceStopEvt;
      chartstep_c24_test2_SysIntegrat(&i);
    }

    if (rtb_inputevents_at[4U] != 0) {
      i = test2_SysInte_event_UpdateEvt_h;
      chartstep_c24_test2_SysIntegrat(&i);
    }
  }

  for (i = 0; i < 5; i++) {
    test2_SysIntegration_PrevZCX.MotorRunDriver_Trig_ZCE[i] =
      rtb_HiddenBuf_InsertedFor_Motor[i];
  }

  /* DiscretePulseGenerator: '<S83>/Pulse Generator' */
  i = ((test2_SysIntegration_DW.clockTickCounter_m < 1) &&
       (test2_SysIntegration_DW.clockTickCounter_m >= 0));
  if (test2_SysIntegration_DW.clockTickCounter_m >= 1) {
    test2_SysIntegration_DW.clockTickCounter_m = 0;
  } else {
    test2_SysIntegration_DW.clockTickCounter_m++;
  }

  /* End of DiscretePulseGenerator: '<S83>/Pulse Generator' */

  /* SignalConversion: '<S83>/HiddenBuf_InsertedFor_Chart_at_inport_5' incorporates:
   *  DataTypeConversion: '<S83>/Data Type Conversion'
   */
  rtb_HiddenBuf_InsertedFor_Cha_0 = (i != 0);

  /* Chart: '<S83>/Chart' incorporates:
   *  TriggerPort: '<S102>/input events'
   */
  rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_n[0] ==
                       POS_ZCSIG) != (int32_T)
                      test2_SysIntegration_B.bitsForTID4.ServoOnEvt) &&
                     (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_n[0] !=
                      UNINITIALIZED_ZCSIG));
  d_tf = rtb_PopAlarmEvt;
  zcEvent_idx_0 = rtb_PopAlarmEvt;
  rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_n[1] ==
                       POS_ZCSIG) != (int32_T)rtb_HiddenBuf_InsertedFor_Cha_0) &&
                     (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_n[1] !=
                      UNINITIALIZED_ZCSIG));
  d_tf = (d_tf || rtb_PopAlarmEvt);
  if (d_tf) {
    i = 0;

    /* SignalConversion: '<S83>/HiddenBuf_InsertedFor_Chart_at_inport_5' */
    if ((int8_T)(zcEvent_idx_0 ? test2_SysIntegration_B.bitsForTID4.ServoOnEvt ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      i = 1;
      sfEvent_h = test2_SysInte_event_PerfEvalEvt;
      chartstep_c27_test2_SysIntegrat(&sfEvent_h);
    }

    if ((int8_T)(rtb_PopAlarmEvt ? rtb_HiddenBuf_InsertedFor_Cha_0 ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      i = 1;
      sfEvent_h = test2_SysInte_event_UpdateEvt_e;
      chartstep_c27_test2_SysIntegrat(&sfEvent_h);
    }

    if ((i != 0) && (test2_SysIntegration_DW.OcclusionJudgeEvtEventCounter > 0U))
    {
      test2_SysIntegration_B.bitsForTID0.OcclusionJudgeEvt =
        !test2_SysIntegration_B.bitsForTID0.OcclusionJudgeEvt;
      test2_SysIntegration_DW.OcclusionJudgeEvtEventCounter--;
    }
  }

  /* Chart: '<S98>/Chart' incorporates:
   *  TriggerPort: '<S99>/input events'
   */
  zcEvent_idx_0 = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_p[0] ==
                     POS_ZCSIG) != (int32_T)test2_SysIntegration_B.UnitDelay2_j)
                   && (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_p[0] !=
                       UNINITIALIZED_ZCSIG));
  zcEvent_idx_1 = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_p[1] ==
                     POS_ZCSIG) != (int32_T)
                    test2_SysIntegration_B.bitsForTID0.OcclusionJudgeEvt) &&
                   (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_p[1] !=
                    UNINITIALIZED_ZCSIG));

  /* Chart: '<S83>/Chart' incorporates:
   *  TriggerPort: '<S102>/input events'
   */
  /* SignalConversion: '<S83>/HiddenBuf_InsertedFor_Chart_at_inport_5' */
  test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_n[0] =
    test2_SysIntegration_B.bitsForTID4.ServoOnEvt;
  test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_n[1] =
    rtb_HiddenBuf_InsertedFor_Cha_0;

  /* Chart: '<S98>/Chart' incorporates:
   *  TriggerPort: '<S99>/input events'
   */
  if (zcEvent_idx_0 || zcEvent_idx_1) {
    if ((int8_T)(zcEvent_idx_0 ? test2_SysIntegration_B.UnitDelay2_j ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      i = test2_SysInteg_event_DiagClrEvt;
      chartstep_c25_test2_SysIntegrat(&i);
    }

    if ((int8_T)(zcEvent_idx_1 ?
                 test2_SysIntegration_B.bitsForTID0.OcclusionJudgeEvt ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      i = test2_SysInte_event_OccJudgeEvt;
      chartstep_c25_test2_SysIntegrat(&i);
    }
  }

  test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_p[0] =
    test2_SysIntegration_B.UnitDelay2_j;
  test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_p[1] =
    test2_SysIntegration_B.bitsForTID0.OcclusionJudgeEvt;
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[5] == 0) {
    /* Chart: '<Root>/MsgRouter5' */
    if (test2_SysIntegration_DW.bitsForTID5.is_active_c52_test2_SysIntegrat ==
        0U) {
      test2_SysIntegration_DW.bitsForTID5.is_active_c52_test2_SysIntegrat = 1;
      test2_SysIntegration_B.Group1AlarmMsgOut_d.Head.MsgId = 0U;
      test2_SysIntegration_B.Group1AlarmMsgOut_d.Head.OpCode = 0U;
      test2_SysIntegration_B.Group1AlarmMsgOut_d.Body.Data = 0U;
      test2_SysIntegration_DW.prevMsg1Id_la =
        test2_SysIntegration_B.BubbleDetectionMsg.Head.MsgId;
      test2_SysIntegration_DW.prevMsg2Id_f =
        test2_SysIntegration_B.OcclusionDiagMsg.Head.MsgId;
    } else if (test2_SysIntegration_DW.prevMsg1Id_la !=
               test2_SysIntegration_B.BubbleDetectionMsg.Head.MsgId) {
      test2_SysIntegration_DW.prevMsg1Id_la =
        test2_SysIntegration_B.BubbleDetectionMsg.Head.MsgId;
      i = (int32_T)(test2_SysIntegration_B.Group1AlarmMsgOut_d.Head.MsgId + 1U);
      if ((uint32_T)i > 255U) {
        i = 255;
      }

      test2_SysIntegration_B.Group1AlarmMsgOut_d.Head.MsgId = (uint8_T)((uint8_T)
        i % MAX_uint8_T);
      test2_SysIntegration_B.Group1AlarmMsgOut_d.Head.OpCode =
        test2_SysIntegration_B.BubbleDetectionMsg.Head.OpCode;
      test2_SysIntegration_B.Group1AlarmMsgOut_d.Body =
        test2_SysIntegration_B.BubbleDetectionMsg.Body;
    } else {
      if (test2_SysIntegration_DW.prevMsg2Id_f !=
          test2_SysIntegration_B.OcclusionDiagMsg.Head.MsgId) {
        test2_SysIntegration_DW.prevMsg2Id_f =
          test2_SysIntegration_B.OcclusionDiagMsg.Head.MsgId;
        i = (int32_T)(test2_SysIntegration_B.Group1AlarmMsgOut_d.Head.MsgId + 1U);
        if ((uint32_T)i > 255U) {
          i = 255;
        }

        test2_SysIntegration_B.Group1AlarmMsgOut_d.Head.MsgId = (uint8_T)
          ((uint8_T)i % MAX_uint8_T);
        test2_SysIntegration_B.Group1AlarmMsgOut_d.Head.OpCode =
          test2_SysIntegration_B.OcclusionDiagMsg.Head.OpCode;
        test2_SysIntegration_B.Group1AlarmMsgOut_d.Body =
          test2_SysIntegration_B.OcclusionDiagMsg.Body;
      }
    }

    /* End of Chart: '<Root>/MsgRouter5' */
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[3] == 0) {
    /* DataTypeConversion: '<S67>/Data Type Conversion1' incorporates:
     *  DiscreteTransferFcn: '<S67>/Discrete Transfer Fcn'
     */
    denAccum = floorf(0.3577F *
                      test2_SysIntegration_DW.DiscreteTransferFcn_states[0] +
                      0.154F *
                      test2_SysIntegration_DW.DiscreteTransferFcn_states[1]);
    if (rtIsNaNF(denAccum) || rtIsInfF(denAccum)) {
      denAccum = 0.0F;
    } else {
      denAccum = fmodf(denAccum, 65536.0F);
    }

    test2_SysIntegration_B.DataTypeConversion1_a = (int16_T)(denAccum < 0.0F ?
      (int32_T)(int16_T)-(int16_T)(uint16_T)-denAccum : (int32_T)(int16_T)
      (uint16_T)denAccum);

    /* End of DataTypeConversion: '<S67>/Data Type Conversion1' */
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    /* Gain: '<S67>/Gain' */
    test2_SysIntegration_B.Gain = (uint16_T)(10U *
      test2_SysIntegration_B.VarSet.SysSetting.SensitivityLevel);
  }

  /* DiscretePulseGenerator: '<S67>/Pulse Generator' */
  i = ((test2_SysIntegration_DW.clockTickCounter_g < 10) &&
       (test2_SysIntegration_DW.clockTickCounter_g >= 0));
  if (test2_SysIntegration_DW.clockTickCounter_g >= 19) {
    test2_SysIntegration_DW.clockTickCounter_g = 0;
  } else {
    test2_SysIntegration_DW.clockTickCounter_g++;
  }

  /* End of DiscretePulseGenerator: '<S67>/Pulse Generator' */

  /* SignalConversion: '<S67>/HiddenBuf_InsertedFor_PressureSingularityDetector_at_inport_3' incorporates:
   *  DataTypeConversion: '<S67>/Data Type Conversion2'
   */
  rtb_HiddenBuf_InsertedFor_Motor[0] =
    test2_SysIntegration_B.bitsForTID4.AirExpelStopEvt;
  rtb_HiddenBuf_InsertedFor_Motor[1] =
    test2_SysIntegration_B.bitsForTID0.boolMotorServoEnable;
  rtb_HiddenBuf_InsertedFor_Motor[2] =
    test2_SysIntegration_B.bitsForTID0.boolMotorServoEnable;
  rtb_HiddenBuf_InsertedFor_Motor[3] =
    test2_SysIntegration_B.bitsForTID5.boolShaftEnc;
  rtb_HiddenBuf_InsertedFor_Motor[4] = (i != 0);

  /* Chart: '<S67>/PressureSingularityDetector' incorporates:
   *  TriggerPort: '<S70>/input events'
   */
  d_tf = false;
  for (i = 0; i < 5; i++) {
    rtb_PopAlarmEvt =
      (((test2_SysIntegration_PrevZCX.PressureSingularityDetector_Tri[i] ==
         POS_ZCSIG) != (int32_T)rtb_HiddenBuf_InsertedFor_Motor[i]) &&
       (test2_SysIntegration_PrevZCX.PressureSingularityDetector_Tri[i] !=
        UNINITIALIZED_ZCSIG));
    d_tf = (d_tf || rtb_PopAlarmEvt);
    zcEvent[i] = rtb_PopAlarmEvt;
  }

  if (d_tf) {
    for (i = 0; i < 5; i++) {
      rtb_inputevents_at[i] = (int8_T)(zcEvent[i] ?
        rtb_HiddenBuf_InsertedFor_Motor[i] ? RISING_ZCEVENT : FALLING_ZCEVENT :
        NO_ZCEVENT);
    }

    if (rtb_inputevents_at[0U] != 0) {
      i = test2__event_AirExpelStopAckEvt;
      chartstep_c39_test2_SysIntegrat(&i);
    }

    if (rtb_inputevents_at[1U] == 1) {
      i = test2_event_DeliveryStartAckEvt;
      chartstep_c39_test2_SysIntegrat(&i);
    }

    if (rtb_inputevents_at[2U] == -1) {
      i = test2__event_DeliveryStopAckEvt;
      chartstep_c39_test2_SysIntegrat(&i);
    }

    if (rtb_inputevents_at[3U] == 1) {
      i = test2_S_event_ShaftEncoderPulse;
      chartstep_c39_test2_SysIntegrat(&i);
    }

    if (rtb_inputevents_at[4U] != 0) {
      if (test2_SysIntegration_DW.temporalCounter_i1_d5 < 255U) {
        test2_SysIntegration_DW.temporalCounter_i1_d5++;
      }

      i = test2_SysInteg_event_UpdateTick;
      chartstep_c39_test2_SysIntegrat(&i);
    }
  }

  for (i = 0; i < 5; i++) {
    test2_SysIntegration_PrevZCX.PressureSingularityDetector_Tri[i] =
      rtb_HiddenBuf_InsertedFor_Motor[i];
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    /* Chart: '<S113>/MemoryFilter' */
    if (test2_SysIntegration_DW.temporalCounter_i1_pl < 1023U) {
      test2_SysIntegration_DW.temporalCounter_i1_pl++;
    }

    if (test2_SysIntegration_DW.bitsForTID4.is_active_c32_test2_SysIntegrat ==
        0U) {
      test2_SysIntegration_DW.bitsForTID4.is_active_c32_test2_SysIntegrat = 1;
      test2_SysIntegration_DW.bitsForTID4.is_c32_test2_SysIntegration =
        test2_SysIntegration_IN_Init_b;
      for (i = 0; i < 8; i++) {
        test2_SysIntegration_DW.prevMsgInIdVector[i] = 0U;
        test2_SysIntegration_B.xLevelAlarmPushMsg[i] = 0U;
      }
    } else if (test2_SysIntegration_DW.bitsForTID4.is_c32_test2_SysIntegration ==
               test2_SysIntegr_IN_FMCodeMemory) {
      if (test2_SysIntegration_DW.temporalCounter_i1_pl >= 600U) {
        test2_SysIntegration_DW.bitsForTID4.is_c32_test2_SysIntegration =
          test2_SysIntegr_IN_FMCodeMemory;
        test2_SysIntegration_DW.temporalCounter_i1_pl = 0U;
        for (i = 0; i < 24; i++) {
          tmp_0[i] = test2_SysIntegration_DW.AlarmFMCodeMemory[i];
        }

        test2_SysIntegration_ShiftUp(tmp_0,
          test2_SysIntegration_DW.AlarmFMCodeMemory);
      } else {
        currMsgInIdVector[0] = rtb_BusConversion_InsertedFor_0;
        currMsgInIdVector[1] =
          test2_SysIntegration_B.Group1AlarmMsgOut_f.Head.MsgId;
        currMsgInIdVector[2] =
          test2_SysIntegration_B.Group1AlarmMsgOut_h.Head.MsgId;
        currMsgInIdVector[3] =
          test2_SysIntegration_B.Group1AlarmMsgOut_b.Head.MsgId;
        currMsgInIdVector[4] =
          test2_SysIntegration_B.Group1AlarmMsgOut_m.Head.MsgId;
        currMsgInIdVector[5] =
          test2_SysIntegration_B.Group1AlarmMsgOut_d.Head.MsgId;
        currMsgInIdVector[6] = test2_SysIntegration_B.SysDiagMsgOut_k.Head.MsgId;
        currMsgInIdVector[7] = test2_SysIntegration_B.PressureDiagMsg.Head.MsgId;
        if (!test2_SysIntegration_isequal_o(currMsgInIdVector,
             test2_SysIntegration_DW.prevMsgInIdVector)) {
          for (i = 0; i < 8; i++) {
            test2_SysIntegration_DW.prevMsgInIdVector[i] = currMsgInIdVector[i];
          }

          zcEvent_idx_0 = false;
          i = 1;
          exitg1 = false;
          while ((!exitg1) && (i < 25)) {
            if (test2_SysIntegration_DW.AlarmFMCodeMemory[i - 1] ==
                rtb_BusConversion_InsertedFor_1) {
              zcEvent_idx_0 = true;
              exitg1 = true;
            } else {
              i++;
            }
          }

          zcEvent_idx_1 = false;
          i = 1;
          exitg1 = false;
          while ((!exitg1) && (i < 25)) {
            if (test2_SysIntegration_DW.AlarmFMCodeMemory[i - 1] ==
                test2_SysIntegration_B.Group1AlarmMsgOut_f.Body.Data) {
              zcEvent_idx_1 = true;
              exitg1 = true;
            } else {
              i++;
            }
          }

          rtb_PopAlarmEvt = false;
          i = 1;
          exitg1 = false;
          while ((!exitg1) && (i < 25)) {
            if (test2_SysIntegration_DW.AlarmFMCodeMemory[i - 1] ==
                test2_SysIntegration_B.Group1AlarmMsgOut_h.Body.Data) {
              rtb_PopAlarmEvt = true;
              exitg1 = true;
            } else {
              i++;
            }
          }

          d_tf = false;
          i = 1;
          exitg1 = false;
          while ((!exitg1) && (i < 25)) {
            if (test2_SysIntegration_DW.AlarmFMCodeMemory[i - 1] ==
                test2_SysIntegration_B.Group1AlarmMsgOut_b.Body.Data) {
              d_tf = true;
              exitg1 = true;
            } else {
              i++;
            }
          }

          rtb_HiddenBuf_InsertedFor_Cha_0 = false;
          i = 1;
          exitg1 = false;
          while ((!exitg1) && (i < 25)) {
            if (test2_SysIntegration_DW.AlarmFMCodeMemory[i - 1] ==
                test2_SysIntegration_B.Group1AlarmMsgOut_m.Body.Data) {
              rtb_HiddenBuf_InsertedFor_Cha_0 = true;
              exitg1 = true;
            } else {
              i++;
            }
          }

          f_tf = false;
          i = 1;
          exitg1 = false;
          while ((!exitg1) && (i < 25)) {
            if (test2_SysIntegration_DW.AlarmFMCodeMemory[i - 1] ==
                test2_SysIntegration_B.Group1AlarmMsgOut_d.Body.Data) {
              f_tf = true;
              exitg1 = true;
            } else {
              i++;
            }
          }

          g_tf = false;
          i = 1;
          exitg1 = false;
          while ((!exitg1) && (i < 25)) {
            if (test2_SysIntegration_DW.AlarmFMCodeMemory[i - 1] ==
                test2_SysIntegration_B.SysDiagMsgOut_k.Body.Data) {
              g_tf = true;
              exitg1 = true;
            } else {
              i++;
            }
          }

          h_tf = false;
          i = 1;
          exitg1 = false;
          while ((!exitg1) && (i < 25)) {
            if (test2_SysIntegration_DW.AlarmFMCodeMemory[i - 1] ==
                test2_SysIntegration_B.PressureDiagMsg.Body.Data) {
              h_tf = true;
              exitg1 = true;
            } else {
              i++;
            }
          }

          test2_SysIntegration_B.xLevelAlarmPushMsg[0] = (uint8_T)
            (rtb_BusConversion_InsertedFor_1 * !zcEvent_idx_0);
          test2_SysIntegration_B.xLevelAlarmPushMsg[1] = (uint8_T)
            (test2_SysIntegration_B.Group1AlarmMsgOut_f.Body.Data *
             !zcEvent_idx_1);
          test2_SysIntegration_B.xLevelAlarmPushMsg[2] = (uint8_T)
            (test2_SysIntegration_B.Group1AlarmMsgOut_h.Body.Data *
             !rtb_PopAlarmEvt);
          test2_SysIntegration_B.xLevelAlarmPushMsg[3] = (uint8_T)
            (test2_SysIntegration_B.Group1AlarmMsgOut_b.Body.Data * !d_tf);
          test2_SysIntegration_B.xLevelAlarmPushMsg[4] = (uint8_T)
            (test2_SysIntegration_B.Group1AlarmMsgOut_m.Body.Data *
             !rtb_HiddenBuf_InsertedFor_Cha_0);
          test2_SysIntegration_B.xLevelAlarmPushMsg[5] = (uint8_T)
            (test2_SysIntegration_B.Group1AlarmMsgOut_d.Body.Data * !f_tf);
          test2_SysIntegration_B.xLevelAlarmPushMsg[6] = (uint8_T)
            (test2_SysIntegration_B.SysDiagMsgOut_k.Body.Data * !g_tf);
          test2_SysIntegration_B.xLevelAlarmPushMsg[7] = (uint8_T)
            (test2_SysIntegration_B.PressureDiagMsg.Body.Data * !h_tf);
          for (i = 0; i < 8; i++) {
            currMsgInIdVector[i] = 0U;
          }

          if (!test2_SysIntegration_isequal_o
              (test2_SysIntegration_B.xLevelAlarmPushMsg, currMsgInIdVector)) {
            test2_SysI_NonZeroElementPushIn
              (test2_SysIntegration_DW.AlarmFMCodeMemory,
               test2_SysIntegration_B.xLevelAlarmPushMsg);
            test2_SysIntegration_DW.sendMsgEvtEventCounter++;
          }
        }
      }
    } else {
      test2_SysIntegration_DW.prevMsgInIdVector[0] =
        rtb_BusConversion_InsertedFor_0;
      test2_SysIntegration_DW.prevMsgInIdVector[1] =
        test2_SysIntegration_B.Group1AlarmMsgOut_f.Head.MsgId;
      test2_SysIntegration_DW.prevMsgInIdVector[2] =
        test2_SysIntegration_B.Group1AlarmMsgOut_h.Head.MsgId;
      test2_SysIntegration_DW.prevMsgInIdVector[3] =
        test2_SysIntegration_B.Group1AlarmMsgOut_b.Head.MsgId;
      test2_SysIntegration_DW.prevMsgInIdVector[4] =
        test2_SysIntegration_B.Group1AlarmMsgOut_m.Head.MsgId;
      test2_SysIntegration_DW.prevMsgInIdVector[5] =
        test2_SysIntegration_B.Group1AlarmMsgOut_d.Head.MsgId;
      test2_SysIntegration_DW.prevMsgInIdVector[6] =
        test2_SysIntegration_B.SysDiagMsgOut_k.Head.MsgId;
      test2_SysIntegration_DW.prevMsgInIdVector[7] =
        test2_SysIntegration_B.PressureDiagMsg.Head.MsgId;
      test2_SysIntegration_DW.bitsForTID4.is_c32_test2_SysIntegration =
        test2_SysIntegr_IN_FMCodeMemory;
      test2_SysIntegration_DW.temporalCounter_i1_pl = 0U;
      for (i = 0; i < 24; i++) {
        tmp_0[i] = test2_SysIntegration_DW.AlarmFMCodeMemory[i];
      }

      test2_SysIntegration_ShiftUp(tmp_0,
        test2_SysIntegration_DW.AlarmFMCodeMemory);
    }

    if (test2_SysIntegration_DW.sendMsgEvtEventCounter > 0U) {
      test2_SysIntegration_B.bitsForTID4.sendMsgEvt =
        !test2_SysIntegration_B.bitsForTID4.sendMsgEvt;
      test2_SysIntegration_DW.sendMsgEvtEventCounter--;
    }

    /* End of Chart: '<S113>/MemoryFilter' */

    /* UnitDelay: '<S113>/Unit Delay' */
    rtb_PopAlarmEvt = test2_SysIntegration_DW.bitsForTID4.UnitDelay_DSTATE_ft;

    /* Chart: '<S113>/Buffer' incorporates:
     *  TriggerPort: '<S118>/input events'
     */
    zcEvent_idx_0 = (((test2_SysIntegration_PrevZCX.Buffer_Trig_ZCE[0] ==
                       POS_ZCSIG) != (int32_T)rtb_PopAlarmEvt) &&
                     (test2_SysIntegration_PrevZCX.Buffer_Trig_ZCE[0] !=
                      UNINITIALIZED_ZCSIG));
    zcEvent_idx_1 = (((test2_SysIntegration_PrevZCX.Buffer_Trig_ZCE[1] ==
                       POS_ZCSIG) != (int32_T)
                      test2_SysIntegration_B.bitsForTID4.sendMsgEvt) &&
                     (test2_SysIntegration_PrevZCX.Buffer_Trig_ZCE[1] !=
                      UNINITIALIZED_ZCSIG));
    if (zcEvent_idx_0 || zcEvent_idx_1) {
      if ((int8_T)(zcEvent_idx_0 ? rtb_PopAlarmEvt ? RISING_ZCEVENT :
                   FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
        i = test2_SysInte_event_PopAlarmEvt;
        chartstep_c31_test2_SysIntegrat(&i);
      }

      if ((int8_T)(zcEvent_idx_1 ? test2_SysIntegration_B.bitsForTID4.sendMsgEvt
                   ? RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
        i = test2_SysI_event_RecvDiagMsgEvt;
        chartstep_c31_test2_SysIntegrat(&i);
      }
    }

    test2_SysIntegration_PrevZCX.Buffer_Trig_ZCE[0] = rtb_PopAlarmEvt;
    test2_SysIntegration_PrevZCX.Buffer_Trig_ZCE[1] =
      test2_SysIntegration_B.bitsForTID4.sendMsgEvt;

    /* BusCreator: '<S113>/BusConversion_InsertedFor_MsgAdaptor_at_inport_1' */
    rtb_Body_n.Data = test2_SysIntegration_B.AlarmCtrlMsgOut.Body.Data[0];

    /* BusCreator: '<S113>/BusConversion_InsertedFor_MsgAdaptor_at_inport_1' */
    test2_SysIntegration_B.BusConversion_InsertedFor_MsgAd.Head =
      test2_SysIntegration_B.AlarmCtrlMsgOut.Head;
    test2_SysIntegration_B.BusConversion_InsertedFor_MsgAd.Body = rtb_Body_n;
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[5] == 0) {
    /* Chart: '<S113>/MsgAdaptor' */
    if (test2_SysIntegration_DW.bitsForTID5.is_active_c33_test2_SysIntegrat ==
        0U) {
      test2_SysIntegration_DW.bitsForTID5.is_active_c33_test2_SysIntegrat = 1;
      test2_SysIntegration_B.AlarmOpMsgOut.Head.MsgId = 0U;
      test2_SysIntegration_B.AlarmOpMsgOut.Head.OpCode = 0U;
      test2_SysIntegration_B.AlarmOpMsgOut.Body.Data = 0U;
      test2_SysIntegration_DW.prevInput1MsgId =
        test2_SysIntegration_B.AlarmACKMsgOut.Head.MsgId;
      test2_SysIntegration_DW.prevInput2MsgId =
        test2_SysIntegration_B.BusConversion_InsertedFor_MsgAd.Head.MsgId;
    } else if (test2_SysIntegration_DW.prevInput1MsgId !=
               test2_SysIntegration_B.AlarmACKMsgOut.Head.MsgId) {
      test2_SysIntegration_DW.prevInput1MsgId =
        test2_SysIntegration_B.AlarmACKMsgOut.Head.MsgId;
      test2_SysIntegration_B.AlarmOpMsgOut.Head.MsgId = (uint8_T)((uint8_T)
        (test2_SysIntegration_B.AlarmOpMsgOut.Head.MsgId + 1U) % MAX_uint8_T);
      test2_SysIntegration_B.AlarmOpMsgOut.Head.OpCode = 1U;
      test2_SysIntegration_B.AlarmOpMsgOut.Body =
        test2_SysIntegration_B.AlarmACKMsgOut.Body;
    } else {
      if (test2_SysIntegration_DW.prevInput2MsgId !=
          test2_SysIntegration_B.BusConversion_InsertedFor_MsgAd.Head.MsgId) {
        test2_SysIntegration_DW.prevInput2MsgId =
          test2_SysIntegration_B.BusConversion_InsertedFor_MsgAd.Head.MsgId;
        zcEvent_idx_0 = false;
        zcEvent_idx_1 = true;
        if (!(test2_SysIntegration_B.BusConversion_InsertedFor_MsgAd.Head.OpCode
              == 250)) {
          zcEvent_idx_1 = false;
        }

        if (zcEvent_idx_1) {
          zcEvent_idx_0 = true;
        }

        if (zcEvent_idx_0) {
          test2_SysIntegration_B.AlarmOpMsgOut.Head.MsgId = (uint8_T)((uint8_T)
            (test2_SysIntegration_B.AlarmOpMsgOut.Head.MsgId + 1U) % MAX_uint8_T);
          test2_SysIntegration_B.AlarmOpMsgOut.Head.OpCode = 0U;
          test2_SysIntegration_B.AlarmOpMsgOut.Body =
            test2_SysIntegration_B.BusConversion_InsertedFor_MsgAd.Body;
          zcEvent_idx_0 = false;
          zcEvent_idx_1 = true;
          if (!(test2_SysIntegration_B.AlarmOpMsgOut.Body.Data == 2)) {
            zcEvent_idx_1 = false;
          }

          if (zcEvent_idx_1) {
            zcEvent_idx_0 = true;
          }

          if (zcEvent_idx_0) {
            test2_SysIntegration_DW.OcclusionObservationCancelEvent++;
          }
        }
      }
    }

    if (test2_SysIntegration_DW.OcclusionObservationCancelEvent > 0U) {
      test2_SysIntegration_B.OcclusionObservationCancel =
        !test2_SysIntegration_B.OcclusionObservationCancel;
      test2_SysIntegration_DW.OcclusionObservationCancelEvent--;
    }

    /* End of Chart: '<S113>/MsgAdaptor' */

    /* DataTypeConversion: '<S112>/Data Type Conversion1' */
    test2_SysIntegration_B.BusCreator.OpCode =
      (test2_SysIntegration_B.AlarmOpMsgOut.Head.OpCode != 0);

    /* BusCreator: '<S112>/Bus Creator' */
    test2_SysIntegration_B.BusCreator.MsgId =
      test2_SysIntegration_B.AlarmOpMsgOut.Head.MsgId;
    test2_SysIntegration_B.BusCreator.FMCode =
      test2_SysIntegration_B.AlarmOpMsgOut.Body.Data;
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[1] == 0) {
    /* Chart: '<S112>/Chart' */
    if (test2_SysIntegration_DW.bitsForTID1.is_active_c19_test2_SysIntegrat ==
        0U) {
      test2_SysIntegration_DW.bitsForTID1.is_active_c19_test2_SysIntegrat = 1;
      test2_SysI_enter_atomic_TaskAct();
      test2_Sy_enter_internal_TaskAct();
    } else {
      test2_SysIntegration_TaskAct();
    }

    if (test2_SysIntegration_DW.AlarmCtrlEvtEventCounter > 0U) {
      test2_SysIntegration_B.bitsForTID1.AlarmCtrlEvt =
        !test2_SysIntegration_B.bitsForTID1.AlarmCtrlEvt;
      test2_SysIntegration_DW.AlarmCtrlEvtEventCounter--;
    }

    if (test2_SysIntegration_DW.HighLevelAlarmEvtStartEventCoun > 0U) {
      test2_SysIntegration_B.bitsForTID1.HighLevelAlarmEvtStart =
        !test2_SysIntegration_B.bitsForTID1.HighLevelAlarmEvtStart;
      test2_SysIntegration_DW.HighLevelAlarmEvtStartEventCoun--;
    }

    if (test2_SysIntegration_DW.HighLevelAlarmEvtStopEventCount > 0U) {
      test2_SysIntegration_B.bitsForTID1.HighLevelAlarmEvtStop =
        !test2_SysIntegration_B.bitsForTID1.HighLevelAlarmEvtStop;
      test2_SysIntegration_DW.HighLevelAlarmEvtStopEventCount--;
    }

    /* End of Chart: '<S112>/Chart' */

    /* Chart: '<S2>/Chart' incorporates:
     *  TriggerPort: '<S25>/event'
     */
    if (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_pt == POS_ZCSIG) !=
         (int32_T)test2_SysIntegration_B.bitsForTID1.AlarmCtrlEvt) &&
        (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_pt != UNINITIALIZED_ZCSIG))
    {
      test2_SysIntegration_alarmIt
        (test2_SysIntegration_B.AlarmCtrlData.AlarmLevel,
         test2_SysIntegration_B.AlarmCtrlData.boolMaster);
    }

    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_pt =
      test2_SysIntegration_B.bitsForTID1.AlarmCtrlEvt;
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    /* Chart: '<S32>/Chart' incorporates:
     *  TriggerPort: '<S33>/PushEvent'
     */
    if (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_lg == POS_ZCSIG) !=
         (int32_T)test2_SysIntegration_B.bitsForTID4.sendBleDataEvt) &&
        (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_lg != UNINITIALIZED_ZCSIG))
    {
      memcpy(&DataOut[0], &test2_SysIntegration_B.BleMsgOut_c[0], 224U * sizeof
             (uint8_T));
      test2_SysIntegratio_sendBleData(DataOut);
    }

    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_lg =
      test2_SysIntegration_B.bitsForTID4.sendBleDataEvt;

    /* Chart: '<S30>/Chart' */
    test2_SysIntegration_B.bitsForTID4.BleConnStatus =
      test2_SysInteg_ChkBleConnection();

    /* Chart: '<S34>/Chart' incorporates:
     *  TriggerPort: '<S35>/Pop'
     */
    if (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_ng == POS_ZCSIG) !=
         (int32_T)test2_SysIntegration_B.bitsForTID4.getBleDataEvt) &&
        (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_ng != UNINITIALIZED_ZCSIG))
    {
      test2_SysIntegration_GetBleData(test2_SysIntegration_DW.BleDataFrameId,
        &zcEvent_idx_0, DataOut, &LogAvailableFlag);
      test2_SysIntegration_DW.BleDataFrameId = LogAvailableFlag;
      if (zcEvent_idx_0) {
        i = (int32_T)(test2_SysIntegration_B.BleMsgOut.Head.MsgId + 1U);
        if ((uint32_T)i > 255U) {
          i = 255;
        }

        test2_SysIntegration_B.BleMsgOut.Head.MsgId = (uint8_T)((uint8_T)i %
          MAX_uint8_T);
        test2_SysIntegration_B.BleMsgOut.Head.OpCode = 0U;
        memcpy(&test2_SysIntegration_B.BleMsgOut.Body.Data[0], &DataOut[0], 224U
               * sizeof(uint8_T));
      }
    }

    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_ng =
      test2_SysIntegration_B.bitsForTID4.getBleDataEvt;
  }

  /* DiscretePulseGenerator: '<S4>/Pulse Generator' */
  i = ((test2_SysIntegration_DW.clockTickCounter_o < 100) &&
       (test2_SysIntegration_DW.clockTickCounter_o >= 0));
  if (test2_SysIntegration_DW.clockTickCounter_o >= 199) {
    test2_SysIntegration_DW.clockTickCounter_o = 0;
  } else {
    test2_SysIntegration_DW.clockTickCounter_o++;
  }

  /* End of DiscretePulseGenerator: '<S4>/Pulse Generator' */

  /* Chart: '<S4>/Chart' incorporates:
   *  TriggerPort: '<S37>/input events'
   */
  zcEvent_idx_0 = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_o[0] ==
                     POS_ZCSIG) != (int32_T)
                    test2_SysIntegration_B.bitsForTID0.EncClrEvt) &&
                   (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_o[0] !=
                    UNINITIALIZED_ZCSIG));
  zcEvent_idx_1 = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_o[1] ==
                     POS_ZCSIG) != (int32_T)
                    test2_SysIntegration_B.bitsForTID0.EncRstEvt) &&
                   (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_o[1] !=
                    UNINITIALIZED_ZCSIG));

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  rtb_PopAlarmEvt = (((i != 0) !=
                      (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_o[2] ==
                       POS_ZCSIG)) &&
                     (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_o[2] !=
                      UNINITIALIZED_ZCSIG));
  if (zcEvent_idx_0 || zcEvent_idx_1 || rtb_PopAlarmEvt) {
    if ((int8_T)(zcEvent_idx_0 ? test2_SysIntegration_B.bitsForTID0.EncClrEvt ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      sfEvent_h = test2_SysIntegration_event_Rst1;
      chartstep_c45_test2_SysIntegrat(&sfEvent_h);
    }

    if ((int8_T)(zcEvent_idx_1 ? test2_SysIntegration_B.bitsForTID0.EncRstEvt ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      sfEvent_h = test2_SysIntegration_event_Rst2;
      chartstep_c45_test2_SysIntegrat(&sfEvent_h);
    }

    /* DataTypeConversion: '<S4>/Data Type Conversion' */
    if ((int8_T)(rtb_PopAlarmEvt ? i != 0 ? RISING_ZCEVENT : FALLING_ZCEVENT :
                 NO_ZCEVENT) != 0) {
      sfEvent_h = test2_SysInteg_event_UpDateTick;
      chartstep_c45_test2_SysIntegrat(&sfEvent_h);
    }
  }

  test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_o[0] =
    test2_SysIntegration_B.bitsForTID0.EncClrEvt;
  test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_o[1] =
    test2_SysIntegration_B.bitsForTID0.EncRstEvt;

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_o[2] = (ZCSigState)(i != 0);
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    /* Chart: '<S45>/Chart' incorporates:
     *  TriggerPort: '<S46>/PushEvent'
     */
    if (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_l == POS_ZCSIG) !=
         (int32_T)test2_SysIntegration_B.bitsForTID4.LPSwitchCtrlEvt) &&
        (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_l != UNINITIALIZED_ZCSIG))
    {
      test2_SysIntegration_LPCtrl(test2_SysIntegration_B.SleepSec * 1000U,
        &zcEvent_idx_0, &elapsedTicks_d);
      if (!zcEvent_idx_0) {
        i = (int32_T)(test2_SysIntegration_B.LP2RTMsgOut_m.Head.MsgId + 1U);
        if ((uint32_T)i > 255U) {
          i = 255;
        }

        test2_SysIntegration_B.LP2RTMsgOut_m.Head.MsgId = (uint8_T)((uint8_T)i %
          MAX_uint8_T);
        test2_SysIntegration_B.LP2RTMsgOut_m.Body.Data = elapsedTicks_d;
      } else {
        test2_SysIntegration_B.LP2RTMsgOut_m.Body.Data = 0U;
      }
    }

    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_l =
      test2_SysIntegration_B.bitsForTID4.LPSwitchCtrlEvt;

    /* Chart: '<S47>/Chart' incorporates:
     *  TriggerPort: '<S48>/PushEvent'
     */
    if (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_nm == POS_ZCSIG) !=
         (int32_T)test2_SysIntegration_B.bitsForTID4.IOSwitchCtrlEvt) &&
        (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_nm != UNINITIALIZED_ZCSIG))
    {
      test2_SysIntegration_IOCtrl(test2_SysIntegration_B.bitsForTID4.IOSwitchCmd);
    }

    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_nm =
      test2_SysIntegration_B.bitsForTID4.IOSwitchCtrlEvt;
  }

  /* DiscretePulseGenerator: '<S92>/Pulse Generator' */
  i = ((test2_SysIntegration_DW.clockTickCounter_a < 100) &&
       (test2_SysIntegration_DW.clockTickCounter_a >= 0));
  if (test2_SysIntegration_DW.clockTickCounter_a >= 199) {
    test2_SysIntegration_DW.clockTickCounter_a = 0;
  } else {
    test2_SysIntegration_DW.clockTickCounter_a++;
  }

  /* End of DiscretePulseGenerator: '<S92>/Pulse Generator' */
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    /* DataTypeConversion: '<S92>/Data Type Conversion2' */
    test2_SysIntegration_B.bitsForTID4.DataTypeConversion2 =
      (test2_SysIntegration_B.VarSet.DoseCtrl.LargeDoseConfig.EffectiveDay != 0);
  }

  /* SignalConversion: '<S92>/HiddenBuf_InsertedFor_Chart_at_inport_9' incorporates:
   *  DataTypeConversion: '<S92>/Data Type Conversion1'
   */
  zcEvent_idx_1 = (i != 0);

  /* Chart: '<S92>/Chart' incorporates:
   *  TriggerPort: '<S93>/input events'
   */
  rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_k[0] ==
                       POS_ZCSIG) != (int32_T)zcEvent_idx_1) &&
                     (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_k[0] !=
                      UNINITIALIZED_ZCSIG));
  d_tf = rtb_PopAlarmEvt;
  zcEvent_idx_0 = rtb_PopAlarmEvt;

  /* SignalConversion: '<S92>/HiddenBuf_InsertedFor_Chart_at_inport_9' */
  rtb_PopAlarmEvt = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_k[1] ==
                       POS_ZCSIG) != (int32_T)
                      test2_SysIntegration_B.bitsForTID4.DataTypeConversion2) &&
                     (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_k[1] !=
                      UNINITIALIZED_ZCSIG));
  d_tf = (d_tf || rtb_PopAlarmEvt);
  if (d_tf) {
    if ((int8_T)(zcEvent_idx_0 ? zcEvent_idx_1 ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      chartstep_c21_test2_SysIntegrat();
    }

    /* SignalConversion: '<S92>/HiddenBuf_InsertedFor_Chart_at_inport_9' */
    if ((int8_T)(rtb_PopAlarmEvt ?
                 test2_SysIntegration_B.bitsForTID4.DataTypeConversion2 ?
                 RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) == -1) {
      chartstep_c21_test2_SysIntegrat();
    }
  }

  test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_k[0] = zcEvent_idx_1;

  /* SignalConversion: '<S92>/HiddenBuf_InsertedFor_Chart_at_inport_9' */
  test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_k[1] =
    test2_SysIntegration_B.bitsForTID4.DataTypeConversion2;
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[5] == 0) {
    /* Chart: '<Root>/MsgRouter6' */
    if (test2_SysIntegration_DW.bitsForTID5.is_active_c53_test2_SysIntegrat ==
        0U) {
      test2_SysIntegration_DW.bitsForTID5.is_active_c53_test2_SysIntegrat = 1;
      test2_SysIntegration_B.Group1DDSMsgOut.Head.MsgId = 0U;
      test2_SysIntegration_B.Group1DDSMsgOut.Head.OpCode = 0U;
      test2_SysIntegration_B.Group1DDSMsgOut.Body.DayInfo = 0U;
      test2_SysIntegration_B.Group1DDSMsgOut.Body.ResidueDoseEst = 0U;
      test2_SysIntegration_B.Group1DDSMsgOut.Body.TotalAmountAcc = 0U;
      test2_SysIntegration_B.Group1DDSMsgOut.Body.DailyAmountAcc = 0U;
      test2_SysIntegration_B.Group1DDSMsgOut.Body.LargeAmountAcc = 0U;
      test2_SysIntegration_DW.prevMsg1Id_c =
        test2_SysIntegration_B.DailyStatMsg.Head.MsgId;
      test2_SysIntegration_DW.prevMsg2Id_g =
        test2_SysIntegration_B.ResidueDoseTrimMsg.Head.MsgId;
    } else if (test2_SysIntegration_DW.prevMsg1Id_c !=
               test2_SysIntegration_B.DailyStatMsg.Head.MsgId) {
      test2_SysIntegration_DW.prevMsg1Id_c =
        test2_SysIntegration_B.DailyStatMsg.Head.MsgId;
      i = (int32_T)(test2_SysIntegration_B.Group1DDSMsgOut.Head.MsgId + 1U);
      if ((uint32_T)i > 255U) {
        i = 255;
      }

      test2_SysIntegration_B.Group1DDSMsgOut.Head.MsgId = (uint8_T)((uint8_T)i %
        MAX_uint8_T);
      test2_SysIntegration_B.Group1DDSMsgOut.Head.OpCode =
        test2_SysIntegration_B.DailyStatMsg.Head.OpCode;
      test2_SysIntegration_B.Group1DDSMsgOut.Body =
        test2_SysIntegration_B.DailyStatMsg.Body;
    } else {
      if (test2_SysIntegration_DW.prevMsg2Id_g !=
          test2_SysIntegration_B.ResidueDoseTrimMsg.Head.MsgId) {
        test2_SysIntegration_DW.prevMsg2Id_g =
          test2_SysIntegration_B.ResidueDoseTrimMsg.Head.MsgId;
        i = (int32_T)(test2_SysIntegration_B.Group1DDSMsgOut.Head.MsgId + 1U);
        if ((uint32_T)i > 255U) {
          i = 255;
        }

        test2_SysIntegration_B.Group1DDSMsgOut.Head.MsgId = (uint8_T)((uint8_T)i
          % MAX_uint8_T);
        test2_SysIntegration_B.Group1DDSMsgOut.Head.OpCode =
          test2_SysIntegration_B.ResidueDoseTrimMsg.Head.OpCode;
        test2_SysIntegration_B.Group1DDSMsgOut.Body =
          test2_SysIntegration_B.ResidueDoseTrimMsg.Body;
      }
    }

    /* End of Chart: '<Root>/MsgRouter6' */
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    /* Chart: '<S14>/MsgRouter2_100ms' */
    if (test2_SysIntegration_DW.bitsForTID4.is_c55_test2_SysIntegration == 1) {
      if (test2_SysIntegration_DW.prevMsg1Id_l !=
          test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Head.MsgId) {
        test2_SysIntegration_DW.prevMsg1Id_l =
          test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Head.MsgId;
        i = (int32_T)
          (test2_SysIntegration_B.Group1FlashAccessMsgOut_d.Head.MsgId + 1U);
        if ((uint32_T)i > 255U) {
          i = 255;
        }

        test2_SysIntegration_B.Group1FlashAccessMsgOut_d.Head.MsgId = (uint8_T)
          ((uint8_T)i % MAX_uint8_T);
        test2_SysIntegration_B.Group1FlashAccessMsgOut_d.Head.OpCode =
          test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Head.OpCode;
        test2_SysIntegration_B.Group1FlashAccessMsgOut_d.Body =
          test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Body;
      } else {
        if (test2_SysIntegration_DW.prevMsg2Id != 0) {
          test2_SysIntegration_DW.prevMsg2Id = 0U;
          i = (int32_T)
            (test2_SysIntegration_B.Group1FlashAccessMsgOut_d.Head.MsgId + 1U);
          if ((uint32_T)i > 255U) {
            i = 255;
          }

          test2_SysIntegration_B.Group1FlashAccessMsgOut_d.Head.MsgId = (uint8_T)
            ((uint8_T)i % MAX_uint8_T);
          test2_SysIntegration_B.Group1FlashAccessMsgOut_d.Head.OpCode = 0U;
          test2_SysIntegration_B.Group1FlashAccessMsgOut_d.Body =
            test2_SysIntegration_rtZtype_FlashAccessMsg.Body;
        }
      }
    } else {
      test2_SysIntegration_DW.bitsForTID4.is_c55_test2_SysIntegration = 1;
      test2_SysIntegration_DW.prevMsg1Id_l =
        test2_SysIntegration_B.Group1FlashAccessMsgOut_c.Head.MsgId;
      test2_SysIntegration_DW.prevMsg2Id = 0U;
    }

    /* End of Chart: '<S14>/MsgRouter2_100ms' */

    /* Chart: '<S14>/MsgRouter3' */
    if (test2_SysIntegration_DW.temporalCounter_i1_ev < 31U) {
      test2_SysIntegration_DW.temporalCounter_i1_ev++;
    }

    if (test2_SysIntegration_DW.bitsForTID4.is_active_c56_test2_SysIntegrat ==
        0U) {
      test2_SysIntegration_DW.bitsForTID4.is_active_c56_test2_SysIntegrat = 1;
      test2_SysIntegration_DW.bitsForTID4.is_c56_test2_SysIntegration =
        test2_SysIntegration_IN_Init_b;
      test2_SysIntegration_DW.temporalCounter_i1_ev = 0U;
      test2_SysIntegration_B.Group1FlashAccessMsgOut.Head.MsgId = 0U;
      test2_SysIntegration_B.Group1FlashAccessMsgOut.Head.OpCode = 0U;
      b_0.MajorId = 0U;
      b_0.MinorId = 0U;
      memset(&b_0.Data[0], 0, 132U * sizeof(uint8_T));
      test2_SysIntegration_B.Group1FlashAccessMsgOut.Body = b_0;
      test2_SysIntegration_DW.prevMsg1Id = 0U;
    } else if (test2_SysIntegration_DW.bitsForTID4.is_c56_test2_SysIntegration ==
               1) {
      if (test2_SysIntegration_DW.prevMsg1Id !=
          test2_SysIntegration_B.drvFlashAccessMsgOut.Head.MsgId) {
        test2_SysIntegration_DW.prevMsg1Id =
          test2_SysIntegration_B.drvFlashAccessMsgOut.Head.MsgId;
        zcEvent_idx_0 = false;
        zcEvent_idx_1 = true;
        if (!(test2_SysIntegration_B.drvFlashAccessMsgOut.Head.OpCode == 10)) {
          zcEvent_idx_1 = false;
        }

        if (zcEvent_idx_1) {
          zcEvent_idx_0 = true;
        }

        guard1 = false;
        if (zcEvent_idx_0) {
          guard1 = true;
        } else {
          zcEvent_idx_0 = false;
          zcEvent_idx_1 = true;
          if (!(test2_SysIntegration_B.drvFlashAccessMsgOut.Head.OpCode == 30))
          {
            zcEvent_idx_1 = false;
          }

          if (zcEvent_idx_1) {
            zcEvent_idx_0 = true;
          }

          if (zcEvent_idx_0) {
            guard1 = true;
          } else {
            zcEvent_idx_0 = false;
            zcEvent_idx_1 = true;
            if (!(test2_SysIntegration_B.drvFlashAccessMsgOut.Head.OpCode == 100))
            {
              zcEvent_idx_1 = false;
            }

            if (zcEvent_idx_1) {
              zcEvent_idx_0 = true;
            }

            if (zcEvent_idx_0) {
              i = (int32_T)
                (test2_SysIntegration_B.Group1FlashAccessMsgOut.Head.MsgId + 1U);
              if ((uint32_T)i > 255U) {
                i = 255;
              }

              test2_SysIntegration_B.Group1FlashAccessMsgOut.Head.MsgId =
                (uint8_T)((uint8_T)i % MAX_uint8_T);
              test2_SysIntegration_B.Group1FlashAccessMsgOut.Head.OpCode =
                test2_SysIntegration_B.drvFlashAccessMsgOut.Head.OpCode;
              test2_SysIntegration_B.Group1FlashAccessMsgOut.Body =
                test2_SysIntegration_B.drvFlashAccessMsgOut.Body;
            }
          }
        }

        if (guard1) {
          i = (int32_T)
            (test2_SysIntegration_B.Group1FlashAccessMsgOut.Head.MsgId + 1U);
          if ((uint32_T)i > 255U) {
            i = 255;
          }

          test2_SysIntegration_B.Group1FlashAccessMsgOut.Head.MsgId = (uint8_T)
            ((uint8_T)i % MAX_uint8_T);
          test2_SysIntegration_B.Group1FlashAccessMsgOut.Head.OpCode = (uint8_T)
            (test2_SysIntegration_B.drvFlashAccessMsgOut.Head.OpCode / 10U);
          test2_SysIntegration_B.Group1FlashAccessMsgOut.Body =
            test2_SysIntegration_B.drvFlashAccessMsgOut.Body;
        }
      }
    } else {
      if (test2_SysIntegration_DW.temporalCounter_i1_ev >= 30U) {
        test2_SysIntegration_DW.bitsForTID4.is_c56_test2_SysIntegration = 1;
        test2_SysIntegration_DW.prevMsg1Id =
          test2_SysIntegration_B.drvFlashAccessMsgOut.Head.MsgId;
      }
    }

    /* End of Chart: '<S14>/MsgRouter3' */
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[2] == 0) {
    /* Chart: '<S20>/PressureADCRead' */
    elapsedTicks_d = test2_SysIntegration_M->Timing.clockTick2 -
      test2_SysIntegration_DW.previousTicks;
    test2_SysIntegration_DW.previousTicks =
      test2_SysIntegration_M->Timing.clockTick2;
    if (test2_SysIntegration_DW.temporalCounter_i1_o + elapsedTicks_d <= 127U) {
      test2_SysIntegration_DW.temporalCounter_i1_o = (uint8_T)
        (test2_SysIntegration_DW.temporalCounter_i1_o + elapsedTicks_d);
    } else {
      test2_SysIntegration_DW.temporalCounter_i1_o = 127U;
    }

    if (test2_SysIntegration_DW.bitsForTID2.is_c44_test2_SysIntegration ==
        test2_SysIntegration_IN_Init) {
      if (test2_SysIntegration_DW.temporalCounter_i1_o >= 100U) {
        test2_SysIntegration_DW.bitsForTID2.is_c44_test2_SysIntegration =
          test2_SysIntegration_IN_Op_h;
        test2_SysIntegration_B.PressureADC = 0;
      }
    } else {
      test2_SysIntegration_B.PressureADC = 0;
    }

    /* End of Chart: '<S20>/PressureADCRead' */

    /* DataTypeConversion: '<S67>/Data Type Conversion' */
    test2_SysIntegration_B.DataTypeConversion =
      test2_SysIntegration_B.PressureADC;

    /* DataTypeConversion: '<S83>/Data Type Conversion1' */
    test2_SysIntegration_B.DataTypeConversion1 =
      test2_SysIntegration_B.rtmAMotorCurrent;
  }

  /* Outputs for Enabled SubSystem: '<S83>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S103>/Enable'
   */
  if (test2_SysIntegration_B.bitsForTID0.boolMonitorEna) {
    if (!test2_SysIntegration_DW.bitsForTID0.EnabledSubsystem_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S103>/Discrete-Time Integrator1' */
      test2_SysIntegration_DW.DiscreteTimeIntegrator1_DSTATE = 0U;

      /* InitializeConditions for DiscreteIntegrator: '<S103>/Discrete-Time Integrator' */
      test2_SysIntegration_DW.DiscreteTimeIntegrator_DSTATE = 0U;
      test2_SysIntegration_DW.bitsForTID0.EnabledSubsystem_MODE = true;
    }

    /* DiscreteIntegrator: '<S103>/Discrete-Time Integrator1' */
    test2_SysIntegration_B.DiscreteTimeIntegrator1 =
      test2_SysIntegration_DW.DiscreteTimeIntegrator1_DSTATE;

    /* DiscreteIntegrator: '<S103>/Discrete-Time Integrator' */
    test2_SysIntegration_B.DiscreteTimeIntegrator =
      test2_SysIntegration_DW.DiscreteTimeIntegrator_DSTATE;

    /* Update for DiscreteIntegrator: '<S103>/Discrete-Time Integrator1' incorporates:
     *  Constant: '<S103>/Constant'
     */
    test2_SysIntegration_DW.DiscreteTimeIntegrator1_DSTATE++;

    /* Update for DiscreteIntegrator: '<S103>/Discrete-Time Integrator' */
    test2_SysIntegration_DW.DiscreteTimeIntegrator_DSTATE +=
      test2_SysIntegration_B.DataTypeConversion1;
  } else {
    if (test2_SysIntegration_DW.bitsForTID0.EnabledSubsystem_MODE) {
      /* Disable for Outport: '<S103>/milliSecIntegration' */
      test2_SysIntegration_B.DiscreteTimeIntegrator1 = 0U;

      /* Disable for Outport: '<S103>/mAmSIntegration' */
      test2_SysIntegration_B.DiscreteTimeIntegrator = 0U;
      test2_SysIntegration_DW.bitsForTID0.EnabledSubsystem_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S83>/Enabled Subsystem' */
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<S115>/Data Type Conversion' incorporates:
     *  UnitDelay: '<S29>/Unit Delay3'
     */
    test2_SysIntegration_DW.UnitDelay3_DSTATE_a.Head.OpCode =
      test2_SysIntegration_B.CommMsgOut.AlarmSwitch;

    /* BusCreator: '<S115>/Bus Creator' incorporates:
     *  UnitDelay: '<S29>/Unit Delay3'
     */
    test2_SysIntegration_DW.UnitDelay3_DSTATE_a.Head.MsgId =
      test2_SysIntegration_B.CommMsgOut.MsgId;

    /* BusCreator: '<S115>/Bus Creator1' incorporates:
     *  UnitDelay: '<S29>/Unit Delay3'
     */
    test2_SysIntegration_DW.UnitDelay3_DSTATE_a.Body.Data =
      test2_SysIntegration_B.CommMsgOut.FMCode;
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    /* Chart: '<S19>/SysDiag_ProcessLogMsgRouter' incorporates:
     *  UnitDelay: '<S29>/Unit Delay3'
     */
    if (test2_SysIntegration_DW.bitsForTID4.is_c38_test2_SysIntegration ==
        test2_SysIntegration_IN_Init) {
      test2_SysIntegration_DW.bitsForTID4.is_c38_test2_SysIntegration =
        test2_SysIntegration_IN_Router;
      test2_SysIntegration_DW.prevCh1MsgId =
        test2_SysIntegration_DW.UnitDelay3_DSTATE_a.Head.MsgId;
      test2_SysIntegration_DW.prevCh2MsgId = 0U;
    } else if (test2_SysIntegration_DW.prevCh1MsgId !=
               test2_SysIntegration_DW.UnitDelay3_DSTATE_a.Head.MsgId) {
      test2_SysIntegration_DW.prevCh1MsgId =
        test2_SysIntegration_DW.UnitDelay3_DSTATE_a.Head.MsgId;
      i = (int32_T)(test2_SysIntegration_B.FlashWriteInforMsg.Head.MsgId + 1U);
      if ((uint32_T)i > 255U) {
        i = 255;
      }

      test2_SysIntegration_B.FlashWriteInforMsg.Head.MsgId = (uint8_T)((uint8_T)
        i % MAX_uint8_T);
      test2_SysIntegration_B.FlashWriteInforMsg.Head.OpCode = 1U;
      test2_SysIntegration_B.FlashWriteInforMsg.Body =
        test2_SysIntegration_DW.UnitDelay3_DSTATE_a.Body;
    } else {
      if (test2_SysIntegration_DW.prevCh2MsgId != 0) {
        test2_SysIntegration_DW.prevCh2MsgId = 0U;
        i = (int32_T)(test2_SysIntegration_B.FlashWriteInforMsg.Head.MsgId + 1U);
        if ((uint32_T)i > 255U) {
          i = 255;
        }

        test2_SysIntegration_B.FlashWriteInforMsg.Head.MsgId = (uint8_T)
          ((uint8_T)i % MAX_uint8_T);
        test2_SysIntegration_B.FlashWriteInforMsg.Head.OpCode = 2U;
        test2_SysIntegration_B.FlashWriteInforMsg.Body =
          test2_SysIntegration_rtZtype_HMI2SecurityMsg.Body;
      }
    }

    /* End of Chart: '<S19>/SysDiag_ProcessLogMsgRouter' */
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[1] == 0) {
    /* UnitDelay: '<S112>/Unit Delay' */
    rtb_UnitDelay_p = test2_SysIntegration_DW.bitsForTID1.UnitDelay_DSTATE_lc;

    /* UnitDelay: '<S112>/Unit Delay1' */
    rtb_UnitDelay1_j = test2_SysIntegration_DW.bitsForTID1.UnitDelay1_DSTATE_eq;

    /* UnitDelay: '<S112>/Unit Delay2' */
    rtb_UnitDelay2_k = test2_SysIntegration_DW.bitsForTID1.UnitDelay2_DSTATE_o1;

    /* Logic: '<S21>/Logical Operator' incorporates:
     *  DataTypeConversion: '<S112>/Data Type Conversion'
     */
    test2_SysIntegration_B.LogicalOperator[0] =
      !(test2_SysIntegration_B.SysDiagMsgOut_c[0] != 0);
    test2_SysIntegration_B.LogicalOperator[1] =
      !(test2_SysIntegration_B.SysDiagMsgOut_c[1] != 0);
    test2_SysIntegration_B.LogicalOperator[2] =
      !(test2_SysIntegration_B.SysDiagMsgOut_c[2] != 0);
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    /* Chart: '<S113>/Actuator' */
    if (test2_SysIntegration_DW.temporalCounter_i1_j < 15U) {
      test2_SysIntegration_DW.temporalCounter_i1_j++;
    }

    if (test2_SysIntegration_DW.bitsForTID4.is_active_c15_test2_SysIntegrat ==
        0U) {
      test2_SysIntegration_DW.bitsForTID4.is_active_c15_test2_SysIntegrat = 1;
      test2_SysIntegration_DW.temporalCounter_i1_j = 0U;
      tmp_1[0] = test2_SysIntegration_B.LogicalOperator[0];
      tmp[0] = test2_SysIntegration_B.boolAlarmEmpty[0];
      tmp_1[1] = test2_SysIntegration_B.LogicalOperator[1];
      tmp[1] = test2_SysIntegration_B.boolAlarmEmpty[1];
      tmp_1[2] = test2_SysIntegration_B.LogicalOperator[2];
      tmp[2] = test2_SysIntegration_B.boolAlarmEmpty[2];
      if (test2_SysIntegr_detectPopAction(tmp_1, tmp)) {
        test2_SysIntegration_DW.PopAlarmEvtEventCounter++;
      }
    } else {
      if (test2_SysIntegration_DW.temporalCounter_i1_j >= 10U) {
        test2_SysIntegration_DW.temporalCounter_i1_j = 0U;
        tmp_1[0] = test2_SysIntegration_B.LogicalOperator[0];
        tmp[0] = test2_SysIntegration_B.boolAlarmEmpty[0];
        tmp_1[1] = test2_SysIntegration_B.LogicalOperator[1];
        tmp[1] = test2_SysIntegration_B.boolAlarmEmpty[1];
        tmp_1[2] = test2_SysIntegration_B.LogicalOperator[2];
        tmp[2] = test2_SysIntegration_B.boolAlarmEmpty[2];
        if (test2_SysIntegr_detectPopAction(tmp_1, tmp)) {
          test2_SysIntegration_DW.PopAlarmEvtEventCounter++;
        }
      }
    }

    if (test2_SysIntegration_DW.PopAlarmEvtEventCounter > 0U) {
      test2_SysIntegration_B.bitsForTID4.PopAlarmEvt =
        !test2_SysIntegration_B.bitsForTID4.PopAlarmEvt;
      test2_SysIntegration_DW.PopAlarmEvtEventCounter--;
    }

    /* End of Chart: '<S113>/Actuator' */
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[1] == 0) {
    /* Chart: '<S114>/Chart' incorporates:
     *  TriggerPort: '<S121>/input events'
     */
    zcEvent_idx_0 = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_g[0] ==
                       POS_ZCSIG) != (int32_T)rtb_UnitDelay2_k) &&
                     (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_g[0] !=
                      UNINITIALIZED_ZCSIG));
    zcEvent_idx_1 = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_g[1] ==
                       POS_ZCSIG) != (int32_T)rtb_UnitDelay1_j) &&
                     (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_g[1] !=
                      UNINITIALIZED_ZCSIG));
    if (zcEvent_idx_0 || zcEvent_idx_1) {
      if ((int8_T)(zcEvent_idx_0 ? rtb_UnitDelay2_k ? RISING_ZCEVENT :
                   FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
        i = test2_SysIn_event_StartTimerEvt;
        chartstep_c37_test2_SysIntegrat(&i);
      }

      if ((int8_T)(zcEvent_idx_1 ? rtb_UnitDelay1_j ? RISING_ZCEVENT :
                   FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
        i = test2_SysInt_event_StopTimerEvt;
        chartstep_c37_test2_SysIntegrat(&i);
      }
    }

    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_g[0] = rtb_UnitDelay2_k;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_g[1] = rtb_UnitDelay1_j;
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[7] == 0) {
    /* UnitDelay: '<S126>/Unit Delay1' */
    rtb_UnitDelay1_j = test2_SysIntegration_DW.bitsForTID7.UnitDelay1_DSTATE_m;

    /* Chart: '<S122>/Chart' incorporates:
     *  TriggerPort: '<S124>/input events'
     */
    zcEvent_idx_0 = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE[0] ==
                       POS_ZCSIG) != (int32_T)rtb_UnitDelay1_j) &&
                     (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE[0] !=
                      UNINITIALIZED_ZCSIG));
    zcEvent_idx_1 = (((test2_SysIntegration_PrevZCX.Chart_Trig_ZCE[1] ==
                       POS_ZCSIG) != (int32_T)
                      test2_SysIntegration_B.bitsForTID7.RTChipWriteEvt) &&
                     (test2_SysIntegration_PrevZCX.Chart_Trig_ZCE[1] !=
                      UNINITIALIZED_ZCSIG));
    if (zcEvent_idx_0 || zcEvent_idx_1) {
      if ((int8_T)(zcEvent_idx_0 ? rtb_UnitDelay1_j ? RISING_ZCEVENT :
                   FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
        i = test2_SysInte_event_InitChipEvt;
        chartstep_c1_test2_SysIntegrati(&i);
      }

      if ((int8_T)(zcEvent_idx_1 ?
                   test2_SysIntegration_B.bitsForTID7.RTChipWriteEvt ?
                   RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
        i = test2_SysIntegr_event_WriteChip;
        chartstep_c1_test2_SysIntegrati(&i);
      }
    }

    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE[0] = rtb_UnitDelay1_j;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE[1] =
      test2_SysIntegration_B.bitsForTID7.RTChipWriteEvt;

    /* Outputs for Enabled SubSystem: '<S126>/AbsoluteTimeHold' incorporates:
     *  EnablePort: '<S127>/Enable'
     */
    /* Logic: '<S126>/Logical Operator' incorporates:
     *  Inport: '<S127>/In1'
     *  UnitDelay: '<S126>/Unit Delay2'
     */
    if (!test2_SysIntegration_B.bitsForTID7.boolAbsTimeHold) {
      test2_SysIntegration_DW.UnitDelay2_DSTATE_o =
        test2_SysIntegration_B.RTTimeMsgOut_h;
    }

    /* End of Logic: '<S126>/Logical Operator' */
    /* End of Outputs for SubSystem: '<S126>/AbsoluteTimeHold' */

    /* Update for UnitDelay: '<S126>/Unit Delay' */
    test2_SysIntegration_DW.UnitDelay_DSTATE_o5 =
      test2_SysIntegration_B.boolSysEnable;
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    /* Update for UnitDelay: '<S29>/Unit Delay4' */
    test2_SysIntegration_DW.UnitDelay4_DSTATE =
      test2_SysIntegration_B.CommVarLogMsgOut;

    /* Update for UnitDelay: '<S29>/Unit Delay2' */
    test2_SysIntegration_DW.UnitDelay2_DSTATE_p =
      test2_SysIntegration_rtZtype_CommCtrlFCTestMsg;

    /* Update for UnitDelay: '<S29>/Unit Delay1' */
    test2_SysIntegration_DW.UnitDelay1_DSTATE_e =
      test2_SysIntegration_B.BleMsgOut;

    /* Update for UnitDelay: '<S65>/Unit Delay5' */
    test2_SysIntegration_DW.UnitDelay5_DSTATE =
      test2_SysIntegration_B.LogDataMsg;
  }

  /* Update for UnitDelay: '<S65>/Unit Delay4' */
  test2_SysIntegration_DW.UnitDelay4_DSTATE_e =
    test2_SysIntegration_B.DynDoseInfoMsg;
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[5] == 0) {
    /* Update for UnitDelay: '<S65>/Unit Delay3' */
    test2_SysIntegration_DW.UnitDelay3_DSTATE =
      test2_SysIntegration_B.Group1DDSMsgOut;
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    /* Update for UnitDelay: '<S65>/Unit Delay6' */
    test2_SysIntegration_DW.UnitDelay6_DSTATE =
      test2_SysIntegration_rtZtype_RecordCtrl2SecurityMsg;

    /* Update for UnitDelay: '<S65>/Unit Delay1' */
    test2_SysIntegration_DW.UnitDelay1_DSTATE = test2_SysIntegration_B.VarSet;

    /* Update for UnitDelay: '<S52>/Unit Delay' */
    test2_SysIntegration_DW.UnitDelay_DSTATE_c =
      test2_SysIntegration_B.VarSet.DoseCtrl.LargeDoseConfig.RegularDose4DWMCase;

    /* Update for UnitDelay: '<S52>/Unit Delay1' */
    test2_SysIntegration_DW.UnitDelay1_DSTATE_b =
      test2_SysIntegration_B.VarSet.DoseCtrl.DoseCtrlParam.MaxLargeDose;

    /* Update for UnitDelay: '<S42>/Unit Delay' */
    test2_SysIntegration_DW.UnitDelay_DSTATE_n =
      test2_SysIntegration_B.LP2RTMsgOut;
  }

  /* Update for UnitDelay: '<S65>/Unit Delay2' */
  test2_SysIntegration_DW.UnitDelay2_DSTATE =
    test2_SysIntegration_B.LargeDoseTimeHitMsg;

  /* Update for UnitDelay: '<S89>/Unit Delay' */
  test2_SysIntegration_DW.UnitDelay_DSTATE =
    test2_SysIntegration_B.MotorServoStateMsg;

  /* Update for UnitDelay: '<S100>/Unit Delay' incorporates:
   *  UnitDelay: '<S83>/Unit Delay3'
   */
  test2_SysIntegration_DW.UnitDelay_DSTATE_b =
    test2_SysIntegration_DW.UnitDelay3_DSTATE_c;
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    /* Update for UnitDelay: '<S63>/Unit Delay' */
    test2_SysIntegration_DW.UnitDelay_DSTATE_l =
      test2_SysIntegration_B.FlashWriteInforMsg;

    /* Update for Delay: '<S67>/Wait4LPFinish' */
    for (i = 0; i < 9; i++) {
      test2_SysIntegration_DW.Wait4LPFinish_DSTATE[i] =
        test2_SysIntegration_DW.Wait4LPFinish_DSTATE[i + 1];
    }

    test2_SysIntegration_DW.Wait4LPFinish_DSTATE[9] = rtb_LogicalOperator;

    /* End of Update for Delay: '<S67>/Wait4LPFinish' */
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UnitDelay: '<S21>/Unit Delay' */
    test2_SysIntegration_DW.bitsForTID1.UnitDelay_DSTATE_f = rtb_UnitDelay_p;
  }

  /* Update for RateTransition: '<S42>/Rate Transition2' */
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[7] == 0) {
    test2_SysIntegration_DW.RateTransition2_Buffer0 =
      test2_SysIntegration_B.NextHitTime;
  }

  /* End of Update for RateTransition: '<S42>/Rate Transition2' */
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    /* Update for UnitDelay: '<S49>/Unit Delay1' */
    test2_SysIntegration_DW.UnitDelay1_DSTATE_d =
      test2_SysIntegration_B.LP2RTMsgOut_m;

    /* Update for UnitDelay: '<S49>/Unit Delay' */
    test2_SysIntegration_DW.UnitDelay_DSTATE_o =
      test2_SysIntegration_rtZtype_HMI2SecurityMsg;
  }

  /* Update for UnitDelay: '<Root>/Unit Delay1' incorporates:
   *  Logic: '<Root>/Logical Operator2'
   */
  test2_SysIntegration_DW.bitsForTID0.UnitDelay1_DSTATE_k =
    (test2_SysIntegration_B.bitsForTID0.boolMotorForwardEnable ||
     test2_SysIntegration_B.bitsForTID0.boolMotorServoEnable ||
     test2_SysIntegration_B.bitsForTID0.boolMotorHomingEnable);

  /* Update for UnitDelay: '<S94>/Unit Delay' */
  test2_SysIntegration_DW.UnitDelay_DSTATE_oz =
    test2_SysIntegration_B.MotorServoStateMsg;
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[7] == 0) {
    /* Update for UnitDelay: '<S123>/Unit Delay1' */
    test2_SysIntegration_DW.UnitDelay1_DSTATE_dc =
      test2_SysIntegration_B.RTMsgOut;

    /* Update for UnitDelay: '<S123>/Unit Delay' */
    test2_SysIntegration_DW.bitsForTID7.UnitDelay_DSTATE_b2 =
      test2_SysIntegration_B.bitsForTID7.boolChipErrStatus;

    /* Update for UnitDelay: '<Root>/Unit Delay' */
    test2_SysIntegration_DW.UnitDelay_DSTATE_h =
      test2_SysIntegration_B.MotionCtrl2RTMsgOut;
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UnitDelay: '<S21>/Unit Delay1' */
    test2_SysIntegration_DW.UnitDelay1_DSTATE_o =
      test2_SysIntegration_B.TimerCtrlMsg;
  }

  /* Update for UnitDelay: '<S87>/Unit Delay2' */
  test2_SysIntegration_DW.UnitDelay2_DSTATE_pc =
    test2_SysIntegration_B.DoseMissionMsg;

  /* Update for UnitDelay: '<S83>/Unit Delay2' */
  test2_SysIntegration_DW.UnitDelay2_DSTATE_f =
    test2_SysIntegration_B.PerfACKMissionFinishMsg;
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    /* Update for UnitDelay: '<S87>/Unit Delay' */
    test2_SysIntegration_DW.bitsForTID4.UnitDelay_DSTATE_o0 =
      test2_SysIntegration_B.bitsForTID4.boolBufferEmpty;

    /* Update for UnitDelay: '<S76>/Unit Delay1' */
    test2_SysIntegration_DW.bitsForTID4.UnitDelay1_DSTATE_i =
      test2_SysIntegration_B.bitsForTID4.PopBufEvt;
  }

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  test2_SysIntegration_DW.UnitDelay_DSTATE_i = test2_SysIntegration_B.rtEncRdOut;

  /* Update for UnitDelay: '<S21>/Unit Delay2' */
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[5] == 0) {
    test2_SysIntegration_DW.UnitDelay2_DSTATE_n =
      test2_SysIntegration_B.OcclusionObservationCancel;
  }

  /* End of Update for UnitDelay: '<S21>/Unit Delay2' */

  /* Update for UnitDelay: '<S83>/Unit Delay' */
  test2_SysIntegration_DW.UnitDelay_DSTATE_k =
    test2_SysIntegration_B.DiscreteTimeIntegrator1;

  /* Update for UnitDelay: '<S83>/Unit Delay1' */
  test2_SysIntegration_DW.UnitDelay1_DSTATE_c =
    test2_SysIntegration_B.DiscreteTimeIntegrator;
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update for DiscreteTransferFcn: '<S67>/Discrete Transfer Fcn' */
    denAccum = (test2_SysIntegration_B.DataTypeConversion - -0.5693F *
                test2_SysIntegration_DW.DiscreteTransferFcn_states[0]) - 0.081F *
      test2_SysIntegration_DW.DiscreteTransferFcn_states[1];
    test2_SysIntegration_DW.DiscreteTransferFcn_states[1] =
      test2_SysIntegration_DW.DiscreteTransferFcn_states[0];
    test2_SysIntegration_DW.DiscreteTransferFcn_states[0] = denAccum;
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[4] == 0) {
    /* Update for UnitDelay: '<S113>/Unit Delay' */
    test2_SysIntegration_DW.bitsForTID4.UnitDelay_DSTATE_ft =
      test2_SysIntegration_B.bitsForTID4.PopAlarmEvt;
  }

  /* Update for UnitDelay: '<S83>/Unit Delay3' */
  test2_SysIntegration_DW.UnitDelay3_DSTATE_c =
    test2_SysIntegration_B.PerfEvalMsg;
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UnitDelay: '<S112>/Unit Delay' */
    test2_SysIntegration_DW.bitsForTID1.UnitDelay_DSTATE_lc =
      test2_SysIntegration_B.bitsForTID1.LowPowerMsgOut;

    /* Update for UnitDelay: '<S112>/Unit Delay1' */
    test2_SysIntegration_DW.bitsForTID1.UnitDelay1_DSTATE_eq =
      test2_SysIntegration_B.bitsForTID1.HighLevelAlarmEvtStart;

    /* Update for UnitDelay: '<S112>/Unit Delay2' */
    test2_SysIntegration_DW.bitsForTID1.UnitDelay2_DSTATE_o1 =
      test2_SysIntegration_B.bitsForTID1.HighLevelAlarmEvtStop;
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[7] == 0) {
    /* Update for UnitDelay: '<S126>/Unit Delay1' */
    test2_SysIntegration_DW.bitsForTID7.UnitDelay1_DSTATE_m =
      test2_SysIntegration_B.bitsForTID7.InitTimerEvt;
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  test2_SysIntegration_M->Timing.clockTick0++;
  if (test2_SysIntegration_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick2" ensures timer will not overflow during the
     * application lifespan selected.
     */
    test2_SysIntegration_M->Timing.clockTick2++;
  }

  if (test2_SysIntegration_M->Timing.TaskCounters.TID[7] == 0) {
    /* Update absolute timer for sample time: [1.0s, 0.0s] */
    /* The "clockTick7" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 1.0, which is the step size
     * of the task. Size of "clockTick7" ensures timer will not overflow during the
     * application lifespan selected.
     */
    test2_SysIntegration_M->Timing.clockTick7++;
  }

  rate_scheduler();
}

/* Model initialize function */
void test2_SysIntegration_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)test2_SysIntegration_M, 0,
                sizeof(RT_MODEL_test2_SysIntegration_T));

  /* block I/O */
  (void) memset(((void *) &test2_SysIntegration_B), 0,
                sizeof(B_test2_SysIntegration_T));

  /* states (dwork) */
  (void) memset((void *)&test2_SysIntegration_DW, 0,
                sizeof(DW_test2_SysIntegration_T));

  {
    type_MsgBody4FlashAccessMsg b;
    type_RT b_0;
    int32_T i;

    /* Start for UnitDelay: '<S126>/Unit Delay' */
    test2_SysIntegration_B.UnitDelay_m = false;

    /* Start for DiscretePulseGenerator: '<S89>/Pulse Generator' */
    test2_SysIntegration_DW.clockTickCounter = 0;

    /* Start for DiscretePulseGenerator: '<S100>/Pulse Generator' */
    test2_SysIntegration_DW.clockTickCounter_l = 0;

    /* Start for DiscretePulseGenerator: '<S94>/Pulse Generator' */
    test2_SysIntegration_DW.clockTickCounter_i = 0;

    /* Start for DiscretePulseGenerator: '<S108>/Pulse Generator' */
    test2_SysIntegration_DW.clockTickCounter_i3 = 0;

    /* Start for DiscretePulseGenerator: '<S69>/Pulse Generator' */
    test2_SysIntegration_DW.clockTickCounter_c = 0;

    /* Start for UnitDelay: '<S21>/Unit Delay2' */
    test2_SysIntegration_B.UnitDelay2_j = false;

    /* Start for DiscretePulseGenerator: '<S96>/Pulse Generator' */
    test2_SysIntegration_DW.clockTickCounter_p = 0;

    /* Start for DiscretePulseGenerator: '<S83>/Pulse Generator' */
    test2_SysIntegration_DW.clockTickCounter_m = 0;

    /* Start for DiscretePulseGenerator: '<S67>/Pulse Generator' */
    test2_SysIntegration_DW.clockTickCounter_g = 0;

    /* Start for DiscretePulseGenerator: '<S4>/Pulse Generator' */
    test2_SysIntegration_DW.clockTickCounter_o = 0;

    /* Start for DiscretePulseGenerator: '<S92>/Pulse Generator' */
    test2_SysIntegration_DW.clockTickCounter_a = 0;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_pt = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_lg = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_ng = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_o[0] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_o[1] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_o[2] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_d = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_l = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_nm = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart1_Trig_ZCE[0] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart1_Trig_ZCE[1] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart1_Trig_ZCE[2] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_ff[0] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_ff[1] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_f[0] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_f[1] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_f[2] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_k[0] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_k[1] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_g4[0] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_g4[1] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_g4[2] = UNINITIALIZED_ZCSIG;
    for (i = 0; i < 5; i++) {
      test2_SysIntegration_PrevZCX.PressureSingularityDetector_Tri[i] =
        UNINITIALIZED_ZCSIG;
      test2_SysIntegration_PrevZCX.MotorRunDriver_Trig_ZCE[i] =
        UNINITIALIZED_ZCSIG;
    }

    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_p[0] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_h[0] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_n[0] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_p[1] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_h[1] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_n[1] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Buffer_Trig_ZCE_o[0] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Buffer_Trig_ZCE_o[1] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Buffer_Trig_ZCE_o[2] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_j[0] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Buffer_Trig_ZCE[0] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_g[0] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE[0] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_j[1] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Buffer_Trig_ZCE[1] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE_g[1] = UNINITIALIZED_ZCSIG;
    test2_SysIntegration_PrevZCX.Chart_Trig_ZCE[1] = UNINITIALIZED_ZCSIG;

    /* SystemInitialize for Chart: '<S29>/Chart' */
    test2_SysIntegration_DW.bitsForTID4.is_Enable = 0;
    test2_SysIntegration_DW.temporalCounter_i1_po = 0U;
    test2_SysIntegration_DW.bitsForTID4.is_active_c8_test2_SysIntegrati = 0;
    test2_SysIntegration_DW.bitsForTID4.is_c8_test2_SysIntegration = 0;
    test2_SysIntegration_DW.prevBleInMsgId = MAX_uint8_T;
    test2_SysIntegration_DW.BleOutMsgId = 0U;
    test2_SysIntegration_DW.getBleDataEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID4.getBleDataEvt = false;
    test2_SysIntegration_DW.sendBleDataEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID4.sendBleDataEvt = false;

    /* SystemInitialize for Chart: '<S65>/Chart' */
    test2_SysIntegration_DW.sfEvent_o = -1;
    test2_SysIntegration_DW.bitsForTID4.is_active_GeneralDeliveryStateM = 0;
    test2_SysIntegration_DW.bitsForTID4.is_GeneralDeliveryStateManageme = 0;
    test2_SysIntegration_DW.bitsForTID4.is_DeliverySwitchOn = 0;
    test2_SysIntegration_DW.temporalCounter_i3 = 0U;
    test2_SysIntegration_DW.bitsForTID4.is_active_TempBaseRateAndLargeD = 0;
    test2_SysIntegration_DW.bitsForTID4.is_active_LargeDoseDumpManageme = 0;
    test2_SysIntegration_DW.bitsForTID4.is_active_TempBaseRateDumpManag = 0;
    test2_SysIntegration_DW.bitsForTID4.is_TempBaseRateDumpManagement = 0;
    test2_SysIntegration_DW.temporalCounter_i1_g = 0U;
    test2_SysIntegration_DW.bitsForTID4.is_active_ThreeTypeDoseDelivery = 0;
    test2_SysIntegration_DW.bitsForTID4.is_ThreeTypeDoseDeliveryPlanMan = 0;
    test2_SysIntegration_DW.bitsForTID4.is_LargeDoseMonitor = 0;
    test2_SysIntegration_DW.temporalCounter_i2_c = 0U;
    test2_SysIntegration_DW.bitsForTID4.is_active_c22_test2_SysIntegrat = 0;
    test2_SysIntegration_DW.bitsForTID4.is_c22_test2_SysIntegration = 0;
    test2_SysIntegration_DW.inputChannel = 0U;
    test2_SysIntegration_DW.prevBufferedLargeDose = 0U;
    test2_SysIntegration_DW.prevTotalDoseAmount = 0U;
    test2_SysIntegration_DW.bitsForTID4.boolLargeDoseMonitorEnable = false;
    test2_SysIntegration_B.bitsForTID4.boolAirExpelSwitchOn = false;
    test2_SysIntegration_B.bitsForTID4.boolNormalDeliverySwitchOn = false;
    test2_SysIntegration_B.bitsForTID4.boolHomingOn = false;
    test2_SysIntegration_DW.CalibraStartEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID4.CalibraStartEvt = false;

    /* SystemInitialize for Chart: '<S55>/Chart' */
    test2_SysIntegration_DW.AirExpelStartEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID4.AirExpelStartEvt = false;
    test2_SysIntegration_DW.AirExpelStopEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID4.AirExpelStopEvt = false;

    /* Chart: '<S55>/Chart' */
    test2_SysIntegration_DW.bitsForTID4.is_c34_test2_SysIntegration =
      test2_SysIntegration_IN_Idle_k;

    /* SystemInitialize for Chart: '<S89>/Chart' */
    test2_SysIntegration_DW.bitsForTID0.is_OpStart = 0;
    test2_SysIntegration_DW.bitsForTID0.is_OpStop = 0;
    test2_SysIntegration_DW.temporalCounter_i1_ig = 0U;
    test2_SysIntegration_DW.bitsForTID0.boolFDBK = false;
    test2_SysIntegration_DW.prevFDBKMsgId = 0U;
    test2_SysIntegration_B.bitsForTID0.boolTrimEnable = false;
    test2_SysIntegration_DW.AirExpelEnaEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID0.AirExpelEnaEvt = false;

    /* Chart: '<S89>/Chart' */
    test2_SysIntegration_DW.bitsForTID0.is_c17_test2_SysIntegration =
      test2_SysIntegration_IN_Init_b;
    test2_SysIntegration_B.ErrDiagMsg.Head.MsgId = 0U;
    test2_SysIntegration_B.ErrDiagMsg.Head.OpCode = 0U;
    test2_SysIntegration_B.ErrDiagMsg.Body.Data = 0U;

    /* Chart: '<S1>/Chart' */
    test2_SysIntegration_B.MajorSensorOutp.Ch1 = 0;
    test2_SysIntegration_B.MajorSensorOutp.Ch2 = 0;
    test2_SysIntegration_B.MajorSensorOutp.Ch3 = 0;
    test2_SysIntegration_B.MajorSensorOutp.Ch4 = 0;
    for (i = 0; i < 5; i++) {
      /* Chart: '<S5>/Chart' */
      test2_SysIntegration_B.KeyVector[i] = false;
    }

    /* Chart: '<S5>/Chart' */
    test2_SysIntegration_B.bitsForTID5.boolBubbleDetected = false;
    test2_SysIntegration_B.bitsForTID5.boolPCADetected = false;
    test2_SysIntegration_B.bitsForTID5.boolShaftEnc = false;

    /* SystemInitialize for Chart: '<S52>/PCAMsgSend' */
    test2_SysIntegration_DW.bitsForTID6.is_active_PCACtrlMsgDetector = 0;
    test2_SysIntegration_DW.bitsForTID6.is_PCACtrlMsgDetector = 0;
    test2_SysIntegration_DW.temporalCounter_i1_ls = 0U;
    test2_SysIntegration_DW.bitsForTID6.is_active_PCADoseMonitor = 0;
    test2_SysIntegration_DW.bitsForTID6.is_PCADoseMonitor = 0;
    test2_SysIntegration_DW.bitsForTID6.is_active_c49_test2_SysIntegrat = 0;
    test2_SysIntegration_DW.PCAACCDose = 0U;
    test2_SysIntegration_DW.PCASaturatedDose = 0U;
    test2_SysIntegration_DW.bitsForTID6.boolPCASatHit = false;
    test2_SysIntegration_DW.prevRTCompMsgId = 0U;

    /* SystemInitialize for Chart: '<S100>/Chart' */
    test2_SysIntegration_DW.temporalCounter_i1_l = 0U;
    test2_SysIntegration_DW.prevCalibraMsgId = 0U;
    test2_SysIntegration_DW.CalibraIndex = 0U;
    test2_SysIntegration_B.bitsForTID0.boolCalibraEna = false;

    /* Chart: '<S100>/Chart' */
    test2_SysIntegration_DW.bitsForTID0.is_c26_test2_SysIntegration =
      test2_SysIntegra_IN_CalibraStop;
    test2__enter_atomic_CalibraStop();

    /* SystemInitialize for Chart: '<S14>/MsgRouter1' */
    test2_SysIntegration_DW.temporalCounter_i1_k = 0U;
    test2_SysIntegration_DW.bitsForTID0.is_active_c46_test2_SysIntegrat = 0;
    test2_SysIntegration_DW.bitsForTID0.is_c46_test2_SysIntegration = 0;

    /* SystemInitialize for Chart: '<S63>/Chart' */
    test2_SysIntegration_DW.sfEvent_gn = -1;
    test2_SysIntegration_DW.bitsForTID4.is_FlashDrv = 0;
    test2_SysIntegration_DW.bitsForTID4.was_FlashDrv = 0;
    test2_SysIntegration_DW.temporalCounter_i4 = 0U;
    test2_SysIntegration_DW.bitsForTID4.is_active_FlashDriveAct = 0;
    test2_SysIntegration_DW.bitsForTID4.is_FlashDriveAct = 0;
    test2_SysIntegration_DW.bitsForTID4.is_active_LogClrService = 0;
    test2_SysIntegration_DW.bitsForTID4.is_LogClrService = 0;
    test2_SysIntegration_DW.bitsForTID4.was_LogClrService = 0;
    test2_SysIntegration_DW.temporalCounter_i3_n = 0U;
    test2_SysIntegration_DW.bitsForTID4.is_active_UpgradeAndLogUpLoadMa = 0;
    test2_SysIntegration_DW.bitsForTID4.is_UpgradeAndLogUpLoadManagemen = 0;
    test2_SysIntegration_DW.bitsForTID4.is_active_VarClrService = 0;
    test2_SysIntegration_DW.bitsForTID4.is_VarClrService = 0;
    test2_SysIntegration_DW.bitsForTID4.was_VarClrService = 0;
    test2_SysIntegration_DW.bitsForTID4.is_Op_h = 0;
    test2_SysIntegration_DW.temporalCounter_i2_dg = 0U;
    test2_SysIntegration_DW.bitsForTID4.is_Init = 0;
    test2_SysIntegration_DW.bitsForTID4.was_Init = 0;
    test2_SysIntegration_DW.temporalCounter_i1_n = 0U;
    test2_SysIntegration_DW.bitsForTID4.is_active_c2_test2_SysIntegrati = 0;
    test2_SysIntegration_DW.bitsForTID4.is_c2_test2_SysIntegration = 0;
    test2_SysIntegration_DW.LogId = 0U;
    test2_SysIntegration_DW.OpCode = 0U;
    memset(&test2_SysIntegration_DW.Data[0], 0, 132U * sizeof(uint8_T));
    test2_SysIntegration_DW.bitsForTID4.FlashAccessEnable = false;
    test2_SysIntegration_DW.prevFlashAccessMsgId = 0U;
    test2_SysIntegration_DW.Channel = 1U;
    test2_SysIntegration_DW.LogWriteMajorId = 0U;
    test2_SysIntegration_DW.LogWriteMinorId = 0U;
    test2_SysIntegration_DW.bitsForTID4.LogUpLoadEnable = false;
    test2_SysIntegration_DW.ParamExt = 0U;
    test2_SysIntegration_DW.prevAlarmInfoMsgId = 0U;
    test2_SysIntegration_DW.LogOpCode = 0U;
    test2_SysIntegration_DW.bitsForTID4.boolLogReadTerminate = true;
    test2_SysIntegration_DW.bitsForTID4.boolLogSend = false;
    test2_SysIntegration_DW.MinorId = 0U;
    test2_SysIntegration_DW.MajorId = 0U;
    test2_SysIntegration_DW.FlashErrTimes = 0U;
    test2_SysIntegration_DW.bitsForTID4.FlashAccessErr = false;
    test2_SysIntegration_DW.bitsForTID4.LogUpdateEnable = false;
    test2_SysIntegration_DW.tempLog_LogWriteMajorId = 0U;
    test2_SysIntegration_DW.tempLog_LogWriteMinorId = 0U;
    test2_SysIntegration_DW.tempLog_ParamExt = 0U;
    test2_SysIntegration_DW.tempVar_LogWriteMajorId = 0U;
    test2_SysIntegration_DW.tempVar_LogWriteMinorId = 0U;
    test2_SysIntegration_DW.tempVar_ParamExt = 0U;
    test2_SysIntegration_DW.FlashInitFinishEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID4.FlashInitFinishEvt = false;

    /* SystemInitialize for Chart: '<S51>/Chart' */
    test2_SysIntegration_DW.bitsForTID2.is_KeyModeIdentification = 0;
    test2_SysIntegration_DW.bitsForTID2.is_SingleKeyModeIdent = 0;
    test2_SysIntegration_DW.temporalCounter_i1_p = 0U;
    test2_SysIntegration_DW.bitsForTID2.is_active_c48_test2_SysIntegrat = 0;
    test2_SysIntegration_DW.KeyValueAcc[0] = 0U;
    test2_SysIntegration_DW.KeyValueAcc[1] = 0U;
    test2_SysIntegration_DW.KeyValueAcc[2] = 0U;
    test2_SysIntegration_DW.KeyValueAcc[3] = 0U;
    test2_SysIntegration_DW.KeyValueAcc[4] = 0U;
    test2_SysIntegration_B.bitsForTID2.KeyDownStatus = false;

    /* SystemInitialize for Chart: '<S49>/Chart' */
    test2_SysIntegration_DW.bitsForTID4.is_LPCtrl = 0;
    test2_SysIntegration_DW.bitsForTID4.is_HoldStage = 0;
    test2_SysIntegration_DW.bitsForTID4.is_IOCtrlStage = 0;
    test2_SysIntegration_DW.temporalCounter_i1_d = 0U;
    test2_SysIntegration_DW.bitsForTID4.is_active_c6_test2_SysIntegrati = 0;
    test2_SysIntegration_DW.bitsForTID4.is_c6_test2_SysIntegration = 0;
    test2_SysIntegration_DW.prevLPCompTimeMsgId = 0U;
    test2_SysIntegration_DW.bitsForTID4.boolHibernation = false;
    test2_SysIntegration_DW.prevInSecurityMsgId = 0U;
    test2_SysIntegration_DW.SleepFailureTimes = 0U;
    test2_SysIntegration_B.bitsForTID4.IOSwitchCmd = false;
    test2_SysIntegration_B.SleepSec = 0U;
    test2_SysIntegration_DW.LCDCtrlEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID4.LCDCtrlEvt = false;
    test2_SysIntegration_DW.LPSwitchCtrlEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID4.LPSwitchCtrlEvt = false;
    test2_SysIntegration_DW.IOSwitchCtrlEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID4.IOSwitchCtrlEvt = false;

    /* Chart: '<S43>/Chart' */
    test2_SysIntegration_B.bitsForTID4.boolLCDStatus = false;

    /* SystemInitialize for Chart: '<S67>/Taskwith10msSamplingTime' */
    test2_SysIntegration_DW.bitsForTID2.is_BattEQEstimator = 0;
    test2_SysIntegration_DW.temporalCounter_i2_f = 0U;
    test2_SysIntegration_DW.bitsForTID2.is_BattEQEst = 0;
    test2_SysIntegration_DW.bitsForTID2.is_BattPowerAlarmManagement = 0;
    test2_SysIntegration_DW.temporalCounter_i1_e = 0U;
    test2_SysIntegration_DW.bitsForTID2.is_active_c40_test2_SysIntegrat = 0;
    test2_SysIntegration_DW.bitsForTID2.is_c40_test2_SysIntegration = 0;
    test2_SysIntegration_DW.BattVolt = 0;
    test2_SysIntegration_DW.prevSensorMsgId = 0U;
    test2_SysIntegration_DW.bitsForTID2.boolHappenMark = false;
    test2_SysIntegration_DW.bitsForTID2.boolBatteryLow = false;
    test2_SysIntegration_DW.BattOverLowFlag = 0U;
    test2_SysIntegration_B.rtCurrent = 0U;
    test2_SysIntegration_B.BattEQ = 100U;
    test2_SysIntegration_B.rtmAMotorCurrent = 0U;

    /* SystemInitialize for Chart: '<S55>/Chart1' */
    test2_SysIntegration_DW.bitsForTID4.is_active_c35_test2_SysIntegrat = 0;
    test2_SysIntegration_DW.bitsForTID4.is_c35_test2_SysIntegration = 0;
    test2_SysIntegration_DW.HomingStartEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID4.HomingStartEvt = false;
    test2_SysIntegration_DW.HomingStopEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID4.HomingStopEvt = false;

    /* SystemInitialize for Chart: '<S94>/Chart' */
    test2_SysIntegration_DW.bitsForTID0.is_HomingStartSrv = 0;
    test2_SysIntegration_DW.temporalCounter_i2_d = 0U;
    test2_SysIntegration_DW.bitsForTID0.is_VerifyHomingState = 0;
    test2_SysIntegration_DW.bitsForTID0.is_HomingStopSrv = 0;
    test2_SysIntegration_DW.temporalCounter_i1_m = 0U;
    test2_SysIntegration_DW.prevFdbkMsgId = 0U;
    test2_SysIntegration_DW.bitsForTID0.boolFdbk = false;
    test2_SysIntegration_DW.boolHomingEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID0.boolHomingEvt = false;

    /* Chart: '<S94>/Chart' */
    test2_SysIntegration_DW.bitsForTID0.is_c23_test2_SysIntegration =
      test2_SysIntegration_IN_Init_n;
    test2_SysIntegration_B.ErrMsg.Head.MsgId = 0U;
    test2_SysIntegration_B.ErrMsg.Head.OpCode = 0U;
    test2_SysIntegration_B.ErrMsg.Body.Data = 0U;

    /* SystemInitialize for Chart: '<Root>/MsgRouter2' */
    test2_SysIntegr_MsgRouter1_Init(&test2_SysIntegration_DW.sf_MsgRouter2);

    /* SystemInitialize for Chart: '<Root>/MsgRouter1' */
    test2_SysIntegr_MsgRouter1_Init(&test2_SysIntegration_DW.sf_MsgRouter1);

    /* SystemInitialize for Chart: '<S123>/RTMsgRuter' */
    test2_SysIntegration_DW.bitsForTID7.is_active_c4_test2_SysIntegrati = 0;
    test2_SysIntegration_DW.prevMsgIn1Id = 0U;
    test2_SysIntegration_DW.prevMsgIn2Id = 0U;
    test2_SysIntegration_DW.prevMsgIn3Id = 0U;
    test2_SysIntegration_DW.RTChipWriteEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID7.RTChipWriteEvt = false;

    /* SystemInitialize for Chart: '<Root>/MsgRouter3' */
    test2_SysIntegr_MsgRouter1_Init(&test2_SysIntegration_DW.sf_MsgRouter3);

    /* SystemInitialize for Chart: '<S17>/MsgRouter2' */
    test2_SysIntegr_MsgRouter1_Init(&test2_SysIntegration_DW.sf_MsgRouter2_n);

    /* SystemInitialize for Chart: '<S126>/Chart' */
    test2_SysIntegration_DW.bitsForTID7.is_RTCtrl = 0;
    test2_SysIntegration_DW.temporalCounter_i1_mw = 0U;
    test2_SysIntegration_DW.bitsForTID7.is_active_c5_test2_SysIntegrati = 0;
    test2_SysIntegration_DW.prevRecordCtrlMsgId = 0U;
    test2_SysIntegration_DW.bitsForTID7.TimeSetSwitch1 = false;
    test2_SysIntegration_DW.bitsForTID7.TimeSetSwitch2 = false;
    test2_SysIntegration_DW.prevLowPowerMsgId = 0U;
    test2_SysIntegration_DW.TotalmSecond = 0U;
    test2_SysIntegration_DW.LargeDoseTimerOpDt = 0U;
    test2_SysIntegration_DW.bitsForTID7.boolRelativeTimerEna = false;
    test2_SysIntegration_DW.prevSysDiagMsgId = 0U;
    test2_SysIntegration_DW.prevDayInfo = 0U;
    test2_SysIntegration_DW.prevMonthInfo = 0U;
    test2_SysIntegration_DW.prevYearInfo = 0U;
    test2_SysIntegration_DW.tryTime = 0U;
    test2_SysIntegration_DW.prevRelativeTimerApplyMsgId = 0U;
    test2_SysIntegration_DW.LargeDoseTimerOpMode = 0U;
    test2_SysIntegration_B.bitsForTID7.boolAbsTimeHold = false;
    test2_SysIntegration_B.bitsForTID7.boolRelativeTimerHold = false;
    test2_SysIntegration_B.LargeDoseRelativeSec = 0U;
    test2_SysIntegration_B.boolSysEnable = false;
    test2_SysIntegration_DW.InitTimerEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID7.InitTimerEvt = false;

    /* SystemInitialize for Chart: '<S87>/Chart' */
    test2_SysIntegration_DW.bitsForTID4.is_ActuatorController = 0;
    test2_SysIntegration_DW.bitsForTID4.is_Idle = 0;
    test2_SysIntegration_DW.bitsForTID4.is_TaskSynthesizer = 0;
    test2_SysIntegration_DW.temporalCounter_i1_ob = 0U;
    test2_SysIntegration_DW.bitsForTID4.is_active_c16_test2_SysIntegrat = 0;
    test2_SysIntegration_DW.prevCalibraMsgId_n = 0U;
    test2_SysIntegration_DW.prevPerfAckMsgId = 0U;
    test2_SysIntegration_DW.prevDoseMsgId = 0U;
    test2_SysIntegration_DW.DoseMode_e = 0U;
    test2_SysIntegration_DW.bitsForTID4.boolEnterActuatorBusy = false;
    test2_SysIntegration_B.targetEncCnt = 0;
    test2_SysIntegration_B.bitsForTID4.boolDoseCtrlBusy = false;
    test2_SysIntegration_DW.ServoOnEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID4.ServoOnEvt = false;
    test2_SysIntegration_DW.ForceStopEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID4.ForceStopEvt = false;
    test2_SysIntegration_DW.PopBufEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID4.PopBufEvt = false;

    /* SystemInitialize for Chart: '<S106>/TaskScheduler' */
    test2_SysIntegration_DW.bitsForTID7.is_DoseTaskScheduler = 0;
    test2_SysIntegration_DW.bitsForTID7.is_LargeDoseTimerRunOrStop = 0;
    test2_SysIntegration_DW.NextSubBaseDoseTaskTimeHitSec = MAX_uint16_T;
    test2_SysIntegration_DW.NextSubLargeDoseTaskTimeHitSec = MAX_uint16_T;
    test2_SysIntegration_DW.prevSubBaseDoseId[0] = 0U;
    test2_SysIntegration_DW.prevSubBaseDoseId[1] = 0U;
    test2_SysIntegration_DW.SubLargeDoseId = 0U;
    test2_SysIntegration_DW.prevSubLargeDoseId = 0U;
    test2_SysIntegration_DW.LargeDoseTaskNo = 0U;
    test2_SysIntegration_DW.bitsForTID7.boolLargeDoseTimeHold = false;
    test2_SysIntegration_DW.bitsForTID7.boolLargeDoseTimeRun = false;
    test2_SysIntegration_DW.bitsForTID7.boolLastLargeSubDose = false;
    test2_SysIntegration_DW.temp_LastDoseEncCnt = 0;
    test2_SysIntegration_DW.temp_LeftDoseEncCnt = 0;
    test2_SysIntegration_B.NextHitTime = 0U;
    test2_SysIntegration_DW.PushDoseEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID7.PushDose = false;
    test2_SysIntegration_DW.ClearQueueEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID7.ClearQueueEvt = false;
    test2_SysIntegration_DW.previousTicks_m = 0U;

    /* Chart: '<S106>/TaskScheduler' */
    test2_SysIntegration_DW.bitsForTID7.is_c29_test2_SysIntegration =
      test2_SysIntegration_IN_Init_b;
    test2_SysIntegration_DW.temporalCounter_i1 = 0U;
    test2_SysIntegration_B.DoseMissionMsgOut.Head.MsgId = 0U;
    test2_SysIntegration_B.DoseMissionMsgOut.Head.OpCode = 0U;
    test2_SysIntegration_B.DoseMissionMsgOut.Body.TargetEncCnt = 0;
    test2_SysIntegration_B.DoseMissionMsgOut.Body.PermittedTime = 0U;
    test2_SysIntegration_B.MotionCtrl2RTMsgOut.Head.MsgId = 0U;
    test2_SysIntegration_B.MotionCtrl2RTMsgOut.Head.OpCode = 0U;
    test2_SysIntegration_B.MotionCtrl2RTMsgOut.Body.Data = 0U;

    /* Chart: '<S104>/Buffer' */
    test2_SysIntegration_B.DoseCtrlMsgOut_j.Head.MsgId = 0U;
    test2_SysIntegration_B.DoseCtrlMsgOut_j.Head.OpCode = 0U;
    test2_SysIntegration_B.DoseCtrlMsgOut_j.Body.TargetEncCnt = 0;
    test2_SysIntegration_B.DoseCtrlMsgOut_j.Body.PermittedTime = 0U;
    test2_SysIntegration_DW.QueueDepth = 0U;
    memset(&test2_SysIntegration_DW.TargetEncCntQ[0], 0, 20U * sizeof(int32_T));
    memset(&test2_SysIntegration_DW.PermitTimeQ[0], 0, 20U * sizeof(uint32_T));
    for (i = 0; i < 20; i++) {
      test2_SysIntegration_DW.OpCodeQ[i] = 0U;
    }

    test2_SysIntegration_B.bitsForTID4.boolBufferEmpty = true;

    /* End of Chart: '<S104>/Buffer' */

    /* SystemInitialize for Chart: '<S108>/Chart' */
    test2_SysIntegration_DW.bitsForTID0.is_Sync = 0;
    test2_SysIntegration_DW.bitsForTID0.is_Wait = 0;
    test2_SysIntegration_DW.bitsForTID0.is_Wait4Sync_c = 0;
    test2_SysIntegration_DW.temporalCounter_i1_di = 0U;
    test2_SysIntegration_DW.bitsForTID0.is_Wait4Task = 0;
    test2_SysIntegration_DW.bitsForTID0.is_Wait4Sync = 0;
    test2_SysIntegration_DW.temporalCounter_i2 = 0U;
    test2_SysIntegration_DW.prevDeliveryMissionId = 0U;
    test2_SysIntegration_DW.bitsForTID0.boolNewDeliveryMission = false;
    test2_SysIntegration_DW.prevSlaveMsgId = 0U;
    test2_SysIntegration_DW.errTime = 0U;
    test2_SysIntegration_DW.DoseMode = 0U;
    test2_SysIntegration_DW.bitsForTID0.boolSyn = false;
    test2_SysIntegration_DW.prevActuatorMsgId = 0U;
    test2_SysIntegration_DW.bitsForTID0.boolCtrlAccuracyFailure = false;
    test2_SysIntegration_DW.EncRstEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID0.EncRstEvt = false;
    test2_SysIntegration_DW.previousTicks_l = 0U;

    /* Chart: '<S108>/Chart' */
    test2_SysIntegration_DW.bitsForTID0.is_c30_test2_SysIntegration =
      test2_SysIntegration_IN_Init;
    test2_SysIntegration_B.SynReqMsg.Head.MsgId = 0U;
    test2_SysIntegration_B.SynReqMsg.Head.OpCode = 0U;
    test2_SysIntegration_B.SynReqMsg.Body.Data = 0U;
    test2_SysIntegration_B.DoseMissionMsg = test2_SysIntegration_B.SynReqMsg;
    test2_SysIntegration_B.DoseActionResultMsg =
      test2_SysIntegration_B.DoseMissionMsg;
    test2_SysIntegration_B.SysDiagMsg.Head.MsgId = 0U;
    test2_SysIntegration_B.SysDiagMsg.Head.OpCode = 0U;
    test2_SysIntegration_B.SysDiagMsg.Body.Data = 0U;
    test2_SysIntegration_B.LargeDoseTimeHitMsg.Head.MsgId = 0U;
    test2_SysIntegration_B.LargeDoseTimeHitMsg.Head.OpCode = 0U;
    test2_SysIntegration_B.LargeDoseTimeHitMsg.Body.Data = 0U;
    test2_SysIntegration_B.bitsForTID0.boolMissionStop = true;
    test2_SysIntegration_DW.bitsForTID0.boolMissionUnfinish = false;
    test2_SysIntegration_DW.targetEncCnt = 0;
    test2_SysIntegration_DW.prevResidueEncCnt = 0;

    /* SystemInitialize for Chart: '<Root>/MsgRouter4' */
    test2_SysIntegr_MsgRouter1_Init(&test2_SysIntegration_DW.sf_MsgRouter4);

    /* SystemInitialize for Chart: '<S89>/ResidueDoseEval' */
    test2_SysIntegration_DW.bitsForTID0.is_Op = 0;
    test2_SysIntegration_DW.temporalCounter_i2_k = 0U;
    test2_SysIntegration_DW.bitsForTID0.is_OpEnd_g = 0;
    test2_SysIntegration_DW.temporalCounter_i1_i = 0U;
    test2_SysIntegration_DW.bitsForTID0.is_active_c18_test2_SysIntegrat = 0;
    test2_SysIntegration_DW.bitsForTID0.is_c18_test2_SysIntegration = 0;
    test2_SysIntegration_DW.bitsForTID0.boolStartUp = false;
    test2_SysIntegration_DW.EncClrEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID0.EncClrEvt = false;

    /* Chart: '<S68>/Chart1' */
    test2_SysIntegration_DW.bitsForTID0.is_c42_test2_SysIntegration =
      test2_SysIntegration_IN_Idle_n;

    /* SystemInitialize for Chart: '<S69>/Chart' */
    test2_SysIntegration_DW.bitsForTID0.is_BubbleDetected = 0;
    test2_SysIntegration_DW.temporalCounter_i1_js = 0U;

    /* Chart: '<S69>/Chart' */
    test2_SysIntegration_DW.bitsForTID0.is_c43_test2_SysIntegration =
      test2_SysIn_IN_NoBubbleDetected;
    test2_SysIntegration_B.BubbleDetectionMsg.Head.MsgId = 0U;
    test2_SysIntegration_B.BubbleDetectionMsg.Head.OpCode = 1U;
    test2_SysIntegration_B.BubbleDetectionMsg.Body.Data = 0U;

    /* SystemInitialize for Chart: '<S96>/MotorRunDriver' */
    test2_SysIntegration_DW.bitsForTID0.is_MotorServOn = 0;
    test2_SysIntegration_DW.bitsForTID0.boolCallbackSucceed = false;
    test2_SysIntegration_DW.bitsForTID0.temp_ServoState = false;

    /* Chart: '<S96>/MotorRunDriver' */
    test2_SysIntegration_DW.bitsForTID0.is_MotorRun =
      test2_SysIntegration_IN_Init;
    test2_SysIntegration_B.bitsForTID0.boolMotorServoEnable = false;
    test2_SysIntegration_B.bitsForTID0.boolMotorHomingEnable = false;
    test2_SysIntegration_B.bitsForTID0.boolMotorForwardEnable = false;
    test2_SysIntegration_B.MotorServoStateMsg.Head.MsgId = 0U;
    test2_SysIntegration_B.MotorServoStateMsg.Head.OpCode = 0U;
    test2_SysIntegration_B.MotorServoStateMsg.Body.Data = 0U;

    /* SystemInitialize for Chart: '<S83>/Chart' */
    test2_SysIntegration_DW.bitsForTID0.is_ServoAnalyzor = 0;
    test2_SysIntegration_DW.bitsForTID0.boolOcclusionStop = false;
    test2_SysIntegration_DW.prevDrvFdbkMsgId = 0U;
    test2_SysIntegration_DW.temp_OpCode = 0U;
    test2_SysIntegration_B.bitsForTID0.boolMonitorEna = false;
    test2_SysIntegration_DW.OcclusionJudgeEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID0.OcclusionJudgeEvt = false;

    /* Chart: '<S83>/Chart' */
    test2_SysIntegration_DW.bitsForTID0.is_PerfAnalysor =
      test2_SysIntegration_IN_Idle_k;
    test2_SysIntegration_B.PerfEvalMsg.Head.MsgId = 0U;
    test2_SysIntegration_B.PerfEvalMsg.Head.OpCode = 0U;
    test2_SysIntegration_B.PerfEvalMsg.Body.millSec = 0U;
    test2_SysIntegration_B.PerfEvalMsg.Body.mAmSecInteg = 0U;
    test2_SysIntegration_B.PerfACKMissionFinishMsg.Head.MsgId = 0U;
    test2_SysIntegration_B.PerfACKMissionFinishMsg.Head.OpCode = 0U;
    test2_SysIntegration_B.PerfACKMissionFinishMsg.Body.Data = 0U;

    /* SystemInitialize for Chart: '<S98>/Chart' */
    test2_SysIntegration_DW.MemMatrix[0] = 0.0F;
    test2_SysIntegration_DW.MemMatrix[1] = 0.0F;
    test2_SysIntegration_DW.MemMatrix[2] = 0.0F;
    test2_SysIntegration_DW.MemMatrix[3] = 0.0F;
    test2_SysIntegration_DW.MemMatrix[4] = 0.0F;
    test2_SysIntegration_DW.MemMatrix[5] = 0.0F;
    test2_SysIntegration_DW.MemMatrix[6] = 0.0F;
    test2_SysIntegration_DW.MemMatrix[7] = 0.0F;
    test2_SysIntegration_DW.MemMatrix[8] = 0.0F;
    test2_SysIntegration_DW.MemMatrix[9] = 0.0F;
    test2_SysIntegration_DW.MemWeight = 0.5F;

    /* Chart: '<S98>/Chart' */
    test2_SysIntegration_B.OcclusionDiagMsg.Head.MsgId = 0U;
    test2_SysIntegration_B.OcclusionDiagMsg.Head.OpCode = 0U;
    test2_SysIntegration_B.OcclusionDiagMsg.Body.Data = 0U;

    /* SystemInitialize for Chart: '<Root>/MsgRouter5' */
    test2_SysIntegration_DW.bitsForTID5.is_active_c52_test2_SysIntegrat = 0;

    /* SystemInitialize for Chart: '<S67>/PressureSingularityDetector' */
    test2_SysIntegration_DW.bitsForTID0.is_Op_p = 0;
    test2_SysIntegration_DW.bitsForTID0.is_Monitor_o = 0;
    test2_SysIntegration_DW.temporalCounter_i1_d5 = 0U;

    /* Chart: '<S67>/PressureSingularityDetector' */
    test2_SysIntegration_DW.bitsForTID0.is_Monitor =
      test2_SysIntegration_IN_Idle_k;
    test2_SysIntegration_B.IdleMeanValuePressure = 0;
    test2_SysIntegration_B.OpMaxPressure =
      test2_SysIntegration_B.IdleMeanValuePressure;
    test2_SysIntegration_B.OpMinPressure =
      test2_SysIntegration_B.IdleMeanValuePressure;
    test2_SysIntegration_B.PressureDiagMsg.Head.MsgId = 0U;
    test2_SysIntegration_B.PressureDiagMsg.Head.OpCode = 1U;
    test2_SysIntegration_B.PressureDiagMsg.Body.Data = 0U;

    /* SystemInitialize for Chart: '<S113>/MemoryFilter' */
    test2_SysIntegration_DW.temporalCounter_i1_pl = 0U;
    test2_SysIntegration_DW.bitsForTID4.is_active_c32_test2_SysIntegrat = 0;
    test2_SysIntegration_DW.bitsForTID4.is_c32_test2_SysIntegration = 0;
    test2_SysIntegration_DW.AlarmFMCodeMemory[0] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[1] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[2] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[3] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[4] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[5] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[6] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[7] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[8] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[9] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[10] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[11] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[12] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[13] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[14] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[15] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[16] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[17] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[18] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[19] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[20] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[21] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[22] = 0U;
    test2_SysIntegration_DW.AlarmFMCodeMemory[23] = 0U;
    test2_SysIntegration_DW.prevMsgInIdVector[0] = 0U;
    test2_SysIntegration_DW.prevMsgInIdVector[1] = 0U;
    test2_SysIntegration_DW.prevMsgInIdVector[2] = 0U;
    test2_SysIntegration_DW.prevMsgInIdVector[3] = 0U;
    test2_SysIntegration_DW.prevMsgInIdVector[4] = 0U;
    test2_SysIntegration_DW.prevMsgInIdVector[5] = 0U;
    test2_SysIntegration_DW.prevMsgInIdVector[6] = 0U;
    test2_SysIntegration_DW.prevMsgInIdVector[7] = 0U;
    test2_SysIntegration_DW.sendMsgEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID4.sendMsgEvt = false;

    /* SystemInitialize for Chart: '<S113>/Buffer' */
    test2_SysIntegration_DW.HighStack[0] = 0U;
    test2_SysIntegration_DW.HighStack[1] = 0U;
    test2_SysIntegration_DW.HighStack[2] = 0U;
    test2_SysIntegration_DW.HighStack[3] = 0U;
    test2_SysIntegration_DW.HighStack[4] = 0U;
    test2_SysIntegration_DW.HighStack[5] = 0U;
    test2_SysIntegration_DW.HighStack[6] = 0U;
    test2_SysIntegration_DW.HighStack[7] = 0U;
    test2_SysIntegration_DW.LowStack[0] = 0U;
    test2_SysIntegration_DW.LowStack[1] = 0U;
    test2_SysIntegration_DW.LowStack[2] = 0U;
    test2_SysIntegration_DW.LowStack[3] = 0U;
    test2_SysIntegration_DW.LowStack[4] = 0U;
    test2_SysIntegration_DW.LowStack[5] = 0U;
    test2_SysIntegration_DW.LowStack[6] = 0U;
    test2_SysIntegration_DW.LowStack[7] = 0U;
    test2_SysIntegration_DW.MidStack[0] = 0U;
    test2_SysIntegration_DW.MidStack[1] = 0U;
    test2_SysIntegration_DW.MidStack[2] = 0U;
    test2_SysIntegration_DW.MidStack[3] = 0U;
    test2_SysIntegration_DW.MidStack[4] = 0U;
    test2_SysIntegration_DW.MidStack[5] = 0U;
    test2_SysIntegration_DW.MidStack[6] = 0U;
    test2_SysIntegration_DW.MidStack[7] = 0U;
    test2_SysIntegration_B.boolAlarmEmpty[0] = true;
    test2_SysIntegration_B.boolAlarmEmpty[1] = true;
    test2_SysIntegration_B.boolAlarmEmpty[2] = true;

    /* Chart: '<S113>/Buffer' */
    test2_SysIntegration_B.AlarmACKMsgOut.Head.MsgId = 0U;
    test2_SysIntegration_B.AlarmACKMsgOut.Head.OpCode = 0U;
    test2_SysIntegration_B.AlarmACKMsgOut.Body.Data = 0U;

    /* SystemInitialize for Chart: '<S113>/MsgAdaptor' */
    test2_SysIntegration_DW.bitsForTID5.is_active_c33_test2_SysIntegrat = 0;
    test2_SysIntegration_DW.prevInput1MsgId = 0U;
    test2_SysIntegration_DW.prevInput2MsgId = 0U;
    test2_SysIntegration_DW.OcclusionObservationCancelEvent = 0U;
    test2_SysIntegration_B.OcclusionObservationCancel = false;

    /* SystemInitialize for Chart: '<S112>/Chart' */
    test2_SysIntegration_DW.bitsForTID1.is_TaskAct = 0;
    test2_SysIntegration_DW.bitsForTID1.is_idle = 0;
    test2_SysIntegration_DW.bitsForTID1.was_idle = 0;
    test2_SysIntegration_DW.bitsForTID1.is_idle_g = 0;
    test2_SysIntegration_DW.bitsForTID1.was_idle_o = 0;
    test2_SysIntegration_DW.bitsForTID1.is_active_c19_test2_SysIntegrat = 0;
    test2_SysIntegration_DW.prevSysDiagMsgId_e = 0U;
    test2_SysIntegration_DW.bitsForTID1.HighAlarmEnable = false;
    test2_SysIntegration_DW.bitsForTID1.LowAlarmEnable = false;
    test2_SysIntegration_DW.bitsForTID1.MidAlarmEnable = false;
    test2_SysIntegration_B.bitsForTID1.LowPowerMsgOut = false;
    test2_SysIntegration_B.SysDiagMsgOut_c[0] = 0U;
    test2_SysIntegration_B.SysDiagMsgOut_c[1] = 0U;
    test2_SysIntegration_B.SysDiagMsgOut_c[2] = 0U;
    test2_SysIntegration_DW.AlarmCtrlEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID1.AlarmCtrlEvt = false;
    test2_SysIntegration_DW.HighLevelAlarmEvtStartEventCoun = 0U;
    test2_SysIntegration_B.bitsForTID1.HighLevelAlarmEvtStart = false;
    test2_SysIntegration_DW.HighLevelAlarmEvtStopEventCount = 0U;
    test2_SysIntegration_B.bitsForTID1.HighLevelAlarmEvtStop = false;

    /* Chart: '<S30>/Chart' */
    test2_SysIntegration_B.bitsForTID4.BleConnStatus =
      test2_SysInteg_ChkBleConnection();

    /* SystemInitialize for Chart: '<S34>/Chart' */
    test2_SysIntegration_DW.BleDataFrameId = MAX_uint8_T;

    /* Chart: '<S34>/Chart' */
    enter_internal_c9_test2_SysInte();

    /* Chart: '<S4>/Chart' */
    test2_SysIntegration_B.rtEncRdOut = test2_SysIntegra_EncoderCntRead(false);

    /* Chart: '<S45>/Chart' */
    test2_SysIntegration_B.LP2RTMsgOut_m.Head.MsgId = 0U;
    test2_SysIntegration_B.LP2RTMsgOut_m.Head.OpCode = 0U;
    test2_SysIntegration_B.LP2RTMsgOut_m.Body.Data = 0U;

    /* SystemInitialize for Chart: '<S92>/Chart' */
    test2_SysIntegration_DW.bitsForTID0.is_DoseDynInfoMonitor = 0;
    test2_SysIntegration_DW.bitsForTID0.is_OpEnd = 0;
    test2_SysIntegration_DW.prevDoseMissionMsgId = 0U;
    test2_SysIntegration_DW.prevMotionStopACKMsgId = 0U;
    test2_SysIntegration_DW.temp_OpCode_l = 0U;
    test2_SysIntegration_DW.prevDoseDynMsgId = 0U;
    test2_SysIntegration_DW.bitsForTID0.boolKeepUpdate = false;

    /* Chart: '<S92>/Chart' */
    test2_SysIntegration_DW.bitsForTID0.is_c21_test2_SysIntegration =
      test2_SysIntegration_IN_Init1;
    test2_SysIntegration_B.DynDoseInfoMsg.Head.MsgId = 0U;
    test2_SysIntegration_B.DynDoseInfoMsg.Head.OpCode = 0U;
    test2_SysIntegration_B.DynDoseInfoMsg.Body.TargetDose = 0U;
    test2_SysIntegration_B.DynDoseInfoMsg.Body.TimeInfo = 0U;
    test2_SysIntegration_B.DynDoseInfoMsg.Body.CompleteDose = 0U;
    test2_SysIntegration_B.DailyStatMsg.Head.MsgId = 0U;
    test2_SysIntegration_B.DailyStatMsg.Head.OpCode = 0U;
    test2_SysIntegration_B.DailyStatMsg.Body.DayInfo = 0U;
    test2_SysIntegration_B.DailyStatMsg.Body.ResidueDoseEst = 0U;
    test2_SysIntegration_B.DailyStatMsg.Body.TotalAmountAcc = 0U;
    test2_SysIntegration_B.DailyStatMsg.Body.DailyAmountAcc = 0U;
    test2_SysIntegration_B.DailyStatMsg.Body.LargeAmountAcc = 0U;

    /* SystemInitialize for Chart: '<Root>/MsgRouter6' */
    test2_SysIntegration_DW.bitsForTID5.is_active_c53_test2_SysIntegrat = 0;

    /* Chart: '<S14>/MsgRouter2_100ms' */
    test2_SysIntegration_DW.bitsForTID4.is_c55_test2_SysIntegration =
      test2_SysIntegration_IN_Init_b;
    test2_SysIntegration_B.Group1FlashAccessMsgOut_d.Head.MsgId = 0U;
    test2_SysIntegration_B.Group1FlashAccessMsgOut_d.Head.OpCode = 0U;
    b.MajorId = 0U;
    b.MinorId = 0U;
    memset(&b.Data[0], 0, 132U * sizeof(uint8_T));
    test2_SysIntegration_B.Group1FlashAccessMsgOut_d.Body = b;
    test2_SysIntegration_DW.prevMsg1Id_l = 0U;
    test2_SysIntegration_DW.prevMsg2Id = 0U;

    /* SystemInitialize for Chart: '<S14>/MsgRouter3' */
    test2_SysIntegration_DW.temporalCounter_i1_ev = 0U;
    test2_SysIntegration_DW.bitsForTID4.is_active_c56_test2_SysIntegrat = 0;
    test2_SysIntegration_DW.bitsForTID4.is_c56_test2_SysIntegration = 0;

    /* SystemInitialize for Chart: '<S20>/PressureADCRead' */
    test2_SysIntegration_B.PressureADC = 0;
    test2_SysIntegration_DW.previousTicks = 0U;

    /* Chart: '<S20>/PressureADCRead' */
    test2_SysIntegration_DW.bitsForTID2.is_c44_test2_SysIntegration =
      test2_SysIntegration_IN_Init;
    test2_SysIntegration_DW.temporalCounter_i1_o = 0U;

    /* SystemInitialize for Enabled SubSystem: '<S83>/Enabled Subsystem' */
    /* InitializeConditions for DiscreteIntegrator: '<S103>/Discrete-Time Integrator1' */
    test2_SysIntegration_DW.DiscreteTimeIntegrator1_DSTATE = 0U;

    /* InitializeConditions for DiscreteIntegrator: '<S103>/Discrete-Time Integrator' */
    test2_SysIntegration_DW.DiscreteTimeIntegrator_DSTATE = 0U;

    /* End of SystemInitialize for SubSystem: '<S83>/Enabled Subsystem' */

    /* SystemInitialize for Chart: '<S19>/SysDiag_ProcessLogMsgRouter' */
    test2_SysIntegration_DW.prevCh1MsgId = 0U;
    test2_SysIntegration_DW.prevCh2MsgId = 0U;

    /* Chart: '<S19>/SysDiag_ProcessLogMsgRouter' */
    test2_SysIntegration_DW.bitsForTID4.is_c38_test2_SysIntegration =
      test2_SysIntegration_IN_Init;
    test2_SysIntegration_B.FlashWriteInforMsg.Head.MsgId = 0U;
    test2_SysIntegration_B.FlashWriteInforMsg.Head.OpCode = 0U;
    test2_SysIntegration_B.FlashWriteInforMsg.Body.Data = 0U;

    /* SystemInitialize for Chart: '<S113>/Actuator' */
    test2_SysIntegration_DW.temporalCounter_i1_j = 0U;
    test2_SysIntegration_DW.bitsForTID4.is_active_c15_test2_SysIntegrat = 0;
    test2_SysIntegration_DW.PopAlarmEvtEventCounter = 0U;
    test2_SysIntegration_B.bitsForTID4.PopAlarmEvt = false;

    /* Chart: '<S114>/Chart' */
    test2_SysIntegration_B.TimerCtrlMsg.Head.MsgId = 0U;
    test2_SysIntegration_B.TimerCtrlMsg.Head.OpCode = 0U;
    test2_SysIntegration_B.TimerCtrlMsg.Body.Data = 0U;

    /* SystemInitialize for Chart: '<S122>/Chart' */
    test2_SysIntegration_B.bitsForTID7.boolChipErrStatus = false;

    /* Chart: '<S122>/Chart' */
    test2_SysIntegration_B.RTMsgOut.Head.MsgId = 0U;
    test2_SysIntegration_B.RTMsgOut.Head.OpCode = 0U;
    for (i = 0; i < 6; i++) {
      b_0.Time[i] = 0U;
    }

    test2_SysIntegration_B.RTMsgOut.Body = b_0;

    /* End of Chart: '<S122>/Chart' */

    /* Enable for Chart: '<S106>/TaskScheduler' */
    test2_SysIntegration_DW.previousTicks_m =
      test2_SysIntegration_M->Timing.clockTick7;

    /* Enable for Chart: '<S108>/Chart' */
    test2_SysIntegration_DW.previousTicks_l =
      test2_SysIntegration_M->Timing.clockTick0;

    /* Enable for Chart: '<S20>/PressureADCRead' */
    test2_SysIntegration_DW.previousTicks =
      test2_SysIntegration_M->Timing.clockTick2;
  }
}

/* Model terminate function */
void test2_SysIntegration_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
