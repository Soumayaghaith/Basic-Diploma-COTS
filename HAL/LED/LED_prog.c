#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERRType.h"

#include "DIO_interface.h"
#include "LED_interface.h"


uint8 LED_u8SetOn  (const LED_Config_t*Copy_pstLEDObj)
{
	uint8 Local_u8ErrorState = OK;
	if(Copy_pstLEDObj != NULL)
	{

		DIO_u8SetPinValue(Copy_pstLEDObj->Port,Copy_pstLEDObj->Pin,Copy_pstLEDObj->ActiveType);

	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}
uint8 LED_u8SetOff (const LED_Config_t* Copy_pstLEDObj)
{
	uint8 Local_u8ErrorState = OK;
	if(Copy_pstLEDObj != NULL)
	{

		DIO_u8SetPinValue(Copy_pstLEDObj->Port,Copy_pstLEDObj->Pin, ~(Copy_pstLEDObj->ActiveType) );

	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}
uint8 LED_u8Toggle (const LED_Config_t* Copy_pstLEDObj)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_pstLEDObj != NULL)
	{

		DIO_u8TogglePinValue(Copy_pstLEDObj->Port,Copy_pstLEDObj->Pin );

	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;

}
