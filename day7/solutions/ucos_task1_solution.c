/*************************************************************************
* Copyright (c) 2004 Altera Corporation, San Jose, California, USA.      *
* All rights reserved. All use of this software and documentation is     *
* subject to the License Agreement located at the end of this file below.*
**************************************************************************
* Description:                                                           *
* The following is a simple hello world program running MicroC/OS-II.The * 
* purpose of the design is to be a very simple application that just     *
* demonstrates MicroC/OS-II running on NIOS II.The design doesn't account*
* for issues such as checking system call return codes. etc.             *
*                                                                        *
* Requirements:                                                          *
*   -Supported Example Hardware Platforms                                *
*     Standard                                                           *
*     Full Featured                                                      *
*     Low Cost                                                           *
*   -Supported Development Boards                                        *
*     Nios II Development Board, Stratix II Edition                      *
*     Nios Development Board, Stratix Professional Edition               *
*     Nios Development Board, Stratix Edition                            *
*     Nios Development Board, Cyclone Edition                            *
*   -System Library Settings                                             *
*     RTOS Type - MicroC/OS-II                                           *
*     Periodic System Timer                                              *
*   -Know Issues                                                         *
*     If this design is run on the ISS, terminal output will take several*
*     minutes per iteration.                                             *
**************************************************************************/


#include <stdio.h>
#include "includes.h"
#include "io.h"
#include "system.h"

/* Definition of Task Stacks */
#define   TASK_STACKSIZE       1024
OS_STK    task1_stk[8][TASK_STACKSIZE];

OS_EVENT* semaphore;

void led_on(int i)
{
	INT8U status;
	OSSemPend(semaphore, 0, &status);

	unsigned char val=IORD(LED_BASE, 0);
	val=val | (1<<i);
	IOWR( LED_BASE, 0, val );

	OSSemPost(semaphore);
}

void led_off(int i)
{
	INT8U status;
	OSSemPend(semaphore, 0, &status);

	unsigned char val=IORD(LED_BASE, 0);
	val=val & ~(1<<i);
	IOWR( LED_BASE, 0, val );

	OSSemPost(semaphore);
}


void task1(void* pdata)
{
  unsigned char i=(unsigned char) pdata;
  while (1)
  { 
	led_on(i);
    OSTimeDlyHMSM(0, 0, 0, (i+1)*100);

    led_off(i);
    OSTimeDlyHMSM(0, 0, 0, (i+1)*100);
  }
}



int main(void)
{
  OSInit();

  semaphore=OSSemCreate(1);

  int i;
  for(i=0; i<8; i++)
  {
      OSTaskCreate(task1,
                   (void*) i,
                   (void *)&task1_stk[i][TASK_STACKSIZE-1],
                   i);
  }
  OSStart();
  return 0;
}

/******************************************************************************
*                                                                             *
* License Agreement                                                           *
*                                                                             *
* Copyright (c) 2004 Altera Corporation, San Jose, California, USA.           *
* All rights reserved.                                                        *
*                                                                             *
* Permission is hereby granted, free of charge, to any person obtaining a     *
* copy of this software and associated documentation files (the "Software"),  *
* to deal in the Software without restriction, including without limitation   *
* the rights to use, copy, modify, merge, publish, distribute, sublicense,    *
* and/or sell copies of the Software, and to permit persons to whom the       *
* Software is furnished to do so, subject to the following conditions:        *
*                                                                             *
* The above copyright notice and this permission notice shall be included in  *
* all copies or substantial portions of the Software.                         *
*                                                                             *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,    *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE *
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER      *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING     *
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER         *
* DEALINGS IN THE SOFTWARE.                                                   *
*                                                                             *
* This agreement shall be governed in all respects by the laws of the State   *
* of California and by the laws of the United States of America.              *
* Altera does not recommend, suggest or require that this reference design    *
* file be used in conjunction or combination with any other product.          *
******************************************************************************/
