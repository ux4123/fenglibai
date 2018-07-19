#include "lcd5110.h"
#include "delay.h"
#include "ascll.h"
/*-----------------------------------------------------------------------
LCD_init          : 3310LCD初始化

编写日期          ：2004-8-10 
最后修改日期      ：2004-8-10 
-----------------------------------------------------------------------*/

u8 Write_float_Flag;


void LCD_init(void)
  {
            // 产生一个让LCD复位的低电平脉冲
		GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
		
		GPIO_InitStructure.GPIO_Speed=GPIO_Speed_10MHz;	
		GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
		
		GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_10|GPIO_Pin_11;	
		GPIO_Init(GPIOB,&GPIO_InitStructure);
		


		
    LCD_RST = 0;
    delay_us(1);

    LCD_RST=1;
    
		// 关闭LCD
    LCD_CE = 0;
    delay_us(1);
		// 使能LCD
    LCD_CE = 1;
    delay_us(1);

    LCD_write_byte(0x21, 0);	// 使用扩展命令设置LCD模式
    LCD_write_byte(0xc8, 0);	// 设置偏置电压
    LCD_write_byte(0x06, 0);	// 温度校正
    LCD_write_byte(0x13, 0);	// 1:48
    LCD_write_byte(0x20, 0);	// 使用基本命令 （芯片活动 水平寻址 基本指令集）
    LCD_clear();	        // 清屏
    LCD_write_byte(0x0c, 0);	// 设定显示模式，正常显示
        
           // 关闭LCD
   LCD_CE = 0;
  }

	void Show_Init()
	{
		LCD_write_english_string(0,0,"Hello");
		LCD_write_english_string(0,1,"Yaw:");
		LCD_write_english_string(0,2,"Pitch:");
		LCD_write_english_string(0,3,"Roll:");
		LCD_write_english_string(0,4,"PWM:");
	}
/*-----------------------------------------------------------------------
LCD_clear         : LCD清屏函数

编写日期          ：2004-8-10 
最后修改日期      ：2004-8-10 
-----------------------------------------------------------------------*/
void LCD_clear(void)
  {
    unsigned int i;

    LCD_write_byte(0x0c, 0);			
    LCD_write_byte(0x80, 0);		//RAM地址回到0

    for (i=0; i<504; i++)
      LCD_write_byte(0, 1);			
  }

/*-----------------------------------------------------------------------
LCD_set_XY        : 设置LCD坐标函数

输入参数：X       ：0－83
          Y       ：0－5

编写日期          ：2004-8-10 
最后修改日期      ：2004-8-10 
-----------------------------------------------------------------------*/
void LCD_set_XY(unsigned char X, unsigned char Y)
  {
    LCD_write_byte(0x40 | Y, 0);		// column
    LCD_write_byte(0x80 | X, 0);          	// row
  }

/*-----------------------------------------------------------------------
LCD_write_char    : 显示英文字符

输入参数：c       ：显示的字符；

编写日期          ：2004-8-10 
最后修改日期      ：2004-8-10 
-----------------------------------------------------------------------*/
void LCD_write_char(unsigned char c)
  {
    unsigned char line;

    c -= 32;

    for (line=0; line<6; line++)
      LCD_write_byte(font6x8[c][line], 1);
  }
	
void LCD_write_char_me(unsigned char X,unsigned char Y,unsigned char c)
  {
    unsigned char line;

    c -= 32;
		LCD_set_XY(X,Y);
    for (line=0; line<6; line++)
      LCD_write_byte(font6x8[c][line], 1);
  }

/*-----------------------------------------------------------------------
LCD_write_english_String  : 英文字符串显示函数

输入参数：*s      ：英文字符串指针；
          X、Y    : 显示字符串的位置,x 0-83 ,y 0-5

编写日期          ：2004-8-10 
最后修改日期      ：2004-8-10 		
-----------------------------------------------------------------------*/
void LCD_write_english_string(unsigned char X,unsigned char Y,char *s)
  {
    LCD_set_XY(X,Y);
    while (*s) 
      {
	 LCD_write_char(*s);
	 s++;
      }
  }
/*-----------------------------------------------------------------------
LCD_write_integer(unsigned char X,unsigned char Y,int *s)

输入参数：*s      ：整型数字指针；
          X、Y    : 显示字符串的位置,x 0-83 ,y 0-5

-----------------------------------------------------------------------*/
void LCD_write_integer(unsigned char X,unsigned char Y,int *s)
  {
		char a[10]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
		int ss=*s;
		int i=0;
		if(*s<0)
		{
			ss=0xffffffff^ss+1;
		}
		while(1)
		{
			a[i]=ss%10+48;
			ss=ss/10;
			i++;
			if(ss==0)break;
		}
		
    LCD_set_XY(X,Y);
//		if(*s<0)
//			LCD_write_char(45);
//		else
//			LCD_write_char(43);
//	  LCD_set_XY(X+1,Y);
		while(i--)
		{
				LCD_write_char(a[i]);
		}
		LCD_write_byte(0, 1);	
		LCD_write_byte(0, 1);	
		LCD_write_byte(0, 1);	
		LCD_write_byte(0, 1);	
    
  }
void LCD_write_integer_zf(unsigned char X,unsigned char Y,int *s)
  {
		char a[10]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
		int ss=*s;
		int i=0;
		if(*s<0)
		{
			ss=0xffffffff^ss+1;
		}
		while(1)
		{
			a[i]=ss%10+48;
			ss=ss/10;
			i++;
			if(ss==0)break;
		}
		
    LCD_set_XY(X,Y);
		if(*s<0)
			LCD_write_char(45);
		else
			LCD_write_char(43);
	  LCD_set_XY(X+1,Y);
		while(i--)
		{
				LCD_write_char(a[i]);
		}
		LCD_write_byte(0, 1);	
		LCD_write_byte(0, 1);	
		LCD_write_byte(0, 1);	
		LCD_write_byte(0, 1);	
    
  }


/*-----------------------------------------------------------------------
LCD_write_byte    : 使用SPI接口写数据到LCD

输入参数：data    ：写入的数据；
          command ：写数据/命令选择；

编写日期          ：2004-8-10 
最后修改日期      ：2004-8-13 
-----------------------------------------------------------------------*/
void LCD_write_byte(unsigned char dat, unsigned char command)
  {
    unsigned char i;
    LCD_CE = 0;
    
    if (command == 0)
     LCD_DC = 0;
    else
			LCD_DC = 1;
		for(i=0;i<8;i++)
		{
			if(dat&0x80)
				SDIN = 1;
			else
				SDIN = 0;
			SCLK = 0;
			dat = dat << 1;
			SCLK = 1;
		}
     LCD_CE = 1;
  }

void LCD_Write_float_Zi(unsigned char X,unsigned char Y,u8 t,u16 value)
{
	int S;
	if(t>3)
		S=value/pow(10,t);
	else
		S=(value%(u16)pow(10,t+1))/pow(10,t);
	if((Write_float_Flag!=0)&&(S==0))
		{
			LCD_write_char_me(X,Y,' ');
		}
		else 
		{
			LCD_write_integer(X,Y,&S);
			Write_float_Flag=0;
		}
}
void LCD_Write_Angle(unsigned char X,unsigned char Y,u16 value)
{
	int S;
	Write_float_Flag=1;
	
//	value=y*100;
	LCD_Write_float_Zi(X,Y,4,value);
	LCD_Write_float_Zi(X+6,Y,3,value);
	S=(value%1000)/100;
	LCD_write_integer(X+12,Y,&S);
	LCD_write_char_me(X+18,Y,'.');
	S=(value%100)/10;
	LCD_write_integer(X+24,Y,&S);
	S=value%10;
	LCD_write_integer(X+30,Y,&S);

//	Write_float_Flag=0;
}
void LCD_Write_2wei(unsigned char X,unsigned char Y,int s)
{
	if(s>9)
		LCD_write_integer(X,Y,&s);
	else
	{
		LCD_set_XY(X,Y);
		LCD_write_char(32);
		LCD_write_integer(X+6,Y,&s);
	}
}

void LCD_Write_Clock(unsigned char X,unsigned char Y,int Hour,int Min,int Sec)
{
	LCD_Write_2wei(X,Y,Hour);
	LCD_write_char_me(X+12,Y,':');
	LCD_Write_2wei(X+18,Y,Min);
	LCD_write_char_me(X+30,Y,':');
	LCD_Write_2wei(X+36,Y,Sec);
}
	

