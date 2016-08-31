#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, 6, NEO_GRB);

char blueToothVal;           //value sent over via bluetooth
char lastValue;              //stores last state of device (on/off)
 
void setup()
{
  strip.begin();
  strip.setBrightness(50);
  strip.show();

  Serial.begin(9600); 
 pinMode(13,OUTPUT);
}
 
 
void loop()
{
  if(Serial.available())
  {//if there is data being recieved
    blueToothVal=Serial.read(); //read it
  }
  if (blueToothVal=='R')
  {
    strip.setPixelColor(0 ,0,255,0);
  }
  else if (blueToothVal=='G')
  {
    strip.setPixelColor(0 ,255,0,0);
  }
  else if (blueToothVal=='B')
  {
    strip.setPixelColor(0 ,0,0,255);
  }
  else
  {
    strip.setPixelColor(0 ,0,0,0);
  }

  strip.show();
  delay(100);
}
