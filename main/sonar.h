#ifndef SONAR_H_
#define SONAR_H_

#include <Arduino.h>

using namespace std;

class Sonar{

public:
	Sonar();
	void setup(int trigPin, int echo2Pin);
	int computeDistance();

private:
	int trigPin;
	int echoPin;
	int duration;
	int distance;
};

#endif // SONAR_H_