#include "disgust.h"
#include <Arduino.h>

Disgust::Disgust(MyServo * (&servoPtr)[3], Motor* (&motorPtr)[2], Led * &led, unsigned long start){

	Serial.println("enter Disgust state");

	this->emotion_duration = 3000;
	this->emotion_started = start;
  	this->servo_last_millis = 0;
  	this->motor_last_millis = 400;
     this->led_last_millis = 0;
  	this->servo_interval = 1500;
  	this->motor_interval = 0;
    this->led_interval = 0;

	this->servo1 = servoPtr[0];
	this->servo2 = servoPtr[1];
	this->servo3 = servoPtr[2];
	this->motor1 = motorPtr[0];
	this->motor2 = motorPtr[1];

  	this->isMotorSwapped = 0;
  	this->isServoSwapped = 0; 
}

Disgust::~Disgust(){
	Serial.println("exiting Disgust state");
}

void Disgust::motorAction(){
  Serial.println("motor action ");
  Serial.println(millis());
  if(millis() - this->emotion_started < 1500){
  if(isMotorSwapped){
    this->motor_last_millis = millis();
    motor1->forward(255);
    motor2->reverse(255);
    isMotorSwapped = 0;
  } else {
    this->motor_last_millis = millis();
    motor1->reverse(255);
    motor2->forward(255);
    isMotorSwapped = 1; 
  }
  } else {
   motor1->reverse(100);
   motor2->reverse(100);
  }
}

void Disgust::servoAction(){
  Serial.println("servo action ");
  Serial.println(millis());
  if(millis() - this->emotion_started > 1500){
	  servo1->move(15,50);
  } else {
    this->servo_last_millis = millis();
    servo1->move(120,30);
    servo2->move(120,30);
    servo3->move(120,30);
  }
}
	
void Disgust::musicAction(){}

void Disgust::ledAction(){
      this->led_last_millis = millis();
  this->led_interval = this->emotion_duration;
  Serial.println("led");
    led->light(102,150,0);  
}

void Disgust::stop(){
	motor1->stop();
	motor2->stop();
 led->light(0,0,0);
	delete this;
}
