const int tMotorpin1 = 7;
const int tMotorpin2 = 8;
const int rMotorpin1 = 12;
const int rMotorpin2 = 13;
const int ultraSonicT = 1;
const int ultraSonicE = 2;
int boardCount;//number of panels
long dist = 0, tim = 0;
int count = 0;
int limit;

void setup() {
  Serial.begin(9600);
  pinMode(ultraSonicT, OUTPUT);
  pinMode(ultraSonicE, INPUT);
  pinMode(tMotorpin1, OUTPUT);
  pinMode(tMotorpin2, OUTPUT);
  pinMode(rMotorpin1, OUTPUT);
  pinMode(rMotorpin2, OUTPUT);
  
}

void loop() {
  digitalWrite(ultraSonicT,LOW);
  delayMicroseconds(2);
  digitalWrite(ultraSonicT,HIGH);
  delayMicroseconds(10);
  digitalWrite(ultraSonicT,LOW);

  tim = pulseIn(ultraSonicE,HIGH);//measures the delay time in echoed signal bouncing off the surface
  dist = (tim*340)/20000;//distance in centimeters
 
  Serial.println(dist);
  Serial.print(" cms");
  
  while(dist>limit){
    count+=1;
      if(count<boardCount){
      digitalWrite(tMotorpin1,HIGH);
      digitalWrite(tMotorpin2,LOW);
      digitalWrite(rMotorpin1,HIGH);
      digitalWrite(rMotorpin2,LOW);
      }
      else if(count>=boardCount){
      digitalWrite(tMotorpin1,LOW);
      digitalWrite(tMotorpin2,HIGH);
      digitalWrite(rMotorpin1,LOW);
      digitalWrite(rMotorpin2,HIGH);
      }
  }
  count  = 0;
 }
