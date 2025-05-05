#include "Tibok.h"

// Private helper method para ipatupad ang kasalukuyang estado ng output pin.
void Tibok::applyState() {
    digitalWrite(_pin, (_enabled && _state == _activeHigh) ? HIGH : LOW);
}

// ---------------------------------------------------------------------------

// Konstruktor ng Tibok class na tumatanggap ng pin number, heartbeat level, active HIGH/LOW flag, at enabled flag.
Tibok::Tibok(int pin, HeartbeatLevel level, bool activeHigh, bool enabled) : _pin(pin), _level(level), _lastToggle(0), _state(false), _activeHigh(activeHigh), _enabled(enabled) {
    pinMode(_pin, OUTPUT);  // Itinatakda ang pin bilang output
    applyState();           // Itinatakda ang default state
}

// I-update ang estado ng status indicator batay sa kasalukuyang antas ng pagtibok (dapat ilagay sa loob ng `loop()`).
void Tibok::update() {
    if (!_enabled) return;

    unsigned long now = millis();
    if (now - _lastToggle >= (unsigned long)_level) {
        _lastToggle = now;
        _state = !_state;
        applyState();
    }
}

// Itinatakda ang estado ng pagtibok (enabled o disabled).
Tibok& Tibok::enable(bool enabled) {
    _enabled = enabled;
    applyState(); // I-reset ang estado ng pin ayon sa bagong logic level
    return *this; // Ibalik ang kasalukuyang object para sa chaining
}

// Itinatakda ang estado ng active HIGH o active LOW.
Tibok& Tibok::setActiveHigh(bool activeHigh) {
    _activeHigh = activeHigh;
    // I-reset ang estado ng pin ayon sa bagong logic level
    applyState();
    return *this; // Ibalik ang kasalukuyang object para sa chaining
}

// Itinatakda ang bagong heartbeat level at ina-update ang tagal ng pagtikwas.
Tibok& Tibok::setHeartbeat(HeartbeatLevel level) {
    _level = level;
    return *this; // Ibalik ang kasalukuyang object para sa chaining
}

// Kinukuha ang pin number ng status indicator.
int Tibok::getPin() const {
    return _pin;
}

// Kinukuha ang label ng kasalukuyang Heartbeat level.
String Tibok::getLabel() const {
    switch (_level) {
        case EMERGENCY:
            return F("KAGIPITAN");
        case CRITICAL:
            return F("KRITIKAL");
        case WARNING:
            return F("BABALA");
        case NORMAL:
            return F("NORMAL");
        default:
            return F("DI-KILALA");
    }
}

// Kinukuha ang estado ng active HIGH o active LOW.
bool Tibok::isActiveHigh() const {
    return _activeHigh;
}

// Kinukuha ang estado ng pagtibok (enabled o disabled).
bool Tibok::isEnabled() const {
    return _enabled;
}

// Kinukuha ang kasalukuyang estado ng status indicator.
bool Tibok::getState() const {
    return _state;
}

// Kinukuha ang huling tagal ng pagtikwas ng status indicator.
unsigned long Tibok::getLastToggle() const {
    return _lastToggle;
}

// Kinukuha ang numerical value ng napiling Heartbeat level.
unsigned long Tibok::getHeartbeat() const {
    return static_cast<unsigned long>(_level);
}