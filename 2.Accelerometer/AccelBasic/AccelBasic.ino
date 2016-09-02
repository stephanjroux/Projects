#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

void setup(void) 
{
  Serial.begin(115200);
  accel.begin();
  accel.setRange(ADXL345_RANGE_16_G);
}

int a,b,x,y;

void loop(void) 
{
  sensors_event_t event; 
  accel.getEvent(&event);
  y = event.acceleration.y;
  x = event.acceleration.x;
  Serial.print("X: "); Serial.print(x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(y); Serial.println("  ");
  delay(500);
}
