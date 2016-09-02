#include <NewPing.h>

#define TRIGGER_PIN  2
#define ECHO_PIN     3
#define MAX_DISTANCE 200  // Maximum distance in cms - max 400

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
 
int pingVal = 0;

void setup (){
  Serial.begin(115200); 
  }
  
void loop ()  {
  pingVal = sonar.ping_cm();
  Serial.print("Ping: ");
  Serial.print(pingVal); 
  Serial.println("cm");
  }
