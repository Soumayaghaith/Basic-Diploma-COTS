#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

typedef enum
{
	ACTIVE_LOW, ACTIVE_HIGH
}LEDAvtiveType;

typedef struct
{
	uint8 Port;
	uint8 Pin;
	LEDAvtiveType ActiveType;

}LED_Config_t;

uint8 LED_u8SetOn  (const LED_Config_t* Copy_pstLEDObj);
uint8 LED_u8SetOff (const LED_Config_t* Copy_pstLEDObj);
uint8 LED_u8Toggle (const LED_Config_t* Copy_pstLEDObj);

#endif
