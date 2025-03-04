#ifndef BACKTOMAIN_H
#define BACKTOMAIN_H

#include "esp_ota_ops.h"
#include "esp_log.h"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "EXTERNAL_APP_EXIT";

/*
 *Basically makes FACTORY PARTITION as bootable partition
 * and restarts the ESP32 to boot from the factory partition.
 */
void return_to_main_firmware()
{
    ESP_LOGI(TAG, "Returning to main firmware...");
    const esp_partition_t *factory_partition = esp_partition_find_first(
        ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_FACTORY, NULL);
    if (factory_partition == NULL)
    {
        ESP_LOGE(TAG, "Factory partition not found!");
        return;
    }
    esp_err_t err = esp_ota_set_boot_partition(factory_partition);
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to set boot partition (%s)", esp_err_to_name(err));
        return;
    }
    ESP_LOGI(TAG, "Boot partition set to factory. Restarting...");
    vTaskDelay(pdMS_TO_TICKS(500)); // Short delay for logs
    esp_restart();
}

#endif // BACKTOMAIN_H
