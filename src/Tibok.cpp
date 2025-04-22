#include "Tibok.h"

/**
 * @brief Konstruktor para sa Tibok class.
 * 
 * @param pin GPIO pin number kung saan nakakabit ang status indicator.
 * @param level Ang paunang antas ng pagtibok (heartbeat level).
 * @param activeHigh Tinutukoy kung active HIGH o LOW ang output (default: `true`).
 * @param enabled Kung awtomatikong papaganahin ang pagtibok (default: `true`).
 */
Tibok::Tibok(int pin, HeartbeatLevel level, bool activeHigh, bool enabled) : _pin(pin), _level(level), _lastToggle(0), _state(false), _activeHigh(activeHigh), _enabled(enabled) {
    pinMode(_pin, OUTPUT);                          // Itinatakda ang pin bilang output
    digitalWrite(_pin,(_enabled && _state == _activeHigh) ? HIGH : LOW);   // Itinatakda ang default state
}

/**
 * @brief Pinapatakbo ang alert logic batay sa napiling heartbeat level.
 * 
 * Kapag lampas na sa itinakdang tagal ng level, magtitikwas ang estado at
 * ipapakita sa status indicator.
 */
void Tibok::update() {
    if (!_enabled) return;

    unsigned long now = millis();
    if (now - _lastToggle >= (unsigned long)_level) {
        _lastToggle = now;
        _state = !_state;
        digitalWrite(_pin, _state == _activeHigh ? HIGH : LOW);
    }
}

void Tibok::setHeartbeat(HeartbeatLevel level) {
    _level = level;
}

void Tibok::disable() {
    _enabled = false;
    digitalWrite(_pin, _activeHigh ? LOW : HIGH);
}

void Tibok::enable() {
    _enabled = true;
}

void Tibok::setActiveHigh(bool activeHigh) {
    _activeHigh = activeHigh;
    // I-reset ang estado ng pin ayon sa bagong logic level
    digitalWrite(_pin, _state == _activeHigh ? HIGH : LOW);
}

int Tibok::getPin() const {
    return _pin;
}

String Tibok::getHeartbeat() const {
    switch (_level) {
        case EMERGENCY:
            return String("KAGIPITAN (125ms bawat tibok)");
        case CRITICAL:
            return String("KRITIKAL (250ms bawat tibok)");
        case WARNING:
            return String("BABALA (500ms bawat tibok)");
        case NORMAL:
            return String("NORMAL (1000ms bawat tibok)");
        default:
            return String("HINDI TINAKDA (hindi wastong antas)");
    }
}

bool Tibok::isActiveHigh() const {
    return _activeHigh;
}

bool Tibok::isEnabled() const {
    return _enabled;
}

bool Tibok::getState() const {
    return _state;
}

unsigned long Tibok::getLastToggle() const {
    return _lastToggle;
}
