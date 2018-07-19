#include "clock.h"

void RTC_INIT()			  //实时时钟的初始化
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);//打开电源时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP,ENABLE);//打开存储器时钟
	PWR_DeInit();
	PWR_BackupAccessCmd(ENABLE);//使能或者失能RTC和后备寄存器访问
	BKP_DeInit();//将外设BKP的全部寄存器重设为缺省值
//	RCC_LSEConfig(RCC_LSE_ON);//设置外部低速晶振（LSE）
//	while(RCC_GetFlagStatus(RCC_FLAG_LSERDY)==RESET);//检查指定的RCC标志位设置与否
//	RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);//设置RTC时钟（RTCCLK）
//	RCC_RTCCLKCmd(ENABLE);//使能或者失能RTC时钟
	
//	RTC_WaitForSynchro(); //等待RTC寄存器同步
//	RTC_WaitForLastTask();//等待最近一次对RTC寄存器的写操作完成
//	RTC_ITConfig(RTC_IT_SEC,ENABLE);//使能或者失能指定的RTC中断
//	RTC_WaitForLastTask();//等待最近一次对RTC寄存器的写操作完成
//	RTC_SetPrescaler(32767);//设置预分频 使用外部晶振为32.768K，要想1s中断则预分频数设置为32767，系统会在此数字基础上加1
//	RTC_WaitForLastTask();//等待最近一次对RTC寄存器的写操作完成
    RCC_LSICmd(ENABLE);  
    while (RCC_GetFlagStatus(RCC_FLAG_LSIRDY) == RESET)  
    {  
    }  
    RCC_RTCCLKConfig(RCC_RTCCLKSource_LSI);  
  
    RCC_RTCCLKCmd(ENABLE);  
  
  
#ifdef RTCClockOutput_Enable  
    /* Disable the Tamper Pin */  
    BKP_TamperPinCmd(DISABLE); 
    BKP_RTCCalibrationClockOutputCmd(ENABLE);  
#endif   
    RTC_WaitForSynchro(); 
    RTC_WaitForLastTask();  
    RTC_ITConfig(RTC_IT_SEC, ENABLE);  
    RTC_WaitForLastTask();  
    RTC_SetPrescaler(41900);            /* RTC period = RTCCLK/RTC_PR = (40.000 KHz)/(39999+1) 40879*/  
    RTC_WaitForLastTask(); 
}

void CLOCK_NVIC_INIT()			 //中断模式初始化配置
{
	NVIC_InitTypeDef NVIC_InitStructure; 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); 

	NVIC_InitStructure.NVIC_IRQChannel = RTC_IRQn; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 5; 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);

}


void CLOCK_INIT()
{
	CLOCK_NVIC_INIT();
	RTC_INIT();
//	CLOCK_NVIC_INIT();
	
	if(BKP_ReadBackupRegister(BKP_DR1)!=0XA5A5)//从指定的后备寄存器中读出数据
	{
		//第一次运行  初始化设置
		//RTC初始化
		RTC_WaitForLastTask();//等待最近一次对RTC寄存器的写操作完成
		RTC_SetCounter(0xa668);//设置RTC计数器的值 11:50：00    1001 1111 1001 0010
		RTC_WaitForLastTask();
		BKP_WriteBackupRegister(BKP_DR1,0xA5A5);
	}
	else
	{	
		RTC_WaitForSynchro();//等待RTC寄存器同步	
		RTC_WaitForLastTask();//等待写RTC寄存器完成		
	    RTC_ITConfig(RTC_IT_SEC,ENABLE);//使能RTC秒中断    
		RTC_WaitForLastTask();//等待写RTC寄存器完成	
	}
	RCC_ClearFlag();//清除复位标志；		
}


