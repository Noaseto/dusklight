#pragma once

#include <mods/api.h>

#ifdef __cplusplus
#include <mods/service.hpp>
#endif

#define CONSOLE_SERVICE_ID "dev.twilitrealm.dusklight.console"
#define CONSOLE_SERVICE_MAJOR 1u
#define CONSOLE_SERVICE_MINOR 0u

typedef struct ConsoleService {
    ServiceHeader header;

    ModResult (*print_message)(ModContext* ctx, char* message);
    // maybe register_command (at mod init surely)
    // maybe unregister_command (at mod shutdown surely)
    // maybe add_tab (at mod init surely)
    // maybe remove_tab (at mod shutdown surely)
} ConsoleService;

MOD_DECLARE_SERVICE(
    ConsoleService, svc_console, CONSOLE_SERVICE_ID,CONSOLE_SERVICE_MAJOR,CONSOLE_SERVICE_MINOR);