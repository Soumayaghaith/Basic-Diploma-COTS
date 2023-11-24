#include "STD_TYPES.h"
#include "ERRType.h"

#include "DIO_interface.h"

#include "Keypad_interface.h"
#include "Keypad_priv.h" 
#include "Keypad_cfg.h" 

uint8 KEYPAD_u8GetPressedKey(void)
{
	uint8 Local_u8ColIndex;
	uint8 Local_u8RowIndex;
	uint8 Local_u8PinState;
	uint8 Local_u8PressedKey = KPD_u8NO_PRESSED_KEY_VAL;

	/*  I created an array to keep the option we provided to the user
	 *  that he do not need to connect the column pins on the same port */
	uint8 Local_au8ColArr[COL_NUM]= {  KPD_u8COL0_PIN	,KPD_u8COL1_PIN	 ,KPD_u8COL2_PIN ,KPD_u8COL3_PIN	};
	uint8 Local_au8RowArr[ROW_NUM]= {  KPD_u8ROW0_PIN	,KPD_u8ROW1_PIN	 ,KPD_u8ROW2_PIN ,KPD_u8ROW3_PIN	};

	uint8 Local_au8KPDArr[ROW_NUM][COL_NUM] =  KPD_au8_BUTTON_ARR ;


	/*The outer loop is responsible for activate the column pins*/
	for(Local_u8ColIndex= 0U ; Local_u8ColIndex < COL_NUM; Local_u8ColIndex++)
	{
		/* Activate the current column */
		DIO_u8SetPinValue(KPD_u8COL_PORT, Local_au8ColArr[Local_u8ColIndex] ,DIO_u8PIN_LOW);
		/* Read the row pins*/
		for(Local_u8RowIndex= 0U ; Local_u8RowIndex < ROW_NUM; Local_u8RowIndex++)
		{
			/* Read the current row */
			DIO_u8ReadPinValue(KPD_u8ROW_PORT,Local_au8RowArr[Local_u8RowIndex],&Local_u8PinState);
			if(Local_u8PinState == DIO_u8PIN_LOW)
			{
				Local_u8PressedKey = Local_au8KPDArr [Local_u8RowIndex][Local_u8ColIndex];

				/*Polling with blocking (waiting) until the key is released */
				while(Local_u8PinState == DIO_u8PIN_LOW)
				{
					DIO_u8ReadPinValue(KPD_u8ROW_PORT,Local_au8RowArr[Local_u8RowIndex],&Local_u8PinState);
				}

				break;
			}





		}
		/*Deactivate the current column */
						DIO_u8SetPinValue(KPD_u8COL_PORT, Local_au8ColArr[Local_u8ColIndex] ,DIO_u8PIN_HIGH);
	}
	return Local_u8PressedKey;
}

























