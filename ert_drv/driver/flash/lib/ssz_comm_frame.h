/************************************************
 * DESCRIPTION:
 *
 ************************************************/
#pragma once
#include "ssz_def.h"
#include "ssz_file.h"

/************************************************
 * Declaration
 ************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#define SSZ_DEFAULT_FRAME_START_SIGN1 0x55
#define SSZ_DEFAULT_FRAME_START_SIGN2 0xAA
struct SszCommFrame_t;
typedef void (*SszCommFrameReceiveHandler)(struct SszCommFrame_t* frame,
                                           void* user_data, int8_t from_id,
                                           const uint8_t* recv_data,
                                           int16_t recv_size);

//return converted data and data size(dest_data_size), used to encry or decode data
//if return NULL, the data will stop hanle.
typedef uint8_t* (*SszCommFrameDataConvertHandler)(bool is_send, const uint8_t* data,
                                           int16_t data_size,
										   int16_t* dest_data_size);
//the converted data is used finish, call it to let user can handle the converted data. e.g. delete it
typedef void (*SszCommFrameDataConvertAfterHandler)(uint8_t* data,
                                           int16_t data_size);

typedef struct {
	uint8_t frame_start_sign1;
	uint8_t frame_start_sign2;
	int8_t src_id;
	int8_t dest_id;
	int16_t data_len;
	uint8_t* data;
	uint32_t checksum;
} SszOneFrame;

typedef struct SszCommFrame_t {
	uint8_t* data_cache;  // save receive data
	SszCommFrameReceiveHandler recv_handler;
	void* user_data;
	SszFile* send_file;
	int32_t last_recv_time;  // when call on receive new byte, update it
	SszOneFrame one_frame;   // used to save receive data
	SszCommFrameDataConvertHandler convert_handler;
	SszCommFrameDataConvertAfterHandler convert_after_handler;
	int16_t data_cache_max_len;
	// current parse number of one frame, 1 is first byte at frame
	int16_t curr_parse_num;
	// the max time to wait next byte when parse frame
	int16_t max_wait_time_ms;
	int8_t my_id;                  // my device id
	int8_t dest_id;                // destination device id
	uint8_t frame_start_sign1;     // frame sign, default is 0x55
	uint8_t frame_start_sign2;     // frame sign, default is 0xAA
	bool is_have_src_and_dest_id;  // is have src_id and dest_id at one frame
} SszCommFrame;

// user_data: will pass to recv handler
// data_cache_at_frame: this will save the data at the frame
// data_cache_max_size: this define the frame's data size which can take
// time_out_to_wait_next_byte_at_frame_parse:
//		the max time to wait next byte, unit:ms
// is_have_src_and_dest_id: is have src_id and dest_id at one frame
// self_id: my device id to communicate, valid only when
//      is_have_src_and_dest_id=true
void ssz_comm_frame_init(SszCommFrame* frame, void* user_data,
                         SszCommFrameReceiveHandler recv_handler,
                         SszFile* send_file, void* data_cache_at_frame,
                         int16_t data_cache_max_size,
                         int16_t time_out_to_wait_next_byte_at_frame_parse,
                         bool is_have_src_and_dest_id, int8_t self_id);

// set dest id
void ssz_comm_frame_set_destination(SszCommFrame* frame, int8_t dest_id);

// send buff to dest
bool ssz_comm_frame_send(SszCommFrame* frame, const void* buff, int buff_size);

// send buff to specify dest(if is_have_src_and_dest_id is false,
//  the dest_id is no affect)
bool ssz_comm_frame_send_to(SszCommFrame* frame, int8_t dest_id,
                            const void* buff, int buff_size);

// handle new receive byte, return true if it is a part of frame
bool ssz_comm_frame_on_receive_new_byte(SszCommFrame* frame, uint8_t ch);

//can be used like encrypt or decode
void ssz_comm_frame_set_convert_handler(SszCommFrame* frame,
	SszCommFrameDataConvertHandler convert_handler,
	SszCommFrameDataConvertAfterHandler convert_after_handler);

#ifdef __cplusplus
}
#endif
