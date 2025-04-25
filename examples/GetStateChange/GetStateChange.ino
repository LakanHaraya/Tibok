#include <Arduino.h>
#include <Tibok.h>

Tibok statusLed(LED_BUILTIN, NORMAL);  // Gumamit ng built-in LED para sa demo
// Subukang palitan ang HEARTBEAT level sa WARNING o CRITICAL para sa iba't ibang mga epekto

unsigned int printCounter = 0;  // Counter para sa bilang ng mga pag-print
const unsigned int maxPrints = 10;  // Limitahan ang pag-print sa 10 beses para sa demo
bool lastState = LOW;  // I-save ang huling estado ng LED

void setup() {
    Serial.begin(115200);
    while (!Serial);  // Hintayin ang Serial monitor

    Serial.println(F("=== Tibok Getters Demo ==="));
    Serial.println(F("[Kasalukuyang Estado] | [Huling Tikwas]"));
}

void loop() {
    // Patuloy na ina-update ang estado ng LED (pagtibok)
    statusLed.update();

    // I-print lamang kung nagbago ang estado ng LED
    bool currentState = statusLed.getState();

    if (currentState != lastState && printCounter < maxPrints) {
        // I-print ang kasalukuyang estado (HIGH/LOW) at ang huling tikwas (sa ms)
        Serial.print(currentState ? F("HIGH") : F("LOW "));
        Serial.print(F(" | "));
        Serial.println(statusLed.getLastToggle());
        
        printCounter++;  // I-increment ang counter
        lastState = currentState;  // I-update ang last state
    }
}
