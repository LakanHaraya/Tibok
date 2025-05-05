#pragma once

#include <Arduino.h>

/**
 * @brief Konstruktor para sa Tibok class.
 * 
 * @param pin GPIO pin number kung saan nakakabit ang status indicator.
 * @param level Ang paunang antas ng pagtibok (heartbeat level). Default: `Tibok::NORMAL` (0.5Hz, 2s puktol).
 * @param activeHigh Tinutukoy kung active HIGH o LOW ang output (default: `true`).
 * @param enabled Kung awtomatikong papaganahin ang pagtibok (default: `true`).
 */
class Tibok {
    public:
        // Antas ng tibok
        enum HeartbeatLevel : uint16_t {
            EMERGENCY = 125,    /** @brief 4 Hz – 125ms bawat hatimpuktol (HIGH or LOW); 250ms kabuoang puktol.*/
            CRITICAL = 250,     /** @brief 2 Hz – 250ms bawat hatimpuktol; 500ms kabuoang puktol.*/
            WARNING = 500,      /** @brief 1 Hz – 500ms bawat hatimpuktol; 1s puktol.*/
            NORMAL = 1000       /** @brief 0.5 Hz – 1s bawat hatimpuktol; 2s puktol.*/
        };

        // Konstruktor
        Tibok(int pin, HeartbeatLevel level = Tibok::NORMAL, bool activeHigh = true, bool enabled = true);

        // Pangkilos
        void update();

        // Panakda
        Tibok& enable(bool enabled = true);
        Tibok& setActiveHigh(bool activeHigh = true);
        Tibok& setHeartbeat(HeartbeatLevel level = Tibok::NORMAL);

        // Panguha
        int getPin() const;
        String getLabel() const;
        bool isActiveHigh() const;
        bool isEnabled() const;
        bool getState() const;
        unsigned long getLastToggle() const;
        unsigned long getHeartbeat() const;
    
    private:
        int _pin;                   /**Ang GPIO pin na ginagamit para sa status inidcator.*/
        HeartbeatLevel _level;      /**Ang kasalukuyang heartbeat level (hatimpuktol ng tibok).*/
        unsigned long _lastToggle;  /**Panahon ng huling pagtikwas ng status indicator (millis). */
        bool _state;                /**Kasalukuyang estado ng status indicator: HIGH o LOW. */
        bool _activeHigh;           /**Tinutukoy kung active HIGH o LOW ang status indicator. */
        bool _enabled;              /**Nagpapahiwatig kung pinagana ang pagtibok. */

        void applyState();
};
