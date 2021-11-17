#include <ext_interrupt.h>
#include <avr/interrupt.h>
#include <avr/io.h>

void (*external_INT0_FE_ISR)(void); // INT0 falling edge interrupt service routine
void (*external_INT1_FE_ISR)(void); // INT1 falling edge interrupt service routine

void INT0_IRQ_en(void)
{
	GICR |= (uint8_t)(1<<INT0);
}
void INT0_IRQ_dis(void)
{
	GICR &= (uint8_t)~(1<<INT0);
}
void INT0_FEdge_ISR_Init(void (*FEdge_ISR_impl)(void))
{
	/* set falling edge triggering */
	MCUCR |= (uint8_t)(1<<ISC01);
	MCUCR &= (uint8_t)~(1<<ISC00);

	external_INT0_FE_ISR = FEdge_ISR_impl; // set ISR handler

	INT0_IRQ_en();
}

void INT1_IRQ_en(void)
{
	GICR |= (uint8_t)(1<<INT1);
}
void INT1_IRQ_dis(void)
{
	GICR &= (uint8_t)~(1<<INT1);
}
void INT1_FEdge_ISR_Init(void (*FEdge_ISR_impl)(void))
{
	/* set falling edge triggering */
	MCUCR |= (uint8_t)(1<<ISC11);
	MCUCR &= (uint8_t)~(1<<ISC10);

	external_INT1_FE_ISR = FEdge_ISR_impl; // set ISR handler

	INT1_IRQ_en();
}
