/************************************************
 * DESCRIPTION:
 *
 * 	route for screen show
 *
 ************************************************/
#pragma once

#include "ssz_def.h"
#include "screen.h"

/************************************************
 * Declaration
 ************************************************/


#include "ui_common.h"
#include "screen_config.h"


#ifdef __cplusplus
extern "C" {
#endif

typedef WM_HWIN (*ScreenCreateFunc)(type_MsgBody4UICtrlMsg *);
typedef int (*ScreenUpdateFunc)(WM_HWIN , type_MsgBody4UICtrlMsg *);
typedef void (*ScrennDestroyFunc)(WM_HWIN);

typedef struct {
	uint8_t screen_id[5];
	ScreenCreateFunc create_func;
	ScreenUpdateFunc update_fun;
	ScrennDestroyFunc destroy_fun;
} ScreenInfo;

extern const ScreenInfo g_scr_routes[35];




Screen* go_to_screen(ScreenID screen);
void go_back();
void go_back_to_screen(ScreenID screen);


WM_HWIN app_scr_alarm_set_enter_34900_create(type_MsgBody4UICtrlMsg *msg);
int app_scr_alarm_set_enter_34900_update(WM_HWIN last_hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_alarm_set_enter_34900_destroy(WM_HWIN win_id); 


WM_HWIN app_scr_base_log_enter_35200_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_base_log_enter_35200_update(WM_HWIN last_hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_base_log_enter_35200_destroy(WM_HWIN win_id); 



WM_HWIN app_scr_time_set_enter_34700_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_time_set_enter_34700_update(WM_HWIN last_hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_time_set_enter_34700_destroy(WM_HWIN win_id); 


WM_HWIN app_scr_date_set_enter_34800_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_date_set_enter_34800_update(WM_HWIN last_hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_date_set_enter_34800_destroy(WM_HWIN win_id); 




WM_HWIN app_scr_infusion_force_enter_34200_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_infusion_force_enter_34200_update(WM_HWIN hwin,type_MsgBody4UICtrlMsg *msg);
void app_scr_infusion_force_enter_34200_destroy(WM_HWIN win_id); 




WM_HWIN app_scr_max_base_dose_enter_34300_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_max_base_dose_enter_34300_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_max_base_dose_enter_34300_destroy(WM_HWIN win_id); 




WM_HWIN app_scr_max_bolus_set_enter_34400_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_max_bolus_set_enter_34400_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_max_bolus_set_enter_34400_destroy(WM_HWIN win_id) ;



WM_HWIN app_scr_remaining_dose_enter_34600_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_remaining_dose_enter_34600_update(WM_HWIN hwin,type_MsgBody4UICtrlMsg *msg);
void app_scr_remaining_dose_enter_34600_destroy(WM_HWIN hwin);




WM_HWIN app_scr_concentration_set_enter_34500_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_concentration_set_enter_34500_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_concentration_set_enter_34500_destroy(WM_HWIN win_id); 



WM_HWIN app_scr_switch_31100_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_switch_31100_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_switch_31100_destroy(WM_HWIN win_id); 


WM_HWIN app_scr_switch_enter_31000_create(type_MsgBody4UICtrlMsg *msg);
int app_scr_switch_enter_31000_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_switch_enter_31000_destroy(WM_HWIN win_id); 


WM_HWIN app_scr_opreate_enter_32000_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_opreate_enter_32000_update(WM_HWIN hwin,  type_MsgBody4UICtrlMsg *msg);
void app_scr_opreate_enter_32000_destroy(WM_HWIN win_id); 

WM_HWIN app_scr_opreate_locate_enter_32100_create(type_MsgBody4UICtrlMsg *msg);
int app_scr_opreate_locate_enter_32100_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_opreate_locate_enter_32100_destroy(WM_HWIN win_id); 

WM_HWIN app_scr_opreate_locateing_32110_enter(type_MsgBody4UICtrlMsg *msg); 
int app_scr_opreate_locateing_32110_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_opreate_locateing_32110_destroy(WM_HWIN win_id); 



WM_HWIN app_scr_opreate_dose_enter_32200_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_opreate_dose_enter_32200_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_opreate_dose_enter_32200_destroy(WM_HWIN win_id); 




WM_HWIN app_scr_opreate_dose_32210_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_opreate_dose_32210_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_opreate_dose_32210_destroy(WM_HWIN win_id); 




WM_HWIN app_scr_opreate_exhaust_32300_create(type_MsgBody4UICtrlMsg *msg) ;
int app_scr_opreate_exhaust_32300_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_opreate_exhaust_32300_destroy(WM_HWIN win_id); 


WM_HWIN app_scr_opreate_exhaust_32310_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_opreate_exhaust_32310_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_opreate_exhaust_32310_destroy(WM_HWIN win_id); 

WM_HWIN app_scr_infusion_set_enter_33000_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_infusion_set_enter_33000_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_infusion_set_enter_33000_destroy(WM_HWIN win_id); 


WM_HWIN app_scr_base_set_enter_33100_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_base_set_enter_33100_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_base_set_33100_destroy(WM_HWIN win_id);



WM_HWIN app_scr_temp_set_enter_33200_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_temp_set_enter_33200_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_temp_set_enter_33200_destroy(WM_HWIN win_id); 

WM_HWIN app_scr_temp_set_33210_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_temp_set_33210_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_temp_set_33210_destroy(WM_HWIN win_id); 


WM_HWIN app_scr_bolus_set_mode_33320_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_bolus_set_mode_33320_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_bolus_set_mode_33320_destroy(WM_HWIN win_id); 


WM_HWIN app_scr_bolus_set_enter_33300_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_bolus_set_enter_33300_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_bolus_set_enter_33300_destroy(WM_HWIN win_id); 



WM_HWIN app_scr_bolus_set_mode_33310_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_bolus_set_mode_33310_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_bolus_set_mode_33310_destroy(WM_HWIN win_id); 


WM_HWIN app_scr_bolus_set_time_33330_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_bolus_set_time_33330_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_bolus_set_time_33330_destroy(WM_HWIN win_id) ;



WM_HWIN app_scr_bolus_set_double_dose_33340_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_bolus_set_double_dose_33340_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_bolus_set_double_dose_33340_destroy(WM_HWIN win_id); 



WM_HWIN app_scr_total_set_enter_34000_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_total_set_enter_34000_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_total_set_enter_34000_destroy(WM_HWIN win_id); 




WM_HWIN app_scr_initing_11000_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_initing_11000_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_initing_11000_destroy(WM_HWIN win_id); 



WM_HWIN app_scr_init_ok_12000_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_init_ok_12000_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_init_ok_12000_destroy(WM_HWIN win_id); 



WM_HWIN app_scr_init_failed_13000_create(type_MsgBody4UICtrlMsg *msg); 
int app_scr_init_failed_13000_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg);
void app_scr_init_failed_13000_destroy(WM_HWIN win_id); 


WM_HWIN app_scr_time_set_tip_14000_create(type_MsgBody4UICtrlMsg * pMsg); 
int app_scr_time_set_tip_14000_update(WM_HWIN hwin, type_MsgBody4UICtrlMsg *msg); 
void app_scr_time_set_tip_14000_destroy(WM_HWIN win_id); 


void ert_uiDisp(uint8_t UIOpCode, type_MsgBody4UICtrlMsg *UIDispData);


#ifdef __cplusplus
}
#endif














