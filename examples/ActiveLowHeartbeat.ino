/*
  ActiveLowHeartbeat.ino
  Gamit ang Active LOW configuration ng LED.

  Ang sketch na ito ay nagpapakita kung paano gamitin ang MuntingTibok library
  upang makontrol ang isang LED na may Active LOW logic. Sa halimbawang ito,
  ang LED ay kikilos sa pattern ng "WARNING" heartbeat (500ms interval).
  
  Author: Lakan Haraya Dima
  Date: 2025-04-11
*/

#include <Arduino.h>
#include <MuntingTibok.h>

// Lumikha ng MuntingTibok object para sa pin 13.
// Ang 'WARNING' ay tumutukoy sa 500ms na interval.
MuntingTibok invertedLED(13, WARNING);

void setup() {
    // I-configure ang LED bilang Active LOW.
    // Kapag true: HIGH = ON
    // Kapag false: LOW = ON (karaniwan sa built-in LED sa ilang Arduino boards)
    invertedLED.begin(false); 
}

void loop() {
    // Tawagin ito sa bawat ikot ng loop upang panatilihin ang tibok.
    invertedLED.update();
}