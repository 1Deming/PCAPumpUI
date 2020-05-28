/************************************************
* DESCRIPTION:
*
*
************************************************/
#pragma once


#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>



/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif
//
////#define RTC_BASE_YEAR   2000
//	
//#define RTCSEC      0x00
//#define RTCMIN      0x01
//#define RTCHOUR     0x02
//#define RTCWKDAY    0x03
//#define RTCDATE     0x04
//#define RTCMTH      0x05
//#define RTCYEAR     0x06
//#define CONTROL     0x07
//#define OSCTRIM     0x08
//	
//	
//#define RTC_ST_BIT          0x80   // RTCSEC register
//#define RTC_12HR_BIT        0x40   // RTCHOUR register
//#define RTC_PM_BIT          0x20   // RTCHOUR register
//#define RTC_OSCRUN_BIT      0x20   // RTCWKDAY register
//#define RTC_LPYR_BIT        0x20   // RTCMTH register
//	
//	//control byte
//#define RTC_READ    0xDF
//#define RTC_WRITE   0xDE
//	
//	typedef enum
//	{
//		kRtcSec,
//		kRtcMin,
//		kRtcHour,
//		kRtcWkday,
//		kRtcDate,
//		kRtcMth,
//		kRtcYear,
//		kRtcMax,
//	}RtcTimeType;
//	
//	typedef struct
//	{
//		uint16_t year;	//range: base year:2000
//		uint16_t month;	//range: 1 ~ 12
//		uint16_t day; 	//range: 1 ~ 31
//		uint16_t weekday; //range: 0~6=Sunday,Monday,...
//	}RtcDate;
//	
//	typedef struct
//	{
//		uint16_t hour;   //range: 0 ~ 23
//		uint16_t minute; //range: 0 ~ 59
//		uint16_t second; //range: 0 ~ 59
//	}RtcTime;
	

//	typedef struct
//	{
//		uint8_t year;	//range: base year:2000
//		uint8_t month;	//range: 1 ~ 12
//		uint8_t day;	//range: 1 ~ 31
//		uint8_t hour;	//range: 0 ~ 23
//		uint8_t minute; //range: 0 ~ 59
//		uint8_t second; //range: 0 ~ 59
//        uint8_t SP;     //周
//	}TimeStamp;
	
//	//start rtc
//	void ERT_rtc_start(void);
//	//stop rtc
//	void ERT_rtc_stop(void);
//	//get current date and time  -1： error  1：good   sp不是修正值，verify_result=-1,其他：1
//	int16_t ERT_rtc_get(TimeStamp *date_time);
//	//set date and time
//	int16_t ERT_rtc_set(const TimeStamp *date_time);
//    
//   int drv_rtc_set_time(RtcTimeType type, int time_val);
#ifdef __cplusplus
}
#endif

