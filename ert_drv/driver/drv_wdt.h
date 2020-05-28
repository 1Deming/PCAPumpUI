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

int8_t ERT_drv_wdt_init(int feed_time_in_ms);
void ERT_drv_feed_wdt(void);



#ifdef __cplusplus
}
#endif

