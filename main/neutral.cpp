#include "neutral.h"
#include <Arduino.h>

Neutral::Neutral(MyServo * (&servoPtr)[3], Motor* (&motorPtr)[2], Led * &ledPtr){

	Serial.println("enter Neutral state");

	this->emotion_duration = 0;
	this->emotion_started = 0;
	this->servo1 = servoPtr[0];
	this->servo2 = servoPtr[1];
	this->servo3 = servoPtr[2];
	this->motor1 = motorPtr[0];
	this->motor2 = motorPtr[1];
	this->led = ledPtr;

	motorAction();
	servoAction();
	ledAction();
	
}

Neutral::~Neutral(){
	Serial.println("exiting neutral state");
}

void Neutral::motorAction(){
  Serial.println("motor action neutral");
  Serial.println(millis());
	motor1->stop();
	motor2->stop();
}

void Neutral::servoAction(){
  Serial.println("servo action neutral");
  Serial.println(millis());
	  servo1->move(55,30);
    servo2->move(55, 30);
    servo3->move(55, 30);	
}
	
void Neutral::musicAction(){}

void Neutral::ledAction(){
  led->light(0,0,0);
}

void Neutral::stop(){
	delete this;
}
