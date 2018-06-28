#include "controller.h"
#include "neutral.h"
#include "joy.h"
#include "anger.h"
#include "fear.h"
#include "sadness.h"
#include "disgust.h"
#include "search.h"
#include "explore.h"

Controller::Controller(MyServo * (&servoPtr)[3], Motor * (&motorPtr)[2], Led * &ledPtr, Player* &playerPtr, Sonar * &sonarPtr){
	this->servo[0] = servoPtr[0];
	this->servo[1] = servoPtr[1];
	this->servo[2] = servoPtr[2];
	this->motor[0] = motorPtr[0];
	this->motor[1] = motorPtr[1];
  this->led = ledPtr;
  this->player = playerPtr;
  this->sonar = sonarPtr;

   this->consecutive = 0;
   this->threshold = 10;
   this->distance = 0;
   this->obstacleFound = 4;
   this->sonar_interval = 25;
   this->sonar_last_millis = 0;
   isNeutral = 1;

  Neutral* n = new Neutral(this, millis(), 1);
  current_emotion = n;
}

void Controller::setEmotion(Emotion * e){
	current_emotion = e;
}

void Controller::updateEmotion(unsigned long current_millis){
	
	//until the emotion has time to do thing enter and do stuff
	if(current_millis - current_emotion->emotion_started < current_emotion->emotion_duration){
		if(current_millis - current_emotion->motor_last_millis >= current_emotion->motor_interval){
			current_emotion->motorAction();
		}
		if(current_millis - current_emotion->servo_last_millis >= current_emotion->servo_interval){
			current_emotion->servoAction();
		}
		if(current_millis - current_emotion->led_last_millis >= current_emotion->led_interval){
			current_emotion->ledAction();
		}
    if(current_millis - current_emotion->music_last_millis >= current_emotion->music_interval){
      current_emotion->musicAction();
    }
    if(current_millis - current_emotion->sonar_last_millis >= current_emotion->sonar_interval){
      current_emotion->sonarAction();
    }
	} else {
    changeEmotion();
	}
}

void Controller::changeEmotion(){
  current_emotion->stop();
  isNeutral = 1;
  this->threshold = 10;
  this->consecutive = 0;
  switch(next_emotion){
    case 1:
    {
      Joy* j = new Joy(this, millis());
      setEmotion(j);
      next_emotion ++;
      break;
    }
    case 2:
    {
      Neutral* n = new Neutral(this, millis(), 1);
      setEmotion(n);
      next_emotion ++;
      break;
    }
    case 3:
    {
      Anger* a = new Anger(this, millis());
      setEmotion(a);
      next_emotion ++;
      break; 
    }
    case 4:
    {
      Neutral* n = new Neutral(this, millis(), 1);
      setEmotion(n);
      next_emotion ++;
      break;
    }
    case 5:
    {
      Disgust* d = new Disgust(this, millis());
      setEmotion(d);
      next_emotion ++;
      break;
    }
    case 6:
    {
      Neutral* n = new Neutral(this, millis(), 0);
      setEmotion(n);
      next_emotion ++;
      break;
    }
    case 7:
    {
      Fear* f = new Fear(this, millis());
      setEmotion(f);
      next_emotion ++;
      break;
    }
    case 8:
    {
      Neutral* n = new Neutral(this, millis(), 0);
      setEmotion(n);
      next_emotion ++;
      break;
    }
    case 9:
    {
      Sadness* s = new Sadness(this, millis());
      setEmotion(s);
      next_emotion ++;
      break;
    }
    default:
    {
      Neutral* n = new Neutral(this, millis(), 1);
      setEmotion(n);
      next_emotion= 1;
      break;
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
