// Declare L298N Dual H-Bridge Motor Controller directly since there is not a library to load.

// Motor 1
int dir1PinA = 23;
int dir2PinA = 25;
int speedPinA = 11; // Needs to be a PWM pin to be able to control motor speed

// Motor 2
int dir1PinB = 24;
int dir2PinB = 22;
int speedPinB = 10; // Needs to be a PWM pin to be able to control motor speed

void setup_wheels() {  // Setup runs once per reset
  // initialize serial communication @ 9600 baud:
  Serial.begin(9600);

  //Define L298N Dual H-Bridge Motor Controller Pins

  pinMode(dir1PinA,OUTPUT);
  pinMode(dir2PinA,OUTPUT);
  pinMode(speedPinA,OUTPUT);
  pinMode(dir1PinB,OUTPUT);
  pinMode(dir2PinB,OUTPUT);
  pinMode(speedPinB,OUTPUT);
}

void motor1forward(int velocity){
  analogWrite(speedPinA, velocity);//Sets speed variable via PWM 
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, HIGH);
  Serial.println("Motor 1 Forward"); // Prints out “Motor 1 Forward” on the serial monitor
}

void motor1stop(){
  analogWrite(speedPinA, 0);
  Serial.println("Motor 1 Stop");
}

void motor1reverse(int velocity){
  analogWrite(speedPinA, velocity);
  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir2PinA, LOW);
  Serial.println("Motor 1 Reverse");
}

void motor2forward(int velocity){
  analogWrite(speedPinB, velocity);
  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, HIGH);
  Serial.println("Motor 2 Forward");
  Serial.println("   ");
}

void motor2stop(){
  analogWrite(speedPinB, 0);
  Serial.println("Motor 2 Stop");
  Serial.println("   ");
}

void motor2reverse(int velocity){
  analogWrite(speedPinB, velocity);
  digitalWrite(dir1PinB, HIGH);
  digitalWrite(dir2PinB, LOW);
  Serial.println("Motor 2 Reverse");
}


void wheels_joy(){
  motor1reverse(255);
  motor2forward(255);
  delay(2000);
  motor1forward(255);
  motor2reverse(255);
  delay(2000);
}

void wheels_fear(){
  motor1reverse(255);
  motor2forward(255);
  delay(50);
  motor1forward(255);
  motor2reverse(255);
  delay(50);
}

void wheels_disgust(){
  motor1reverse(100);
  motor2forward(100);
  delay(500);
  motor1forward(100);
  motor2reverse(100);
  delay(500);
  motor1stop();
  motor2stop();
}

