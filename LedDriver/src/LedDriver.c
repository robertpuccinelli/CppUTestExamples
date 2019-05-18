#include "LedDriver.h"
uint16_t * led_address;
void ledDriverCreate(uint16_t * address)
{
  led_address = address;
  *led_address = 0;
}

void turnOnLed(int led_number)
{
  *led_address = 1;
}

void turnOffLed(int led_number)
{
  *led_address = 0;
}
