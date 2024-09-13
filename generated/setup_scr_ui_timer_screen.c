/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_ui_timer_screen(lv_ui *ui)
{
	//Write codes ui_timer_screen
	ui->ui_timer_screen = lv_obj_create(NULL);
	lv_obj_set_size(ui->ui_timer_screen, 480, 320);
	lv_obj_set_scrollbar_mode(ui->ui_timer_screen, LV_SCROLLBAR_MODE_OFF);

	//Write style for ui_timer_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_timer_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_timer_screen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->ui_timer_screen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_timer_screen_start_stop_btn
	ui->ui_timer_screen_start_stop_btn = lv_btn_create(ui->ui_timer_screen);
	ui->ui_timer_screen_start_stop_btn_label = lv_label_create(ui->ui_timer_screen_start_stop_btn);
	lv_label_set_text(ui->ui_timer_screen_start_stop_btn_label, "START/STOP");
	lv_label_set_long_mode(ui->ui_timer_screen_start_stop_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ui_timer_screen_start_stop_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ui_timer_screen_start_stop_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->ui_timer_screen_start_stop_btn_label, LV_PCT(100));
	lv_obj_set_pos(ui->ui_timer_screen_start_stop_btn, 20, 245);
	lv_obj_set_size(ui->ui_timer_screen_start_stop_btn, 135, 50);

	//Write style for ui_timer_screen_start_stop_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_timer_screen_start_stop_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_timer_screen_start_stop_btn, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->ui_timer_screen_start_stop_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_timer_screen_start_stop_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_timer_screen_start_stop_btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_timer_screen_start_stop_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_timer_screen_start_stop_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_timer_screen_start_stop_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_timer_screen_start_stop_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_timer_screen_start_stop_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_timer_screen_reset_btn
	ui->ui_timer_screen_reset_btn = lv_btn_create(ui->ui_timer_screen);
	ui->ui_timer_screen_reset_btn_label = lv_label_create(ui->ui_timer_screen_reset_btn);
	lv_label_set_text(ui->ui_timer_screen_reset_btn_label, "RESET");
	lv_label_set_long_mode(ui->ui_timer_screen_reset_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ui_timer_screen_reset_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ui_timer_screen_reset_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->ui_timer_screen_reset_btn_label, LV_PCT(100));
	lv_obj_set_pos(ui->ui_timer_screen_reset_btn, 170, 245);
	lv_obj_set_size(ui->ui_timer_screen_reset_btn, 135, 50);

	//Write style for ui_timer_screen_reset_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_timer_screen_reset_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_timer_screen_reset_btn, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->ui_timer_screen_reset_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_timer_screen_reset_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_timer_screen_reset_btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_timer_screen_reset_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_timer_screen_reset_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_timer_screen_reset_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_timer_screen_reset_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_timer_screen_reset_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_timer_screen_set_btn
	ui->ui_timer_screen_set_btn = lv_btn_create(ui->ui_timer_screen);
	ui->ui_timer_screen_set_btn_label = lv_label_create(ui->ui_timer_screen_set_btn);
	lv_label_set_text(ui->ui_timer_screen_set_btn_label, "SET");
	lv_label_set_long_mode(ui->ui_timer_screen_set_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->ui_timer_screen_set_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->ui_timer_screen_set_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->ui_timer_screen_set_btn_label, LV_PCT(100));
	lv_obj_set_pos(ui->ui_timer_screen_set_btn, 320, 245);
	lv_obj_set_size(ui->ui_timer_screen_set_btn, 135, 50);

	//Write style for ui_timer_screen_set_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->ui_timer_screen_set_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->ui_timer_screen_set_btn, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->ui_timer_screen_set_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->ui_timer_screen_set_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_timer_screen_set_btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_timer_screen_set_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_timer_screen_set_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_timer_screen_set_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_timer_screen_set_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_timer_screen_set_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_timer_screen_hrs_label
	ui->ui_timer_screen_hrs_label = lv_label_create(ui->ui_timer_screen);
	lv_label_set_text(ui->ui_timer_screen_hrs_label, "00");
	lv_label_set_long_mode(ui->ui_timer_screen_hrs_label, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_timer_screen_hrs_label, 20, 83);
	lv_obj_set_size(ui->ui_timer_screen_hrs_label, 140, 145);

	//Write style for ui_timer_screen_hrs_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_timer_screen_hrs_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_timer_screen_hrs_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_timer_screen_hrs_label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_timer_screen_hrs_label, &lv_font_Antonio_Regular_135, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_timer_screen_hrs_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_timer_screen_hrs_label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_timer_screen_hrs_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_timer_screen_hrs_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_timer_screen_hrs_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_timer_screen_hrs_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_timer_screen_hrs_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_timer_screen_hrs_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_timer_screen_hrs_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_timer_screen_hrs_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_timer_screen_min_label
	ui->ui_timer_screen_min_label = lv_label_create(ui->ui_timer_screen);
	lv_label_set_text(ui->ui_timer_screen_min_label, "00");
	lv_label_set_long_mode(ui->ui_timer_screen_min_label, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_timer_screen_min_label, 167, 83);
	lv_obj_set_size(ui->ui_timer_screen_min_label, 140, 145);

	//Write style for ui_timer_screen_min_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_timer_screen_min_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_timer_screen_min_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_timer_screen_min_label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_timer_screen_min_label, &lv_font_Antonio_Regular_135, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_timer_screen_min_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_timer_screen_min_label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_timer_screen_min_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_timer_screen_min_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_timer_screen_min_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_timer_screen_min_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_timer_screen_min_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_timer_screen_min_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_timer_screen_min_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_timer_screen_min_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_timer_screen_sec_label
	ui->ui_timer_screen_sec_label = lv_label_create(ui->ui_timer_screen);
	lv_label_set_text(ui->ui_timer_screen_sec_label, "00");
	lv_label_set_long_mode(ui->ui_timer_screen_sec_label, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_timer_screen_sec_label, 315, 83);
	lv_obj_set_size(ui->ui_timer_screen_sec_label, 140, 145);

	//Write style for ui_timer_screen_sec_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_timer_screen_sec_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_timer_screen_sec_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_timer_screen_sec_label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_timer_screen_sec_label, &lv_font_Antonio_Regular_135, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_timer_screen_sec_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_timer_screen_sec_label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_timer_screen_sec_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_timer_screen_sec_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_timer_screen_sec_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_timer_screen_sec_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_timer_screen_sec_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_timer_screen_sec_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_timer_screen_sec_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_timer_screen_sec_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_timer_screen_label_4
	ui->ui_timer_screen_label_4 = lv_label_create(ui->ui_timer_screen);
	lv_label_set_text(ui->ui_timer_screen_label_4, ":");
	lv_label_set_long_mode(ui->ui_timer_screen_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_timer_screen_label_4, 149, 114);
	lv_obj_set_size(ui->ui_timer_screen_label_4, 29, 70);

	//Write style for ui_timer_screen_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_timer_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_timer_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_timer_screen_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_timer_screen_label_4, &lv_font_Antonio_Regular_70, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_timer_screen_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_timer_screen_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_timer_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_timer_screen_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_timer_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_timer_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_timer_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_timer_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_timer_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_timer_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_timer_screen_label_5
	ui->ui_timer_screen_label_5 = lv_label_create(ui->ui_timer_screen);
	lv_label_set_text(ui->ui_timer_screen_label_5, ":");
	lv_label_set_long_mode(ui->ui_timer_screen_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_timer_screen_label_5, 297, 118);
	lv_obj_set_size(ui->ui_timer_screen_label_5, 29, 70);

	//Write style for ui_timer_screen_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_timer_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_timer_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_timer_screen_label_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_timer_screen_label_5, &lv_font_Antonio_Regular_70, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_timer_screen_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_timer_screen_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_timer_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_timer_screen_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_timer_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_timer_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_timer_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_timer_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_timer_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_timer_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_timer_screen_label_6
	ui->ui_timer_screen_label_6 = lv_label_create(ui->ui_timer_screen);
	lv_label_set_text(ui->ui_timer_screen_label_6, "TIMER");
	lv_label_set_long_mode(ui->ui_timer_screen_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_timer_screen_label_6, 26, 35);
	lv_obj_set_size(ui->ui_timer_screen_label_6, 64, 14);

	//Write style for ui_timer_screen_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_timer_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_timer_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_timer_screen_label_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_timer_screen_label_6, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_timer_screen_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_timer_screen_label_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_timer_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_timer_screen_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_timer_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_timer_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_timer_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_timer_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_timer_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_timer_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_timer_screen_date_label
	ui->ui_timer_screen_date_label = lv_label_create(ui->ui_timer_screen);
	lv_label_set_text(ui->ui_timer_screen_date_label, "2023/07/31");
	lv_label_set_long_mode(ui->ui_timer_screen_date_label, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_timer_screen_date_label, 170, 35);
	lv_obj_set_size(ui->ui_timer_screen_date_label, 135, 14);

	//Write style for ui_timer_screen_date_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_timer_screen_date_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_timer_screen_date_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_timer_screen_date_label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_timer_screen_date_label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_timer_screen_date_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_timer_screen_date_label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_timer_screen_date_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_timer_screen_date_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_timer_screen_date_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_timer_screen_date_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_timer_screen_date_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_timer_screen_date_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_timer_screen_date_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_timer_screen_date_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes ui_timer_screen_label_7
	ui->ui_timer_screen_label_7 = lv_label_create(ui->ui_timer_screen);
	lv_label_set_text(ui->ui_timer_screen_label_7, "10:55 PM");
	lv_label_set_long_mode(ui->ui_timer_screen_label_7, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->ui_timer_screen_label_7, 344, 35);
	lv_obj_set_size(ui->ui_timer_screen_label_7, 87, 14);

	//Write style for ui_timer_screen_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->ui_timer_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->ui_timer_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->ui_timer_screen_label_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->ui_timer_screen_label_7, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->ui_timer_screen_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->ui_timer_screen_label_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->ui_timer_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->ui_timer_screen_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->ui_timer_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->ui_timer_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->ui_timer_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->ui_timer_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->ui_timer_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->ui_timer_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of ui_timer_screen.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->ui_timer_screen);

	//Init events for screen.
	events_init_ui_timer_screen(ui);
}
