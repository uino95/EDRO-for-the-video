#ifndef FEAR_H_
#define FEAR_H_

#include "emotion.h"

using namespace std;

class Fear: public Emotion{

public:
	Fear(MyServo * (&servoPtr)[3], Motor * (&motorPtr)[2], Led * &led, unsigned long start);
	~Fear();

	void motorAction();
	void servoAction();
	void musicAction();
	void ledAction();
	void stop();

private:
  	bool isServoSwapped;
  	bool isMotorSwapped;
    bool isLedSwapped;
};

#endif // FEAR_H_
