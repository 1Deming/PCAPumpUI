/************************************************
* DESCRIPTION:
*
*
************************************************/
#pragma once

#include "ssz_def.h"
#include "mid_rtc.h"
/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
	uint8_t year;	//range: base year:2000
	uint8_t month;	//range: 1 ~ 12
	uint8_t day;	//range: 1 ~ 31
	uint8_t hour;	//range: 0 ~ 23
	uint8_t minute; //range: 0 ~ 59
	uint8_t second; //range: 0 ~ 59
	uint8_t SP; 	//周(此处不要啦)
}TimeStamp;


void ERT_rtc_get(TimeStamp *ts);
void ERT_rtc_set(TimeStamp ts);



#ifdef __cplusplus
}
#endif

