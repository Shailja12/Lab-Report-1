const int trigPin = 33;  
const int echoPin = 35;  
int angle = 0;  
int distance = 999;  
long duration;  
float distancecm;  
int leftMotor_speed, rightMotor_speed, servoAngle; 
#include <math.h>  
#include <MPU6050_tockn.h>  
#include <Wire.h>  
MPU6050 mpu6050(Wire);  
#define I2C_SLAVE_ADDR 0x04  
int x = 0;  

void setup()
{
  Serial.begin(9600);  
  Wire.begin();  
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);  
  mpu6050.begin();  
  mpu6050.calcGyroOffsets(true);  
  Serial.print("\tangleZ : ");  
  Serial.println(mpu6050.getAngleZ());  
}

void loop()
{
  //Forward 1 second
  leftMotor_speed = 150;
  rightMotor_speed = 150;
  servoAngle = 88;
  Transmit_to_arduino(leftMotor_speed, rightMotor_speed, servoAngle);  
  delay(1000);
  //stop
  leftMotor_speed = 0;
  rightMotor_speed = 0;
  servoAngle = 90;
  Transmit_to_arduino(leftMotor_speed, rightMotor_speed, servoAngle);  
  delay(1000);
    //Rotate 90 degrees
  leftMotor_speed = 250;
  rightMotor_speed = 100;
  servoAngle = 125;
  Transmit_to_arduino(leftMotor_speed, rightMotor_speed, servoAngle);  
  while (angle >= -85 ) {  
    angle = accelerometer(); 
  }
   //stop
  leftMotor_speed = 0;
  rightMotor_speed = 0;
   servoAngle = 90;
  Transmit_to_arduino(leftMotor_speed, rightMotor_speed, servoAngle);  
  delay(2500); 
 //Reverse and rotate 90 degrees
  leftMotor_speed = -100;
  rightMotor_speed = -250;
  servoAngle = 55;
  Transmit_to_arduino(leftMotor_speed, rightMotor_speed, servoAngle);  
  while (angle >= -165  ) {  
    angle = accelerometer();  
  }
  
   //stop
  leftMotor_speed = 0;
  rightMotor_speed = 0;
  servoAngle = 90;
  Transmit_to_arduino(leftMotor_speed, rightMotor_speed, servoAngle);  //transmit data to arduino
  delay(3000);

//reverse until 10cm away from wall
  leftMotor_speed = -100;
  rightMotor_speed = -100;
  servoAngle = 90;
  Transmit_to_arduino(leftMotor_speed, rightMotor_speed, servoAngle);
  do {
    distance = ultrasonic();
    delay(100);
  }
  while (distance >= 13);
  distance = 999;
 //stop
  leftMotor_speed = 0;
  rightMotor_speed = 0;
  servoAngle = 90;
  Transmit_to_arduino(leftMotor_speed, rightMotor_speed, servoAngle);
  delay(3000);
  
  leftMotor_speed = 100;
  rightMotor_speed = 250;
  servoAngle = 55;
  Transmit_to_arduino(leftMotor_speed, rightMotor_speed, servoAngle);
  while (angle <= -85 ) {
    angle = accelerometer();
  }
   //stop
  leftMotor_speed = 0;
  rightMotor_speed = 0;
  servoAngle = 90;
  Transmit_to_arduino(leftMotor_speed, rightMotor_speed, servoAngle);
  delay(5000);
 
    //stop
  leftMotor_speed = 0;
  rightMotor_speed = 0;
  servoAngle = 90;
  Transmit_to_arduino(leftMotor_speed, rightMotor_speed, servoAngle);
  delay(1000);
   //reverse until 10cm away from wall
  leftMotor_speed = -100;
  rightMotor_speed = -100;
  servoAngle = 90;
  Transmit_to_arduino(leftMotor_speed, rightMotor_speed, servoAngle);
  do {
    distance = ultrasonic();
    delay(100);
  }
  while (distance >= 13);
  distance = 999;
 //stop
  leftMotor_speed = 0;
  rightMotor_speed = 0;
  servoAngle = 90;
  Transmit_to_arduino(leftMotor_speed, rightMotor_speed, servoAngle);
  delay(50000);


}

void Transmit_to_arduino(int leftMotor_speed, int rightMotor_speed, int servoAngle)
{
  Wire.beginTransmission(I2C_SLAVE_ADDR); 
  Wire.write((byte)((leftMotor_speed & 0x0000FF00) >> 8));   
  Wire.write((byte)(leftMotor_speed & 0x000000FF));          
  Wire.write((byte)((rightMotor_speed & 0x0000FF00) >> 8));   
  Wire.write((byte)(rightMotor_speed & 0x000000FF));          
  Wire.write((byte)((servoAngle & 0x0000FF00) >> 8));        
  Wire.write((byte)(servoAngle & 0x000000FF)); 
  Wire.endTransmission();   // stop transmitting
}

//function to get angle from accelerometer
float accelerometer()
{
  mpu6050.update();  
  Serial.print("\tangleZ : "); 
  Serial.println(mpu6050.getAngleZ());  
  return mpu6050.getAngleZ();  
}

float ultrasonic()
{
  float distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  return (duration * 0.034 / 2);
}
