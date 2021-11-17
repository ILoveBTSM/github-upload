#ifndef INCLUDE_DRIVERS_GPIO_DRIVER_H_
#define INCLUDE_DRIVERS_GPIO_DRIVER_H_

#include "avr/io.h"

typedef volatile uint8_t* PORT_ptr;

void Configure_PORTC_in_noPU(uint8_t pin_mask);

void BitClr_GPIO(PORT_ptr x, uint8_t pin_mask);
void BitSet_GPIO(PORT_ptr x, uint8_t pin_mask);

void wt_GPIO(PORT_ptr x, uint8_t pin_mask, uint8_t val_mask);
void wt_GPIOxn(PORT_ptr x, uint8_t pin_n, uint8_t state);

uint8_t rd_GPIO(PORT_ptr  x, uint8_t pin_mask);
uint8_t rd_GPIOxn(PORT_ptr  x, uint8_t pin_n);




#endif /* INCLUDE_DRIVERS_GPIO_DRIVER_H_ */
