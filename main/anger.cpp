#include "anger.h"
#include <Arduino.h>

Anger::Anger(MyServo * (&servoPtr)[3], Motor* (&motorPtr)[2], Led * &led, unsigned long start){

	Serial.println("enter Anger state");

	this->emotion_duration = 5000;
	this->emotion_started = start;
  	this->servo_last_millis = 0;
  	this->motor_last_millis = 0;
    this->led_last_millis = 0;
  	this->servo_interval = 200;
  	this->motor_interval = 400;
   this->led_interval = 50;

	this->servo1 = servoPtr[0];
	this->servo2 = servoPtr[1];
	this->servo3 = servoPtr[2];
	this->motor1 = motorPtr[0];
	this->motor2 = motorPtr[1];

  	this->isMotorSwapped = 0;
  	this->isServoSwapped = 0; 
    this->isFirstTime = 1;

    this->initColor[0] = 50;
    this->initColor[1] = 0;
    this->initColor[2] = 0;
    this->endColor[0] = 150;
    this->endColor[1] = 0;
    this->endColor[2] = 0;
    
    for(int i = 0; i< 3; i++){
      this->steps[i] = round((float)abs((int)this->initColor[i] - (int)this->endColor[i]) * (int)this->led_interval / (this->servo_interval * 2));
      if(this->steps[i] < 1){
        this->steps[i] = 1;
      }
      Serial.println(this->steps[i]);
      this->currentColor[i] = initColor[i];
    }
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
    if(this->currentColor[0] >= this->endColor[0] && this->currentColor[1] >= this->endColor[1] && this->currentColor[2] >= this->endColor[2]){
      for(int i = 0; i < 3; i++){
        currentColor[i] = initColor[i];
      }
    } else {
      led->light(this->currentColor[0], this->currentColor[1], this->currentColor[2]);
      for(int i = 0; i < 3; i++){
        currentColor[i] = currentColor[i] + this->steps[i];
      }
    }
    this->led_last_millis = millis(); 
}

void Anger::stop(){
	motor1->stop();
	motor2->stop();
  led->light(0,0,0);
	delete this;
}
