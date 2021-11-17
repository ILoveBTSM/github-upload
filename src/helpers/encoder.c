#include <encoder.h>
#include <stdlib.h>

struct encoder
{
	uint8_t (*chA_rd_state)();
	uint8_t (*chB_rd_state)();
	void (*ClockwiseTickAction)();
	void (*CntrClockwiseTickAction)();
};

EncPtr create_Encoder(	uint8_t (*chA_rd_state)(void),
						uint8_t (*chB_rd_state)(void),
						void (*ClockwiseTickAction)(void),
						void (*CntrClockwiseTickAction)(void))
{
	EncPtr EncInst = (EncPtr)malloc(sizeof(struct encoder));

	EncInst->chA_rd_state = chA_rd_state;
	EncInst->chB_rd_state = chB_rd_state;
	EncInst->ClockwiseTickAction = ClockwiseTickAction;
	EncInst->CntrClockwiseTickAction = CntrClockwiseTickAction;

	return EncInst;
}
void destroy_Encoder(EncPtr EncInst)
{
	if(0 != EncInst)
	{
		free(EncInst);
	}
}

void Enc_chA_FEdge_trigger(EncPtr EncInst)
{
	( EncInst->chB_rd_state() == 1 ) ? EncInst->ClockwiseTickAction() : EncInst->CntrClockwiseTickAction();
}
void Enc_chB_FEdge_trigger(EncPtr EncInst)
{
	( EncInst->chA_rd_state() == 1 ) ? EncInst->CntrClockwiseTickAction() : EncInst->ClockwiseTickAction();
}

