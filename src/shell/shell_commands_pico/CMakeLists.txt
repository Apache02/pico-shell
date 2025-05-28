add_library(
        shell_commands_pico INTERFACE
)

target_include_directories(
        shell_commands_pico INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/include
)

file(
        GLOB COMMANDS
        ${CMAKE_CURRENT_LIST_DIR}/commands/*.cpp
)

target_sources(
        shell_commands_pico INTERFACE
        ${COMMANDS}
)

target_link_libraries(
        shell_commands_pico INTERFACE
        shell_main
        hardware_gpio
        hardware_i2c
        hardware_adc
)
