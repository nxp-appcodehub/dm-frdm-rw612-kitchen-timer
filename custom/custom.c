/*
* Copyright 2023-2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>


#include "lvgl.h"
#include "custom.h"

#include <stdlib.h>

#include "fsl_debug_console.h"


/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void mask_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);

    static int16_t mask_top_id = -1;
    static int16_t mask_bottom_id = -1;

    if(code == LV_EVENT_COVER_CHECK) {
        lv_event_set_cover_res(e, LV_COVER_RES_MASKED);

    }
    else if(code == LV_EVENT_DRAW_MAIN_BEGIN) {
        /* add mask */
        const lv_font_t * font = lv_obj_get_style_text_font(obj, LV_PART_MAIN);
        lv_coord_t line_space = lv_obj_get_style_text_line_space(obj, LV_PART_MAIN);
        lv_coord_t font_h = lv_font_get_line_height(font);

        lv_area_t roller_coords;
        lv_obj_get_coords(obj, &roller_coords);

        lv_area_t rect_area;
        rect_area.x1 = roller_coords.x1;
        rect_area.x2 = roller_coords.x2;
        rect_area.y1 = roller_coords.y1;
        rect_area.y2 = roller_coords.y1 + (lv_obj_get_height(obj) - font_h - line_space) / 2;

        lv_draw_mask_fade_param_t * fade_mask_top = lv_mem_buf_get(sizeof(lv_draw_mask_fade_param_t));
        lv_draw_mask_fade_init(fade_mask_top, &rect_area, LV_OPA_TRANSP, rect_area.y1, LV_OPA_COVER, rect_area.y2);
        mask_top_id = lv_draw_mask_add(fade_mask_top, NULL);

        rect_area.y1 = rect_area.y2 + font_h + line_space - 1;
        rect_area.y2 = roller_coords.y2;

        lv_draw_mask_fade_param_t * fade_mask_bottom = lv_mem_buf_get(sizeof(lv_draw_mask_fade_param_t));
        lv_draw_mask_fade_init(fade_mask_bottom, &rect_area, LV_OPA_COVER, rect_area.y1, LV_OPA_TRANSP, rect_area.y2);
        mask_bottom_id = lv_draw_mask_add(fade_mask_bottom, NULL);

    }
    else if(code == LV_EVENT_DRAW_POST_END) {
        lv_draw_mask_fade_param_t * fade_mask_top = lv_draw_mask_remove_id(mask_top_id);
        lv_draw_mask_fade_param_t * fade_mask_bottom = lv_draw_mask_remove_id(mask_bottom_id);
        lv_draw_mask_free_param(fade_mask_top);
        lv_draw_mask_free_param(fade_mask_bottom);
        lv_mem_buf_release(fade_mask_top);
        lv_mem_buf_release(fade_mask_bottom);
        mask_top_id = -1;
        mask_bottom_id = -1;
    }
}
/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */
BTN_STATUS_T btn_status = kBTN_StatusSTOP;


char current_hrs_str[sizeof(int)*8+1];
char current_sec_str[sizeof(int)*8+1];
char current_min_str[sizeof(int)*8+1];

int current_hrs, current_min, current_sec;

char * hour_in_terminal[3];

void my_timer(lv_timer_t * timer)
{
  
  char add_zero_hrs[sizeof(int)*8+1] = "0";
  char add_zero_min[sizeof(int)*8+1] = "0";
  char add_zero_sec[sizeof(int)*8+1] = "0";
	if(btn_status == kBTN_StatusSTART){
      if((current_hrs == 0) && (current_min == 0) && (current_sec == 0)){
        lv_label_set_text(guider_ui.ui_timer_screen_hrs_label,"00");
        lv_label_set_text(guider_ui.ui_timer_screen_min_label,"00");
        lv_label_set_text(guider_ui.ui_timer_screen_sec_label,"00");
        btn_status = kBTN_StatusIDLE;
      }
      else{

            if((current_min == 0) && (current_sec == 0)){
              current_hrs = current_hrs - 1;
            }
            if(current_sec == 0){
              current_sec = 59;
              if(current_min == 0){
                current_min = 59;
              }
              else{
                current_min = current_min - 1;
              }        
            }
            else{
              current_sec = current_sec - 1;
            }
            itoa(current_hrs,current_hrs_str,10);
            itoa(current_min,current_min_str,10);
            itoa(current_sec,current_sec_str,10);
            if(current_hrs < 10){
              strcat(add_zero_hrs,current_hrs_str);
              lv_label_set_text(guider_ui.ui_timer_screen_hrs_label,add_zero_hrs);//updates the value of the hrs in the label
              hour_in_terminal[0] = add_zero_hrs;
            }
            if(current_min < 10){
              strcat(add_zero_min,current_min_str);
              lv_label_set_text(guider_ui.ui_timer_screen_min_label,add_zero_min);//updates the value of the min in the label
              hour_in_terminal[1] = add_zero_min;
            }
            if(current_sec < 10){
              strcat(add_zero_sec,current_sec_str);
              lv_label_set_text(guider_ui.ui_timer_screen_sec_label,add_zero_sec);//updates the value of the sec in the label
              hour_in_terminal[2] = add_zero_sec;
            }
            if(current_hrs >= 10){
              lv_label_set_text(guider_ui.ui_timer_screen_hrs_label,current_hrs_str);//updates the value of the hrs in the label
              hour_in_terminal[0] = current_hrs_str;
            }
            if(current_min >= 10){
              lv_label_set_text(guider_ui.ui_timer_screen_min_label,current_min_str);//updates the value of the min in the label
              hour_in_terminal[1] = current_min_str;
            }
            if(current_sec >= 10){
              lv_label_set_text(guider_ui.ui_timer_screen_sec_label,current_sec_str);//updates the value of the sec in the label
              hour_in_terminal[2] = current_sec_str;
            }

            PRINTF("*******        %s : %s : %s       *******\r",hour_in_terminal[0],hour_in_terminal[1],hour_in_terminal[2]);

      }
    }
    else if(btn_status == kBTN_StatusSTOP){
      btn_status = kBTN_StatusIDLE;
    }
    else if(btn_status == kBTN_StatusRESET){
      btn_status = kBTN_StatusIDLE;
      PRINTF("*******        %s : %s : %s       *******\r",hour_in_terminal[0],hour_in_terminal[1],hour_in_terminal[2]);
    }
    else if(btn_status == kBTN_StatusIDLE){
      btn_status = kBTN_StatusIDLE;
    }
	
}

void custom_init(lv_ui *ui)
{

  setup_scr_ui_set_timer_screen(&guider_ui);
  guider_ui.ui_set_timer_screen_del = false;

  lv_obj_set_style_text_line_space(guider_ui.ui_set_timer_screen_hrs_roller, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_line_space(guider_ui.ui_set_timer_screen_min_roller, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_line_space(guider_ui.ui_set_timer_screen_sec_roller, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_line_space(guider_ui.ui_set_timer_screen_color_roller, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
  
  lv_obj_set_height(guider_ui.ui_set_timer_screen_hrs_roller, 110);
  lv_obj_set_height(guider_ui.ui_set_timer_screen_min_roller, 110);
  lv_obj_set_height(guider_ui.ui_set_timer_screen_sec_roller, 110);
  lv_obj_set_height(guider_ui.ui_set_timer_screen_color_roller, 110);
  
  lv_obj_add_event_cb(guider_ui.ui_set_timer_screen_hrs_roller, mask_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_add_event_cb(guider_ui.ui_set_timer_screen_min_roller, mask_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_add_event_cb(guider_ui.ui_set_timer_screen_sec_roller, mask_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_add_event_cb(guider_ui.ui_set_timer_screen_color_roller, mask_event_cb, LV_EVENT_ALL, NULL);
  
  lv_timer_t * timer = lv_timer_create(my_timer, 1000, NULL);

  PRINTF("******Please set the Kitchen Timer*******\r");


}

