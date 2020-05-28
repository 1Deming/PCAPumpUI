/************************************************
* DESCRIPTION:
*   sst26 is a norflash, it has below speciality:
*   More than 100,000 erase/program cycles
*   More than 100-year data retention
*
*   Program unit:
*   Page   - 256bytes
*
*   Erase unit:
*   Sector - 4K
*   Block  - 8K,32K,64K
*   Chip   - all   
*   
*   SST26VF064B :
*		Flash size: 8Mbyte 
*
************************************************/
#pragma once
#include "ssz_file.h"
#include "nrf_log.h"

/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif

//
//#ifdef SST25_VF010
//
//#define SST25_FLASH_SIZE (128*1024)
//#define SST25_FLASH_ID 0xBF49 
//
//#elif defined SST25_VF020
//
//#define SST25_FLASH_SIZE (256*1024)
//#define SST25_FLASH_ID 0xBF8C
//#define SST25_FLASH_JEDEC_ID 0xBF258C
//
//#elif defined SST25_VF016
//
//#define SST25_FLASH_SIZE (16*1024*1024)
//#define SST25_FLASH_JEDEC_ID 0xBF2541
//
//#elif defined SST26_VF064

#define SST26_FLASH_SIZE (8*1024*1024)
#define SST26_FLASH_JEDEC_ID 0xBF2643

//#else
//#error "not define flash type"
//
//#endif

#define SST26_FLASH_SPI  hspi3

#define SST26_FLASH_PAGE_PROGRAM_UNIT_SIZE  (256)
#define SST26_FLASH_ERASE_UNIT_SIZE		   (4*1024)

#if FLASH_ERASE_UNIT_SIZE>0 && FLASH_ERASE_UNIT_SIZE!=SST26_FLASH_ERASE_UNIT_SIZE
#error "the defined flash erase unit size is not same as this device's erase unit size"
#endif

//#define SST25_FLASH_CS_PORT  FLASH_NSS_GPIO_Port	 	
//#define SST25_FLASH_CS_PIN   FLASH_NSS_Pin		 

 
bool drv_sst26_flash_init(void);
void drv_sst26_pwr_enable(void);

//read status register, param can be:sst26_FLASH_STATUS1,sst26_FLASH_STATUS2,sst26_FLASH_STATUS3
uint8_t drv_sst26_flash_read_status(uint8_t status_code);

//check is busy
bool drv_sst26_flash_is_busy();

bool drv_sst26_flash_read(int32_t address, void *buff, int need_read_size);
bool drv_sst26_flash_write_at_one_page(int32_t address, uint8_t *buff, int buffer_len);
//Note: you must ensure the destion's data is already erased or will not success
bool drv_sst26_flash_write(int32_t address, const void *buff, int buffer_len);

//erase one unit, the address must be address%sst26_FLASH_ERASE_UNIT_SIZE==0
void drv_sst26_flash_erase_one_unit(int32_t address);

//Note: it will cost about 8(for W25Q32FV) seconds, 
//so after call it, please wait for xx seconds to  continue operation this flash
void drv_sst26_flash_erase_chip(void);

//read the JEDEC ID of the flash
uint32_t drv_sst26_flash_read_jedec(void);

void drv_sst26_flash_wait_idle(void);

//enable sst26 power supply from system power supply 
void drv_sst26_pwr_enable(void);

//disable sst26 power supply from system power supply
void drv_sst26_pwr_disable(void);

//return ssz file
SszFile* drv_sst26_flash_file();

#ifdef __cplusplus
}
#endif


