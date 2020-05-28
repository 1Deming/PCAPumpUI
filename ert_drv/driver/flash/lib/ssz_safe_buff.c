#include "ssz_safe_buff.h"
#include "ssz_common.h"
/************************************************
 * Declaration
 ************************************************/
#define M_get_node(container, index) \
	((uint8_t*)((container)->p_nodes + (index)))
#define M_get_data_address(container, index) M_get_node(container, index)
// #define M_get_data_size(container) ((container)->one_node_byte_size)
/************************************************
 * Variable
 ************************************************/

/************************************************
 * Function
 ************************************************/

// init by the node array and node array size,the valid max size=max_size-1
void ssz_safe_buff_init(SszSafeBuff* container, void* buff, int buff_size) {
	ssz_assert(container && buff);
	container->max_size = (int16_t)buff_size;
	container->start_index = 0;
	container->next_write_index = 0;
	// container->one_node_byte_size = (int16_t)one_node_byte_size;
	container->p_nodes = (uint8_t*)buff;
}

// Capacity:
// judge is empty
bool ssz_safe_buff_is_empty(SszSafeBuff* container) {
	if (container->start_index == container->next_write_index) {
		return true;
	} else {
		return false;
	}
}
// judge is full
bool ssz_safe_buff_is_full(SszSafeBuff* container) {
	if (container->next_write_index >= container->max_size &&
	    container->next_write_index != container->start_index) {
		return true;
	} else {
		return false;
	}
}

int ssz_safe_buff_size(SszSafeBuff* container) {
	int size = container->next_write_index - container->start_index;

	return size;
}
int ssz_safe_buff_max_size(SszSafeBuff* container) {
	return container->max_size - 1;
}

// Element access:
// return first element
uint8_t ssz_safe_buff_front_byte(SszSafeBuff* container) {
	ssz_assert(container);
	if (container->start_index != container->next_write_index) {
		return container->p_nodes[container->start_index];
	} else {
		return 0;
	}
}
// return first element address
const uint8_t* ssz_safe_buff_front(SszSafeBuff* container) {
	ssz_assert(container);
	if (container->start_index != container->next_write_index) {
		return container->p_nodes + container->start_index;
	} else {
		return 0;
	}
}

// Modifiers:
// delete first node
void ssz_safe_buff_pop_font_byte(SszSafeBuff* container) {
	if (container->start_index != container->next_write_index) {
		int index = container->start_index + 1;
		container->start_index = index;
	}
}
// return real pop size
int ssz_safe_buff_pop_font(SszSafeBuff* container, int pop_buff_size) {
	int ret = 0;
	if (container->start_index != container->next_write_index) {
		int index = container->start_index + pop_buff_size;
		if (index > container->next_write_index) {
			index = container->next_write_index;
		}
		ret = index - container->start_index;
		container->start_index = index;
	}
	return ret;
}

// insert node at tail,set the node's data
// return:  false -> fail because it is full
bool ssz_safe_buff_push_back(SszSafeBuff* container, const void* data,
                             int data_size) {
	if (container->start_index == container->next_write_index) {
		container->start_index = 0;
		container->next_write_index = 0;
	}
	if (container->next_write_index + data_size > container->max_size) {
		// it is at end or full
		return false;
	} else {
		memcpy(container->p_nodes + container->next_write_index, data,
		       data_size);
		container->next_write_index += data_size;
		if (container->next_write_index < container->max_size) {
			container->p_nodes[container->next_write_index] = 0;
		}
		return true;
	}
}
bool ssz_safe_buff_push_back_one_byte(SszSafeBuff* container,
                                      uint8_t one_data) {
	if (container->start_index == container->next_write_index) {
		container->start_index = 0;
		container->next_write_index = 0;
	}
	if (container->next_write_index >= container->max_size) {
		// it is at end or full
		return false;
	} else {
		container->p_nodes[container->next_write_index] = one_data;
		container->next_write_index++;
		if (container->next_write_index < container->max_size) {
			container->p_nodes[container->next_write_index] = 0;
		}
		return true;
	}
}
// clear all
void ssz_safe_buff_clear(SszSafeBuff* container) {
	container->start_index = 0;
	container->next_write_index = 0;
}