#include <Arduino.h>
#include <MuntingTibok.h>

MuntingTibok invertedLED(13, WARNING);

void setup() {
    invertedLED.begin(false);  // Active LOW
}

void loop() {
    invertedLED.update();
}
