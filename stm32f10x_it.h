#ifndef __STM32F10x_IT_H
#define __STM32F10x_IT_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "pid.h"
#include "adc.h"
#include "string.h"
#include "usart.h"
#include "time.h"
#include "mpu6050.h"	
#include "OLED_I2C.h"
#include "keypro.h"
#include "mympu.h"
	 
extern float pitch,roll,yaw;
extern float X_SI,Y_SI;
extern float Angle_SI ;
extern int Ban_jing;
extern u8 Key_Mode ,Display_Flag,Debug_Value,PID_Flag;
	 
extern u8 Task_Flag;

extern long Time_Jishu;
extern float Kp,Ki,Kd;
extern	float x,y;

u8 Receive_Count,Flag_Ok;
int Receive_Data;
char receive[100];
u8 Speed=85;
u16 Time_Count;
	 
	 
void Display(void);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F10x_IT_H */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
