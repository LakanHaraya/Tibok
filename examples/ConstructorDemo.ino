#include <Arduino.h>
#include <Tibok.h>

const int statusPin = 13;
// === Subukan magtagkda ng mga halaga sa konstruktor ===
// Tibok objek(`pin`, `HeartbeatLevel`, `activeHigh`, `enabled`)
Tibok tibok(statusPin, WARNING, true, true);
// ======================================================

// Mga huling estado para sa comparison
int lastPin = -1;
String lastHeartbeat = "";
bool lastActiveHigh = false;
bool lastEnabled = false;
bool lastState = false;
unsigned long lastToggle = 0;

void setup() {
    Serial.begin(115200);
    Serial.println("Sinimulan ang Tibok!");
    Serial.print("[getPin] ");
    Serial.print(" [getHeartbeat] ");
    Serial.print(" [isActiveHigh] ");
    Serial.print(" [isEnabled] ");
    Serial.print(" [getState] ");
    Serial.println(" [getLastToggle] ");
}

void loop() {
    tibok.update();

    // I-collect ang kasalukuyang estado
    int currentPin = tibok.getPin();
    String currentHeartbeat = tibok.getHeartbeat();  // e.g., "NORMAL (1000)"
    bool currentActiveHigh = tibok.isActiveHigh();
    bool currentEnabled = tibok.isEnabled();
    bool currentState = tibok.getState();
    unsigned long currentToggle = tibok.getLastToggle();

    // I-print lang kapag may nagbago
    if (currentPin != lastPin ||
        currentHeartbeat != lastHeartbeat ||
        currentActiveHigh != lastActiveHigh ||
        currentEnabled != lastEnabled ||
        currentState != lastState ||
        currentToggle != lastToggle) {

        Serial.print("[");
        Serial.print(currentPin);
        Serial.print("] ["); 
        Serial.print(currentHeartbeat);
        Serial.print("] [");
        Serial.print(currentActiveHigh ? "OPO" : "HINDI PO");
        Serial.print("] [");
        Serial.print(currentEnabled ? "OPO" : "HINDI PO");
        Serial.print("] [");
        Serial.print(currentState ? "MATAAS" : "MABABA");
        Serial.print("] [");
        Serial.print(currentToggle);
        Serial.println("]");

        // I-update ang mga last states
        lastPin = currentPin;
        lastHeartbeat = currentHeartbeat;
        lastActiveHigh = currentActiveHigh;
        lastEnabled = currentEnabled;
        lastState = currentState;
        lastToggle = currentToggle;
    }
}
