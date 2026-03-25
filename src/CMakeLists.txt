pico_sdk_init()

add_subdirectory(shell)
add_subdirectory(commands)
add_subdirectory(utils)

add_executable(
        pico-shell
        main.cpp
        usb/usb_descriptors.c
        usb/usb_task.cpp
        shell_task.cpp
        handlers.cpp
)

pico_add_extra_outputs(pico-shell)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/config
        ${CMAKE_CURRENT_SOURCE_DIR}/usb
)

target_link_libraries(
        pico-shell
        pico_stdlib
        pico_stdio_usb
        tinyusb_device
        FreeRTOS-Kernel
        FreeRTOS-Kernel-Heap4
        shell_main
        shell_commands_common
        shell_commands_pico
        shell_commands_freertos
        commands
)

add_deploy_target(pico-shell "${CMAKE_CURRENT_BINARY_DIR}/pico-shell.uf2")
