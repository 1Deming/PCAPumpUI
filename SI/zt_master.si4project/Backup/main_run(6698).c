#include "config.h"
#include "init.h"
#include "version.h"
#include "event.h"
#include "ssz_common.h"
#include "com.h"
#include "timer.h"
#include "cpu_usage.h"
#include "sys_power.h"
#include "app_mcu_comm.h"
#include "mid_common.h"

#include "GUI.h"
#include "WM.h"

#include "ert_RTC.h"
#include "ert_channelsADC_Major.h"
#include "ert_getKeyVector.h"

#include "string_data.h"
#include "font_data.h"
#include "image_data.h"


#include "app_route.h"
#include "uiDisp.h"

/************************************************
* Declaration
************************************************/
extern void do_before_main_loop();
extern void run_test_after_main();

/************************************************
* Variable 
************************************************/

/************************************************
* Function 
************************************************/
static void main_handle_pc_uart_recv()
{
	com_handle_new_received_data(kComPCUart);
}
static void main_handle_bt_uart_recv()
{
	com_handle_new_received_data(kComBTUart);
}
static void main_handle_mcu_uart_recv()
{
	com_handle_new_received_data(kComMCUUart);
}


static void main_init_event_handler() {
	event_set_handler(kEventNewTick, timer_handle_all);
	event_set_handler(kEventPCUartReceiveNewData, main_handle_pc_uart_recv);
    event_set_handler(kEventBTUartReceiveNewData, main_handle_bt_uart_recv);
    event_set_handler(kEventMCUUartReceiveNewData, main_handle_mcu_uart_recv);
}

/***********************************************
* Description:
*   handle all(e.g. event, timer, data receive...)
* Argument:
*
* Return:
*   if not handle anything, return false, otherwise return true
************************************************/
bool main_handle_all(void)
{
	bool ret = false;

	
	for (int i = 0; i < kEventIDMax; i++)
	{
		if (event_is_set((EventID)i))
		{
			event_clear((EventID)i);
			event_handle((EventID)i);
			ret = true;
		}
	}

	return ret;
}

#ifdef TEST
void run_unit_test(){
	extern int run_test_main(int argc, const char **argv);
	
	sys_power_enable();
	app_mcu_send_to_slave(COMM_POWER_ON,0,0);
	
	char *args[] = {
		"-t","data_write",	//-t casename, run the case who's name have the substr
		"-s","",  //-s suitename, run the suite who's name have the substr
		//"-a",  //-a - when test fail, assert to let user debug
		//"-v",  //-v - Verbose output
		//"-l",  //-l - List suites and their tests, then exit
	};
	run_test_main(ssz_array_size(args), (const char **)args);
	msg_clear_all_handler();
	//wait cmd
	while (1)
	{
		//handle all
		if (main_handle_all() == false)
		{
			//if nothing need handle, go to sleep
			ssz_sleep();
		}
		//clear watchdog
	}
	return;

}
#endif


void wm_bk_callback(WM_MESSAGE *pMsg)
{
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
			//WINDOW_SetBkColor(pMsg->hWin, GUI_WHITE);
            GUI_Clear();
			break;

		default:
			WM_DefaultProc(pMsg);
			break;

	}
}

static uint8_t data , index;
void test(void)
{
	type_MsgBody4UICtrlMsg disp_msg;
	const ScreenInfo *sptr;
	data = (data + 1) % 9;
	index = (index +1)%6;
	sptr = (const ScreenInfo *)&g_scr_routes[23];


	
	memcpy(disp_msg.UIID, sptr->screen_id, 5);
	disp_msg.CursorIndex = index;
	disp_msg.OpMethod = SCR_VALUE_ALTER;
	disp_msg.DItem[0] = data;
	ert_uiDisp(SCR_VALUE_ALTER, &disp_msg);
}

/***********************************************
* Description:
*   main 
*
* Argument:
*
* Return:
*
************************************************/

extern void test2_SysIntegration_initialize(void);
extern void test2_SysIntegration_step(void);

void main_run(void)
{
    //init all modules
	init_all();
	//init event handler
	main_init_event_handler();

	ssz_traceln("%s power on.", version_software_name());
#ifdef TEST
	run_unit_test();
#endif

	//do after init, before enter main loop
	do_before_main_loop();

	//run test something at once
	run_test_after_main();

#if CPU_USAGE_MODULE_ENABLE
	cpu_usage_reset_usage();
#endif


	GUI_Init();
	GUI_UC_SetEncodeUTF8();
	GUI_SetBkColor(GUI_BLACK);
	WM_SetCallback(WM_HBKWIN, wm_bk_callback);
	GUI_SetColor(GUI_WHITE);
	
	timer_set_handler(kTimerTest, test);
	timer_start_periodic_every(kTimerTest, 1500);
	//test2_SysIntegration_initialize();

    while(1)
    {
		//handle all
		if (main_handle_all() == false)
		{
			//if nothing need handle, go to sleep
#if CPU_USAGE_MODULE_ENABLE
			cpu_usage_enter_idle();
#endif
			//ssz_sleep();
#if CPU_USAGE_MODULE_ENABLE
			cpu_usage_exit_idle();
			//cpu_usage_print_if_large_than(20);
#endif
		}
		//GUI_Delay(1);
		GUI_Exec();
		//test2_SysIntegration_step();
        //clear watchdog
		//ssz_clear_watchdog();
		
    }
}
