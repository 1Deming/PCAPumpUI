/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "drv_peer_comm_msg.h"
#include "ssz_comm_msg.h"
#include "comm.h"
#include "ssz_list.h"
#include "timer.h"
#include "timer_config.h"

/************************************************
* Declaration
************************************************/
// each time to check if the respond time is too long
#define PEER_COMM_MSG_RESPOND_CHEKC_TIME_MS 10
// the max time to wait the respond, if arrived, we think the request is fail
#define PEER_COMM_MSG_RESPOND_FAIL_TIME_MS 500

typedef struct {
	SSZ_LIST_NODE_BASE_DEFINE;
	uint8_t msg_data[PEER_COMM_MS_MAX_DATA_SIZE_WHEN_NEED_RESEND];
	uint32_t send_tick_time;
	PeerCommMsgRespondHandler respond_handler;
	int msg_data_size;
	uint16_t msg_id;
	uint8_t msg_sequence;
	bool is_enable_retry;
} PeerCommMsgSentInfo;

typedef struct {
	SSZ_LIST_NODE_BASE_DEFINE;
	PeerCommMsgSentInfo sent_info;
} PeerCommMsgSentListNode;

SszResult peer_comm_msg_send_internal(PeerCommMsgID msg_id,
                                      const void *msg_data, int msg_data_size,
                                      PeerCommMsgRespondHandler respond_handler,
                                      bool is_need_retry);

/************************************************
* Variable 
************************************************/
static uint8_t g_peer_comm_msg_data_cache[250];
static SszCommMsg g_peer_comm_msg;

static SszList g_peer_comm_msg_sent_list;
static PeerCommMsgSentListNode g_peer_comm_msg_sent_nodes[PEER_COMM_MSG_MAX_SIZE_OF_SENT_MSG];

static PeerCommMsgHandler g_peer_comm_msg_handler = NULL;
static PeerCommMsgRespondHandler g_peer_comm_msg_respond_handler = NULL;
static PeerCommMsgIDtoStrHandler g_peer_comm_msg_id_to_str_handler = NULL;

static bool g_peer_comm_msg_is_resending = false;

/************************************************
 * Function
 ************************************************/

void peer_comm_msg_handle_respond(SszCommMsg *comm_msg,
                                  SszCommMsgFromInfo *from,
                                  const uint8_t *msg_data,
                                  int16_t msg_data_size) {
	int pos;
	PeerCommMsgSentInfo *p_send;
	bool is_find_related_send_msg = false;
	// check each sent msg
	for (pos = ssz_list_begin(&g_peer_comm_msg_sent_list); pos != -1;
	     pos = ssz_list_next(&g_peer_comm_msg_sent_list, pos)) {
		p_send = (PeerCommMsgSentInfo *)ssz_list_at_pos(
		    &g_peer_comm_msg_sent_list, pos);
		// if find the msg, call respond and delete it
		if (p_send->msg_id == (from->from_msg_id & 0x7FFF) &&
		    p_send->msg_sequence == from->from_msg_sequence) {
			if (p_send->respond_handler) {
				// call handler
				p_send->respond_handler(comm_msg, kSszSuccess, from, msg_data,
				                        msg_data_size);
			}
			is_find_related_send_msg = true;
			ssz_list_erase(&g_peer_comm_msg_sent_list, pos);
			break;
		}
	}

	if (g_peer_comm_msg_respond_handler) {
		if (is_find_related_send_msg) {
			g_peer_comm_msg_respond_handler(comm_msg, kSszSuccess, from,
			                                msg_data, msg_data_size);
		} else {
			g_peer_comm_msg_respond_handler(comm_msg, kSszNotExist, from,
			                                msg_data, msg_data_size);
		}
	}
}

// handle new msg
static void peer_comm_msg_on_receive(struct SszCommMsg_t *comm_msg,
                                     SszCommMsgFromInfo *from,
                                     const uint8_t *msg_data,
                                     int16_t msg_data_size) {
	if (from->from_msg_id < 0x8000) {
		if (g_peer_comm_msg_handler) {
			PeerCommMsgAckCode ack_code = kPeerCommMsgAckUnknownMsg;
			// handle the msg
			ack_code = g_peer_comm_msg_handler(comm_msg, from, msg_data,
			                                   msg_data_size);

			// if need ack, send ack code
			if (ack_code != kPeerCommMsgAckNull) {
				peer_comm_msg_send_respond(from, &ack_code, 1);
			}
		}
	} else {
		peer_comm_msg_handle_respond(comm_msg, from, msg_data, msg_data_size);
	}
}


// handle new byte, let com msg to handle it
static bool peer_comm_msg_on_receive_new_byte(
    CommID comm_id, uint8_t ch, bool is_handled_ok_at_pre_handler) {
	if (!is_handled_ok_at_pre_handler &&
	    ssz_comm_msg_on_receive_new_byte(&g_peer_comm_msg, ch)) {
		return true;
	}
	return false;
}

static void peer_comm_msg_respond_check(void) {
	int pos;
	int next_pos;

	PeerCommMsgSentInfo *p_send;
	
	// check each sent msg
	for (pos = ssz_list_begin(&g_peer_comm_msg_sent_list); pos != -1;) {
		next_pos = ssz_list_next(&g_peer_comm_msg_sent_list, pos);
		p_send = (PeerCommMsgSentInfo *)ssz_list_at_pos(
		    &g_peer_comm_msg_sent_list, pos);
		// if the msg is arrive the max respond time, we think it is fail,
		//   need resend or call fail handler
		if (ssz_tick_time_elapsed(p_send->send_tick_time) >
		    PEER_COMM_MSG_RESPOND_FAIL_TIME_MS) {
			if (p_send->is_enable_retry) {
				PeerCommMsgSentInfo send_info;
				memcpy(&send_info, p_send, sizeof(send_info));
				ssz_list_erase(&g_peer_comm_msg_sent_list, pos);
				// resend
				g_peer_comm_msg_is_resending = true;
				peer_comm_msg_send_internal(
				    (PeerCommMsgID)send_info.msg_id, send_info.msg_data,
				    send_info.msg_data_size, send_info.respond_handler, false);
				g_peer_comm_msg_is_resending = false;

			} else if (p_send->respond_handler) {
				// call fail handler
				p_send->respond_handler(&g_peer_comm_msg, kSszTimeout, NULL,
				                        NULL, 0);
				ssz_list_erase(&g_peer_comm_msg_sent_list, pos);
			}
		}
		pos = next_pos;
	}

	// if no one restart the timer, we need check if need restart it
	if (!timer_is_actived(kTimerPeerCommMsgRespondCheck)) {
		// if there is exist send buffer, need restart timer to check continue
		if (ssz_list_size(&g_peer_comm_msg_sent_list) > 0) {
			timer_start_oneshot_after(kTimerPeerCommMsgRespondCheck,
			                          PEER_COMM_MSG_RESPOND_CHEKC_TIME_MS);
		}
	}
}

void peer_comm_msg_init(CommID comm_id, CommHandleOrder order) {
	ssz_comm_msg_init(&g_peer_comm_msg, NULL, peer_comm_msg_on_receive,
	                  comm_to_file(comm_id), g_peer_comm_msg_data_cache,
	                  sizeof(g_peer_comm_msg_data_cache), false, 0);
	comm_set_byte_receive_handler(comm_id, order,
	                              peer_comm_msg_on_receive_new_byte);
	ssz_list_init(&g_peer_comm_msg_sent_list,
	              (SszListNode *)g_peer_comm_msg_sent_nodes,
	              ssz_array_size(g_peer_comm_msg_sent_nodes),
	              ssz_array_node_size(g_peer_comm_msg_sent_nodes));
	timer_set_handler(kTimerPeerCommMsgRespondCheck,
	                  peer_comm_msg_respond_check);
}


SszResult peer_comm_msg_send_internal(PeerCommMsgID msg_id,
                                      const void *msg_data, int msg_data_size,
                                      PeerCommMsgRespondHandler respond_handler,
                                      bool is_need_retry) {
	
	uint8_t send_sequence;
	if (ssz_comm_msg_send(&g_peer_comm_msg, msg_id, msg_data, msg_data_size,
	                      &send_sequence)) {
		if (respond_handler || is_need_retry) {
			PeerCommMsgSentInfo sent_info;
			ssz_mem_zero(&sent_info, sizeof(sent_info));
			sent_info.msg_id = msg_id;
			sent_info.msg_sequence = send_sequence;
			sent_info.send_tick_time = ssz_tick_time_now();
			sent_info.respond_handler = respond_handler;
			if (is_need_retry) {
				ssz_assert(msg_data_size <=
				           PEER_COMM_MS_MAX_DATA_SIZE_WHEN_NEED_RESEND);
				sent_info.msg_data_size = msg_data_size;
				memcpy(sent_info.msg_data, msg_data, msg_data_size);
			}
			if (ssz_list_push_back(&g_peer_comm_msg_sent_list, &sent_info)) {
				if (!timer_is_actived(kTimerPeerCommMsgRespondCheck)) {
					timer_start_oneshot_after(
					    kTimerPeerCommMsgRespondCheck,
					    PEER_COMM_MSG_RESPOND_CHEKC_TIME_MS);
				}
				return kSszSuccess;
			} else {
				return kSszNoEnoughResource;
			}
		} else {
			return kSszSuccess;
		}
	} else {
		return kSszError;
	}
}


SszResult peer_comm_msg_send(PeerCommMsgID msg_id, const void *msg_data,
                             int msg_data_size,
                             PeerCommMsgRespondHandler respond_handler) {
	return peer_comm_msg_send_internal(msg_id, msg_data, msg_data_size,
	                                   respond_handler, false);
}

SszResult peer_comm_msg_send_with_retry(
    PeerCommMsgID msg_id, const void *msg_data, int msg_data_size,
    PeerCommMsgRespondHandler respond_handler) {
	return peer_comm_msg_send_internal(msg_id, msg_data, msg_data_size,
	                                   respond_handler, true);
}

SszResult peer_comm_msg_send_respond(SszCommMsgFromInfo *from,
                                     const void *msg_data, int msg_data_size) {
	return ssz_comm_msg_send_respond(&g_peer_comm_msg, from, msg_data,
	                                 msg_data_size)
	           ? kSszSuccess
	           : kSszError;
}


SszResult peer_comm_msg_send_notify(PeerCommMsgID msg_id, const void *msg_data,
                                    int msg_data_size) {
	return peer_comm_msg_send_internal(msg_id, msg_data, msg_data_size, NULL,
	                                   false);
}

void peer_comm_msg_set_handler_for_all_msg(PeerCommMsgHandler handler) {
	g_peer_comm_msg_handler = handler;
}

// callback result: kSszSuccess,kSszNotExist(not find the related send msg)
void peer_comm_msg_set_respond_handler_for_all_msg(
    PeerCommMsgRespondHandler handler) {
	g_peer_comm_msg_respond_handler = handler;
}

void peer_comm_msg_set_msg_id_to_str_handler(
    PeerCommMsgIDtoStrHandler handler) {
	g_peer_comm_msg_id_to_str_handler = handler;
}
	
SszCommMsg *peer_comm_msg() {
	return &g_peer_comm_msg;
}






