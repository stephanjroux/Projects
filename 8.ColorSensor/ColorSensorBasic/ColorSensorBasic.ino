#include <Wire.h>
#include <Adafruit_TCS34725.h>

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_24MS);

byte gammatable[256];

void setup(){
      tcs.begin();
      Serial.begin(115200); 

      // thanks PhilB for this gamma table!
      // it helps convert RGB colors to what humans see
      for (int i=0; i<256; i++) {
            float x = i;
            x /= 255;
            x = pow(x, 2.5);
            x *= 255;
            gammatable[i] = x;      
            }
      }
 
void loop()
{
  uint16_t clear, red, green, blue;
  tcs.getRawData(&red, &green, &blue, &clear);
  
  // Figure out some basic hex code for visualization
  uint32_t sum = clear;
  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;

  Serial.print("C:\t"); Serial.print(clear);
  Serial.print("\tR:\t"); Serial.print(gammatable[(int)r]);
  Serial.print("\tG:\t"); Serial.print(gammatable[(int)g]);
  Serial.print("\tB:\t"); Serial.println(gammatable[(int)b]);

  delay(150);
}
