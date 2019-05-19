#include <CppUTest/TestHarness.h>
extern "C"
{
#include "LedDriver.h"
#include "RuntimeErrorStub.h"
}
/* LIST OF TESTS
X All LEDs are off when initialized
X A single LED can be turned on
X A single LED can be turned Off
X Multiple LEDs can be turned on/off
X Turn on all LEDs
X Turn off all LEDs
X Query LED state
X Check boundary values
X Check out-of-bounds values
*/
TEST_GROUP(LedDriver)
{
	uint16_t virtual_leds;
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

TEST(LedDriver, TurnOnMultiple)
{
	turnOnLed(4);
	turnOnLed(8);
	CHECK_EQUAL(0x0088, virtual_leds);
}

TEST(LedDriver, TurnOffMultiple)
{
	turnOnAllLed();
	turnOffLed(3);
	turnOffLed(2);
	CHECK_EQUAL(0xFFF9, virtual_leds);

}

TEST(LedDriver, AllOn)
{
	turnOnAllLed();
	CHECK_EQUAL(0xFFFF, virtual_leds);
}

TEST(LedDriver, AllOff)
{
	turnOnAllLed();
	turnOffAllLed();
	CHECK_EQUAL(0x0000, virtual_leds);
}

TEST(LedDriver, LedBankNotReadable)
{
	virtual_leds = 0xFFFF;
	turnOnLed(1);
	CHECK_EQUAL(0x0001, virtual_leds);
}

TEST(LedDriver, UpperAndLowerBounds)
{
	turnOnLed(1);
	turnOnLed(16);
	CHECK_EQUAL(0x8001,virtual_leds);
}

TEST(LedDriver, OutOfBoundsChangesNothingOn)
{
	turnOnLed(-1);
	turnOnLed(0);
	turnOnLed(17);
	turnOnLed(3141);
	CHECK_EQUAL(0x0000, virtual_leds);
}

TEST(LedDriver, OutOfBoundsChangesNothingOff)
{
	turnOnAllLed();
	turnOffLed(-1);
	turnOffLed(0);
	turnOffLed(17);
	turnOffLed(3141);
	CHECK_EQUAL(0xFFFF, virtual_leds);
}

TEST(LedDriver, OutOfBoundsRuntimeError)
{
	turnOnLed(0);
	STRCMP_EQUAL("LedDriver: led_number out-of-bounds.", RuntimeErrorStub_GetLastError());
	CHECK_EQUAL(0, RuntimeErrorStub_GetLastParameter());
}

TEST(LedDriver, QueryLedState)
{
	CHECK_FALSE(queryLedState(8));
	turnOnLed(8);
	CHECK_TRUE(queryLedState(8));
}

TEST(LedDriver, QuereyOutOfBoundsLedState)
{
	CHECK_FALSE(queryLedState(0));
	CHECK_FALSE(queryLedState(17));
}
