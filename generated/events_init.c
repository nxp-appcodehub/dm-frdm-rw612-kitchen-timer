/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


#include "custom.h"
extern BTN_STATUS_T btn_status;
#include <stdio.h>
#include <stdlib.h>
#include <custom.h>
#include "fsl_debug_console.h"


extern char * hour_in_terminal[3];

extern int current_hrs, current_min, current_sec;

//The itoa() and strcat() functions specifies that the minimum size of the array must be sizeof(int)*8+1
char hrs_str[sizeof(int)*8+1]; //to have the current hrs in ascii
char min_str[sizeof(int)*8+1]; //to have the current min in ascii
char sec_str[sizeof(int)*8+1]; //to have the current sec in ascii




typedef enum
{
	kRLR_StatusRED,
	kRLR_StatusGREEN,
	kRLR_StatusBLUE,
	kRLR_StatusPURPLE,
    RLR_StatusYELLOW,
} RLR_STATUS_T;

uint16_t next_color;
static void ui_timer_screen_start_stop_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
		if((btn_status == kBTN_StatusSTOP) || (btn_status == kBTN_StatusIDLE)){
	  btn_status = kBTN_StatusSTART;
	}
	else{
	  btn_status = kBTN_StatusSTOP;
	}
		break;
	}
	default:
		break;
	}
}
static void ui_timer_screen_reset_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
		lv_roller_get_selected_str(guider_ui.ui_set_timer_screen_hrs_roller, hrs_str, 0);
	lv_roller_get_selected_str(guider_ui.ui_set_timer_screen_min_roller, min_str, 0);
	lv_roller_get_selected_str(guider_ui.ui_set_timer_screen_sec_roller, sec_str, 0);
	
	current_hrs = atoi(hrs_str);
	current_min = atoi(min_str);
	current_sec = atoi(sec_str);
	
	lv_label_set_text(guider_ui.ui_timer_screen_hrs_label,hrs_str);//updates the value of the hrs in the label
	lv_label_set_text(guider_ui.ui_timer_screen_min_label,min_str);//updates the value of the min in the label
	lv_label_set_text(guider_ui.ui_timer_screen_sec_label,sec_str);//updates the value of the sec in the label
	
	btn_status = kBTN_StatusRESET;

	hour_in_terminal[0] = hrs_str;
	hour_in_terminal[1] = min_str;
	hour_in_terminal[2] = sec_str;

		break;
	}
	default:
		break;
	}
}
static void ui_timer_screen_set_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.ui_set_timer_screen, guider_ui.ui_set_timer_screen_del, &guider_ui.ui_timer_screen_del, setup_scr_ui_set_timer_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, false);
		break;
	}
	default:
		break;
	}
}
void events_init_ui_timer_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->ui_timer_screen_start_stop_btn, ui_timer_screen_start_stop_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ui_timer_screen_reset_btn, ui_timer_screen_reset_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ui_timer_screen_set_btn, ui_timer_screen_set_btn_event_handler, LV_EVENT_ALL, ui);
}
static void ui_set_timer_screen_set_timer_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
		
	
	lv_roller_get_selected_str(guider_ui.ui_set_timer_screen_hrs_roller, hrs_str, 0);
	lv_roller_get_selected_str(guider_ui.ui_set_timer_screen_min_roller, min_str, 0);
	lv_roller_get_selected_str(guider_ui.ui_set_timer_screen_sec_roller, sec_str, 0);
	
	current_hrs = atoi(hrs_str);
	current_min = atoi(min_str);
	current_sec = atoi(sec_str);
	
	lv_label_set_text(guider_ui.ui_timer_screen_hrs_label,hrs_str);//updates the value of the hrs in the label
	lv_label_set_text(guider_ui.ui_timer_screen_min_label,min_str);//updates the value of the min in the label
	lv_label_set_text(guider_ui.ui_timer_screen_sec_label,sec_str);//updates the value of the sec in the label
	
	
	ui_load_scr_animation(&guider_ui, &guider_ui.ui_timer_screen, guider_ui.ui_set_timer_screen_del, &guider_ui.ui_timer_screen_del, setup_scr_ui_set_timer_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, false);
	
	btn_status = kBTN_StatusIDLE;

	hour_in_terminal[0] = hrs_str;
	hour_in_terminal[1] = min_str;
	hour_in_terminal[2] = sec_str;

	PRINTF("*******        %s : %s : %s       *******\r",hour_in_terminal[0],hour_in_terminal[1],hour_in_terminal[2]);
		break;
	}
	default:
		break;
	}
}
static void ui_set_timer_screen_set_date_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
		char * date_str;
	
	date_str = lv_label_get_text(guider_ui.ui_set_timer_screen_datetext_1);
	
	lv_label_set_text(guider_ui.ui_timer_screen_date_label,date_str);
	
	
	ui_load_scr_animation(&guider_ui, &guider_ui.ui_timer_screen, guider_ui.ui_set_timer_screen_del, &guider_ui.ui_timer_screen_del, setup_scr_ui_set_timer_screen, LV_SCR_LOAD_ANIM_NONE, 0, 0, false, false);
	
	btn_status = kBTN_StatusIDLE;
		break;
	}
	default:
		break;
	}
}
static void ui_set_timer_screen_change_color_btn_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_RELEASED:
	{
		next_color = lv_roller_get_selected(guider_ui.ui_set_timer_screen_color_roller);
	if(next_color == kRLR_StatusRED){
	  lv_obj_set_style_bg_color(guider_ui.ui_set_timer_screen_set_timer_btn, lv_color_hex(0xFF0000), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_set_timer_screen_set_date_btn, lv_color_hex(0xFF0000), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_set_timer_screen_change_color_btn, lv_color_hex(0xFF0000), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_timer_screen_set_btn, lv_color_hex(0xFF0000), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_timer_screen_reset_btn, lv_color_hex(0xFF0000), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_timer_screen_start_stop_btn, lv_color_hex(0xFF0000), LV_PART_MAIN|LV_STATE_DEFAULT);
	}
	else if(next_color == kRLR_StatusGREEN){
	  lv_obj_set_style_bg_color(guider_ui.ui_set_timer_screen_set_timer_btn, lv_color_hex(0x009929), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_set_timer_screen_set_date_btn, lv_color_hex(0x009929), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_set_timer_screen_change_color_btn, lv_color_hex(0x009929), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_timer_screen_set_btn, lv_color_hex(0x009929), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_timer_screen_reset_btn, lv_color_hex(0x009929), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_timer_screen_start_stop_btn, lv_color_hex(0x009929), LV_PART_MAIN|LV_STATE_DEFAULT);
	}
	else if(next_color == kRLR_StatusBLUE){
	  lv_obj_set_style_bg_color(guider_ui.ui_set_timer_screen_set_timer_btn, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_set_timer_screen_set_date_btn, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_set_timer_screen_change_color_btn, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_timer_screen_set_btn, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_timer_screen_reset_btn, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_timer_screen_start_stop_btn, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
	}
	else if(next_color == kRLR_StatusPURPLE){
	  lv_obj_set_style_bg_color(guider_ui.ui_set_timer_screen_set_timer_btn, lv_color_hex(0x7900AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_set_timer_screen_set_date_btn, lv_color_hex(0x7900AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_set_timer_screen_change_color_btn, lv_color_hex(0x7900AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_timer_screen_set_btn, lv_color_hex(0x7900AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_timer_screen_reset_btn, lv_color_hex(0x7900AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_timer_screen_start_stop_btn, lv_color_hex(0x7900AC), LV_PART_MAIN|LV_STATE_DEFAULT);
	}
	else if(next_color == RLR_StatusYELLOW){
	  lv_obj_set_style_bg_color(guider_ui.ui_set_timer_screen_set_timer_btn, lv_color_hex(0xF8DA45), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_set_timer_screen_set_date_btn, lv_color_hex(0xF8DA45), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_set_timer_screen_change_color_btn, lv_color_hex(0xF8DA45), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_timer_screen_set_btn, lv_color_hex(0xF8DA45), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_timer_screen_reset_btn, lv_color_hex(0xF8DA45), LV_PART_MAIN|LV_STATE_DEFAULT);
	  lv_obj_set_style_bg_color(guider_ui.ui_timer_screen_start_stop_btn, lv_color_hex(0xF8DA45), LV_PART_MAIN|LV_STATE_DEFAULT);
	}
	
	
	
		break;
	}
	default:
		break;
	}
}
void events_init_ui_set_timer_screen(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->ui_set_timer_screen_set_timer_btn, ui_set_timer_screen_set_timer_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ui_set_timer_screen_set_date_btn, ui_set_timer_screen_set_date_btn_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->ui_set_timer_screen_change_color_btn, ui_set_timer_screen_change_color_btn_event_handler, LV_EVENT_ALL, ui);
}

void events_init(lv_ui *ui)
{

}
