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


void ert_channelsADC(bool swtich, 
					uint16_t *SysPwrADC,
					uint16_t *PressureADC,
					uint16_t *SZDJCurrentADC,
					uint16_t *STFDJCurrentADC,
					uint16_t *SlaverMCUPwrADC);





#ifdef __cplusplus
}
#endif

