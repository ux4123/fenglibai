#ifndef __PID_H
#define	__PID_H

#include "stm32f10x.h"
#include "adc.h"
#include "math.h"
//#include "stm32f10x_gpio.h"

extern float Kp_x,Kp_y,Ki_x,Ki_y,Kd_x,Kd_y,Angle_Balance;
extern float Angle_SI;
extern float Kp_ZhiDong,Ki_ZhiDong,Kd_ZhiDong;


extern float X_SI,Y_SI;



extern int t;
//int Balance_PID(float Angle);
float PID_Control_X(float X_now,float X_To)  ;    //½Ç¶È ½ÇËÙ¶È
float PID_Control_Y(float X_now,float X_To)    ;
float PID_Control_Zhi_X(float X_now)   ;  
float PID_Control_Zhi_Y(float X_now)   ; 

float PID_ZhiDong_X(float X_now);      
float PID_ZhiDong_Y(float X_now);  

int baidong_balance_X(float Angle,int R,int xiangwei);
	int baidong_balance_Y(float Angle,int R,int xiangwei);
#endif 

