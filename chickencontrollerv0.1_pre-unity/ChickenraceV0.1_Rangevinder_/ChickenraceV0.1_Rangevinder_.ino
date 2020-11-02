int distanceL;
int distanceR;
long duration;

const int Trig_pin = 15;
const int Echo_pin = 14;

//controlls
bool left;
bool right;
float forward;
void setup() {
  // put your setup code here, to run once:
  pinMode(Trig_pin,OUTPUT);
  pinMode(Echo_pin,INPUT);
  //unity communication
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Unity===============

  if(Serial.available()){
    char inByte = Serial.read();

    if(inByte == 'a'){
        int adc0 = digitalRead(A0);
        int adc1 = digitalRead(A1);
      
        // construct string from read values
        if(left == true){
            Serial.write("L1"); 
            Serial.flush(); 
        }
        //String s0 = "";
        //String s1 = s0 + adc0;
        //String s2 = s1 + ",";
        //String s3 = s2 + adc1;

        //Serial.println(s3);
        
    }
  }
  
  //Buttons============================
  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  duration = pulseIn(Echo_pin,HIGH);
  distanceL = duration /29 / 2;
    if(distanceL <= 10){
      left = true; 
       
    }else{
      left = false;
    }
  
  Serial.print("DistanceL: ");
 
  Serial.println(distanceL);
  
}
