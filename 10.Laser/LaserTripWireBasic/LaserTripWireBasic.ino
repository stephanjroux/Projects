int laserPin = 6;
int photoPin = A6;

void setup() {
  pinMode(laserPin,OUTPUT);
  Serial.begin(115200);
  digitalWrite(laserPin,HIGH);
}

void loop() {
  Serial.print("Photo: ");  Serial.print(analogRead(photoPin));
  Serial.println();
  delay(100);
}


