#include "anger.h"
#include <Arduino.h>

Anger::Anger(MyServo * (&servoPtr)[3], Motor* (&motorPtr)[2], Led * &led, unsigned long start){

	Serial.println("enter Anger state");

	this->emotion_duration = 10000;
	this->emotion_started = start;
  	this->servo_last_millis = 0;
  	this->motor_last_millis = 0;
    this->led_last_millis = 0;
  	this->servo_interval = 200;
  	this->motor_interval = 400;
   this->led_interval = 0;

	this->servo1 = servoPtr[0];
	this->servo2 = servoPtr[1];
	this->servo3 = servoPtr[2];
	this->motor1 = motorPtr[0];
	this->motor2 = motorPtr[1];

  	this->isMotorSwapped = 0;
  	this->isServoSwapped = 0; 
    this->isFirstTime = 1;
}

Anger::~Anger(){
	Serial.println("exiting Anger state");
}

void Anger::motorAction(){
  //Serial.println("motor action ");
  //Serial.println(millis());
	if(isMotorSwapped){
		this->motor_last_millis = millis();
		motor1->forward(255);
		motor2->forward(255);
		isMotorSwapped = 0;
	} else {
		this->motor_last_millis = millis();
		motor1->stop();
		motor2->stop();
		isMotorSwapped = 1;	
	}
}

void Anger::servoAction(){
  //Serial.println("servo action ");
  //Serial.println(millis());
  if(isFirstTime){
    this->servo_last_millis = millis();
    servo1->move(15,30);
    isFirstTime = 0;
  }
  if(isServoSwapped){
    this->servo_last_millis = millis();
	  servo2->move(90,30);
	  servo3->move(90,30);
    isServoSwapped = 0;
  } else {
    servo2->move(120,150);
    servo3->move(120,150);
    isServoSwapped = 1;
    this->servo_last_millis = millis();
  }
}
	
void Anger::musicAction(){}

void Anger::ledAction(){
    this->led_last_millis = millis();
    this->led_interval = this->emotion_duration;
    Serial.println("led");
    led->light(150,20,0);
  }

void Anger::stop(){
	motor1->stop();
	motor2->stop();
  led->light(0,0,0);
	delete this;
}
