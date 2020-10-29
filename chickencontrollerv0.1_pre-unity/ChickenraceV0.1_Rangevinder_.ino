int distanceL;
int distanceR;
long duration;

const int Trig_pin = 9;
const int Echo_pin = 10;

//controlls
bool left;
bool right;
float forward;
void setup() {
  // put your setup code here, to run once:
  pinMode(Trig_pin,OUTPUT);
  pinMode(Echo_pin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  duration = pulseIn(Echo_pin,HIGH);
  distanceL = duration /29 / 2;
    if(distanceL <= 5){
      left = true; 
      Serial.print("Left = true    "); 
    }else{
      left = false;
    }
  
  Serial.print("DistanceL: ");
 
  Serial.println(distanceL);
  
}
