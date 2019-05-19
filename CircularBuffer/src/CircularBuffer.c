#include "CircularBuffer.h"
#define BUFFER_SIZE 2
//static int * buffer_address;

static int * buffers_address[BUFFER_SIZE] = {0};

//static void bufferShift(int )

void circularBufferCreate(int * address)
{
//  buffer_address = address;
//  *buffer_address = 0;

  buffers_address[0] = address;
  *buffers_address[0] = 0;
}

void bufferInput(int value)
{
//  *buffer_address = value;
  *buffers_address[0] = value;
}

int bufferOutput(void)
{
//  return *buffer_address;
  return * buffers_address[0];
}
