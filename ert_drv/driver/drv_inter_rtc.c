/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "drv_inter_rtc.h"
#include "ssz_time_utility.h"
#include "ssz_common.h"
#include "timer_config.h"
#include "timer.h"
#include "nrf_drv_systick.h"
#include "app_timer.h"

/************************************************
* Declaration
************************************************/

/************************************************
* Variable 
************************************************/
uint32_t g_drv_inter_rtc_count;
TimeStamp g_drv_inter_rtc;
bool g_drv_inter_rtc_sw;
bool g_drv_rtc_is_setting;

/************************************************
* Function 
************************************************/
void TimeStamp_To_SszDateTime(TimeStamp ts, SszDateTime *st)
{
	st->year = ts.year + RTC_BASE_YEAR;
	st->month = (int8_t)ts.month;
	st->day = (int8_t)ts.day;
	st->hour = (int8_t)ts.hour;
	st->minute = (int8_t)ts.minute;
	st->second = (int8_t)ts.second;
	st->weekday = (int8_t)ts.SP;
}

void SszDateTime_To_TimeStamp(SszDateTime st,  TimeStamp *ts)
{
	ts->year = st.year-RTC_BASE_YEAR;
	ts->month = st.month;
	ts->day = st.day;
	ts->hour = st.hour;
	ts->minute = st.minute;
	ts->second = st.second;
	ts->SP = st.weekday;
}

void drv_inter_rtc_pro(void)
{
	SszDateTime time;

	if((g_drv_inter_rtc_sw == 0) || g_drv_rtc_is_setting) return;
	
	g_drv_inter_rtc_count++;
	
	ssz_seconds_to_time(g_drv_inter_rtc_count, &time);
	SszDateTime_To_TimeStamp(time, &g_drv_inter_rtc);
}

void drv_inter_rtc_scan_start(void)
{
	timer_set_handler(kTimerScanRTC, drv_inter_rtc_pro);
	timer_start_periodic_every(kTimerScanRTC, 1000);
	drv_inter_rtc_pro();
}	

void drv_inter_rtc_scan_stop(void)
{
	timer_stop(kTimerScanRTC);
}

int8_t ERT_drv_inter_rtc_init(void)
{
	SszDateTime time;
	ssz_mem_zero(&g_drv_inter_rtc, sizeof(g_drv_inter_rtc));
	g_drv_inter_rtc.year = 19;
	g_drv_inter_rtc.month = 1;
	g_drv_inter_rtc.day = 1;
	g_drv_inter_rtc.hour = 0;
	g_drv_inter_rtc.minute = 0;
	g_drv_inter_rtc.second = 0;
	TimeStamp_To_SszDateTime(g_drv_inter_rtc, &time);
	g_drv_inter_rtc_count = ssz_time_to_seconds(&time);

	g_drv_rtc_is_setting = false;
	g_drv_inter_rtc_sw = 1;
	return 0;
}


void ERT_drv_inter_rtc_start(void)
{
	g_drv_inter_rtc_sw = 1;
}

void ERT_drv_inter_rtc_stop(void)
{
	g_drv_inter_rtc_sw = 0;
}

void ERT_drv_inter_rtc_set(TimeStamp *ts)
{
	SszDateTime time;
	g_drv_rtc_is_setting = true;
	g_drv_inter_rtc = *ts;
	TimeStamp_To_SszDateTime(g_drv_inter_rtc, &time);
	g_drv_inter_rtc_count = ssz_time_to_seconds(&time);
	g_drv_rtc_is_setting = false;
}

void ERT_drv_inter_rtc_get(TimeStamp *ts)
{
	*ts = g_drv_inter_rtc;
}


uint32_t ERT_drv_inter_rtc_get_systicks(void)
{
	return app_timer_cnt_get();
}


void ERT_drv_inter_rtc_increase_by_sec(uint32_t ms)
{
	g_drv_inter_rtc_count += ms;
}









