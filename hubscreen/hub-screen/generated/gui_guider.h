/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
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
  
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *screen_tileview_main;
	lv_obj_t *screen_tileview_main_hub_screen;
	lv_obj_t *screen_tileview_main_settings;
	lv_obj_t *screen_tileview_hub;
	lv_obj_t *screen_tileview_hub_home;
	lv_obj_t *screen_tileview_hub_home_control;
	lv_obj_t *screen_background;
	lv_obj_t *screen_background_label;
	lv_obj_t *screen_cont_date;
	lv_obj_t *screen_back_date;
	lv_obj_t *screen_back_time;
	lv_obj_t *screen_cont_sensor;
	lv_obj_t *screen_icon_temp;
	lv_obj_t *screen_icon_temp_label;
	lv_obj_t *screen_back_temp;
	lv_obj_t *screen_icon_humitidy;
	lv_obj_t *screen_icon_humitidy_label;
	lv_obj_t *screen_back_humidity;
	lv_obj_t *screen_cont_hub_menu;
	lv_obj_t *screen_label_13;
	lv_obj_t *screen_cont_24;
	lv_obj_t *screen_label_14;
	lv_obj_t *screen_imgbtn_5;
	lv_obj_t *screen_imgbtn_5_label;
	lv_obj_t *screen_cont_25;
	lv_obj_t *screen_label_15;
	lv_obj_t *screen_imgbtn_6;
	lv_obj_t *screen_imgbtn_6_label;
	lv_obj_t *screen_cont_26;
	lv_obj_t *screen_label_16;
	lv_obj_t *screen_imgbtn_7;
	lv_obj_t *screen_imgbtn_7_label;
	lv_obj_t *screen_cont_led;
	lv_obj_t *screen_led_1;
	lv_obj_t *screen_led_1_name;
	lv_obj_t *screen_led_1_icon;
	lv_obj_t *screen_led_1_icon_label;
	lv_obj_t *screen_led_2;
	lv_obj_t *screen_led_2_name;
	lv_obj_t *screen_led_2_icon;
	lv_obj_t *screen_led_2_icon_label;
	lv_obj_t *screen_led_3;
	lv_obj_t *screen_led_3_name;
	lv_obj_t *screen_led_3_icon;
	lv_obj_t *screen_led_3_icon_label;
	lv_obj_t *screen_led_4;
	lv_obj_t *screen_led_4_name;
	lv_obj_t *screen_led_4_icon;
	lv_obj_t *screen_led_4_icon_label;
	lv_obj_t *screen_led_5;
	lv_obj_t *screen_led_5_name;
	lv_obj_t *screen_led_5_icon;
	lv_obj_t *screen_led_5_icon_label;
	lv_obj_t *screen_led_6;
	lv_obj_t *screen_led_6_name;
	lv_obj_t *screen_led_6_icon;
	lv_obj_t *screen_led_6_icon_label;
	lv_obj_t *screen_led_7;
	lv_obj_t *screen_led_7_name;
	lv_obj_t *screen_led_7_icon;
	lv_obj_t *screen_led_7_icon_label;
	lv_obj_t *screen_led_8;
	lv_obj_t *screen_led_8_name;
	lv_obj_t *screen_led_8_icon;
	lv_obj_t *screen_led_8_icon_label;
	lv_obj_t *screen_cont_sw;
	lv_obj_t *screen_switch_1;
	lv_obj_t *screen_sw_1_name;
	lv_obj_t *screen_sw_1_icon;
	lv_obj_t *screen_switch_2;
	lv_obj_t *screen_sw_2_name;
	lv_obj_t *screen_sw_2_icon;
	lv_obj_t *screen_switch_3;
	lv_obj_t *screen_sw_3_name;
	lv_obj_t *screen_sw_3_icon;
	lv_obj_t *screen_switch_4;
	lv_obj_t *screen_sw_4_name;
	lv_obj_t *screen_sw_4_icon;
	lv_obj_t *screen_switch_5;
	lv_obj_t *screen_sw_5_name;
	lv_obj_t *screen_sw_5_icon;
	lv_obj_t *screen_switch_6;
	lv_obj_t *screen_sw_6_name;
	lv_obj_t *screen_sw_6_icon;
	lv_obj_t *screen_cont_timer;
	lv_obj_t *screen_timer_1;
	lv_obj_t *screen_timer_1_time;
	lv_obj_t *screen_imgbtn_14;
	lv_obj_t *screen_imgbtn_14_label;
	lv_obj_t *screen_timer_2;
	lv_obj_t *screen_timer_2_time;
	lv_obj_t *screen_imgbtn_15;
	lv_obj_t *screen_imgbtn_15_label;
	lv_obj_t *screen_timer_3;
	lv_obj_t *screen_timer_3_time;
	lv_obj_t *screen_imgbtn_16;
	lv_obj_t *screen_imgbtn_16_label;
	lv_obj_t *screen_timer_4;
	lv_obj_t *screen_timer_4_time;
	lv_obj_t *screen_imgbtn_17;
	lv_obj_t *screen_imgbtn_17_label;
	lv_obj_t *screen_timer_5;
	lv_obj_t *screen_timer_5_time;
	lv_obj_t *screen_imgbtn_18;
	lv_obj_t *screen_imgbtn_18_label;
	lv_obj_t *screen_timer_6;
	lv_obj_t *screen_timer_6_time;
	lv_obj_t *screen_imgbtn_19;
	lv_obj_t *screen_imgbtn_19_label;
	lv_obj_t *screen_win_1;
	lv_obj_t *screen_win_1_item0;
	lv_obj_t *screen_cont_setting_menu;
	lv_obj_t *screen_cont_setting_text;
	lv_obj_t *screen_label_1;
	lv_obj_t *screen_cont_wifi_menu;
	lv_obj_t *screen_label_2;
	lv_obj_t *screen_imgbtn_1;
	lv_obj_t *screen_imgbtn_1_label;
	lv_obj_t *screen_cont_ble_menu;
	lv_obj_t *screen_label_3;
	lv_obj_t *screen_imgbtn_2;
	lv_obj_t *screen_imgbtn_2_label;
	lv_obj_t *screen_cont_zigbe_menu;
	lv_obj_t *screen_zigbee_name;
	lv_obj_t *screen_imgbtn_3;
	lv_obj_t *screen_imgbtn_3_label;
	lv_obj_t *screen_cont_language_menu;
	lv_obj_t *screen_language_name;
	lv_obj_t *screen_imgbtn_4;
	lv_obj_t *screen_imgbtn_4_label;
	lv_obj_t *screen_cont_notify_menu;
	lv_obj_t *screen_label_18;
	lv_obj_t *screen_imgbtn_21;
	lv_obj_t *screen_imgbtn_21_label;
	lv_obj_t *screen_cont_ble;
	lv_obj_t *screen_cont_14;
	lv_obj_t *screen_label_9;
	lv_obj_t *screen_sw_2;
	lv_obj_t *screen_cont_12;
	lv_obj_t *screen_cont_13;
	lv_obj_t *screen_label_8;
	lv_obj_t *screen_btn_2;
	lv_obj_t *screen_btn_2_label;
	lv_obj_t *screen_cont_lang;
	lv_obj_t *screen_cont_18;
	lv_obj_t *screen_label_11;
	lv_obj_t *screen_cont_16;
	lv_obj_t *screen_ddlist_1;
	lv_obj_t *screen_cont_noti;
	lv_obj_t *screen_cont_21;
	lv_obj_t *screen_label_12;
	lv_obj_t *screen_cont_20;
	lv_obj_t *screen_list_1;
	lv_obj_t *screen_list_1_item0;
	lv_obj_t *screen_list_1_item1;
	lv_obj_t *screen_list_1_item2;
	lv_obj_t *screen_cont_zigbee;
	lv_obj_t *screen_cont_30;
	lv_obj_t *screen_label_20;
	lv_obj_t *screen_zigbee_icon;
	lv_obj_t *screen_cont_28;
	lv_obj_t *screen_cont_29;
	lv_obj_t *screen_label_19;
	lv_obj_t *screen_btn_3;
	lv_obj_t *screen_btn_3_label;
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


void setup_scr_screen(lv_ui *ui);
LV_IMG_DECLARE(_background_alpha_800x480);
LV_IMG_DECLARE(_itemperature_alpha_40x30);
LV_IMG_DECLARE(_ihumidity_alpha_31x28);
LV_IMG_DECLARE(_onlight_alpha_38x35);
LV_IMG_DECLARE(_switch_alpha_37x33);
LV_IMG_DECLARE(_clock_alpha_32x32);
LV_IMG_DECLARE(_offlight_alpha_54x52);
LV_IMG_DECLARE(_led_alpha_54x52);
LV_IMG_DECLARE(_offlight_alpha_54x52);
LV_IMG_DECLARE(_led_alpha_54x52);
LV_IMG_DECLARE(_offlight_alpha_54x52);
LV_IMG_DECLARE(_led_alpha_54x52);
LV_IMG_DECLARE(_offlight_alpha_54x52);
LV_IMG_DECLARE(_led_alpha_54x52);
LV_IMG_DECLARE(_offlight_alpha_54x52);
LV_IMG_DECLARE(_led_alpha_54x52);
LV_IMG_DECLARE(_offlight_alpha_54x52);
LV_IMG_DECLARE(_led_alpha_54x52);
LV_IMG_DECLARE(_offlight_alpha_54x52);
LV_IMG_DECLARE(_led_alpha_54x52);
LV_IMG_DECLARE(_offlight_alpha_54x52);
LV_IMG_DECLARE(_led_alpha_54x52);
LV_IMG_DECLARE(_timer_alpha_47x41);
LV_IMG_DECLARE(_timer_alpha_47x41);
LV_IMG_DECLARE(_timer_alpha_47x41);
LV_IMG_DECLARE(_timer_alpha_47x41);
LV_IMG_DECLARE(_timer_alpha_47x41);
LV_IMG_DECLARE(_timer_alpha_47x41);
LV_IMG_DECLARE(_arrow_alpha_38x35);
LV_IMG_DECLARE(_arrow_alpha_38x35);
LV_IMG_DECLARE(_arrow_alpha_38x35);
LV_IMG_DECLARE(_arrow_alpha_38x35);
LV_IMG_DECLARE(_arrow_alpha_38x35);

LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_24)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_Antonio_Regular_32)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_16)
LV_FONT_DECLARE(lv_font_Acme_Regular_25)
LV_FONT_DECLARE(lv_font_montserratMedium_14)
LV_FONT_DECLARE(lv_font_montserratMedium_18)
LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_FontAwesome5_18)


#ifdef __cplusplus
}
#endif
#endif
