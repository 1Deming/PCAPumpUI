/************************************************
 * DESCRIPTION:
 *   used to handle communication
 *
 ************************************************/
#pragma once
#include "comm_config.h"
#include "ssz_def.h"
#include "ssz_file.h"

/************************************************
 * Declaration
 ************************************************/

#ifdef __cplusplus
extern "C" {
#endif

// ch is the received byte
typedef bool (*CommByteReceiveHandler)(CommID comm_id, uint8_t ch,
                                       bool is_handled_ok_at_pre_handler);
// buff is the received buff
typedef bool (*CommBuffReceiveHandler)(CommID comm_id, const uint8_t* buff,
                                       int buff_size,
                                       bool is_handled_ok_at_pre_handler);

// handle new received data
void comm_handle_new_received_data(CommID comm_id);
// handle one new received byte, return true if someone handled it
bool comm_handle_new_byte(CommID comm_id, uint8_t ch);
// handle one new received bytes, return true if someone handled it
bool comm_handle_new_buff(CommID comm_id, const void* buff, int buff_size);

// bind receive handler
void comm_set_byte_receive_handler(CommID comm_id, CommHandleOrder order,
                                   CommByteReceiveHandler handler);
void comm_set_buff_receive_handler(CommID comm_id, CommHandleOrder order,
                                   CommBuffReceiveHandler handler);
void comm_clear_all_handler();

SszFile* comm_to_file(CommID comm_id);
CommID comm_id_from_file(SszFile* file);

// bind file to comm
void comm_set_file(CommID comm_id, SszFile* file);

#ifdef __cplusplus
}
#endif
