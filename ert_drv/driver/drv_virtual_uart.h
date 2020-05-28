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


void drv_virtaul_uart_init(void);
int drv_virtual_uart_send(uint8_t *buff, int buff_size);



#ifdef __cplusplus
}
#endif

