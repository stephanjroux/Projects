#include <Adafruit_NeoPixel.h>

#include <SoftwareSerial.h>
 
#define DEBUG true
 
SoftwareSerial esp8266(2,3); // make RX Arduino line is pin 2, make TX Arduino line is pin 3.
                             // This means that you need to connect the TX line from the esp to the Arduino's pin 2
                             // and the RX line from the esp to the Arduino's pin 3

Adafruit_NeoPixel strip = Adafruit_NeoPixel(2, 5, NEO_GRB);

boolean toggle1, toggle2 = 0;

void setup()
{
  Serial.begin(57600);
  esp8266.begin(9600); // your esp's baud rate might be different
  
  strip.begin();
  strip.setBrightness(50);
  strip.setPixelColor(0 ,0,0,0);
  strip.setPixelColor(1 ,0,0,0);
  strip.show();

  sendData("AT+RST\r\n",2000,DEBUG); // reset module
  sendData("AT+CWMODE=2\r\n",1000,DEBUG); // configure as access point
  sendData("AT+CIFSR\r\n",1000,DEBUG); // get ip address
  sendData("AT+CIPMUX=1\r\n",1000,DEBUG); // configure for multiple connections
  sendData("AT+CIPSERVER=1,80\r\n",1000,DEBUG); // turn on server on port 80
}
 
void loop()
{
  if(esp8266.available()) // check if the esp is sending a message 
  {
    if(esp8266.find("+IPD,"))
    {
     delay(1000);
 
     int connectionId = esp8266.read()-48; // subtract 48 because the read() function returns 
                                           // the ASCII decimal value and 0 (the first decimal number) starts at 48
     if (esp8266.find("pin=")){
       int pinNumber = (esp8266.read()-48); 
       Serial.print("TOGGLE PIN !!! "); Serial.println((int)pinNumber);
       if ((int)pinNumber == 1){         toggle1 = !toggle1;         }
       if ((int)pinNumber == 2){         toggle2 = !toggle2;         }
       Serial.print("TOGGLE1 = "); Serial.println(toggle1);
       Serial.print("TOGGLE2 = "); Serial.println(toggle2);         
       if (toggle1){strip.setPixelColor(0 ,0,255,0);}
       else {strip.setPixelColor(0 ,0,0,0);}
       if (toggle2){strip.setPixelColor(1 ,255,0,0);}
       else {strip.setPixelColor(1 ,0,0,0);}
       strip.show();
       }
     
     String webpage = "<h1>Hello</h1><h2>World!</h2><a href='/&pin=1'>LED1</a><br><a href='/&pin=2'>LED2</a>";
 
     String cipSend = "AT+CIPSEND=";
     cipSend += connectionId;
     cipSend += ",";
     cipSend +=webpage.length();
     cipSend +="\r\n";
     
     sendData(cipSend,1000,DEBUG);
     sendData(webpage,2000,DEBUG);

     String closeCommand = "AT+CIPCLOSE="; 
     closeCommand+=connectionId; // append connection id
     closeCommand+="\r\n";
     
     sendData(closeCommand,3000,DEBUG);
    }
  }
}
 
 
String sendData(String command, const int timeout, boolean debug)
{
    String response = "";

    Serial.print(command);
    esp8266.print(command); // send the read character to the esp8266
    
    long int time = millis();
    
    while( (time+timeout) > millis())
    {
      while(esp8266.available())
      {
        
        // The esp has data so display its output to the serial window 
        char c = esp8266.read(); // read the next character.
        response+=c;
      }  
    }
        
    if(debug)
    {
      Serial.println(response);
    }
    
    return response;
}
