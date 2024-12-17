// Sound.c
#include "pico/stdlib.h"
#include "Sound.h"
#include <stdbool.h>

// Initialize the sound sensor and actuator
void Sound_Init(void) {
    gpio_init(SOUND_SENSOR); // Initialize the sound sensor pin
    gpio_set_dir(SOUND_SENSOR, GPIO_IN); // Set as input

    gpio_init(SOUND_ACTUATOR); // Initialize the sound actuator pin
    gpio_set_dir(SOUND_ACTUATOR, GPIO_OUT); // Set as output

    gpio_put(SOUND_ACTUATOR, false); // Ensure actuator is off initially
}

// Function to read the state of the sound sensor
void Sound_Sensor_Read(void) {
    bool sensor_state = gpio_get(SOUND_SENSOR); // Read the state of the sensor

    if (sensor_state) {
        Sound_Actuator_On(); // Activate the actuator if sound is detected
    } else {
        Sound_Actuator_Off(); // Deactivate the actuator if no sound is detected
    }
}

// Turn the sound actuator on
void Sound_Actuator_On(void) {
    gpio_put(SOUND_ACTUATOR, true); // Set the actuator pin high
}

// Turn the sound actuator off
void Sound_Actuator_Off(void) {
    gpio_put(SOUND_ACTUATOR, false); // Set the actuator pin low
}
