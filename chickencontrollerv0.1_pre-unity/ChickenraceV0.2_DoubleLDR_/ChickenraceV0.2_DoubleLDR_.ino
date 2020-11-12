//defines
#define DEAD_ZONE (100) 
//INCLUDES
#include <IRremote.h>
//
long duration;
//
//send2unity
   int oldreed;
   int leftint;
   int rightint;
   int speedint;
   int spd;//speedholder
   String komma = ",";
//

//ldrtest
const int ldrLPin = A1;
const int ldrRPin = A2;

const int receiverinfra = 12;
float maxtimer = 100;


void setup() {
  // put your setup code here, to run once:
  oldreed = 0;
  pinMode(ldrLPin, INPUT_PULLUP);
  pinMode(ldrRPin, INPUT_PULLUP);
  pinMode(receiverinfra, INPUT_PULLUP);
  //unity communication
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Unity===============
  
 
  ldrs();
  spinner();
  unityconnection();
  //ldr============
  
  

  
}
void spinner(){
  //here comes the spinn
  //digitalWrite(13, HIGH);
  int reed_status = digitalRead(12);
  bool once = false;
  
  float timer;
  
  timer = millis();
 
   if(oldreed == 0 && once == false){
    if(reed_status == 1){
      //Serial.println("1");
      spd++;
      oldreed = 1;
      once = true;
    }
   }
   if(oldreed == 1 && once == false){
    if(reed_status == 0){
   // Serial.println("0");
    spd++;
    oldreed = 0;
    once = true;
    }
   } 
  if(timer >= maxtimer){
    
  maxtimer = maxtimer + 100;
 
  
  //Serial.println(spd);
  speedint = spd;
  spd = 0;
  }
  
}

void ldrs(){
  //ldr left
  int ldrLraw = analogRead(ldrLPin);
  int ldrLfinal;
  int diffL = ldrLraw - ldrLfinal;

  if(abs(diffL) > DEAD_ZONE){
    
    ldrLfinal = ldrLraw;
    leftint = ldrLfinal;
  }
   int ldrRraw = analogRead(ldrRPin);
  int ldrRfinal;
  int diffR = ldrRraw - ldrRfinal;

  if(abs(diffR) > DEAD_ZONE){
    
    ldrRfinal = ldrRraw;
    rightint = ldrRfinal;
    
  }
 
  //=============


}

void unityconnection() {
 
 if(Serial.available()){
    char inByte = Serial.read();

    if(inByte == 'a'){  
        Serial.print(leftint);//l1 
        Serial.print(",");
        Serial.print(rightint);    
        Serial.print(",");
        Serial.println(speedint);  
    }
    
      
  }
}
