#include <CppUTest/TestHarness.h>
extern "C"
{
#include "CircularBuffer.h"
}
/* LIST OF TESTS TO DO
- Initialize as empty
- An input can be passed to the buffer
- An output can be read from the buffer
- Buffer shifts as a new input is made
-
*/
TEST_GROUP(CircularBuffer)
{
	void setup()
	{
	}
	void teardown()
	{
	}
};

TEST(CircularBuffer,CreateBufferOfSizeN)
{

}
