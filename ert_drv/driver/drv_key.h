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



int8_t ERT_drv_set_key_pin(void);
bool ERT_drv_get_key_state(void);

void ert_getKeyVector(uint8_t *data);





#ifdef __cplusplus
}
#endif

