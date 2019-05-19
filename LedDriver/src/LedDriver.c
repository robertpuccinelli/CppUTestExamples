#include "LedDriver.h"
typedef enum { false, true } BOOL;

enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};
enum {FIRST_LED = 1, LAST_LED = 16};
static uint16_t * led_address;
static uint16_t led_state;
static uint16_t numberToBit(int number)
{
  uint16_t result = 0;
  result |= 1 << (number - 1);
  return result;
}
static void updateHardware(void)
{
  *led_address = led_state;
}
static BOOL isLedOutOfBounds(int led_number)
{
  RuntimeError("LedDriver: led_number out-of-bounds.",led_number,"test",1);
  return (led_number < FIRST_LED || led_number > LAST_LED);
}
static void setBit(int led_number)
{
  led_state |= numberToBit(led_number);
}
static void clearBit(int led_number)
{
  led_state &= ~numberToBit(led_number);
}
void ledDriverCreate(uint16_t * address)
{
  led_address = address;
  led_state = ALL_LEDS_OFF;
  updateHardware();
}

void turnOnLed(int led_number)
{
  if (isLedOutOfBounds(led_number))
    return;
  setBit(led_number);
  updateHardware();
}

void turnOffLed(int led_number)
{
  if (isLedOutOfBounds(led_number))
    return;
  clearBit(led_number);
  updateHardware();
}

void turnOnAllLed(void)
{
  led_state = (uint16_t)ALL_LEDS_ON;
  updateHardware();
}

void turnOffAllLed(void)
{
  led_state = ALL_LEDS_OFF;
  updateHardware();
}

int queryLedState(int led_number)
{
  if (isLedOutOfBounds(led_number))
    return false;

  return (led_state & numberToBit(led_number));
}
