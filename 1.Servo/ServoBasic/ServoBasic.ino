#include <Servo.h> 
 
Servo myservo;
 
int pos = 0;  
 
void setup() 
{ 
  myservo.attach(11); 
} 
 
void loop() 
{ 
  if (pos == 0){pos=180;}else{pos=0;}
  myservo.write(pos);  
  delay(1000);          
} 

