#include "pico/stdlib.h"
#include "buzzer.h"
#include <stdbool.h>

// Function to initialize the buzzer
void buzzer_init(void) {
    // Initialize the SOUND_SENSOR pin as output
    // printf("Initializing buzzer on pin %d\n", BUZZER_ACTUATOR);
    gpio_init(BUZZER_ACTUATOR); // Initialize the sound sensor pin
    gpio_set_dir(BUZZER_ACTUATOR, GPIO_OUT); // Set as input
    // Add actual hardware-specific initialization code here, e.g., pinMode(SOUND_SENSOR, OUTPUT) for Arduino
}

// Function to turn the buzzer on
void buzzer_on(void) {
    // printf("Turning buzzer ON\n");
    gpio_put(BUZZER_ACTUATOR, true); // Set the actuator pin hig
    // Add actual code to turn the buzzer on, e.g., digitalWrite(SOUND_SENSOR, HIGH) for Arduino
}

// Function to turn the buzzer off
void buzzer_off(void) {
    // printf("Turning buzzer OFF\n");
    gpio_put(BUZZER_ACTUATOR, false); // Set the actuator pin hig
    // Add actual code to turn the buzzer off, e.g., digitalWrite(SOUND_SENSOR, LOW) for Arduino
}

// Function to toggle the buzzer state
void buzzer_toggle(void) {
    // printf("Toggling buzzer state\n");
    gpio_put(BUZZER_ACTUATOR, !gpio_get(BUZZER_ACTUATOR));
    // Add actual code to toggle the buzzer state if supported by your platform
}
