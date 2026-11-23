#include <ironbrick_v2.h>
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  ironbrick_v2.Forward(100, 1000);
  ironbrick_v2.StopMotors(100);
  ironbrick_v2.Backward(100, 1900);
  ironbrick_v2.StopMotors(100);
  ironbrick_v2.Right(70, 1000);
  ironbrick_v2.StopMotors(100);
  ironbrick_v2.Left(70, 1000);
  ironbrick_v2.StopMotors(100);
  ironbrick_v2.MotorControl(60, 80, 1000);
  ironbrick_v2.ArcTurn(30, 80, 1000);
}
