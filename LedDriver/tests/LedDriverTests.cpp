#include <CppUTest/TestHarness.h>
extern "C"
{
#include "LedDriver.h"
}
/* LIST OF TESTS
- All LEDs are off when initialized
- A single LED can be turned on
- A single LED can be turned Off
- Multiple LEDs can be turned on/off
- Turn on all LEDs
- Turn off all LEDs
- Query LED state
- Check boundary values
- Check out-of-bounds values
*/
TEST_GROUP(LedDriver)
{
	uint16_t virtual_leds = 0xFFFF;
	void setup()
	{
		ledDriverCreate(&virtual_leds);
	}
	void teardown()
	{
	}
};

TEST(LedDriver, OffAtCreate)
{
	uint16_t virtual_leds = 0xFFFF;
	ledDriverCreate(&virtual_leds);
	CHECK_EQUAL(0x0000, virtual_leds);
}

TEST(LedDriver, TurnOnLedOne)
{
	turnOnLed(1);
	CHECK_EQUAL(0x0001, virtual_leds);
}

TEST(LedDriver, TurnOffLedOne)
{
	turnOnLed(1);
	turnOffLed(1);
	CHECK_EQUAL(0x0000, virtual_leds)
;}
