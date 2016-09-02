int laserPin = 6;
int buzzerPin = 7;
int photoPin = A6;
int swPin = 2;
boolean armed = digitalRead(swPin);

void setup() {
  pinMode(laserPin,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  pinMode(swPin,INPUT_PULLUP);
  Serial.begin(115200);
  digitalWrite(laserPin,HIGH);
  digitalWrite(buzzerPin,LOW);
}

void loop() {
  Serial.print("Phoyto: ");  Serial.print(analogRead(photoPin));Serial.print("\tTouch: ");  Serial.print(digitalRead(swPin));
  Serial.println();
  delay(100);
  
  while ((digitalRead(swPin))&&(analogRead(photoPin)>100)){
    beep(1000);
    delay(300);
    }
}

void beep(int beepDur){
  digitalWrite(buzzerPin,HIGH);
  delay(beepDur);
  digitalWrite(buzzerPin,LOW);   
  }
