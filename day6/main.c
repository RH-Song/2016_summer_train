/*
 * main.c
 *
 *  Created on: 07.11.2012
 *      Author: karl_ee
 */

#include "main.h"

int main()
{
	 unsigned int i,j;
	 unsigned long phase1=0x0,phase2=0x000,duty1=0x1388,duty2=0x1388,period=0x186A,enable=0x1;
	while(1)
	{

		 motor_setting(phase1,duty1,phase2,duty2,period,enable);
			//phase1++;
			//phase2++;
			//duty1++;
			//duty2++;
			for(i=0;i<2550;i++)
				for(j=0;j<2550;j++);//delay

	}

}
