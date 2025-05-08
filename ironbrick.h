#ifndef ironbrick_h 
#define ironbrick_h	
		

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
                void MotorControl(int LeftSpeed, int RightSpeed);
};



extern IronbrickClass ironbrick; 
#endif
