#include "myServo.h"
#include "Motor.h"
#include "led.h"
#include "sonar.h"
#include "controller.h"

MyServo* servo1 = new MyServo();
MyServo* servo2 = new MyServo();
MyServo* servo3 = new MyServo();
Motor* motor1 = new Motor();
Motor* motor2 = new Motor();
Led* led = new Led();
Sonar* sonar = new Sonar();

MyServo * servoPtrs[3] = {servo1, servo2, servo3};
Motor* motorPtrs[2] = {motor1, motor2};

Controller controller(servoPtrs, motorPtrs, led, sonar);

void setup(){
  attachInterrupt(digitalPinToInterrupt(21), changeEmotion, RISING);
  servo1->Attach(6);
  servo2->Attach(7);
  servo3->Attach(8);
  motor1->setup(24, 22, 11);
  motor2->setup(23, 25, 12);
  led->configure(2,3,5);
  //sonar->setup(9,10);
  Serial.begin(9600);
}

void loop(){
  controller.updateEmotion(millis());
}

int emotion = 0;
long lastDebounceTime = 0; 
long debounceDelay = 500; 

void changeEmotion(){
  if ((millis() - lastDebounceTime) > debounceDelay){
    Serial.println("BUTTON PRESSED ");
    Serial.println("               ");
    lastDebounceTime = millis();
	  controller.changeEmotion();
  }
}
