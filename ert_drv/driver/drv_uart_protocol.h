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
void ERT_drv_uart_protocol_init(uint8_t uart_id);//整合


typedef enum
{
	kUartVirtual,
	kUartReal,
	kUartIDMAX
}ERTUartID;


bool ERT_drv_uart_new_data_flag(uint8_t uart_id);
int ERT_drv_uart_get_data(uint8_t uart_id, uint8_t *data);
int ERT_drv_uart_send(uint8_t uart_id, void *buff, int buff_size);



bool ert_getSerialData(uint8_t *data);
bool ert_sendSerialData(uint8_t *data);



#ifdef __cplusplus
}
#endif

