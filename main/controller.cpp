#include "controller.h"
#include <Arduino.h>

Controller::Controller(MyServo * (&servoPtr)[3], Motor * (&motorPtr)[2], Led * &ledPtr, Sonar * &sonarPtr){
	this->servoPtrs[0] = servoPtr[0];
	this->servoPtrs[1] = servoPtr[1];
	this->servoPtrs[2] = servoPtr[2];
	this->motorPtrs[0] = motorPtr[0];
	this->motorPtrs[1] = motorPtr[1];
  this->led = ledPtr;
  this->sonar = sonarPtr;

  this->consecutive = 0;
  this->threshold = 10;
  this->distance = 0;
  this->obstacleFound = 4;
  this->sonar_interval = 25;
  this->sonar_last_millis = 0;

	Neutral* n = new Neutral(this->servoPtrs, this->motorPtrs, this->led);
	current_emotion = n;
  isNeutral = 1;
  counter = 1;
}

void Controller::setEmotion(Emotion * e){
	current_emotion = e;
}

void Controller::updateEmotion(unsigned long current_millis){
	
	//until the emotion has time to do thing enter and do stuff
	if(!isNeutral && current_millis - current_emotion->emotion_started < current_emotion->emotion_duration){

		if(current_millis - current_emotion->motor_last_millis >= current_emotion->motor_interval){
			current_emotion->motorAction();
		}
		if(current_millis - current_emotion->servo_last_millis >= current_emotion->servo_interval){
			current_emotion->servoAction();
		}
		if(current_millis - current_emotion->music_last_millis >= current_emotion->music_interval){
			current_emotion->musicAction();
		}
		if(current_millis - current_emotion->led_last_millis >= current_emotion->led_interval){
			current_emotion->ledAction();
		}
	} else {
		//TODO stop() could be also the destroyer of the single emotion, which has to stop all the motors
		if (!isNeutral){//aka we aren't in neutral state;
			current_emotion->stop();
			Neutral* n = new Neutral(this->servoPtrs, this->motorPtrs, this->led);
			setEmotion(n);
      isNeutral = 1;
		}
    else {
      if(current_millis - this->sonar_last_millis >= this->sonar_interval){
        //this->sonar_last_millis = millis();
        //changeEmotion();
        checkObstacle();
        Serial.println("hey ther");
      }
    }
	}
}

void Controller::changeEmotion(){
  current_emotion->stop();
  this->consecutive = 0;
  this->threshold = 10;
  isNeutral = 0;
  switch(counter){
    case 1:
    {
      Joy* j = new Joy(this->servoPtrs, this->motorPtrs, this->led, millis());
      setEmotion(j);
      counter++;
    }
      break;
    case 2:
  {
      Anger* a = new Anger(this->servoPtrs, this->motorPtrs, this->led, millis());
      setEmotion(a);
      counter++;
  }
      break; 
    case 3:
    {
      Disgust* d = new Disgust(this->servoPtrs, this->motorPtrs, this->led, millis());
      setEmotion(d);
      counter++;
    }
      break;
    case 4:
    {
      Fear* f = new Fear(this->servoPtrs, this->motorPtrs, this->led, millis());
      setEmotion(f);
      counter++;
    }
      break;
    case 5:
    {
      Sadness* s = new Sadness(this->servoPtrs, this->motorPtrs, this->led, millis());
      setEmotion(s);
      counter++;
    }
      break;
    default:
    {
      Neutral* n = new Neutral(this->servoPtrs, this->motorPtrs, this->led);
      setEmotion(n);
      isNeutral = 1;
      counter= 1;
    }
  }
	Serial.println("emotion changed");
}

void Controller::checkObstacle(){
  this->sonar_last_millis = millis();
  this->distance = sonar->computeDistance();
  if(this->distance < this->threshold && this->distance > 0){
    this->consecutive ++;
    if (this->consecutive = this->obstacleFound){
      this->threshold = 4000;
      changeEmotion();
    }
  } else {
    this->consecutive = 0;
  }
}
