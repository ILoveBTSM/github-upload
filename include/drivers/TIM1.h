#ifndef INCLUDE_TIM1_DRIVER_H_
#define INCLUDE_TIM1_DRIVER_H_

#define CLOCK_PRESC_DIS 	0
#define CLOCK_PRESC_1		1
#define CLOCK_PRESC_8		2
#define CLOCK_PRESC_64		3
#define CLOCK_PRESC_256		4
#define CLOCK_PRESC_1024	5

void Conf_IRQ_on_OCR1A(uint8_t PreSc, uint16_t IRQ_Period, void (*ISR_TIM1)(void));
void set_T1_normal_mode(void);

#endif
