#ifndef CLI_H
#define CLI_H

#include <stdio.h>
#include <string.h>
#include "esp_system.h"
#include "esp_log.h"
#include "esp_console.h"
#include "esp_vfs_dev.h"
#include "driver/uart.h"
#include "linenoise/linenoise.h"
#include "argtable3/argtable3.h"
#include "cmd_decl.h"
#include "esp_vfs_fat.h"
#include "nvs.h"
#include "nvs_flash.h"

#ifdef __cplusplus
extern "C" {
#endif

void initialize_console(void);
void cli_tasks();
void register_cli(void);

#ifdef __cplusplus
} // extern "C"
#endif
 
#endif // CLI_H