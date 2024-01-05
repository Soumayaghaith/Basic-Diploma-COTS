#ifndef ADC_REG_H
#define ADC_REG_H



#define ADMUX       *((volatile uint8*) 0x27)
#define ADMUX_RFS0		6
#define ADMUX_RFS1	    7
#define ADMUX_ADLAR		5



#define ADCSRA			*((volatile uint8*) 0x26)
#define ADCSRA_ADEN		7
#define ADCSRA_ADSC		6
#define ADCSRA_ADATE    5
#define ADCSRA_ADIF		4
#define ADCSRA_ADIE		3

#define ADCH      *((volatile uint8*) 0x25)
#define ADCL      *((volatile uint8*) 0x24)
#define ADC       *((volatile uint16*) 0x24)


/*to select the autotrigger source*/
#define SFIOR     *((volatile uint8*) 0x50)


#endif
