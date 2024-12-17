#include <stdio.h>
#include "pico/stdlib.h"
#include "LDR.h"


void LDR_init(){
    gpio_init(LDR_SENSOR);
    gpio_set_dir(LDR_SENSOR,GPIO_IN);
    gpio_pull_down(LDR_SENSOR);
}

bool LDR_getState(){
    return gpio_get(LDR_SENSOR);
}
