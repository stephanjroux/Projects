#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();
 
const int maxScale = 8;
const int redZone = 6;
 
const int cycleDelay = 100;

unsigned int signalMax = 900;
unsigned int signalMin = 100;


void setup() 
{
   Serial.begin(115200);
   matrix.begin(0x70);  // pass in the address
   Serial.println("Test Serial");
}
 
 
void loop() 
{
   unsigned int sampleTot = 0;  
  
   int getSample = analogRead(A0);
   Serial.print("Max: ");Serial.print(signalMax);Serial.print("\tMin: ");Serial.print(signalMin);Serial.print("\tAverage: ");Serial.print(getSample);
   Serial.println();

   int displayPeak = map(getSample, signalMin, signalMax, 0, maxScale);
 
   // Update the display:
   for (int i = 0; i < 7; i++)  // shift the display left
   {
      matrix.displaybuffer[i] = matrix.displaybuffer[i+1];
   }
 
   for (int i = 0; i <= maxScale; i++)
   {
      if (i >= displayPeak)  // blank these pixels
      {
         matrix.drawPixel(i, 7, 0);
      }
      else if (i < redZone) // draw in green
      {
         matrix.drawPixel(i, 7, LED_GREEN);
      }
      else // Red Alert!  Red Alert!
      {
         matrix.drawPixel(i, 7, LED_RED);
      }
   }
   matrix.writeDisplay();  // write the changes we just made to the display
   delay(cycleDelay);
}
