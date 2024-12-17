#ifndef IR_H_
#define IR_H_



#define IR_SENSOR_LEFT 19
#define IR_SENSOR_RIGHT 20


void IR_init(bool left);


bool IR_getState(bool left);


#endif