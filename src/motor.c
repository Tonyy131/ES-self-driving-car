#include "pico/stdlib.h"
#include "motor.h"
#include "hardware/pwm.h"

void motor_init(bool left) {

    gpio_init(Motor_dir1);
    gpio_set_dir(Motor_dir1, GPIO_OUT);
    gpio_init(Motor_dir2);
    gpio_set_dir(Motor_dir2, GPIO_OUT);
    gpio_init(Motor_dir3);
    gpio_set_dir(Motor_dir3, GPIO_OUT);
    gpio_init(Motor_dir4);
    gpio_set_dir(Motor_dir4, GPIO_OUT);

    

    if(left){
        gpio_set_function(BRIDGE_LEFT_PWM, GPIO_FUNC_PWM);
        uint slice = pwm_gpio_to_slice_num(BRIDGE_LEFT_PWM);

        pwm_set_wrap(slice,255);
        pwm_set_clkdiv(slice,4.0f);

        pwm_set_enabled(slice,true);
    }else{
        gpio_set_function(BRIDGE_RIGHT_PWM, GPIO_FUNC_PWM);
        uint slice = pwm_gpio_to_slice_num(BRIDGE_RIGHT_PWM);

        pwm_set_wrap(slice,255);
        pwm_set_clkdiv(slice,4.0f);

        pwm_set_enabled(slice,true);
    }


}

void motor_drive(bool left,uint16_t speed, bool forward){
    if(speed > 150) speed = 150;

    // if(forward){
    //     gpio_put(Motor_dir1,1);
    //     gpio_put(Motor_dir2,0);
    //     gpio_put(Motor_dir4,0);
    //     gpio_put(Motor_dir3,1);
    // }else{
    //     gpio_put(Motor_dir1,0);
    //     gpio_put(Motor_dir2,1);
    //     gpio_put(Motor_dir4,1);
    //     gpio_put(Motor_dir3,0);
    // }

    if(left){
        if(forward){
        gpio_put(Motor_dir1,1);
        gpio_put(Motor_dir2,0);
        // gpio_put(Motor_dir4,0);
        // gpio_put(Motor_dir3,1);
    }else{
        gpio_put(Motor_dir1,0);
        gpio_put(Motor_dir2,1);
        // gpio_put(Motor_dir4,1);
        // gpio_put(Motor_dir3,0);
    }
        pwm_set_gpio_level(BRIDGE_LEFT_PWM,speed);
    }else{
        if(forward){
        // gpio_put(Motor_dir1,1);
        // gpio_put(Motor_dir2,0);
        gpio_put(Motor_dir4,0);
        gpio_put(Motor_dir3,1);
    }else{
        // gpio_put(Motor_dir1,0);
        // gpio_put(Motor_dir2,1);
        gpio_put(Motor_dir4,1);
        gpio_put(Motor_dir3,0);
    }
        pwm_set_gpio_level(BRIDGE_RIGHT_PWM,speed);

    }
}
