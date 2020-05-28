/************************************************
* DESCRIPTION:
*
*
************************************************/
#pragma once


#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif

int8_t ERT_drv_ble_init(const char * device_name);
void ERT_drv_ble_start_advertising();
void ERT_drv_ble_stop_advertising();
void ERT_drv_ble_set_advertising_inter_ms(int inter_ms);
uint32_t ERT_drv_ble_change_mtu_size(int mt_size);
uint32_t ERT_drv_ble_change_conn_interval(int min_conn_interval_ms, int max_conn_interval_ms);
int ERT_drv_ble_is_connected();
void ERT_drv_ble_close();



	
#ifdef __cplusplus
}
#endif

