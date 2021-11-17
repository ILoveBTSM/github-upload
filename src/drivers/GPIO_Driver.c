#include "GPIO_Driver.h"
#include <util/atomic.h>



void Configure_PORTC_in_noPU(uint8_t pin_mask)
{
	PORTC &= ~ pin_mask;
	DDRC &= ~ pin_mask;
}
void wt_GPIO(PORT_ptr x, uint8_t pin_mask, uint8_t val_mask)
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		BitClr_GPIO(x, pin_mask & ~val_mask); // clear bits
		BitSet_GPIO(x, pin_mask & val_mask); // set bits
	}
	__builtin_avr_nop(); // wait until out state becomes active
}

void wt_GPIOxn(PORT_ptr x, uint8_t pin_n, uint8_t state) {;}

uint8_t rd_GPIO(PORT_ptr  x, uint8_t pin_mask)
{
	return (uint8_t)(*x & pin_mask);
}

uint8_t rd_GPIOxn(PORT_ptr  x, uint8_t pin_n)
{
	return (uint8_t)(*x & (1<<pin_n)) >> pin_n;
}

void BitClr_GPIO(PORT_ptr  x, uint8_t pin_mask)
{
	*x &= ~pin_mask;
}
void BitSet_GPIO(PORT_ptr  x, uint8_t pin_mask)
{
	*x |= pin_mask;
}
