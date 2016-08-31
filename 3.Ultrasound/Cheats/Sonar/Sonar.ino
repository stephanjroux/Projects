#include <NewPing.h>

#define TRIGGER_PIN  2
#define ECHO_PIN     3
#define MAX_DISTANCE 200  // Maximum distance in cms - max 400

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
 
int buzzer = 8 ;
unsigned long lastPingTime, lastBeepTime;
int pingPause = 50;
int beepDuration = 500;
int pingVal = 0;
int beepPause = 500;

void setup ()
{
  Serial.begin(115200); 
  pinMode (buzzer, OUTPUT) ;
  lastPingTime = lastBeepTime = millis();
}
void loop ()  {
  if (millis() - lastPingTime > pingPause){
    pingVal = sonar.ping_cm();
    Serial.print("Ping: ");
    Serial.print(pingVal); 
    Serial.println("cm");
    lastPingTime = millis();
    }
  
  
  if (millis() - lastBeepTime > (pingVal*30)){
    digitalWrite(buzzer,HIGH);
    delay(pingVal/10);
    digitalWrite(buzzer,LOW);
    delay(pingVal/10);    
    if (millis() - lastBeepTime > ((pingVal*30) + beepDuration)){
      lastBeepTime = millis();
      }
    }
}
