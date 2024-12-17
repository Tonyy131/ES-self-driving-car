#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_



#define TRIGGER 15    
#define ECHO  25 

void Ultrasonic_init(void);


unsigned short Ultrasonic_readDistance(void);



#endif