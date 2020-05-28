#pragma once
#include "ssz_def.h"
/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif


#define SERIAL_NUMBER_LEN 12



#define FIRMWARE_NVRAM_START_ADDRESS ((1024+900)*4096)//((512+60)*1024)


//used to read this to check if not init or version upgrade
//if not init or version upgrade, write default data to nvram
typedef struct {
	int8_t init_flag;//the flag indicate if the data is init
	int8_t version;//if the version is not same, it will reinit the data
}DataInitInfo;

//used to clear the block data which is the type, 
// e.g. clear user data will erase the block data which's type is User
typedef enum {
	kDataTypeInfusionSet,
	kDataTypeActionControl,
	kDataTypeAlarm,
	kDataTypeFirmware,
	kDataTypeSystemSet,
	kDataTypeCalibration,
	kDataTypeMax,
}DataType;


//Notice: first define block, then define the block's childes
//Cause it use this rule to find which id is at which block 
// you can read or write by block or child id
//e.g.  
// struct XXX{    <- XXX is a block
//	int id;			<- id the child of the block
//	char name[20];   <-	name is the child of the block
// };
// XXX a;
// data_read(XXX, &a, sizeof(a));    <- can read block
// data_read(id, &a.id, sizeof(a.id));  <- can read block's child(must use the block cache first)
// data_read(id, &a.name, sizeof(a.name)); <- can read block's child(must use the block cache first)
typedef enum {

	kDataInfusionSetInitBlock,
	kDataActionControlInitBlock,
	kDataAlarmInitBlock,
	kDataFirmwareInitBlock,
	kDataSystemSetInitBlock,
	kDataCalibrationInitBlock,
	//kDataEnergyStardardInitBlock,

	//Infusion set block
	kDataInfusionSetBlock,
	kDataDoseCtrolParam,
	kDataBaseSet,
	kDataTempSet,
	kDataLastTempSet,
	kDataBolusSet,

	//action control
	kDataActionControlBlock,
	kDataFirstLoadDose,
	kDataInfusionSwtich,
	kDataBaseProData,
	kDataBolusProData,
	kDataDelayProData,
	
	//alarm
	kDataAlarmBlock,
	kDataAlarmFlag,
	kDataAlarmConfig,

	//fireware
	kDataFirmwareBlock,
	kDataFirmwareInfo,
	
	//system set
	kDataSystemSetBlock,
	kDataInfusionForce,
	kDataSerialNumber,
	kDataSoftwareVersion,
	kDataHardwareVersion,
	kDataFlashConfigFlag,
	
	//Calibration
	kDataCalibrationBlock,
	kDatabetteryOffset,
	kDataCalibrationInfo,

	//energy
	//kDataEnergyStardardBlock,  ///暂时无此功能


	kDataIDMax,
}DataID;


#ifdef __cplusplus
}
#endif




