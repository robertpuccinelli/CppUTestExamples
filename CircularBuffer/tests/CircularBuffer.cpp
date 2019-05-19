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
	int circular_buffer;
	void setup()
	{
		circularBufferCreate(&circular_buffer);
	}
	void teardown()
	{
	}
};

TEST(CircularBuffer,CreateEmptyBuffer)
{
	circularBufferCreate(&circular_buffer);
	CHECK_EQUAL(0, circular_buffer);
}

TEST(CircularBuffer, PassBufferInput)
{
	bufferInput(1);
	CHECK_EQUAL(1, circular_buffer);
}

TEST(CircularBuffer,ReadBufferOutput)
{
	int output;
	bufferInput(1);
	output = bufferOutput();
	CHECK_EQUAL(1, output);
}

TEST(CircularBuffer, BufferShift)
{
	int output;
	bufferInput(1);
	output = bufferOutput();
	CHECK_EQUAL(0,output);
	bufferInput(2);
	output = bufferOutput();
	CHECK_EQUAL(1,output);
}
