/************************************************
* DESCRIPTION:
*
*
************************************************/
#pragma once

#include "ssz_def.h"
#include "ssz_list.h"
#include "ssz_common.h"

/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
	kListTypeAlarmRemind,
	kListTypeAlarmLow,
	kListTypeAlarmMidddle,
	kListTypeAlarmHigh,
	//add other
	
	kListTypeIDMax,
}ListType;


extern SszListNode g_drv_list_alarm_remind_nodes[4];
extern SszList g_drv_list_alarm_remind;

extern SszListNode g_drv_list_alarm_low_nodes[4];
extern SszList g_drv_list_alarm_low;

extern SszListNode g_drv_list_alarm_middle_nodes[4];
extern SszList g_drv_list_alarm_middle;

extern SszListNode g_drv_list_alarm_high_nodes[4];
extern SszList g_drv_list_alarm_high;

//init all type list, The user needs to determine the linked list in advance
void ERT_drv_list_init(void);
//Reads data from the tail of the list
void* ERT_drv_list_back(ListType list_type);
void* ERT_drv_list_front(ListType list_type);
void *ERT_drv_list_at_pos(ListType list_type, int pos);
//Write data to the tail of the list
int ERT_drv_list_push_back(ListType list_type, const void *data);
int ERT_drv_list_push_front(ListType list_type, const void *data);
//Erases the node at the specified location
int ERT_drv_list_erase(ListType list_type, int pos);

int ERT_drv_list_begin(ListType list_type);
int ERT_drv_list_next(ListType list_type, int pos);
int ERT_drv_list_prev(ListType list_type, int pos);
int ERT_drv_list_rbegin(ListType list_type);

SszList * drv_list_get_container(ListType list_type);

int ERT_drv_list_find_node(ListType list_type, void *data);






















#ifdef __cplusplus
}
#endif

