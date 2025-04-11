/**
 * @file MuntingTibok.h
 * @brief Header file para sa MuntingTibok library — isang simpleng heartbeat blinker.
 * 
 * Ang MuntingTibok library ay isang simpleng aklatan na nagbibigay ng
 * heartbeat signaling gamit ang LED o ibang indicator upang ipakita ang
 * operational status ng sistema.
 * Ito ay nagbibigay ng mga antas ng tibok batay sa antas ng kalubhaan, alinsunod sa IEC 60073:2002.
 * Gamitin ito sa mga embedded project upang makatulong sa diagnostics na
 * natatanaw, nadidinig, o nahahaplos (LED, buzzer, o vibration motor). 
 * 
 * @note Ito ay maaaring gamitin sa mga Arduino board at iba pang compatible na platform.
 * 
 * @author Lakan Haraya Dima
 * @date 2025-04-11
 * @version 1.0.0
 */

#pragma once

#include <Arduino.h>

/**
 * @enum HeartbeatLevel
 * @brief Mga nakatakdang antas ng alerto na tumutukoy sa bilis ng pagtibok.
 * 
 * Ang bawat antas ay tumutukoy sa antala (delay) sa milisegundo (ms) sa
 * pagitan ng pagtikwas ng indicator.
 */
enum HeartbeatLevel {
    EMERGENCY = 125,    /** 4 Hz – Napakabilis na tibok; maaaring indikasyon ng seryosong problema.*/
    CRITICAL = 250,     /** 2 Hz – Mabilis na tibok; senyales ng kritikal na kondisyon.*/
    WARNING = 500,      /** 1 Hz – Katamtamang tibok, may babala pero hindi malala.*/
    NORMAL = 1000,      /** 0.5 Hz – Mabagal na tibok, lahat ay nasa pangkaraniwang operasyon.*/
    DISABLED = -1       /** Walang tibok; Hindi pinapagana ang pagtibok.*/
};

/**
 * @class MuntingTibok
 * @brief Klase para sa heartbeat indicator.
 * 
 * Mainam gamitin para sa status indication, error signaling, o simpleng
 * visual heartbeat ng isang embedded system.
 */
class MuntingTibok {
    private:
        int _pin;                   /**Ang GPIO pin na ginagamit para sa status inidcator.*/
        HeartbeatLevel _level;      /**Ang kasalukuyang heartbeat level (frequency ng pagtibok).*/
        unsigned long _lastToggle;  /**Panahon ng huling pagtikwas ng status indicator (millis). */
        bool _state;                /**Kasalukuyang estado ng status indicator: HIGH o LOW. */
        bool _activeHigh;           /**Tinutukoy kung active HIGH o LOW ang status indicator. */
        bool _enabled;              /**Nagpapahiwatig kung pinagana ang pagtibok. */
    
    public:
        /**
         * @brief Konstruktor para sa MuntingTibok class.
         * 
         * @param pin GPIO pin number kung saan nakakabit ang status indicator.
         * @param level Ang paunang antas ng pagtibok (heartbeat level).
         */
        MuntingTibok(int pin, HeartbeatLevel level);

        /**
         * @brief Simulan ang MuntingTibok instance.
         * 
         * @param activeHigh Kung `true`, HIGH signal ang magsisindi sa
         * status indicator; kung `false`, LOW signal.
         * Default ay `true` (active HIGH).
         */
        void begin(bool activeHigh = true);

        /**
         * @brief Dapat tawagin sa loob ng `loop()` function upang i-update at
         * mapagana ang pagtikwas ng status indicator batay sa antas ng pagtibok.
         */
        void update();

        /**
         * @brief Itakda ang antas ng pagtibok (heartbeat level).
         * 
         * @param level Ang bagong antas ng pagtibok (heartbeat level).
         */
        void setLevel(HeartbeatLevel level);

        /**
         * @brief Pinapatigil ang pagtibok ng status indicator.
         */
        void disable();

        /**
         * @brief Pinapagana muli ang pagtibok ng status indicator.
         */
        void enable();
    };