#ifndef MUNTINGTIBOK_H
#define MUNTINGTIBOK_H

#include <Arduino.h>

enum HeartbeatLevel {
    EMERGENCY = 125,
    CRITICAL = 250,
    WARNING = 500,
    NORMAL = 1000,
    DISABLED = -1
};

class MuntingTibok {
    private:
        int _pin;
        HeartbeatLevel _level;
        unsigned long _lastToggle;
        bool _state;
        bool _activeHigh;
        bool _enabled;
    
    public:
        MuntingTibok(int pin, HeartbeatLevel level);
        void begin(bool activeHigh = true);
        void update();
        void setLevel(HeartbeatLevel level);
        void disable();
        void enable();
    };

#endif