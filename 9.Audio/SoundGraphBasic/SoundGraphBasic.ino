void setup() 
{
   Serial.begin(115200);
}
 
void loop() 
{
   Serial.print("Mic: ");Serial.print(analogRead(6));
   Serial.println();
}
