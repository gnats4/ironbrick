#include "Arduino.h"
#include "ironbrick.h"

#define R_IN1 6
#define R_IN2 7
#define L_IN1 5
#define L_IN2 4
#define R_PWM 11
#define L_PWM 3


String IronbrickString; 


IronbrickClass::IronbrickClass(){
	pinMode(R_IN1, OUTPUT);
	pinMode(R_IN2, OUTPUT);
	pinMode(L_IN1, OUTPUT);
	pinMode(L_IN2, OUTPUT);
	pinMode(R_PWM, OUTPUT);
	pinMode(L_PWM, OUTPUT);
}

void IronbrickClass::SETUP(){

}


void IronbrickClass::Forward(byte speed, int Time){
   
   speed = constrain(speed,0,100);
   speed = map(speed,0,100,0,255);
   digitalWrite(L_IN1,HIGH);
   digitalWrite(L_IN2,LOW);
   digitalWrite(R_IN1,HIGH);
   digitalWrite(R_IN2,LOW);
   analogWrite(R_PWM, speed);
   analogWrite(L_PWM, speed);
   delay(Time);
   
}
 
void IronbrickClass::Backward(byte speed, int Time){
   
   speed = constrain(speed,0,100);
   speed = map(speed,0,100,0,255);
   digitalWrite(L_IN1,LOW);
   digitalWrite(L_IN2,HIGH);
   digitalWrite(R_IN1,LOW);
   digitalWrite(R_IN2,HIGH);
   analogWrite(L_PWM, speed);
   analogWrite(R_PWM, speed);
   delay(Time);
   
}

void IronbrickClass::Right(byte speed, int Time){
   
   speed = constrain(speed,0,100);
   speed = map(speed,0,100,0,255);
   digitalWrite(R_IN1,LOW);
   digitalWrite(R_IN2,HIGH);
   digitalWrite(L_IN1,HIGH);
   digitalWrite(L_IN2,LOW);
   analogWrite(R_PWM, speed);
   analogWrite(L_PWM, speed);
   delay(Time);
   
}

void IronbrickClass::Left(byte speed, int Time){
   
   speed = constrain(speed,0,100);
   speed = map(speed,0,100,0,255);
   digitalWrite(R_IN1,HIGH);
   digitalWrite(R_IN2,LOW);
   digitalWrite(L_IN1,LOW);
   digitalWrite(L_IN2,HIGH);
   analogWrite(R_PWM, speed);
   analogWrite(L_PWM, speed);
   delay(Time);
   
}

void IronbrickClass::ArcTurn(byte LeftSpeed, byte RightSpeed, int Time){
	
	LeftSpeed = constrain(LeftSpeed,0,100);
	LeftSpeed = map(LeftSpeed,0,100,0,255);
	RightSpeed = constrain(RightSpeed,0,100);
	RightSpeed = map(RightSpeed,0,100,0,255);
	digitalWrite(R_IN1,HIGH);
	digitalWrite(R_IN2,LOW);
	digitalWrite(L_IN1,HIGH);
	digitalWrite(L_IN2,LOW);
    	analogWrite(R_PWM, RightSpeed);
    	analogWrite(L_PWM, LeftSpeed);
    	delay(Time);
	
}

void IronbrickClass::MotorControl(float LeftMotorPower, float RightMotorPower, int Time) {
  int RightMotorPwm = abs(RightMotorPower * 2.55);
  int LeftMotorPwm = abs(LeftMotorPower * 2.55);

  if (RightMotorPower > 0) {
    digitalWrite(R_IN1, HIGH);
    digitalWrite(R_IN2, LOW);
    analogWrite(R_PWM, RightMotorPwm);
  } 
  else if (RightMotorPower < 0) {
    digitalWrite(R_IN1, LOW);
    digitalWrite(R_IN2, HIGH);
    analogWrite(R_PWM, RightMotorPwm);
  } 
  else {
    digitalWrite(R_IN1, HIGH);
    digitalWrite(R_IN2, HIGH);
    analogWrite(R_PWM, 0);
  }

  if (LeftMotorPower > 0) {
    digitalWrite(L_IN1, HIGH);
    digitalWrite(L_IN2, LOW);
    analogWrite(L_PWM, LeftMotorPwm);
  } 
  else if (LeftMotorPower < 0) {
    digitalWrite(L_IN1, LOW);
    digitalWrite(L_IN2, HIGH);
    analogWrite(L_PWM, LeftMotorPwm);
  } 
  else {
    digitalWrite(L_IN1, HIGH);
    digitalWrite(L_IN2, HIGH);
    analogWrite(L_PWM, 0);
  }

  delay(Time);
}



void IronbrickClass::StopMotors(int Time) {
    digitalWrite(R_IN1, LOW); 
    digitalWrite(R_IN2, LOW);
    digitalWrite(L_IN1, LOW); 
    digitalWrite(L_IN2, LOW); 
    analogWrite(R_PWM, 0);     
    analogWrite(L_PWM, 0);    
    delay(Time);              
}

IronbrickClass ironbrick = IronbrickClass();
