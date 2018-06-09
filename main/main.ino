
//Put here all your setup
int state=0;

void loop() {
  switch(state){
    //joy
    case 1:
      joy();
      state ++;
      delay(3000);
      break;
      
    case 2:
      sadness();
      state ++;
      delay(3000);
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
  for(int i=0; i<10; i++){
    servo_joy();
    play();
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

