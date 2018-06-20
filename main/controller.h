#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "emotion.h"
#include "neutral.h"
#include "joy.h"
#include "anger.h"
#include "fear.h"
#include "sadness.h"
#include "disgust.h"
#include "myServo.h"
#include "led.h"
#include "sonar.h"

using namespace std;

class Controller {

public:
	//make it private
	Emotion* current_emotion;
	Controller(MyServo * (&servoPtr)[3], Motor * (&motorPtr)[2], Led * &led, Sonar * &sonar);
	void init();
	void setEmotion(Emotion * current_emotion);
	void changeEmotion();
	void updateEmotion(unsigned long current_millis);	
	void checkObstacle();

private:
	MyServo * servoPtrs[3];
	Motor * motorPtrs[2];
	Led * led;
	Sonar * sonar;
  	bool isNeutral;
  	int counter;

  	int sonar_interval;
	int sonar_last_millis;
	int distance;
	int consecutive;
	int threshold;
	int obstacleFound;
};

#endif // CONTROLLER_H_
