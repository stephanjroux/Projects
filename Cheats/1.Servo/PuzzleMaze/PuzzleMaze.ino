#include <Servo.h>

Servo myservo1; 
Servo myservo2; 

int mid1 = 1180;
int mid2 = 1630;
int span = 100;
int xJoyPin = A6;
int yJoyPin = A5;
int servo1Pin = 2;
int servo2Pin = 3;
int xJoy, yJoy, goX, goY;

void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(0));
  myservo1.attach(servo1Pin); 
  myservo2.attach(servo2Pin); 
}

void loop() {
  xJoy = analogRead(xJoyPin); 
  yJoy = analogRead(yJoyPin);
  goX = map(xJoy,0,1023,mid1-span,mid1+span); 
  goY = map(yJoy,0,1023,mid2-span,mid2+span); 
  myservo1.writeMicroseconds(goX);
  myservo2.writeMicroseconds(goY);
  delay(10);

  /*
  Serial.print("PotX: ");
  Serial.print(xJoy);
  Serial.print(" X: ");
  Serial.print(goX);
  Serial.print(" PotY: ");
  Serial.print(yJoy);
  Serial.print(" Y: ");
  Serial.println(goY);
  */
  }
