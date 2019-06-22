#include "MKL46Z4.h"
#include "systick.h"

unsigned int tick = 0;

void delay(int time)
{
	int current_tick = tick;
	while(tick - current_tick != time);
}

void systick_init()
{
	SysTick->CTRL |= 0x7;
	SysTick->LOAD = 8000;
}