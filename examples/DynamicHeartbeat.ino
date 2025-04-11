#include <Arduino.h>
#include <MuntingTibok.h>

MuntingTibok statusLED(13, NORMAL);

void setup() {
    statusLED.begin();
}

void loop() {
    static unsigned long lastChange = 0;
    unsigned long now = millis();

    if (now - lastChange > 5000) {
        static bool toggle = false;
        statusLED.setLevel(toggle ? EMERGENCY : WARNING);
        toggle = !toggle;
        lastChange = now;
    }

    statusLED.update();
}
