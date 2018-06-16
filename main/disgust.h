#ifndef DISGUST_H_
#define DISGUST_H_

#include "emotion.h"

using namespace std;

class Disgust: public Emotion{

public:
	Disgust(MyServo * (&servoPtr)[3], Motor * (&motorPtr)[2], Led * &led, unsigned long start);
	~Disgust();

	void motorAction();
	void servoAction();
	void musicAction();
	void ledAction();
	void stop();

private:
  	bool isServoSwapped;
  	bool isMotorSwapped;
};

#endif // DISGUST_H_
