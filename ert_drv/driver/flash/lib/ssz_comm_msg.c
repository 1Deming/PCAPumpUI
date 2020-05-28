/************************************************
 * DESCRIPTION:
 *
 ************************************************/
#include "ssz_comm_msg.h"
#include "ssz_common.h"

/************************************************
 * Declaration
 ************************************************/

/************************************************
 * Variable
 ************************************************/

/************************************************
 * Function
 ************************************************/

static void ssz_comm_msg_on_receive_one_frame(struct SszCommFrame_t* frame,
                                              void* user_data, int8_t from_id,
                                              const uint8_t* recv_data,
                                              int16_t recv_size) {
	SszCommMsg* p = (SszCommMsg*)user_data;
	if (recv_size < 3) {
		return;
	}
	SszCommMsgFromInfo from;
	from.from_id = from_id;
	from.from_msg_sequence = recv_data[0];
	memcpy(&from.from_msg_id, recv_data + 1, 2);
	if (p->recv_handler) {
		p->recv_handler(p, &from, recv_data + 3, recv_size - 3);
	}
}

// data_cache_at_frame: this will save the data at the frame
// data_cache_max_size: this define the frame's data size which can take
void ssz_comm_msg_init(SszCommMsg* comm_msg, void* user_data,
                       SszCommMsgReceiveHandler recv_handler,
                       SszFile* send_file, void* data_cache_at_frame,
                       int16_t data_cache_max_size,
                       bool is_have_src_and_dest_id, int8_t self_id) {
	ssz_comm_frame_init(&comm_msg->frame, comm_msg,
	                    ssz_comm_msg_on_receive_one_frame, send_file,
	                    data_cache_at_frame, data_cache_max_size, 1000,
	                    is_have_src_and_dest_id, self_id);
	comm_msg->user_data = user_data;
	comm_msg->recv_handler = recv_handler;
	comm_msg->msg_send_sequence = 0;
	// check if we can alloc this size tmp buff
	ssz_tmp_buff_check_size(kSszTempAllocCommonBuff, data_cache_max_size);
}

// set dest id
void ssz_comm_msg_set_destination(SszCommMsg* comm_msg, int8_t dest_id) {
	ssz_comm_frame_set_destination(&comm_msg->frame, dest_id);
}

bool ssz_comm_msg_send_ex(SszCommMsg* comm_msg, int8_t dest_id, uint16_t msg_id,
                          const void* msg_data, int msg_data_size,
                          uint8_t send_sequence) {
	uint8_t* p = ssz_tmp_buff_alloc(kSszTempAllocCommonBuff, msg_data_size + 3);
	p[0] = send_sequence;
	memcpy(p + 1, &msg_id, 2);
	memcpy(p + 3, msg_data, msg_data_size);
	ssz_comm_frame_send_to(&comm_msg->frame, dest_id, p, msg_data_size + 3);
	ssz_tmp_buff_free(p);
	return true;
}

// send buff to dest
bool ssz_comm_msg_send(SszCommMsg* comm_msg, uint16_t msg_id,
                       const void* msg_data, int msg_data_size,
                       uint8_t* return_send_sequence) {
	comm_msg->msg_send_sequence++;
	if (return_send_sequence) {
		*return_send_sequence = comm_msg->msg_send_sequence;
	}
	return ssz_comm_msg_send_ex(comm_msg, comm_msg->frame.dest_id, msg_id,
	                            msg_data, msg_data_size,
	                            comm_msg->msg_send_sequence);
}

bool ssz_comm_msg_send_respond(SszCommMsg* comm_msg, SszCommMsgFromInfo* from,
                               const void* msg_data, int msg_data_size) {
	return ssz_comm_msg_send_ex(comm_msg, from->from_id,
	                            from->from_msg_id | 0x8000, msg_data,
	                            msg_data_size, from->from_msg_sequence);
}

// handle new receive byte, return true if it is a part of frame
bool ssz_comm_msg_on_receive_new_byte(SszCommMsg* comm_msg, uint8_t ch) {
	return ssz_comm_frame_on_receive_new_byte(&comm_msg->frame, ch);
}

//can be used like encrypt or decode
//Note: it will convert the frame data
//e.g. recv one frame->decode->one comm msg
//	   send one comm msg->encry->one frame
void ssz_comm_msg_set_convert_handler(SszCommMsg* comm_msg,
	SszCommFrameDataConvertHandler convert_handler,
	SszCommFrameDataConvertAfterHandler convert_after_handler) {

	ssz_comm_frame_set_convert_handler(&comm_msg->frame, convert_handler,
		convert_after_handler);
}