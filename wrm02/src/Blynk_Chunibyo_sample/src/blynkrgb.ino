#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Adafruit_NeoPixel.h>

char auth[] = "YOUR_auth_key";

char ssid[] = "YOUR_SSID";
char pass[] = "YOUR_PASS";

int ledPin = 13;
int numPixels = 128;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numPixels, ledPin, NEO_RGB + NEO_KHZ800);

int pinValue_red, pinValue_green, pinValue_Blue;

BLYNK_WRITE(V0){
  pinValue_red = param.asInt();
}

BLYNK_WRITE(V1){
  pinValue_green = param.asInt();
}

BLYNK_WRITE(V2){
  pinValue_Blue = param.asInt();
}
void setup()
{
  // Debug console
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pixels.begin();
  pixels.show();

}

void loop()
{
  Blynk.run();

  // Using Serial monitor to debug this code.
  Serial.print("Pin Red : ");
  Serial.println(pinValue_red);
  Blynk.virtualWrite(V3, pinValue_green);

  Serial.print("Pin Green : ");
  Serial.println(pinValue_green);
  Blynk.virtualWrite(V4, pinValue_red);
 
  Serial.print("Pin Blue : ");
  Serial.println(pinValue_Blue);
  Blynk.virtualWrite(V5, pinValue_Blue);

  // pixels LED
  for(int i=0; i<pixels.numPixels(); i++){
    pixels.setPixelColor(i, pixels.Color(pinValue_red, pinValue_green, pinValue_Blue));
}
  
  pixels.show();

  Serial.println("\n");
  delay(500);
}
