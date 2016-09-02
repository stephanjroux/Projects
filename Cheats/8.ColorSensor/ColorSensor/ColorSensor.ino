#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, 2, NEO_GRB);
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_24MS);

// 0:Red 1:Org 2:Grn 3:Pur 4:Yel 5:Off
int colors[6][3] = {
        {255,0,0},
        {237,162,40},
        {0,255,0},
        {152,40,237},        
        {237,237,40},
        {0,0,0},
    };        

int gotCol = 5;
        
void setup()
{
  tcs.begin();
  Serial.begin(115200); 
  strip.begin();
  strip.show();  
}
 
uint16_t  r,g,b,c,lux ;
int ir,ig,ib,ic,il;

void loop()
{
    strip.setPixelColor(0 ,0,0,0);
    strip.show();
    
    tcs.getRawData(&r, &g, &b, &c);
    lux = tcs.calculateLux(r, g, b);
    delay(100);
    
    ir = int(r);
    ig = int(g);
    ib = int(b);
    ic = int(c);
    il = int(lux);
    
    Serial.print("R: ");Serial.print(ir);
    Serial.print("\tG: ");Serial.print(ig);
    Serial.print("\tB: ");Serial.print(ib); 
    Serial.print("\tC: ");Serial.print(ic);
    Serial.print("\tLUX: ");Serial.print(il);
    Serial.println ();

    //Figure out colors 0:Red 1:Org 2:Grn 3:Pur 4:Yel 5:Off
    if ((ic<1200)&&(ir>ig)&&(ig>il)){gotCol=0;} //RED
    if (ir>600){
      if (ig>400){gotCol=4;}                    //YEL
      else {gotCol=1;}                          //ORG
        }
    if ((ig>500)&&(il>500)){gotCol=2;}          //GRN
    if ((ir<300)&&(ig<300)&&(ib<300)){gotCol = 5;} //OFF
    //if ((ir<400)&&(ig<400)&&(ib<400)&&(ic>800)&&(il<400)){gotCol = 3;} //PUR (Gave up)

    strip.setPixelColor(0 ,colors[gotCol][1],colors[gotCol][0],colors[gotCol][2]);
    strip.show();  
    delay(1000);
}
