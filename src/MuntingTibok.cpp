#include "MuntingTibok.h"

MuntingTibok::MuntingTibok(int pin, HeartbeatLevel level) : _pin(pin), _level(level), _lastToggle(0), _state(false), _activeHigh(true), _enabled(true) {}

void MuntingTibok::begin(bool activeHigh) {
    _activeHigh = activeHigh;
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, _activeHigh ? LOW : HIGH);
}

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