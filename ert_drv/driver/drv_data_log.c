/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "drv_data_log.h"
#include "ssz_time_utility.h"
#include <stdint.h>
#include <stdbool.h>
#include "drv_sst26_flash.h"
#include "data.h"
#include "record_log.h"
#include "bsp_spi.h"
#include "ssz_common.h"


#include "nrf_delay.h"
#include "ssz_algorithm.h"
/************************************************
* Declaration
************************************************/

/************************************************
* Variable 
************************************************/
#define ERT_DATA_BUFF_LEN				48


/************************************************
* Function 
************************************************/

int32_t ERT_drv_time_to_seconds(const TimeStamp *time)
{
	SszDateTime *tm = (SszDateTime *)time;
	return ssz_time_to_seconds(tm);
}


void ERT_drv_seconds_to_time(int32_t seconds, TimeStamp *time)
{
	SszDateTime *tm = (SszDateTime *)time;
	ssz_seconds_to_time(seconds, tm);
}


int8_t ERT_drv_sst26_flash_init(void)
{
	return drv_sst26_flash_init()?0:1;
}

int8_t ERT_drv_data_init(void)
{
	return (int8_t)data_init();
}

int8_t ERT_drv_record_log_init(void)
{
	return (int8_t)record_log_init();
}

int8_t ERT_drv_flash_init(void)
{
	int8_t ret = 0;
	bsp_spi_init();
	
	drv_sst26_pwr_enable();
	
	ret = drv_sst26_flash_init();
	if(ret != 1)
		return ret;

	ret = (int8_t)data_init();
	if(ret != 0)
		return ret;

	ret = (int8_t)record_log_init();
	if(ret != 0)
		return ret;

	return ret;
}




DataID data_index_to_id(uint8_t major_id, uint8_t minor_id, int *data_size)
{
	switch((MajorIndexID)major_id)
	{
		case kMajorIndexInfusionSet:
		{
			switch(minor_id)
			{
				//case 0: *data_size = 109; return kDataInfusionSetBlock;
				case 1: *data_size = 7; return kDataDoseCtrolParam;   
				case 2: *data_size = 48; return kDataBaseSet;
				case 3: *data_size = 48; return kDataTempSet;
				case 4: *data_size = 1; return kDataLastTempSet; 
				case 5: *data_size = 48; return kDataBolusSet; 
			}
			break;
		}
	
		case kMajorIndexACTCTRL:
		{
			switch(minor_id)
			{
				//case 0: *data_size = 35;  return kDataActionControlBlock;
				case 1: *data_size = 1; return kDataFirstLoadDose; 
				//case 2: return 0;
				case 3: *data_size = 1; return kDataInfusionSwtich;
				case 4: *data_size = 6; return kDataBaseProData; 
				case 5: *data_size = 6; return kDataBolusProData; 
				case 6: *data_size = 17; return kDataDelayProData; 
			}
			break;
		}
		
		case kMajorIndexAlarm:
		{
			switch(minor_id)
			{
				//case 0: *data_size = 1;  return kDataAlarmBlock;
				case 1: *data_size = 1; return kDataAlarmFlag; 
				case 2: *data_size = 6;  return kDataAlarmConfig;
			}
			break;

		}
		
		case kMajorIndexFirewareUpdate:
		{
			switch(minor_id)
			{
				//case 0: *data_size = 1;  return kDataFirmwareBlock;
				case 1: *data_size = 9; return kDataFirmwareInfo;  //下载头
				//case 2: return 0; //写入固件，写入正确返回false，错误返回true
				//case 3: return 0;  //重启
				default:
					break;
			}
			break;

		}


		case kMajorIndexSystemSet:
		{
			switch(minor_id)
			{
				//case 0: *data_size = 20;  return kDataSystemSetBlock;
				case 1: *data_size = 1; return kDataInfusionForce; 
				case 2: *data_size = 10; return kDataSerialNumber;
				case 3: *data_size = 6; return kDataSoftwareVersion;
				case 4: *data_size = 3; return kDataHardwareVersion;
				case 5: *data_size = 1; return kDataFlashConfigFlag;
				default:
					break;
			}
			break;

		}

		case kMajorIndexCalibration:
		{
			switch(minor_id)
			{
				//case 0: *data_size = 109;  return kDataInfusionSetBlock;
				case 1: *data_size = 4; return kDatabetteryOffset; 
				case 2: *data_size = 132; return kDataCalibrationInfo;
			}
			break;

		}
	}
    return kDataIDMax;
}



bool drv_ert_dataread(uint8_t major_id, uint8_t minor_id, uint8_t channel, uint8_t *data)
{
	DataID data_id;
	int	data_size;
	data_id = data_index_to_id(major_id, minor_id, &data_size);
	ERT_data_read(data_id, data, data_size);
	return true;
}

extern SszNvram g_data_file_nvram;

bool ert_dataread(uint8_t major_id, uint8_t minor_id, uint8_t channel, uint8_t *data, uint8_t x_size)
{
	DataID data_id;
	int	data_size;

	typedef struct
	{
		uint32_t pack_num;
		uint8_t buff[128];
	}g_val;


	if(major_id == 4)
	{
		switch(minor_id)
		{
			case 2:  //读取固件包
			{
				/*
				uint32_t package_num = (data[0]<<24)|(data[1]<<16)|(data[2]<<8)|data[3];
				memset(&data[4], 0xFF, 128);
				
				uint32_t addr = FIRMWARE_NVRAM_START_ADDRESS + package_num*128;
				ssz_nvram_read_ex(&g_data_file_nvram, addr, (uint8_t *)&data[4], 128, 
										SSZ_NVRAM_RW_MODE_CHECK_IF_CAN_WRITE|SSZ_NVRAM_RW_MODE_CHECK_IF_WRITE_SUCCESS);

				*/
				
				g_val *dptr = (g_val *)data;
				memset(dptr->buff, 0xFF, 128);
				
				uint32_t addr = FIRMWARE_NVRAM_START_ADDRESS + dptr->pack_num*128;
				ssz_nvram_read_ex(&g_data_file_nvram, addr, (uint8_t *)dptr->buff, 128, 
										SSZ_NVRAM_RW_MODE_CHECK_IF_CAN_WRITE|SSZ_NVRAM_RW_MODE_CHECK_IF_WRITE_SUCCESS);

				
				
				return false;
			}

			case 3: //系统复位
			{
				return false;
			}
		}
	}
	

	data_id = data_index_to_id(major_id, minor_id, &data_size);
	data_read(data_id, data, x_size);
	return false;

}


//boolean_T ert_dataRead(uint8_T x_majorId,uint8_T x_minorId,uint8_T x_channel,uint8_T* x_data,uint8_T x_size);
bool drv_ert_datawrite(uint8_t major_id, uint8_t minor_id,  uint8_t *buff, uint8_t buff_size, uint8_t channel)
{
	DataID data_id;
	int data_size;
	data_id = data_index_to_id(major_id, minor_id, &data_size);
	data_write(data_id, buff, buff_size);
	return false;
}



//boolean_T ert_dataWrite(uint8_T x_majorId,uint8_T x_minorId,uint8_T* x_data,uint8_T x_size,uint8_T x_channel);
bool ert_datawrite(uint8_t major_id, uint8_t minor_id,  uint8_t *x_data, uint8_t x_size, uint8_t x_channel)
{
	DataID data_id;
	int data_size;
	typedef struct
	{
		uint32_t pack_num;
		uint8_t buff[128];
	}g_val;
	

	if(major_id == 4)
	{
		switch(minor_id)
		{
			case 2:  //写入固件包
			{
			/*
				uint32_t package_num = (x_data[0]<<24)|(x_data[1]<<16)|(x_data[2]<<8)|x_data[3];
				uint8_t df[128];
				memcpy(df, &x_data[4], 128);
				
				uint32_t addr = FIRMWARE_NVRAM_START_ADDRESS + package_num*128;
				ssz_nvram_write_ex(&g_data_file_nvram, addr, df, 128, 
										SSZ_NVRAM_RW_MODE_CHECK_IF_CAN_WRITE|SSZ_NVRAM_RW_MODE_CHECK_IF_WRITE_SUCCESS);

				*/
			
				g_val *dptr = (g_val *)x_data;
	
				uint32_t addr = FIRMWARE_NVRAM_START_ADDRESS + dptr->pack_num*128;
				ssz_nvram_read_ex(&g_data_file_nvram, addr, (uint8_t *)dptr->buff, 128, 
										SSZ_NVRAM_RW_MODE_CHECK_IF_CAN_WRITE|SSZ_NVRAM_RW_MODE_CHECK_IF_WRITE_SUCCESS);

				



										
				return false;

			}

			case 3: //系统复位
			{
				NVIC_SystemReset();
				return false;
			}
		}
	}
	
	data_id = data_index_to_id(major_id, minor_id, &data_size);
	data_write(data_id, x_data, x_size);
	return false;
}

//boolean_T ert_dataErase(uint8_T x_channel);
bool ert_dataerase(uint8_t channel)
{

	const DataID init_ids[] = {kDataInfusionSetBlock, kDataActionControlBlock, 
	                           kDataAlarmBlock, kDataFirmwareBlock, kDataSystemSetBlock, 
	                           kDataCalibrationBlock};
	for(int i =0; i<ssz_array_size(init_ids); i++)
	{
		data_erase_block(init_ids[i]);
		nrf_delay_ms(500);
	}
	
    return false;
}


LogEvent log_index_to_id(uint8_t major_id, uint8_t minor_id)
{
	switch(major_id)
	{
		case 1:

			switch(minor_id)
			{
				case 1: return kLogEventBolusStart;
				case 2: return kLogEventBolusEnd;
				case 3: return kLogEventBaseStart;
				case 4: return kLogEventBaseEnd;
				case 5: return kLogEventDelayDose;
			}
			break;
		case 2:

			switch(minor_id)
			{
				case 1: return kLogEventAlarm;
			}

			break;
		case 3:

			switch(minor_id)
			{
				case 1: return kLogEventPostReport;
				case 2: return kLogEventSwitchSet;
				case 3: return kLogEventDoseParaSet;
				case 4: return kLogEventFirstLoadDose;
				case 5: return kLogEventReset;
			}

		case 4:
			switch(minor_id)
			{
				case 1: return kLogEventBaseSet12s;
				case 2: return kLogEventBaseSet16;
				case 3: return kLogEventBaseSet12e;
				case 4: return kLogEventTempSet12s;
				case 5: return kLogEventTempSet16;
				case 6: return kLogEventTempSet12e;
			}

			break;
	}
        
        return true;
}


extern SszRecord g_logs[kLogTypeMax];
static uint16_t log_count;
bool ert_recordread(uint8_t major_id, uint8_t channel, uint8_t *data_buff)
{
	result_t ret;

	LogOneRecord getlog;
	LogType log_type;
	ert_LogOneRecord *dptr = (ert_LogOneRecord *)data_buff;
	
	if(++log_count >1000)
		log_count = 0;

	switch(major_id)
	{
		case 1:
			log_type = kInfusionLog;
			break;

		case 2:
			log_type = kAlarmLog;
			break;

		case 3:
			log_type = kInternalLog1;
			break;
		
		case 4:
			log_type = kInternalLog2;		
			break;
	}
	
	ret = record_log_get(log_type, log_count, &getlog);
	//序列号
	dptr->sequence_number = getlog.sequence_number;
	//时间
	memcpy(dptr->time, &getlog.occur_time, 4);
	memcpy(&dptr->time[4], (uint8_t *)&getlog.event_type, 2);	
	//ID号
	dptr->major_id = (getlog.event_id >>8)& 0xFF;
	dptr->minor_id = getlog.event_id & 0xFF;
	//数据	
	memcpy(dptr->event_data, getlog.event_data, 20);

	uint32_t crc32 = ssz_crc32(data_buff, 40);
	memcpy((uint8_t *)&dptr->crc32, (uint8_t *)&crc32, 4);

	ret = ssz_record_size(&g_logs[log_type]);
	if(ret == 0)
		return 0;
	return ret;

}

bool ert_recordWrite(type_RT *ptrRT, uint8_t major_id, uint8_t minor_id, uint8_t *data_buff, uint8_t channel)
{
	LogType log_type;
	LogOneRecord onelog;

	//LOG 类型
	switch(major_id)
	{
		case 1:
			log_type = kInfusionLog;
			break;

		case 2:
			log_type = kAlarmLog;
			break;

		case 3:
			log_type = kInternalLog1;
			break;
		
		case 4:
			log_type = kInternalLog2;		
			break;
	}
	
	//时间
	memcpy(&onelog.occur_time, ptrRT->Time, 4);
	//事件类型
	onelog.event_type = (uint32_t)(ptrRT->Time[4]<<8) | ptrRT->Time[5];
	
	//事件ID
    uint16_t id = (major_id<<8)|minor_id;
	onelog.event_id = (int32_t)id;
	
	//数据
	ssz_mem_zero(onelog.event_data, 20);
	//if(data_size > 20) data_size = 20;
	memcpy(onelog.event_data, data_buff, 20);
	
	record_log_add_with_data_ex(log_type, onelog.occur_time,
		onelog.event_type, onelog.event_id, onelog.event_data, 20);

	return false;

}

bool ert_recorderase(uint8_t major_id, uint8_t channel)
{
	 result_t ret;
	 LogType log_type;

	 //LOG 类型
	 switch(major_id)
	 {
		 case 1:
			 log_type = kInfusionLog;
			 break;
	 
		 case 2:
			 log_type = kAlarmLog;
			 break;
	 
		 case 3:
			 log_type = kInternalLog1;
			 break;
		 
		 case 4:
			 log_type = kInternalLog2;		 
			 break;
	 }
	 
	 ret = record_log_clear(log_type);
	 
     return ret;
}









