#include <FastLED.h>
#define UPDATES_PER_SECOND 100

const int NUM_LEDS = 100;
const int LED = 9;

CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  FastLED.addLeds<WS2812B, LED, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(100);
}

void loop() {
  if (Serial.available() > 0) {
    //   Serial.readBytes((char*) (&leds[idx]), 3);
    Serial.readBytes((char*)leds, NUM_LEDS * 3);
    FastLED.show();
  }
  delay(5);
}
