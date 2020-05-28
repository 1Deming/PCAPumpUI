/************************************************
* DESCRIPTION:
*
*
************************************************/
#pragma once

#include "ssz_def.h"
#include "drv_data_log.h"
#include "rtwtypes.h"
#include "data_type.h"
/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif


//bool ert_recordWrite(type_RT *ptrRT, uint8_t major_id, uint8_t minor_id, uint8_t *data_buff, uint8_t channel);
bool ert_recordWrite(type_RT *ptrRT, uint8_t major_id, uint8_t minor_id, uint8_t *data_buff, uint8_t channel);




#ifdef __cplusplus
}
#endif

