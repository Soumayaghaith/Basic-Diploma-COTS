#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

typedef enum
{
	ANODE, CATHODE, ETAKIT
}SSD_Common_t;
typedef struct  
{
	SSD_Common_t Type;
	uint8 LEDPort;
	uint8 LEDAPin;
	
	uint8 EnablePort;
	uint8 EnablePin;
	
	
}SSD_Config_t;

uint8 SSD_u8ON(const SSD_Config_t* Copy_pstSSDConfigObj );
uint8 SSD_u8OFF(const SSD_Config_t* Copy_pstSSDConfigObj);
uint8 SSD_u8SetNumber(const SSD_Config_t* Copy_pstSSDConfigObj , uint8 Copy_u8Number);



#endif
