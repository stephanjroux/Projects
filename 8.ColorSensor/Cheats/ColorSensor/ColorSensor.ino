#include <Adafruit_NeoPixel.h>

int NEO_PIN = 2;
int SW1 = 3;
int NUM_PIXELS = 4;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, NEO_PIN, NEO_GRB);

int val; 
int encoder0PinA = 5;
int encoder0PinB = 4;
int encoder0Pos = 0;
int encoder0PinALast = LOW;
int n = LOW;
int pixelPos = 0;

void setup()
{
  Serial.begin(115200); 
  pinMode(SW1, INPUT);
  pinMode (encoder0PinA,INPUT);
  pinMode (encoder0PinB,INPUT);
  
  strip.setBrightness(50);
  strip.begin();
  for (int a=0; a<4; a++){strip.setPixelColor(0 ,0,0,0);}
  strip.show();
}
 
 
void loop()
{
   n = digitalRead(encoder0PinA);
   if ((encoder0PinALast == LOW) && (n == HIGH)) {
     if (digitalRead(encoder0PinB) == LOW) {encoder0Pos--;} 
     else {encoder0Pos++;}
     Serial.print("PixPos\t");
     Serial.print(pixelPos);
     Serial.print("\tPotPos\t");
     Serial.println (encoder0Pos);
     } 
   encoder0PinALast = n;
   pixelPos = map(encoder0Pos,0,100,0,4);
   for (int a=0; a<pixelPos;a++){
     strip.setPixelColor(a ,0,0,255);
     }
   for (int b=pixelPos; b<NUM_PIXELS;b++){
     strip.setPixelColor(b ,0,0,0);
     }
   strip.show();
}
