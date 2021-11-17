#ifndef INCLUDE_DRIVERS_EXT_INTERRUPT_H_
#define INCLUDE_DRIVERS_EXT_INTERRUPT_H_


void INT0_IRQ_en(void);
void INT0_IRQ_dis(void);
void INT0_FEdge_ISR_Init(void (*FEdge_ISR_impl)(void));

void INT1_IRQ_en(void);
void INT1_IRQ_dis(void);
void INT1_FEdge_ISR_Init(void (*FEdge_ISR_impl)(void));


#endif /* INCLUDE_DRIVERS_EXT_INTERRUPT_H_ */
