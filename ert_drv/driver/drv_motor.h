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

typedef enum
{
    kForward,
    kBackward
}MotorDirection;

typedef enum
{
    kMotorStop,
    kMotorRun,
    kMotorStateMax
}MotorState;




extern int8_t ERT_drv_encode_init(void);
extern int8_t ERT_drv_motor_enable(void);
extern void ERT_drv_motor_disable(void);
extern void ERT_drv_motor_move(int8_t duty_cycle);
extern void ERT_drv_encode_clear(void);
extern int32_t ERT_drv_encode_get(void);

void ERT_drv_motor_pwr_enable(void);
void ERT_drv_motor_pwr_disable(void);


void drv_motor_pwm_deinit(void);
void drv_qdec_deinit(void);




void ert_pwmTrans(int16_t data, uint16_t fullscale, uint8_t *percent, bool *direction);
uint32_t ert_encoderRead(bool data);
void ert_doseTimerStart(uint32_t data);
void ert_chkDoseEnds(uint32_t *data);































#ifdef __cplusplus
}
#endif

