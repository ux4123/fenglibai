#ifndef __KEYPRO_H
#define	__KEYPRO_H

#include "stm32f10x.h"
#include "delay.h"
#include "OLED_I2C.h"
#include "math.h"
#include "usart.h"
#include "time.h"


#define  KEY_ADD 0				//按键最低位
#define  KEYH_Pin (GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3)
#define  KEYL_Pin (GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7)
#define  KEY KEYH_Pin|KEYL_Pin		//要求为高八位或低八位
#define  KEY_GPIO GPIOF
#define  KEY_RCC  RCC_APB2Periph_GPIOF

//extern u8 Key_Change_Flag,Key_Mode,Time_Begin_Flag,MPU_Init_Flag,Display_Flag,PID_Flag,SXT_Begin_Flag;

//extern float Kp_X,Ki_X,Kd_X;
//extern float Kp_Y,Ki_Y,Kd_Y;
//extern int Angle_Balance_X,Angle_Balance_Y;

//extern 	float Kp_Pos_X,Ki_Pos_X,Kd_Pos_X,Target_X;
//extern 	float Kp_Pos_Y,Ki_Pos_Y,Kd_Pos_Y,Target_Y;

//extern u8 Task_Flag,Task_3_Flag,Task_4_Flag,Task_5_Flag,Task_6_Flag,Task_7_Flag,Task_8_Flag;
//extern u16 Speed_Zheng,Speed_Fan,Position_X_Array[9],Position_Y_Array[9];

extern u8 Task_Flag;
extern float X_SI,Y_SI;
extern float pitch,roll,yaw;
extern u8 Key_Mode ,Display_Flag,Debug_Value,PID_Flag;
extern float Kp_x,Kp_y,Ki_x,Ki_y,Kd_x,Kd_y;
extern float Kp_ZhiDong,Ki_ZhiDong,Kd_ZhiDong;
extern int PWM;		/// -500:-15;-9
extern float Angle_SI ;
extern int Ban_jing;

void KEY_Iint(void);
u8 KeyProcess(void);
void Key_judje(u8 key_value);
void myKeypro(u8 key);	
#endif 
