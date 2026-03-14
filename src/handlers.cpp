#include "shell/Shell.h"
#include "shell/commands_common.h"
#include "shell/commands_pico.h"
#include "shell/commands_freertos.h"
#include "commands/commands.h"
#include <stdio.h>


static int help(int, const char *[]);

extern const Shell::Handler handlers[];

const Shell::Handler handlers[] = {
    {"help",       help,              "list available commands"},
    {"echo",       command_echo,      "print arguments to console"},
    {"dump",       command_dump,      "hex dump memory region (byte)"},
    {"dump32",     command_dump32,    "hex dump memory region (32-bit words)"},
    {"sensors",    command_sensors,   "read and print sensor values"},
    {"clocks",     command_clocks,    "show system clock frequencies"},
    {"i2c_scan",   command_i2c_scan,  "scan I2C bus for connected devices"},
    {"board_help", command_board_help,"show board pinout"},
    {"chip_id",    command_chip_id,   "show chip and flash memory identity"},
    {"bench",      command_benchmark, "run performance benchmark"},
    {"tasks",      command_tasks,     "list FreeRTOS tasks and stack usage"},
    // required at the end
    {nullptr, nullptr},
};


static int help(int, const char *[]) {
    printf("Commands:\r\n");
    for (int i = 0;; i++) {
        if (!handlers[i].name || !handlers[i].handler) break;

        if (handlers[i].description) {
            printf("  %-16s %s\r\n", handlers[i].name, handlers[i].description);
        } else {
            printf("  %s\r\n", handlers[i].name);
        }
    }
    return 0;
}
