#pragma once
#include "ssz_def.h"
#include "config.h"
/************************************************
 * Declaration
 ************************************************/

// all support msg
typedef enum {
	kCommMsgGetVersion,
#if DATA_MODULE_ENABLE
	kCommMsgGetSerialNumber,
#endif
	// add other
} CommMsgID;
