/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "drv_queue.h"
#include "ssz_queue.h"
#include "ssz_common.h"

/************************************************
* Declaration
************************************************/

/************************************************
* Variable 
************************************************/
QueueNode g_drv_queue_test_nodes[16];
SszQueue g_drv_queue_test;

/************************************************
* Function 
************************************************/
SszQueue *drv_queue_get_queue(QueueType queue_type)
{
	SszQueue * queue;
	switch(queue_type)
	{
		case kQueueTypeText:
			queue = &g_drv_queue_test;
			break;
	
	}

	return queue;
}

void ERT_drv_queue_init(void)
{
	ssz_queue_init(&g_drv_queue_test, g_drv_queue_test_nodes, 
		      ssz_array_size(g_drv_queue_test_nodes), ssz_array_node_size(g_drv_queue_test_nodes));
}



//Capacity:
bool ERT_drv_queue_is_empty(QueueType queue_type)
{
	return ssz_queue_is_empty(drv_queue_get_queue(queue_type));
}

bool ERT_drv_queue_is_full(QueueType queue_type)
{
	return ssz_queue_is_full(drv_queue_get_queue(queue_type));
}

int ERT_drv_queue_size(QueueType queue_type)
{
	return ssz_queue_size(drv_queue_get_queue(queue_type));
}

//Element access:
//return first element's address, 
//return:  null->not exist 
void *ERT_drv_queue_front(QueueType queue_type)
{
	return ssz_queue_front(drv_queue_get_queue(queue_type));
}

//return last element's address
//return:  null->not exist
void *ERT_drv_queue_back(QueueType queue_type)
{
	return ssz_queue_back(drv_queue_get_queue(queue_type));
}

//Modifiers：
//delete first node
void ERT_drv_queue_pop(QueueType queue_type)
{
	ssz_queue_pop(drv_queue_get_queue(queue_type));
}


//insert node at tail,set the node's data  and return the inserted node pos
//return:  -1 -> fail because it is full
int ERT_drv_queue_push(QueueType queue_type, const void *data)
{
	return ssz_queue_push(drv_queue_get_queue(queue_type), data); 
}












