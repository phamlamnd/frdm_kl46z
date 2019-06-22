#ifndef __interrupt_h__
#define __interrupt_h__

void Sw1_IRQHandler(void);
void Reserved_IRQHandler(void);
void NMI_Handler(void);
void HardFault_Handler(void);
void SVC_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);

#endif /* __interrupt_h__ */
