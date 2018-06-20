#include "fear.h"
#include <Arduino.h>

Fear::Fear(MyServo * (&servoPtr)[3], Motor* (&motorPtr)[2], Led * &led, unsigned long start){

	Serial.println("enter Fear state");

	this->emotion_duration = 10000;
	this->emotion_started = start;
  	this->servo_last_millis = 0;
  	this->motor_last_millis = 0;
     this->led_last_millis = 0;
  	this->servo_interval = 0;
  	this->motor_interval = 50;
     this->led_interval = 50;
    

	this->servo1 = servoPtr[0];
	this->servo2 = servoPtr[1];
	this->servo3 = servoPtr[2];
	this->motor1 = motorPtr[0];
	this->motor2 = motorPtr[1];

  	this->isMotorSwapped = 0;
  	this->isServoSwapped = 0; 
    this->isLedSwapped = 1; 
   
}

Fear::~Fear(){
	Serial.println("exiting Fear state");
}

void Fear::motorAction(){
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

void Fear::servoAction(){
  Serial.println("servo action ");
  Serial.println(millis());
  this->servo_last_millis = millis();
  this->servo_interval = this->emotion_duration;
   servo1->reset();
   servo2->reset();
   servo3->reset();
}
	
void Fear::musicAction(){}

void Fear::ledAction(){
   this->led_last_millis = millis();
  if(isLedSwapped){
    led->light(150,0,150);
    isLedSwapped = 0;
  } else {
    led->light(0,0,0);
    isLedSwapped = 1;
  }
  
}

void Fear::stop(){
	motor1->stop();
	motor2->stop();
 led->light(0,0,0);
	delete this;
}
