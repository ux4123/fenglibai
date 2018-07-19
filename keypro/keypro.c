#include "keypro.h"
//	u8 key,time,Debug_Flag;

//	u8 Debug_Position,Debug_Weishu,Debug_Array[10];
int PWM=-900;		/// -500:-15;-9
//	u16 Debug_Result_Data;
void Key_GPIO_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin=KEYH_Pin;                 
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(KEY_GPIO,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=KEYL_Pin;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;	//上拉输入
	GPIO_Init(KEY_GPIO,&GPIO_InitStructure);	
}

void KEY_Iint()
{
	RCC_APB2PeriphClockCmd(KEY_RCC,ENABLE);
	Key_GPIO_Init();
}

u8 KeyProcess()
{
	u8 key, key_value=255;
	u8 time;
	GPIO_Write(KEY_GPIO,(GPIO_ReadInputData(KEY_GPIO)&(0xff<<(8-KEY_ADD)))|(0xf7<<KEY_ADD));  //判断第一行那个按键按下

	if((GPIO_ReadInputData(KEY_GPIO)&(0xff<<KEY_ADD))!=(0xf7<<KEY_ADD))		   //h1
	{
		delay_ms(10);	  //消抖
		if((GPIO_ReadInputData(KEY_GPIO)&(0xff<<KEY_ADD))!=(0xf7<<KEY_ADD))
		{
			key=(u8)((GPIO_ReadInputData(KEY_GPIO)&(0xf0<<KEY_ADD))>>KEY_ADD);
			switch(key)		
			{
				case 0xe0: key_value=1;break;
				case 0xd0: key_value=2;break;
				case 0xb0: key_value=3;break;
				case 0x70: key_value=10;break;
			}
			Usart_SendByte(USART2,(u8)key_value);
		}
		while((GPIO_ReadInputData(KEY_GPIO)&(0xff<<KEY_ADD))!=(0xf7<<KEY_ADD)&&time!=30)
		{
			time++;
			delay_ms(10);
		}
		time=0;
	}
/////////////////////////
	GPIO_Write(KEY_GPIO,(GPIO_ReadInputData(KEY_GPIO)&(0xff<<(8-KEY_ADD)))|(0xfb<<KEY_ADD));  //判断第2行那个按键按下

	if((GPIO_ReadInputData(KEY_GPIO)&(0xff<<KEY_ADD))!=(0xfb<<KEY_ADD))
	{
		delay_ms(10);
		if((GPIO_ReadInputData(KEY_GPIO)&(0xff<<KEY_ADD))!=(0xfb<<KEY_ADD))
		{
			
			key=(u8)((GPIO_ReadInputData(KEY_GPIO)&(0xf0<<KEY_ADD))>>KEY_ADD);
			switch(key)		
			{
				case 0xe0: key_value=4;break;
				case 0xd0: key_value=5;break;
				case 0xb0: key_value=6;break;
				case 0x70: key_value=11;break;
			}
			Usart_SendByte(USART2,(u8)key_value);
		}
		while((GPIO_ReadInputData(KEY_GPIO)&(0xff<<KEY_ADD))!=(0xfb<<KEY_ADD)&&time!=30)
		{
			time++;
			delay_ms(10);
		}
		time=0;
	}

	GPIO_Write(KEY_GPIO,(GPIO_ReadInputData(KEY_GPIO)&(0xff<<(8-KEY_ADD)))|(0xfd<<KEY_ADD));  //判断第3行那个按键按下

	if((GPIO_ReadInputData(KEY_GPIO)&(0xff<<KEY_ADD))!=(0xfd<<KEY_ADD))
	{
		delay_ms(10);
		if((GPIO_ReadInputData(KEY_GPIO)&(0xff<<KEY_ADD))!=(0xfd<<KEY_ADD))
		{			
			key=(u8)((GPIO_ReadInputData(KEY_GPIO)&(0xf0<<KEY_ADD))>>KEY_ADD);
			switch(key)		
			{
				case 0xe0: key_value=7;break;
				case 0xd0: key_value=8;break;
				case 0xb0: key_value=9;break;
				case 0x70: key_value=12;break;
			}
			Usart_SendByte(USART2,(u8)key_value);
		}
 	while((GPIO_ReadInputData(KEY_GPIO)&(0xff<<KEY_ADD))!=(0xfd<<KEY_ADD)&&time!=30)
		{
			time++;
			delay_ms(10);
		}
		time=0;
	}

	GPIO_Write(KEY_GPIO,(GPIO_ReadInputData(KEY_GPIO)&(0xff<<(8-KEY_ADD)))|(0xfe<<KEY_ADD)); //判断第4行那个按键按下

	if((GPIO_ReadInputData(KEY_GPIO)&(0xff<<KEY_ADD))!=(0xfe<<KEY_ADD))
	{
		delay_ms(10);
		if((GPIO_ReadInputData(KEY_GPIO)&(0xff<<KEY_ADD))!=(0xfe<<KEY_ADD))
		{
			key=(u8)((GPIO_ReadInputData(KEY_GPIO)&(0xf0<<KEY_ADD))>>KEY_ADD);
			switch(key)		
			{
				case 0xe0: key_value=13;break;
				case 0xd0: key_value=0;break;
				case 0xb0: key_value=14;break;
				case 0x70: key_value=15;break;
			}
			Usart_SendByte(USART2,(u8)key_value);
		}
		while((GPIO_ReadInputData(KEY_GPIO)&(0xff<<KEY_ADD))!=(0xfe<<KEY_ADD)&&time!=30)
		{
			time++;
			delay_ms(10);
		}
		time=0;
	}
	return key_value;
}

/*
void Key_judje(u8 key_value)
{
	char tempr[25]=0;
	switch(Key_Mode)
	{
		case 0:                    //开始模式
			switch(key_value)
			{				
				case 0: Key_Mode=0;break;
				case 1: Key_Mode=1;break;
				case 2: Key_Mode=2;break;
				case 3: Key_Mode=3;break;
				case 4: Set_Pwm(PWM,PWM);
								PWM+=100;break; 
				case 5: X_SI = roll;
								Y_SI = pitch;
								break;
				case 6:Angle_SI = (X_SI - roll + Y_SI - pitch)/2;break;
				case 7:PID_Flag = 1;break;
				case 8:Ban_jing += 10;break;
				case 9:Ban_jing = 0;break;
			}
			break;
		case 1:										//调试模式
			switch(key_value)
			{
				case 1:Kp+=10;break;
				case 2:Kp-=10;break;
				case 3:Kp+=1;break;
				case 4:Kp-=1;break;
				case 5:Kd+=50;break;
				case 6:Kd-=50;break;
				case 7:Ki+=0.1;break;
				case 8:Ki-=0.1;break;
				case 9:Kp_ZhiDong+=10;break;
				case 10:Kp_ZhiDong-=10;break;
				case 11:Ki_ZhiDong+=0.1;break;
				case 12:Ki_ZhiDong-=0.1;break;
				case 0: Kd_ZhiDong+=10;break;
				case 13:Key_Mode=0;break;
			}
//			if(key_value==13)
//			{
//				Debug_Flag=0;
//				Key_Mode=0;
//				Debug_Weishu=0;
//				Debug_Position=0;
//				Show_Init();
//				
//					break;		
//			}	
//			if(	Debug_Flag==0)		
//			{
//				OLED_Clear();
//				OLED_ShowString(0,0,"Debug Mode");
//				Debug_Value=key_value;
//				Debug_Flag++;
//				
//				break;
//			}
//			if(key_value==14)
//			{
//				Debug_Flag=0;
//				for(i=0;i<Debug_Weishu;i++)																				//之前数据送入数据数组
//				{	
//					Debug_Result_Data+=Debug_Array[i]*pow(10,Debug_Weishu-i-1);
//				}
//				Debug_Weishu=0;Debug_Position=0;
//				switch(Debug_Value)
//				{
//					case 0:Kp_X=Debug_Result_Data;break;
//					case 1:Kd_X=Debug_Result_Data;break;
//					case 2:Kp_Y=Debug_Result_Data;break;
//					case 3:Kd_Y=Debug_Result_Data;break;
//					case 4:Kp_Pos_X=Debug_Result_Data;break;
//					case 5:Kd_Pos_X=Debug_Result_Data;break;
//					case 6:Kp_Pos_Y=Debug_Result_Data;break;
//					case 7:Kd_Pos_Y=Debug_Result_Data;break;
//					case 8:Ki_Pos_X=Debug_Result_Data;break;
//					case 9:Ki_Pos_Y=Debug_Result_Data;break;
//					case 10:Target_X=Debug_Result_Data;break;
//					case 11:Target_Y=Debug_Result_Data;break;
//					case 12:Ki_X=Debug_Result_Data;break;
//					case 13:Ki_Y=Debug_Result_Data;break;
//				}
//				Debug_Result_Data=0;
//				Key_Mode=0;
//				Show_Init();				
//			}
//			else if(key_value<10)
//			{	
//					Debug_Array[Debug_Weishu]=key_value;Debug_Weishu++;
//					OLED_ShowNumber(95,53,key_value,3,12);
//					OLED_Refresh_Gram();//更新显示到 OLED
//					Debug_Position+=6;
//			}
			break;
		case 2:										     //控制模式
////			if(key_value==15)
////			{
////				Key_Mode=0;
////				Show_Init();
////				Time_Begin_Flag=0;
////				Task_Flag=0;
////					break;		 
////			}
			switch(key_value)
			{
					case 0:Task_Flag=0;break;
					case 1:Task_Flag=1;break;
					case 2:Task_Flag=2;break;
//					case 3:Task_Flag=3;Task_3_Flag=1;Target_X=328;Target_Y=414;break;
//					case 4:Task_Flag=4;Task_4_Flag=1;break;
//					case 5:Task_Flag=5;Task_5_Flag=1;break;
//					case 6:Task_Flag=6;Task_6_Flag=1;break;
//					case 7:Task_Flag=7;Task_7_Flag=1;break;
					case 13:Key_Mode=0;break;
			}
////			Time_Begin_Flag=1;
			break;
		case 3: 					
					Display_Flag=key_value;
					Key_Mode=0;
//					Show_Init(Display_Flag);	
					break;
//		case 5: 					
//					Display_Flag=key_value;
//					Key_Mode=0;
//					break;
//		case 9:break;
			
	}
//	OLED_ON();
}
*/
extern float X_SI,Y_SI;


void myKeypro(u8 key)
{
	switch(key)
	{
		case 13:if(PID_Flag==1) PID_Flag=0;else PID_Flag=1;break;
		case 7:Task_Flag=1;break;
		case 4:Task_Flag=2;break;
		case 1:Y_SI=pitch;X_SI=roll;break;
		
		case 0:Set_Pwm(0,0);PID_Flag=0;break;//Set_Pwm(100,100);break;//if(zhixianR==10) zhixianR=1;zhixianR+=1;break;//Set_Pwm(100,0);break;
		case 8:if(Ban_jing==6370) Ban_jing=6350;else Ban_jing+=1;break;//Set_Pwm(150,150);break;//if(xiangwei==360) xiangwei=0; xiangwei+=30; break;//Set_Pwm(-100,0);break;
		case 5://Set_Pwm(0,200);break;//Set_Pwm(0,100);break;
		case 2://Set_Pwm(0,-200);break;//Set_Pwm(0,-100);break;
		
		case 14:Kp_x-=1;break;//xPID.kp+=1;break;
		case  9:Kp_x+=1;break;//xPID.kp-=1;break;
		case  6:Kp_y-=1;break;//xPID.kd+=1;break;
		case  3:Kp_y+=1;break;//xPID.kd-=1;break;
		
		case 15:Kd_x-=1;break;//yPID.kp+=1;break;
		case 12:Kd_x+=1;break;//yPID.kp-=1;break;
		case 11:Kd_y-=1;break;//yPID.kd+=1;break;
		case 10:Kd_y+=1;break;//yPID.kd-=1;break;

		default:break;	
	}
	

}

