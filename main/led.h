#ifndef LED_H_
#define LED_H_

#include <VarSpeedServo.h>

using namespace std;

class Led{

public:
	Led();
	void configure(int pinRed, int pinGreen, int pinBlue);
	void light(int red, int green, int blue);
private:
	int pinRed;
	int pinGreen;
	int pinBlue;
};

#endif // LED_H_
