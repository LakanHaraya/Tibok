#include <Arduino.h>
#include <Tibok.h>

Tibok statusLed(LED_BUILTIN, WARNING);  // Gumamit ng built-in LED para sa demo

void setup() {
    Serial.begin(115200);
    while (!Serial);  // Hintayin ang Serial monitor

    Serial.println("=== Tibok Getters Demo ===");

    Serial.print("Pin: ");
    Serial.println(statusLed.getPin());

    Serial.print("Tatak: ");
    Serial.println(statusLed.getLabel());

    Serial.print("Hatimpuktol (ms): ");
    Serial.println(statusLed.getHeartbeat()); 

    Serial.print("Aktibong Mataas: ");
    Serial.println(statusLed.isActiveHigh() ? "true" : "false");

    Serial.print("Pinagana: ");
    Serial.println(statusLed.isEnabled() ? "true" : "false");

    Serial.print("Kasalukuyang Estado (Nakasindi ba LED?): ");
    Serial.println(statusLed.getState() ? "HIGH" : "LOW");

    Serial.print("Huling Tikwas (ms): ");
    Serial.println(statusLed.getLastToggle());
}

void loop() {
    statusLed.update();
}
