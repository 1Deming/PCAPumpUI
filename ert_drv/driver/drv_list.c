/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "drv_list.h"


/************************************************
* Declaration
************************************************/



/************************************************
* Variable 
************************************************/
SszListNode g_drv_list_alarm_remind_nodes[4];
SszList g_drv_list_alarm_remind;

SszListNode g_drv_list_alarm_low_nodes[4];
SszList g_drv_list_alarm_low;

SszListNode g_drv_list_alarm_middle_nodes[4];
SszList g_drv_list_alarm_middle;

SszListNode g_drv_list_alarm_high_nodes[4];
SszList g_drv_list_alarm_high;


/************************************************
* Function 
************************************************/

SszList * drv_list_get_container(ListType list_type)
{
	SszList *list = NULL;
	switch(list_type)
	{
		case kListTypeAlarmRemind:
			list = &g_drv_list_alarm_remind;
			break;
		
		case kListTypeAlarmLow:
			list = &g_drv_list_alarm_low;
			break;
		
		case kListTypeAlarmMidddle:
			list = &g_drv_list_alarm_middle;
			break;

		case kListTypeAlarmHigh:
			list = &g_drv_list_alarm_high;
			break;

		default:
			break;

	}

	return list;
}

void ERT_drv_list_init(void)
{
	ssz_list_init(&g_drv_list_alarm_remind, (SszListNode *)g_drv_list_alarm_remind_nodes, 
				   ssz_array_size(g_drv_list_alarm_remind_nodes), ssz_array_node_size(g_drv_list_alarm_remind_nodes)); 

	ssz_list_init(&g_drv_list_alarm_low, (SszListNode *)g_drv_list_alarm_low_nodes, 
				   ssz_array_size(g_drv_list_alarm_low_nodes), ssz_array_node_size(g_drv_list_alarm_low_nodes)); 


	ssz_list_init(&g_drv_list_alarm_middle, (SszListNode *)g_drv_list_alarm_middle_nodes, 
				   ssz_array_size(g_drv_list_alarm_middle_nodes), ssz_array_node_size(g_drv_list_alarm_middle_nodes)); 


	ssz_list_init(&g_drv_list_alarm_high, (SszListNode *)g_drv_list_alarm_high_nodes, 
				   ssz_array_size(g_drv_list_alarm_high_nodes), ssz_array_node_size(g_drv_list_alarm_high_nodes)); 

}

//postion

int ERT_drv_list_begin(ListType list_type)
{
	return ssz_list_begin(drv_list_get_container(list_type));
}

int ERT_drv_list_prev(ListType list_type, int pos)
{
	return ssz_list_prev(drv_list_get_container(list_type), pos);
}

int ERT_drv_list_next(ListType list_type, int pos)
{
	return ssz_list_next(drv_list_get_container(list_type), pos);
}

int ERT_drv_list_rbegin(ListType list_type)
{
	return ssz_list_rbegin(drv_list_get_container(list_type));
}

//read  data 
void *ERT_drv_list_at_pos(ListType list_type, int pos)
{
	return ssz_list_at_pos(drv_list_get_container(list_type), pos);
}


void* ERT_drv_list_front(ListType list_type)
{
	return ssz_list_front(drv_list_get_container(list_type));
}

void* ERT_drv_list_back(ListType list_type)
{
	return ssz_list_back(drv_list_get_container(list_type));

}

//write data
int ERT_drv_list_push_back(ListType list_type, const void *data)
{
	return ssz_list_push_back(drv_list_get_container(list_type), data);
}

void ERT_drv_list_pop_back(ListType list_type)
{
	ssz_list_pop_back(drv_list_get_container(list_type));
}


int ERT_drv_list_push_front(ListType list_type, const void *data)
{
	return ssz_list_push_front(drv_list_get_container(list_type), data);
}


void ERT_drv_list_pop_front(ListType list_type)
{
	ssz_list_pop_front(drv_list_get_container(list_type));
}


//erase
int ERT_drv_list_erase(ListType list_type, int pos)
{
	return ssz_list_erase(drv_list_get_container(list_type), pos);
}


//search

int ERT_drv_list_find_node(ListType list_type, void *data)
{
	int pos;
	const void *compare_data = NULL;
	
	for(pos = ERT_drv_list_begin(list_type); pos != -1;)
					
	{
		compare_data = ERT_drv_list_at_pos(list_type, pos);
		if(0 == memcmp((int *)compare_data, (int *)data, 4))
		{
			return pos;
		}
		pos = ERT_drv_list_next(list_type, pos);	
	}

	return -1;	
}









































