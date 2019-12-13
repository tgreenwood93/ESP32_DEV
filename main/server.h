#ifndef SERVER_H
#define SERVER_H

#include <esp_wifi.h>
#include <esp_event_loop.h>
#include <esp_log.h>
#include <esp_system.h>
#include <nvs_flash.h>
#include <sys/param.h>

#include <esp_https_server.h>
#include "cmd_wifi.h"

void initialize_server();
void start_esp_server();
void stop_esp_webserver();

#endif // Server