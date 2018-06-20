#ifndef ANGER_H_
#define ANGER_H_

#include "emotion.h"

using namespace std;

class Anger: public Emotion{

public:
	Anger(MyServo * (&servoPtr)[3], Motor * (&motorPtr)[2], Led * &led, unsigned long start);
	~Anger();

	void motorAction();
	void servoAction();
	void musicAction();
	void ledAction();
	void stop();

private:
  	bool isServoSwapped;
  	bool isMotorSwapped;
    bool isFirstTime;
    int steps[3];
    int initColor[3];
    int endColor[3];
    int currentColor[3];
};

#endif // ANGER_H_
