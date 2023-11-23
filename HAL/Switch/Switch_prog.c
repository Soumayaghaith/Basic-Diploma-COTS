#include "STD_TYPES.h"
#include "ERRType.h"

#include "DIO_interface.h"
#include "Switch_interface.h"

uint8 Switch_u8GetState (const Switch_Config_t* Copy_pstSwitchObj, SwitchState * Copy_penumState )
{
	uint8 Local_u8ErrorState =OK;
	if( (Copy_pstSwitchObj != NULL) && (Copy_penumState != NULL) )
	{
		uint8 Local_u8State ;
		if(Copy_pstSwitchObj ->Pulling == PULL_DOWN)
		{
			DIO_u8ReadPinValue(Copy_pstSwitchObj->Port, Copy_pstSwitchObj ->Pin, &Local_u8State);
			if(Local_u8State == DIO_u8PIN_HIGH)
			{
				*Copy_penumState =PRESSED;

			}
			else
			{
				*Copy_penumState = RELEASED;
			}
		}
		else if(Copy_pstSwitchObj ->Pulling == PULL_UP)
		{
			DIO_u8ReadPinValue(Copy_pstSwitchObj->Port, Copy_pstSwitchObj ->Pin, &Local_u8State);
			if(Local_u8State == DIO_u8PIN_HIGH)
			{
				*Copy_penumState =RELEASED;

			}
			else
			{
				*Copy_penumState = PRESSED;
			}
		}

	}
	else
	{
		Local_u8ErrorState =NULL_PTR_ERR;
	}


	return Local_u8ErrorState;

}
