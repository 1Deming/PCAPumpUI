/************************************************
 * DESCRIPTION:
 *   used to handle communication
 *
 ************************************************/
#include "comm.h"
#include "ssz_common.h"

/************************************************
 * Declaration
 ************************************************/
typedef struct {
	SszFile* file;
	union {
		CommByteReceiveHandler byte_receive_handler[kCommHandleMax];
		CommBuffReceiveHandler buff_receive_handler[kCommHandleMax];
	};
	bool is_use_buff_receive_handler;
} CommInfo;

/************************************************
 * Variable
 ************************************************/
static CommInfo g_comm_info[kCommmIDMax];

/************************************************
 * Function
 ************************************************/

/***********************************************
 * Description:
 *   handle new received data
 * Argument:
 *
 * Return:
 *
 ************************************************/
void comm_handle_new_received_data(CommID comm_id) {
	int buff_size = ssz_fsize(g_comm_info[comm_id].file);
	if (buff_size > 0) {
		bool ret;
		if (g_comm_info[comm_id].is_use_buff_receive_handler) {
			ret = comm_handle_new_buff(
			    comm_id, ssz_fget_data_pointer(g_comm_info[comm_id].file),
			    buff_size);
			if (ret == false) {
				ssz_traceln("com %d receive unknow buff[%d]\n", comm_id,
				            buff_size);
			}
			ssz_fskip_read(g_comm_info[comm_id].file, buff_size);
		} else {
			int i;

			uint8_t a;

			for (i = 0; i < buff_size; i++) {
				// get the receive byte
				a = (uint8_t)ssz_fgetc(g_comm_info[comm_id].file);
				ret = comm_handle_new_byte(comm_id, a);
				if (ssz_fsize(g_comm_info[comm_id].file) == 0) {
					// the receive data is clear by a com handle, so stop handle
					break;
				}

				if (ret == false) {
					ssz_traceln("com %d receive unknow byte[%x]\n", comm_id, a);
				}
			}
		}
	}
}

// handle one new received byte, return true if someone handled it
bool comm_handle_new_byte(CommID comm_id, uint8_t ch) {
	int j;
	bool ret = false;

	for (j = 0; j < kCommHandleMax; j++) {
		// let each handler to handle it
		if (g_comm_info[comm_id].byte_receive_handler[j]) {
			if (ret == false) {
				// previous handler not know it and not handle it
				ret = g_comm_info[comm_id].byte_receive_handler[j](comm_id, ch,
				                                                   false);
			} else {
				// previous handler already know it and handle it
				g_comm_info[comm_id].byte_receive_handler[j](comm_id, ch, true);
			}
		}
	}

	return ret;
}
// handle one new received bytes, return true if someone handled it
bool comm_handle_new_buff(CommID comm_id, const void* buff, int buff_size) {
	int j;
	bool ret = false;

	for (j = 0; j < kCommHandleMax; j++) {
		// let each handler to handle it
		if (g_comm_info[comm_id].buff_receive_handler[j]) {
			if (ret == false) {
				// previous handler not know it and not handle it
				ret = g_comm_info[comm_id].buff_receive_handler[j](
				    comm_id, buff, buff_size, false);
			} else {
				// previous handler already know it and handle it
				g_comm_info[comm_id].buff_receive_handler[j](comm_id, buff,
				                                             buff_size, true);
			}
		}
	}

	return ret;
}

/***********************************************
 * Description:
 *   bind receive handler
 * Argument:
 *   order:
 *   handler:
 *
 * Return:
 *
 ************************************************/
void comm_set_byte_receive_handler(CommID comm_id, CommHandleOrder order,
                                   CommByteReceiveHandler handler) {
	ssz_assert(order < kCommHandleMax);
	g_comm_info[comm_id].byte_receive_handler[order] = handler;
	g_comm_info[comm_id].is_use_buff_receive_handler = false;
}
void comm_set_buff_receive_handler(CommID comm_id, CommHandleOrder order,
                                   CommBuffReceiveHandler handler) {
	ssz_assert(order < kCommHandleMax);
	g_comm_info[comm_id].buff_receive_handler[order] = handler;
	g_comm_info[comm_id].is_use_buff_receive_handler = true;
}
void comm_clear_all_handler() {
	for (int i = 0; i < ssz_array_size(g_comm_info); i++) {
		ssz_mem_zero(g_comm_info[i].buff_receive_handler,
			sizeof(g_comm_info[i].buff_receive_handler));
	}
}
SszFile* comm_to_file(CommID comm_id) {
	return g_comm_info[comm_id].file;
}
CommID comm_id_from_file(SszFile* file) {
	for (int j = 0; j < kCommHandleMax; j++) {
		if (g_comm_info[j].file == file) {
			return (CommID)j;
		}
	}
	return kCommmIDMax;
}
void comm_set_file(CommID comm_id, SszFile* file) {
	g_comm_info[comm_id].file = file;
}