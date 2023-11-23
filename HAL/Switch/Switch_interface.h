#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

typedef enum
{
	PULL_DOWN, PULL_UP
}PullType;
typedef enum
{
	RELEASED,PRESSED
}SwitchState;
typedef struct
{
	uint8 Port;
	uint8 Pin;
	PullType Pulling;

}Switch_Config_t;

uint8 Switch_u8GetState (const Switch_Config_t* Copy_pstSwitchObj, SwitchState * Copy_penumState );

#endif
