/*
  BasicHeartbeat.ino
  Simpleng paggamit ng default heartbeat na may Active HIGH logic.

  Ipinapakita sa sketch na ito ang pinakapangunahing gamit ng MuntingTibok library,
  kung saan ang isang LED (sa pin 13) ay tumitibok gamit ang default na "NORMAL"
  na antas (1000ms interval), na may Active HIGH logic (HIGH = ON).

  Author: Lakan Haraya Dima
  Date: 2025-04-11
*/

#include <Arduino.h>
#include <MuntingTibok.h>

// Lumikha ng MuntingTibok object sa pin 13 na may NORMAL tibok (1000ms)
MuntingTibok tibok(13, NORMAL);

void setup() {
    // Simulan ang tibok gamit ang default na active HIGH logic
    tibok.begin();
}

void loop() {
    // Panatilihin ang tibok
    tibok.update();
}
