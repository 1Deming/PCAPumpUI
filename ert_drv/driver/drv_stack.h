/************************************************
* DESCRIPTION:
*
*
************************************************/
#pragma once

#include "ssz_def.h"

/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
	kStackTypeTest,

	
	kStackTypeIDMAX,
}StackType;


void ETR_drv_stack_init(void);
// Capacity:
// judge is empty
bool ERT_drv_stack_is_empty(StackType stack_type);	
// judge is full
bool ERT_drv_stack_is_full(StackType stack_type);
int ERT_drv_stack_size(StackType stack_type);
// Element access:
// return top element's address,
// return:	null->not exist
void *ERT_drv_stack_top(StackType stack_type);
// Modifiers：
// insert node at tail,set the node's data
// return:	false -> fail because it is full
bool ERT_drv_stack_push_back(StackType stack_type, const void *data_p);
// delete tail node
void ERT_drv_stack_pop_back(StackType stack_type);
// clear all
void ERT_drv_stack_clear(StackType stack_type);

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

















#ifdef __cplusplus
}
#endif

