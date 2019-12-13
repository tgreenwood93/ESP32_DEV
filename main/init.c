#include "init.h"
#include "cli.h"
#include "server.h"
#include "ap.h"

static const char* TAG = "Init";

/* Console command history can be stored to and loaded from a file.
 * The easiest way to do this is to use FATFS filesystem on top of
 * wear_levelling library.
 */
#if CONFIG_STORE_HISTORY

static void initialize_filesystem()
{
    static wl_handle_t wl_handle;

    const esp_vfs_fat_mount_config_t mount_config = {
            .max_files = 4,
            .format_if_mount_failed = true
    };
    esp_err_t err = esp_vfs_fat_spiflash_mount(MOUNT_PATH, "storage", &mount_config, &wl_handle);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to mount FATFS (%s)", esp_err_to_name(err));
        return;
    }
}
#endif // CONFIG_STORE_HISTORY

static void initialize_nvs()
{
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK( nvs_flash_erase() );
        err = nvs_flash_init();
    }
    ESP_ERROR_CHECK(err);
}

void init_system()
{
    initialize_nvs();

#if CONFIG_STORE_HISTORY
    initialize_filesystem();
#endif

    initialize_console();
    //initialize_server();
    initialize_ap();
    start_esp_server();
    /* Register commands */
    esp_console_register_help_command();
    register_system();
    register_wifi();
    register_nvs();
    register_cli();

}