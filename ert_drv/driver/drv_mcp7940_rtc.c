/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "drv_mcp7940_rtc.h"
#include "bsp_i2c.h"
#include "greatest.h"

/************************************************
* Declaration
************************************************/

/************************************************
* Variable 
************************************************/

/************************************************
* Function 
************************************************/

//e.g. 10->0x10
uint8_t decimal_to_bcd(uint8_t dec)
{
	uint8_t bcd;
	bcd = (dec/10)*16 + dec%10;
	return bcd;
}

//e.g. 0x10->10
uint8_t bcd_to_decimal(uint8_t bcd)
{
	int dec;
	dec = (bcd/16)*10 + bcd%16;
	return dec;
}

//cal weekday
int rtc_week_day(int year, int month, int day)
{
	int y, c, m, d, week;
	int zeller;

	if (month >= 3)
	{
		m = month;
		y = year % 100;
		c = year / 100;
		d = day;
	}
	else	
	{
		m = month + 12;
		y = (year - 1) % 100;
		c = (year - 1) / 100;
		d = day;
	}

	zeller = y + y / 4 + c / 4 - 2 * c + (26 * (m + 1)) / 10 + d - 1;
	if (zeller < 0)    
	{
		week = 7 - (-zeller) % 7;
	}
	else
	{
		week = zeller % 7;
	}
	return week;
}

int drv_rtc_set_time(RtcTimeType type, int time_val)
{
	i2c_start();

	i2c_write_byte(RTC_WRITE);
	if(0 != i2c_read_ack())
		return -1;

	switch(type)
	{
	    case kRtcSec:
	    	i2c_write_byte(RTCSEC);
	    	break;
	    case kRtcMin:
	    	i2c_write_byte(RTCMIN);
	    	break;
	    case kRtcHour:
	      	i2c_write_byte(RTCHOUR);
	    	break;
	    case kRtcWkday:
	    	if (time_val == 0) {
				time_val = 7;
			}
	    	i2c_write_byte(RTCWKDAY);
	    	break;
	    case kRtcDate:
	    	i2c_write_byte(RTCDATE);
	    	break;
	    case kRtcMth:
	    	i2c_write_byte(RTCMTH);
	    	break;
	    case kRtcYear:
	    	i2c_write_byte(RTCYEAR);
	    	break;
		default:
			break;
	}
	if(0 != i2c_read_ack())
		return -1;

	i2c_write_byte(decimal_to_bcd(time_val));
	if(0 != i2c_read_ack())
		return -1;

	i2c_stop();

	return 0;
}

int drv_rtc_get_time(RtcTimeType type)
{
	int temp_time = 0;

	i2c_start();	

	i2c_write_byte(RTC_WRITE);
	if(0 != i2c_read_ack())
		return -1;

	switch(type)
	{
	    case kRtcSec:
	    	i2c_write_byte(RTCSEC);
	    	break;
	    case kRtcMin:
	    	i2c_write_byte(RTCMIN);
	    	break;
	    case kRtcHour:
	      	i2c_write_byte(RTCHOUR);
	    	break;
	    case kRtcWkday:
	    	i2c_write_byte(RTCWKDAY);
	    	break;
	    case kRtcDate:
	    	i2c_write_byte(RTCDATE);
	    	break;
	    case kRtcMth:
	    	i2c_write_byte(RTCMTH);
	    	break;
	    case kRtcYear:
	    	i2c_write_byte(RTCYEAR);
	    	break;
		default:
			break;
	}
	if(0 != i2c_read_ack())
		return -1;

	i2c_start();
	i2c_write_byte(RTC_READ);
	if(0 != i2c_read_ack())
		return -1;

	temp_time = i2c_read_byte();
	i2c_send_nack();
	i2c_stop();


	switch(type)
	{
	    case kRtcSec:
	    	temp_time &= 0x7F;
	    	break;
	    case kRtcMin:
	    	temp_time &= 0x7F;
	    	break;
	    case kRtcHour:
	    	temp_time &= 0x3F;
	    	break;
	    case kRtcWkday:
	    	temp_time &= 0x07;
	    	break;
	    case kRtcDate:
	    	temp_time &= 0x3F;
	    	break;
	    case kRtcMth:
	    	temp_time &= 0x1F;
	    	break;
	    case kRtcYear:
	    	break;
		default:
			break;
	}

    if(type == kRtcYear)
    {
        return (bcd_to_decimal(temp_time)+RTC_BASE_YEAR);
    }
	else if (type == kRtcWkday) 
	{
		int week_day = bcd_to_decimal(temp_time);
		if (week_day==7) 
		{
			week_day = 0;
		}
		return week_day;
	}
    else
    {
        return bcd_to_decimal(temp_time);
    }
}

//start rtc
void ERT_rtc_start(void)
{
    int sec;
    sec=drv_rtc_get_time(kRtcSec);
    drv_rtc_set_time(kRtcSec, sec+bcd_to_decimal(RTC_ST_BIT));
}

//stop rtc
void ERT_rtc_stop(void)
{
    int sec;
    sec=drv_rtc_get_time(kRtcSec);
    drv_rtc_set_time(kRtcSec,sec);
}

//get current date and time
int16_t ERT_rtc_get(TimeStamp *date_time )
{
	int8_t weekday;

  	i2c_start();

  	i2c_write_byte(RTC_WRITE);
	if(0 != i2c_read_ack())
		return -1;
	
  	i2c_write_byte(RTCSEC);
	if(0 != i2c_read_ack())
		return -1;

  	i2c_start();
    i2c_write_byte(RTC_READ);
	if(0 != i2c_read_ack())
		return -1;

  	date_time->second = bcd_to_decimal(i2c_read_byte() & 0x7F);
  	i2c_send_ack();

  	date_time->minute = bcd_to_decimal(i2c_read_byte() & 0x7F);
  	i2c_send_ack();

 	date_time->hour = bcd_to_decimal(i2c_read_byte() & 0x3F);
    i2c_send_ack();

    weekday = bcd_to_decimal(i2c_read_byte()& 0x07);  
    i2c_send_ack();

    date_time->day = bcd_to_decimal(i2c_read_byte() & 0x3F);
    i2c_send_ack();

    date_time->month = bcd_to_decimal(i2c_read_byte() & 0x1F);
    i2c_send_ack();

    date_time->year = bcd_to_decimal(i2c_read_byte());
    i2c_send_ack();

    i2c_stop();
  
	if (weekday == 7) 
	{
		  weekday = 0;
	}
	date_time->SP = weekday;
	date_time->year += RTC_BASE_YEAR;
	return 0;
}



//set date and time
static uint8_t rtx_sec;
int16_t ERT_rtc_set(const TimeStamp *date_time)
{
	///uint8_t weekday = rtc_week_day(date_time->year, date_time->month, date_time->day);

    ERT_rtc_stop();

    i2c_start();

    i2c_write_byte(RTC_WRITE);
	if(0 != i2c_read_ack())
		return -1;

    i2c_write_byte(RTCSEC);
	if(0 != i2c_read_ack())
		return -1;
	
	rtx_sec = decimal_to_bcd(date_time->second);
	
    i2c_write_byte(rtx_sec);//(decimal_to_bcd(date_time->second));
	if(0 != i2c_read_ack())
		return -1;

    i2c_write_byte(decimal_to_bcd(date_time->minute));
	if(0 != i2c_read_ack())
		return -1;

    i2c_write_byte(decimal_to_bcd(date_time->hour));
	if(0 != i2c_read_ack())
		return -1;

	if (date_time->SP == 0) {
		i2c_write_byte(0x07);
	}
	else {
		i2c_write_byte(decimal_to_bcd(date_time->SP));
	}

	
	if(0 != i2c_read_ack())
		return -1;

    i2c_write_byte(decimal_to_bcd(date_time->day));
	if(0 != i2c_read_ack())
		return -1;

    i2c_write_byte(decimal_to_bcd(date_time->month));
	if(0 != i2c_read_ack())
		return -1;

    i2c_write_byte(decimal_to_bcd(date_time->year-RTC_BASE_YEAR));
	if(0 != i2c_read_ack())
		return -1;

    i2c_stop();

	ERT_rtc_start();
	return 0;
}






















