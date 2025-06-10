#include <ironbrick.h>
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  ironbrick.Forward(100, 1000);
  ironbrick.StopMotors(100);
  ironbrick.Backward(100, 1900);
  ironbrick.StopMotors(100);
  ironbrick.Right(70, 1000);
  ironbrick.StopMotors(100);
  ironbrick.Left(70, 1000);
  ironbrick.StopMotors(100);
  ironbrick.MotorControl(60, 80, 1000);
  ironbrick.ArcTurn(30, 80, 1000);
}
