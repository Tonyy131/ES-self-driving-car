#ifndef MOTOR_H
#define MOTOR_H

#define BRIDGE_LEFT_PWM 6
#define BRIDGE_RIGHT_PWM 26
#define Motor_dir1 21
#define Motor_dir2 5
#define Motor_dir3 7
#define Motor_dir4 4


void motor_init(bool left);

void motor_drive(bool left,uint16_t speed, bool forward);

#endif