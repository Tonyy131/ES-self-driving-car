#ifndef BUZZER_H
#define BUZZER_H

// Include necessary standard libraries
#include <stdint.h>

// Pin configuration for the sound sensor
#define BUZZER_ACTUATOR 13

// Function prototypes
void buzzer_init(void);
void buzzer_on(void);
void buzzer_off(void);
void buzzer_toggle(void);

#endif // BUZZER_H