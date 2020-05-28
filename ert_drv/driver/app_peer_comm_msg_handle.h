/************************************************
* DESCRIPTION:
*
*
************************************************/
#pragma once

#include "ssz_def.h"
#include "drv_peer_comm_msg.h"


/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	PeerCommMsgHandler handler;
	// if the msg data length less than it, the param is wrong
	int16_t msg_data_min_size;
	PeerCommMsgID msg;
} PeerCommMsgHanlderInfo;

void app_peer_comm_msg_handle_init(); 

#ifdef __cplusplus
}
#endif

