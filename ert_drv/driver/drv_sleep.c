/************************************************
* DESCRIPTION:
*
*
*
************************************************/
#include "drv_sleep.h"
#include "drv_adc.h"
#include "bsp_gpio.h"
#include "bsp_uart.h"
#include "drv_motor.h"
#include "bsp_adc.h"
#include "bsp_timer.h"
#include "bsp_spi.h"
#include "bsp_ble.h"
#include "nrf_drv_gpiote.h"
#include "nrf_delay.h"

#include "nordic_common.h"
#include "nrf.h"
#include "nrf_log.h"
#include "app_error.h"
#include "nrf_pwr_mgmt.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
#include "nrfx_log.h"
#include "app_timer.h"
#include "drv_wdt.h"
#include "drv_sst26_flash.h"

/************************************************
* Declaration
************************************************/

/************************************************
* Variable 
************************************************/
bool g_drv_sleep_wakeup_by_key;
bool g_drv_sleep_wakeup_by_ble;
bool g_drv_sleep_wakeup_by_timer;

uint32_t g_drv_wakeup_timer_ticks_before_sleep;
uint32_t g_drv_wakeup_timer_ticks_after_sleep;


/************************************************
* Function 
************************************************/

//led
void drv_all_led_off(void)
{
	bsp_gpio_output_clear(LED_GREEN_PIN_NUM);
	bsp_gpio_output_clear(LED_BLUE_PIN_NUM);
	bsp_gpio_output_clear(LED_RED_PIN_NUM);
}
 
void drv_all_led_on( void)
{
	bsp_gpio_output_set(LED_GREEN_PIN_NUM);
	bsp_gpio_output_set(LED_BLUE_PIN_NUM);
	bsp_gpio_output_set(LED_RED_PIN_NUM);
} 


//GPIO
static void key_wakeup_event_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
	if(pin != KEY_PIN_NUM) return;
	g_drv_sleep_wakeup_by_key = true;
}

void drv_sleep_set_gpio_wakeup(void)
{
	uint32_t err_code;
	
	if (!nrf_drv_gpiote_is_init())
	{
		err_code = nrf_drv_gpiote_init();
		APP_ERROR_CHECK(err_code);
	}
	nrf_drv_gpiote_in_config_t config = GPIOTE_CONFIG_IN_SENSE_TOGGLE(false);
	config.sense = NRF_GPIOTE_POLARITY_HITOLO;
	// config.sense = NRF_GPIOTE_POLARITY_TOGGLE;
	//按键默认是高,如果使用以下的事件,会导致启用事件nrf_drv_gpiote_in_event_enable后马上触发一个事件
	//即使这个事件已经处理了,后面的休眠也会失败,需要第二次休眠才成功
	// config.sense = NRF_GPIOTE_POLARITY_LOTOHI;
	config.pull = NRF_GPIO_PIN_PULLUP;
	err_code = nrf_drv_gpiote_in_init(KEY_PIN_NUM, &config, key_wakeup_event_handler);
	APP_ERROR_CHECK(err_code);
	nrf_drv_gpiote_in_event_enable(KEY_PIN_NUM, true);
}

bool ERT_drv_sleep_get_wakeup_by_key_flag(void)
{
	return g_drv_sleep_wakeup_by_key;
}

bool ERT_drv_sleep_get_wakeup_by_ble_flag(void)
{
	return g_drv_sleep_wakeup_by_ble;
}

bool ERT_drv_sleep_get_wakeup_by_timer_flag(void)
{
	return g_drv_sleep_wakeup_by_timer;
}


//从CPU休眠指令
void drv_sleep_slaver(void)
{
	uint8_t sleep_cmd = 0x40;
	ERT_drv_uart_send(&sleep_cmd, 1);
}

void drv_wakeup_slaver(void)
{
	uint32_t err_code;
	
	if (!nrf_drv_gpiote_is_init())
	{
		err_code = nrf_drv_gpiote_init();
		APP_ERROR_CHECK(err_code);
	}

	nrf_gpio_cfg_output(M_Pause_To_S_PIN_NUM);
	nrf_gpio_pin_set(SLAVER_NRST_PIN_NUM);
	nrf_delay_ms(50);
	nrf_gpio_pin_clear(SLAVER_NRST_PIN_NUM);
	nrf_delay_ms(50);
	nrf_gpio_pin_clear(SLAVER_NRST_PIN_NUM);
}

//PCB外设
void ERT_drv_sleep_pcb_peripheral_power_disable(  void )
{
	drv_sst26_pwr_disable();
	ERT_drv_adc_battery_current_disable();
	
}

void ERT_drv_sleep_pcb_peripheral_power_enable( void )
{
	drv_sst26_pwr_enable();
	ERT_drv_adc_battery_current_enable();
}


uint32_t ERT_drv_get_wakeup_timer_count_value(void)
{
	return app_timer_cnt_diff_compute(g_drv_wakeup_timer_ticks_after_sleep, 
		                              g_drv_wakeup_timer_ticks_before_sleep);
}

void ERT_drv_sleep_uart_and_adc_deinit(uint8_t uart_id)
{
	//bsp_adc_deinit();
	bsp_uart_deinit();
}

void ERT_drv_sleep_peripherals_except_uart_and_adc_deinit(void)
{
	g_drv_sleep_wakeup_by_ble = false;
	g_drv_sleep_wakeup_by_timer = false;  
  
	//drv_all_led_off();
	//drv_sleep_slaver();

    //timer在停止时会有SWI_IRQn事件,所以需要调用一次nrf_pwr_mgmt_run来清除这次事件
    bsp_timer_deinit();
    nrf_pwr_mgmt_run();

	bsp_gpio_deinit();
	drv_sleep_set_gpio_wakeup();
	g_drv_sleep_wakeup_by_key = false;
	//drv_sleep_slaver();
	//drv_motor_pwm_deinit();
	//drv_qdec_deinit();
	//bsp_adc_deinit();
	bsp_spi_deinit();
	//ERT_drv_feed_wdt();  //喂狗,防止重启
	ERT_drv_sleep_pcb_peripheral_power_disable();
}


//进入退出总函数
bool ERT_drv_sleep_enter_lpsleep(  uint32_t time_ms)
{

	//init wakeup timer
	bsp_wakeup_timer_init(time_ms);

	g_drv_wakeup_timer_ticks_before_sleep = app_timer_cnt_get();	
	printf("enter sleep mode \n");
    nrf_pwr_mgmt_run();
	nrf_pwr_mgmt_run();
	
	bsp_wakeup_timer_deinit();
	return 1;
}


void ERT_drv_sleep_exit_lpsleep( uint8_t uart_id )
{
  	printf("exit sleep \n");
	g_drv_wakeup_timer_ticks_after_sleep = app_timer_cnt_get();
	nrfx_gpiote_in_uninit(ssz_gpio_pin_mask_to_number(KEY_PIN_NUM));
	bsp_gpio_init();
	bsp_uart_init();
	//drv_wakeup_slaver();
	//bsp_wakeup_timer_deinit();
	bsp_timer_init();
	//ERT_drv_motor_enable();
	//ERT_drv_encode_init();
	//bsp_adc_init();
	bsp_spi_init();
	//ERT_drv_feed_wdt();  //喂狗,防止重启
	ERT_drv_sleep_pcb_peripheral_power_enable();
}



bool ert_ioCtrl(bool data)
{
	if(data == true)
	{
		ERT_drv_sleep_uart_and_adc_deinit(1);
		ERT_drv_sleep_peripherals_except_uart_and_adc_deinit();
	}
	else if(data == false)
	{
		ERT_drv_sleep_exit_lpsleep(1);
	}
}


bool ert_lpCtrl(bool data, uint32_t *SleepSpe)
{
	if(data == true)
	{
		ERT_drv_sleep_enter_lpsleep(*SleepSpe);
	}
	else if(data == false)
	{	
		*SleepSpe = ERT_drv_get_wakeup_timer_count_value();

		//返回值为：是否被三种中断唤醒                 如果被三种唤醒，*SleepSpe：返回时间。
		
	}
        
        return true;
}

























