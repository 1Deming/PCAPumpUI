/************************************************
 * DESCRIPTION:
 *
 * 	route for screen show
 *
 ************************************************/
#include "app_route.h"
#include "config.h"
#include "screen_config.h"
#include "WM.h"



//#if SCREEN_MODULE_ENABLE
/************************************************
 * Declaration
 ************************************************/
typedef Screen* (*ScreenEnterFunc)(void);
typedef struct {
	ScreenID screen_id;
	ScreenEnterFunc enter_func;
} ScreenEnterInfo;


/************************************************
 * Variable
 ************************************************/
static const ScreenEnterInfo g_routes[] = {
    {kScreenNull, NULL},
};

const ScreenInfo g_scr_routes[35] = {

    {{3,4,9,0,0}, app_scr_alarm_set_enter_34900_create, app_scr_alarm_set_enter_34900_update,app_scr_alarm_set_enter_34900_destroy},   
	{{3,5,2,0,0}, app_scr_base_log_enter_35200_create, app_scr_base_log_enter_35200_update, app_scr_base_log_enter_35200_destroy},

	{{3,4,7,0,0}, app_scr_time_set_enter_34700_create, app_scr_time_set_enter_34700_update, app_scr_time_set_enter_34700_destroy},
    {{3,4,8,0,0}, app_scr_date_set_enter_34800_create, app_scr_date_set_enter_34800_update, app_scr_date_set_enter_34800_destroy},
    {{3,4,2,0,0}, app_scr_infusion_force_enter_34200_create, app_scr_infusion_force_enter_34200_update, app_scr_infusion_force_enter_34200_destroy},
    {{3,4,3,0,0}, app_scr_max_base_dose_enter_34300_create, app_scr_max_base_dose_enter_34300_update, app_scr_max_base_dose_enter_34300_destroy}, 	
    {{3,4,4,0,0}, app_scr_max_bolus_set_enter_34400_create, app_scr_max_bolus_set_enter_34400_update, app_scr_max_bolus_set_enter_34400_destroy},

	{{3,4,5,0,0}, app_scr_concentration_set_enter_34500_create, app_scr_concentration_set_enter_34500_update,app_scr_concentration_set_enter_34500_destroy},   
    {{3,4,6,0,0}, app_scr_remaining_dose_enter_34600_create, app_scr_remaining_dose_enter_34600_update, app_scr_remaining_dose_enter_34600_destroy},	
    {{3,1,1,0,0}, app_scr_switch_31100_create, app_scr_switch_31100_update, app_scr_switch_31100_destroy},
    {{3,1,0,0,0}, app_scr_switch_enter_31000_create, app_scr_switch_enter_31000_update, app_scr_switch_enter_31000_destroy},   
    {{3,2,0,0,0}, app_scr_opreate_enter_32000_create, app_scr_opreate_enter_32000_update, app_scr_opreate_enter_32000_destroy},

	{{3,2,1,0,0}, app_scr_opreate_locate_enter_32100_create, app_scr_opreate_locate_enter_32100_update, app_scr_opreate_locate_enter_32100_destroy},
	{{3,2,1,1,0}, app_scr_opreate_locateing_32110_enter, app_scr_opreate_locateing_32110_update, app_scr_opreate_locateing_32110_destroy},
    {{3,2,2,0,0}, app_scr_opreate_dose_enter_32200_create, app_scr_opreate_dose_enter_32200_update, app_scr_opreate_dose_enter_32200_destroy},
    {{3,2,2,1,0}, app_scr_opreate_dose_32210_create, app_scr_opreate_dose_32210_update, app_scr_opreate_dose_32210_destroy},
	{{3,2,3,0,0}, app_scr_opreate_exhaust_32300_create, app_scr_opreate_exhaust_32300_update, app_scr_opreate_exhaust_32300_destroy},

	{{3,2,3,1,0}, app_scr_opreate_exhaust_32310_create, app_scr_opreate_exhaust_32310_update, app_scr_opreate_exhaust_32310_destroy},
	{{3,3,0,0,0}, app_scr_infusion_set_enter_33000_create, app_scr_infusion_set_enter_33000_update, app_scr_infusion_set_enter_33000_destroy},
    {{3,3,1,0,0}, app_scr_base_set_enter_33100_create, app_scr_base_set_enter_33100_update, app_scr_base_set_33100_destroy},
    {{3,3,1,1,0}, app_scr_bolus_set_mode_33310_create, app_scr_bolus_set_mode_33310_update, app_scr_bolus_set_mode_33310_destroy},
    {{3,3,2,0,0}, app_scr_bolus_set_mode_33320_create, app_scr_bolus_set_mode_33320_update, app_scr_bolus_set_mode_33320_destroy},
    
    {{3,3,2,1,0}, app_scr_temp_set_33210_create, app_scr_temp_set_33210_update, app_scr_temp_set_33210_destroy},
    {{3,3,3,0,0}, app_scr_bolus_set_enter_33300_create, app_scr_bolus_set_enter_33300_update, app_scr_bolus_set_enter_33300_destroy},
    {{3,3,3,1,0}, app_scr_bolus_set_mode_33310_create, app_scr_bolus_set_mode_33310_update, app_scr_bolus_set_mode_33310_destroy},	
    {{3,3,3,2,0}, app_scr_bolus_set_mode_33320_create, app_scr_bolus_set_mode_33320_update, app_scr_bolus_set_mode_33320_destroy},	
    {{3,3,3,3,0}, app_scr_bolus_set_time_33330_create, app_scr_bolus_set_time_33330_update, app_scr_bolus_set_time_33330_destroy},	
    
    {{3,3,3,4,0}, app_scr_bolus_set_double_dose_33340_create, app_scr_bolus_set_double_dose_33340_update, app_scr_bolus_set_double_dose_33340_destroy},	
    {{3,4,0,0,0}, app_scr_total_set_enter_34000_create, app_scr_total_set_enter_34000_update, app_scr_total_set_enter_34000_destroy},	
    
    {{1,1,0,0,0}, app_scr_initing_11000_create, app_scr_initing_11000_update, app_scr_initing_11000_destroy},	
    {{1,2,0,0,0}, app_scr_init_ok_12000_create, app_scr_init_ok_12000_update, app_scr_init_ok_12000_destroy},
    {{1,3,0,0,0}, app_scr_init_failed_13000_create, app_scr_init_failed_13000_update, app_scr_init_failed_13000_destroy},
    {{1,4,0,0,0}, app_scr_time_set_tip_14000_create, app_scr_time_set_tip_14000_update, app_scr_time_set_tip_14000_destroy},


	
};


/************************************************
 * Function
 ************************************************/

Screen* go_to_screen(ScreenID screen) {
	Screen* ret = NULL;
	int i;

	for (i = 0; i < ssz_array_size(g_routes); i++) {
		if (g_routes[i].screen_id == screen) {
			if (g_routes[i].enter_func) {
				ret = g_routes[i].enter_func();  //调用界面的进入函数。
			}
			break;
		}
	}
	ssz_assert(i < ssz_array_size(g_routes));
	return ret;
}
void go_back() {
	screen_go_back();
}
void go_back_to_screen(ScreenID screen) {
	screen_go_back_to_id(screen);
}
//#endif


void ert_uiDisp(uint8_t UIOpCode, type_MsgBody4UICtrlMsg *UIDispData)
{
  	int i;
	ScreenCreateFunc createfunc;
	ScreenUpdateFunc updatefun;
	ScrennDestroyFunc destroyfun;


	for (i = 0; i < ssz_array_size(g_scr_routes); i++) {
		if (memcmp(UIDispData->UIID, g_scr_routes[i].screen_id, 5) == 0) 
		{
			createfunc = g_scr_routes[i].create_func; 
			updatefun = g_scr_routes[i].update_fun;
			destroyfun = g_scr_routes[i].destroy_fun;
			break;
		}
	}

	if(i == ssz_array_size(g_scr_routes))
	{//no screen is finded
		return;
	}

	if(createfunc == NULL || updatefun== NULL || destroyfun==NULL)
	{//any api is null renturn
		return;
	}

	switch(UIOpCode)
	{
		case SCR_CREATE:
			if((memcmp(g_ui_common_param.uiid, UIDispData->UIID, sizeof(g_ui_common_param.uiid)) != 0))
			{
				if(g_ui_common_param.win_id != 0)
				{
					destroyfun(g_ui_common_param.win_id);	
				}
				g_ui_common_param.win_id = createfunc(UIDispData);
				memcpy(g_ui_common_param.uiid, UIDispData->UIID, 5);
				g_ui_common_param.opcode = UIDispData->OpMethod;
			}
			break;
		
		case SCR_CURSER_MOVE:	
		case SCR_VALUE_ALTER:
			if((memcmp(g_ui_common_param.uiid, UIDispData->UIID, sizeof(g_ui_common_param.uiid)) != 0))
			{
				if(g_ui_common_param.win_id != 0)
				{
					destroyfun(g_ui_common_param.win_id);	
				}
				g_ui_common_param.win_id = createfunc(UIDispData);
				memcpy(g_ui_common_param.uiid, UIDispData->UIID, 5);
			}
			
			updatefun(g_ui_common_param.win_id, UIDispData);
			g_ui_common_param.opcode = UIDispData->OpMethod;
			
			break;
		default:
			break;
	}

}






































