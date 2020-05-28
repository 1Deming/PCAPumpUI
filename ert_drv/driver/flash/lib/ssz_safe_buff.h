/************************************************
 * DESCRIPTION:
 *
 *
 *
 ************************************************/
#pragma once
#include "ssz_def.h"
#include "ssz_deque.h"
/************************************************
 * Declaration
 ************************************************/
typedef struct {
	int16_t max_size;         /* max size */
	int16_t start_index;      /* start node index in node array*/
	int16_t next_write_index; /* the node index to write data in node array*/
	uint8_t* p_nodes;         /* node array */
	// int16_t one_node_byte_size; 	/* size of one node */
} SszSafeBuff;

#ifdef __cplusplus
extern "C" {
#endif

// init by the node array and node array size, the valid max size=max_size-1
void ssz_safe_buff_init(SszSafeBuff* container, void* buff, int buff_size);

// Capacity:
// judge is empty
bool ssz_safe_buff_is_empty(SszSafeBuff* container);
// judge is full
bool ssz_safe_buff_is_full(SszSafeBuff* container);

int ssz_safe_buff_size(SszSafeBuff* container);
int ssz_safe_buff_max_size(SszSafeBuff* container);

// Element access:
// return first element
uint8_t ssz_safe_buff_front_byte(SszSafeBuff* container);
// return first element address
const uint8_t* ssz_safe_buff_front(SszSafeBuff* container);

// Modifiers：
// delete first node
void ssz_safe_buff_pop_font_byte(SszSafeBuff* container);
// return real pop size
int ssz_safe_buff_pop_font(SszSafeBuff* container, int pop_buff_size);

// insert node at tail,set the node's data
// return:  false -> fail because it is full
bool ssz_safe_buff_push_back(SszSafeBuff* container, const void* data,int data_size);
bool ssz_safe_buff_push_back_one_byte(SszSafeBuff* container, uint8_t one_data);
// clear all
void ssz_safe_buff_clear(SszSafeBuff* container);

#ifdef __cplusplus
}
#endif