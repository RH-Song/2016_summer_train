/*
 SWITCH LED ACCORDING by KEYs
 AUTHOR: GANG
 */

#include "system.h"
#include "io.h"

int main() {
    unsigned char key;
    unsigned char val = 0x01;
    IOWR( LED_BASE, 0, val );
    while(1) {
        key=IORD(KEY_BASE,0);

        if( key == 0x02 ){
            // key number 1 pressed

            // slide the bit one position to the left
            val = val << 1 | val >> 7;

            // update the LEDs
            IOWR( LED_BASE, 0, val );

            // wait until the key is released
            while(IORD(KEY_BASE,0) != 0x03) {}
        }

    }
    return 0;
}


