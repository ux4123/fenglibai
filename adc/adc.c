#include "adc.h"

//u8 CCD_Yuzhi;


//void  Adc_Init(void)
//{ 	
//	ADC_InitTypeDef ADC_InitStructure; 
//	GPIO_InitTypeDef GPIO_InitStructure;

//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_ADC1	, ENABLE );	  //使能ADC1通道时钟
// 

//	RCC_ADCCLKConfig(RCC_PCLK2_Div6);   //设置ADC分频因子6 72M/6=12,ADC最大时间不能超过14M

//	//PA1 作为模拟通道输入引脚                         
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//模拟输入引脚
//	GPIO_Init(GPIOA, &GPIO_InitStructure);	

//	ADC_DeInit(ADC1);  //复位ADC1,将外设 ADC1 的全部寄存器重设为缺省值

//	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	//ADC工作模式:ADC1和ADC2工作在独立模式
//	ADC_InitStructure.ADC_ScanConvMode = DISABLE;	//模数转换工作在单通道模式
//	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;	//模数转换工作在单次转换模式
//	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//转换由软件而不是外部触发启动
//	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	//ADC数据右对齐
//	ADC_InitStructure.ADC_NbrOfChannel = 1;	//顺序进行规则转换的ADC通道的数目
//	ADC_Init(ADC1, &ADC_InitStructure);	//根据ADC_InitStruct中指定的参数初始化外设ADCx的寄存器   

//  ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_239Cycles5 );	//ADC1,ADC通道,采样时间为239.5周期	
//	ADC_Cmd(ADC1, ENABLE);	//使能指定的ADC1
//	
//	//校准
//	ADC_ResetCalibration(ADC1);	//使能复位校准  
//	while(ADC_GetResetCalibrationStatus(ADC1));	//等待复位校准结束
//	ADC_StartCalibration(ADC1);	 //开启AD校准
//  while(ADC_GetCalibrationStatus(ADC1));	 //等待校准结束
// 
////	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//使能指定的ADC1的软件转换启动功能

//}		

//u16 Get_Adc()   
//{
//  	//设置指定ADC的规则组通道，一个序列，采样时间
////	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5 );	//ADC1,ADC通道,采样时间为239.5周期	  			    
//  
//	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//使能指定的ADC1的软件转换启动功能	
//	 
//	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//等待转换结束

//	return ADC_GetConversionValue(ADC1);	// 读取转换结果 返回最近一次ADC1规则组的转换结果
//}

//u16 Get_Adc_Average(u8 times)
//{
//	u32 temp_val=0;
//	u8 t;
//	for(t=0;t<times;t++)
//	{
//		temp_val+=Get_Adc();
////		delay_ms(5);
//	}
//	return temp_val/times;
//} 	

//void Dly_us(void)
//{
//   int ii;    
//   for(ii=0;ii<10;ii++);      
//}

//void Start_Integration(void) 
//{
//		unsigned char i;

//		TSL_SI = 1;        
//		Dly_us();           
//		TSL_CLK = 1;        
//		Dly_us();
//		TSL_SI = 0;         
//		Dly_us();
//		TSL_CLK = 0;        
//		for(i=0; i<127; i++) 
//		{

//			 Dly_us();
//			 TSL_CLK = 1;   
//			 Dly_us();
//			 TSL_CLK = 0;    
//	 }
//		 Dly_us();
//		 TSL_CLK = 1;   
//		 Dly_us();
//		 TSL_CLK = 0;  
//		
//}

//void Image_Capture(u8 * ImageData) 
//{
//    unsigned char i;
//    u16  temp_int;

//    TSL_SI = 1;         //SI  = 1 
//    Dly_us();
//    TSL_CLK = 1;        // CLK = 1 
//    Dly_us();
//    TSL_SI = 0;         // SI  = 0 
//    Dly_us();
//	  for(i = 0; i < 200; i++)    
//    {                
//        Dly_us();                     
//    }
//    temp_int = (Get_Adc_Average(5)>>4)*5; 
//				if(temp_int>255)			
//					*ImageData =255; 
//				else	
//					*ImageData =temp_int;  
//		ImageData++;	
//   
//    TSL_CLK = 0;        // CLK = 0 

//    for(i=0; i<127; i++) 
//    {
//        Dly_us();
//        TSL_CLK = 1;    //CLK = 1 
//        Dly_us();
////			TSL_CLK = 0;    // CLK = 0 
//        temp_int = (Get_Adc_Average(5)>>4)*5; 
//				if(temp_int>255)			
//					*ImageData =255; 
//				else	
//					*ImageData =temp_int;
//				ImageData++;			
//        TSL_CLK = 0;    // CLK = 0 

//    }

//    Dly_us();
//    TSL_CLK = 1;        // CLK = 1  
//    Dly_us();
//    TSL_CLK = 0;        // CLK = 0
//}

//void CCD_Data_Pro(u8 * ad)
//{
//	u8 i;
//	
//	AD_All = 0;
//	for(i=0; i<127; i++) 
//	{
//		if(ad[i] > AD_High)
//			ad[i] = AD_High;
//		else if(ad[i] < AD_Low)
//			ad[i] = AD_Low;
//		AD_All += ad[i];
//	}
//}
// void RD_TSL(void) 
//{
// u8 i=0,tslp=0;
//  TSL_CLK=1;
//  TSL_SI=0; 
//  Dly_us();
//      
//  TSL_SI=1; 
//  TSL_CLK=0;
//  Dly_us();
//      
//  TSL_CLK=1;
//  TSL_SI=0;
//  Dly_us(); 
//  for(i=0;i<128;i++)
//  { 
//    TSL_CLK=0; 
//    Dly_us();  //调节曝光时间
//    AD[tslp]=Get_Adc_Average(3)>>4;
//    ++tslp;
//    TSL_CLK=1;
//     Dly_us();
////		Usart_SendByte(USART1,AD[tslp-1]);
//		
//  }  
//}

//void CCD_Init()
//{
//	GPIO_InitTypeDef GPIO_InitStructure;

//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_ADC1	, ENABLE );	  //使能ADC1通道时钟
//                    
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5;
//	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;

//	GPIO_Init(GPIOA, &GPIO_InitStructure);	

//}


////例程边沿扫描
//u8  Find_CCD_Zhongzhi(void)
//{ 
//	 static u8 i,j,Last_CCD_Zhongzhi=64;
//	 static u16 value1_max,value1_min;
//	 u16 CCD_Zhongzhi;
//	
//	   value1_max=AD[0];  //动态阈值算法，读取最大和最小值
//     for(i=5;i<123;i++)   //两边各去掉5个点
//     {
//        if(value1_max<=AD[i])
//        value1_max=AD[i];
//     }
//	   value1_min=AD[0];  //最小值
//     for(i=5;i<123;i++) 
//     {
//        if(value1_min>=AD[i])
//        value1_min=AD[i];
//     }
////    CCD_Yuzhi=(value1_max+value1_min)/2;	  //计算出本次中线提取的阈值
//		CCD_Yuzhi=(value1_max+value1_min)*5/10;	  //计算出本次中线提取的阈值
//		 
////		if(CCD_Yuzhi>(Yuzhi_Xia+50)&&Intergration_Time>1)		//曝光时间调节
////			Intergration_Time-=1;
////		else if(CCD_Yuzhi<Yuzhi_Xia&&Intergration_Time<20)
////			Intergration_Time+=1;
//		
//		for(i = 5;i<123; i++)   //寻找左边跳变沿
//		{
//			if(AD[i]>CCD_Yuzhi&&AD[i-1]>CCD_Yuzhi&&AD[i-2]>CCD_Yuzhi&&AD[i+1]<CCD_Yuzhi&&AD[i+2]<CCD_Yuzhi&&AD[i+3]<CCD_Yuzhi)
//			{	
//				Left=i;
//				break;	
//			}
//		}
//	 for(j = 123;j>5; j--)//寻找右边跳变沿
//		{
//			if(AD[j]<CCD_Yuzhi&&AD[j-1]<CCD_Yuzhi&&AD[j-2]<CCD_Yuzhi&&AD[j+1]>CCD_Yuzhi&&AD[j+2]>CCD_Yuzhi&&AD[j+3]>CCD_Yuzhi)
//			{	
//				Right=j;
//				break;	
//			}	
//		}
//	if(Right==0|Left==0)
//		CCD_Zhongzhi=Right+Left;
//	else if(myabs(Right-Left)>40)
//		CCD_Zhongzhi=CCD_Jixie_Zhong;
//	else
//	CCD_Zhongzhi=(Right+Left)/2;//计算中线位置

//	if(AD_All<AD_All_Min*128)
//		CCD_Zhongzhi = CCD_Jixie_Zhong;
//	if(myabs(CCD_Zhongzhi-Last_CCD_Zhongzhi)>80)   //计算中线的偏差，如果太大
//		CCD_Zhongzhi=Last_CCD_Zhongzhi;    //则取上一次的值
//	Last_CCD_Zhongzhi=CCD_Zhongzhi;  //保存上一次的偏差
//	
//	return CCD_Zhongzhi;
//}	
