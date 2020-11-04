int distanceL;
int distanceR;
long duration;
//
bool unityReady;
//

const int Trig_pin = 15;
const int Echo_pin = 14;
//ldrtest
const int ldrPin = A2;
//controlls
bool left;
bool right;
float forward;
void setup() {
  // put your setup code here, to run once:
  pinMode(Trig_pin,OUTPUT);
  pinMode(Echo_pin,INPUT);
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
        int adc0 = analogRead(14);
        int adc1 = analogRead(15);
        unityReady = true;
       
        //Serial.print("connected");
        
        // construct string from read values
        
        //String s0 = "";
        //String s1 = s0 + adc0;
        //String s2 = s1 + ",";
        //String s3 = s2 + adc1;

        //Serial.println(s3);
        
    }

    if(unityReady == true){
      
      if(left == true){
            Serial.println("8,0");//l1 
            
        }
    }
  }
  
  //Buttons============================
  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);//replace delay with timer
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);//replace delay with timer
  digitalWrite(Trig_pin, LOW);
  duration = pulseIn(Echo_pin,HIGH);
  distanceL = duration /29 / 2;
    if(distanceL <= 10){
      left = true; 
       
    }else{
      left = false;
    }
  //ldr============
  //int ldr1status = analogRead(ldrPin);
 // Serial.println(ldr1status);
  //=============
 //print("DistanceL: ");
 
 // println(distanceL);
  
}
