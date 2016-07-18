/*
 * main.c
 *
 * Press Key0 to change the direction of the LED
 *
 *  Created on: Jul 1, 2013
 *  Modified on: 8 Aug, 2014
 *      Author: Gang
 */

#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "io.h"
#include "sys/alt_irq.h"

volatile static char key = 0;

unsigned int nirq_isr_context;
void nIRQ_Initial(void);
void nPIO_ISR(void* isr_context);
//
int main()
{
	unsigned char led = 0x01;
	int delay = 0;

	IOWR(LED_BASE,0,0xff);

    nIRQ_Initial();

	while(1)	  {
		//key=IORD(PIO_1_BASE,0);
		if (key) {
			if(led==0x80)
				led=0x01;
	        else
				led=led<<1;
		} else {
			if(led==0x01)
				led=0x80;
		    else
				led=led>>1;
		}
	    IOWR(LED_BASE,0,led);
	    delay=0;
        while(delay++ < 200000);
	}

  return 0;
}
//
void nIRQ_Initial(void)
{
    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(KEY_BASE, 1); //
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEY_BASE, 1); //
    // register ISR function
    alt_ic_isr_register(
    		KEY_IRQ_INTERRUPT_CONTROLLER_ID,
    		KEY_IRQ,
	  nPIO_ISR,
      0x0,
      0x0);
}
// ISR
void nPIO_ISR(void* nirq_isr_context)
{
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEY_BASE, 1);
    key = key ^1;
}
