#ifndef RTW_HEADER_MsgBody4TaskStat_h_
#define RTW_HEADER_MsgBody4TaskStat_h_
#include "rtwtypes.h"

typedef struct {
  uint8_T   BleConnection;
  uint8_T   DoseCtrlConfig;
  uint8_T   BattLifeEst;
  uint16_T  ResidueDoseEst;
  uint16_T  BaseDoseDailyAcc;
  uint16_T  LargeDoseDailyAcc;
  uint8_T   FMCode;
} type_MsgBody4TaskStat;

#endif                                 /* RTW_HEADER_MsgBody4TaskStat_h_ */
