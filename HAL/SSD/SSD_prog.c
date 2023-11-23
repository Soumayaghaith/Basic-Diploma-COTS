#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrType.h"

#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_priv.h"
#include "SSD_cfg.h"

uint8 SSD_u8ON(const SSD_Config_t* Copy_pstSSDConfigObj )
{
	uint8 Local_u8ErrorState = OK;
	if(Copy_pstSSDConfigObj != NULL)
	{
		if( (Copy_pstSSDConfigObj->Type == CATHODE) || (Copy_pstSSDConfigObj->Type == ETAKIT) )
		{
			DIO_u8SetPinValue(Copy_pstSSDConfigObj->EnablePort, Copy_pstSSDConfigObj->EnablePin,DIO_u8PIN_HIGH);
		}
		else if( (Copy_pstSSDConfigObj->Type == ANODE) )
		{
			DIO_u8SetPinValue(Copy_pstSSDConfigObj->EnablePort, Copy_pstSSDConfigObj->EnablePin,DIO_u8PIN_LOW);

		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}



	return Local_u8ErrorState;
}
uint8 SSD_u8OFF(const SSD_Config_t* Copy_pstSSDConfigObj)
{
	uint8 Local_u8ErrorState = OK;
	if(Copy_pstSSDConfigObj != NULL)
	{
		if( (Copy_pstSSDConfigObj->Type == CATHODE) || (Copy_pstSSDConfigObj->Type == ETAKIT) )
		{
			DIO_u8SetPinValue(Copy_pstSSDConfigObj->EnablePort, Copy_pstSSDConfigObj->EnablePin,DIO_u8PIN_LOW);
		}
		else if( (Copy_pstSSDConfigObj->Type == ANODE) )
		{
			DIO_u8SetPinValue(Copy_pstSSDConfigObj->EnablePort, Copy_pstSSDConfigObj->EnablePin,DIO_u8PIN_HIGH);

		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}



	return Local_u8ErrorState;

}
uint8 SSD_u8SetNumber(const SSD_Config_t* Copy_pstSSDConfigObj , uint8 Copy_u8Number)
{
	static uint8 Local_au8SSDArr[10]=   //static to not consume in stack
	{
			0b00111111,
			0b00000110,
			0b01011011,
			0b01001111,
			0b01100110,
			0b01101101,
			0b01111101,
			0b00000111,
			0b01111111,
			0b01101111
	};
	uint8 Local_u8ErrorState = OK;
	if(Copy_pstSSDConfigObj != NULL)
	{

		uint8 Local_u8Pin = Copy_pstSSDConfigObj->LEDAPin;
		uint8 Local_u8Iterator;
		if( (Copy_pstSSDConfigObj->Type == CATHODE) || (Copy_pstSSDConfigObj->Type == ETAKIT) )
		{
			for(Local_u8Iterator=0 ; Local_u8Iterator <7; Local_u8Iterator++, Local_u8Pin++)
			{
				DIO_u8SetPinValue (Copy_pstSSDConfigObj->LEDPort,Local_u8Pin,( Local_au8SSDArr[Copy_u8Number]>> Local_u8Iterator)&1 );
			}
		}
		else if( (Copy_pstSSDConfigObj->Type == ANODE) )
		{
			DIO_u8SetPinValue (Copy_pstSSDConfigObj->LEDPort,Local_u8Pin,( ~Local_au8SSDArr[Copy_u8Number]>> Local_u8Iterator)&1 );

		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}



	return Local_u8ErrorState;
}
