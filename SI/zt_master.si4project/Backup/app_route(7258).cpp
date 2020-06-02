/************************************************
 * DESCRIPTION:
 *
 * 	route for screen show
 *
 ************************************************/
#include "app_route.h"
#include "config.h"
#include "WM.h"
#include "ssz_common.h"
//#include "app_scr_logo_01000.h"
//#include "app_scr_main_menu_11000.h"
//#include "app_scr_set_dose_12300.h"
//#include "app_scr_unlock_password_12100.h"
//#include "app_scr_exhaust_tip_11100.h"
//#include "app_scr_exhaust_11200.h"
//#include "app_scr_home_02000.h"
//#include "app_scr_alarm_21000.h"
//#include "app_scr_histroy_15100.h"
//#include "app_scr_shutdown_41000.h"
//#include "app_scr_lock_error_34000.h"
//#include "app_scr_error_22000.h"
//#include "app_scr_check_12500.h"
//#include "app_scr_infusion_speed_12400.h"
//#include "app_scr_set_date_14120.h"
//#include "app_scr_set_time_14110.h"
//#include "app_scr_set_14100.h"
//#include "app_scr_set_year_14130.h"
//#include "app_scr_stop_infusion_13100.h"
//#include "app_scr_version_14140.h"
//#include "app_scr_stop_infusion_13100.h"
//#include "app_scr_set_14100.h"
//#include "app_scr_set_year_14130.h"
//#include "app_scr_set_date_14120.h"
//#include "app_scr_test_gain.h"
//#include "app_scr_test_minus_offset.h"
//#include "app_scr_test_plus_offset.h"
//#include "app_scr_test_current_max.h"
//#include "app_scr_test_current_min.h"
//#include "app_scr_exhaust_start.h"
//#include "app_scr_exhaust_pause.h"

//add by deming, 2020/05/27
#include "app_scr_class1.h"
#include "app_scr_class2.h"
#include "app_scr_class3.h"
#include "app_scr_class8.h"
#include "app_scr_class9.h"


/************************************************
 * Declaration
 ************************************************/



/************************************************
 * Variable

 typedef struct {
	uint8_t uiclass_id;
	uint8_t screen_id[5];
	ScreenCreateFunc create_func;
	ScreenUpdateFunc update_fun;
	ScrennDestroyFunc destroy_fun;
} ScreenInfo;


 ************************************************/
const ScreenInfo g_scr_routes[SCREEN_NUMBER_TOTAL]= {

	{
		.uiclass_id 	= 1,
		.screen_id 		= {},
		.create_func 	= app_scr_class1_create,
		.update_fun 	= app_scr_class1_update,
		.destroy_fun 	= app_scr_class1_destroy,
	},
	{
		.uiclass_id 	= 2,
		.screen_id 		= {},
		.create_func 	= app_scr_class2_create,
		.update_fun 	= app_scr_class2_update,
		.destroy_fun 	= app_scr_class2_destroy,
	},
	{
		.uiclass_id 	= 3,
		.screen_id 		= {},
		.create_func 	= app_scr_class3_create,
		.update_fun 	= app_scr_class3_update,
		.destroy_fun 	= app_scr_class3_destroy,
	},
	{
		.uiclass_id 	= 4,
		.screen_id 		= {},
		.create_func 	= NULL,
		.update_fun 	= NULL,
		.destroy_fun 	= NULL,
	},
	{
		.uiclass_id 	= 5,
		.screen_id 		= {},
		.create_func 	= NULL,
		.update_fun 	= NULL,
		.destroy_fun 	= NULL,
	},
	{
		.uiclass_id 	= 6,
		.screen_id 		= {},
		.create_func 	= NULL,
		.update_fun 	= NULL,
		.destroy_fun 	= NULL,
	},
	{
		.uiclass_id 	= 7,
		.screen_id 		= {},
		.create_func 	= NULL,
		.update_fun 	= NULL,
		.destroy_fun 	= NULL,
	},
	{
		.uiclass_id 	= 8,
		.screen_id 		= {},
		.create_func 	= app_scr_class8_create,
		.update_fun 	= app_scr_class8_update,
		.destroy_fun 	= app_scr_class8_destroy,
	},
	{
		.uiclass_id 	= 9,
		.screen_id 		= {},
		.create_func 	= app_scr_class9_create,
		.update_fun 	= app_scr_class9_update,
		.destroy_fun 	= app_scr_class9_destroy,
	},
	{
		.uiclass_id 	= 10,
		.screen_id 		= {},
		.create_func 	= NULL,
		.update_fun 	= NULL,
		.destroy_fun 	= NULL,
	},
	{
		.uiclass_id 	= 11,
		.screen_id 		= {},
		.create_func 	= NULL,
		.update_fun 	= NULL,
		.destroy_fun 	= NULL,
	},
	{
		.uiclass_id 	= 12,
		.screen_id 		= {},
		.create_func 	= NULL,
		.update_fun 	= NULL,
		.destroy_fun 	= NULL,
	},
	{
		.uiclass_id 	= 13,
		.screen_id 		= {},
		.create_func 	= NULL,
		.update_fun 	= NULL,
		.destroy_fun 	= NULL,
	},
	{
		.uiclass_id 	= 14,
		.screen_id 		= {},
		.create_func 	= NULL,
		.update_fun 	= NULL,
		.destroy_fun 	= NULL,
	},
	{
		.uiclass_id 	= 15,
		.screen_id 		= {},
		.create_func 	= NULL,
		.update_fun 	= NULL,
		.destroy_fun 	= NULL,
	},
	{
		.uiclass_id 	= 16,
		.screen_id 		= {},
		.create_func 	= NULL,
		.update_fun 	= NULL,
		.destroy_fun 	= NULL,
	},
	{
		.uiclass_id 	= 17,
		.screen_id 		= {},
		.create_func 	= NULL,
		.update_fun 	= NULL,
		.destroy_fun 	= NULL,
	},
	{
		.uiclass_id 	= 18,
		.screen_id 		= {},
		.create_func 	= NULL,
		.update_fun 	= NULL,
		.destroy_fun 	= NULL,
	},
	{
		.uiclass_id 	= 19,
		.screen_id 		= {},
		.create_func 	= NULL,
		.update_fun 	= NULL,
		.destroy_fun 	= NULL,
	},
	{
		.uiclass_id 	= 20,
		.screen_id 		= {},
		.create_func 	= NULL,
		.update_fun 	= NULL,
		.destroy_fun 	= NULL,
	},
         
      
//  //testing
//  {{1,4,1,4,8}, app_init_screen_create, app_init_screen_update, app_init_screen_destroy},
//
//  
//  {{1,2,1,0,0}, app_scr_unlock_password_12100_create, app_scr_unlock_password_12100_update, app_scr_unlock_password_12100_destroy},
//  {{1,4,1,4,0}, app_scr_version_14140_create, app_scr_version_14140_update, app_scr_version_14140_destroy},
//
//  {{2,1,0,0,0}, app_scr_alarm_21000_create, app_scr_alarm_21000_update, app_scr_alarm_21000_destroy},
//  {{2,2,0,0,0}, app_scr_error_22000_create, app_scr_error_22000_update, app_scr_error_22000_destroy},
//
//  {{1,5,1,0,0}, app_scr_histroy_15100_create, app_scr_histroy_15100_update, app_scr_histroy_15100_destroy},
//  {{4,1,0,0,0}, app_scr_shotdown_41000_create, app_scr_shotdown_41000_update, app_scr_shotdown_41000_destroy},
//  {{3,2,0,0,0}, app_scr_lock_error_34000_create, app_scr_lock_error_34000_update, app_scr_lock_error_34000_destroy},   
//  {{3,3,0,0,0}, app_scr_lock_error_34000_create, app_scr_lock_error_34000_update, app_scr_lock_error_34000_destroy},
//  {{3,4,0,0,0}, app_scr_lock_error_34000_create, app_scr_lock_error_34000_update, app_scr_lock_error_34000_destroy},
//
// 
//  //test pass
//  {{1,1,0,0,0}, app_main_menu_11000_create, app_main_menu_11000_update, app_main_menu_11000_destroy},
//  {{1,1,1,0,0}, app_exhaust_tip_11100_create, app_exhaust_tip_11100_update, app_exhaust_tip_11100_destroy},
//  {{1,1,2,0,0}, app_exhaust_start_create, app_exhaust_start_update, app_exhaust_start_destroy},   
//  {{1,1,2,1,0}, app_exhaust_pause_create, app_exhaust_pause_update, app_exhaust_pause_destroy},   
//  {{0,2,0,0,0}, app_home_02000_create, app_home_02000_update, app_home_02000_destroy},
//  {{0,1,0,0,0}, app_logo_01000_create, app_logo_01000_update, app_logo_01000_destroy},  
//
//  {{1,4,1,2,0}, app_scr_set_date_14120_create, app_scr_set_date_14120_update, app_scr_set_date_14120_destroy},
//  {{1,4,1,1,0}, app_scr_set_time_14110_create, app_scr_set_time_14110_update, app_scr_set_time_14110_destroy},   
//  {{1,4,1,3,0}, app_scr_set_year_14130_create, app_scr_set_year_14130_update, app_scr_set_year_14130_destroy},
//  {{1,3,1,0,0}, app_scr_stop_infusion_13100_create, app_scr_stop_infusion_13100_update, app_scr_stop_infusion_13100_destroy},
//  
//  //need to test
//
//  
//  //not to use
//  {{1,2,3,0,0}, app_scr_set_dose_12300_create, app_scr_set_dose_12300_update, app_scr_set_dose_12300_destroy},
//  {{1,4,1,0,0}, app_scr_set_14100_create, app_scr_set_14100_update, app_scr_set_14100_destroy},



};
 

//void ert_uiDispService(uint8_T UIClassID,uiClassIDArray UIIDArray,
//        curDescriptor* CursorDept,dItemDescriptor* DItemDept,
//        sItemDescriptor* SItemDept)
//{
//  	int i;
//	ScreenCreateFunc createfunc;
//	ScreenUpdateFunc updatefun;
//	ScrennDestroyFunc destroyfun;
//
//	type_MsgBody4UICtrlMsg UIDispData;
//	
//	memset((uint8_t *)&UIDispData, 0, sizeof(type_MsgBody4UICtrlMsg));
//	
//	memcpy((uint8_t *)&UIDispData.CursorIndex, (uint8_t *)CursorDept, sizeof(curDescriptor));
//	memcpy((uint8_t *)&UIDispData.ditem, (uint8_t *)DItemDept, sizeof(dItemDescriptor));
//	memcpy((uint8_t *)&UIDispData.SItem, (uint8_t *)SItemDept, sizeof(sItemDescriptor));
//	memcpy(UIDispData.UIID, UIIDArray, 5);
//
//
//	for (i = 0; i < ssz_array_size(g_scr_routes); i++)
//	{
//		if (memcmp(UIDispData.UIID, g_scr_routes[i].screen_id, 5) == 0) 
//		{
//			createfunc = g_scr_routes[i].create_func; 
//			updatefun = g_scr_routes[i].update_fun;
//			destroyfun = g_scr_routes[i].destroy_fun;
//			break;
//		}
//	}
//
//	if(i == ssz_array_size(g_scr_routes))
//	{//no screen is finded
//		return;
//	}
//
//	if(createfunc == NULL || updatefun== NULL || destroyfun==NULL)
//	{//any api is null renturn
//		return;
//	}
//
//	if((memcmp(g_ui_common_param.uiid, UIDispData.UIID, sizeof(g_ui_common_param.uiid)) != 0))
//	{
//		if(g_ui_common_param.win_id != 0)
//		{
//			destroyfun(g_ui_common_param.win_id);	
//		}
//		g_ui_common_param.win_id = createfunc(&UIDispData);
//		memcpy(g_ui_common_param.uiid, UIDispData.UIID, 5);	
//		updatefun(g_ui_common_param.win_id, &UIDispData);
//	}
//	else
//	{
//		updatefun(g_ui_common_param.win_id, &UIDispData);
//	}
//}



void ert_uiDispService(uint8_T UIClassID,uiClassIDArray UIIDArray,
        curDescriptor* CursorDept,dItemDescriptor* DItemDept,
        sItemDescriptor* SItemDept)
{
  	int i;
	ScreenCreateFunc createfunc;
	ScreenUpdateFunc updatefun;
	ScrennDestroyFunc destroyfun;

	type_MsgBody4UICtrlMsg UIDispData;
	memset((uint8_t *)&UIDispData, 0, sizeof(type_MsgBody4UICtrlMsg));
	
        //copy data 
	memcpy((uint8_t *)&UIDispData.CursorIndex, (uint8_t *)CursorDept, sizeof(curDescriptor));
	memcpy((uint8_t *)&UIDispData.ditem, (uint8_t *)DItemDept, sizeof(dItemDescriptor));
	memcpy((uint8_t *)&UIDispData.SItem, (uint8_t *)SItemDept, sizeof(sItemDescriptor));
	memcpy(UIDispData.UIID, UIIDArray, 5);
        UIDispData.ClassID = UIClassID ;

        
	if(g_scr_routes[UIClassID-1].create_func        == NULL ||  
           g_scr_routes[UIClassID-1].update_fun          == NULL ||  
           g_scr_routes[UIClassID-1].destroy_fun         ==NULL)
	{//any api is null renturn
		return;
	}
        createfunc = g_scr_routes[UIClassID-1].create_func;
        updatefun = g_scr_routes[UIClassID-1].update_fun;
        destroyfun = g_scr_routes[UIClassID-1].destroy_fun;

        //check this screen if has been created
	if( g_ui_common_param.classid != UIDispData.ClassID )
	{
		if(g_ui_common_param.win_id != 0)
		{
			destroyfun(g_ui_common_param.win_id);	
		}
		g_ui_common_param.win_id = createfunc(&UIDispData);	
                g_ui_common_param.classid = UIDispData.ClassID;
		updatefun(g_ui_common_param.win_id, &UIDispData);
	}
	else
	{
		updatefun(g_ui_common_param.win_id, &UIDispData);
	}
}


































