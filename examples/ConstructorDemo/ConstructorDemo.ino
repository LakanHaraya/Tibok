#include <Arduino.h>
#include <Tibok.h>

// Apat na magkakaibang setup ng Tibok
Tibok tibok2(2);  // level = NORMAL (default), activeHigh = true (default), enabled = true (default) 
Tibok tibok3(3, WARNING);  // activeHigh = true (default), enabled = true (default)
Tibok tibok4(4, CRITICAL, true); // enabled = true (default)
Tibok tibok5(5, EMERGENCY, true, true); 

void setup() {
    // Walang kailangang setup code bukod sa automatic constructor init
}

void loop() {
    // Patakbuhin ang update para sa bawat instance
    tibok2.update();
    tibok3.update();
    tibok4.update();
    tibok5.update();
}
