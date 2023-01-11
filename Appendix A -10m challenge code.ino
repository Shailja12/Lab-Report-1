//********************************************************//
//*  University of Nottingham                            *//
//*  Department of Electrical and Electronic Engineering *//
//*  Nat Dacombe & Alex Ottway                           *//
//*  UoN EEEBot 2022                                     *//
//*  Motor & Servo Basic Test Code                       *//
//********************************************************//

// ASSUMPTION: Channel A is LEFT, Channel B is RIGHT


#include <Servo.h>    
#define servoPin 4
Servo myservo;        
float steeringAngle;  

#define enA 5   
#define enB 6   


#define INa A0 
#define INb A1 
#define INc A2  
#define INd A3  

byte speedSetting = 0;  


void setup() {
    myservo.write(90);
  myservo.attach(servoPin);  

  pinMode(INa, OUTPUT);
  pinMode(INb, OUTPUT);
  pinMode(INc, OUTPUT);
  pinMode(INd, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);   


  Serial.begin(9600);
  Serial.println("Arduino Nano is Running"); 

  speedSetting = 255;
  motors(speedSetting, speedSetting); 
  Serial.print("Motor Speeds: ");
  Serial.println(speedSetting); 
}
 

void loop() {
delay(5000);
 goForwards();
 delay(35960);
 stopMotors();
delay(200000);

 
}


void motors(int leftSpeed, int rightSpeed) {


  analogWrite(enA, leftSpeed);
  analogWrite(enB, rightSpeed);
}

void moveSteering() {
  int maxAngle = 180;
  int minAngle = 0;
 
  for (steeringAngle = minAngle; steeringAngle <= maxAngle; steeringAngle += 5) {

    myservo.write(steeringAngle);   
    delay(15);                      
  }
  for (steeringAngle = maxAngle; steeringAngle >= -minAngle; steeringAngle -= 5) { 
    myservo.write(steeringAngle);   
    delay(15);                      
  }
}


void goForwards() {
  digitalWrite(INa, HIGH);
  digitalWrite(INb, LOW);
  digitalWrite(INc, HIGH);
  digitalWrite(INd, LOW);
}

void goBackwards() {
  digitalWrite(INa, LOW);
  digitalWrite(INb, HIGH);
  digitalWrite(INc, LOW);
  digitalWrite(INd, HIGH);
}

void goClockwise() {
  digitalWrite(INa, HIGH);
  digitalWrite(INb, LOW);
  digitalWrite(INc, LOW );
  digitalWrite(INd, HIGH);
}

void goAntiClockwise() {
  digitalWrite(INa, LOW);
  digitalWrite(INb, HIGH);
  digitalWrite(INc, HIGH);
  digitalWrite(INd, LOW);
}

void stopMotors() {
  digitalWrite(INa, LOW);
  digitalWrite(INb, LOW);
  digitalWrite(INc, LOW);
  digitalWrite(INd, LOW);
}