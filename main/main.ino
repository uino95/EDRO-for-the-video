
//Put here all your setup
int state=1;

void loop() {
  switch(state){
    //joy
    case 1:
      joy();
      state ++;
      break;
      delay(3000);
      
    case 2:
      sadness();
      state ++;
      break;
      delay(3000);

    case 3:
      anger();
      state ++;
      break;
      delay(3000);

    case 4:
      fear();
      state++;
      break;
      delay(3000);

    case 5:
       disgust();
       state++;
       break;
       delay(3000);

    default:
        state = 1;
        neutral();
  }
  
}

void joy(){
  for(int i=0; i<10; i++){
    servo_joy();
  }
}

void sadness(){
  for(int i=0; i<3; i++){
    servo_sadness();
  }
}

void anger(){
  for(int i=0; i<15; i++){
    servo_anger();
  } 
}

void fear(){
}
void disgust(){
}
void neutral(){
  servo_reset();
}

