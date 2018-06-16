#include "myServo.h"


MyServo::MyServo(){
}

//closed position is set to 120
//open position is set to 10
//speed range is from 0 (min) to 255 (max)
void MyServo::move(int pos, int speed){
  if (isInverse){
    pos = inverse(pos);
  }
  //Serial.println("moving to " + pos + " at speed " + speed);
  servo.slowmove(pos, speed);
}

void MyServo::reset(){
  move(120, 255);
}

int MyServo::inverse(int pos){
  int new_pos = pos -125;
  if (new_pos < 0){
    new_pos = (new_pos * (-1)) + 20;
  }
  return new_pos;
}

void MyServo::Attach(int pin)
  {
    servo.attach(pin);
    if(pin == 8){
      isInverse = 1;
    } else {
      isInverse = 0;
    }
  }
  
void MyServo::Detach()
  {
    servo.detach();
  }

// void servo_joy() {
//   int velocity = 50;
//   servo_2.slowmove(20,velocity);
//   servo_1.slowmove(20,velocity);
//   servo_0.slowmove(inverse(20),velocity);
//   delay(500);
//   servo_2.slowmove(80,velocity);
//   servo_1.slowmove(80,velocity);
//   servo_0.slowmove(inverse(80),velocity);
//   delay(500);
// }

// void servo_sadness(){
//   servo_2.slowmove(10,45);
//   servo_1.slowmove(10,45);
//   servo_0.slowmove(inverse(10),45);
//   delay(3000);
//   servo_2.slowmove(120,45);
//   servo_1.slowmove(120,45);
//   servo_0.slowmove(inverse(120),45);
// }

// void servo_anger(){
//   servo_2.write(115);
//   servo_1.write(115);
//   servo_0.write(inverse(115));
//   delay(100);
//   servo_2.write(90);
//   servo_1.write(90);
//   servo_0.write(inverse(90));
//   delay(250);
// }

