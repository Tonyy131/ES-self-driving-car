#include "pico/stdlib.h" // Ensure the correct GPIO header is included
#include "LED.h"
#include <stdbool.h> // Include the header that defines 'true' and 'false'

void LED_Init(uint8_t led_pin)
{
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);
}

void LED_On(uint8_t led_pin)
{
    gpio_put(led_pin, true);
}

void LED_Off(uint8_t led_pin)
{
    gpio_put(led_pin, false);
}

void LED_Toggle(uint8_t led_pin)
{
    gpio_put(led_pin, !gpio_get(led_pin));
}
