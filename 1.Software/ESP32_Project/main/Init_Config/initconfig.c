/*
 * @Author: letian
 * @Date: 2022-11-29 13:57
 * @LastEditors: Letian-stu
 * @LastEditTime: 2023-03-12 10:20
 * @FilePath: /ESP32_Project/main/Init_Config/initconfig.c
 * @Description: 
 * Copyright (c) 2022 by letian 1656733965@qq.com, All Rights Reserved. 
 */
#include "BaseConfig.h"

#define TAG "init"

void Init_Config(void)
{
    ESP_LOGI(TAG,"Start Init");
    Event_Init();
    Sem_Init();
    Queue_Init();
    Times_Init();
    nvs_flash_init();
    if(read_wifi_from_nvs() == ESP_OK) 
    {
        ESP_LOGI(TAG, "wifi data from nvs");
        strncpy ( (char *)sta_ap_wifi_config.sta.ssid, read_wifi_buf.ssid, read_wifi_buf.ssidlen );
        strncpy ( (char *)sta_ap_wifi_config.sta.password, read_wifi_buf.pass, read_wifi_buf.passlen );
        //ESP_LOGI(TAG, "ssid=%s pass=%s",sta_ap_wifi_config.sta.ssid,sta_ap_wifi_config.sta.password);
    }
    sdcard_init(ESP_SD_FS_PATH);
    speech_recognition_init();
    cam_config_init(); 
    xTaskCreatePinnedToCore(appguiTask, "App_Gui",  1024 * 8, NULL, 7, NULL, 1);
    wifi_ap_sta_init();
    mount_storage(ESP_FS_PATH);
    start_wifi_config_server(ESP_SD_FS_PATH);
    Tasks_Init();
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    ESP_LOGI(TAG,"Init Succrss");
}


