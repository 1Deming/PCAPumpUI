/************************************************
* DESCRIPTION:
*
*
************************************************/
#pragma once

#include "ssz_def.h"
#include "drv_mcp7940_rtc.h"

/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#define RTC_BASE_YEAR   2000

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


void drv_inter_rtc_pro(void);  //inter use

int8_t ERT_drv_inter_rtc_init(void);
void ERT_drv_inter_rtc_stop(void);
void ERT_drv_inter_rtc_start(void);
void ERT_drv_inter_rtc_set(TimeStamp *ts);
//TimeStamp ERT_drv_inter_rtc_get(void);
void ERT_drv_inter_rtc_get(TimeStamp *ts);
void ERT_drv_inter_rtc_increase_by_sec(uint32_t ms);
uint32_t ERT_drv_inter_rtc_get_systicks(void);




#ifdef __cplusplus
}
#endif

