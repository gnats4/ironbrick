#ifndef IRONBRICK_V2_H 
#define IRONBRICK_V2_H	
		

#include <Arduino.h>

class IronbrickClass{ 
	public: 
		IronbrickClass(); 
		void SETUP(); 
		void Forward(byte speed, int time);
		void Backward(byte speed, int time);
		void Right(byte speed, int time);
		void Left(byte speed, int time);
                void StopMotors(int time);
		void ArcTurn(byte LeftSpeed, byte RightSpeed, int Time);
                void MotorControl(float LeftSpeed, float RightSpeed, int Time);
};



extern IronbrickClass ironbrick_v2; 
#endif
