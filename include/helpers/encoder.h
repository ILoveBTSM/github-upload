#ifndef INCLUDE_HELPERS_ENCODER_H_
#define INCLUDE_HELPERS_ENCODER_H_

#include <avr/io.h>

typedef struct encoder* EncPtr;

EncPtr create_Encoder(	uint8_t (*chA_rd_state)(void),
						uint8_t (*chB_rd_state)(void),
						void (*ClockwiseTickAction)(void),
						void (*CntrClockwiseTickAction)(void));
void destroy_Encoder(EncPtr);

void Enc_chA_FEdge_trigger(EncPtr);
void Enc_chA_FEdge_trigger(EncPtr);

#endif /* INCLUDE_HELPERS_ENCODER_H_ */
