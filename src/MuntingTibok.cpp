#include "MuntingTibok.h"

/**
 * @brief Constructor implementation ng MuntingTibok.
 * 
 * Inilalagay ang mga default na value para sa internal state variables. 
 * Hindi pa itinatakda ang `pinMode()` dito — nangyayari iyon sa `begin()`.
 */
MuntingTibok::MuntingTibok(int pin, HeartbeatLevel level) : _pin(pin), _level(level), _lastToggle(0), _state(false), _activeHigh(true), _enabled(true) {}

/**
 * @brief Simulan ang output pin para sa LED at isinasaalang-alang ang `activeHigh` logic.
 */
void MuntingTibok::begin(bool activeHigh) {
    _activeHigh = activeHigh;
    pinMode(_pin, OUTPUT);
    // Itakda sa 'off' state batay sa logic level
    digitalWrite(_pin, _activeHigh ? LOW : HIGH);
}

/**
 * @brief Pinapatakbo ang alert logic batay sa napiling heartbeat level.
 * 
 * Kapag lampas na sa itinakdang tagal ng level, magtitikwas ang estado at
 * ipapakita sa status indicator.
 */
void MuntingTibok::update() {
    if (!_enabled || _level == DISABLED) return;

    unsigned long now = millis();
    if (now - _lastToggle >= (unsigned long)_level) {
        _lastToggle = now;
        _state = !_state;
        digitalWrite(_pin, _state == _activeHigh ? HIGH : LOW);
    }
}

void MuntingTibok::setLevel(HeartbeatLevel level) {
    _level = level;
}

void MuntingTibok::disable() {
    _enabled = false;
    digitalWrite(_pin, _activeHigh ? LOW : HIGH);
}

void MuntingTibok::enable() {
    _enabled = true;
}