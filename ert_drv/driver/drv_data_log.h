/************************************************
* DESCRIPTION:
*
*
************************************************/
#pragma once

#include "ssz_def.h"
#include "data.h"
#include "record_log.h"
#include "drv_inter_rtc.h"
#include "bsp_gpio.h"
#include "drv_adc.h"
#include "data_type.h"

/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif


typedef enum
{
	kMajorIndexInfusionSet = 1,
	kMajorIndexACTCTRL	   = 2,	
	kMajorIndexAlarm = 3 ,
	kMajorIndexFirewareUpdate = 4,
	kMajorIndexSystemSet = 5,
	kMajorIndexCalibration = 7,

}MajorIndexID;


//saved size at nvram:16+20+4=40
typedef struct  {
	int32_t sequence_number;
	uint8_t time[8];
	int32_t major_id;
	uint32_t minor_id;
	uint8_t event_data[RECORD_LOG_EVENT_DATA_MAX_SIZE];
	uint32_t crc32;
}ert_LogOneRecord;


//#ifndef ERT
//typedef struct
//{
//	uint8_t Time[6];
//}type_RT;
//#endif

//#ifndef DEFINED_TYPEDEF_FOR_type_RT_
//#define DEFINED_TYPEDEF_FOR_type_RT_
//
//typedef struct {
//  /* the year just keeps the last three digits for its value here, for example, year 2019 just keeps 019 for its value */
//  uint8_t Time[6];
//} type_RT;
//
//#endif





//flash
#define ERT_drv_sst26_flash_enable ERT_drv_adc_battery_current_enable
#define ERT_drv_sst26_flash_disable ERT_drv_adc_battery_current_disable

////data
#define ERT_data_read  data_read
#define ERT_data_write data_write
#define ERT_data_erase_block data_erase_block 
//
////log
#define ERT_drv_record_log_add_data record_log_add_with_data_ex
#define ERT_drv_record_log_get_data record_log_get
#define ERT_drv_record_log_size record_log_size

//all  init
int8_t ERT_drv_flash_init(void);

//辅助函数
int32_t ERT_drv_time_to_seconds(const TimeStamp *time);
void ERT_drv_seconds_to_time(int32_t seconds, TimeStamp *time);




//bool ert_dataread(uint8_t major_id, uint8_t minor_id, uint8_t channel, uint8_t *data);
bool ert_datawrite(uint8_t major_id, uint8_t minor_id,  uint8_t *x_data, uint8_t x_size, uint8_t x_channel);
#define ert_dataWrite ert_datawrite

bool ert_dataerase(uint8_t channel);
#define ert_dataErase ert_dataerase


bool ert_dataread(uint8_t major_id, uint8_t minor_id, uint8_t channel, uint8_t *data, uint8_t x_size);
#define ert_dataRead ert_dataread

bool ert_recordread(uint8_t major_id, uint8_t channel, uint8_t *data_buff);
#define ert_recordRead ert_recordread

bool ert_recordWrite(type_RT *ptrRT, uint8_t major_id, uint8_t minor_id, uint8_t *data_buff, uint8_t channel);
#define ert_recordwrite ert_recordWrite

bool ert_recorderase(uint8_t major_id, uint8_t channel);
#define ert_recordErase ert_recorderase






#ifdef __cplusplus
}
#endif

