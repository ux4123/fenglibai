#ifndef __ADC_H
#define	__ADC_H

#include "stm32f10x.h"
#include "time.h"

// PA1 AO
#define TSL_SI    PAout(5)   //SI  PA5
#define TSL_CLK   PAout(4)   //CLK PA4

//#define CCD_Jixie_Zhong 60
//#define AD_Low 50
//#define AD_High 150

//extern u8 AD[128],AD_Low,AD_High;
//extern u8 Left,Right; 
//extern u8 Intergration_Time;
//extern u8 Yuzhi_Xia,CCD_Jixie_Zhong;
//extern u32 AD_All,AD_All_Min;

//void  Adc_Init(void);
//u16 Get_Adc(void);
//u16 Get_Adc_Average(u8 times);
//void Image_Capture(u8 * ImageData);
//void CCD_Data_Pro(u8 * ImageData);
//void Start_Integration(void);
//// void RD_TSL(void);
//void CCD_Init(void);

//u16 CCD_Zhong(void);
//u8  Find_CCD_Zhongzhi(void);

#endif
