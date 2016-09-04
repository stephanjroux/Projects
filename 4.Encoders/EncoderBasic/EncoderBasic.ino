
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, 2, NEO_GRB);

 int encoder0PinA = 5;
 int encoder0PinB = 4;
 int encoder0Pos = 0;
 int encoder0PinALast = LOW;
 int n = LOW;

 void setup() { 
  pinMode (encoder0PinA,INPUT);
  pinMode (encoder0PinB,INPUT);
   
  strip.setBrightness(20);
  strip.begin();
  strip.setPixelColor(0 ,255,0,0);  
  strip.setPixelColor(1 ,0,0,0);  
  strip.setPixelColor(2 ,0,0,0);  
  strip.setPixelColor(3 ,0,0,0);    
  strip.show();
   
  Serial.begin (115200);
 } 

 void loop() { 
   n = digitalRead(encoder0PinA);
   if ((encoder0PinALast == LOW) && (n == HIGH)) {
     if (digitalRead(encoder0PinB) == LOW) {
       if (encoder0Pos>0){encoder0Pos--;}
     } else {
       encoder0Pos++;
     }
     Serial.print("EncoderPos\t");Serial.print(encoder0Pos);
     Serial.println();
   } 
   encoder0PinALast = n;
 } 
