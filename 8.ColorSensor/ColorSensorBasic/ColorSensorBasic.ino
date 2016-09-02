#include <Wire.h>
#include <Adafruit_TCS34725.h>

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_24MS);

void setup()
{
  tcs.begin();
  Serial.begin(115200); 
  digitalWrite(9,HIGH);  
}
 
uint16_t  r,g,b,c,lux ;
 
void loop()
{
    tcs.getRawData(&r, &g, &b, &c);
    lux = tcs.calculateLux(r, g, b);

    Serial.print("R: ");Serial.print(r);Serial.print("\tG: ");Serial.print(g);Serial.print("\tB: ");Serial.print(b); Serial.print("\tC: ");Serial.print(c);Serial.print("\tLUX: ");Serial.print(lux);
    Serial.println ();
    delay(200);
}
