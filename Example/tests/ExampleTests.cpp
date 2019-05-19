#include <CppUTest/TestHarness.h>
extern "C"
{
#include "Example.h"
}
/* LIST OF TESTS TO DO
-
*/
TEST_GROUP(Example)
{
	void setup()
	{
	}
	void teardown()
	{
	}
};

TEST(Example,ExampleFail)
{
	FAIL("Start here.");
}
