/************************************************
 * DESCRIPTION:
 *
 *
 ************************************************/
#pragma once

#include "ssz_def.h"
#include "comm_config.h"
#include "ssz_file.h"
#include "event.h"

/************************************************
 * Declaration
 ************************************************/

#ifdef __cplusplus
extern "C" {
#endif

typedef bool (*DrvCommSendHandler)(void* obj, const void* buff, int buff_size);

// usually called at interrupt handler
void drv_comm_on_receive_one_byte(CommID comm_id, unsigned char ch);
void drv_comm_on_receive_buff(CommID comm_id, const void* buff, int buff_size);

// return ssz file
SszFile* drv_comm_file(CommID comm_id);

void drv_comm_clear_recv_cache(CommID comm_id);

void drv_comm_init(CommID comm_id, EventID recv_event, bool is_recv_by_one_byte,
                   uint8_t* recv_buff, int recv_buff_size, void* object,
                   DrvCommSendHandler send_handler);

#ifdef __cplusplus
}
#endif
