#include <VarSpeedServo.h>

VarSpeedServo servo_0, servo_1, servo_2;

int inverse(int pos){
  int new_pos = pos -125;
  if (new_pos < 0){
    new_pos = (new_pos * (-1)) + 20;
  }
  return new_pos;
}

void setup_servo(){
  servo_2.attach(7);
  servo_1.attach(8); //the one in the front
  servo_0.attach(9); //attach here the one that has inverse movement
  servo_2.write(115);
  servo_1.write(115);
  servo_0.write(inverse(110));
}

// closed position is set to 115
// open position is set to 5
void servo_reset(){
  servo_2.write(120);
  servo_1.write(120);
  servo_0.write(10);
}

void servo_stay(int pos, int milliseconds) {
  servo_2.write(pos);
  servo_1.write(pos);
  servo_0.write(inverse(pos));
  delay(milliseconds);
}

void servo_full_movement(){
  servo_2.write(120);
  servo_1.write(120);
  servo_0.write(inverse(120));
  delay(2000);
  servo_2.write(10);
  servo_1.write(10);
  servo_0.write(inverse(10));
  delay(2000);
}

void servo_joy() {
  int velocity = 50;
  servo_2.slowmove(20,velocity);
  servo_1.slowmove(20,velocity);
  servo_0.slowmove(inverse(20),velocity);
  delay(500);
  servo_2.slowmove(80,velocity);
  servo_1.slowmove(80,velocity);
  servo_0.slowmove(inverse(80),velocity);
  delay(500);
}

void servo_sadness(){
  servo_2.slowmove(10,45);
  servo_1.slowmove(10,45);
  servo_0.slowmove(inverse(10),45);
  delay(3000);
  servo_2.slowmove(120,45);
  servo_1.slowmove(120,45);
  servo_0.slowmove(inverse(120),45);
}

void servo_anger(){
  servo_2.write(115);
  servo_1.write(115);
  servo_0.write(inverse(115));
  delay(100);
  servo_2.write(90);
  servo_1.write(90);
  servo_0.write(inverse(90));
  delay(250);
}


