/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "ert_RTC.h"

/************************************************
* Declaration
************************************************/

/************************************************
* Variable 
************************************************/

/************************************************
* Function 
************************************************/
void TimeStamp_To_SszDateTime(TimeStamp ts, SszDateTime *st)
{
	st->year = ts.year + 2000;
	st->month = (int8_t)ts.month;
	st->day = (int8_t)ts.day;
	st->hour = (int8_t)ts.hour;
	st->minute = (int8_t)ts.minute;
	st->second = (int8_t)ts.second;
	st->weekday = (int8_t)ts.SP;
}

void SszDateTime_To_TimeStamp(SszDateTime st,  TimeStamp *ts)
{
	ts->year = st.year-2000;
	ts->month = st.month;
	ts->day = st.day;
	ts->hour = st.hour;
	ts->minute = st.minute;
	ts->second = st.second;
	ts->SP = st.weekday;
}

void ERT_rtc_set(TimeStamp *ts)
{
	SszDateTime time;
	TimeStamp_To_SszDateTime(*ts, time);
	rtc_set(time);
}

void ERT_rtc_get(TimeStamp *ts)
{
	SszDateTime *DateTime;
	DateTime = rtc_get();
	SszDateTime_To_TimeStamp(*DateTime, ts);
}


