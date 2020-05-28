/************************************************
 * DESCRIPTION:
 *
 ************************************************/
#include "ssz_comm_frame.h"
#include "ssz_common.h"
#include "ssz_algorithm.h"
#include "ssz_tick_time.h"

/************************************************
 * Declaration
 ************************************************/

/************************************************
 * Variable
 ************************************************/

/************************************************
 * Function
 ************************************************/

void ssz_comm_frame_init(SszCommFrame* frame, void* user_data,
                         SszCommFrameReceiveHandler recv_handler,
                         SszFile* send_file, void* data_cache_at_frame,
                         int16_t data_cache_max_size,
                         int16_t time_out_to_wait_next_byte_at_frame_parse,
                         bool is_have_src_and_dest_id, int8_t self_id) {
	ssz_mem_zero(frame, sizeof(*frame));
	frame->my_id = self_id;
	frame->is_have_src_and_dest_id = is_have_src_and_dest_id;
	frame->frame_start_sign1 = SSZ_DEFAULT_FRAME_START_SIGN1;
	frame->frame_start_sign2 = SSZ_DEFAULT_FRAME_START_SIGN2;
	frame->recv_handler = recv_handler;
	frame->user_data = user_data;
	frame->send_file = send_file;
	frame->data_cache = data_cache_at_frame;
	frame->data_cache_max_len = data_cache_max_size;
	frame->max_wait_time_ms = time_out_to_wait_next_byte_at_frame_parse;
	frame->one_frame.data = data_cache_at_frame;
}

void ssz_comm_frame_set_destination(SszCommFrame* frame, int8_t dest_id) {
	frame->dest_id = dest_id;
}

uint32_t ssz_comm_frame_calc_one_frame_checksum(SszOneFrame* one_frame,
                                                bool is_have_src_and_dest_id) {
	uint32_t crc32 = SSZ_CRC32_SEED;
	const uint8_t* p = (uint8_t*)one_frame;

	// calc the frame before data's crc32
	// calc sign
	crc32 = ssz_crc32_ex(p, 2, crc32);
	// calc device id
	if (is_have_src_and_dest_id) {
		crc32 = ssz_crc32_ex(p + 2, 2, crc32);
	}
	// calc data len
	crc32 = ssz_crc32_ex(p + 4, 2, crc32);
	// calc the data's crc32
	crc32 = ssz_crc32_ex(one_frame->data, one_frame->data_len, crc32);

	return crc32 ^ SSZ_CRC32_SEED;
}
bool ssz_comm_frame_send(SszCommFrame* frame, const void* buff, int buff_size) {
	return ssz_comm_frame_send_to(frame, frame->dest_id, buff, buff_size);
}

bool ssz_comm_frame_send_to(SszCommFrame* frame, int8_t dest_id,
                            const void* buff, int buff_size) {
	SszOneFrame one_frame;
	uint8_t* new_buff = (uint8_t*)buff;
	int16_t new_buff_size = buff_size;
	bool is_need_call_convert_after = false;

	if (frame->convert_handler) {
		new_buff = frame->convert_handler(true, buff, buff_size, &new_buff_size);
		if (new_buff==NULL) {
			return false;
		}
		is_need_call_convert_after = true;
	}

	one_frame.frame_start_sign1 = frame->frame_start_sign1;
	one_frame.frame_start_sign2 = frame->frame_start_sign2;
	one_frame.src_id = frame->my_id;
	one_frame.dest_id = dest_id;
	one_frame.data_len = new_buff_size;
	one_frame.data = new_buff;
	// calc the frame 's crc32
	uint32_t crc32 = ssz_comm_frame_calc_one_frame_checksum(
	    &one_frame, frame->is_have_src_and_dest_id);

	const uint8_t* p = (uint8_t*)&one_frame;
	// send frame head
	ssz_fwrite(frame->send_file, p, 2);
	if (frame->is_have_src_and_dest_id) {
		ssz_fwrite(frame->send_file, p + 2, 2);
	}
	ssz_fwrite(frame->send_file, p + 4, 2);
	// send frame data
	ssz_fwrite(frame->send_file, one_frame.data, one_frame.data_len);
	// send frame checksum
	ssz_fwrite(frame->send_file, &crc32, sizeof(crc32));
	if (is_need_call_convert_after && frame->convert_after_handler) {
		frame->convert_after_handler(new_buff, new_buff_size);
	}
	return true;
}

bool ssz_comm_frame_on_receive_new_byte(SszCommFrame* frame, uint8_t ch) {
	bool is_handle_ok = true;

	frame->curr_parse_num++;

	// check if time out
	if (frame->curr_parse_num != 1 && frame->max_wait_time_ms != -1) {
		if (ssz_tick_time_elapsed(frame->last_recv_time) >frame->max_wait_time_ms) {
			// time out, reset as first byte
			frame->curr_parse_num = 1;
		}
	}

	frame->last_recv_time = ssz_tick_time_now();

	// check if received data is a frame's header, if it is not,
	//  reset curr_parse_num
	if (frame->curr_parse_num == 1)  // first sign byte:
	{
		if (ch != frame->frame_start_sign1) {
			// not match, reset
			frame->curr_parse_num = 0;
			is_handle_ok = false;
		}
	} else if (frame->curr_parse_num == 2)  // second sign byte:
	{
		if (ch != frame->frame_start_sign2) {
			// not match second, check if match first
			if (ch == frame->frame_start_sign1) {
				// match first
				frame->curr_parse_num = 1;
			} else {
				// not match first and second, reset
				frame->curr_parse_num = 0;
				is_handle_ok = false;
			}
		}
	} else {
		int head_num = 4;
		if (frame->is_have_src_and_dest_id) {
			head_num = 6;
		}
		if (frame->curr_parse_num <= head_num)  // head
		{
			// save the head
			((uint8_t*)&frame->one_frame)[frame->curr_parse_num - 1] = ch;
			if (frame->curr_parse_num == head_num) {  // it is the data len
				if (!frame->is_have_src_and_dest_id) {
					// the data len is at the src and dest id,
					// so copy to data len
					memcpy(&frame->one_frame.data_len, &frame->one_frame.src_id,
					       2);  //lint !e420
					frame->one_frame.src_id = 0;
				}
				// check the data len
				if (frame->one_frame.data_len > frame->data_cache_max_len) {
					// the data len is too long
					frame->curr_parse_num = 0;
					is_handle_ok = false;
				}
			}
		} else if (frame->curr_parse_num <=
		           head_num + frame->one_frame.data_len)  // data
		{
			// save data
			frame->one_frame.data[frame->curr_parse_num - 1 - head_num] = ch;
		} else {  // checksum
			int checksum_index = frame->curr_parse_num - 1 - head_num -
			                     frame->one_frame.data_len;
			// save checksum
			((uint8_t*)&(frame->one_frame.checksum))[checksum_index] = ch;

			if (checksum_index == 3) {
				// reset parse
				frame->curr_parse_num = 0;

				// verify the frame
				frame->one_frame.frame_start_sign1 = frame->frame_start_sign1;
				frame->one_frame.frame_start_sign2 = frame->frame_start_sign2;
				uint32_t checksum = ssz_comm_frame_calc_one_frame_checksum(
				    &frame->one_frame, frame->is_have_src_and_dest_id);
				if (checksum == frame->one_frame.checksum) {
					if (!frame->is_have_src_and_dest_id ||
					    (frame->is_have_src_and_dest_id &&
					     frame->one_frame.dest_id == frame->my_id)) {
						// the frame is right, call handler
						if (frame->recv_handler) 
						{
							uint8_t* data_p = frame->one_frame.data;
							int16_t data_len = frame->one_frame.data_len;
							bool is_need_call_convert_after = false;
							if (frame->convert_handler) {
								data_p = frame->convert_handler(false, frame->one_frame.data,
									frame->one_frame.data_len, &data_len);
								if (data_p) {
									is_need_call_convert_after = true;
								}
							}
							if (data_p) {
								frame->recv_handler(frame, frame->user_data,
									frame->one_frame.src_id,
									frame->one_frame.data,
									frame->one_frame.data_len);
							}
							if (is_need_call_convert_after && frame->convert_after_handler) {
								frame->convert_after_handler(data_p, data_len);
							}
						}
					}
				}
			}
		}
	}
	return is_handle_ok;
}

//can be used like encrypt or decode
void ssz_comm_frame_set_convert_handler(SszCommFrame* frame,
	SszCommFrameDataConvertHandler convert_handler,
	SszCommFrameDataConvertAfterHandler convert_after_handler) {
	frame->convert_handler = convert_handler;
	frame->convert_after_handler = convert_after_handler;
}