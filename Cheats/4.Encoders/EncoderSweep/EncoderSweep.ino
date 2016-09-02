#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, 2, NEO_GRB);

 int val; 
 int encoder0PinA = 5;
 int encoder0PinB = 4;
 int encoder0Pos = 0;
 int encoder0PinALast = LOW;
 int n = LOW;
 int ledSweep = 0;
 
 void setup() { 
  pinMode (encoder0PinA,INPUT);
  pinMode (encoder0PinB,INPUT);
    
  strip.setBrightness(50);
  strip.begin();
  for (int a=0; a<4; a++){strip.setPixelColor(0 ,0,0,0);}
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
     ledSweep = (int)(encoder0Pos /10);
     if (ledSweep > 4){ledSweep = 4;}
     for (int a = 0;a<ledSweep;a++){strip.setPixelColor(a ,255,0,0);}
     for (int b=ledSweep; b<4; b++){strip.setPixelColor(b ,0,0,0);}
     strip.show();
     Serial.print(encoder0Pos);Serial.print("\t");Serial.print(ledSweep);
     Serial.println();
   } 
   encoder0PinALast = n;
 } 

