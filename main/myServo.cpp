#include "myServo.h"


MyServo::MyServo(){}

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

