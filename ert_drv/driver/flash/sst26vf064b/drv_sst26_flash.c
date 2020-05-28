#include "drv_sst26_flash.h"
#include "ssz_spi.h"
#include "ssz_common.h"
#include "ssz_file.h"
#include "nrf_gpio.h"
#include "bsp_gpio.h"

/************************************************
* Declaration
************************************************/


//commands which flash supports
//read cmds
#define SST26_FLASH_READ_DATA_CMD	    0x03
#define SST26_FLASH_READ_STATUS_CMD     0x05
#define SST26_FLASH_READ_JEDEC_ID_CMD   0x9F
#define SST26_FLASH_READ_CONFIG_REG_CMD 0x35

//write cmds
#define SST26_FLASH_PAGE_PROGRAM_CMD	0x02 
#define SST26_FLASH_CHIP_ERASE_CMD		0xC7
#define SST26_FLASH_SECTOR_ERASE_CMD	0x20

#define SST26_FLASH_WRITE_ENABLE_CMD    0x06 
#define SST26_FLASH_WRITE_DISABLE_CMD   0x04
#define SST26_FLASH_WRITE_STATUS_REG	0x01
#define SST26_FLASH_WRITE_SUSPEND_CMD	0xB0
#define SST26_FLASH_WRITE_RESUME_CMD	0x30

//protection cmds
#define SST26_FLASH_READ_BLOCK_PROTECTION_CMD	    0x72
#define SST26_FLASH_WRITE_BLOCK_PROTECTION_CMD	    0x42
#define SST26_FLASH_LOCK_DOWN_BLOCK_PROTECTION_CMD	0x8D
#define SST26_FLASH_GLOBAL_BLOCK_PROTECTION_UNLOCK_CMD      0x98
#define SST26_FLASH_nvWRITE_LOCK_DOWN_BLOCK_PROTECTION_CMD  0xE8

#define M_drv_sst26_flash_is_Protected(status1) ( (((uint8_t)status1)&0x0C)==0 )  // ok ?
#define M_drv_sst26_flash_is_enable_write(status1) ((((uint8_t)status1)&0x02)!=0) // ok ?
#define M_drv_sst26_flash_is_busy(status1) ( (((uint8_t)status1)&0x01)==0x01 )  // ok ?
///////////////////////////////////////////////////////////////////////////
typedef struct {
	int32_t address;
}DrvSST25FlashDev;
uint8_t drv_sst26_flash_read_status(uint8_t status_code);
static void drv_sst26_flash_enable_write(void);
//static void drv_sst26_select_slave(bool is_select);
bool drv_sst26_flash_write_at_one_page(int32_t address, uint8_t *buff, int buffer_len);
extern const SszIODevice kDrvSST26FlashIODev;
/************************************************
* Variable
************************************************/
//static bool g_sst26_flash_is_need_check_busy = true;

//spi define
static SszSPI g_sst26_flash_spi;
static SszFile g_sst26_flash_spi_file_inter = {
	&kSszSPIIODev, &g_sst26_flash_spi
};
static SszFile *g_sst26_flash_spi_file = &g_sst26_flash_spi_file_inter;


//file define
static DrvSST25FlashDev g_sst26_flash_dev;
SszFile g_sst26_flash_file;

/************************************************
* Function
************************************************/	
//enable sst26 power supply from system power supply 
void drv_sst26_pwr_enable(void)
{
	bsp_gpio_output_clear(BATTERY_CURRENT_AND_FLASH_EN_PIN_NUM);
}

//disable sst26 power supply from system power supply
void drv_sst26_pwr_disable(void)
{
	bsp_gpio_output_set(BATTERY_CURRENT_AND_FLASH_EN_PIN_NUM);
}

void drv_sst26_hold_enable(void)
{
    //ssz_gpio_clear(FLASH_HOLD_GPIO_Port, FLASH_HOLD_Pin); 
    //HAL_GPIO_WritePin(FLASH_HOLD_GPIO_Port, FLASH_HOLD_Pin, GPIO_PIN_RESET); 
}

void drv_sst26_hold_disable(void)
{
 	//nrf_gpio_pin_set(FLASH_HOLD_PIN);
}

static void drv_sst26_flash_enable_cs(void)
{
 	bsp_gpio_output_clear(FLASH_SPI_NSS_PIN_NUM); 
}

static void drv_sst26_flash_disable_cs(void)
{
  	bsp_gpio_output_set(FLASH_SPI_NSS_PIN_NUM); 
}


static void drv_sst26_select_slave(bool is_select) {
	if (is_select) {
		drv_sst26_flash_enable_cs();
	}
	else {
		drv_sst26_flash_disable_cs();
	}
}

//read status register, param can be:SST26_FLASH_READ_STATUS_CMD
uint8_t drv_sst26_flash_read_status(uint8_t status_code)
{
	uint8_t status;

	drv_sst26_flash_enable_cs();

	ssz_fwrite(g_sst26_flash_spi_file, &status_code, 1);
	ssz_fread(g_sst26_flash_spi_file, &status, 1);

	drv_sst26_flash_disable_cs();
	//printf("0x%X status: 0x%X\n", status_code, status);
	return status;
}

//check if flash is busy
bool drv_sst26_flash_is_busy() {
#ifndef SSZ_TARGET_SIMULATOR
	return M_drv_sst26_flash_is_busy(drv_sst26_flash_read_status(SST26_FLASH_READ_STATUS_CMD));
#else
	return false;
#endif
}

//wait flash can accept command
void drv_sst26_flash_wait_idle(void)
{
	int retry = 0;
	uint8_t status1;
	do
	{

		status1 = drv_sst26_flash_read_status(SST26_FLASH_READ_STATUS_CMD);
        retry++;
		if (retry >= 30000) { // 30000
			ssz_trace("warn: flash busy long, status1[0x%x]\n", status1);
		}
	} while (M_drv_sst26_flash_is_busy(status1));
}

static void drv_sst26_flash_write_cmd(uint8_t cmd)
{
	drv_sst26_flash_wait_idle();

	drv_sst26_flash_enable_cs();
	ssz_fputc(g_sst26_flash_spi_file, cmd);
	//wait spi send finish
	ssz_fflush(g_sst26_flash_spi_file);	
 	drv_sst26_flash_disable_cs();
}

//this cmd must be executed before: erase, program, write block-protection register,
//write lock-down block-protection register, write non-volatile write-lock lock-down register,
//and write status register.
void drv_sst26_flash_enable_write(void)
{
    drv_sst26_flash_write_cmd(SST26_FLASH_WRITE_ENABLE_CMD);
}

void drv_sst26_flash_disable_write(void)
{
    drv_sst26_flash_write_cmd(SST26_FLASH_WRITE_DISABLE_CMD);
}
//used to suspend current program/erae operation
void drv_sst26_flash_write_suspend(void)
{
    drv_sst26_flash_write_cmd(SST26_FLASH_WRITE_SUSPEND_CMD);
}

//used to resume last program/erae operation that has been suspended
void drv_sst26_flash_write_resume(void)
{
    drv_sst26_flash_write_cmd(SST26_FLASH_WRITE_RESUME_CMD);
}

void drv_sst26_flash_lock_down_block_protection_reg(void)
{
    drv_sst26_flash_enable_write();
    drv_sst26_flash_write_cmd(SST26_FLASH_LOCK_DOWN_BLOCK_PROTECTION_CMD);
}

//clear all write-protection bits in block-protection register except those
//have been locked down with nvWLDR cmd.
void drv_sst26_flash_global_block_protection_unlock(void)
{
    drv_sst26_flash_enable_write();
    drv_sst26_flash_write_cmd(SST26_FLASH_GLOBAL_BLOCK_PROTECTION_UNLOCK_CMD);
}

/***********************************************
* Description:
*   read some data
*
* Argument:
*   address:
*   buff:
*   need_read_size:
*
* Return:
*   is ok
************************************************/
bool drv_sst26_flash_read(int32_t address, void *buff, int need_read_size)
{
	bool is_ok = true;
	int i ;
	ssz_assert(address >= 0 && address + need_read_size <= SST26_FLASH_SIZE);

 	drv_sst26_flash_wait_idle();
	drv_sst26_flash_enable_cs();

	ssz_fputc(g_sst26_flash_spi_file, SST26_FLASH_READ_DATA_CMD);
	//write 24bit address
	ssz_fputc(g_sst26_flash_spi_file, (uint8_t)(((uint32_t)address) >> 16));
	ssz_fputc(g_sst26_flash_spi_file, (uint8_t)(((uint32_t)address) >> 8));
	ssz_fputc(g_sst26_flash_spi_file, (uint8_t)(((uint32_t)address)));
	//read data
	//is_ok = ssz_is_result_ok(ssz_fread(g_sst26_flash_spi_file, buff, need_read_size));
	for (i = 0; i < need_read_size; i++)
		{
	  	 	*((uint8_t*)buff + i) = ssz_fgetc(g_sst26_flash_spi_file); 		
		}	

	drv_sst26_flash_disable_cs();

	return is_ok;
}

//page program, each page has 256 bytes
bool drv_sst26_flash_write_at_one_page(int32_t address, uint8_t *buff, int buffer_len)
{
	bool is_ok = true;
    //int i ;
	ssz_assert(address >= 0 && address + buffer_len <= SST26_FLASH_SIZE
		&& address%SST26_FLASH_PAGE_PROGRAM_UNIT_SIZE + buffer_len <= SST26_FLASH_PAGE_PROGRAM_UNIT_SIZE);


    drv_sst26_flash_wait_idle();
    drv_sst26_flash_enable_write();

#ifdef SSZ_TARGET_MACHINE
    ssz_assert(M_drv_sst26_flash_is_enable_write(drv_sst26_flash_read_status(SST26_FLASH_READ_STATUS_CMD)));
#endif	

    drv_sst26_flash_enable_cs();  
    ssz_fputc(g_sst26_flash_spi_file, SST26_FLASH_PAGE_PROGRAM_CMD);
    //write 24bit address
    ssz_fputc(g_sst26_flash_spi_file, (uint8_t)(((uint32_t)address) >> 16));
    ssz_fputc(g_sst26_flash_spi_file, (uint8_t)(((uint32_t)address) >> 8));
    ssz_fputc(g_sst26_flash_spi_file, (uint8_t)(((uint32_t)address)));

    for (int i = 0; i < buffer_len; i++){
        //drv_sst26_flash_wait_idle();
        ssz_fputc(g_sst26_flash_spi_file, buff[i]);
    }           

    drv_sst26_flash_disable_cs();

	return is_ok;
}
 
/***********************************************
* Description:
*   write data, Note: you must ensure the destion's data is already erased or will not success
* Argument:
*   address:
*   buff:
*   buffer_len:
*
* Return:
************************************************/
bool drv_sst26_flash_write(int32_t address, const void *buff, int buffer_len)
{
	int write_bytes_count = 0;	//	record the write bytes count
	int once_write_count;		//	once write bytes count at one page

	ssz_assert(address >= 0 && address + buffer_len <= SST26_FLASH_SIZE);

	while (write_bytes_count < buffer_len)
	{
		//get once write bytes count
		once_write_count = buffer_len - write_bytes_count;
		//write finish, break
		if (once_write_count <= 0)
		{
			break;
		}
		//if once write count overstep one page, reset it
		if ((address + write_bytes_count) % SST26_FLASH_PAGE_PROGRAM_UNIT_SIZE + once_write_count>SST26_FLASH_PAGE_PROGRAM_UNIT_SIZE)
		{                     
			once_write_count = SST26_FLASH_PAGE_PROGRAM_UNIT_SIZE - (address + write_bytes_count) % SST26_FLASH_PAGE_PROGRAM_UNIT_SIZE;
		}
		//write at one page
		drv_sst26_flash_write_at_one_page(address + write_bytes_count, (uint8_t*)buff + write_bytes_count, once_write_count);
		write_bytes_count += once_write_count;
	}

	return true;
}

/***********************************************
* Description:
*   erase one unit, the address must be address%SST26_FLASH_ERASE_UNIT_SIZE==0
* Argument:
*   address:
*
* Return:
*
************************************************/
void drv_sst26_flash_erase_one_unit(int32_t address)
{
	ssz_assert(address >= 0 && address<SST26_FLASH_SIZE
		&& address%SST26_FLASH_ERASE_UNIT_SIZE == 0);

	drv_sst26_flash_enable_write();
	drv_sst26_flash_wait_idle();
	ssz_assert(M_drv_sst26_flash_is_enable_write(drv_sst26_flash_read_status(SST26_FLASH_READ_STATUS_CMD)));
	drv_sst26_flash_enable_cs();

	ssz_fputc(g_sst26_flash_spi_file, SST26_FLASH_SECTOR_ERASE_CMD);
	//write 24bit address
	ssz_fputc(g_sst26_flash_spi_file, (uint8_t)(((uint32_t)address) >> 16));
	ssz_fputc(g_sst26_flash_spi_file, (uint8_t)(((uint32_t)address) >> 8));
	ssz_fputc(g_sst26_flash_spi_file, (uint8_t)(((uint32_t)address)));

	ssz_fflush(g_sst26_flash_spi_file);
	drv_sst26_flash_disable_cs();
}

/***********************************************
* Description:
*   erase chip, that mean all data at flash will be erased
* Argument:
*
* Return:
*
************************************************/
void drv_sst26_flash_erase_chip(void)
{
    drv_sst26_flash_wait_idle();
	drv_sst26_flash_enable_write();
	ssz_assert(M_drv_sst26_flash_is_enable_write(drv_sst26_flash_read_status(SST26_FLASH_READ_STATUS_CMD)));
	drv_sst26_flash_enable_cs();

	ssz_fputc(g_sst26_flash_spi_file, SST26_FLASH_CHIP_ERASE_CMD);

	ssz_fflush(g_sst26_flash_spi_file);
   	drv_sst26_flash_disable_cs(); 
}

/***********************************************
* Description:
*   read the JEDEC ID of the flash
*   the four byte is: dummy,manufacturer ID, Memory Type, Memory Capacity
* Argument:
*
* Return:
*
************************************************/
uint32_t drv_sst26_flash_read_jedec(void)
{
	uint32_t id = 0;

	drv_sst26_flash_wait_idle();
	drv_sst26_flash_enable_cs();

	ssz_fputc(g_sst26_flash_spi_file, SST26_FLASH_READ_JEDEC_ID_CMD);
	id += ssz_fgetc(g_sst26_flash_spi_file);//manufacturer ID
	id <<= 8;
	id += ssz_fgetc(g_sst26_flash_spi_file);//Memory Type
	id <<= 8;
	id += ssz_fgetc(g_sst26_flash_spi_file);//Memory Capacity

	drv_sst26_flash_disable_cs();

	return id;
}

bool drv_sst26_flash_init(void)
{
	uint32_t jedec_id;
    //static uint8_t       buf[10];
 
	//drv_sst26_hold_disable();
    drv_sst26_pwr_enable();
    
    
	ssz_spi_init(&g_sst26_flash_spi, NULL, NULL);
	ssz_file_init(&g_sst26_flash_file, &kDrvSST26FlashIODev, &g_sst26_flash_dev);
    drv_sst26_flash_global_block_protection_unlock();

    jedec_id = drv_sst26_flash_read_jedec();

	if (jedec_id == SST26_FLASH_JEDEC_ID)
	{
		ssz_traceln("Flash JEDEC_ID[0x%x]", jedec_id);
        //NRF_LOG_HEXDUMP_INFO(&jedec_id, sizeof(jedec_id));
        //memcpy(buf, &jedec_id,  sizeof(jedec_id));
        //NRF_LOG_HEXDUMP_INFO(buf, strlen((const char *)buf));
        NRF_LOG_INFO("Flash JEDEC_ID[0x%x]:", jedec_id);
		return true;
	}
	else
	{
		//ssz_traceln("Flash JEDEC_ID[0x%x] is wrong", jedec_id);
		return false;
	}
}

//IO define
static int drv_sst26_flash_file_read(struct ssz_file_t* file, void* buff, int buff_size, int* real_read_buff_size) {
	DrvSST25FlashDev* dev = file->dev_data;

	if (drv_sst26_flash_read(dev->address, buff, buff_size)) {
		if (real_read_buff_size)*real_read_buff_size = buff_size;
		return kSuccess;
	}
	else
	{
		if (real_read_buff_size)*real_read_buff_size = 0;
		return kError;
	}
}
static int drv_sst26_flash_file_write(struct ssz_file_t* file, const void* buff, int buff_size, int* real_write_buff_size) {
	DrvSST25FlashDev* dev = file->dev_data;

	if (drv_sst26_flash_write(dev->address, buff, buff_size)) {
		if (real_write_buff_size)*real_write_buff_size = buff_size;
		return kSuccess;
	}
	else {
		if (real_write_buff_size)*real_write_buff_size = 0;
		return kError;
	}
}
static int drv_sst26_flash_file_ctl(struct ssz_file_t* file, int command, void* param) {
	int ret = kSuccess;
	DrvSST25FlashDev* dev = file->dev_data;
	switch (command) {
	case SSZ_IOCTL_ERASE_ONE_UNIT:
		ssz_assert(param);
		drv_sst26_flash_erase_one_unit(*(int32_t*)param);
		break;
	case SSZ_IOCTL_SEEK:
		ssz_assert(param);
		dev->address = *(int32_t*)param;
		break;
	case SSZ_IOCTL_IS_SUPPORT_ERASE:
		ssz_assert(param);
		*(int*)param = 1;
		break;
	case SSZ_IOCTL_IS_NEED_ERASE_BEFORE_WRITE:
		ssz_assert(param);
		*(int*)param = 1;
		break;
	case SSZ_IOCTL_ERASE_UNIT_SIZE:
		ssz_assert(param);
		*(int*)param = SST26_FLASH_ERASE_UNIT_SIZE;
		break;
	case SSZ_IOCTL_SIZE:
		ssz_assert(param);
		(*(int32_t*)param) = SST26_FLASH_SIZE;
		break;
	case SSZ_IOCTL_CURR_POS:
		ssz_assert(param);
		(*(int32_t*)param) = dev->address;
		break;
	default:
		ret = kNotSupport;
		break;
	}
	return ret;
}
//io dev
const SszIODevice kDrvSST26FlashIODev = {
	"flash",
	drv_sst26_flash_file_read,
	drv_sst26_flash_file_write,
	drv_sst26_flash_file_ctl,
};

//return ssz file
SszFile* drv_sst26_flash_file() {
	return &g_sst26_flash_file;
}

