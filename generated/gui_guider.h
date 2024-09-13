/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *ui_timer_screen;
	bool ui_timer_screen_del;
	lv_obj_t *ui_timer_screen_start_stop_btn;
	lv_obj_t *ui_timer_screen_start_stop_btn_label;
	lv_obj_t *ui_timer_screen_reset_btn;
	lv_obj_t *ui_timer_screen_reset_btn_label;
	lv_obj_t *ui_timer_screen_set_btn;
	lv_obj_t *ui_timer_screen_set_btn_label;
	lv_obj_t *ui_timer_screen_hrs_label;
	lv_obj_t *ui_timer_screen_min_label;
	lv_obj_t *ui_timer_screen_sec_label;
	lv_obj_t *ui_timer_screen_label_4;
	lv_obj_t *ui_timer_screen_label_5;
	lv_obj_t *ui_timer_screen_label_6;
	lv_obj_t *ui_timer_screen_date_label;
	lv_obj_t *ui_timer_screen_label_7;
	lv_obj_t *ui_set_timer_screen;
	bool ui_set_timer_screen_del;
	lv_obj_t *ui_set_timer_screen_min_roller;
	lv_obj_t *ui_set_timer_screen_hrs_roller;
	lv_obj_t *ui_set_timer_screen_sec_roller;
	lv_obj_t *ui_set_timer_screen_label_1;
	lv_obj_t *ui_set_timer_screen_label_2;
	lv_obj_t *ui_set_timer_screen_label_3;
	lv_obj_t *ui_set_timer_screen_label_4;
	lv_obj_t *ui_set_timer_screen_label_5;
	lv_obj_t *ui_set_timer_screen_set_timer_btn;
	lv_obj_t *ui_set_timer_screen_set_timer_btn_label;
	lv_obj_t *ui_set_timer_screen_datetext_1;
	lv_obj_t *ui_set_timer_screen_set_date_btn;
	lv_obj_t *ui_set_timer_screen_set_date_btn_label;
	lv_obj_t *ui_set_timer_screen_label_6;
	lv_obj_t *ui_set_timer_screen_label_7;
	lv_obj_t *ui_set_timer_screen_change_color_btn;
	lv_obj_t *ui_set_timer_screen_change_color_btn_label;
	lv_obj_t *ui_set_timer_screen_color_roller;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_move_animation(void * var, int32_t duration, int32_t delay, int32_t x_end, int32_t y_end, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_scale_animation(void * var, int32_t duration, int32_t delay, int32_t width, int32_t height, lv_anim_path_cb_t path_cb,
                        uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                        lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_zoom_animation(void * var, int32_t duration, int32_t delay, int32_t zoom, lv_anim_path_cb_t path_cb,
                           uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                           lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_rotate_animation(void * var, int32_t duration, int32_t delay, lv_coord_t x, lv_coord_t y, int32_t rotate,
                   lv_anim_path_cb_t path_cb, uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time,
                   uint32_t playback_delay, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);


extern lv_ui guider_ui;


void setup_scr_ui_timer_screen(lv_ui *ui);
void setup_scr_ui_set_timer_screen(lv_ui *ui);

LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_Antonio_Regular_135)
LV_FONT_DECLARE(lv_font_Antonio_Regular_70)
LV_FONT_DECLARE(lv_font_montserratMedium_14)
LV_FONT_DECLARE(lv_font_Adventpro_regular_45)
LV_FONT_DECLARE(lv_font_montserratMedium_25)
LV_FONT_DECLARE(lv_font_Adventpro_regular_25)


#ifdef __cplusplus
}
#endif
#endif
