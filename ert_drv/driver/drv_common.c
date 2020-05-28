/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "drv_common.h"
#include <string.h>
#include "ssz_algorithm.h"
#include "drv_common.h"


/************************************************
* Declaration
************************************************/

/************************************************
* Variable 
************************************************/

/************************************************
* Function 
************************************************/
void ERT_drv_common_memcpy(void *destin, void* scr, uint32_t size)
{	
	memcpy(destin, scr, size);
}


void ERT_drv_common_split_u16(uint16_t source_data, uint8_t *high_data, uint8_t *low_data)
{
	*high_data = (source_data>>8)&0xFF;
	*low_data = (source_data&0xFF);
}

uint16_t ERT_drv_common_Combination_two_byte(uint8_t data1, uint8_t data2)
{
	return (uint16_t)((data1<<8)|data2);
}

uint32_t ERT_drv_common_Combination_four_byte(uint8_t data1, uint8_t data2, uint8_t data3, uint8_t data4)
{
	return (uint32_t)((data1<<24)|(data2<<16)|(data3<<8)|data4);
}

uint32_t ERT_drv_common_crc32(const void *p_buffer, int buffer_len)
{
	return ssz_crc32(p_buffer, buffer_len);
}

//uint32_t ssz_crc32_ex(const void *p_buffer, int buffer_len, uint32_t seed)

uint32_t ERT_drv_common_crc32_ex(const void *p_buffer, int buffer_len, uint32_t seed)
{
	return ssz_crc32_ex(p_buffer, buffer_len, seed);
}


DrvErrorCode drv_common_get_error_code(uint32_t error_code)
{
	return (DrvErrorCode)(((error_code & 0xFFFF)<=kDrvErrorCode_ALREADY_INITIALIZED)?(error_code & 0xFF):kDrvErrorCode_UNKOWN_ERROR);
}

