#include <VarSpeedServo.h>

VarSpeedServo myServo, myServo1;

void setup() {
  myServo1.attach(6);
  myServo.attach(9); // attaches the servo on pin 9 to the servo object
  myServo1.write(0);
  myServo.write(0);
}

void servo_reset(){
  myServo1.write(0);
  myServo.write(0);
}

void servo_stay(int pos, int milliseconds) {
  myServo1.write(pos);
  myServo.write(pos);
  delay(milliseconds);
}

void servo_full_movement(){
  myServo1.write(0);
  myServo.write(0);
  delay(1000);
  myServo1.write(70);
  myServo.write(70);
  delay(1000);
}

void servo_joy() {
  myServo1.slowmove(30,70);
  delay(100);
  myServo.slowmove(30,70);
  delay(300);
  myServo1.slowmove(70,70);
  delay(100);
  myServo.slowmove(70,70);
  delay(300);
}

void servo_sadness(){
  myServo1.slowmove(80,15);
  myServo.slowmove(120,23);
  delay(3000);
  myServo1.slowmove(0,15);
  myServo.slowmove(0,23);
  delay(4000);
}

void servo_anger(){
  myServo1.write(0);
  myServo.write(0);
  delay(100);
  myServo1.write(30);
  myServo.write(30);
  delay(250);
}


