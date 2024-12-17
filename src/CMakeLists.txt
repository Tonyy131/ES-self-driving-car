add_executable(${ProjectName}
    main.c
    motor.c
    IR.c
    LED.c
    buzzer.c
    Ultrasonic.c
    LDR.c
)

# Include directories
target_include_directories(${ProjectName} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Link libraries, including hardware_pwm for PWM functionality
target_link_libraries(${ProjectName} 
    pico_stdlib 
    FreeRTOS-Kernel-Heap4 
    hardware_pwm
)

# Ensure main.c is included
target_sources(${PROJECT_NAME} PRIVATE main.c)

# Enable USB serial output
pico_enable_stdio_usb(${PROJECT_NAME} 1)

# Disable UART output (optional)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

# Add extra outputs (e.g., UF2, ELF, Binary)
pico_add_extra_outputs(${ProjectName})
