/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "app_peer_comm_msg_handle.h"
#include "config.h"
#include "ssz_comm_msg.h"
#include "comm.h"
#include "drv_peer_comm_msg.h"
#include "ssz_common.h"

#if PEER_COMM_MSG_MODULE_ENABLE

/************************************************
* Declaration
************************************************/

/************************************************
* Variable 
************************************************/

/************************************************
* Function 
************************************************/

PeerCommMsgAckCode app_peer_comm_msg_on_query_version(SszCommMsg *comm_msg,
                                                      SszCommMsgFromInfo *from,
                                                      const uint8_t *msg_data,
                                                      int16_t msg_data_size) {
	char ver[28];
	snprintf(ver, sizeof(ver), "%s", "InsulinPumpV2_0_slaver");
	peer_comm_msg_send_respond(from, ver, strlen(ver));
	return kPeerCommMsgAckSuccess;
}
// add other
PeerCommMsgAckCode app_peer_comm_msg_on_init(SszCommMsg *comm_msg, SszCommMsgFromInfo *from, const uint8_t *msg_data, int16_t msg_data_size)
{
	
	return kPeerCommMsgAckSuccess;
}

PeerCommMsgAckCode app_peer_comm_msg_on_open_ble(SszCommMsg *comm_msg, SszCommMsgFromInfo *from, const uint8_t *msg_data, int16_t msg_data_size)
{
	
	return kPeerCommMsgAckSuccess;
}

// all msg handlers
const static PeerCommMsgHanlderInfo g_peer_comm_msg_handlers[] = {
    {app_peer_comm_msg_on_query_version, 0, kPeerCommMsgStartMotor},
    // add other
    {app_peer_comm_msg_on_init, 0, kPeerCommMsgInit},
    {app_peer_comm_msg_on_open_ble, 0, kPeerCommMsgOpenBLE},
};


// handle msg, return the ack code
PeerCommMsgAckCode app_peer_comm_msg_handle(SszCommMsg *comm_msg,
                                            SszCommMsgFromInfo *from,
                                            const uint8_t *msg_data,
                                            int16_t msg_data_size) {
	int i;
	PeerCommMsgAckCode ack_code = kPeerCommMsgAckUnknownMsg;
	// find the msg handler
	for (i = 0; i < ssz_array_size(g_peer_comm_msg_handlers); i++) {
		if (g_peer_comm_msg_handlers[i].msg == from->from_msg_id) {
			if (msg_data_size >=
			    g_peer_comm_msg_handlers[i].msg_data_min_size) {
				ack_code = g_peer_comm_msg_handlers[i].handler(
				    comm_msg, from, msg_data, msg_data_size);
			} else {
				ack_code = kPeerCommMsgAckMsgParamWrong;
			}
			break;
		}
	}

	return ack_code;
}



void app_peer_comm_msg_handle_init() {
	peer_comm_msg_set_handler_for_all_msg(app_peer_comm_msg_handle);
}


#endif

