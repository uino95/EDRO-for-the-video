#ifndef NEUTRAL_H_
#define NEUTRAL_H_

#include "controller.h"
#include "emotion.h"
#include "sonar.h"

using namespace std;

class Neutral: public Emotion{

public:
	Neutral(MyServo * (&servoPtr)[3], Motor * (&motorPtr)[2], Led * &ledPtr);
	~Neutral();

	void motorAction();
	void servoAction();
	void musicAction();
	void ledAction();
	void stop();
};

#endif // NEUTRAL_H_
