/************************************************
* DESCRIPTION:
*
*
************************************************/
#pragma once

#include "ssz_def.h"
#include "ssz_def.h"
#include "ssz_comm_msg.h"
#include "peer_comm_msg_config.h"
#include "ssz_common.h"
#include "comm.h"

/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif

  
 // all error code
typedef enum {
	kPeerCommMsgAckSuccess,
	kPeerCommMsgAckFail,
	kPeerCommMsgAckUnknownMsg,
	kPeerCommMsgAckMsgParamWrong,
	kPeerCommMsgAckUnavailableAtCurrentOperationMode,
	// is handing
	kPeerCommMsgAckPending,
	// add other

	//add before this line
	kPeerCommMsgAckNull = 250,  // not send ack
} PeerCommMsgAckCode;

typedef PeerCommMsgAckCode (*PeerCommMsgHandler)(SszCommMsg* comm_msg,
                                                 SszCommMsgFromInfo* from,
                                                 const uint8_t* msg_data,
                                                 int16_t msg_data_size);
// result: may be kSszSuccess,kSszTimeout
typedef void (*PeerCommMsgRespondHandler)(SszCommMsg* comm_msg,
                                          SszResult result,
                                          SszCommMsgFromInfo* from,
                                          const uint8_t* msg_data,
                                          int16_t msg_data_size);
typedef bool (*PeerCommMsgIDtoStrHandler)(int msg_id, char msg_name[],
                                          int msg_name_max_size);

void peer_comm_msg_init(CommID comm_id, CommHandleOrder order);
// return: kSszNoEnoughResource=>the sent msg queue is full
//		  kSszSuccess,kSszError
SszResult peer_comm_msg_send(PeerCommMsgID msg_id, const void* msg_data,
                             int msg_data_size,
                             PeerCommMsgRespondHandler respond_handler);
// it will check if received, if not received, it will resend again(only once).
// Note: because need resend, so the msg_data_size must
//  less than PEER_COMM_MS_MAX_DATA_SIZE_WHEN_NEED_RESEND
// return: kSszNoEnoughResource,kSszSuccess,kSszError
SszResult peer_comm_msg_send_with_retry(
    PeerCommMsgID msg_id, const void* msg_data, int msg_data_size,
    PeerCommMsgRespondHandler respond_handler);
SszResult peer_comm_msg_send_respond(SszCommMsgFromInfo* from,
                                     const void* msg_data, int msg_data_size);
SszResult peer_comm_msg_send_notify(PeerCommMsgID msg_id, const void* msg_data,
                                    int msg_data_size);
// callback: if return not kPeerCommMsgAckNull,
//   it will send the act code to from
void peer_comm_msg_set_handler_for_all_msg(PeerCommMsgHandler handler);
// callback param result: kSszSuccess,
//    kSszNotExist(not find the related send msg)
void peer_comm_msg_set_respond_handler_for_all_msg(
    PeerCommMsgRespondHandler handler);
void peer_comm_msg_set_msg_id_to_str_handler(PeerCommMsgIDtoStrHandler handler);
SszCommMsg* peer_comm_msg(); 
  
  
 
#ifdef __cplusplus
}
#endif

