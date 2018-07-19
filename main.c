#include "delay.h"
#include "usart.h"
#include "time.h"
#include "Exit.h"
#include "mpu6050.h"
#include "OLED_I2C.h"
#include "mympu.h"
#include "keypro.h"
///////////////////////////////////////10ms  36 1

///////////////////////////////////////20ms   37 10 r=15cm Y 
///////////////////////////////////////2ND    36 10 R=15CM Y
/*
												15cm 33,2 X
												20cm 33,2 X
												25cm 33,2 X
												30cm 30,1 X
*/
///////////////14.0.10.zx
float Kp_x=27,Ki_x=0,Kd_x=2;//////////////////////////////////R=0
float Kp_y=49,Ki_y=0,Kd_y=10;/////////////////////////////////R=0
float Kp_ZhiDong=40,Ki_ZhiDong=0,Kd_ZhiDong=2000;		//9.2V

u8 Task_Flag=2;
float pitch=0,roll=0,yaw=0;
float Angle_SI = 9.5;
int Ban_jing =6350;

float x,y;
 int t;
long Time_Jishu=888;

u8 Key_Mode =0,Display_Flag =1,Debug_Value=0, PID_Flag = 0;


 int main()
{
	SystemInit();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	delay_init();
	uart_init(38400);		
	Usart_SendByte(USART2,1);
	KEY_Iint();
	
	Time1_PWM_Init(999,0);
	I2C_Configuration();
	OLED_Init();
	OLED_CLS();
	Show_Init();
	
	MPU_Init();
	while(mpu_dmp_init())
		delay_ms(200);
	
	TIM2_Timer_Init();	
	mpu_exit_int(1,0);
	
//	TIM_SetCompare1(TIM1, 500);
//	TIM_SetCompare2(TIM1, 600);
//	TIM_SetCompare3(TIM1, 700);
//	TIM_SetCompare4(TIM1, 0);
	Usart_SendByte(USART2,1);
	while(1)
	{
		u8 key_value =255;
		
		key_value = KeyProcess();
		if(key_value!=255)
			myKeypro(key_value);
		
//		oled_write_num(0,5,atan(Ban_jing/90.0f)*57.2958f,0,4);
////		oled_write_num(60,5,Ki_ZhiDong*10,1,4);
////		oled_write_num(0,5,Kp_ZhiDong,0,4);
////		oled_write_num(20,7,(int)x,0,4);
////		oled_write_num(20,7,(int)x,0,4);
////		oled_write_num(50,7,(int)y,0,4);
////		oled_write_num(0,6,t*10,1,8);
//////		oled_write_num(30,6,Time_Jishu,0,8);
////		oled_write_num(70,6,PWM,0,5);
			oled_write_num(0,5,Kp_x,0,4);
			oled_write_num(30,5,Kd_x,0,4);
			oled_write_num(0,6,Kp_y,0,4);
			oled_write_num(30,6,Kd_y,0,4);
			
			oled_write_num(0,7,PID_Flag,0,4);
			oled_write_num(30,7,Task_Flag,0,4);		
			oled_write_num(60,7,Ban_jing,0,4);			
//		Time_Jishu=0;
		
		Display();

		
		delay_ms(10);
	}
}


