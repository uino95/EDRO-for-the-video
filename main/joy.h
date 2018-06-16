#ifndef JOY_H_
#define JOY_H_

#include "emotion.h"

using namespace std;

class Joy: public Emotion{

public:
	Joy(MyServo * (&servoPtr)[3], Motor * (&motorPtr)[2], Led * &led, unsigned long start);
	~Joy();

	void motorAction();
	void servoAction();
	void musicAction();
	void ledAction();
	void stop();

private:
  	bool isServoSwapped;
  	bool isMotorSwapped;
};

#endif // JOY_H_
