#include "ssz_stack.h"

/************************************************
 * Declaration
 ************************************************/

/************************************************
 * Variable
 ************************************************/

/************************************************
 * Function
 ************************************************/

// init by the node array and node array size
void ssz_stack_init(SszStack* container, void* p_nodes, int node_count,
                    int one_node_byte_size) {
	ssz_deque_init(container, p_nodes, node_count, one_node_byte_size);
}

// Capacity:
// judge is empty
bool ssz_stack_is_empty(SszStack* container) {
	return ssz_deque_is_empty(container);
}
// judge is full
bool ssz_stack_is_full(SszStack* container) {
	return ssz_deque_is_full(container);
}

int ssz_stack_size(SszStack* container) {
	return ssz_deque_size(container);
}

// Element access:
// return top element's address,
// return:  null->not exist
void* ssz_stack_top(SszStack* container) {
	return ssz_deque_back(container);
}

// Modifiers:
#if SSZ_DEQUE_EMPLACE_ENABLE
// insert node at tail and return the inserted node data
// return:  null -> fail because it is full
void* ssz_stack_emplace_back(SszStack* container) {
	return ssz_deque_emplace_back(container);
}
#endif
// insert node at tail,set the node's data
// return:  false -> fail because it is full
bool ssz_stack_push_back(SszStack* container, const void* data_p) {
	return ssz_deque_push_back(container, data_p);
}
// delete tail node
void ssz_stack_pop_back(SszStack* container) {
	ssz_deque_pop_back(container);
}
// clear all
void ssz_stack_clear(SszStack* container) {
	ssz_deque_clear(container);
}
