/*
  DynamicHeartbeat.ino
  Pagpapalit ng tibok sa runtime gamit ang setLevel() method.

  Ipinapakita sa sketch na ito kung paano pabagu-baguhin ang tibok ng LED
  batay sa kondisyon o takdang oras. Sa kasong ito, nagpapalit ng antas ng
  tibok kada 5 segundo sa pagitan ng EMERGENCY (125ms) at WARNING (500ms)
  gamit ang `setLevel()` function.

  Author: Lakan Haraya Dima
  Date: 2025-04-11
*/

#include <Arduino.h>
#include <MuntingTibok.h>

// Gumamit ng NORMAL bilang panimulang tibok
MuntingTibok statusLED(13, NORMAL);

void setup() {
    // Simulan ang heartbeat (Active HIGH default)
    statusLED.begin();
}

void loop() {
    static unsigned long lastChange = 0;
    unsigned long now = millis();

    // Palitan ang tibok tuwing 5 segundo
    if (now - lastChange > 5000) {
        static bool toggle = false;
        statusLED.setLevel(toggle ? EMERGENCY : WARNING);
        toggle = !toggle;
        lastChange = now;
    }

    // Panatilihin ang tibok
    statusLED.update();
}
