#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERRType.h"

#include "DIO_interface.h"

#include "DCMotor_interface.h"
#include "DCMotor_priv.h"
#include "DCMotor_cfg.h"

uint8 DcMotor_u8RotateCW  (const DCMotor_Config_t* Copy_pstDCMotorObj)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_pstDcMotorObj != NULL)
	{
		DIO_u8SetPinValue(Copy_pstDcMotorObj->Port, Copy_pstDcMotorObj->Pin2, DIO_u8PIN_LOW );
		DIO_u8SetPinValue(Copy_pstDcMotorObj->Port, Copy_pstDcMotorObj->Pin1, DIO_u8PIN_HIGH );
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}


	return Local_u8ErrorState;

}
uint8 DcMotor_u8RotateCCW (const DCMotor_Config_t* Copy_pstDCMotorObj)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_pstDcMotorObj != NULL)
	{
		DIO_u8SetPinValue(Copy_pstDcMotorObj->Port, Copy_pstDcMotorObj->Pin1, DIO_u8PIN_LOW );
		DIO_u8SetPinValue(Copy_pstDcMotorObj->Port, Copy_pstDcMotorObj->Pin2, DIO_u8PIN_HIGH );
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}


	return Local_u8ErrorState;

}
uint8 DcMotor_u8Stop	  (const DCMotor_Config_t* Copy_pstDCMotorObj)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_pstDcMotorObj != NULL)
	{
		DIO_u8SetPinValue(Copy_pstDcMotorObj->Port, Copy_pstDcMotorObj->Pin1, DIO_u8PIN_LOW );
		DIO_u8SetPinValue(Copy_pstDcMotorObj->Port, Copy_pstDcMotorObj->Pin2, DIO_u8PIN_LOW );
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}


	return Local_u8ErrorState;

}


