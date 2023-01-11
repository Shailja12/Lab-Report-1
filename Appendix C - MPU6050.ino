
#include <MPU6050_tockn.h>
#include <Wire.h> 
int angle = 0;
MPU6050 mpu6050(Wire);

void setup() {
Serial.begin(9600);
Wire.begin();
mpu6050.begin();
mpu6050.calcGyroOffsets(true);
}

void loop() {
mpu6050.update();
Serial.print("\tangleX : ");
Serial.println(mpu6050.getAngleX());
Serial.print("\tangleY : ");
Serial.println(mpu6050.getAngleY());
Serial.print("\tangleZ : ");
Serial.println(mpu6050.getAngleZ());
}

