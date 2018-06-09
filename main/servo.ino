#include <VarSpeedServo.h>

VarSpeedServo servo_0, servo_1;

void servo_reset(){
  servo_1.write(0);
  servo_0.write(0);
}

void servo_stay(int pos, int milliseconds) {
  servo_1.write(pos);
  servo_0.write(pos);
  delay(milliseconds);
}

void servo_full_movement(){
  servo_1.write(0);
  servo_0.write(0);
  delay(1000);
  servo_1.write(70);
  servo_0.write(70);
  delay(1000);
}

void servo_joy() {
  servo_1.slowmove(30,70);
  delay(100);
  servo_0.slowmove(50,70);
  delay(300);
  servo_1.slowmove(70,70);
  delay(100);
  servo_0.slowmove(90,70);
  delay(300);
}

void servo_sadness(){
  servo_1.slowmove(80,15);
  servo_0.slowmove(120,23);
  delay(3000);
  servo_1.slowmove(0,15);
  servo_0.slowmove(0,23);
  delay(4000);
}

void servo_anger(){
  servo_1.write(0);
  servo_0.write(0);
  delay(100);
  servo_1.write(30);
  servo_0.write(50);
  delay(250);
}


