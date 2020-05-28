/************************************************
 * DESCRIPTION:
 * comm msg is base on ssz_comm_frame
 * the data at SszOneFrame have msg_send_sequence(1 byte),msg_id(2 byte)
 * the msg_id<0x8000 is request, msg_id|0x8000 is respond
 ************************************************/
#pragma once
#include "ssz_def.h"
#include "ssz_comm_frame.h"

/************************************************
 * Declaration
 ************************************************/
#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	// the peer id, if not have src and dest id, it will not use
	int8_t from_id;
	// when respond, the respond msg sequence should same as it
	uint8_t from_msg_sequence;
	uint16_t from_msg_id;
} SszCommMsgFromInfo;

struct SszCommMsg_t;
typedef void (*SszCommMsgReceiveHandler)(struct SszCommMsg_t* comm_msg,
                                         SszCommMsgFromInfo* from,
                                         const uint8_t* msg_data,
                                         int16_t msg_data_size);

typedef struct SszCommMsg_t {
	SszCommMsgReceiveHandler recv_handler;
	void* user_data;
	SszCommFrame frame;
	// when send one msg, it will increase
	// use it can check if the received msg is relate with send msg
	uint8_t msg_send_sequence;
} SszCommMsg;

// data_cache_at_frame: this will save the data at the frame
// data_cache_max_size: this define the frame's data size which can take
// is_have_src_and_dest_id: is have src_id and dest_id at one frame
// self_id: my device id to communicate,
//    valid only when is_have_src_and_dest_id=true
void ssz_comm_msg_init(SszCommMsg* comm_msg, void* user_data,
                       SszCommMsgReceiveHandler recv_handler,
                       SszFile* send_file, void* data_cache_at_frame,
                       int16_t data_cache_max_size,
                       bool is_have_src_and_dest_id, int8_t self_id);

// set dest id
void ssz_comm_msg_set_destination(SszCommMsg* comm_msg, int8_t dest_id);

// send buff to dest
bool ssz_comm_msg_send(SszCommMsg* comm_msg, uint16_t msg_id,
                       const void* msg_data, int msg_data_size,
                       uint8_t* return_send_sequence);

// send buff to dest with send_sequence
bool ssz_comm_msg_send_ex(SszCommMsg* comm_msg, int8_t dest_id, uint16_t msg_id,
                          const void* msg_data, int msg_data_size,
                          uint8_t send_sequence);

// send respond to from
bool ssz_comm_msg_send_respond(SszCommMsg* comm_msg, SszCommMsgFromInfo* from,
                               const void* msg_data, int msg_data_size);

// handle new receive byte, return true if it is a part of frame
bool ssz_comm_msg_on_receive_new_byte(SszCommMsg* comm_msg, uint8_t ch);

//can be used like encrypt or decode
//Note: it will convert the frame data
//e.g. recv one frame->decode->one comm msg
//	   send one comm msg->encry->one frame
void ssz_comm_msg_set_convert_handler(SszCommMsg* comm_msg,
	SszCommFrameDataConvertHandler convert_handler,
	SszCommFrameDataConvertAfterHandler convert_after_handler);

#ifdef __cplusplus
}
#endif
