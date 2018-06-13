
//Put here all your setup
int state=1;

void setup(){
  setup_servo();
  setup_wheels();
}

void loop() {
  switch(state){
    //joy
    case 1:
      joy();
      state =1;
      delay(3000);
      break;
      
    case 2:
      sadness();
      state ++;
      delay(3000);
      Serial.println("stop joy");
      Serial.println("       ");
      break;

    case 3:
      anger();
      state ++;
      delay(3000);
      break;

    case 4:
      fear();
      state++;
      delay(3000);
      break;

    case 5:
       disgust();
       state++;
       delay(3000);
       break;


    default:
        state = 1;
        neutral();
  }
  
}

void joy(){
  for(int j=0; j<10; j++){
      wheels_disgust();
      servo_joy();
  }
  
}

void sadness(){
  for(int i=0; i<1; i++){
    servo_sadness();
    Serial.print("sadness");
  }
}

void anger(){
  for(int i=0; i<1; i++){
    Serial.print("anger");
    servo_anger();
  } 
}

void fear(){
  for(int i=0; i<10; i++){
    wheels_fear();
  }
  Serial.print("fear");
  motor1stop();
  motor2stop();
}
void disgust(){
  for(int i=0; i<10; i++){
    wheels_disgust();
    Serial.print("bleah");
  }
  motor1stop();
  motor2stop();
}
void neutral(){
  //servo_reset();
  motor1forward(50);
  delay(500);
  motor1reverse(50);
  delay(500);
 
  //servo_full_movement();
 
}

