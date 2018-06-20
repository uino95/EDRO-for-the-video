#ifndef MYSERVO_H_
#define MYSERVO_H_

#include <VarSpeedServo.h>

using namespace std;

class MyServo{

public:
	MyServo();
	void reset();
	VarSpeedServo servo; //TODO make this this private
	void move(int pos, int speed);
 	void Attach(int pin);
  	void Detach(); //TODO delete this method

private:
	bool isInverse; 
	int inverse(int pos);
};

#endif // MYSERVO_H_
