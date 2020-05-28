#pragma once
#include "ssz_def.h"
#include "config.h"
/************************************************
 * Declaration
 ************************************************/

typedef enum {
	kCommPCUart,  // communicate with PC by UART
#if PEER_COMM_MSG_MODULE_ENABLE
	kCommPeerUart,  // communicate with peer by UART
#endif
#if SEGGER_RTT_MODULE_ENABLE
	kCommRTT,
#endif
	// add other
	kCommBLE, 
	kCommmIDMax
} CommID;

// the handler order
typedef enum {
	// it will handle first
	kCommHandleFirst,
	// it will handle data second(after first handle finish)
	kCommHandleSecond,
	// it will handle data third(after first and second handle finish)
	kCommHandleThird,

	kCommHandleMax
} CommHandleOrder;
