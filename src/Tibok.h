#pragma once

#include <Arduino.h>

/**
 * @brief Konstruktor para sa Tibok class.
 * 
 * @param pin GPIO pin number kung saan nakakabit ang status indicator.
 * @param level Ang paunang antas ng pagtibok (heartbeat level). Default: `Tibok::STANDBY` (Mabugsong 0.5Hz, 2s puktol).
 * @param activeHigh Tinutukoy kung active HIGH o LOW ang output (default: `true`).
 * @param enabled Kung awtomatikong papaganahin ang pagtibok (default: `true`).
 */
class Tibok {
    public:
        // Antas ng tibok
        enum HeartbeatLevel : uint8_t {
            EMERGENCY,  // Karaniwang 4Hz
            CRITICAL,   // Karaniwang 2Hz
            WARNING,    // Karaniwang 1Hz
            NOTICE,     // Karaniwang 0.5Hz
            STANDBY,    // Mabugsong 0.5Hz na may 2 tibok (4 na tikwas), pagkatapos ay 1s pagtigil
            NORMAL      // Matatag nakaSINDI
        };

        // Konstruktor
        Tibok(int pin, HeartbeatLevel level = Tibok::STANDBY, bool activeHigh = true, bool enabled = true);

        // Pangkilos
        void update();

        // Pantakda
        Tibok& enable(bool enabled = true);
        Tibok& setActiveHigh(bool activeHigh = true);
        Tibok& setHeartbeat(HeartbeatLevel level = Tibok::STANDBY);

        // Pangkuha
        int getPin() const;
        String getLabel() const;
        bool isActiveHigh() const;
        bool isEnabled() const;
        bool getState() const;
        unsigned long getLastToggle() const;
    
    private:
        int _pin;                   /**Ang GPIO pin na ginagamit para sa status inidcator.*/
        HeartbeatLevel _level;      /**Ang kasalukuyang heartbeat level (hatimpuktol ng tibok).*/
        unsigned long _lastToggle;  /**Panahon ng huling pagtikwas ng status indicator (millis). */
        bool _state;                /**Kasalukuyang estado ng status indicator: HIGH o LOW. */
        bool _activeHigh;           /**Tinutukoy kung active HIGH o LOW ang status indicator. */
        bool _enabled;              /**Nagpapahiwatig kung pinagana ang pagtibok. */
        uint8_t _emergencyPhase = 0; /**Bagong internal state tracker para sa EMERGENCY */

        void _applyState();
        void _toggle();
        void _updateWithInterval(unsigned long now, uint16_t interval);
        void _ensureOn();
        void _updateStandby(unsigned long now);
};
