/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "drv_stack.h"
#include "ssz_common.h"
#include "ssz_stack.h"

/************************************************
* Declaration
************************************************/

/************************************************
* Variable 
************************************************/
int g_drv_stack_test_nodes[16];
SszStack g_drv_stack_test;

/************************************************
* Function 
************************************************/
SszStack *drv_stack_get_stack(StackType stack_type)
{
	SszStack *stack;

	switch(stack_type)
	{
		case kStackTypeTest:
			stack = &g_drv_stack_test;
			break;
	}

	return stack;
}

void ETR_drv_stack_init(void)
{
	ssz_stack_init(&g_drv_stack_test, g_drv_stack_test_nodes, ssz_array_size(g_drv_stack_test_nodes),
						ssz_array_node_size(g_drv_stack_test_nodes));
}

// Capacity:
// judge is empty
bool ERT_drv_stack_is_empty(StackType stack_type)
{
	return ssz_stack_is_empty(drv_stack_get_stack(stack_type)); 
}
	
// judge is full
bool ERT_drv_stack_is_full(StackType stack_type)
{
	return ssz_stack_is_full(drv_stack_get_stack(stack_type)); 
}

int ERT_drv_stack_size(StackType stack_type)
{
	return ssz_stack_size(drv_stack_get_stack(stack_type)); 
}

// Element access:
// return top element's address,
// return:  null->not exist
void *ERT_drv_stack_top(StackType stack_type)
{
	return ssz_stack_top(drv_stack_get_stack(stack_type));
}



// Modifiers：

// insert node at tail,set the node's data
// return:  false -> fail because it is full
bool ERT_drv_stack_push_back(StackType stack_type, const void *data_p)
{
	return ssz_stack_push_back(drv_stack_get_stack(stack_type), data_p);
}


// delete tail node
void ERT_drv_stack_pop_back(StackType stack_type)
{
	ssz_stack_pop_back(drv_stack_get_stack(stack_type));
}

// clear all
void ERT_drv_stack_clear(StackType stack_type)
{
	ssz_stack_clear(drv_stack_get_stack(stack_type));
}




















