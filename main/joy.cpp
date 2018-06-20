#include "joy.h"
#include <Arduino.h>

Joy::Joy(MyServo * (&servoPtr)[3], Motor* (&motorPtr)[2], Led * &led, unsigned long start){

	Serial.println("enter Joy state");

	  this->emotion_duration = 10000;
	  this->emotion_started = start;
  	this->servo_last_millis = 0;
  	this->motor_last_millis = 0;
    this->led_last_millis = 0;
  	this->servo_interval = 400;
  	this->motor_interval = 150;
    this->led_interval = 200;

	this->servo1 = servoPtr[0];
	this->servo2 = servoPtr[1];
	this->servo3 = servoPtr[2];
	this->motor1 = motorPtr[0];
	this->motor2 = motorPtr[1];
  this->led = led;

  	this->isMotorSwapped = 0;
  	this->isServoSwapped = 0;
   this->isLedSwapped = 0;
   
   
}

Joy::~Joy(){
	Serial.println("exiting Joy state");
}

void Joy::motorAction(){
  Serial.println("motor action ");
  Serial.println(millis());
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
}

void Joy::servoAction(){
  Serial.println("servo action ");
  Serial.println(millis());
  if(isServoSwapped){
    this->servo_last_millis = millis();
	  servo1->move(45,30);
	  servo2->move(45,30);
	  servo3->move(45,30);
    isServoSwapped = 0;
  } else {
    this->servo_last_millis = millis();
    servo1->move(80,30);
    servo2->move(80,30);
    servo3->move(80,30);
    isServoSwapped = 1;
  }
}
	
void Joy::musicAction(){}

void Joy::ledAction(){
  this->led_last_millis = millis();
  if(isLedSwapped){
    led->light(150,150,0);
    isLedSwapped = 0;
  } else {
    led->light(0,0,0);
    isLedSwapped = 1;
  }
  
  }

void Joy::stop(){
	motor1->stop();
	motor2->stop();
  led->light(0,0,0);
	delete this;
}
