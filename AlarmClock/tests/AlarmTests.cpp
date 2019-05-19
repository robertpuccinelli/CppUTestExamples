#include <CppUTest/TestHarness.h>
extern "C"
{
#include "AlarmClock.h"
}
/* LIST OF TESTS TO DO
- Schedule an alarm
- Remove a scheduled alarm
- Activate alarm
- Deactivate alarm
- View all alarms
*/
TEST_GROUP(Alarm)
{
	void setup()
	{
	}
	void teardown()
	{
	}
};

TEST(Alarm,ExampleFail)
{
	FAIL("Start here.");
}
