/*
 SWITCH LED ACCORDING by KEYs
 AUTHOR: GANG
 */

#include "system.h"
#include "io.h"
#include "stdio.h"
#include "adc_spi_read.h"

int main() {
    int ADC_Val,i;
    while(1) {
    	for(i=0;i<8;i++)
    	{
    		ADC_Val=ADC_Read(i);
        	printf("ADC value %d",ADC_Val);
    	}
    	for(i=0;i<10000;i++);
    }
    return 0;
}
