#ifndef ADC_CFG_H
#define ADC_CFG_H

#define ADC0_SINGLE_ENDED   	00000
#define ADC1_SINGLE_ENDED   	00001
#define ADC2_SINGLE_ENDED   	00010
#define ADC3_SINGLE_ENDED   	00011
#define ADC4_SINGLE_ENDED   	00100
#define ADC5_SINGLE_ENDED   	00101
#define ADC6_SINGLE_ENDED   	00110
#define ADC7_SINGLE_ENDED   	00111
#define DIFFERENTIAL_PA0_NA0	01000

/*Configure the ADC resolution bits options are:      1- EIGHT_BITS
 * 													  2- TEN_BITS				*/

#define ADC_u8Resolution      TEN_BITS

typedef enum
{
	Div_2,Div_2P2,Div_4,Div_8,Div_16, Div_32, Div_64, Div_128
}Prescaler;


#endif
