#include "ironbrick_v2.h"
#include "Arduino.h>

namespace {
constexpr byte leftIn1 = 3, leftIn2 = 5;
constexpr byte rightIn1 = 6, rightIn2 = 11;

void drive(byte in1, byte in2, float percent) {
    percent = constrain(percent, -100.0f, 100.0f);
    const byte active = percent < 0 ? in2 : in1;
    const byte inactive = percent < 0 ? in1 : in2;
    const float magnitude = percent < 0 ? -percent : percent;
    digitalWrite(inactive, LOW);
    analogWrite(active, static_cast<int>(magnitude * 255 / 100));
}
}

IronbrickClass ironbrick_v2;

IronbrickClass::IronbrickClass() {
    SETUP();
}

void IronbrickClass::SETUP() {
    pinMode(leftIn1, OUTPUT);
    pinMode(leftIn2, OUTPUT);
    pinMode(rightIn1, OUTPUT);
    pinMode(rightIn2, OUTPUT);
    StopMotors(0);
}

void IronbrickClass::MotorControl(float left, float right, int time) {
    drive(leftIn1, leftIn2, left);
    drive(rightIn1, rightIn2, right);
    if (time > 0) delay(time);
}

void IronbrickClass::Forward(byte speed, int time) {
    MotorControl(speed, speed, time);
}

void IronbrickClass::Backward(byte speed, int time) {
    MotorControl(-speed, -speed, time);
}

void IronbrickClass::Left(byte speed, int time) {
    MotorControl(-speed, speed, time);
}

void IronbrickClass::Right(byte speed, int time) {
    MotorControl(speed, -speed, time);
}

void IronbrickClass::ArcTurn(byte left, byte right, int time) {
    MotorControl(left, right, time);
}

void IronbrickClass::StopMotors(int time) {
    MotorControl(0, 0, time);
}
