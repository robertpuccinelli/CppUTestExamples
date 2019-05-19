#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include "stdio.h"

//typedef enum BOOL;

void ledDriverCreate(uint16_t * address);
void turnOnLed(int led_number);
void turnOffLed(int led_number);
void turnOnAllLed(void);
void turnOffAllLed(void);
int queryLedState(int led_number);

#endif
