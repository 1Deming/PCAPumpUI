#pragma once
#include "ssz_def.h"
#include "config.h"
/************************************************
 * Declaration
 ************************************************/

// the max size of send msg queue can save to wait the respond
#define PEER_COMM_MSG_MAX_SIZE_OF_SENT_MSG 30
// the max data size to send if need resend
#define PEER_COMM_MS_MAX_DATA_SIZE_WHEN_NEED_RESEND 32

// all support msg
typedef enum {
	kPeerCommMsgInit =0 ,
		
	kPeerCommMsgGetVersion = 0x200,
	kPeerCommMsgGetSystemState= 0x201,
	
	kPeerCommMsgStartWatchdog= 0x300,
	kPeerCommMsgStopWatchdog= 0x301,
	kPeerCommMsgClearWatchdog= 0x302,
	
	kPeerCommMsgStartMotor= 0x400,
	kPeerCommMsgStopMotor= 0x401,
	kPeerCommMsgGetMotorState= 0x402,
	kPeerCommMsgMotorStopNotify= 0x403,

	kPeerCommMsgSleep= 0x500,
	
	kPeerCommMsgOpenBLE= 0x600,
	kPeerCommMsgBLEConnectedNotify= 0x601,
	kPeerCommMsgBLEDisconnectedNotify= 0x602,
	kPeerCommMsgDisconnectBLE= 0x603,
	kPeerCommMsgEnableEncryption= 0x604,
	kPeerCommMsgBLEReceiveDataNotify= 0x605,
	kPeerCommMsgSendDataByBLE= 0x606,
	kPeerCommMsgSendDebugDataByBLE= 0x607,
	
} PeerCommMsgID;
