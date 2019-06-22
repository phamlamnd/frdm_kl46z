#include "MKL46Z4.h"
#include "clock.h"
#include "gpio.h"
//#include "systick.h"
//#include "interrupt.h"

void delay_(unsigned int timeout)
{
	unsigned int t1, t2;
    for (t1 = 0; t1 < timeout; t1++)
    {
        for (t2 = 0; t2 < 0xFFF; t2++)
        {
          asm(" nop");
        }
    }
}

void main(void)
{
	gpio_init();
	delay_(10);
	clock_enable();
	//systick_init();
	UpdateClockTo8Mhz();
	//ConfigFEIToPEE48Mhz();
	
	while(1)
	{
		GPIOE->PDOR |= (1<<29);  //ON LED
		delay_(0xff);
		GPIOE->PDOR &= ~(1<<29); //OFF LED
		delay_(0xff);
	}
}