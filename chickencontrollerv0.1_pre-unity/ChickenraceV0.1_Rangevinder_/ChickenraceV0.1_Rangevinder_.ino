int distanceL;
int distanceR;
long duration;
//
bool unityReady;
//


//ldrtest
const int ldrLPin = A2;
const int ldrRPin = A1;
//controlls
bool left;
bool right;
float forward;
//defines
#define DEAD_ZONE (1000) 
//

void setup() {
  // put your setup code here, to run once:

  pinMode(ldrLPin, INPUT);
  pinMode(ldrRPin, INPUT);
  //unity communication
  unityReady = false;
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Unity===============

  if(Serial.available()){
    char inByte = Serial.read();

    if(inByte == 'a'){
        unityReady = true;
        Serial.println("connected");        
    }
    if(unityReady == true){
      int leftint;
      int rightint;
      String komma = ",";
      //int speedint;//speed
      

        //Serial.println(s3);
      if(left == true){
           
            leftint = 1;
            
      }else{
        leftint = 0;
      }

        
      //send2unity
   
      Serial.print(leftint);//l1 
      Serial.print(",");
      Serial.println(rightint);
      //
    }
  }
  
  //Buttons============================

    if(distanceL <= 10){
      left = true; 
       
    }else{
      left = false;
    }
  //ldr============
  
  int ldrLraw = analogRead(ldrLPin);
  int ldrLfinal;
  int diffL = ldrLraw - ldrLfinal;

  if(abs(diffL) > DEAD_ZONE){
    
    ldrLfinal = ldrLraw;
     Serial.println(ldrLfinal);
     Serial.print(",");
  }
   int ldrRraw = analogRead(ldrRPin);
  int ldrRfinal;
  int diffR = ldrRraw - ldrRfinal;

  if(abs(diffR) > DEAD_ZONE){
    
    ldrRfinal = ldrRraw;
     Serial.println(ldrRfinal);
    
  }
 
  //=============

  delay(10);
}
