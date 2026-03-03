#include "commands.h"

#include <stdio.h>
#include "hardware/structs/sysinfo.h"
#include "hardware/flash.h"
#include "pico/unique_id.h"


static struct {
    uint8_t manufacturer;
    uint8_t memory_type;
    uint8_t capacity;
} flash_JEDEC_ID;

static void __attribute__((constructor)) _read_flash_JEDEC_ID_on_boot() {
    uint8_t txbuf[4] = {0};
    uint8_t rxbuf[4] = {0};
    // Winbond W25Q series pdf
    // 8.2.29 Read JEDEC ID (9Fh)
    txbuf[0] = 0x9f;
    flash_do_cmd(txbuf, rxbuf, 4);

    flash_JEDEC_ID.manufacturer = rxbuf[1];
    flash_JEDEC_ID.memory_type = rxbuf[2];
    flash_JEDEC_ID.capacity = rxbuf[3];
}

int command_chip_id(int, const char *[]) {
    uint32_t chip_id = sysinfo_hw->chip_id;
    uint16_t manufacturer = (chip_id >> 0) & 0x0fff;
    uint16_t part_id = (chip_id >> 12) & 0xffff;
    uint16_t revision = (chip_id >> 28) & 0x0f;

    printf("Manufacturer: 0x%03X\n", manufacturer);
    printf("Part ID: 0x%04X\n", part_id);
    printf("Revision: %s\n", revision == 2 ? "B2" : "B0/B1");

    char board_id[32];
    pico_get_unique_board_id_string(board_id, sizeof(board_id));
    printf("Unique board identifier: %s\n", board_id);

    printf("Flash Manufacturer: 0x%02X\n", flash_JEDEC_ID.manufacturer);
    printf("Flash Memory Type: 0x%02X\n", flash_JEDEC_ID.memory_type);
    printf("Flash Capacity: 0x%02X (%d MB)\n", flash_JEDEC_ID.capacity, (1 << flash_JEDEC_ID.capacity) / (1 << 20));

    return 0;
}
