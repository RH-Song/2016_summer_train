/*
 SWITCH LED ACCORDING by KEYs
 */

#include "system.h"
#include "io.h"

int main()
{
  unsigned char keys;
  // turn on the first led
  IOWR(LED_BASE,0,0x01);
  while(1)
  {
	  keys=IORD(KEY_BASE,0);
	  
	  // TODO: check if key 1 is pressed by checking if bit #1 is 1
	  
      // TODO: if key 1 is pressed, make the next LED glow, such that
      //       your LEDs behave like the BIT slider from the exercises of day 2

      // TODO: make sure that one key press only causes one slide step,
      //       by reading KEY_BASE again and waiting the bit #1 to turn 0 again
  }
  return 0;
}
