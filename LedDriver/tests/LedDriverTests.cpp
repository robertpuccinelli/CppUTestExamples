#include <CppUTest/TestHarness.h>
extern "C"
{
#include "LedDriver.h"
}

TEST_GROUP(LedDriver)
{
	void setup()
	{
	}
	void teardown()
	{
	}
};

TEST(LedDriver, OffAtCreate)
{
	FAIL("Start here.");
}

