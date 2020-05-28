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


void ert_pwmTrans(int16_t data, uint16_t fullscale, uint8_t *percent, bool *direction);




#ifdef __cplusplus
}
#endif

