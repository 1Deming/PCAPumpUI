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


#define DRV_BLE_PTOROCOL_START_SIGN1	0x55
#define DRV_BLE_PTOROCOL_START_SIGN2	0xAA

#pragma pack(push)
#pragma pack(1)


void ERT_drv_ble_protocol_init(void);  
bool ERT_drv_ble_new_data_flag(void); 
int ERT_drv_ble_get_data(uint8_t *data);  //定长：224
int ERT_drv_ble_send(void *buff, int buff_size);


bool ert_getBleData(uint8_t *data);
void ert_sendBleData(uint8_t *data);


#ifdef __cplusplus
}
#endif

