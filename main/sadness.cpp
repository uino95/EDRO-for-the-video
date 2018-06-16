#include "sadness.h"
#include <Arduino.h>

Sadness::Sadness(MyServo * (&servoPtr)[3], Motor* (&motorPtr)[2], Led * &led ,unsigned long start){

	Serial.println("enter Sadness state");

	this->emotion_duration = 5000;
	this->emotion_started = start;
  	this->servo_last_millis = 0;
  	this->motor_last_millis = 0;
     this->led_last_millis = 0;
  	this->servo_interval = 0;
  	this->motor_interval = 0;
    this->led_interval = 100;

	this->servo1 = servoPtr[0];
	this->servo2 = servoPtr[1];
	this->servo3 = servoPtr[2];
	this->motor1 = motorPtr[0];
	this->motor2 = motorPtr[1];

  	this->isMotorSwapped = 0;
  	this->isServoSwapped = 0; 
    this->initColor[0] = 0;
    this->initColor[1] = 150;
    this->initColor[2] = 150;
    this->endColor[0] = 0;
    this->endColor[1] = 10;
    this->endColor[2] = 10;
    
    for(int i = 0; i< 3; i++){
      this->steps[i] = round((float)abs((int)this->initColor[i] - (int)this->endColor[i]) * (int)this->led_interval / this->emotion_duration);
      if(this->steps[i] < 1){
        this->steps[i] = 1;
      }
      Serial.println(this->steps[i]);
      this->currentColor[i] = initColor[i];
    }
    
}

Sadness::~Sadness(){
	Serial.println("exiting Sadness state");
}

void Sadness::motorAction(){
  Serial.println("motor action ");
  Serial.println(millis());
  if(millis() - this->emotion_started < (this->emotion_duration / 2)){
    Serial.println("motor action firat ");
    motor1->forward(100);
    motor2->stop();
    this->motor_last_millis = millis();
    this->motor_interval = (this->emotion_duration / 2);
  } else {
    Serial.println("motor action second ");
    motor1->stop();
    motor2->forward(100);
    this->motor_interval = this->emotion_duration;
    this->motor_last_millis = millis();
  }
}

void Sadness::servoAction(){
  Serial.println("servo action ");
  Serial.println(millis());
  if(millis() - this->emotion_started < this->emotion_duration / 2){
    Serial.println("servo action first");
    servo1->move(120,25);
    servo2->move(120,25);
    servo3->move(120,25);
    this->servo_last_millis = millis();
    this->servo_interval = this->emotion_duration / 2;
  } else {
    Serial.println("servo action second");
    servo1->move(15,25);
    servo2->move(15,25);
    servo3->move(15,25);
    this->servo_interval = this->emotion_duration;
    this->servo_last_millis = millis();
  }
}

  
void Sadness::musicAction(){}

void Sadness::ledAction(){
  this->led_last_millis = millis();
  //Serial.println("led");
  led->light(this->currentColor[0], this->currentColor[1], this->currentColor[2]);
  for(int i = 0; i < 3; i++){
    currentColor[i] = currentColor[i] - this->steps[i];
  }
}

void Sadness::stop(){
	motor1->stop();
	motor2->stop();
  led->light(0,0,0);
	delete this;
}
