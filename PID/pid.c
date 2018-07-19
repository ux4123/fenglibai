#include "pid.h"
	 
float PID_Control_X(float X_now,float X_To)      
{
	 static float Bias,Gyro,Angle_before,integral;
	 static float balance;
	  
	 Bias=X_To-X_now;      													  //===求出平衡的角度中值 和机械相关
	 integral+=Bias;															//积分
	if(Bias>10)
		integral = 0;
	
	 if(integral>1000)														//积分限幅
		 integral = 1000;
	 else if(integral<-1000)
		 integral = -1000;
		 
	 Gyro=Bias-Angle_before;																		//微分
	 Angle_before=Bias;
	 	 balance=(Kp_x*Bias+Gyro*Kd_x+integral*Ki_x);  
// balance=-(Kp*Bias+Gyro*Kd+integral*Ki-sin(X_now*3.1415/180)*400/sin(Angle_SI*3.1415/180));  										  //===计算平衡控制的电机PWM  PID控制   kp是P系数 kd是D系数 
	 return balance;
}

float PID_Control_Y(float X_now,float X_To)      
{
	 static float Bias,Gyro,Angle_before,integral;
	 static float balance;
	  
	 Bias=X_To-X_now;      													  //===求出平衡的角度中值 和机械相关
	 integral+=Bias;															//积分
////	if(Bias>10)
////		integral = 0;
	
	 if(integral>1000)														//积分限幅
		 integral = 10000;
	 else if(integral<-1000)
		 integral = -1000;
		 
	 Gyro=Bias-Angle_before;																		//微分
	 Angle_before=Bias;
	 balance=(Kp_y*Bias+Gyro*Kd_y+integral*Ki_y);  										  //===计算平衡控制的电机PWM  PID控制   kp是P系数 kd是D系数 
	 return balance;
}

int baidong_balance_X(float Angle,int R,int xiangwei)
{  
	 const int period=1620;     //T=1500ms 
	 static int t;
	 static float Omega,A;
	
	 if(t<2*period)t+=20.0;else t=0;
		
   Omega=6.2832*t/period;      //sin??w?
	 A=(atan(R/83.5f)*57.2958f+3.5);  //?????????
	
	 return PID_Control_X(Angle ,A*sin(Omega+xiangwei)); 	
}

int baidong_balance_Y(float Angle,int R,int xiangwei)
{  
	 const float period=1620.0;     //T=1500ms 
	 static int t;
	 static float Omega,A;
	
	 if(t<2*period)t+=20;else t=0;
		
   Omega=6.2832*t/period;      //sin??w?
	 A=(atan(R/83.5f)*57.2958f);  //?????????
	
	 return PID_Control_Y(Angle ,A*sin(Omega+xiangwei) ); 	
}



float PID_Control_Zhi_X(float X_now)      
{
	 static float Bias,Gyro,Angle_before,integral;
	 static float balance;
	  
	 Bias=0-X_now;      													  //===求出平衡的角度中值 和机械相关
	 integral+=Bias;															//积分
	
	if(myabs(Bias)>5)
		integral = 0;
	
	 if(integral>10000)														//积分限幅
		 integral = 10000;
	 else if(integral<-10000)
		 integral = -10000;
		 
	 Gyro=Bias-Angle_before;																		//微分
	 Angle_before=Bias;
//////	 
	 	if(myabs(X_now)<5)
				 balance=((18)*Bias+Gyro*(30)-integral*0.01);  										  
//////		 Bias = 0;
			else
	 balance=(22*Bias+Gyro*30+integral*Ki_x);  										  //===计算平衡控制的电机PWM  PID控制   kp是P系数 kd是D系数 
	 return balance;
}
float PID_Control_Zhi_Y(float X_now)      
{
	 static float Bias,Gyro,Angle_before,integral;
	 static float balance;
	  
	 Bias=0-X_now;      													  //===求出平衡的角度中值 和机械相关
	 integral+=Bias;															//积分
	if(myabs(Bias)>5)
		integral = 0;
	
	 if(integral>10000)														//积分限幅
		 integral = 10000;
	 else if(integral<-10000)
		 integral = -10000;
		 
	 Gyro=Bias-Angle_before;																		//微分
	 Angle_before=Bias;
	 
	 	if(myabs(X_now)<5)
		balance=((24)*Bias+Gyro*(30)-integral*0.01);  						 
		else
		balance=(24*Bias+Gyro*40+integral*Ki_y);  										  //===计算平衡控制的电机PWM  PID控制   kp是P系数 kd是D系数 
	 return balance;
}

float PID_ZhiDong_X(float X_now)      
{
	 static float Bias,Gyro,Angle_before,integral;
	 static float balance;
	  
	 Bias=X_now;      													  //===求出平衡的角度中值 和机械相关
	 integral+=Bias;															//积分
	if(myabs(Bias)>3)
		integral = 0;
	
	 if(integral>10000)														//积分限幅
		 integral = 10000;
	 else if(integral<-10000)
		 integral = -10000;
		 
	 Gyro=X_now-Angle_before;																		//微分
	 Angle_before=X_now;
	 if(myabs(Bias)>3)
		 Bias = 0;
	 balance=-(Kp_ZhiDong*Bias+Gyro*Kd_ZhiDong+integral*Ki_ZhiDong);  										  //===计算平衡控制的电机PWM  PID控制   kp是P系数 kd是D系数 
	 return balance;
}

float PID_ZhiDong_Y(float X_now)      
{
	 static float Bias,Gyro,Angle_before,integral;
	 static float balance;
	  
	 Bias=X_now;      													  //===求出平衡的角度中值 和机械相关
	 integral+=Bias;															//积分
	if(myabs(Bias)>3)
		integral = 0;
	
	 if(integral>10000)														//积分限幅
		 integral = 10000;
	 else if(integral<-10000)
		 integral = -10000;
		 
	 Gyro=X_now-Angle_before;																		//微分
	 Angle_before=X_now;
	 if(myabs(Bias)>3)
		 Bias = 0;
	 balance=-(Kp_ZhiDong*Bias+Gyro*Kd_ZhiDong+integral*Ki_ZhiDong);  										  //===计算平衡控制的电机PWM  PID控制   kp是P系数 kd是D系数 
	 return balance;
}





//////////////////////////////////////92 2980
//////////////105 2980