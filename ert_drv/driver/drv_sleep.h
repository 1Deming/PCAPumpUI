/************************************************
* DESCRIPTION:
*
*
************************************************/
#pragma once

#include "ssz_def.h"

/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif


extern bool g_drv_sleep_wakeup_by_key;
extern bool g_drv_sleep_wakeup_by_ble;
extern bool g_drv_sleep_wakeup_by_timer;


bool ERT_drv_sleep_get_wakeup_by_key_flag(void);
bool ERT_drv_sleep_get_wakeup_by_ble_flag(void);
bool ERT_drv_sleep_get_wakeup_by_timer_flag(void);


uint32_t ERT_drv_get_wakeup_timer_count_value(void);
void ERT_drv_sleep_uart_and_adc_deinit(uint8_t uart_id);
void ERT_drv_sleep_peripherals_except_uart_and_adc_deinit(void);
bool ERT_drv_sleep_enter_lpsleep(  uint32_t time_ms);
void ERT_drv_sleep_exit_lpsleep( uint8_t uart_id );



bool ert_ioCtrl(bool data);
bool ert_lpCtrl(bool data, uint32_t *SleepSpe);



#ifdef __cplusplus
}
#endif

