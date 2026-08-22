#include "mods/svc/console.h"
#include <borealis/log.hpp>

#include "registry.hpp"

#include "dusk/ui/ui.hpp"
#include "dusk/ui/command_console.hpp"

namespace dusk::mods::svc {
namespace {

constexpr borealis::Log Log("dusk::mods::console");

ModResult console_print_message(ModContext* context, char* message) {
    if (message == nullptr) {
        return MOD_INVALID_ARGUMENT;
    }
    auto* console = static_cast<ui::CommandConsole*>(
        ui::find_document(ui::DocumentScope::CommandConsole));
    if (console == nullptr) {
        return MOD_UNAVAILABLE;
    }
    console->append_message(message);
    return MOD_OK;
}

constexpr ConsoleService s_consoleService{
    .header = SERVICE_HEADER(ConsoleService, CONSOLE_SERVICE_MAJOR, CONSOLE_SERVICE_MINOR),
    .print_message = console_print_message,
};

}  // namespace

constinit const ServiceModule g_consoleModule{
    .id = CONSOLE_SERVICE_ID,
    .majorVersion = CONSOLE_SERVICE_MAJOR,
    .minorVersion = CONSOLE_SERVICE_MINOR,
    .service = &s_consoleService,
};

}  // namespace dusk::mods::svc
