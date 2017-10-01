void setup() 
{
   Serial.begin(115200);
}
 
void loop() 
{
      int val = analogRead(A6);
      Serial.print("Mic: "); Serial.print(val);Serial.print(" "); 
      for (int x=500; x<val;x++) Serial.print(".");
      Serial.println();
      delay(20);
}
