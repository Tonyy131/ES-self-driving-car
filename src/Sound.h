#ifndef SOUND_H_
#define SOUND_H_

#define SOUND_SENSOR 17
#define SOUND_ACTUATOR 18

void Sound_Init(void);
void Sound_Sensor_Read(void);
void Sound_Actuator_On(void);
void Sound_Actuator_Off(void);

#endif

