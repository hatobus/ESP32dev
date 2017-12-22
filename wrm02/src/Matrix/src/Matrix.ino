#include <Adafruit_NeoPixel.h>

int ledPin = 13;
int numPixels = 128;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numPixels, ledPin, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.show();
}

void loop() {
  int i, j = 0;
  for(j=0; j < 255; j++){
      
      for(i=0; i<pixels.numPixels(); i++) {
          pixels.setPixelColor(i, pixels.Color(255-j, j, 0));
          }
      
      //j++;
      pixels.show();
      delay(10);
  }
  delay(500);


  for(; j > 0; j--){
      
      for(i=0; i<pixels.numPixels(); i++) {
          pixels.setPixelColor(i, pixels.Color(255-j, j, 0));
          }
      
      //j--;
      pixels.show();
      delay(10);
  }
  delay(500);
}
