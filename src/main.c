#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"

#include "buzzer.h"
#include "IR.h"
#include "LED.h"
#include "motor.h"
#include "ultrasonic.h"
#include "LDR.h"

#include <stdbool.h>

// Define constants
#define TURN_SPEED 150
#define STRAIGHT_SPEED 200
#define STOP_DISTANCE_CM 10 // Stop if obstacle is closer than 11 cm
#define LED_ID 12
#define HEADLIGHT_ID 27

// Shared sensor variables
bool left_ir = false;
bool right_ir = false;
bool isLight = false;
unsigned short distance = 0;

// Task handles
TaskHandle_t motorTaskHandle, ledBuzzerTaskHandle, headlightTaskHandle, sensorTaskHandle;

// Sensor reading task
void sensorTask(void *pvParameters) {
    while (1) {
        // Update global sensor states
        left_ir = IR_getState(true);
        right_ir = IR_getState(false);
        isLight = LDR_getState();
        distance = Ultrasonic_readDistance();

        vTaskDelay(pdMS_TO_TICKS(50)); // Update sensors every 50ms
    }
}

// Motor control task
void motorTask(void *pvParameters) {
    while (1) {
        bool obstacle_detected = (distance <= STOP_DISTANCE_CM);

        if (obstacle_detected) {
            motor_drive(true, 0, false);  // Stop left motor
            motor_drive(false, 0, false); // Stop right motor
        } else if (right_ir && !left_ir) {
            motor_drive(true, STRAIGHT_SPEED, false); // Left motor slow
            motor_drive(false, TURN_SPEED, true);   // Right motor fast
        } else if (!right_ir && left_ir) {
            motor_drive(true, TURN_SPEED, true);    // Left motor fast
            motor_drive(false, STRAIGHT_SPEED, false); // Right motor slow
        } else {
            motor_drive(true, STRAIGHT_SPEED, true); // Both motors straight
            motor_drive(false, STRAIGHT_SPEED, true);
        }

        vTaskDelay(pdMS_TO_TICKS(100)); // Run motor control every 100ms
    }
}

// LED and buzzer control task
void ledBuzzerTask(void *pvParameters) {
    while (1) {
        bool obstacle_detected = (distance <= STOP_DISTANCE_CM);

        if (obstacle_detected) {
            buzzer_on();  // Sound buzzer for obstacle alert
        } else if (!left_ir || !right_ir) {
            LED_On(LED_ID); // Turn on LED if an IR sensor detects a problem
            buzzer_off();
        } else {
            LED_Off(LED_ID);
            buzzer_off();
        }

        vTaskDelay(pdMS_TO_TICKS(100)); // Run LED and buzzer control every 100ms
    }
}

// Headlight control task
void headlightTask(void *pvParameters) {
    while (1) {
        if (isLight) {
            LED_On(HEADLIGHT_ID);
        } else {
            LED_Off(HEADLIGHT_ID);
        }

        vTaskDelay(pdMS_TO_TICKS(100)); // Run headlight control every 100ms
    }
}

int main() {
    // Initialize standard I/O
    stdio_init_all();

    // Initialize peripherals
    motor_init(false);
    motor_init(true);
    IR_init(true);
    IR_init(false);
    LED_Init(LED_ID);
    LED_Init(HEADLIGHT_ID);
    buzzer_init();
    Ultrasonic_init();
    LDR_init();

    // Create FreeRTOS tasks
    xTaskCreate(sensorTask, "Sensor Task", 256, NULL, 1, &sensorTaskHandle);
    xTaskCreate(motorTask, "Motor Task", 256, NULL, 1, &motorTaskHandle);
    xTaskCreate(ledBuzzerTask, "LED Buzzer Task", 256, NULL, 1, &ledBuzzerTaskHandle);
    xTaskCreate(headlightTask, "Headlight Task", 256, NULL, 1, &headlightTaskHandle);

    // Start the RTOS scheduler
    vTaskStartScheduler();

    // Main loop (should never reach here)
    while (1) {}
}
