#ifndef NEUTRAL_H_
#define NEUTRAL_H_

#include "controller.h"
#include "emotion.h"

using namespace std;

class Neutral: public Emotion{

public:
	Neutral(Controller* controller, unsigned long current_millis, bool closed);
	~Neutral();

	void motorAction();
	void servoAction();
	void musicAction();
	void ledAction();
 void sonarAction();
	void stop();

private: 
	Controller* controller;
  bool closed;
};

#endif // NEUTRAL_H_
