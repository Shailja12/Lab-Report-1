// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //

#define echoPin 22 
#define trigPin 23
#define led 25

long duration;
int distance; 

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(led, OUTPUT);
  Serial.begin(115200); 
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); 
  Serial.println("with Arduino UNO R3");
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin, HIGH);
  if (distance < 10)
  {
     digitalWrite(led,HIGH);
     delay(25);
     digitalWrite(led,LOW);
     delay(25);
     
     digitalWrite(led,HIGH);
     delay(25);
     digitalWrite(led,LOW);
     delay(25);
  }

else if ((distance >= 10) && (distance <= 20) )
{ 
digitalWrite(led,HIGH);
     delay(100);
     digitalWrite(led,LOW);
     delay(100);
     digitalWrite(led,HIGH);
     delay(100);
     digitalWrite(led,LOW);
     delay(100);

}   
else if ((distance > 20) && (distance <= 30) ) 
   { 
digitalWrite(led,HIGH);
     delay(300);
     digitalWrite(led,LOW);
     delay(300);
     digitalWrite(led,HIGH);
     delay(300);
     digitalWrite(led,LOW);
     delay(300);

 }
else 
  digitalWrite(led,LOW);

  distance = duration * 0.034 / 2; 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}