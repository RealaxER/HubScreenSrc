/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
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



void setup_scr_screen(lv_ui *ui)
{
	//Write codes screen
	ui->screen = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen, 800, 480);
	lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_tileview_main
	ui->screen_tileview_main = lv_tileview_create(ui->screen);
	ui->screen_tileview_main_hub_screen = lv_tileview_add_tile(ui->screen_tileview_main, 0, 0, LV_DIR_BOTTOM);
	ui->screen_tileview_main_settings = lv_tileview_add_tile(ui->screen_tileview_main, 0, 1, LV_DIR_TOP);
	lv_obj_set_pos(ui->screen_tileview_main, 0, 0);
	lv_obj_set_size(ui->screen_tileview_main, 800, 480);
	lv_obj_set_scrollbar_mode(ui->screen_tileview_main, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_tileview_main, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_tileview_main, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_tileview_main, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_tileview_main, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_tileview_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_tileview_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_tileview_main, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_tileview_main, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_tileview_main, lv_color_hex(0xeaeff3), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_tileview_main, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_tileview_main, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);



	//Write codes screen_tileview_hub
	ui->screen_tileview_hub = lv_tileview_create(ui->screen_tileview_main_hub_screen);
	ui->screen_tileview_hub_home = lv_tileview_add_tile(ui->screen_tileview_hub, 0, 0, LV_DIR_RIGHT);
	ui->screen_tileview_hub_home_control = lv_tileview_add_tile(ui->screen_tileview_hub, 1, 0, LV_DIR_LEFT);
	lv_obj_set_pos(ui->screen_tileview_hub, 0, 0);
	lv_obj_set_size(ui->screen_tileview_hub, 800, 480);
	lv_obj_set_scrollbar_mode(ui->screen_tileview_hub, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_tileview_hub, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_tileview_hub, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_tileview_hub, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_tileview_hub, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_tileview_hub, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_tileview_hub, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_tileview_hub, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_tileview_hub, lv_color_hex(0xeaeff3), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_tileview_hub, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_tileview_hub, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);



	//Write codes screen_background
	ui->screen_background = lv_imgbtn_create(ui->screen_tileview_hub_home);
	lv_obj_add_flag(ui->screen_background, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_background, LV_IMGBTN_STATE_RELEASED, NULL, &_background_alpha_800x480, NULL);
	ui->screen_background_label = lv_label_create(ui->screen_background);
	lv_label_set_text(ui->screen_background_label, "");
	lv_label_set_long_mode(ui->screen_background_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_background_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_background, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_background, 0, 0);
	lv_obj_set_size(ui->screen_background, 800, 480);

	//Write style for screen_background, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_background, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_background, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_background, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_background, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_background, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_background, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_background, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_background, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_background, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_background, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_background, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_background, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_background, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_background, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_background, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_background, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_background, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_background, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_cont_date
	ui->screen_cont_date = lv_obj_create(ui->screen_tileview_hub_home);
	lv_obj_set_pos(ui->screen_cont_date, 472, 280);
	lv_obj_set_size(ui->screen_cont_date, 326, 200);
	lv_obj_set_scrollbar_mode(ui->screen_cont_date, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_back_date
	ui->screen_back_date = lv_label_create(ui->screen_cont_date);
	lv_label_set_text(ui->screen_back_date, "11 May, 2024");
	lv_label_set_long_mode(ui->screen_back_date, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_back_date, 127, 91);
	lv_obj_set_size(ui->screen_back_date, 183, 32);

	//Write style for screen_back_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_back_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_back_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_back_date, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_back_date, &lv_font_montserratMedium_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_back_date, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_back_date, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_back_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_back_date, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_back_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_back_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_back_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_back_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_back_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_back_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_back_time
	ui->screen_back_time = lv_label_create(ui->screen_cont_date);
	lv_label_set_text(ui->screen_back_time, "9:00 AM");
	lv_label_set_long_mode(ui->screen_back_time, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_back_time, 139, 137);
	lv_obj_set_size(ui->screen_back_time, 183, 32);

	//Write style for screen_back_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_back_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_back_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_back_time, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_back_time, &lv_font_Antonio_Regular_32, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_back_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_back_time, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_back_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_back_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_back_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_back_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_back_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_back_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_back_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_back_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_sensor
	ui->screen_cont_sensor = lv_obj_create(ui->screen_tileview_hub_home);
	lv_obj_set_pos(ui->screen_cont_sensor, 455, -1);
	lv_obj_set_size(ui->screen_cont_sensor, 344, 60);
	lv_obj_set_scrollbar_mode(ui->screen_cont_sensor, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_sensor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_sensor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_sensor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_sensor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_sensor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_sensor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_sensor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_sensor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_sensor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_icon_temp
	ui->screen_icon_temp = lv_imgbtn_create(ui->screen_cont_sensor);
	lv_obj_add_flag(ui->screen_icon_temp, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_icon_temp, LV_IMGBTN_STATE_RELEASED, NULL, &_itemperature_alpha_40x30, NULL);
	ui->screen_icon_temp_label = lv_label_create(ui->screen_icon_temp);
	lv_label_set_text(ui->screen_icon_temp_label, "");
	lv_label_set_long_mode(ui->screen_icon_temp_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_icon_temp_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_icon_temp, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_icon_temp, 113, 3);
	lv_obj_set_size(ui->screen_icon_temp, 40, 30);

	//Write style for screen_icon_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_icon_temp, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_icon_temp, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_icon_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_icon_temp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_icon_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_icon_temp, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_icon_temp, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_icon_temp, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_icon_temp, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_icon_temp, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_icon_temp, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_icon_temp, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_icon_temp, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_icon_temp, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_icon_temp, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_icon_temp, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_icon_temp, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_icon_temp, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_icon_temp, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_back_temp
	ui->screen_back_temp = lv_label_create(ui->screen_cont_sensor);
	lv_label_set_text(ui->screen_back_temp, "25°C");
	lv_label_set_long_mode(ui->screen_back_temp, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_back_temp, 149, 6);
	lv_obj_set_size(ui->screen_back_temp, 63, 24);

	//Write style for screen_back_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_back_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_back_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_back_temp, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_back_temp, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_back_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_back_temp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_back_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_back_temp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_back_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_back_temp, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_back_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_back_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_back_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_back_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_icon_humitidy
	ui->screen_icon_humitidy = lv_imgbtn_create(ui->screen_cont_sensor);
	lv_obj_add_flag(ui->screen_icon_humitidy, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_icon_humitidy, LV_IMGBTN_STATE_RELEASED, NULL, &_ihumidity_alpha_31x28, NULL);
	ui->screen_icon_humitidy_label = lv_label_create(ui->screen_icon_humitidy);
	lv_label_set_text(ui->screen_icon_humitidy_label, "");
	lv_label_set_long_mode(ui->screen_icon_humitidy_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_icon_humitidy_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_icon_humitidy, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_icon_humitidy, 233, 4);
	lv_obj_set_size(ui->screen_icon_humitidy, 31, 28);

	//Write style for screen_icon_humitidy, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_icon_humitidy, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_icon_humitidy, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_icon_humitidy, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_icon_humitidy, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_icon_humitidy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_icon_humitidy, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_icon_humitidy, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_icon_humitidy, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_icon_humitidy, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_icon_humitidy, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_icon_humitidy, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_icon_humitidy, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_icon_humitidy, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_icon_humitidy, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_icon_humitidy, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_icon_humitidy, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_icon_humitidy, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_icon_humitidy, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_icon_humitidy, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_back_humidity
	ui->screen_back_humidity = lv_label_create(ui->screen_cont_sensor);
	lv_label_set_text(ui->screen_back_humidity, "70%");
	lv_label_set_long_mode(ui->screen_back_humidity, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_back_humidity, 272, 6);
	lv_obj_set_size(ui->screen_back_humidity, 63, 24);

	//Write style for screen_back_humidity, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_back_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_back_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_back_humidity, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_back_humidity, &lv_font_Alatsi_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_back_humidity, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_back_humidity, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_back_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_back_humidity, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_back_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_back_humidity, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_back_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_back_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_back_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_back_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);



	//Write codes screen_cont_hub_menu
	ui->screen_cont_hub_menu = lv_obj_create(ui->screen_tileview_hub_home_control);
	lv_obj_set_pos(ui->screen_cont_hub_menu, 0, 0);
	lv_obj_set_size(ui->screen_cont_hub_menu, 175, 480);
	lv_obj_set_scrollbar_mode(ui->screen_cont_hub_menu, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_hub_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_hub_menu, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_hub_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_hub_menu, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_hub_menu, LV_BORDER_SIDE_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_hub_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_hub_menu, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_hub_menu, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cont_hub_menu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_hub_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_hub_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_hub_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_hub_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_hub_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_13
	ui->screen_label_13 = lv_label_create(ui->screen_cont_hub_menu);
	lv_label_set_text(ui->screen_label_13, "Home");
	lv_label_set_long_mode(ui->screen_label_13, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_13, 0, 0);
	lv_obj_set_size(ui->screen_label_13, 175, 57);

	//Write style for screen_label_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_13, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_13, &lv_font_Acme_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_13, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_13, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_label_13, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_label_13, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_13, 13, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_24
	ui->screen_cont_24 = lv_obj_create(ui->screen_cont_hub_menu);
	lv_obj_set_pos(ui->screen_cont_24, 7, 76);
	lv_obj_set_size(ui->screen_cont_24, 161, 48);
	lv_obj_set_scrollbar_mode(ui->screen_cont_24, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_24, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_24, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_24, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_24, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_24, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_24, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_24, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cont_24, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_14
	ui->screen_label_14 = lv_label_create(ui->screen_cont_24);
	lv_label_set_text(ui->screen_label_14, "Lights");
	lv_label_set_long_mode(ui->screen_label_14, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_14, 27, 5);
	lv_obj_set_size(ui->screen_label_14, 120, 32);

	//Write style for screen_label_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_14, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_14, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_14, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_14, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_14, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_imgbtn_5
	ui->screen_imgbtn_5 = lv_imgbtn_create(ui->screen_cont_24);
	lv_obj_add_flag(ui->screen_imgbtn_5, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_imgbtn_5, LV_IMGBTN_STATE_RELEASED, NULL, &_onlight_alpha_38x35, NULL);
	ui->screen_imgbtn_5_label = lv_label_create(ui->screen_imgbtn_5);
	lv_label_set_text(ui->screen_imgbtn_5_label, "");
	lv_label_set_long_mode(ui->screen_imgbtn_5_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_imgbtn_5_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_imgbtn_5, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_imgbtn_5, 0, 0);
	lv_obj_set_size(ui->screen_imgbtn_5, 38, 35);

	//Write style for screen_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_imgbtn_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_imgbtn_5, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_imgbtn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_5, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_5, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_5, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_5, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_imgbtn_5, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_5, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_cont_25
	ui->screen_cont_25 = lv_obj_create(ui->screen_cont_hub_menu);
	lv_obj_set_pos(ui->screen_cont_25, 8, 133);
	lv_obj_set_size(ui->screen_cont_25, 161, 48);
	lv_obj_set_scrollbar_mode(ui->screen_cont_25, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_25, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_25, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_25, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_25, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_25, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_25, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_25, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cont_25, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_25, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_15
	ui->screen_label_15 = lv_label_create(ui->screen_cont_25);
	lv_label_set_text(ui->screen_label_15, "Switches");
	lv_label_set_long_mode(ui->screen_label_15, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_15, 34, 5);
	lv_obj_set_size(ui->screen_label_15, 120, 32);

	//Write style for screen_label_15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_15, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_15, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_15, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_15, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_15, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_imgbtn_6
	ui->screen_imgbtn_6 = lv_imgbtn_create(ui->screen_cont_25);
	lv_obj_add_flag(ui->screen_imgbtn_6, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_imgbtn_6, LV_IMGBTN_STATE_RELEASED, NULL, &_switch_alpha_37x33, NULL);
	ui->screen_imgbtn_6_label = lv_label_create(ui->screen_imgbtn_6);
	lv_label_set_text(ui->screen_imgbtn_6_label, "");
	lv_label_set_long_mode(ui->screen_imgbtn_6_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_imgbtn_6_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_imgbtn_6, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_imgbtn_6, 3, 5);
	lv_obj_set_size(ui->screen_imgbtn_6, 37, 33);

	//Write style for screen_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_imgbtn_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_imgbtn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_imgbtn_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_6, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_6, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_imgbtn_6, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_6, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_cont_26
	ui->screen_cont_26 = lv_obj_create(ui->screen_cont_hub_menu);
	lv_obj_set_pos(ui->screen_cont_26, 8, 188);
	lv_obj_set_size(ui->screen_cont_26, 160, 48);
	lv_obj_set_scrollbar_mode(ui->screen_cont_26, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_26, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_26, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_26, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_26, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_26, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_26, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_26, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cont_26, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_26, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_16
	ui->screen_label_16 = lv_label_create(ui->screen_cont_26);
	lv_label_set_text(ui->screen_label_16, "Set timer");
	lv_label_set_long_mode(ui->screen_label_16, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_16, 27, 5);
	lv_obj_set_size(ui->screen_label_16, 120, 32);

	//Write style for screen_label_16, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_16, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_16, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_16, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_16, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_16, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_imgbtn_7
	ui->screen_imgbtn_7 = lv_imgbtn_create(ui->screen_cont_26);
	lv_obj_add_flag(ui->screen_imgbtn_7, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_imgbtn_7, LV_IMGBTN_STATE_RELEASED, NULL, &_clock_alpha_32x32, NULL);
	ui->screen_imgbtn_7_label = lv_label_create(ui->screen_imgbtn_7);
	lv_label_set_text(ui->screen_imgbtn_7_label, "");
	lv_label_set_long_mode(ui->screen_imgbtn_7_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_imgbtn_7_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_imgbtn_7, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_imgbtn_7, 4, 5);
	lv_obj_set_size(ui->screen_imgbtn_7, 32, 32);

	//Write style for screen_imgbtn_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_imgbtn_7, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_imgbtn_7, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_imgbtn_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_imgbtn_7, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_7, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_7, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_imgbtn_7, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_7, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_7, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_imgbtn_7, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_7, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_cont_led
	ui->screen_cont_led = lv_obj_create(ui->screen_tileview_hub_home_control);
	lv_obj_set_pos(ui->screen_cont_led, 204, 26);
	lv_obj_set_size(ui->screen_cont_led, 563, 453);
	lv_obj_set_scrollbar_mode(ui->screen_cont_led, LV_SCROLLBAR_MODE_AUTO);

	//Write style for screen_cont_led, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_led, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_led, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_led, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_led, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_led, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_led, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_led, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_led, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_led_1
	ui->screen_led_1 = lv_obj_create(ui->screen_cont_led);
	lv_obj_set_pos(ui->screen_led_1, 25, 20);
	lv_obj_set_size(ui->screen_led_1, 240, 60);
	lv_obj_set_scrollbar_mode(ui->screen_led_1, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_led_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_led_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_led_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_led_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_led_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_led_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_led_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_led_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_led_1, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_led_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_led_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_led_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_led_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_led_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_led_1_name
	ui->screen_led_1_name = lv_label_create(ui->screen_led_1);
	lv_label_set_text(ui->screen_led_1_name, "Light 1");
	lv_label_set_long_mode(ui->screen_led_1_name, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_led_1_name, 85, 13);
	lv_obj_set_size(ui->screen_led_1_name, 120, 32);

	//Write style for screen_led_1_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_led_1_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_led_1_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_led_1_name, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_led_1_name, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_led_1_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_led_1_name, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_led_1_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_led_1_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_led_1_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_led_1_name, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_led_1_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_led_1_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_led_1_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_1_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_led_1_icon
	ui->screen_led_1_icon = lv_imgbtn_create(ui->screen_led_1);
	lv_obj_add_flag(ui->screen_led_1_icon, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_led_1_icon, LV_IMGBTN_STATE_RELEASED, NULL, &_offlight_alpha_54x52, NULL);
	lv_imgbtn_set_src(ui->screen_led_1_icon, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_led_alpha_54x52, NULL);
	ui->screen_led_1_icon_label = lv_label_create(ui->screen_led_1_icon);
	lv_label_set_text(ui->screen_led_1_icon_label, "");
	lv_label_set_long_mode(ui->screen_led_1_icon_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_led_1_icon_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_led_1_icon, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_led_1_icon, 25, 1);
	lv_obj_set_size(ui->screen_led_1_icon, 54, 52);

	//Write style for screen_led_1_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_led_1_icon, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_led_1_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_led_1_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_led_1_icon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_1_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_led_1_icon, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_led_1_icon, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_led_1_icon, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_led_1_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_led_1_icon, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_led_1_icon, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_led_1_icon, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_led_1_icon, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_led_1_icon, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_led_1_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_led_1_icon, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_led_1_icon, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_led_1_icon, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_led_1_icon, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_led_2
	ui->screen_led_2 = lv_obj_create(ui->screen_cont_led);
	lv_obj_set_pos(ui->screen_led_2, 297, 20);
	lv_obj_set_size(ui->screen_led_2, 240, 60);
	lv_obj_set_scrollbar_mode(ui->screen_led_2, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_led_2, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_led_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_led_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_led_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_led_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_led_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_led_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_led_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_led_2, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_led_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_led_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_led_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_led_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_led_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_led_2_name
	ui->screen_led_2_name = lv_label_create(ui->screen_led_2);
	lv_label_set_text(ui->screen_led_2_name, "Light 2");
	lv_label_set_long_mode(ui->screen_led_2_name, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_led_2_name, 85, 13);
	lv_obj_set_size(ui->screen_led_2_name, 120, 32);

	//Write style for screen_led_2_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_led_2_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_led_2_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_led_2_name, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_led_2_name, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_led_2_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_led_2_name, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_led_2_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_led_2_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_led_2_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_led_2_name, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_led_2_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_led_2_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_led_2_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_2_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_led_2_icon
	ui->screen_led_2_icon = lv_imgbtn_create(ui->screen_led_2);
	lv_obj_add_flag(ui->screen_led_2_icon, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_led_2_icon, LV_IMGBTN_STATE_RELEASED, NULL, &_offlight_alpha_54x52, NULL);
	lv_imgbtn_set_src(ui->screen_led_2_icon, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_led_alpha_54x52, NULL);
	ui->screen_led_2_icon_label = lv_label_create(ui->screen_led_2_icon);
	lv_label_set_text(ui->screen_led_2_icon_label, "");
	lv_label_set_long_mode(ui->screen_led_2_icon_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_led_2_icon_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_led_2_icon, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_led_2_icon, 25, 1);
	lv_obj_set_size(ui->screen_led_2_icon, 54, 52);

	//Write style for screen_led_2_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_led_2_icon, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_led_2_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_led_2_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_led_2_icon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_2_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_led_2_icon, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_led_2_icon, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_led_2_icon, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_led_2_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_led_2_icon, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_led_2_icon, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_led_2_icon, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_led_2_icon, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_led_2_icon, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_led_2_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_led_2_icon, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_led_2_icon, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_led_2_icon, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_led_2_icon, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_led_3
	ui->screen_led_3 = lv_obj_create(ui->screen_cont_led);
	lv_obj_set_pos(ui->screen_led_3, 25, 95);
	lv_obj_set_size(ui->screen_led_3, 240, 60);
	lv_obj_set_scrollbar_mode(ui->screen_led_3, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_led_3, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_led_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_led_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_led_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_led_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_led_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_led_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_led_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_led_3, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_led_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_led_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_led_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_led_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_led_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_led_3_name
	ui->screen_led_3_name = lv_label_create(ui->screen_led_3);
	lv_label_set_text(ui->screen_led_3_name, "Light 3");
	lv_label_set_long_mode(ui->screen_led_3_name, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_led_3_name, 85, 13);
	lv_obj_set_size(ui->screen_led_3_name, 120, 32);

	//Write style for screen_led_3_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_led_3_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_led_3_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_led_3_name, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_led_3_name, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_led_3_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_led_3_name, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_led_3_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_led_3_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_led_3_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_led_3_name, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_led_3_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_led_3_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_led_3_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_3_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_led_3_icon
	ui->screen_led_3_icon = lv_imgbtn_create(ui->screen_led_3);
	lv_obj_add_flag(ui->screen_led_3_icon, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_led_3_icon, LV_IMGBTN_STATE_RELEASED, NULL, &_offlight_alpha_54x52, NULL);
	lv_imgbtn_set_src(ui->screen_led_3_icon, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_led_alpha_54x52, NULL);
	ui->screen_led_3_icon_label = lv_label_create(ui->screen_led_3_icon);
	lv_label_set_text(ui->screen_led_3_icon_label, "");
	lv_label_set_long_mode(ui->screen_led_3_icon_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_led_3_icon_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_led_3_icon, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_led_3_icon, 25, 1);
	lv_obj_set_size(ui->screen_led_3_icon, 54, 52);

	//Write style for screen_led_3_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_led_3_icon, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_led_3_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_led_3_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_led_3_icon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_3_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_led_3_icon, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_led_3_icon, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_led_3_icon, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_led_3_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_led_3_icon, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_led_3_icon, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_led_3_icon, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_led_3_icon, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_led_3_icon, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_led_3_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_led_3_icon, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_led_3_icon, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_led_3_icon, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_led_3_icon, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_led_4
	ui->screen_led_4 = lv_obj_create(ui->screen_cont_led);
	lv_obj_set_pos(ui->screen_led_4, 297, 95);
	lv_obj_set_size(ui->screen_led_4, 240, 60);
	lv_obj_set_scrollbar_mode(ui->screen_led_4, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_led_4, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_led_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_led_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_led_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_led_4, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_led_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_led_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_led_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_led_4, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_led_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_led_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_led_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_led_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_led_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_led_4_name
	ui->screen_led_4_name = lv_label_create(ui->screen_led_4);
	lv_label_set_text(ui->screen_led_4_name, "Light 4");
	lv_label_set_long_mode(ui->screen_led_4_name, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_led_4_name, 86, 13);
	lv_obj_set_size(ui->screen_led_4_name, 120, 32);

	//Write style for screen_led_4_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_led_4_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_led_4_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_led_4_name, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_led_4_name, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_led_4_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_led_4_name, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_led_4_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_led_4_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_led_4_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_led_4_name, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_led_4_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_led_4_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_led_4_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_4_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_led_4_icon
	ui->screen_led_4_icon = lv_imgbtn_create(ui->screen_led_4);
	lv_obj_add_flag(ui->screen_led_4_icon, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_led_4_icon, LV_IMGBTN_STATE_RELEASED, NULL, &_offlight_alpha_54x52, NULL);
	lv_imgbtn_set_src(ui->screen_led_4_icon, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_led_alpha_54x52, NULL);
	ui->screen_led_4_icon_label = lv_label_create(ui->screen_led_4_icon);
	lv_label_set_text(ui->screen_led_4_icon_label, "");
	lv_label_set_long_mode(ui->screen_led_4_icon_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_led_4_icon_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_led_4_icon, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_led_4_icon, 25, 1);
	lv_obj_set_size(ui->screen_led_4_icon, 54, 52);

	//Write style for screen_led_4_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_led_4_icon, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_led_4_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_led_4_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_led_4_icon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_4_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_led_4_icon, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_led_4_icon, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_led_4_icon, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_led_4_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_led_4_icon, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_led_4_icon, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_led_4_icon, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_led_4_icon, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_led_4_icon, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_led_4_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_led_4_icon, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_led_4_icon, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_led_4_icon, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_led_4_icon, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_led_5
	ui->screen_led_5 = lv_obj_create(ui->screen_cont_led);
	lv_obj_set_pos(ui->screen_led_5, 25, 170);
	lv_obj_set_size(ui->screen_led_5, 240, 60);
	lv_obj_set_scrollbar_mode(ui->screen_led_5, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_led_5, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_led_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_led_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_led_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_led_5, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_led_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_led_5, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_led_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_led_5, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_led_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_led_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_led_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_led_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_led_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_led_5_name
	ui->screen_led_5_name = lv_label_create(ui->screen_led_5);
	lv_label_set_text(ui->screen_led_5_name, "Light 5");
	lv_label_set_long_mode(ui->screen_led_5_name, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_led_5_name, 85, 13);
	lv_obj_set_size(ui->screen_led_5_name, 120, 32);

	//Write style for screen_led_5_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_led_5_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_led_5_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_led_5_name, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_led_5_name, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_led_5_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_led_5_name, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_led_5_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_led_5_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_led_5_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_led_5_name, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_led_5_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_led_5_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_led_5_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_5_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_led_5_icon
	ui->screen_led_5_icon = lv_imgbtn_create(ui->screen_led_5);
	lv_obj_add_flag(ui->screen_led_5_icon, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_led_5_icon, LV_IMGBTN_STATE_RELEASED, NULL, &_offlight_alpha_54x52, NULL);
	lv_imgbtn_set_src(ui->screen_led_5_icon, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_led_alpha_54x52, NULL);
	ui->screen_led_5_icon_label = lv_label_create(ui->screen_led_5_icon);
	lv_label_set_text(ui->screen_led_5_icon_label, "");
	lv_label_set_long_mode(ui->screen_led_5_icon_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_led_5_icon_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_led_5_icon, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_led_5_icon, 25, 1);
	lv_obj_set_size(ui->screen_led_5_icon, 54, 52);

	//Write style for screen_led_5_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_led_5_icon, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_led_5_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_led_5_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_led_5_icon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_5_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_led_5_icon, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_led_5_icon, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_led_5_icon, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_led_5_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_led_5_icon, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_led_5_icon, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_led_5_icon, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_led_5_icon, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_led_5_icon, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_led_5_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_led_5_icon, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_led_5_icon, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_led_5_icon, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_led_5_icon, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_led_6
	ui->screen_led_6 = lv_obj_create(ui->screen_cont_led);
	lv_obj_set_pos(ui->screen_led_6, 296, 170);
	lv_obj_set_size(ui->screen_led_6, 240, 60);
	lv_obj_set_scrollbar_mode(ui->screen_led_6, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_led_6, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_led_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_led_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_led_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_led_6, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_led_6, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_led_6, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_led_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_led_6, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_led_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_led_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_led_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_led_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_led_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_led_6_name
	ui->screen_led_6_name = lv_label_create(ui->screen_led_6);
	lv_label_set_text(ui->screen_led_6_name, "Light 6");
	lv_label_set_long_mode(ui->screen_led_6_name, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_led_6_name, 85, 12);
	lv_obj_set_size(ui->screen_led_6_name, 120, 32);

	//Write style for screen_led_6_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_led_6_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_led_6_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_led_6_name, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_led_6_name, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_led_6_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_led_6_name, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_led_6_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_led_6_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_led_6_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_led_6_name, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_led_6_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_led_6_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_led_6_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_6_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_led_6_icon
	ui->screen_led_6_icon = lv_imgbtn_create(ui->screen_led_6);
	lv_obj_add_flag(ui->screen_led_6_icon, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_led_6_icon, LV_IMGBTN_STATE_RELEASED, NULL, &_offlight_alpha_54x52, NULL);
	lv_imgbtn_set_src(ui->screen_led_6_icon, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_led_alpha_54x52, NULL);
	ui->screen_led_6_icon_label = lv_label_create(ui->screen_led_6_icon);
	lv_label_set_text(ui->screen_led_6_icon_label, "");
	lv_label_set_long_mode(ui->screen_led_6_icon_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_led_6_icon_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_led_6_icon, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_led_6_icon, 25, 1);
	lv_obj_set_size(ui->screen_led_6_icon, 54, 52);

	//Write style for screen_led_6_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_led_6_icon, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_led_6_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_led_6_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_led_6_icon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_6_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_led_6_icon, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_led_6_icon, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_led_6_icon, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_led_6_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_led_6_icon, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_led_6_icon, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_led_6_icon, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_led_6_icon, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_led_6_icon, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_led_6_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_led_6_icon, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_led_6_icon, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_led_6_icon, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_led_6_icon, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_led_7
	ui->screen_led_7 = lv_obj_create(ui->screen_cont_led);
	lv_obj_set_pos(ui->screen_led_7, 25, 245);
	lv_obj_set_size(ui->screen_led_7, 240, 60);
	lv_obj_set_scrollbar_mode(ui->screen_led_7, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_led_7, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_led_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_led_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_led_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_led_7, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_led_7, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_led_7, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_led_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_led_7, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_led_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_led_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_led_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_led_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_led_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_led_7_name
	ui->screen_led_7_name = lv_label_create(ui->screen_led_7);
	lv_label_set_text(ui->screen_led_7_name, "Light 6");
	lv_label_set_long_mode(ui->screen_led_7_name, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_led_7_name, 85, 12);
	lv_obj_set_size(ui->screen_led_7_name, 120, 32);

	//Write style for screen_led_7_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_led_7_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_led_7_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_led_7_name, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_led_7_name, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_led_7_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_led_7_name, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_led_7_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_led_7_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_led_7_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_led_7_name, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_led_7_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_led_7_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_led_7_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_7_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_led_7_icon
	ui->screen_led_7_icon = lv_imgbtn_create(ui->screen_led_7);
	lv_obj_add_flag(ui->screen_led_7_icon, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_led_7_icon, LV_IMGBTN_STATE_RELEASED, NULL, &_offlight_alpha_54x52, NULL);
	lv_imgbtn_set_src(ui->screen_led_7_icon, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_led_alpha_54x52, NULL);
	ui->screen_led_7_icon_label = lv_label_create(ui->screen_led_7_icon);
	lv_label_set_text(ui->screen_led_7_icon_label, "");
	lv_label_set_long_mode(ui->screen_led_7_icon_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_led_7_icon_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_led_7_icon, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_led_7_icon, 25, 1);
	lv_obj_set_size(ui->screen_led_7_icon, 54, 52);

	//Write style for screen_led_7_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_led_7_icon, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_led_7_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_led_7_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_led_7_icon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_7_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_led_7_icon, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_led_7_icon, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_led_7_icon, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_led_7_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_led_7_icon, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_led_7_icon, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_led_7_icon, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_led_7_icon, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_led_7_icon, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_led_7_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_led_7_icon, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_led_7_icon, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_led_7_icon, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_led_7_icon, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_led_8
	ui->screen_led_8 = lv_obj_create(ui->screen_cont_led);
	lv_obj_set_pos(ui->screen_led_8, 296, 245);
	lv_obj_set_size(ui->screen_led_8, 240, 60);
	lv_obj_set_scrollbar_mode(ui->screen_led_8, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_led_8, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_led_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_led_8, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_led_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_led_8, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_led_8, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_led_8, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_led_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_led_8, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_led_8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_led_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_led_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_led_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_led_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_led_8_name
	ui->screen_led_8_name = lv_label_create(ui->screen_led_8);
	lv_label_set_text(ui->screen_led_8_name, "Light 6");
	lv_label_set_long_mode(ui->screen_led_8_name, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_led_8_name, 85, 12);
	lv_obj_set_size(ui->screen_led_8_name, 120, 32);

	//Write style for screen_led_8_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_led_8_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_led_8_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_led_8_name, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_led_8_name, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_led_8_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_led_8_name, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_led_8_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_led_8_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_led_8_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_led_8_name, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_led_8_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_led_8_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_led_8_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_8_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_led_8_icon
	ui->screen_led_8_icon = lv_imgbtn_create(ui->screen_led_8);
	lv_obj_add_flag(ui->screen_led_8_icon, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_led_8_icon, LV_IMGBTN_STATE_RELEASED, NULL, &_offlight_alpha_54x52, NULL);
	lv_imgbtn_set_src(ui->screen_led_8_icon, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_led_alpha_54x52, NULL);
	ui->screen_led_8_icon_label = lv_label_create(ui->screen_led_8_icon);
	lv_label_set_text(ui->screen_led_8_icon_label, "");
	lv_label_set_long_mode(ui->screen_led_8_icon_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_led_8_icon_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_led_8_icon, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_led_8_icon, 25, 1);
	lv_obj_set_size(ui->screen_led_8_icon, 54, 52);

	//Write style for screen_led_8_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_led_8_icon, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_led_8_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_led_8_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_led_8_icon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_led_8_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_led_8_icon, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_led_8_icon, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_led_8_icon, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_led_8_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_led_8_icon, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_led_8_icon, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_led_8_icon, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_led_8_icon, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_led_8_icon, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_led_8_icon, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_led_8_icon, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_led_8_icon, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_led_8_icon, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_led_8_icon, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_cont_sw
	ui->screen_cont_sw = lv_obj_create(ui->screen_tileview_hub_home_control);
	lv_obj_set_pos(ui->screen_cont_sw, 204, 26);
	lv_obj_set_size(ui->screen_cont_sw, 563, 453);
	lv_obj_set_scrollbar_mode(ui->screen_cont_sw, LV_SCROLLBAR_MODE_AUTO);

	//Write style for screen_cont_sw, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_sw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_sw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_sw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_sw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_sw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_sw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_sw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_sw, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_switch_1
	ui->screen_switch_1 = lv_obj_create(ui->screen_cont_sw);
	lv_obj_set_pos(ui->screen_switch_1, 25, 20);
	lv_obj_set_size(ui->screen_switch_1, 240, 61);
	lv_obj_set_scrollbar_mode(ui->screen_switch_1, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_switch_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_switch_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_switch_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_switch_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_switch_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_switch_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_switch_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_switch_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_switch_1, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_switch_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_switch_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_switch_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_switch_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_switch_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_switch_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_sw_1_name
	ui->screen_sw_1_name = lv_label_create(ui->screen_switch_1);
	lv_label_set_text(ui->screen_sw_1_name, "Switch 1");
	lv_label_set_long_mode(ui->screen_sw_1_name, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_sw_1_name, 88, 13);
	lv_obj_set_size(ui->screen_sw_1_name, 120, 32);

	//Write style for screen_sw_1_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_sw_1_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sw_1_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_sw_1_name, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_sw_1_name, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_sw_1_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_sw_1_name, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_sw_1_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_sw_1_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_sw_1_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_sw_1_name, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_sw_1_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_sw_1_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_sw_1_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_sw_1_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_sw_1_icon
	ui->screen_sw_1_icon = lv_switch_create(ui->screen_switch_1);
	lv_obj_set_pos(ui->screen_sw_1_icon, 35, 16);
	lv_obj_set_size(ui->screen_sw_1_icon, 50, 25);

	//Write style for screen_sw_1_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_sw_1_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_sw_1_icon, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_sw_1_icon, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_sw_1_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sw_1_icon, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_sw_1_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_sw_1_icon, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screen_sw_1_icon, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screen_sw_1_icon, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->screen_sw_1_icon, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screen_sw_1_icon, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screen_sw_1_icon, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_sw_1_icon, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_sw_1_icon, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_sw_1_icon, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_sw_1_icon, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sw_1_icon, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_switch_2
	ui->screen_switch_2 = lv_obj_create(ui->screen_cont_sw);
	lv_obj_set_pos(ui->screen_switch_2, 300, 20);
	lv_obj_set_size(ui->screen_switch_2, 240, 61);
	lv_obj_set_scrollbar_mode(ui->screen_switch_2, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_switch_2, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_switch_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_switch_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_switch_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_switch_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_switch_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_switch_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_switch_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_switch_2, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_switch_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_switch_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_switch_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_switch_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_switch_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_switch_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_sw_2_name
	ui->screen_sw_2_name = lv_label_create(ui->screen_switch_2);
	lv_label_set_text(ui->screen_sw_2_name, "Switch 2");
	lv_label_set_long_mode(ui->screen_sw_2_name, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_sw_2_name, 88, 13);
	lv_obj_set_size(ui->screen_sw_2_name, 120, 32);

	//Write style for screen_sw_2_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_sw_2_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sw_2_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_sw_2_name, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_sw_2_name, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_sw_2_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_sw_2_name, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_sw_2_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_sw_2_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_sw_2_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_sw_2_name, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_sw_2_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_sw_2_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_sw_2_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_sw_2_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_sw_2_icon
	ui->screen_sw_2_icon = lv_switch_create(ui->screen_switch_2);
	lv_obj_set_pos(ui->screen_sw_2_icon, 35, 16);
	lv_obj_set_size(ui->screen_sw_2_icon, 50, 25);

	//Write style for screen_sw_2_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_sw_2_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_sw_2_icon, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_sw_2_icon, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_sw_2_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sw_2_icon, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_sw_2_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_sw_2_icon, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screen_sw_2_icon, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screen_sw_2_icon, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->screen_sw_2_icon, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screen_sw_2_icon, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screen_sw_2_icon, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_sw_2_icon, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_sw_2_icon, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_sw_2_icon, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_sw_2_icon, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sw_2_icon, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_switch_3
	ui->screen_switch_3 = lv_obj_create(ui->screen_cont_sw);
	lv_obj_set_pos(ui->screen_switch_3, 25, 93);
	lv_obj_set_size(ui->screen_switch_3, 240, 61);
	lv_obj_set_scrollbar_mode(ui->screen_switch_3, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_switch_3, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_switch_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_switch_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_switch_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_switch_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_switch_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_switch_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_switch_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_switch_3, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_switch_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_switch_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_switch_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_switch_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_switch_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_switch_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_sw_3_name
	ui->screen_sw_3_name = lv_label_create(ui->screen_switch_3);
	lv_label_set_text(ui->screen_sw_3_name, "Switch 3");
	lv_label_set_long_mode(ui->screen_sw_3_name, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_sw_3_name, 87, 12);
	lv_obj_set_size(ui->screen_sw_3_name, 120, 32);

	//Write style for screen_sw_3_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_sw_3_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sw_3_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_sw_3_name, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_sw_3_name, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_sw_3_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_sw_3_name, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_sw_3_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_sw_3_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_sw_3_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_sw_3_name, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_sw_3_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_sw_3_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_sw_3_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_sw_3_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_sw_3_icon
	ui->screen_sw_3_icon = lv_switch_create(ui->screen_switch_3);
	lv_obj_set_pos(ui->screen_sw_3_icon, 35, 16);
	lv_obj_set_size(ui->screen_sw_3_icon, 50, 25);

	//Write style for screen_sw_3_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_sw_3_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_sw_3_icon, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_sw_3_icon, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_sw_3_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sw_3_icon, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_sw_3_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_sw_3_icon, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screen_sw_3_icon, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screen_sw_3_icon, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->screen_sw_3_icon, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screen_sw_3_icon, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screen_sw_3_icon, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_sw_3_icon, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_sw_3_icon, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_sw_3_icon, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_sw_3_icon, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sw_3_icon, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_switch_4
	ui->screen_switch_4 = lv_obj_create(ui->screen_cont_sw);
	lv_obj_set_pos(ui->screen_switch_4, 300, 93);
	lv_obj_set_size(ui->screen_switch_4, 240, 61);
	lv_obj_set_scrollbar_mode(ui->screen_switch_4, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_switch_4, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_switch_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_switch_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_switch_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_switch_4, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_switch_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_switch_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_switch_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_switch_4, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_switch_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_switch_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_switch_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_switch_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_switch_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_switch_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_sw_4_name
	ui->screen_sw_4_name = lv_label_create(ui->screen_switch_4);
	lv_label_set_text(ui->screen_sw_4_name, "Switch 4");
	lv_label_set_long_mode(ui->screen_sw_4_name, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_sw_4_name, 87, 12);
	lv_obj_set_size(ui->screen_sw_4_name, 120, 32);

	//Write style for screen_sw_4_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_sw_4_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sw_4_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_sw_4_name, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_sw_4_name, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_sw_4_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_sw_4_name, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_sw_4_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_sw_4_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_sw_4_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_sw_4_name, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_sw_4_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_sw_4_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_sw_4_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_sw_4_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_sw_4_icon
	ui->screen_sw_4_icon = lv_switch_create(ui->screen_switch_4);
	lv_obj_set_pos(ui->screen_sw_4_icon, 35, 16);
	lv_obj_set_size(ui->screen_sw_4_icon, 50, 25);

	//Write style for screen_sw_4_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_sw_4_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_sw_4_icon, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_sw_4_icon, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_sw_4_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sw_4_icon, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_sw_4_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_sw_4_icon, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screen_sw_4_icon, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screen_sw_4_icon, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->screen_sw_4_icon, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screen_sw_4_icon, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screen_sw_4_icon, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_sw_4_icon, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_sw_4_icon, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_sw_4_icon, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_sw_4_icon, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sw_4_icon, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_switch_5
	ui->screen_switch_5 = lv_obj_create(ui->screen_cont_sw);
	lv_obj_set_pos(ui->screen_switch_5, 25, 165);
	lv_obj_set_size(ui->screen_switch_5, 240, 61);
	lv_obj_set_scrollbar_mode(ui->screen_switch_5, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_switch_5, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_switch_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_switch_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_switch_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_switch_5, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_switch_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_switch_5, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_switch_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_switch_5, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_switch_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_switch_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_switch_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_switch_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_switch_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_switch_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_sw_5_name
	ui->screen_sw_5_name = lv_label_create(ui->screen_switch_5);
	lv_label_set_text(ui->screen_sw_5_name, "Switch 5");
	lv_label_set_long_mode(ui->screen_sw_5_name, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_sw_5_name, 87, 12);
	lv_obj_set_size(ui->screen_sw_5_name, 120, 32);

	//Write style for screen_sw_5_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_sw_5_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sw_5_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_sw_5_name, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_sw_5_name, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_sw_5_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_sw_5_name, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_sw_5_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_sw_5_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_sw_5_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_sw_5_name, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_sw_5_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_sw_5_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_sw_5_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_sw_5_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_sw_5_icon
	ui->screen_sw_5_icon = lv_switch_create(ui->screen_switch_5);
	lv_obj_set_pos(ui->screen_sw_5_icon, 35, 16);
	lv_obj_set_size(ui->screen_sw_5_icon, 50, 25);

	//Write style for screen_sw_5_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_sw_5_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_sw_5_icon, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_sw_5_icon, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_sw_5_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sw_5_icon, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_sw_5_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_sw_5_icon, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screen_sw_5_icon, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screen_sw_5_icon, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->screen_sw_5_icon, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screen_sw_5_icon, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screen_sw_5_icon, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_sw_5_icon, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_sw_5_icon, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_sw_5_icon, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_sw_5_icon, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sw_5_icon, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_switch_6
	ui->screen_switch_6 = lv_obj_create(ui->screen_cont_sw);
	lv_obj_set_pos(ui->screen_switch_6, 300, 165);
	lv_obj_set_size(ui->screen_switch_6, 240, 61);
	lv_obj_set_scrollbar_mode(ui->screen_switch_6, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_switch_6, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_switch_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_switch_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_switch_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_switch_6, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_switch_6, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_switch_6, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_switch_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_switch_6, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_switch_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_switch_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_switch_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_switch_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_switch_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_switch_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_sw_6_name
	ui->screen_sw_6_name = lv_label_create(ui->screen_switch_6);
	lv_label_set_text(ui->screen_sw_6_name, "Switch 6");
	lv_label_set_long_mode(ui->screen_sw_6_name, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_sw_6_name, 87, 12);
	lv_obj_set_size(ui->screen_sw_6_name, 120, 32);

	//Write style for screen_sw_6_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_sw_6_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sw_6_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_sw_6_name, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_sw_6_name, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_sw_6_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_sw_6_name, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_sw_6_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_sw_6_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_sw_6_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_sw_6_name, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_sw_6_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_sw_6_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_sw_6_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_sw_6_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_sw_6_icon
	ui->screen_sw_6_icon = lv_switch_create(ui->screen_switch_6);
	lv_obj_set_pos(ui->screen_sw_6_icon, 35, 16);
	lv_obj_set_size(ui->screen_sw_6_icon, 50, 25);

	//Write style for screen_sw_6_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_sw_6_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_sw_6_icon, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_sw_6_icon, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_sw_6_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sw_6_icon, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_sw_6_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_sw_6_icon, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screen_sw_6_icon, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screen_sw_6_icon, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->screen_sw_6_icon, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screen_sw_6_icon, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screen_sw_6_icon, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_sw_6_icon, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_sw_6_icon, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_sw_6_icon, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_sw_6_icon, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sw_6_icon, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_cont_timer
	ui->screen_cont_timer = lv_obj_create(ui->screen_tileview_hub_home_control);
	lv_obj_set_pos(ui->screen_cont_timer, 204, 25);
	lv_obj_set_size(ui->screen_cont_timer, 563, 453);
	lv_obj_set_scrollbar_mode(ui->screen_cont_timer, LV_SCROLLBAR_MODE_AUTO);

	//Write style for screen_cont_timer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_timer_1
	ui->screen_timer_1 = lv_obj_create(ui->screen_cont_timer);
	lv_obj_set_pos(ui->screen_timer_1, 25, 20);
	lv_obj_set_size(ui->screen_timer_1, 240, 61);
	lv_obj_set_scrollbar_mode(ui->screen_timer_1, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_timer_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_timer_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_timer_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_timer_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_timer_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_timer_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_timer_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_timer_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_timer_1, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_timer_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_timer_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_timer_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_timer_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_timer_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_timer_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_timer_1_time
	ui->screen_timer_1_time = lv_label_create(ui->screen_timer_1);
	lv_label_set_text(ui->screen_timer_1_time, "10:50-20/10");
	lv_label_set_long_mode(ui->screen_timer_1_time, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_timer_1_time, 58, 14);
	lv_obj_set_size(ui->screen_timer_1_time, 173, 32);

	//Write style for screen_timer_1_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_timer_1_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_timer_1_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_timer_1_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_timer_1_time, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_timer_1_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_timer_1_time, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_timer_1_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_timer_1_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_timer_1_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_timer_1_time, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_timer_1_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_timer_1_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_timer_1_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_timer_1_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_imgbtn_14
	ui->screen_imgbtn_14 = lv_imgbtn_create(ui->screen_timer_1);
	lv_obj_add_flag(ui->screen_imgbtn_14, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_imgbtn_14, LV_IMGBTN_STATE_RELEASED, NULL, &_timer_alpha_47x41, NULL);
	ui->screen_imgbtn_14_label = lv_label_create(ui->screen_imgbtn_14);
	lv_label_set_text(ui->screen_imgbtn_14_label, "");
	lv_label_set_long_mode(ui->screen_imgbtn_14_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_imgbtn_14_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_imgbtn_14, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_imgbtn_14, 12, 7);
	lv_obj_set_size(ui->screen_imgbtn_14, 47, 41);

	//Write style for screen_imgbtn_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_imgbtn_14, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_imgbtn_14, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_imgbtn_14, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_imgbtn_14, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_14, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_14, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_14, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_14, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_14, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_imgbtn_14, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_14, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_14, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_14, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_14, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_14, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_imgbtn_14, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_14, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_timer_2
	ui->screen_timer_2 = lv_obj_create(ui->screen_cont_timer);
	lv_obj_set_pos(ui->screen_timer_2, 302, 20);
	lv_obj_set_size(ui->screen_timer_2, 240, 61);
	lv_obj_set_scrollbar_mode(ui->screen_timer_2, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_timer_2, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_timer_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_timer_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_timer_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_timer_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_timer_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_timer_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_timer_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_timer_2, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_timer_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_timer_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_timer_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_timer_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_timer_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_timer_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_timer_2_time
	ui->screen_timer_2_time = lv_label_create(ui->screen_timer_2);
	lv_label_set_text(ui->screen_timer_2_time, "5:30-08/10");
	lv_label_set_long_mode(ui->screen_timer_2_time, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_timer_2_time, 58, 14);
	lv_obj_set_size(ui->screen_timer_2_time, 173, 32);

	//Write style for screen_timer_2_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_timer_2_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_timer_2_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_timer_2_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_timer_2_time, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_timer_2_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_timer_2_time, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_timer_2_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_timer_2_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_timer_2_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_timer_2_time, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_timer_2_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_timer_2_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_timer_2_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_timer_2_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_imgbtn_15
	ui->screen_imgbtn_15 = lv_imgbtn_create(ui->screen_timer_2);
	lv_obj_add_flag(ui->screen_imgbtn_15, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_imgbtn_15, LV_IMGBTN_STATE_RELEASED, NULL, &_timer_alpha_47x41, NULL);
	ui->screen_imgbtn_15_label = lv_label_create(ui->screen_imgbtn_15);
	lv_label_set_text(ui->screen_imgbtn_15_label, "");
	lv_label_set_long_mode(ui->screen_imgbtn_15_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_imgbtn_15_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_imgbtn_15, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_imgbtn_15, 12, 7);
	lv_obj_set_size(ui->screen_imgbtn_15, 47, 41);

	//Write style for screen_imgbtn_15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_imgbtn_15, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_imgbtn_15, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_imgbtn_15, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_imgbtn_15, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_15, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_15, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_15, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_15, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_15, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_imgbtn_15, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_15, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_15, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_15, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_15, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_15, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_imgbtn_15, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_15, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_timer_3
	ui->screen_timer_3 = lv_obj_create(ui->screen_cont_timer);
	lv_obj_set_pos(ui->screen_timer_3, 25, 95);
	lv_obj_set_size(ui->screen_timer_3, 240, 61);
	lv_obj_set_scrollbar_mode(ui->screen_timer_3, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_timer_3, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_timer_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_timer_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_timer_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_timer_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_timer_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_timer_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_timer_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_timer_3, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_timer_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_timer_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_timer_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_timer_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_timer_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_timer_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_timer_3_time
	ui->screen_timer_3_time = lv_label_create(ui->screen_timer_3);
	lv_label_set_text(ui->screen_timer_3_time, "7:30-08/10");
	lv_label_set_long_mode(ui->screen_timer_3_time, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_timer_3_time, 57, 13);
	lv_obj_set_size(ui->screen_timer_3_time, 173, 32);

	//Write style for screen_timer_3_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_timer_3_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_timer_3_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_timer_3_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_timer_3_time, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_timer_3_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_timer_3_time, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_timer_3_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_timer_3_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_timer_3_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_timer_3_time, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_timer_3_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_timer_3_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_timer_3_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_timer_3_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_imgbtn_16
	ui->screen_imgbtn_16 = lv_imgbtn_create(ui->screen_timer_3);
	lv_obj_add_flag(ui->screen_imgbtn_16, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_imgbtn_16, LV_IMGBTN_STATE_RELEASED, NULL, &_timer_alpha_47x41, NULL);
	ui->screen_imgbtn_16_label = lv_label_create(ui->screen_imgbtn_16);
	lv_label_set_text(ui->screen_imgbtn_16_label, "");
	lv_label_set_long_mode(ui->screen_imgbtn_16_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_imgbtn_16_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_imgbtn_16, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_imgbtn_16, 12, 7);
	lv_obj_set_size(ui->screen_imgbtn_16, 47, 41);

	//Write style for screen_imgbtn_16, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_imgbtn_16, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_imgbtn_16, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_imgbtn_16, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_imgbtn_16, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_16, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_16, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_16, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_16, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_16, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_imgbtn_16, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_16, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_16, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_16, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_16, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_16, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_imgbtn_16, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_16, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_timer_4
	ui->screen_timer_4 = lv_obj_create(ui->screen_cont_timer);
	lv_obj_set_pos(ui->screen_timer_4, 302, 95);
	lv_obj_set_size(ui->screen_timer_4, 240, 61);
	lv_obj_set_scrollbar_mode(ui->screen_timer_4, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_timer_4, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_timer_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_timer_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_timer_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_timer_4, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_timer_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_timer_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_timer_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_timer_4, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_timer_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_timer_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_timer_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_timer_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_timer_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_timer_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_timer_4_time
	ui->screen_timer_4_time = lv_label_create(ui->screen_timer_4);
	lv_label_set_text(ui->screen_timer_4_time, "1:50-10/5");
	lv_label_set_long_mode(ui->screen_timer_4_time, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_timer_4_time, 58, 14);
	lv_obj_set_size(ui->screen_timer_4_time, 173, 32);

	//Write style for screen_timer_4_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_timer_4_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_timer_4_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_timer_4_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_timer_4_time, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_timer_4_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_timer_4_time, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_timer_4_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_timer_4_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_timer_4_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_timer_4_time, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_timer_4_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_timer_4_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_timer_4_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_timer_4_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_imgbtn_17
	ui->screen_imgbtn_17 = lv_imgbtn_create(ui->screen_timer_4);
	lv_obj_add_flag(ui->screen_imgbtn_17, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_imgbtn_17, LV_IMGBTN_STATE_RELEASED, NULL, &_timer_alpha_47x41, NULL);
	ui->screen_imgbtn_17_label = lv_label_create(ui->screen_imgbtn_17);
	lv_label_set_text(ui->screen_imgbtn_17_label, "");
	lv_label_set_long_mode(ui->screen_imgbtn_17_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_imgbtn_17_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_imgbtn_17, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_imgbtn_17, 11, 7);
	lv_obj_set_size(ui->screen_imgbtn_17, 47, 41);

	//Write style for screen_imgbtn_17, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_imgbtn_17, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_imgbtn_17, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_17, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_imgbtn_17, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_imgbtn_17, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_17, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_17, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_17, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_17, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_17, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_imgbtn_17, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_17, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_17, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_17, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_17, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_17, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_imgbtn_17, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_17, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_timer_5
	ui->screen_timer_5 = lv_obj_create(ui->screen_cont_timer);
	lv_obj_set_pos(ui->screen_timer_5, 25, 170);
	lv_obj_set_size(ui->screen_timer_5, 240, 61);
	lv_obj_set_scrollbar_mode(ui->screen_timer_5, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_timer_5, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_timer_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_timer_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_timer_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_timer_5, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_timer_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_timer_5, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_timer_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_timer_5, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_timer_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_timer_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_timer_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_timer_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_timer_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_timer_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_timer_5_time
	ui->screen_timer_5_time = lv_label_create(ui->screen_timer_5);
	lv_label_set_text(ui->screen_timer_5_time, "7:30-08/10");
	lv_label_set_long_mode(ui->screen_timer_5_time, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_timer_5_time, 57, 13);
	lv_obj_set_size(ui->screen_timer_5_time, 173, 32);

	//Write style for screen_timer_5_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_timer_5_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_timer_5_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_timer_5_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_timer_5_time, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_timer_5_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_timer_5_time, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_timer_5_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_timer_5_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_timer_5_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_timer_5_time, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_timer_5_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_timer_5_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_timer_5_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_timer_5_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_imgbtn_18
	ui->screen_imgbtn_18 = lv_imgbtn_create(ui->screen_timer_5);
	lv_obj_add_flag(ui->screen_imgbtn_18, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_imgbtn_18, LV_IMGBTN_STATE_RELEASED, NULL, &_timer_alpha_47x41, NULL);
	ui->screen_imgbtn_18_label = lv_label_create(ui->screen_imgbtn_18);
	lv_label_set_text(ui->screen_imgbtn_18_label, "");
	lv_label_set_long_mode(ui->screen_imgbtn_18_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_imgbtn_18_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_imgbtn_18, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_imgbtn_18, 12, 7);
	lv_obj_set_size(ui->screen_imgbtn_18, 47, 41);

	//Write style for screen_imgbtn_18, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_imgbtn_18, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_imgbtn_18, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_18, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_imgbtn_18, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_imgbtn_18, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_18, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_18, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_18, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_18, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_18, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_imgbtn_18, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_18, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_18, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_18, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_18, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_18, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_imgbtn_18, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_18, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_timer_6
	ui->screen_timer_6 = lv_obj_create(ui->screen_cont_timer);
	lv_obj_set_pos(ui->screen_timer_6, 302, 170);
	lv_obj_set_size(ui->screen_timer_6, 240, 61);
	lv_obj_set_scrollbar_mode(ui->screen_timer_6, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_timer_6, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_timer_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_timer_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_timer_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_timer_6, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_timer_6, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_timer_6, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_timer_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_timer_6, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_timer_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_timer_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_timer_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_timer_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_timer_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_timer_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_timer_6_time
	ui->screen_timer_6_time = lv_label_create(ui->screen_timer_6);
	lv_label_set_text(ui->screen_timer_6_time, "7:30-08/10");
	lv_label_set_long_mode(ui->screen_timer_6_time, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_timer_6_time, 57, 13);
	lv_obj_set_size(ui->screen_timer_6_time, 173, 32);

	//Write style for screen_timer_6_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_timer_6_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_timer_6_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_timer_6_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_timer_6_time, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_timer_6_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_timer_6_time, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_timer_6_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_timer_6_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_timer_6_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_timer_6_time, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_timer_6_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_timer_6_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_timer_6_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_timer_6_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_imgbtn_19
	ui->screen_imgbtn_19 = lv_imgbtn_create(ui->screen_timer_6);
	lv_obj_add_flag(ui->screen_imgbtn_19, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_imgbtn_19, LV_IMGBTN_STATE_RELEASED, NULL, &_timer_alpha_47x41, NULL);
	ui->screen_imgbtn_19_label = lv_label_create(ui->screen_imgbtn_19);
	lv_label_set_text(ui->screen_imgbtn_19_label, "");
	lv_label_set_long_mode(ui->screen_imgbtn_19_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_imgbtn_19_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_imgbtn_19, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_imgbtn_19, 12, 7);
	lv_obj_set_size(ui->screen_imgbtn_19, 47, 41);

	//Write style for screen_imgbtn_19, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_imgbtn_19, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_imgbtn_19, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_19, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_imgbtn_19, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_imgbtn_19, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_19, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_19, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_19, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_19, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_19, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_imgbtn_19, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_19, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_19, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_19, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_19, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_19, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_imgbtn_19, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_19, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_win_1
	ui->screen_win_1 = lv_win_create(ui->screen_tileview_hub_home_control, 55);
	lv_obj_t * screen_win_1_title = lv_win_add_title(ui->screen_win_1, "Control device information");
	ui->screen_win_1_item0 = lv_win_add_btn(ui->screen_win_1, LV_SYMBOL_CLOSE, 40);
	lv_obj_t *screen_win_1_label = lv_label_create(lv_win_get_content(ui->screen_win_1));
	lv_obj_set_scrollbar_mode(lv_win_get_content(ui->screen_win_1), LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(screen_win_1_label, "Light 1 [on]\n\nSwitch 2 [off]");
	lv_obj_set_pos(ui->screen_win_1, 176, -1);
	lv_obj_set_size(ui->screen_win_1, 623, 480);
	lv_obj_set_scrollbar_mode(ui->screen_win_1, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_win_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_win_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_win_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_win_1, lv_color_hex(0xeeeef6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_win_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->screen_win_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_win_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_win_1_extra_content_main_default
	static lv_style_t style_screen_win_1_extra_content_main_default;
	ui_init_style(&style_screen_win_1_extra_content_main_default);
	
	lv_style_set_bg_opa(&style_screen_win_1_extra_content_main_default, 255);
	lv_style_set_bg_color(&style_screen_win_1_extra_content_main_default, lv_color_hex(0xeeeef6));
	lv_style_set_bg_grad_dir(&style_screen_win_1_extra_content_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_text_color(&style_screen_win_1_extra_content_main_default, lv_color_hex(0x393c41));
	lv_style_set_text_font(&style_screen_win_1_extra_content_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_screen_win_1_extra_content_main_default, 255);
	lv_style_set_text_letter_space(&style_screen_win_1_extra_content_main_default, 0);
	lv_style_set_text_line_space(&style_screen_win_1_extra_content_main_default, 2);
	lv_obj_add_style(lv_win_get_content(ui->screen_win_1), &style_screen_win_1_extra_content_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_win_1_extra_header_main_default
	static lv_style_t style_screen_win_1_extra_header_main_default;
	ui_init_style(&style_screen_win_1_extra_header_main_default);
	
	lv_style_set_bg_opa(&style_screen_win_1_extra_header_main_default, 255);
	lv_style_set_bg_color(&style_screen_win_1_extra_header_main_default, lv_color_hex(0xe6e6e6));
	lv_style_set_bg_grad_dir(&style_screen_win_1_extra_header_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_text_color(&style_screen_win_1_extra_header_main_default, lv_color_hex(0x393c41));
	lv_style_set_text_font(&style_screen_win_1_extra_header_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_opa(&style_screen_win_1_extra_header_main_default, 255);
	lv_style_set_text_letter_space(&style_screen_win_1_extra_header_main_default, 0);
	lv_style_set_text_line_space(&style_screen_win_1_extra_header_main_default, 2);
	lv_obj_add_style(lv_win_get_header(ui->screen_win_1), &style_screen_win_1_extra_header_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_win_1_extra_btns_main_default
	static lv_style_t style_screen_win_1_extra_btns_main_default;
	ui_init_style(&style_screen_win_1_extra_btns_main_default);
	
	lv_style_set_radius(&style_screen_win_1_extra_btns_main_default, 8);
	lv_style_set_border_width(&style_screen_win_1_extra_btns_main_default, 0);
	lv_style_set_bg_opa(&style_screen_win_1_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_screen_win_1_extra_btns_main_default, lv_color_hex(0x2195f6));
	lv_style_set_bg_grad_dir(&style_screen_win_1_extra_btns_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_shadow_width(&style_screen_win_1_extra_btns_main_default, 0);
	lv_obj_add_style(ui->screen_win_1_item0, &style_screen_win_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);



	//Write codes screen_cont_setting_menu
	ui->screen_cont_setting_menu = lv_obj_create(ui->screen_tileview_main_settings);
	lv_obj_set_pos(ui->screen_cont_setting_menu, 0, 0);
	lv_obj_set_size(ui->screen_cont_setting_menu, 175, 480);
	lv_obj_set_scrollbar_mode(ui->screen_cont_setting_menu, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_setting_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_setting_menu, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_setting_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_setting_menu, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_setting_menu, LV_BORDER_SIDE_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_setting_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_setting_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_setting_menu, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cont_setting_menu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_setting_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_setting_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_setting_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_setting_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_setting_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_setting_text
	ui->screen_cont_setting_text = lv_obj_create(ui->screen_cont_setting_menu);
	lv_obj_set_pos(ui->screen_cont_setting_text, 0, 0);
	lv_obj_set_size(ui->screen_cont_setting_text, 175, 75);
	lv_obj_set_scrollbar_mode(ui->screen_cont_setting_text, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_setting_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_setting_text, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_setting_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_setting_text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_setting_text, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_setting_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_setting_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_setting_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_setting_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_setting_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_setting_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_setting_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_1
	ui->screen_label_1 = lv_label_create(ui->screen_cont_setting_text);
	lv_label_set_text(ui->screen_label_1, "Settings");
	lv_label_set_long_mode(ui->screen_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_1, 17, 25);
	lv_obj_set_size(ui->screen_label_1, 143, 32);

	//Write style for screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_1, lv_color_hex(0x268cf2), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_1, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_wifi_menu
	ui->screen_cont_wifi_menu = lv_obj_create(ui->screen_cont_setting_menu);
	lv_obj_set_pos(ui->screen_cont_wifi_menu, 7, 101);
	lv_obj_set_size(ui->screen_cont_wifi_menu, 156, 48);
	lv_obj_set_scrollbar_mode(ui->screen_cont_wifi_menu, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_wifi_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_wifi_menu, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_wifi_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_wifi_menu, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_wifi_menu, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_wifi_menu, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_wifi_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_wifi_menu, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cont_wifi_menu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_wifi_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_wifi_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_wifi_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_wifi_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_wifi_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_2
	ui->screen_label_2 = lv_label_create(ui->screen_cont_wifi_menu);
	lv_label_set_text(ui->screen_label_2, "Wifi");
	lv_label_set_long_mode(ui->screen_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_2, 5, 5);
	lv_obj_set_size(ui->screen_label_2, 56, 32);

	//Write style for screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_2, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_2, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_imgbtn_1
	ui->screen_imgbtn_1 = lv_imgbtn_create(ui->screen_cont_wifi_menu);
	lv_obj_add_flag(ui->screen_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_arrow_alpha_38x35, NULL);
	ui->screen_imgbtn_1_label = lv_label_create(ui->screen_imgbtn_1);
	lv_label_set_text(ui->screen_imgbtn_1_label, "");
	lv_label_set_long_mode(ui->screen_imgbtn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_imgbtn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_imgbtn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_imgbtn_1, 110, 4);
	lv_obj_set_size(ui->screen_imgbtn_1, 38, 35);

	//Write style for screen_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_imgbtn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_imgbtn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_imgbtn_1, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_1, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_cont_ble_menu
	ui->screen_cont_ble_menu = lv_obj_create(ui->screen_cont_setting_menu);
	lv_obj_set_pos(ui->screen_cont_ble_menu, 7, 157);
	lv_obj_set_size(ui->screen_cont_ble_menu, 156, 48);
	lv_obj_set_scrollbar_mode(ui->screen_cont_ble_menu, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_ble_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_ble_menu, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_ble_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_ble_menu, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_ble_menu, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_ble_menu, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_ble_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_ble_menu, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cont_ble_menu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_ble_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_ble_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_ble_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_ble_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_ble_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_3
	ui->screen_label_3 = lv_label_create(ui->screen_cont_ble_menu);
	lv_label_set_text(ui->screen_label_3, "Bluetooth");
	lv_label_set_long_mode(ui->screen_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_3, 4, 10);
	lv_obj_set_size(ui->screen_label_3, 98, 32);

	//Write style for screen_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_3, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_3, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_imgbtn_2
	ui->screen_imgbtn_2 = lv_imgbtn_create(ui->screen_cont_ble_menu);
	lv_obj_add_flag(ui->screen_imgbtn_2, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_imgbtn_2, LV_IMGBTN_STATE_RELEASED, NULL, &_arrow_alpha_38x35, NULL);
	ui->screen_imgbtn_2_label = lv_label_create(ui->screen_imgbtn_2);
	lv_label_set_text(ui->screen_imgbtn_2_label, "");
	lv_label_set_long_mode(ui->screen_imgbtn_2_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_imgbtn_2_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_imgbtn_2, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_imgbtn_2, 109, 7);
	lv_obj_set_size(ui->screen_imgbtn_2, 38, 35);

	//Write style for screen_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_imgbtn_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_imgbtn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_imgbtn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_2, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_2, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_imgbtn_2, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_2, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_cont_zigbe_menu
	ui->screen_cont_zigbe_menu = lv_obj_create(ui->screen_cont_setting_menu);
	lv_obj_set_pos(ui->screen_cont_zigbe_menu, 7, 214);
	lv_obj_set_size(ui->screen_cont_zigbe_menu, 156, 48);
	lv_obj_set_scrollbar_mode(ui->screen_cont_zigbe_menu, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_zigbe_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_zigbe_menu, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_zigbe_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_zigbe_menu, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_zigbe_menu, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_zigbe_menu, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_zigbe_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_zigbe_menu, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cont_zigbe_menu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_zigbe_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_zigbe_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_zigbe_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_zigbe_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_zigbe_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_zigbee_name
	ui->screen_zigbee_name = lv_label_create(ui->screen_cont_zigbe_menu);
	lv_label_set_text(ui->screen_zigbee_name, "Zigbee");
	lv_label_set_long_mode(ui->screen_zigbee_name, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_zigbee_name, 6, 7);
	lv_obj_set_size(ui->screen_zigbee_name, 94, 32);

	//Write style for screen_zigbee_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_zigbee_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_zigbee_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_zigbee_name, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_zigbee_name, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_zigbee_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_zigbee_name, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_zigbee_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_zigbee_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_zigbee_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_zigbee_name, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_zigbee_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_zigbee_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_zigbee_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_zigbee_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_imgbtn_3
	ui->screen_imgbtn_3 = lv_imgbtn_create(ui->screen_cont_zigbe_menu);
	lv_obj_add_flag(ui->screen_imgbtn_3, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_imgbtn_3, LV_IMGBTN_STATE_RELEASED, NULL, &_arrow_alpha_38x35, NULL);
	ui->screen_imgbtn_3_label = lv_label_create(ui->screen_imgbtn_3);
	lv_label_set_text(ui->screen_imgbtn_3_label, "");
	lv_label_set_long_mode(ui->screen_imgbtn_3_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_imgbtn_3_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_imgbtn_3, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_imgbtn_3, 109, 3);
	lv_obj_set_size(ui->screen_imgbtn_3, 38, 35);

	//Write style for screen_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_imgbtn_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_imgbtn_3, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_imgbtn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_3, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_3, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_imgbtn_3, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_3, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_3, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_3, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_3, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_imgbtn_3, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_3, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_cont_language_menu
	ui->screen_cont_language_menu = lv_obj_create(ui->screen_cont_setting_menu);
	lv_obj_set_pos(ui->screen_cont_language_menu, 7, 272);
	lv_obj_set_size(ui->screen_cont_language_menu, 156, 48);
	lv_obj_set_scrollbar_mode(ui->screen_cont_language_menu, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_language_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_language_menu, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_language_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_language_menu, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_language_menu, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_language_menu, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_language_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_language_menu, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cont_language_menu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_language_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_language_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_language_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_language_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_language_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_language_name
	ui->screen_language_name = lv_label_create(ui->screen_cont_language_menu);
	lv_label_set_text(ui->screen_language_name, "Language");
	lv_label_set_long_mode(ui->screen_language_name, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_language_name, 3, 7);
	lv_obj_set_size(ui->screen_language_name, 120, 32);

	//Write style for screen_language_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_language_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_language_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_language_name, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_language_name, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_language_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_language_name, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_language_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_language_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_language_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_language_name, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_language_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_language_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_language_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_language_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_imgbtn_4
	ui->screen_imgbtn_4 = lv_imgbtn_create(ui->screen_cont_language_menu);
	lv_obj_add_flag(ui->screen_imgbtn_4, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_imgbtn_4, LV_IMGBTN_STATE_RELEASED, NULL, &_arrow_alpha_38x35, NULL);
	ui->screen_imgbtn_4_label = lv_label_create(ui->screen_imgbtn_4);
	lv_label_set_text(ui->screen_imgbtn_4_label, "");
	lv_label_set_long_mode(ui->screen_imgbtn_4_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_imgbtn_4_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_imgbtn_4, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_imgbtn_4, 113, 3);
	lv_obj_set_size(ui->screen_imgbtn_4, 38, 35);

	//Write style for screen_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_imgbtn_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_imgbtn_4, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_imgbtn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_4, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_4, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_4, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_4, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_imgbtn_4, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_4, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_cont_notify_menu
	ui->screen_cont_notify_menu = lv_obj_create(ui->screen_cont_setting_menu);
	lv_obj_set_pos(ui->screen_cont_notify_menu, 7, 330);
	lv_obj_set_size(ui->screen_cont_notify_menu, 156, 48);
	lv_obj_set_scrollbar_mode(ui->screen_cont_notify_menu, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_notify_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_notify_menu, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_cont_notify_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_cont_notify_menu, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_cont_notify_menu, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_notify_menu, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_notify_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_cont_notify_menu, lv_color_hex(0x252525), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_cont_notify_menu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_notify_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_notify_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_notify_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_notify_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_notify_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_18
	ui->screen_label_18 = lv_label_create(ui->screen_cont_notify_menu);
	lv_label_set_text(ui->screen_label_18, "Notification");
	lv_label_set_long_mode(ui->screen_label_18, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_18, 3, 7);
	lv_obj_set_size(ui->screen_label_18, 120, 32);

	//Write style for screen_label_18, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_18, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_18, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_18, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_18, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_18, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_18, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_imgbtn_21
	ui->screen_imgbtn_21 = lv_imgbtn_create(ui->screen_cont_notify_menu);
	lv_obj_add_flag(ui->screen_imgbtn_21, LV_OBJ_FLAG_CHECKABLE);
	lv_imgbtn_set_src(ui->screen_imgbtn_21, LV_IMGBTN_STATE_RELEASED, NULL, &_arrow_alpha_38x35, NULL);
	ui->screen_imgbtn_21_label = lv_label_create(ui->screen_imgbtn_21);
	lv_label_set_text(ui->screen_imgbtn_21_label, "");
	lv_label_set_long_mode(ui->screen_imgbtn_21_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_imgbtn_21_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_imgbtn_21, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_imgbtn_21, 113, 3);
	lv_obj_set_size(ui->screen_imgbtn_21, 38, 35);

	//Write style for screen_imgbtn_21, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_imgbtn_21, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_imgbtn_21, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_21, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_imgbtn_21, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_imgbtn_21, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_21, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_21, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_21, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_21, 255, LV_PART_MAIN|LV_STATE_PRESSED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_21, 0, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style for screen_imgbtn_21, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_21, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_color(ui->screen_imgbtn_21, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_imgbtn_21, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_imgbtn_21, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_imgbtn_21, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_imgbtn_21, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
	lv_obj_set_style_img_opa(ui->screen_imgbtn_21, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

	//Write codes screen_cont_ble
	ui->screen_cont_ble = lv_obj_create(ui->screen_tileview_main_settings);
	lv_obj_set_pos(ui->screen_cont_ble, 207, 32);
	lv_obj_set_size(ui->screen_cont_ble, 560, 447);
	lv_obj_set_scrollbar_mode(ui->screen_cont_ble, LV_SCROLLBAR_MODE_ACTIVE);
	lv_obj_add_flag(ui->screen_cont_ble, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_cont_ble, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_ble, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_ble, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_ble, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_ble, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_ble, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_ble, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_ble, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_ble, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_14
	ui->screen_cont_14 = lv_obj_create(ui->screen_cont_ble);
	lv_obj_set_pos(ui->screen_cont_14, 0, -1);
	lv_obj_set_size(ui->screen_cont_14, 560, 43);
	lv_obj_set_scrollbar_mode(ui->screen_cont_14, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_cont_14, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_cont_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_9
	ui->screen_label_9 = lv_label_create(ui->screen_cont_14);
	lv_label_set_text(ui->screen_label_9, "Bluetooth");
	lv_label_set_long_mode(ui->screen_label_9, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_9, 2, 5);
	lv_obj_set_size(ui->screen_label_9, 100, 32);

	//Write style for screen_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_9, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_9, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_sw_2
	ui->screen_sw_2 = lv_switch_create(ui->screen_cont_14);
	lv_obj_set_pos(ui->screen_sw_2, 143, 2);
	lv_obj_set_size(ui->screen_sw_2, 40, 20);

	//Write style for screen_sw_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_sw_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_sw_2, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_sw_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_sw_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sw_2, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_sw_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_sw_2, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screen_sw_2, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screen_sw_2, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->screen_sw_2, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screen_sw_2, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screen_sw_2, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_sw_2, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_sw_2, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_sw_2, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_sw_2, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sw_2, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_cont_12
	ui->screen_cont_12 = lv_obj_create(ui->screen_cont_ble);
	lv_obj_set_pos(ui->screen_cont_12, -4, 70);
	lv_obj_set_size(ui->screen_cont_12, 560, 376);
	lv_obj_set_scrollbar_mode(ui->screen_cont_12, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_13
	ui->screen_cont_13 = lv_obj_create(ui->screen_cont_12);
	lv_obj_set_pos(ui->screen_cont_13, 8, 0);
	lv_obj_set_size(ui->screen_cont_13, 550, 62);
	lv_obj_set_scrollbar_mode(ui->screen_cont_13, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_cont_13, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_cont_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_8
	ui->screen_label_8 = lv_label_create(ui->screen_cont_13);
	lv_label_set_text(ui->screen_label_8, "Bluetooth 1");
	lv_label_set_long_mode(ui->screen_label_8, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_8, -2, 20);
	lv_obj_set_size(ui->screen_label_8, 120, 32);

	//Write style for screen_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_8, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_8, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_btn_2
	ui->screen_btn_2 = lv_btn_create(ui->screen_cont_13);
	ui->screen_btn_2_label = lv_label_create(ui->screen_btn_2);
	lv_label_set_text(ui->screen_btn_2_label, "Connect");
	lv_label_set_long_mode(ui->screen_btn_2_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_btn_2_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_btn_2_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_btn_2, 443, 5);
	lv_obj_set_size(ui->screen_btn_2, 100, 50);

	//Write style for screen_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_btn_2, lv_color_hex(0x5597ff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_lang
	ui->screen_cont_lang = lv_obj_create(ui->screen_tileview_main_settings);
	lv_obj_set_pos(ui->screen_cont_lang, 207, 32);
	lv_obj_set_size(ui->screen_cont_lang, 560, 447);
	lv_obj_set_scrollbar_mode(ui->screen_cont_lang, LV_SCROLLBAR_MODE_ACTIVE);
	lv_obj_add_flag(ui->screen_cont_lang, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_cont_lang, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_lang, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_lang, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_lang, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_lang, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_lang, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_lang, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_lang, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_lang, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_18
	ui->screen_cont_18 = lv_obj_create(ui->screen_cont_lang);
	lv_obj_set_pos(ui->screen_cont_18, 0, -1);
	lv_obj_set_size(ui->screen_cont_18, 560, 43);
	lv_obj_set_scrollbar_mode(ui->screen_cont_18, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_18, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_18, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_11
	ui->screen_label_11 = lv_label_create(ui->screen_cont_18);
	lv_label_set_text(ui->screen_label_11, "Language");
	lv_label_set_long_mode(ui->screen_label_11, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_11, 2, 5);
	lv_obj_set_size(ui->screen_label_11, 123, 32);

	//Write style for screen_label_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_11, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_11, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_11, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_16
	ui->screen_cont_16 = lv_obj_create(ui->screen_cont_lang);
	lv_obj_set_pos(ui->screen_cont_16, -4, 70);
	lv_obj_set_size(ui->screen_cont_16, 560, 376);
	lv_obj_set_scrollbar_mode(ui->screen_cont_16, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_16, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_ddlist_1
	ui->screen_ddlist_1 = lv_dropdown_create(ui->screen_cont_16);
	lv_dropdown_set_options(ui->screen_ddlist_1, "Vietnamese\nEnglish");
	lv_obj_set_pos(ui->screen_ddlist_1, 13, 5);
	lv_obj_set_size(ui->screen_ddlist_1, 322, 30);

	//Write style for screen_ddlist_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_ddlist_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_ddlist_1, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_ddlist_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_ddlist_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_ddlist_1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_ddlist_1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_ddlist_1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_ddlist_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_ddlist_1, 126, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_ddlist_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_ddlist_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_ddlist_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_ddlist_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_text_color(ui->screen_ddlist_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_ddlist_1, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_ddlist_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screen_ddlist_1, 1, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_opa(ui->screen_ddlist_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->screen_ddlist_1, lv_color_hex(0x654f4f), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_side(ui->screen_ddlist_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_top(ui->screen_ddlist_1, 8, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_left(ui->screen_ddlist_1, 6, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_right(ui->screen_ddlist_1, 6, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_radius(ui->screen_ddlist_1, 3, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_opa(ui->screen_ddlist_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screen_ddlist_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->screen_ddlist_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_ddlist_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_ddlist_1, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_text_color(ui->screen_ddlist_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->screen_ddlist_1, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->screen_ddlist_1, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->screen_ddlist_1, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_opa(ui->screen_ddlist_1, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_color(ui->screen_ddlist_1, lv_color_hex(0x654f4f), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_side(ui->screen_ddlist_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_top(ui->screen_ddlist_1, 8, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_left(ui->screen_ddlist_1, 6, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_right(ui->screen_ddlist_1, 6, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->screen_ddlist_1, 3, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_opa(ui->screen_ddlist_1, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->screen_ddlist_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->screen_ddlist_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->screen_ddlist_1, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write style for screen_ddlist_1, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
	lv_obj_set_style_text_color(ui->screen_ddlist_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_text_font(ui->screen_ddlist_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_text_opa(ui->screen_ddlist_1, 255, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_border_width(ui->screen_ddlist_1, 1, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_border_opa(ui->screen_ddlist_1, 255, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_border_color(ui->screen_ddlist_1, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_border_side(ui->screen_ddlist_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_pad_top(ui->screen_ddlist_1, 8, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_pad_left(ui->screen_ddlist_1, 6, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_pad_right(ui->screen_ddlist_1, 6, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_radius(ui->screen_ddlist_1, 3, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_bg_opa(ui->screen_ddlist_1, 255, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_bg_color(ui->screen_ddlist_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_bg_grad_dir(ui->screen_ddlist_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
	lv_obj_set_style_shadow_width(ui->screen_ddlist_1, 0, LV_PART_MAIN|LV_STATE_DISABLED);

	//Write style state: LV_STATE_CHECKED for &style_screen_ddlist_1_extra_list_selected_checked
	static lv_style_t style_screen_ddlist_1_extra_list_selected_checked;
	ui_init_style(&style_screen_ddlist_1_extra_list_selected_checked);
	
	lv_style_set_border_width(&style_screen_ddlist_1_extra_list_selected_checked, 2);
	lv_style_set_border_opa(&style_screen_ddlist_1_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_screen_ddlist_1_extra_list_selected_checked, lv_color_hex(0x654f4f));
	lv_style_set_border_side(&style_screen_ddlist_1_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_ddlist_1_extra_list_selected_checked, 3);
	lv_style_set_bg_opa(&style_screen_ddlist_1_extra_list_selected_checked, 110);
	lv_style_set_bg_color(&style_screen_ddlist_1_extra_list_selected_checked, lv_color_hex(0x000000));
	lv_style_set_bg_grad_dir(&style_screen_ddlist_1_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_1), &style_screen_ddlist_1_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_screen_ddlist_1_extra_list_main_default
	static lv_style_t style_screen_ddlist_1_extra_list_main_default;
	ui_init_style(&style_screen_ddlist_1_extra_list_main_default);
	
	lv_style_set_max_height(&style_screen_ddlist_1_extra_list_main_default, 90);
	lv_style_set_text_color(&style_screen_ddlist_1_extra_list_main_default, lv_color_hex(0xffffff));
	lv_style_set_text_font(&style_screen_ddlist_1_extra_list_main_default, &lv_font_montserratMedium_14);
	lv_style_set_text_opa(&style_screen_ddlist_1_extra_list_main_default, 255);
	lv_style_set_border_width(&style_screen_ddlist_1_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_screen_ddlist_1_extra_list_main_default, 255);
	lv_style_set_border_color(&style_screen_ddlist_1_extra_list_main_default, lv_color_hex(0x654f4f));
	lv_style_set_border_side(&style_screen_ddlist_1_extra_list_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_ddlist_1_extra_list_main_default, 3);
	lv_style_set_bg_opa(&style_screen_ddlist_1_extra_list_main_default, 138);
	lv_style_set_bg_color(&style_screen_ddlist_1_extra_list_main_default, lv_color_hex(0x000000));
	lv_style_set_bg_grad_dir(&style_screen_ddlist_1_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_1), &style_screen_ddlist_1_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_ddlist_1_extra_list_scrollbar_default
	static lv_style_t style_screen_ddlist_1_extra_list_scrollbar_default;
	ui_init_style(&style_screen_ddlist_1_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_screen_ddlist_1_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_screen_ddlist_1_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_screen_ddlist_1_extra_list_scrollbar_default, lv_color_hex(0x000000));
	lv_style_set_bg_grad_dir(&style_screen_ddlist_1_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_1), &style_screen_ddlist_1_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes screen_cont_noti
	ui->screen_cont_noti = lv_obj_create(ui->screen_tileview_main_settings);
	lv_obj_set_pos(ui->screen_cont_noti, 207, 32);
	lv_obj_set_size(ui->screen_cont_noti, 560, 447);
	lv_obj_set_scrollbar_mode(ui->screen_cont_noti, LV_SCROLLBAR_MODE_ACTIVE);
	lv_obj_add_flag(ui->screen_cont_noti, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_cont_noti, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_noti, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_noti, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_noti, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_noti, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_noti, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_noti, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_noti, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_noti, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_21
	ui->screen_cont_21 = lv_obj_create(ui->screen_cont_noti);
	lv_obj_set_pos(ui->screen_cont_21, 0, -1);
	lv_obj_set_size(ui->screen_cont_21, 560, 40);
	lv_obj_set_scrollbar_mode(ui->screen_cont_21, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_21, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_12
	ui->screen_label_12 = lv_label_create(ui->screen_cont_21);
	lv_label_set_text(ui->screen_label_12, "Notification");
	lv_label_set_long_mode(ui->screen_label_12, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_12, 2, 5);
	lv_obj_set_size(ui->screen_label_12, 155, 32);

	//Write style for screen_label_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_12, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_12, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_12, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_20
	ui->screen_cont_20 = lv_obj_create(ui->screen_cont_noti);
	lv_obj_set_pos(ui->screen_cont_20, -4, 70);
	lv_obj_set_size(ui->screen_cont_20, 560, 376);
	lv_obj_set_scrollbar_mode(ui->screen_cont_20, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_20, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_list_1
	ui->screen_list_1 = lv_list_create(ui->screen_cont_20);
	ui->screen_list_1_item0 = lv_list_add_btn(ui->screen_list_1, LV_SYMBOL_BATTERY_1, "Battery is running low");
	ui->screen_list_1_item1 = lv_list_add_btn(ui->screen_list_1, LV_SYMBOL_BELL, "New software is  available");
	ui->screen_list_1_item2 = lv_list_add_btn(ui->screen_list_1, LV_SYMBOL_CHARGE, "SW1 is turning on");
	lv_obj_set_pos(ui->screen_list_1, 15, -3);
	lv_obj_set_size(ui->screen_list_1, 522, 380);
	lv_obj_set_scrollbar_mode(ui->screen_list_1, LV_SCROLLBAR_MODE_ACTIVE);

	//Write style state: LV_STATE_DEFAULT for &style_screen_list_1_main_main_default
	static lv_style_t style_screen_list_1_main_main_default;
	ui_init_style(&style_screen_list_1_main_main_default);
	
	lv_style_set_pad_top(&style_screen_list_1_main_main_default, 5);
	lv_style_set_pad_left(&style_screen_list_1_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_list_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_list_1_main_main_default, 0);
	lv_style_set_bg_opa(&style_screen_list_1_main_main_default, 0);
	lv_style_set_border_width(&style_screen_list_1_main_main_default, 0);
	lv_style_set_radius(&style_screen_list_1_main_main_default, 7);
	lv_style_set_shadow_width(&style_screen_list_1_main_main_default, 0);
	lv_obj_add_style(ui->screen_list_1, &style_screen_list_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_list_1_main_scrollbar_default
	static lv_style_t style_screen_list_1_main_scrollbar_default;
	ui_init_style(&style_screen_list_1_main_scrollbar_default);
	
	lv_style_set_radius(&style_screen_list_1_main_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_screen_list_1_main_scrollbar_default, 255);
	lv_style_set_bg_color(&style_screen_list_1_main_scrollbar_default, lv_color_hex(0xffffff));
	lv_style_set_bg_grad_dir(&style_screen_list_1_main_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(ui->screen_list_1, &style_screen_list_1_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_list_1_extra_btns_main_default
	static lv_style_t style_screen_list_1_extra_btns_main_default;
	ui_init_style(&style_screen_list_1_extra_btns_main_default);
	
	lv_style_set_pad_top(&style_screen_list_1_extra_btns_main_default, 5);
	lv_style_set_pad_left(&style_screen_list_1_extra_btns_main_default, 10);
	lv_style_set_pad_right(&style_screen_list_1_extra_btns_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_list_1_extra_btns_main_default, 10);
	lv_style_set_border_width(&style_screen_list_1_extra_btns_main_default, 1);
	lv_style_set_border_opa(&style_screen_list_1_extra_btns_main_default, 255);
	lv_style_set_border_color(&style_screen_list_1_extra_btns_main_default, lv_color_hex(0x6f6969));
	lv_style_set_border_side(&style_screen_list_1_extra_btns_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_text_color(&style_screen_list_1_extra_btns_main_default, lv_color_hex(0xfef6ea));
	lv_style_set_text_font(&style_screen_list_1_extra_btns_main_default, &lv_font_FontAwesome5_18);
	lv_style_set_text_opa(&style_screen_list_1_extra_btns_main_default, 255);
	lv_style_set_radius(&style_screen_list_1_extra_btns_main_default, 0);
	lv_style_set_bg_opa(&style_screen_list_1_extra_btns_main_default, 0);
	lv_obj_add_style(ui->screen_list_1_item2, &style_screen_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_list_1_item1, &style_screen_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_style(ui->screen_list_1_item0, &style_screen_list_1_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_list_1_extra_texts_main_default
	static lv_style_t style_screen_list_1_extra_texts_main_default;
	ui_init_style(&style_screen_list_1_extra_texts_main_default);
	
	lv_style_set_pad_top(&style_screen_list_1_extra_texts_main_default, 6);
	lv_style_set_pad_left(&style_screen_list_1_extra_texts_main_default, 5);
	lv_style_set_pad_right(&style_screen_list_1_extra_texts_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_list_1_extra_texts_main_default, 0);
	lv_style_set_border_width(&style_screen_list_1_extra_texts_main_default, 0);
	lv_style_set_text_color(&style_screen_list_1_extra_texts_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_screen_list_1_extra_texts_main_default, &lv_font_montserratMedium_18);
	lv_style_set_text_opa(&style_screen_list_1_extra_texts_main_default, 255);
	lv_style_set_radius(&style_screen_list_1_extra_texts_main_default, 3);
	lv_style_set_bg_opa(&style_screen_list_1_extra_texts_main_default, 0);

	//Write codes screen_cont_zigbee
	ui->screen_cont_zigbee = lv_obj_create(ui->screen_tileview_main_settings);
	lv_obj_set_pos(ui->screen_cont_zigbee, 216, 42);
	lv_obj_set_size(ui->screen_cont_zigbee, 560, 447);
	lv_obj_set_scrollbar_mode(ui->screen_cont_zigbee, LV_SCROLLBAR_MODE_ACTIVE);
	lv_obj_add_flag(ui->screen_cont_zigbee, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_cont_zigbee, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_zigbee, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_zigbee, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_zigbee, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_zigbee, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_zigbee, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_zigbee, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_zigbee, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_zigbee, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_30
	ui->screen_cont_30 = lv_obj_create(ui->screen_cont_zigbee);
	lv_obj_set_pos(ui->screen_cont_30, 0, -1);
	lv_obj_set_size(ui->screen_cont_30, 560, 43);
	lv_obj_set_scrollbar_mode(ui->screen_cont_30, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_30, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_30, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_20
	ui->screen_label_20 = lv_label_create(ui->screen_cont_30);
	lv_label_set_text(ui->screen_label_20, "Zigbee");
	lv_label_set_long_mode(ui->screen_label_20, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_20, 2, 5);
	lv_obj_set_size(ui->screen_label_20, 100, 32);

	//Write style for screen_label_20, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_20, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_20, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_20, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_20, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_20, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_zigbee_icon
	ui->screen_zigbee_icon = lv_switch_create(ui->screen_cont_30);
	lv_obj_set_pos(ui->screen_zigbee_icon, 116, 2);
	lv_obj_set_size(ui->screen_zigbee_icon, 40, 20);

	//Write style for screen_zigbee_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_zigbee_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_zigbee_icon, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_zigbee_icon, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_zigbee_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_zigbee_icon, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_zigbee_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_zigbee_icon, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
	lv_obj_set_style_bg_opa(ui->screen_zigbee_icon, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screen_zigbee_icon, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->screen_zigbee_icon, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screen_zigbee_icon, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style for screen_zigbee_icon, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_zigbee_icon, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_zigbee_icon, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_zigbee_icon, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_zigbee_icon, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_zigbee_icon, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_cont_28
	ui->screen_cont_28 = lv_obj_create(ui->screen_cont_zigbee);
	lv_obj_set_pos(ui->screen_cont_28, -4, 70);
	lv_obj_set_size(ui->screen_cont_28, 560, 376);
	lv_obj_set_scrollbar_mode(ui->screen_cont_28, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_28, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_28, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_cont_29
	ui->screen_cont_29 = lv_obj_create(ui->screen_cont_28);
	lv_obj_set_pos(ui->screen_cont_29, 8, 0);
	lv_obj_set_size(ui->screen_cont_29, 550, 62);
	lv_obj_set_scrollbar_mode(ui->screen_cont_29, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_cont_29, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_cont_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_cont_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_cont_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_cont_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_cont_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_cont_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_cont_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_cont_29, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_19
	ui->screen_label_19 = lv_label_create(ui->screen_cont_29);
	lv_label_set_text(ui->screen_label_19, "Zigbee 1");
	lv_label_set_long_mode(ui->screen_label_19, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_label_19, 6, 16);
	lv_obj_set_size(ui->screen_label_19, 100, 32);

	//Write style for screen_label_19, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_label_19, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_label_19, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_label_19, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_label_19, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_label_19, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_btn_3
	ui->screen_btn_3 = lv_btn_create(ui->screen_cont_29);
	ui->screen_btn_3_label = lv_label_create(ui->screen_btn_3);
	lv_label_set_text(ui->screen_btn_3_label, "Connect");
	lv_label_set_long_mode(ui->screen_btn_3_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_btn_3_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_btn_3_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_btn_3, 443, 5);
	lv_obj_set_size(ui->screen_btn_3, 100, 50);

	//Write style for screen_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_btn_3, lv_color_hex(0x5597ff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of screen.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->screen);

	//Init events for screen.
	events_init_screen(ui);
}
