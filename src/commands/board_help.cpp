#include "commands.h"
#include "shell/console_colors.h"

#include <stdio.h>


int command_board_help(int, const char *[]) {
    printf("                             --------------                           \r\n");
    printf("           [I2C 0 SDA |  0] | o   |__|   o | [%s] 5V                  \r\n", COLOR_RED("VBUS"));
    printf("           [I2C 0 SCL |  1] |              | [%s] 3V3                 \r\n", COLOR_RED("VSYS"));
    printf("                      [GND] |              | [GND]                    \r\n");
    printf("           [I2C 1 SDA |  2] |              | [%s]                     \r\n", COLOR_YELLOW("3V3_EN"));
    printf("           [I2C 1 SCL |  3] |              | [%s]                     \r\n", COLOR_RED("3V3(OUT)"));
    printf("           [I2C 0 SDA |  4] |              | ---------[ADC_VREF]      \r\n");
    printf("           [I2C 0 SCL |  5] |              | [28 | ADC2]              \r\n");
    printf("                      [GND] |              | [GND]                    \r\n");
    printf("           [I2C 1 SDA |  6] |              | [27 | I2C 1 SCL | ADC1]  \r\n");
    printf("           [I2C 1 SCL |  7] |              | [26 | I2C 1 SDA | ADC0]  \r\n");
    printf("           [I2C 0 SDA |  8] |              | [RUN]                    \r\n");
    printf("           [I2C 0 SCL |  9] |              | [22 | ]                  \r\n");
    printf("                      [GND] |              | [GND]                    \r\n");
    printf("           [I2C 1 SDA | 10] |              | [21 | I2C 0 SCL]         \r\n");
    printf("           [I2C 1 SCL | 11] |              | [20 | I2C 0 SDA]         \r\n");
    printf("           [I2C 0 SDA | 12] |              | [19 | I2C 1 SCL]         \r\n");
    printf("           [I2C 0 SCL | 13] |              | [18 | I2C 1 SDA]         \r\n");
    printf("                      [GND] |              | [GND]                    \r\n");
    printf("           [I2C 1 SDA | 14] |              | [17 | I2C 0 SCL]         \r\n");
    printf("           [I2C 1 SCL | 15] | o          o | [16 | I2C 0 SDA]         \r\n");
    printf("                             --------------                           \r\n");
    printf("\n");

    return 0;
}
