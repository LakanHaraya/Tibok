#include <Arduino.h>
#include <MuntingTibok.h>

MuntingTibok heartLED(13, NORMAL);

void setup() {
    heartLED.begin();
}

void loop() {
    static unsigned long lastToggle = 0;
    unsigned long now = millis();

    if (now - lastToggle > 7000) {
        static bool isOn = true;
        if (isOn) heartLED.disable();
        else heartLED.enable();

        isOn = !isOn;
        lastToggle = now;
    }

    heartLED.update();
}