#ifndef __OLED_I2C_H
#define	__OLED_I2C_H

#include "stm32f10x.h"

#define OLED_ADDRESS	0x78 //通过调整0R电阻,屏可以0x78和0x7A两个地址 -- 默认0x78

//extern float pitch,roll,yaw;
extern u8 Key_Mode ,Display_Flag,Debug_Value;

void I2C_Configuration(void);
void I2C_WriteByte(uint8_t addr,uint8_t data);
void WriteCmd(unsigned char I2C_Command);
void WriteDat(unsigned char I2C_Data);
void OLED_Init(void);
void OLED_SetPos(unsigned char x, unsigned char y);
void OLED_Fill(unsigned char fill_Data);
void OLED_CLS(void);
void OLED_ON(void);
void OLED_OFF(void);
void OLED_ShowStr(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize);
void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N);
void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]);
void convert_to(int a,u8 *p);
void myOLED_ShowStr(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize);
void disnum(unsigned char x, unsigned char y, unsigned char ch[],unsigned char i);
void oled_write_num(u8 x,u8 y,long num,u8 mode,u8 wei);
void Show_Init(void);
#endif
