 int photoPin = 3;

 void setup() { 
   pinMode (photoPin,INPUT);
   Serial.begin (115200);
 } 

 void loop() { 
   Serial.println(digitalRead(photoPin));
   delay(100);
 } 