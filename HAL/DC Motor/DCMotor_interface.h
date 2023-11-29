#ifndef DCMOTOR_INTERFACE_H
#define DCMOTOR_INTERFACE_H


typedef struct
{
	uint8 Port;
	uint8 Pin1;
	uint8 Pin2;

}DCMotor_Config_t;

uint8 DcMotor_u8RotateCW  (const DCMotor_Config_t* Copy_pstDCMotorObj);
uint8 DcMotor_u8RotateCCW (const DCMotor_Config_t* Copy_pstDCMotorObj);
uint8 DcMotor_u8Stop	  (const DCMotor_Config_t* Copy_pstDCMotorObj);

#endif
