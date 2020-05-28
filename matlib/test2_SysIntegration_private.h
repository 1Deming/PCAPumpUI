/*
 * File: test2_SysIntegration_private.h
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

#ifndef RTW_HEADER_test2_SysIntegration_private_h_
#define RTW_HEADER_test2_SysIntegration_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "test2_SysIntegration.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_roundd_snf(real_T u);
extern real32_T rt_remf_snf(real32_T u0, real32_T u1);
extern void test2_SysIntegr_MsgRouter1_Init(DW_MsgRouter1_test2_SysIntegr_T
  *localDW);
extern void test2_SysIntegration_MsgRouter1(const type_HMI2SecurityMsg
  *rtu_Ch1AlarmMsgIn, const type_HMI2SecurityMsg *rtu_Ch2AlarmMsgIn,
  type_HMI2SecurityMsg *rty_Group1AlarmMsgOut, DW_MsgRouter1_test2_SysIntegr_T
  *localDW);

#endif                                 /* RTW_HEADER_test2_SysIntegration_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
