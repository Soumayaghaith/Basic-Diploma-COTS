#ifndef CLCD_INTERFACE_H
#define CLCD_INTERFACE_H

#define CLCD_CLEAR_COMMAND    1u

void CLCD_voidSendCmd (uint8 Copy_u8Cmd);

void CLCD_voidSendData (uint8 Copy_u8Data);

void CLCD_voidInit (void);

uint8 CLCD_u8SendString(const char* Copy_PchString);

void CLCD_voidSendNumber(sint32 Copy_s32Number);

void CLCD_voidGoToXY(uint8 Copy_u8XPos, uint8 Copy_u8YPos);

uint8 CLCD_voidSendSpecialCharacter (uint8 Copy_u8LocationNum, uint8* Copy_u8Pattern,uint8 Copy_u8XPos, uint8 Copy_u8YPos);
#endif
