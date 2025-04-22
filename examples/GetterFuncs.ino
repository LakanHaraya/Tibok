#include <Arduino.h>
#include <Tibok.h>

const int statusPin = 13;  // Ang pin kung saan nakakabit ang status LED
Tibok tibok(statusPin, NORMAL, false);  // Gumagamit ng NORMAL na heartbeat level

// Variable na magtatago ng nakaraang estado ng pin
bool lastState = false;

void setup() {
    // Pag-enable ng tibok at pagpapakita ng kasalukuyang status
    tibok.enable();
    Serial.begin(115200);

    Serial.println("Sinimulan ang Tibok!");
    Serial.print("Pin: ");
    Serial.println(tibok.getPin());  // Ipapakita ang pin number

    // Pagpapakita ng kasalukuyang antas ng tibok at activeHigh status
    Serial.print("Kasalukuyang Antas ng Tibok: ");
    Serial.println(tibok.getHeartbeat());  // Ipapakita ang kasalukuyang antas ng tibok (teksto at numero)

    Serial.print("Aktibong Mataas: ");
    Serial.println(tibok.isActiveHigh() ? "OPO" : "HINDI PO");  // Ipapakita kung active high

    Serial.print("Pinagana Ba: ");
    Serial.println(tibok.isEnabled() ? "OPO" : "HINDI PO");  // Ipapakita kung enabled

    Serial.print("Kasalukuyang Estado: ");
    Serial.println(tibok.getState() ? "MATAAS" : "MABABA");  // Ipapakita ang kasalukuyang estado (HIGH o LOW)
}

void loop() {
    // I-update ang tibok status indicator
    tibok.update();

    // Kunin ang kasalukuyang estado mula sa tibok object
    bool currentState = tibok.getState();

    // I-check kung may pagbabago sa estado
    if (currentState != lastState) {
        // Kung may pagbabago, ipakita ang bagong estado sa Serial Monitor
        Serial.print("Kasalukuyang Estado: ");
        Serial.println(currentState ? "MATAAS" : "MABABA");

        // I-update ang lastState sa kasalukuyang estado
        lastState = currentState;
    }
}
