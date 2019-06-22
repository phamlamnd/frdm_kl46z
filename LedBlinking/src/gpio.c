#include "MKL46Z4.h"
#include "gpio.h"

void gpio_init()
{
	//Set PORTC 3 GPIO
	PORTC->PCR[3] &= ~PORT_PCR_MUX_MASK;
	PORTC->PCR[3] |= PORT_PCR_MUX(1);
	//ENABLE PULL
	PORTC->PCR[3] |= PORT_PCR_PE(1);
	//PULL UP
	PORTC->PCR[3] |= PORT_PCR_PS(1);
  
	//Set PORTE 29 GPIO
	PORTE->PCR[29] |= PORT_PCR_MUX(1);
	//GPIOE 29 OUTPUT
	GPIOE->PDDR |= (1<<29);
	GPIOE->PDOR &= ~(1 << 29);
  
	//GPIOC 3 INPUT
	GPIOC->PDDR &= ~(1<<3);
}