#include "adc.h"

//u8 CCD_Yuzhi;


//void  Adc_Init(void)
//{ 	
//	ADC_InitTypeDef ADC_InitStructure; 
//	GPIO_InitTypeDef GPIO_InitStructure;

//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_ADC1	, ENABLE );	  //ʹ��ADC1ͨ��ʱ��
// 

//	RCC_ADCCLKConfig(RCC_PCLK2_Div6);   //����ADC��Ƶ����6 72M/6=12,ADC���ʱ�䲻�ܳ���14M

//	//PA1 ��Ϊģ��ͨ����������                         
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//ģ����������
//	GPIO_Init(GPIOA, &GPIO_InitStructure);	

//	ADC_DeInit(ADC1);  //��λADC1,������ ADC1 ��ȫ���Ĵ�������Ϊȱʡֵ

//	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	//ADC����ģʽ:ADC1��ADC2�����ڶ���ģʽ
//	ADC_InitStructure.ADC_ScanConvMode = DISABLE;	//ģ��ת�������ڵ�ͨ��ģʽ
//	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;	//ģ��ת�������ڵ���ת��ģʽ
//	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//ת��������������ⲿ��������
//	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	//ADC�����Ҷ���
//	ADC_InitStructure.ADC_NbrOfChannel = 1;	//˳����й���ת����ADCͨ������Ŀ
//	ADC_Init(ADC1, &ADC_InitStructure);	//����ADC_InitStruct��ָ���Ĳ�����ʼ������ADCx�ļĴ���   

//  ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_239Cycles5 );	//ADC1,ADCͨ��,����ʱ��Ϊ239.5����	
//	ADC_Cmd(ADC1, ENABLE);	//ʹ��ָ����ADC1
//	
//	//У׼
//	ADC_ResetCalibration(ADC1);	//ʹ�ܸ�λУ׼  
//	while(ADC_GetResetCalibrationStatus(ADC1));	//�ȴ���λУ׼����
//	ADC_StartCalibration(ADC1);	 //����ADУ׼
//  while(ADC_GetCalibrationStatus(ADC1));	 //�ȴ�У׼����
// 
////	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//ʹ��ָ����ADC1�����ת����������

//}		

//u16 Get_Adc()   
//{
//  	//����ָ��ADC�Ĺ�����ͨ����һ�����У�����ʱ��
////	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5 );	//ADC1,ADCͨ��,����ʱ��Ϊ239.5����	  			    
//  
//	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//ʹ��ָ����ADC1�����ת����������	
//	 
//	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//�ȴ�ת������

//	return ADC_GetConversionValue(ADC1);	// ��ȡת����� �������һ��ADC1�������ת�����
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
//    Dly_us();  //�����ع�ʱ��
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

//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_ADC1	, ENABLE );	  //ʹ��ADC1ͨ��ʱ��
//                    
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5;
//	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;

//	GPIO_Init(GPIOA, &GPIO_InitStructure);	

//}


////���̱���ɨ��
//u8  Find_CCD_Zhongzhi(void)
//{ 
//	 static u8 i,j,Last_CCD_Zhongzhi=64;
//	 static u16 value1_max,value1_min;
//	 u16 CCD_Zhongzhi;
//	
//	   value1_max=AD[0];  //��̬��ֵ�㷨����ȡ������Сֵ
//     for(i=5;i<123;i++)   //���߸�ȥ��5����
//     {
//        if(value1_max<=AD[i])
//        value1_max=AD[i];
//     }
//	   value1_min=AD[0];  //��Сֵ
//     for(i=5;i<123;i++) 
//     {
//        if(value1_min>=AD[i])
//        value1_min=AD[i];
//     }
////    CCD_Yuzhi=(value1_max+value1_min)/2;	  //���������������ȡ����ֵ
//		CCD_Yuzhi=(value1_max+value1_min)*5/10;	  //���������������ȡ����ֵ
//		 
////		if(CCD_Yuzhi>(Yuzhi_Xia+50)&&Intergration_Time>1)		//�ع�ʱ�����
////			Intergration_Time-=1;
////		else if(CCD_Yuzhi<Yuzhi_Xia&&Intergration_Time<20)
////			Intergration_Time+=1;
//		
//		for(i = 5;i<123; i++)   //Ѱ�����������
//		{
//			if(AD[i]>CCD_Yuzhi&&AD[i-1]>CCD_Yuzhi&&AD[i-2]>CCD_Yuzhi&&AD[i+1]<CCD_Yuzhi&&AD[i+2]<CCD_Yuzhi&&AD[i+3]<CCD_Yuzhi)
//			{	
//				Left=i;
//				break;	
//			}
//		}
//	 for(j = 123;j>5; j--)//Ѱ���ұ�������
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
//	CCD_Zhongzhi=(Right+Left)/2;//��������λ��

//	if(AD_All<AD_All_Min*128)
//		CCD_Zhongzhi = CCD_Jixie_Zhong;
//	if(myabs(CCD_Zhongzhi-Last_CCD_Zhongzhi)>80)   //�������ߵ�ƫ����̫��
//		CCD_Zhongzhi=Last_CCD_Zhongzhi;    //��ȡ��һ�ε�ֵ
//	Last_CCD_Zhongzhi=CCD_Zhongzhi;  //������һ�ε�ƫ��
//	
//	return CCD_Zhongzhi;
//}	
