int inputPin = 3;
 
 void setup() { 
   pinMode (inputPin,INPUT_PULLUP);
   Serial.begin (115200);
 } 

 void loop() { 
      Serial.println(digitalRead(inputPin));
      delay(100);
      } 
