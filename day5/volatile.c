/*
 * volatile variable
 */

#include "system.h"
#include "io.h"

//#define VOLATILE_TEST

#ifndef VOLATILE_TEST
int * key_ptr;
#else
volatile int * key_ptr;
#endif

int main()
{
    key_ptr = (int *) PIO_1_BASE;
 
	IOWR(PIO_0_BASE,0,0x00);

    while (*key_ptr != 1);
 
	IOWR(PIO_0_BASE,0,0xff);

  return 0;
}
