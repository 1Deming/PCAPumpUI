#pragma once
#include "ssz_def.h"
/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif


typedef enum {
	kEventNewTick,
	kEventReceiveNewMsg,
	kEventBLEReceiveNewData,
	kEventBLESendNewData,
	kEventPeerUartReceiveNewData,
	kEventPeerSendNewData,
	kEventBTUartReceiveNewData,
	kEventMCUUartReceiveNewData,

	kEventIDMax
}EventID;

#ifdef __cplusplus
}
#endif


