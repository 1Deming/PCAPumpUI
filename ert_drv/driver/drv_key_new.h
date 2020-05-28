/************************************************
* DESCRIPTION:
*
*
************************************************/
#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>


/************************************************
* Declaration
************************************************/
#ifdef __cplusplus
extern "C" {
#endif

typedef enum 
{
	kKeyMain  = 1,
	kKeyPlus  = 2,
	kKeyRedue = 3,
	kKeyIDMAX,
}keyID;


bool drv_get_key_status(keyID key_id);




#ifdef __cplusplus
}
#endif

