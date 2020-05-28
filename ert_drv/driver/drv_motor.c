#include "nrf_drv_qdec.h"
#include "nrf_drv_pwm.h"
#include "drv_motor.h"
#include "bsp_gpio.h"

#include "drv_common.h"

#include "nordic_common.h"
#include "nrf.h"
#include "nrf_log.h"
#include "app_error.h"
#include "app_timer.h"

#include "nrf_gpio.h"
#include "nrf_gpiote.h"
#include "nrf_drv_gpiote.h"
#include "ssz_tick_time.h"

#include "timer.h"
#include "timer_config.h"

/************************************************
* Declaration
************************************************/


/************************************************
* Variable 
************************************************/
static nrf_drv_pwm_t pwm_motor = NRF_DRV_PWM_INSTANCE(0);

static nrf_drv_pwm_config_t pwm_config = {
    .output_pins  = {
        NRFX_PWM_DEFAULT_CONFIG_OUT0_PIN,
        NRFX_PWM_DEFAULT_CONFIG_OUT1_PIN,
        NRF_DRV_PWM_PIN_NOT_USED,
        NRF_DRV_PWM_PIN_NOT_USED
    },
    .irq_priority = NRFX_PWM_DEFAULT_CONFIG_IRQ_PRIORITY,
    .base_clock   = (nrf_pwm_clk_t)3,//NRFX_PWM_DEFAULT_CONFIG_BASE_CLOCK,
    .count_mode   = (nrf_pwm_mode_t)NRFX_PWM_DEFAULT_CONFIG_COUNT_MODE,
    .top_value    = NRFX_PWM_DEFAULT_CONFIG_TOP_VALUE,
    .load_mode    = (nrf_pwm_dec_load_t)NRFX_PWM_DEFAULT_CONFIG_LOAD_MODE,
    .step_mode    = (nrf_pwm_dec_step_t)NRFX_PWM_DEFAULT_CONFIG_STEP_MODE
};

static nrf_pwm_values_individual_t pwm_values = {
    0, 0, 0, 0
};

static nrf_pwm_sequence_t pwm_seq = {
    .values.p_individual = &pwm_values,
    .length              = NRF_PWM_VALUES_LENGTH(pwm_values),
    .repeats             = 0,
    .end_delay           = 0
};

static uint8_t g_drv_motor_move_dir;
static uint32_t g_drv_motor_encode;
//static uint32_t g_motor_dir_error_count;

uint32_t g_drv_ecnode_obj;

uint32_t g_drv_encode_time;

/************************************************
* Function 
************************************************/

//get encode by gpio intrrupt
static void motor_gpiote_event_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{  
	if((pin == MOTOR_QDEC_CONFIG_PIO_A) && (action == NRF_GPIOTE_POLARITY_HITOLO))
	{
		g_drv_motor_encode++;
        //if(g_drv_motor_encode > g_drv_ecnode_obj)
       // {
  	//		ert_pwmTrans(0, 100, NULL, NULL);
	//		//ERT_drv_motor_disable();              
         //    ert_chkDoseEnds(&g_drv_encode_time); 
        //     g_drv_motor_move_dir = 0; 
        //}
	}
}

int8_t ERT_drv_set_motor_hall_pin(void)
{
    uint32_t err_code;

	//HALL B
    nrf_gpio_cfg_input(MOTOR_QDEC_CONFIG_PIO_B, NRF_GPIO_PIN_NOPULL);

	//HALL A
    nrf_drv_gpiote_in_config_t config = NRFX_GPIOTE_CONFIG_IN_SENSE_HITOLO(false);//NRFX_GPIOTE_CONFIG_IN_SENSE_LOTOHI(false);  
	//config.pull = NRF_GPIO_PIN_PULLDOWN;
	err_code = nrf_drv_gpiote_in_init(MOTOR_QDEC_CONFIG_PIO_A, &config, motor_gpiote_event_handler);
    APP_ERROR_CHECK(err_code);
    nrf_drv_gpiote_in_event_enable(MOTOR_QDEC_CONFIG_PIO_A, true);

    return kDrvErrorCode_SUCCESS;//(int8_t)drv_common_get_error_code(err_code);
}



void drv_motor_pwr_enable(void)
{
	bsp_gpio_output_set(MOTOR_PWR_EN_PIN_NUM);
}

void drv_motor_pwr_disable(void)
{
	bsp_gpio_output_clear(MOTOR_PWR_EN_PIN_NUM);
}

int8_t ERT_drv_motor_enable(void)
{
    ret_code_t err_code;

    err_code = nrf_drv_pwm_init(&pwm_motor, &pwm_config, NULL);
    if (err_code != NRFX_SUCCESS)
        return drv_common_get_error_code(err_code);

	drv_motor_pwr_enable();
	return 0;
}

void ERT_drv_motor_disable(void)
{
	//nrf_drv_pwm_uninit(&pwm_motor);
	drv_motor_pwr_disable();
}

void ERT_drv_motor_move(int8_t duty_cycle)
{
    if (duty_cycle < -100 || duty_cycle > 100)
        return;

    nrf_drv_pwm_stop(&pwm_motor, true);

    if (duty_cycle > 0) {
        pwm_values.channel_0 = pwm_config.top_value / 100 * duty_cycle;
        pwm_values.channel_1 = 0;
		g_drv_motor_move_dir = kForward;
    } else if (duty_cycle < 0) {
        pwm_values.channel_0 = 0;
        pwm_values.channel_1 = pwm_config.top_value / 100 * (-duty_cycle);
		g_drv_motor_move_dir = kBackward;
    } else {
        pwm_values.channel_0 = pwm_config.top_value;
        pwm_values.channel_1 = pwm_config.top_value;
    }

    nrf_drv_pwm_simple_playback(&pwm_motor, &pwm_seq, 1, NRF_DRV_PWM_FLAG_LOOP);
}



int8_t ERT_drv_encode_init(void)
{
    ERT_drv_set_motor_hall_pin();
    return 0;
}

void ERT_drv_encode_clear(void)
{
	g_drv_motor_encode = 0;
}

int32_t ERT_drv_encode_get(void)
{
    return g_drv_motor_encode;
}


void ert_pwmTrans(int16_t data, uint16_t fullscale, uint8_t *percent, 
                       bool *direction)
{
	uint8_t temp = (data>0)?(data*100/fullscale):(-1*data*100/fullscale);	
	int8_t duty;
	
	*percent = temp;
	*direction = (data>0)?true:false;

	if(*direction == true)
	{
		duty = temp;
	}
	else
	{
		duty = -temp;
	}

	//ERT_drv_motor_enable();
	ERT_drv_motor_move(duty);
	
}


uint32_t ert_encoderRead(bool data)
{
	if(data == false)
	{
		ERT_drv_encode_clear();
		return 0;
	}
	return ERT_drv_encode_get();
}

static uint32_t g_dose_time;
void ert_doseTimerStart(uint32_t data)
{
	g_dose_time = ssz_tick_time_now();
}


void ert_chkDoseEnds(uint32_t *data)
{
	*data = ssz_tick_time_elapsed(g_dose_time);
}











































/*
static volatile int32_t qdec_acc        = 0;

static nrf_drv_qdec_config_t qdec_config = {
    .reportper          = (nrf_qdec_reportper_t)NRFX_QDEC_CONFIG_REPORTPER,
    .sampleper          = (nrf_qdec_sampleper_t)NRFX_QDEC_CONFIG_SAMPLEPER,
    .psela              = NRFX_QDEC_CONFIG_PIO_A,
    .pselb              = NRFX_QDEC_CONFIG_PIO_B,
    .pselled            = 0xFFFFFFFF, //NRFX_QDEC_CONFIG_PIO_LED
    .ledpre             = NRFX_QDEC_CONFIG_LEDPRE,
    .ledpol             = (nrf_qdec_ledpol_t)NRFX_QDEC_CONFIG_LEDPOL,
    .interrupt_priority = NRFX_QDEC_CONFIG_IRQ_PRIORITY,
    .dbfen              = NRFX_QDEC_CONFIG_DBFEN,
    .sample_inten       = NRFX_QDEC_CONFIG_SAMPLE_INTEN
};




static void qdec_handler(nrf_drv_qdec_event_t event)
{
    if (event.type == NRF_QDEC_EVENT_REPORTRDY) {
        qdec_acc += event.data.report.acc;
    }
}

int8_t ERT_drv_encode_init(void)
{
    ret_code_t err_code;
	ERT_drv_motor_pwr_enable();
    err_code = nrf_drv_qdec_init(&qdec_config, qdec_handler);
    if (err_code != NRFX_SUCCESS)
        return (int8_t)drv_common_get_error_code(err_code);

    nrf_drv_qdec_enable();

	return (int8_t)drv_common_get_error_code(err_code);
}


void ERT_drv_encode_clear(void)
{
    int16_t acc, accdbl;

    //accumulators will be cleared after reading 
    nrf_drv_qdec_accumulators_read(&acc, &accdbl);

    qdec_acc = 0;
}

int32_t ERT_drv_encode_get(void)
{
    return qdec_acc;
}

void drv_qdec_deinit(void)
{
	nrf_drv_qdec_uninit();
}


*/



