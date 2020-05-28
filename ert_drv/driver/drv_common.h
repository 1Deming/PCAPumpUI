/************************************************
* DESCRIPTION:
*
*
************************************************/
#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif


/** @brief Enumerated type for error codes. */
typedef enum {
    kDrvErrorCode_SUCCESS              = (0),  ///< Operation performed successfully.
    kDrvErrorCode_INTERNAL             = (1),  ///< Internal error.
    kDrvErrorCode_NO_MEM               = (2),  ///< No memory for operation.
    kDrvErrorCode_NOT_SUPPORTED        = (3),  ///< Not supported.
    kDrvErrorCode_INVALID_PARAM        = (4),  ///< Invalid parameter.
    kDrvErrorCode_INVALID_STATE        = (5),  ///< Invalid state, operation disallowed in this state.
    kDrvErrorCode_INVALID_LENGTH       = (6),  ///< Invalid length.
    kDrvErrorCode_TIMEOUT              = (7),  ///< Operation timed out.
    kDrvErrorCode_FORBIDDEN            = (8),  ///< Operation is forbidden.
    kDrvErrorCode_NULL                 = (9),  ///< Null pointer.
    kDrvErrorCode_INVALID_ADDR         = (10), ///< Bad memory address.
    kDrvErrorCode_BUSY                 = (11), ///< Busy.
    kDrvErrorCode_ALREADY_INITIALIZED  = (12), ///< Module already initialized.
    kDrvErrorCode_UNKOWN_ERROR		   = (0xFFFF), ///< unkown error
    kDrvErrorCodeIDMAX,
}DrvErrorCode;

DrvErrorCode drv_common_get_error_code(uint32_t error_code);
void ERT_drv_common_memcpy(void *destin, void* scr, uint32_t size);
uint16_t ERT_drv_common_Combination_two_byte(uint8_t data1, uint8_t data2);
uint32_t ERT_drv_common_Combination_four_byte(uint8_t data1, uint8_t data2, uint8_t data3, uint8_t data4);
uint32_t ERT_drv_common_crc32(const void *p_buffer, int buffer_len);
uint32_t ERT_drv_common_crc32_ex(const void *p_buffer, int buffer_len, uint32_t seed);

void ERT_drv_common_split_u16(uint16_t source_data, uint8_t *high_data, uint8_t *low_data);





#ifdef __cplusplus
}
#endif

