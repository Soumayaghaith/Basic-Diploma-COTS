#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

typedef enum
{
	AREF,AVCC,RESERVED,INTERNAL2_56

}RefVolt_t;
typedef struct
{
	RefVolt_t ReferencVolt;
	uint8 	  Resolution; /*Options are on the cfg file*/
	uint8     Prescaler;

	uint8     InterruptEnable; /*Enable interrupts by sending 1
	 	 	 	 	 	 	 	Disable interrupts by sending 0*/


	uint8 	  AutoTriggerEnable;/*Enable Auto-trigger by sending 1
	 	 	 	 	 	 	 	Disable Auto-trigger by sending 0*/

}ADC_Config_t;


void ADC_voidInit(const ADC_Config_t* Copy_pstADCObj);
uint16 ADC_u8GetChannelReading(uint8 Copy_u8Channel);

#endif
