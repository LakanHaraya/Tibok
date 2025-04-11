/*
  EnableDisableHeartbeat.ino - Halimbawa para sa MuntingTibok Library
  Pagtikwas ng tibok gamit ang enable() at disable() methods.

  Ipinapakita sa sketch na ito kung paano pansamantalang itigil o ibalik
  ang heartbeat ng isang status LED sa pamamagitan ng `disable()` at `enable()`
  methods. Ang LED ay magpapahinga at babalik kada 7 segundo.

  Author: Lakan Haraya Dima
  Date: 2025-04-11
*/

#include <Arduino.h>
#include <MuntingTibok.h>

// LED na may NORMAL tibok (1000ms)
MuntingTibok heartLED(13, NORMAL);

void setup() {
    // Simulan ang heartbeat (Active HIGH default)
    heartLED.begin();
}

void loop() {
    static unsigned long lastToggle = 0;
    unsigned long now = millis();

    // I-toggle ang enable/disable tuwing 7 segundo
    if (now - lastToggle > 7000) {
        static bool isOn = true;

        if (isOn) {
            heartLED.disable();  // Patigilin ang tibok
        } else {
            heartLED.enable();   // Ibalik ang tibok
        }

        isOn = !isOn;
        lastToggle = now;
    }

    // Panatilihin ang tibok kung naka-enable
    heartLED.update();
}
