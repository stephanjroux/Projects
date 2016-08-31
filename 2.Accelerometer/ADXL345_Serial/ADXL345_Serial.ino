//Use Putty Term to get Clear Screen

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

void setup(void) 
{
  Serial.begin(115200);
  if(!accel.begin())
  {
    /* There was a problem detecting the ADXL345 ... check your connections */
    Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
    while(1);
  }
  accel.setRange(ADXL345_RANGE_16_G);
}

int a,b,x,y;

void loop(void) 
{
  sensors_event_t event; 
  accel.getEvent(&event);
  y = map(event.acceleration.x,-10,10,0,20);
  x = map(event.acceleration.y,-10,10,0,20);
  Serial.print("X: "); Serial.print(x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(y); Serial.println("  ");

  Serial.print("+");
  for (a=0; a<20; a++){Serial.print("-");}
  Serial.println("+");
  
  for (b=0; b<20; b++){
    Serial.print("|");
    for (a=0; a<20; a++){
      if (a==x && b==y){Serial.print("X");}
      else{Serial.print(" ");}
      }
    Serial.println("|");
    }
  
  Serial.print("+");
  for (a=0; a<20; a++){Serial.print("-");}
  Serial.println("+");
  delay(100);
  
  //Clear screen and go home
  Serial.write(27);       // ESC command
  Serial.print("[2J");    // clear screen command
  Serial.write(27);
  Serial.print("[H");     // cursor to home command

}
