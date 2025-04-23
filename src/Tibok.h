/**
 * @file Tibok.h
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
 * 
 * @enum HeartbeatLevel
 * @brief Mga antas ng tibok na naaayon sa antas ng kalubhaan, alinsunod sa IEC 60073:2002.
 *
 * Ang bawat halaga ay kumakatawan sa delay sa milisegundo (ms) sa pagitan ng pag-toggle
 * ng indicator gaya ng LED, buzzer, o vibration motor. Ginagamit ito upang magpakita
 * ng operasyonal o alertong estado ng sistema.
 *
 */
enum HeartbeatLevel {
    EMERGENCY = 125,    /** @brief 4 Hz – Napakabilis na tibok; maaaring indikasyon ng seryosong problema.*/
    CRITICAL = 250,     /** @brief 2 Hz – Mabilis na tibok; senyales ng kritikal na kondisyon.*/
    WARNING = 500,      /** @brief 1 Hz – Katamtamang tibok, may babala pero hindi malala.*/
    NORMAL = 1000       /** @brief 0.5 Hz – Mabagal na tibok, lahat ay nasa pangkaraniwang operasyon.*/
};

/**
 * @class Tibok
 * @brief Klase para sa heartbeat indicator.
 * 
 * Mainam gamitin para sa status indication, error signaling, o simpleng
 * visual heartbeat ng isang embedded system.
 */

/**
 * @brief Konstruktor para sa Tibok class.
 * 
 * @param pin GPIO pin number kung saan nakakabit ang status indicator.
 * @param level Ang paunang antas ng pagtibok (heartbeat level).
 * @param activeHigh Tinutukoy kung active HIGH o LOW ang output (default: `true`).
 * @param enabled Kung awtomatikong papaganahin ang pagtibok (default: `true`).
 * 
 * ### Halimbawa ng Paggamit:
 * ``` cpp
 * // Gumamit ng LED sa pin 13, CRITICAL ang tibok, active HIGH, at awtomatikong pinagana.
 * Tibok statusLED(13, CRITICAL);
 * 
 * // Gumamit ng custom configuration: active LOW at hindi agad pinagana.
 * Tibok silentIndicator(12, WARNING, false, false);
 * ```
 */
class Tibok {
    private:
        int _pin;                   /**Ang GPIO pin na ginagamit para sa status inidcator.*/
        HeartbeatLevel _level;      /**Ang kasalukuyang heartbeat level (frequency ng pagtibok).*/
        unsigned long _lastToggle;  /**Panahon ng huling pagtikwas ng status indicator (millis). */
        bool _state;                /**Kasalukuyang estado ng status indicator: HIGH o LOW. */
        bool _activeHigh;           /**Tinutukoy kung active HIGH o LOW ang status indicator. */
        bool _enabled;              /**Nagpapahiwatig kung pinagana ang pagtibok. */
    
    public:
        Tibok(int pin, HeartbeatLevel level, bool activeHigh = true, bool enabled = true);

        /**
         * @brief Dapat tawagin sa loob ng `loop()` function upang i-update at
         * mapagana ang pagtikwas ng status indicator batay sa antas ng pagtibok.
         */

        /**
         * 
         * @brief Ina-update ang estado ng status indicator batay sa tibok.
         * 
         * Dapat tawagin sa loob ng `loop()` function ng sketch upang mapanatili
         * ang tamang pagtikwas (toggling) ng indicator. Gumagana ito batay sa kasalukuyang
         * itinakdang `HeartbeatLevel` at sa pinakahuling oras na na-update.
         * 
         * Kung ang heartbeat ay naka-disable (`enabled` = false), walang tikwas na magaganap.
         *
         * ### Halimbawa ng Paggamit:
         * ``` cpp
         * Tibok heartbeatLED(13, NORMAL);
         * void loop() {
         *     // Panatilihing buhay ang tibok
         *     heartbeatLED.update();
         * }
         * ```
         */
        void update();

        /**
         * @brief Itakda ang antas ng pagtibok (heartbeat level).
         * 
         * Pinapahintulutan ang pagbabago ng dalas ng pagtikwas ng status indicator habang
         * tumatakbo ang programa. Mainam itong gamitin upang magpahiwatig ng pagbabago sa
         * estado ng system tulad ng babala, error, o normal na operasyon.
         * 
         * @param level Ang bagong antas ng pagtibok (heartbeat level), gaya ng `NORMAL`, `WARNING`, `CRITICAL`, o `EMERGENCY`.
         * 
         * ### Halimbawa ng Paggamit:
         * ``` cpp
         * Tibok statusLED(13, NORMAL);
         * void someConditionHandler() {
         *     // Kapag may natuklasang error
         *     statusLED.setHeartbeat(CRITICAL);
         * }
         * ```
         */
        void setHeartbeat(HeartbeatLevel level);

        /**
         * 
         * @brief Pinapatigil ang pagtibok ng status indicator.
         * 
         * Kapaki-pakinabang kung nais mong ihinto pansamantala ang visual feedback mula sa LED
         * o iba pang indicator, halimbawa sa panahon ng low-power mode o maintenance. Hindi nito
         * binubura ang kasalukuyang antas ng tibok; maaari itong ipagpatuloy gamit ang `enable()`.
         * 
         * ### Halimbawa ng Paggamit:
         * ``` cpp
         * Tibok statusLED(13, NORMAL);
         * void enterLowPowerMode() {
         *     statusLED.disable(); // Itigil ang pagtikwas habang naka-low power
         * }
         * ```
         */
        void disable();

        /**
         * 
         * @brief Pinapagana muli ang pagtibok ng status indicator.
         * 
         * Kapag tinawag, muling sisimulan ang pagtibok (blinking) ng status indicator batay sa
         * huling itinakdang antas ng tibok. Mainam gamitin pagkatapos ng `disable()` kung kailan
         * kailangang ipagpatuloy ang visual feedback.
         * 
         * ### Halimbawa ng Paggamit:
         * ``` cpp
         * Tibok statusLED(13, NORMAL);
         * void resumeFromSleep() {
         *     statusLED.enable(); // Ipagpatuloy ang pagtibok matapos ang pagtigil
         * }
         * ```
         */
        void enable();

        /**
         * @brief Itinatakda kung ang status indicator ay active-HIGH o active-LOW.
         * 
         * Pinapayagan nitong baguhin sa runtime kung paanong pinapatakbo ang status LED
         * o anumang output indicator—kung HIGH (`true`) o LOW (`false`) ang nagpapagana rito.
         * Kapaki-pakinabang kung gumagamit ng iba’t ibang uri ng hardware (e.g., common cathode vs. anode).
         * 
         * @param activeHigh Kung `true`, active-HIGH ang output (default behavior); kung `false`, active-LOW.
         * 
         * ### Halimbawa ng Paggamit:
         * ``` cpp
         * Tibok indicator(12, WARNING);    // Default sa active HIGH
         * void setup() {
         *     // Baguhin sa active-LOW kung gumagamit ng inverted logic LED
         *     indicator.setActiveHigh(false);
         * }
         * ```
         */
        void setActiveHigh(bool activeHigh);

        /**
         *
         * @brief Kinukuha ang kasalukuyang GPIO pin number ng status indicator.
         * 
         * Makakatulong ito sa pag-debug o kapag kailangan muling gamitin ang pin number
         * para sa ibang bahagi ng system configuration o diagnostic output.
         * 
         * @return `int` Ang GPIO pin number na kasalukuyang ginagamit ng Tibok instance.
         * 
         * ### Halimbawa ng Paggamit:
         * ``` cpp
         * Tibok indicator(13, NORMAL);
         * void setup() {
         *     Serial.begin(9600);
         *     Serial.print("Gumagamit ng pin: ");
         *     Serial.println(indicator.getPin());
         * }
         * ```
         */
        int getPin() const;

        /**
         * 
         * @brief Kinukuha ang kasalukuyang antas ng pagtibok (heartbeat level) bilang isang human-readable na string.
         * 
         * Ibinabalik nito ang isang string na naglalarawan ng kasalukuyang antas ng tibok, tulad ng "NORMAL", "WARNING", "CRITICAL", o "EMERGENCY",
         * kasama ang katumbas nitong delay sa millisecond (ms). Magagamit ito para sa diagnostics o para ipakita ang status ng sistema.
         * 
         * @return `String` Isang string na naglalarawan ng kasalukuyang heartbeat level at ang katumbas nitong delay.
         * 
         * ### Halimbawa ng Paggamit:
         * ``` cpp
         * Tibok indicator(13, WARNING);
         * void setup() {
         *     Serial.begin(9600);
         *     Serial.print("Kasalukuyang heartbeat: ");
         *     Serial.println(indicator.getHeartbeat());
         * }
         * ```
         */
        String getHeartbeat() const;

        /**
         * @brief Kinukuha kung ang status indicator ay naka-activate sa HIGH logic level.
         * 
         * Ibinabalik nito ang `true` kung ang indicator ay naka-activate sa HIGH logic level (active HIGH),
         * at `false` naman kung ito ay naka-activate sa LOW logic level (active LOW).
         * 
         * @return `bool` `true` kung active HIGH ang status indicator, `false` kung active LOW.
         * 
         * ### Halimbawa ng Paggamit:
         * ``` cpp
         * Tibok indicator(13, NORMAL, true);
         * void setup() {
         *     Serial.begin(9600);
         *     if (indicator.isActiveHigh()) {
         *         Serial.println("Active HIGH ang status indicator.");
         *     } else {
         *         Serial.println("Active LOW ang status indicator.");
         *     }
         * }
         * ```
         */
        bool isActiveHigh() const;

        /**
         * @brief Kinukuha kung ang pagtibok ng status indicator ay pinagana o hindi.
         * 
         * Ibinabalik nito ang `true` kung ang pagtibok ng status indicator ay pinagana,
         * at `false` kung ito ay pinatigil.
         * 
         * @return `bool` `true` kung ang pagtibok ay pinagana, `false` kung ito ay pinatigil.
         * 
         * ### Halimbawa ng Paggamit:
         * ``` cpp
         * Tibok indicator(13, NORMAL);
         * void setup() {
         *     Serial.begin(9600);
         *     if (indicator.isEnabled()) {
         *         Serial.println("Pinagana ang pagtibok.");
         *     } else {
         *         Serial.println("Pinatigil ang pagtibok.");
         *     }
         * }
         * ```
         */
        bool isEnabled() const;

        /**
         * @brief Kinukuha ang kasalukuyang estado ng status indicator.
         * 
         * Ibinabalik nito ang `true` kung ang status indicator ay nasa `HIGH` state,
         * at `false` kung ito ay nasa `LOW` state. Ang estado ng indicator ay batay sa
         * kasalukuyang status ng pagtibok ayon sa antas ng alerto at kung ito ay pinagana.
         * 
         * @return `bool` Sa active high,`true` kung ang status indicator ay nasa `HIGH` state, 
         *              `false` kung ito ay nasa `LOW` state. Kabaligtaran sa active low.
         * 
         * ### Halimbawa ng Paggamit:
         * ``` cpp
         * Tibok indicator(13, NORMAL);
         * void setup() {
         *     Serial.begin(9600);
         *     if (indicator.getState()) {
         *         Serial.println("Ang indicator ay nasa HIGH state.");
         *     } else {
         *         Serial.println("Ang indicator ay nasa LOW state.");
         *     }
         * }
         * ```
         */
        bool getState() const;

        /**
         * @brief Kinukuha ang oras ng huling pagtikwas ng status indicator.
         * 
         * Ibinabalik nito ang bilang ng milisegundo mula nang huling magbago
         * ang estado ng status indicator (HIGH o LOW). Ang timestamp na ito ay 
         * nagbibigay ng reference sa pinakahuling oras ng pagpapalit ng estado ng indicator.
         * 
         * @return `unsigned long` Ang bilang ng milisegundo mula nang huling pagtikwas ng indicator.
         * 
         * ### Halimbawa ng Paggamit:
         * ``` cpp
         * Tibok indicator(13, NORMAL);
         * void setup() {
         *     Serial.begin(9600);
         *     indicator.update();  // I-update ang indicator.
         *     Serial.print("Huling pagtikwas: ");
         *     Serial.println(indicator.getLastToggle());  // I-print ang oras ng huling pagtikwas.
         * }
         * ```
         */
        unsigned long getLastToggle() const;
    };