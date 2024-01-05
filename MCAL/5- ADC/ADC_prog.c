#include  "STD_TYPES.h"
#include  "BIT_MATH.h"
#include  "ErrType.h"

#include "ADC_reg.h"
#include "ADC_cfg.h"
#include "ADC_priv.h"
#include "ADC_interface.h"


void ADC_voidInit(const ADC_Config_t* Copy_pstADCObj)
{
	/*Select the reference volt*/
	ADMUX =  (ADMUX & REFERENCE_VOLT_BITS_MASK) | Copy_pstADCObj->ReferencVolt;


	/* Select left or right adjust according to resolution configuration */
	if(Copy_pstADCObj ->Resolution == EIGHT_BITS)
	{
		SET_BIT(ADMUX,ADMUX_ADLAR);
	}
	else if(Copy_pstADCObj ->Resolution == TEN_BITS)
	{
		CLR_BIT(ADMUX,ADMUX_ADLAR);
	}


	if(Copy_pstADCObj->InterruptEnable ==1)
	{
		SET_BIT(ADCSRA, ADCSRA_ADIE);
	}
	else if (Copy_pstADCObj->InterruptEnable ==0)
	{
		CLR_BIT(ADCSRA, ADCSRA_ADIE);
	}

	/*Configure Prescaler Division */
	ADCSRA = ((ADCSRA & PRESCALER_BITS_MASK ) | Copy_pstADCObj->Prescaler)<<0;

	/*Auto-trigger source enable */
	if(Copy_pstADCObj->AutoTriggerEnable ==1)
	{
		SET_BIT(ADCSRA, ADCSRA_ADATE);
	}
	else if(Copy_pstADCObj->AutoTriggerEnable ==0)
	{
		CLR_BIT(ADCSRA, ADCSRA_ADATE);
	}


	/*Enable the ADC peripheral after setting the required configurations*/
	SET_BIT(ADCSRA, ADCSRA_ADEN);


}
uint16 ADC_u8GetChannelReading(uint8 Copy_u8Channel)
{

	/*Select the channel*/
	ADMUX = ((ADMUX & CHANNEL_BITS_MASK ) | Copy_u8Channel);

	/*Start Conversion*/
	SET_BIT(ADCSRA, ADCSRA_ADSC);

	/*Polling on the ADC Flag*/
	while(GET_BIT(ADCSRA,ADCSRA_ADIF) != 1);

	/*Clear the ADC flag by writing logical one*/
	SET_BIT(ADCSRA, ADCSRA_ADIF);

	/*take the sample reading*/
#if ADC_u8Resolution == TEN_BITS
	uint8 Local_u8Reading = ADC;
#elif ADC_u8Resolution == EIGHT_BITS
	uint8 Local_u8Reading = ADCH;
#endif


	return Local_u8Reading;


}






