#include "STD_TYPES.h"
#include "ErrType.h"
#include "BIT_MATH.h"
#include <util/delay.h>


#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_priv.h"
#include "CLCD_cfg.h"

#if CLCD_u8BIT_MODE == FOUR_BIT
static void voidSetHalfDataPort(uint8 Copy_u8Data)
{
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8D4_PIN,GET_BIT(Copy_u8Data,0));
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8D5_PIN,GET_BIT(Copy_u8Data,1));
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8D6_PIN,GET_BIT(Copy_u8Data,2));
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8D7_PIN,GET_BIT(Copy_u8Data,3));
}
#endif

static void voidSendEnablePulse(void)
{
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN ,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN ,DIO_u8PIN_LOW);
}
void CLCD_voidSendCmd (uint8 Copy_u8Cmd)
{
	/*Set RS pin to low for command*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RS_PIN ,DIO_u8PIN_LOW);

	/*Set RW pin to low for writing */
#if CLCD_u8RW_CONN_STS == DIO_CONNECTED

	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RW_PIN ,DIO_u8PIN_LOW);
#endif

#if CLCD_u8BIT_MODE == EIGHT_BIT
	/*Send the command*/
	DIO_u8SetPortValue(CLCD_u8DATA_PORT,Copy_u8Cmd);
	/*Set enable pulse */
	voidSendEnablePulse();
#elif CLCD_u8BIT_MODE == FOUR_BIT
	voidSetHalfDataPort(Copy_u8Cmd >>4); /*Send the 4 most signifcant bits of the command first */
	voidSendEnablePulse();
	voidSetHalfDataPort(Copy_u8Cmd );
	voidSendEnablePulse();
#else
#error wrong CLCD_u8BIT_MODE Configuration Option
#endif

}

void CLCD_voidSendData (uint8 Copy_u8Data)
{
	/*Set RS pin to high for data*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RS_PIN ,DIO_u8PIN_HIGH);

	/*Set RW pin to low for writing */
#if CLCD_u8RW_CONN_STS == DIO_CONNECTED

	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RW_PIN ,DIO_u8PIN_LOW);
#endif

#if CLCD_u8BIT_MODE == EIGHT_BIT
	/*Send the data*/
	DIO_u8SetPortValue(CLCD_u8DATA_PORT,Copy_u8Data);
	/*Set enable pulse */
	voidSendEnablePulse();
#elif CLCD_u8BIT_MODE == FOUR_BIT
	voidSetHalfDataPort(Copy_u8Data >>4); /*Send the 4 most significant bits of the data first */
	voidSendEnablePulse();
	voidSetHalfDataPort(Copy_u8Data );
	voidSendEnablePulse();
#else
#error wrong CLCD_u8BIT_MODE Configuration Option
#endif


}

void CLCD_voidInit (void)
{
	/*Wait for more than 30 ms after Power On*/
	_delay_ms(40);

	/*Function set command: 2 lines, 5x7*/
#if CLCD_u8BIT_MODE == EIGHT_BIT
	CLCD_voidSendCmd(0b00111000);
#elif CLCD_u8BIT_MODE == FOUR_BIT
	voidSetHalfDataPort(0b0010);
	voidSendEnablePulse();
	voidSetHalfDataPort(0b0010);
	voidSendEnablePulse();
	voidSetHalfDataPort(0b1000);
	voidSendEnablePulse();

#endif
	/*  we do not need the delay of 39 us as
	 *  the function send command its self
	 * waits 2ms and that was the purpose for the 2ms*/

	/*Display on off control: Display on, Cursor off, Blink Cursor off*/
	CLCD_voidSendCmd(0b00001100);

	/*Clear display*/
	CLCD_voidSendCmd(1);
}

uint8 CLCD_u8SendString(const char* Copy_PchString)
{
	uint8 Local_u8ErrorState =OK;
	if(Copy_PchString != NULL)
	{
		uint8 Local_u8LoopCounter=0;
		while(Copy_PchString[Local_u8LoopCounter] != '\0')
		{
			CLCD_voidSendData(Copy_PchString[Local_u8LoopCounter]);
			Local_u8LoopCounter++;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR ;
	}

	return Local_u8ErrorState;
}

void CLCD_voidSendNumber(sint32 Copy_s32Number)
{
	uint8 Local_u8TotalDigits[10];
	uint8 Local_u8NumberOfDigits=0;
	sint8 Local_s8iterator;
	if(Copy_s32Number >= 0)
	{

		if(Copy_s32Number==0)
		{
			CLCD_voidSendData('0');

		}
		else
		{
			while(Copy_s32Number>0)
			{

				Local_u8TotalDigits[ Local_u8NumberOfDigits] =  Copy_s32Number%10; //get the right most digit
				Local_u8NumberOfDigits++;
				Copy_s32Number/=10;

			}
			sint8 Local_s8iterator;
			for(Local_s8iterator= (sint8)Local_u8NumberOfDigits-1;  Local_s8iterator>=0 ;Local_s8iterator--)
			{
				CLCD_voidSendData((Local_u8TotalDigits[(uint8)Local_s8iterator]+48));
			}
		}
	}
	else
	{
		CLCD_voidSendData('-');
		Copy_s32Number =Copy_s32Number*-1;


		while(Copy_s32Number>0)
		{

			while(Copy_s32Number>0)
			{

				Local_u8TotalDigits[ Local_u8NumberOfDigits] = (uint8)((uint32) Copy_s32Number%10);
				Local_u8NumberOfDigits++;
				Copy_s32Number/=10;

			}

			for(Local_s8iterator=Local_u8NumberOfDigits-1;  Local_s8iterator>=0 ;Local_s8iterator--)
			{
				CLCD_voidSendData((Local_u8TotalDigits[Local_s8iterator]+48));
			}
		}

	}


}
void CLCD_voidGoToXY(uint8 Copy_u8XPos, uint8 Copy_u8YPos)
{
	uint8 Local_u8Address;
	Local_u8Address = 0x40*Copy_u8YPos + Copy_u8XPos;
	/*if(Copy_u8YPos==0)
	{
		Local_u8Address=Copy_u8XPos;
	}
	else if(Copy_u8YPos==1)
	{
		Local_u8Address=Copy_u8XPos +0x40;
	}*/
	/*Set bit 7 to be 1 for Set DDRAM Address Command*/
	Local_u8Address |= (1<<7);
	/* Excute DDRAM Address Command*/
	CLCD_voidSendCmd(Local_u8Address);
}
uint8 CLCD_voidSendSpecialCharacter (uint8 Copy_u8LocationNum, uint8* Copy_u8Pattern,uint8 Copy_u8XPos, uint8 Copy_u8YPos)
{
	uint8 Local_u8ErrorState=OK;
	uint8 Local_CGRAMAdderss =Copy_u8LocationNum *8;
	uint8 Local_u8CounterLoop;
	if(Copy_u8Pattern !=NULL)
	{
		/*Set Bit six for CGRAM Address*/
		SET_BIT(Local_CGRAMAdderss,6);
		/*Set  CGRAM Address*/
		CLCD_voidSendCmd(Local_CGRAMAdderss);

		/*Write the input pattern inside the CGRAM*/
		for(Local_u8CounterLoop=0;Local_u8CounterLoop<8u; Local_u8CounterLoop++)
		{
			CLCD_voidSendData(Copy_u8Pattern[Local_u8CounterLoop]);
		}
		/*Go back to DDRAM and the function gotoxy deals with ddram*/
		CLCD_voidGoToXY(Copy_u8XPos, Copy_u8YPos);

		/*Display Special pattern inside CGRAM*/
		CLCD_voidSendData(Copy_u8LocationNum);
	}
	else
	{
		Local_u8ErrorState =NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}
