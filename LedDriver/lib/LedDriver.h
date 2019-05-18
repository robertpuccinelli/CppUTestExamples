#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include "stdio.h"

void ledDriverCreate(uint16_t * address);
void turnOnLed(int led_number);
void turnOffLed(int led_number);

#endif
