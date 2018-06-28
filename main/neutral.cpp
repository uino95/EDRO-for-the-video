#include "neutral.h"

Neutral::Neutral(Controller* controller, unsigned long start, bool closed){

	Serial.println("enter Neutral state");

	this->controller = controller;

	this->emotion_duration = 4000;//duration of the emotion in milliseconds
	this->emotion_started = start;
  this->closed = closed;
  
}

Neutral::~Neutral(){
	Serial.println("exiting neutral state");
}

void Neutral::motorAction(){
  Serial.println("motor action neutral");
  Serial.println(millis());
  this->motor_interval = this->emotion_duration;
	controller->motor[0]->stop();
	controller->motor[1]->stop();
}

void Neutral::servoAction(){
  Serial.println("servo action neutral");
  Serial.println(millis());
  this->servo_interval = this->emotion_duration;
  if(this->closed){
	  controller->servo[0]->close(30);
    controller->servo[1]->close(30);
    controller->servo[2]->close(30);
  } else {
    controller->servo[0]->open(30);
    controller->servo[1]->open(30);
    controller->servo[2]->open(30);
  }
}
	
void Neutral::musicAction(){}

void Neutral::ledAction(){
  this->led_interval = this->emotion_duration;
  controller->led->light(0,0,0);
}

void Neutral::sonarAction(){}

void Neutral::stop(){ 
	delete this;
}
