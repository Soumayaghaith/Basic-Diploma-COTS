#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include  "GIE_reg.h"
#include  "GIE_interface.h"



void GIE_voidEnableGlobal(void)
{
	__asm volatile ("SEI"); /*Inline assembly to set I-Bit*/
	/*SET_BIT(SREG,SREG_I)8*/;
}

void GIE_voidDisableGlobal(void)
{
	__asm volatile ("CLI");   /*Inline assembly to clear I-Bit*/
	
	/*CLR _BIT(SREG,SREG_I);*/
}
