//Use Putty Term to get Clear Screen

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ADXL345_U.h>
#include <Adafruit_SSD1306.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup(void) 
{
  Serial.begin(115200);
  accel.begin();
  accel.setRange(ADXL345_RANGE_16_G);
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.drawRect(0,0,128,32,WHITE);
  display.display();    
}

int x,y;

void loop(void) 
{
  x = map(accel.getX(),-50,50,0,128);
  y = map(accel.getY(),-50,50,32,0);
  
  display.drawRect(0,0,128,32,WHITE);
  display.drawLine(64, 0, 64, 10, WHITE);
  display.drawLine(64, 22, 64, 32, WHITE);
  display.drawLine(0, 16, 58, 16, WHITE);
  display.drawLine(70, 16, 128, 16, WHITE);
  
  display.fillCircle(x, y, 2, WHITE);
  display.display();    
  delay(10);
  display.clearDisplay();
}
