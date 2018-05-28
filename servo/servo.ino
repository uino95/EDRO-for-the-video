#include <VarSpeedServo.h>
//#include <Servo.h>

VarSpeedServo myservo;
//Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0; // variable to store the servo position
int i=0;

void setup() {
  myservo.attach(9); 
  myservo.write(0);// attaches the servo on pin 9 to the servo object
}

void loop() {

  delay(500);
 
  /*for(i=0; i<3; i++){
    full_movement();
  }*/
  
  for(i=0; i<5; i++){
    anger();
  }
  
  for(i=0; i<10; i++){
    joy();
  }

  reset();

  for(i=0; i<2; i++){
    sadness();
  }

  /*
  //for (pos = 0; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(60);              // tell servo to go to position in variable 'pos'
    delay(300);                       // waits 15ms for the servo to reach the position
  //}
  //for (pos = 100; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(120);              // tell servo to go to position in variable 'pos'
    delay(300);                       // waits 15ms for the servo to reach the position
  //}*/
}

void reset(){
  myservo.write(0);
}

void stay(int pos, int milliseconds) {
  myservo.write(pos);
  delay(milliseconds);
}

void full_movement(){
  myservo.write(0);
  delay(1000);
  myservo.write(70);
  delay(1000);
}

void joy() {
  myservo.slowmove(30,70);
  delay(300);
  myservo.slowmove(70,70);
  delay(300);
}

void sadness(){
  myservo.slowmove(90,15);
  delay(3000);
  myservo.slowmove(0,15);
  delay(3000);
}

void anger(){
  myservo.write(0);
  delay(100);
  myservo.write(30);
  delay(500);
}


