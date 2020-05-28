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

typedef struct
{
	int id;
	int data;
}QueueNode;
  
  
typedef enum
{
	kQueueTypeText,
	kQueueTypeIDMAX,
}QueueType;

void ERT_drv_queue_init(void);
//Capacity:
bool ERT_drv_queue_is_empty(QueueType queue_type);
bool ERT_drv_queue_is_full(QueueType queue_type);
int ERT_drv_queue_size(QueueType queue_type);
//Element access:
//return first element's address, 
//return:  null->not exist 
void *ERT_drv_queue_front(QueueType queue_type);
//return last element's address
//return:  null->not exist
void *ERT_drv_queue_back(QueueType queue_type);
//Modifiers：
//delete first node
void ERT_drv_queue_pop(QueueType queue_type);
//insert node at tail,set the node's data  and return the inserted node pos
//return:  -1 -> fail because it is full
int ERT_drv_queue_push(QueueType queue_type, const void *data);


#ifdef __cplusplus
}
#endif

