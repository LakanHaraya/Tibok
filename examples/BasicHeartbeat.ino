#include <Arduino.h>
#include <MuntingTibok.h>

MuntingTibok tibok(13, NORMAL);  // LED sa pin 13

void setup() {
    tibok.begin();  // Default: active HIGH
}

void loop() {
    tibok.update();
}