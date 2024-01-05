#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERRType.h"

#include "DIO_interface.h"
#include "ExternalDAC_interface.h"
#include "ExternalDAC_cfg.h"
#include "ExternalDAC_priv.h"

void ExternalDAC_voidSetAnalogVolt(uint16 Copy_u16miliVolt)
{

	/*without the correct casting,
	 *  the digital value seemed to be always 0*/


	/*Without UL it always gave me ZERO even only U was not correct*/
	uint8 Digital= (uint8)(((uint16)Copy_u16miliVolt *256UL) /5000UL);
	if(Digital >255)
	{
		Digital =255;
	}
	DIO_u8SetPortValue(DAC_PORT,Digital);

}
