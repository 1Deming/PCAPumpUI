/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "ert_getKeyVector.h"
#include "drv_key.h"
#include "string.h"
/************************************************
* Declaration
************************************************/

/************************************************
* Variable 
************************************************/


/************************************************
* Function 
************************************************/
void ert_getKeyVector(uint8_t *data)
{
	//kKeyLeft,
	//kKeyRight,
	//kKeyOK,
	//kKeyBack,
	//kKeyStart,
    int8_t key_states[kKeyIDMax];
	drv_key_scan(key_states);
	memcpy(data, key_states, kKeyIDMax);
}



