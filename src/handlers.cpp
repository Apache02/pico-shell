#include "shell/commands_common.h"
#include "shell/commands_pico.h"
#include "commands/commands.h"
#include <stdio.h>


static void help(Console &console);

extern const Console::Handler handlers[] = {
        {"help",       help},
        {"echo",       command_echo},
        {"dump",       command_dump},
        {"dump32",     command_dump32},
        {"sensors",    command_sensors},
        {"clocks",     command_clocks},
        {"i2c_scan",   command_i2c_scan},
        {"board_help", command_board_help},
        {"chip_id",    command_chip_id},
        {"bench",      command_benchmark},
        // required at the end
        {nullptr,      nullptr},
};


void help(Console &console) {
    printf("Commands:\r\n");
    for (int i = 0;; i++) {
        if (!handlers[i].name || !handlers[i].handler) {
            break;
        }

        printf("  %s\r\n", handlers[i].name);
    }
}
