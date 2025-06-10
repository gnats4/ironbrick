#include<ironbrick.h>
#define LSens 8
#define MSens A2 
#define RSens 9
#define ir 10
#define DS1 A3
#define DS2 A4
#define DS3 A5
int LastValue = 3;
bool tactic = false;


void setup() {

  pinMode(LSens,INPUT_PULLUP);
  pinMode(MSens, INPUT_PULLUP);
  pinMode(RSens, INPUT_PULLUP);

  pinMode(ir, INPUT);

  pinMode(DS1, INPUT_PULLUP);
  pinMode(DS2, INPUT_PULLUP);
  pinMode(DS3, INPUT_PULLUP);
    
  Serial.begin(9600);

}

void loop() {
//-------------------------------------------------DEBUG--------------------------------------------------------------------
  int LSensVal=digitalRead(LSens);
  int MSensVal=digitalRead(MSens);
  int RSensVal=digitalRead(RSens);

  Serial.print("Left Sensor Value : ");
  Serial.println(LSensVal);
  Serial.print("Middle Sensor Value : ");
  Serial.println(MSensVal);
  Serial.print("Right Sensor Value : ");
  Serial.println(RSensVal);
  //delay(1000);
//-----------------------------------------------END DEBUG-----------------------------------------------------------------------

  while(digitalRead(ir) == 1){
    if(!tactic){
      handleTactics();
      tactic = true;
    }
     if(digitalRead(MSens) == HIGH){
      ironbrick.Forward(100,1);
      LastValue=0;
      lastMoveTime = millis();
    }
    else if(digitalRead(LSens) == HIGH) {
        ironbrick.Left(80, 1);
        LastValue=1;
        lastMoveTime = millis();
     } 
    else  if(digitalRead(RSens) == HIGH) { 
        ironbrick.Right(80, 1);
        LastValue=2;
        lastMoveTime = millis();
     }
    else if (LastValue == 0) {
      ironbrick.Forward(79, 1);
      lastMoveTime = millis();
    }
    else if(LastValue == 1) {
      ironbrick.Left(79, 1);
      lastMoveTime = millis();
    }
    else if(LastValue == 2){
      ironbrick.Right(79, 1);
      lastMoveTime = millis();
    }
  }
  ironbrick.StopMotors(10);
}

void handleTactics(){
  if(digitalRead(DS1) == 0 && digitalRead(DS2) == 1 && digitalRead(DS3) == 0){  //Go Forward
    ironbrick.Forward(230, 80);
    ironbrick.Backward(100, 10);
    ironbrick.StopMotors(1);
  }
  else if (digitalRead(DS1) == 1 && digitalRead(DS2) == 0 && digitalRead(DS3) == 0 ) { //Left Zig-Zag
    ironbrick.Right(80,40);
    ironbrick.StopMotors(20);
    ironbrick.Forward(100, 90);
    ironbrick.StopMotors(20);
    ironbrick.Left(100,110);
    ironbrick.Forward(100, 70);
    ironbrick.StopMotors(10);
  }
  else if (digitalRead(DS1) == 0 && digitalRead(DS2) == 0 && digitalRead(DS3) == 1 ) { //Right Zig-Zag

    ironbrick.Left(100, 40);
    ironbrick.StopMotors(20);
    ironbrick.Forward(100, 90);
    ironbrick.StopMotors(20);
    ironbrick.Right(100, 130);
    ironbrick.Forward(100, 70);
    ironbrick.StopMotors(10);
  }
  else if (digitalRead(DS1) == 1 && digitalRead(DS2) == 1 && digitalRead(DS3) == 1 ) { //Right Arc 
    ironbrick.ArcTurn(50, 100, 150);
    ironbrick.Backward(100,1);
    ironbrick.Left(60, 80);
    ironbrick.StopMotors(2);
  }
  else if (digitalRead(DS1) == 0 && digitalRead(DS2) == 0 && digitalRead(DS3) == 0 ) { //Left Arc
    ironbrick.ArcTurn(100,50,150);
    ironbrick.Backward(100, 2);
    ironbrick.Right(60, 60);
    ironbrick.StopMotors(2);
  }
  else if(digitalRead(DS1) == 0 && digitalRead(DS2) == 1 && digitalRead(DS3) == 1){ //Forward-Wait 3s-LeftArc
    ironbrick.Forward(230, 50);
    ironbrick.Backward(100, 10);
    ironbrick.StopMotors(1);

    unsigned long time = millis();
    while (millis() - time < 3000){
      if(digitalRead(LSens) == HIGH || digitalRead(MSens) == HIGH || digitalRead(RSens) == HIGH){
        return;
      }
    }
    ironbrick.ArcTurn(100,50,150);
    ironbrick.Backward(100, 2);
    ironbrick.Right(60, 60);
    ironbrick.Backward(100, 10);
    ironbrick.StopMotors(1);
  }
  else if(digitalRead(DS1)==1 && digitalRead(DS2)==1 && digitalRead(DS3)==0){//Forward-Wait 3s-RightArc
    ironbrick.Forward(230,50);
    ironbrick.Backward(100, 10);
    ironbrick.StopMotors(1);

    unsigned long time = millis();
    while (millis() - time < 3000){
      if(digitalRead(LSens) == HIGH || digitalRead(MSens) == HIGH || digitalRead(RSens) == HIGH){
        return;
      } 
    }
    ironbrick.ArcTurn(50, 100, 150);
    ironbrick.Backward(100,1);
    ironbrick.Left(60, 80);
    ironbrick.Backward(100,10);
    ironbrick.StopMotors(1);
  }
  else if(digitalRead(DS1)==1 && digitalRead(DS2)==0 && digitalRead(DS3)==1){ //Backward
    ironbrick.Backward(100, 100);
    ironbrick.Forward(100,10);
    ironbrick.StopMotors(1);
  }

}