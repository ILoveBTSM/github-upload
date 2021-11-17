#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>

#include "drivers/TIM1.h"

static uint16_t Delta_OCR1A;

void (*ISR_TIM1_COMPA)(void);
static inline void set_prescaler(uint8_t PScl);
static inline void set_normal_mode(uint8_t PreSc);
static inline void set_CTC_mode(uint8_t PreSc);
static inline void set_OCR1A(uint16_t val);
static inline uint16_t get_OCR1A(void);




void Conf_IRQ_on_OCR1A(uint8_t PreSc, uint16_t IRQ_Period, void (*ISR_handler)(void)){

	Delta_OCR1A = IRQ_Period;			// CompA leap value
	set_OCR1A( Delta_OCR1A-1 ); 		  // Output Compare Register A value
	ISR_TIM1_COMPA = ISR_handler;     // external ISR handler
	TIMSK = (1 << OCIE1A);           // enable compare interrupt	//set_CTC_mode();

	set_normal_mode(PreSc);

}


static inline void set_prescaler(uint8_t PreSc){

	TCCR1B |= (PreSc & 0x7) << CS10;
}

static inline void set_normal_mode(uint8_t PreSc){
	TCCR1A = 0x0;
	TCCR1B = 0x0;
	set_prescaler(PreSc);
}

static inline void set_CTC_mode(uint8_t PreSc){
	TCCR1A = 0;
	TCCR1B = 1 << WGM12;
	set_prescaler(PreSc);
}

static inline void set_OCR1A(uint16_t val){


	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
	OCR1AH = (uint8_t)(val >> 8); // accessing higher OCR1A byte
	OCR1AL = (uint8_t)(val & 0xFF); // accessing lower OCR1A byte
	}
}

static inline uint16_t get_OCR1A(){
	uint16_t temp;


	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		temp = OCR1AL; // accessing lower OCR1A byte
		temp |= ((uint16_t)OCR1AH) << 8; // accessing higher OCR1A byte
	}


	return temp;

}

ISR(TIMER1_COMPA_vect) {

	set_OCR1A(get_OCR1A() + Delta_OCR1A);

	ISR_TIM1_COMPA();
}
