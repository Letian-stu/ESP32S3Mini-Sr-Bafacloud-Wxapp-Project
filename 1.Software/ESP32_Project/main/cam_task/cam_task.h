/*
 * @Author: error: git config user.name & please set dead value or install git
 * @Date: 2023-01-29 10:55
 * @LastEditors: error: git config user.name & please set dead value or install git
 * @LastEditTime: 2023-02-24 23:32
 * @FilePath: \ESP32_Project\main\cam_task\cam_task.h
 * @Description: 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef _CAM_TASK_H
#define _CAM_TASK_H

#include <stdio.h>
#include <stdint.h>
#include <esp_log.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "gui_guider.h"
#include "esp_camera.h"
#include "BaseConfig.h"
#include "lvgl/lvgl.h"

typedef enum
{
    http_stream_mode = 0,
    lvgl_show_mode,
    take_pic_mode
}cam_mode_t;

#define CAM_PIN_PWDN 15
#define CAM_PIN_RESET -1
#define CAM_PIN_XCLK 12
#define CAM_PIN_SIOD 14
#define CAM_PIN_SIOC 13
#define CAM_PIN_D7 9
#define CAM_PIN_D6 8
#define CAM_PIN_D5 7
#define CAM_PIN_D4 5
#define CAM_PIN_D3 3
#define CAM_PIN_D2 1
#define CAM_PIN_D1 2
#define CAM_PIN_D0 4
#define CAM_PIN_VSYNC 11
#define CAM_PIN_HREF 10
#define CAM_PIN_PCLK 6

esp_err_t cam_config_init(void);
void cam_show_task(void *p);
esp_err_t cam_take_pic_config(cam_mode_t mode);
#endif

