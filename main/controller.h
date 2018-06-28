#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "emotion.h"
#include "myServo.h"
#include "led.h"
#include "sonar.h"
#include "motor.h"
#include "player.h"

using namespace std;

class Controller {

public:
	
	Controller(MyServo * (&servoPtr)[3], Motor * (&motorPtr)[2], Led * &led, Player* &player, Sonar * &sonar);
	void init();
	void setEmotion(Emotion * current_emotion);
	void changeEmotion();
	void updateEmotion(unsigned long current_millis);	
	void checkObstacle();
	MyServo * servo[3];
	Motor * motor[2];
	Led * led;
	Player * player;
	Sonar * sonar;
	int next_emotion;

private:
  int consecutive;
  int threshold;
  int distance;
  int obstacleFound;
  unsigned long sonar_interval;
  unsigned long sonar_last_millis;
  bool isNeutral;

	Emotion* current_emotion;
};

#endif // CONTROLLER_H_
