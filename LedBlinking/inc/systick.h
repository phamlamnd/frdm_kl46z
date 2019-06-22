#ifndef __systick_h__
#define __systick_h__

extern unsigned int tick;
void delay(int time);
void systick_init();
void SysTick_Handler();

#endif /* __systick_h__ */
