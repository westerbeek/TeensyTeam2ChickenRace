//defines
#define DEAD_ZONE (500) 
//INCLUDES
#include <IRremote.h>
//
long duration;
//
//send2unity
   int leftint;
   int rightint;
   int speed;
   String komma = ",";
//

//ldrtest
const int ldrLPin = A2;
const int ldrRPin = A1;

const int receiverinfra = 12;

//controlls
bool left;
bool right;
float forward;


void setup() {
  // put your setup code here, to run once:

  pinMode(ldrLPin, INPUT);
  pinMode(ldrRPin, INPUT);
  pinMode(receiverinfra, INPUT);
  //unity communication
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Unity===============
  //unityconnection();
 
  ldrs();
  spinner();

  //ldr============
  
  

  
}
void spinner(){
  //here comes the spinn
  //digitalWrite(13, HIGH);
  int reed_status = digitalRead(12);
  if (reed_status == 1){
    Serial.println("1");
  } else{
    Serial.println("0");
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

  //ldr Right
  int ldrRraw = analogRead(ldrRPin);
  int ldrRfinal;
  int diffR = ldrRraw - ldrRfinal;

  if(abs(diffR) > DEAD_ZONE){
    
     ldrRfinal = ldrRraw;
     rightint = ldrRfinal;
    
  }
     /*Serial.println(ldrLfinal);
     Serial.print(",");
     Serial.println(ldrRfinal);*/
  //=============
  delay(10);
}

void unityconnection() {
 
 if(Serial.available()){
    char inByte = Serial.read();

    if(inByte == 'a'){  
      //  Serial.print(leftint);//l1 
      //  Serial.print(",");
      //  Serial.println(rightint);     
    }
    
      
  }
}
