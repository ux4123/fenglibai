#include "stm32f10x_it.h"


//u16 hongwai;
float R_X[4]={7.5,12.9904,12.9904,7.5};
float R_Y[4]={12.9904,7.5,-7.5,-12.9904};


float Control;
u8 Receive_PID_Flag,Receive_Data_Flag,Receive_Speed_Flag,Receive_Ad_Flag;
u8 zhong;
//float x,y;
//long Time_Jishu=0;
//float x,y;
float X_SI = -4,Y_SI =-1.8;
//void Display();
//void mode_1(void)
//{
//			x = baidong_balance_X(roll - X_SI, Ban_jing , 0);
//			y = baidong_balance_Y(pitch - Y_SI, 0 , 0);			
//			Set_Pwm(x,0);

//}
////////////zhi dong Y 24 40
////////////zhi dong X 22 25///////////////////////////22 30
void  EXTI9_5_IRQHandler(void) 
{  
	static int time = 0,count = -90;
//	int pXiangwei=1620;
//	static int t=0;
	static int X_Terminal = 0,Y_Terminal = 0;
	float pianzhi=0;
	if(PAin(5)==0)		
	{
		if(Time_Jishu ==0)
			TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE );	//使能或者失能指定的TIM中断
		else if(Time_Jishu!=888)
			TIM_ITConfig(TIM2, TIM_IT_Update, DISABLE );	//使能或者失能指定的TIM中断
			
//    EXTI->PR=1<<5;                             //清除LINE5上的中断标志位   
		while((mpu_dmp_get_data(&pitch,&roll,&yaw))!=0) 
			PWM=0;
			
		if(PID_Flag == 1)
		{
			switch(Task_Flag)
			{
				case 1:
				//	t+=10;
			//		if(t==1620) t=0;else t+=10;
					if(Ban_jing==30) pianzhi=1.4;else pianzhi=0.4;
					x = baidong_balance_X(roll - X_SI, 15 , 0);
				  y = baidong_balance_Y(-pitch+Y_SI+pianzhi, 15 ,0);			
				
//					if(Ban_jing>1)
//					Set_Pwm(x,y);//y = baidong_balance_Y(-pitch +Y_SI+pianzhi, R_Y[Ban_jing] , 3.14159);			
//					else
					Set_Pwm(0,y);	
					
		    	u2_printf("%d   ,%3.3f\r\n",(int)x,roll);
				break;
				case 2:
					x = PID_Control_Zhi_X(roll-X_SI)   ;  
					y = PID_Control_Zhi_Y(-pitch+Y_SI)   ;  

					//y = baidong_balance_Y(-pitch + Y_SI, Ban_jing , 0);			
//					if(myabs(roll - X_SI)<35||myabs(-pitch +Y_SI)<35)
//						Set_Pwm(0,0);
//					else
						Set_Pwm(x,y);
					            // 	if(myabs(roll)>45 || myabs(pitch)>45){Set_Pwm(0,0);}  //制动模式

					//u2_printf("%d   ,%3.3f\r\n",(int)x,roll);
					break;
				default:break;
			}
		}
//		oled_write_num(0,5,atan(Ban_jing/90.0f)*57.2958f,0,4);
//		oled_write_num(20,7,(int)x,0,4);
//		oled_write_num(50,7,(int)y,0,4);
//		oled_write_num(0,6,Time_Jishu,0,8);
//		oled_write_num(40,6,PWM,0,8);
//		Time_Jishu=0;
		
		time++;
		if(time==100)
		{
			Time_Jishu =0;
//			time=0;

		}
		
//		u2_printf("pitch = %3.3f \n",pitch);
//		u2_printf("roll = %3.3f \n",roll);
//		Usart_SendByte(USART2,(u8)(pitch+90));
//		Usart_SendByte(USART2,(u8)(roll+90));

		EXTI->PR=1<<5;   
	}
//	EXTI->IMR &= ~(EXTI_Line5);  		//失能外部中断  
} 

void USART2_IRQHandler(void)																//1 2
{
	u16 rec_data,i;
	static u32 Vlaue_Middle;
	if(USART_GetITStatus(USART2,USART_IT_RXNE)!=RESET)
	{		
		rec_data = USART_ReceiveData(USART2);

	}
}

void TIM2_IRQHandler(void)                 //1 0
{
	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	Time_Jishu++;
		
}

void Display(void)
{	
		Show_Init();
		switch(Display_Flag)
		{
			case 1:
				oled_write_num(36,2,roll*10,1,8);
				oled_write_num(36,3,pitch*10,1,8);
				oled_write_num(36,4,yaw*10,1,8);
				oled_write_num(80,2,Kp_x,0,8);
				oled_write_num(80,3,Kd_x,0,8);
				oled_write_num(80,4,Ki_x*10,1,8);break;
			case 2:
				switch(Debug_Value)
				{
					case 0:oled_write_num(30,2,Kp_x,0,8);
							 oled_write_num(30,3,Kd_x,0,8);
							 oled_write_num(30,4,Ki_x*10,1,8);break;
//					case 3:OLED_ShowString(0,15,"Kd_Y=");break;			
				}break;
//					case 3:
//						oled_write_num(40,35,(long)Balance_Value_X,0,0);
//						oled_write_num(40,45,(long)Balance_Value_Y,0,0);break;
//					case 4:
//						oled_write_num(40,35,(long)Position_X,0,0);
//						oled_write_num(40,45,(long)Position_Y,0,0);break;
			case 5:break;
			case 6:break;
			case 7:break;
		}
}
