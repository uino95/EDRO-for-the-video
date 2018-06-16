#ifndef EMOTION_H_
#define EMOTION_H_

#include "myServo.h"
#include "Motor.h"
#include "led.h"
#include <Arduino.h>

using namespace std;

class Emotion {

public:

	unsigned long emotion_duration;
	unsigned long emotion_started;
	
	//Intervals
	unsigned long motor_interval;
	unsigned long servo_interval;
	unsigned long music_interval;
	unsigned long led_interval;

	//Last call to action function
	unsigned long motor_last_millis;
	unsigned long servo_last_millis;
	unsigned long music_last_millis;
	unsigned long led_last_millis;

	//Actions to be redifined by the derived class
 	virtual void motorAction();
	virtual void servoAction();
	virtual void musicAction();
	virtual void ledAction();
	virtual void stop();

	//instance of the components used
	MyServo * servo1;
	MyServo * servo2;
	MyServo * servo3;
	Motor * motor1;
	Motor * motor2;
  	Led * led;
	//TODO add the other components
};

#endif // EMOTION_H_
