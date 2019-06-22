#include "MKL46Z4.h"
#include "interrupt.h"
#include "systick.h"
void Sw1_IRQHandler(void)
{
	while(1)
  {
    /* nothing to be run here */
  }
}

void Reserved_IRQHandler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void NMI_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void HardFault_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void SVC_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void PendSV_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void SysTick_Handler(void)
{
  SysTick->CTRL &= ~(1<<16);
  tick++;
}

