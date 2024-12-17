#include <stdio.h>
#include "pico/stdlib.h"
#include "IR.h"


void IR_init(bool left){
    if(left){

        gpio_init(IR_SENSOR_LEFT);
        gpio_set_dir(IR_SENSOR_LEFT,GPIO_IN);
    }
    else{
        gpio_init(IR_SENSOR_RIGHT);
        gpio_set_dir(IR_SENSOR_RIGHT,GPIO_IN);
    }

}

bool IR_getState(bool left){
    if(left){
	    return gpio_get(IR_SENSOR_LEFT);
    }else{
        return gpio_get(IR_SENSOR_RIGHT);
    }
}
