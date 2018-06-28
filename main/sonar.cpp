#include "sonar.h"

Sonar::Sonar(){}

void Sonar::setup(uint8_t trigPin, uint8_t echoPin, unsigned int maxDistance){
	sonar.setup(trigPin, echoPin, maxDistance);
	this->trigPin = trigPin;
	this->echoPin = echoPin;
}

int Sonar::computeDistance(){

	this->distance = sonar.ping_cm();
	Serial.print("Ping: ");
  	Serial.print(this->distance);
  	Serial.println("cm");
  	return this->distance;
	// // Clears the trigPin
	// digitalWrite(trigPin, LOW);
	// delayMicroseconds(2);

	// // Sets the trigPin on HIGH state for 10 micro seconds
	// digitalWrite(trigPin, HIGH);
	// delayMicroseconds(10);
	// digitalWrite(trigPin, LOW);

	// // Reads the echoPin, returns the sound wave travel time in microseconds
	// this->duration = pulseIn(echoPin, HIGH);

	// // Calculating the distance
	// this->distance= duration*0.034/2;

	// // Prints the distance on the Serial Monitor
	// Serial.print("Distance: ");
	// Serial.println(distance);
	// return distance;
}
