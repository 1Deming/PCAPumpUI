/************************************************
 * DESCRIPTION:
 *
 *
 ************************************************/
#include "drv_comm.h"
#include "event.h"
#include "ssz_safe_queue.h"
#include "ssz_safe_buff.h"
#include "ssz_common.h"
#include "ssz_errorcode.h"
#ifdef SSZ_TARGET_MACHINE
#include "nrf_log.h"
#endif

/************************************************
 * Declaration
 ************************************************/
typedef struct {
	void* object;
	DrvCommSendHandler send_handler;
	union {
		SszSafeQueue recv_queue;
		SszSafeBuff recv_buff;
	};
	SszFile file;
	EventID recv_event;
	bool is_use_recv_queue;
} DrvCommInfo;

/************************************************
 * Variable
 ************************************************/
static DrvCommInfo g_drv_comm_info[kCommmIDMax] = {{0}};

/************************************************
 * Function
 ************************************************/
// usually called at interrupt handler
void drv_comm_on_receive_one_byte(CommID comm_id, unsigned char ch) {
	ssz_assert(g_drv_comm_info[comm_id].is_use_recv_queue);
	if (g_drv_comm_info[comm_id].is_use_recv_queue) {
		// push to recv queue
		if (!ssz_safe_queue_push_back(&g_drv_comm_info[comm_id].recv_queue,
		                              &ch)) {
	#ifdef SSZ_TARGET_MACHINE
			NRF_LOG_WARNING("com[%d] is full, ignore byte[%x]\n", comm_id, ch);
	#endif
		}
	} else {
		// push to recv buff
		if (!ssz_safe_buff_push_back_one_byte(
		        &g_drv_comm_info[comm_id].recv_buff, ch)) {
	#ifdef SSZ_TARGET_MACHINE		
			NRF_LOG_WARNING("com[%d] is full, ignore byte[%x]\n", comm_id, ch);
	#endif
		}
	}
	// set event
	event_set_quick(g_drv_comm_info[comm_id].recv_event);
}
void drv_comm_on_receive_buff(CommID comm_id, const void* buff, int buff_size) {
	ssz_assert(buff && buff_size > 0);
	if (g_drv_comm_info[comm_id].is_use_recv_queue) {
		// push to recv queue
		for (int i = 0; i < buff_size; i++) {
			if (!ssz_safe_queue_push_back(&g_drv_comm_info[comm_id].recv_queue,
			                              (const uint8_t*)buff + i)) {
#ifdef SSZ_TARGET_MACHINE
				NRF_LOG_WARNING("com[%d] is full, ignore buff[%d]\n", comm_id, buff_size-i);
#endif
				break;
			}
		}
	} else {
		// push to recv buff
		if (!ssz_safe_buff_push_back(&g_drv_comm_info[comm_id].recv_buff, buff,
		                             buff_size)) {
	#ifdef SSZ_TARGET_MACHINE		
			NRF_LOG_WARNING("com[%d] is full, ignore buff[%d]\n", comm_id, buff_size);
	#endif
		}
	}
	// set event
	event_set_quick(g_drv_comm_info[comm_id].recv_event);
}
// return ssz file
SszFile* drv_comm_file(CommID comm_id) {
	ssz_assert(comm_id < kCommmIDMax);
	if (g_drv_comm_info[comm_id].file.dev) {
		return &g_drv_comm_info[comm_id].file;
	} else {
		return NULL;
	}
}

void drv_comm_clear_recv_cache(CommID comm_id) {
	if (g_drv_comm_info[comm_id].is_use_recv_queue) {
		ssz_safe_queue_clear(&g_drv_comm_info[comm_id].recv_queue);
	} else {
		ssz_safe_buff_clear(&g_drv_comm_info[comm_id].recv_buff);
	}
}

static int drv_comm_file_read(struct ssz_file_t* file, void* buff,
                              int buff_size, int* real_read_buff_size) {
	DrvCommInfo* dev = file->dev_data;
	for (int i = 0; i < buff_size; i++) {
		// wait until not empty
		while (ssz_safe_queue_is_empty(&dev->recv_queue)) {
		};
		//lint -e{613}
		((uint8_t*)buff)[i] = *(uint8_t*)ssz_safe_queue_front(&dev->recv_queue);
		ssz_safe_queue_pop_front(&dev->recv_queue);
	}
	if (real_read_buff_size) *real_read_buff_size = buff_size;
	return kSszSuccess;
}
static int drv_comm_file_write(struct ssz_file_t* file, const void* buff,
                               int buff_size, int* real_write_buff_size) {
	DrvCommInfo* dev = file->dev_data;

	if (dev->send_handler && dev->send_handler(dev->object, buff, buff_size)) {
		if (real_write_buff_size) *real_write_buff_size = buff_size;
		return kSszSuccess;
	} else {
		if (real_write_buff_size) *real_write_buff_size = 0;
		return kSszError;
	}
}
static int drv_comm_file_ctl(struct ssz_file_t* file, int command,
                             void* param) {
	int ret = kSszSuccess;
	(void)param;
	DrvCommInfo* dev = file->dev_data;
	switch (command) {
		case SSZ_IOCTL_SIZE:
			if (dev->is_use_recv_queue) {
				(*(int32_t*)param) = ssz_safe_queue_size(&dev->recv_queue);
			} else {
				(*(int32_t*)param) = ssz_safe_buff_size(&dev->recv_buff);
			}
			break;
		case SSZ_IOCTL_SKIP_READ:
			if (dev->is_use_recv_queue) {
				ret = kSszNotSupport;
			} else {
				(*(int*)param) =
				    ssz_safe_buff_pop_font(&dev->recv_buff, (*(int*)param));
			}
			break;
		case SSZ_IOCTL_GET_INTERNAL_DATA_POINTER:
			if (dev->is_use_recv_queue) {
				ret = kSszNotSupport;
			} else {
				(*(const uint8_t**)param) =
				    ssz_safe_buff_front(&dev->recv_buff);
			}
			break;
		default:
			ret = kSszNotSupport;
			break;
	}
	return ret;
}

const SszIODevice kDrvCommIODev = {
    NULL,
    drv_comm_file_read,
    drv_comm_file_write,
    drv_comm_file_ctl,
};
void drv_comm_init(CommID comm_id, EventID recv_event, bool is_recv_by_one_byte,
                   uint8_t* recv_buff, int recv_buff_size, void* object,
                   DrvCommSendHandler send_handler) {
	ssz_mem_zero(&g_drv_comm_info[comm_id], sizeof(g_drv_comm_info[comm_id]));
	g_drv_comm_info[comm_id].recv_event = recv_event;
	g_drv_comm_info[comm_id].object = object;
	g_drv_comm_info[comm_id].send_handler = send_handler;
	g_drv_comm_info[comm_id].is_use_recv_queue = is_recv_by_one_byte;
	ssz_file_init(&g_drv_comm_info[comm_id].file, &kDrvCommIODev,
	              &g_drv_comm_info[comm_id]);

	if (recv_buff) {
		if (is_recv_by_one_byte) {
			ssz_safe_queue_init(&g_drv_comm_info[comm_id].recv_queue, recv_buff,
			                    recv_buff_size, 1);
		} else {
			ssz_safe_buff_init(&g_drv_comm_info[comm_id].recv_buff, recv_buff,
			                   recv_buff_size);
		}
	}
}
