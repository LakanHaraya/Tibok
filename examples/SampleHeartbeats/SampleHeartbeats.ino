/*
  SampleHeartbeats.ino
  Simpleng paggamit ng lahat ng heartbeat na may Active HIGH logic.

  Ipinapakita sa sketch na ito ang iba't ibang uri ng `HeartbeatLevel`,
  kung saan ang bawat LED (sa pin 13 hanggang 8) ay tumitibok sa kaukulang 
  antas, na may default na Active HIGH logic (HIGH = ON).

  Author: Lakan Haraya Dima
  Date: 2025-08-17
*/

#include <Arduino.h>
#include <Tibok.h>

// Lumikha ng `Tibok` limbagay
Tibok led1(13, Tibok::EMERGENCY);
Tibok led2(12, Tibok::CRITICAL);
Tibok led3(11, Tibok::WARNING);
Tibok led5(10, Tibok::NORMAL);
Tibok led4(9, Tibok::STANDBY);

void setup() {
}

void loop() {
    // Panatilihin ang tibok
    led1.update();
    led2.update();
    led3.update();
    led4.update();
    led5.update();
}
