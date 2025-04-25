# TibokGetters Demo

Ang sketch na ito ay nagpapakita ng paggamit ng `Tibok` class upang makuha ang mga iba't ibang impormasyon tungkol sa isang LED na kumikilos bilang status indicator. Gumagamit ito ng mga getter functions upang kunin ang mga detalye ng LED tulad ng pin, label ng heartbeat level, aktibong HIGH/LOW, at iba pang estado ng LED.

### Paano Gumagana ang mga Getter Functions?

1. **`getPin()`**  
   - Ibinabalik ng `getPin()` ang numero ng pin kung saan nakakabit ang LED. Ito ay ginagamit upang malaman kung aling pin sa microcontroller ang ginagamit para sa LED.
   - Halimbawa:
     ```cpp
     int pin = statusLed.getPin();
     ```

2. **`getLabel()`**  
   - Ibinabalik ng `getLabel()` ang label o pangalan ng kasalukuyang `HeartbeatLevel` ng LED. Ang label ay tutukoy kung anong level ng tibok ang itinakda, tulad ng "KAGIPITAN", "KRITIKAL", "BABALA", o "NORMAL".
   - Halimbawa:
     ```cpp
     String label = statusLed.getLabel();
     ```

3. **`getHeartbeat()`**  
   - Ibinabalik ng `getHeartbeat()` ang numerical na halaga ng kasalukuyang `HeartbeatLevel`. Ang halaga ng heartbeat level ay tumutukoy sa tagal ng pag-tick ng LED (sa millisecond).
   - Halimbawa:
     ```cpp
     unsigned long heartbeat = statusLed.getHeartbeat();
     ```

4. **`isActiveHigh()`**  
   - Ang `isActiveHigh()` ay isang getter function na nagsasabi kung ang LED ay aktibo kapag ang signal ay HIGH o LOW. Ibinabalik nito ang `true` kung ang LED ay aktibo sa HIGH state, at `false` kung sa LOW state.
   - Halimbawa:
     ```cpp
     bool isActive = statusLed.isActiveHigh();
     ```

5. **`isEnabled()`**  
   - Ang `isEnabled()` ay isang getter function na nagsasabi kung ang LED ay pinagana o hindi. Ibinabalik nito ang `true` kung ang LED ay pinagana, at `false` kung hindi.
   - Halimbawa:
     ```cpp
     bool enabled = statusLed.isEnabled();
     ```

6. **`getState()`**  
   - Ibinabalik ng `getState()` ang kasalukuyang estado ng LED, kung ang LED ay naka-on (`HIGH`) o naka-off (`LOW`).
   - Halimbawa:
     ```cpp
     bool currentState = statusLed.getState();
     ```

7. **`getLastToggle()`**  
   - Ibinabalik ng `getLastToggle()` ang tagal ng oras (sa milliseconds) mula nang huling pagbabago ng estado ng LED.
   - Halimbawa:
     ```cpp
     unsigned long lastToggle = statusLed.getLastToggle();
     ```

### Layunin ng Demo

Ang demo na ito ay nagpapakita ng mga getter functions ng `Tibok` class upang makuha ang mga detalye ng isang LED na ginagamit bilang status indicator. Ang bawat function ay nagbibigay ng mahalagang impormasyon tungkol sa LED, tulad ng pin, label ng heartbeat level, aktibong HIGH/LOW, at ang kasalukuyang estado.

### Paano Gamitin:

1. **I-upload ang Sketch**: I-upload ang `TibokGetters.ino` sa iyong Arduino board. Siguraduhin na ang board ay may built-in LED (tulad ng mga Arduino Uno at iba pang compatible boards).
   
2. **Buksan ang Serial Monitor**: Pagkatapos i-upload ang sketch, buksan ang Serial Monitor (115200 baud rate).

3. **Makikita ang Output**:
    - Ipapakita ng output ang mga detalye ng LED, tulad ng pin, label, heartbeat level, at ang kasalukuyang estado. Halimbawa ng output:
      ```
      === Tibok Getters Demo ===
      Pin: 13
      Tatak: BABALA
      Hatimpuktol (ms): 500
      Aktibong Mataas: true
      Pinagana: true
      Kasalukuyang Estado (Nakasindi ba LED?): HIGH
      Huling Tikwas (ms): 0
      ```

### Mga Detalye ng Sketch:

- **`getPin()`** ay ginagamit upang malaman kung aling pin sa Arduino board ang ginagamit ng LED.
- **`getLabel()`** ay ginagamit upang kunin ang label ng kasalukuyang `HeartbeatLevel` ng LED.
- **`getHeartbeat()`** ay ginagamit upang malaman ang numerical na halaga ng heartbeat level (sa milliseconds).
- **`isActiveHigh()`** ay ginagamit upang matukoy kung ang LED ay active sa HIGH state.
- **`isEnabled()`** ay ginagamit upang malaman kung ang LED ay pinagana.
- **`getState()`** ay ginagamit upang malaman ang kasalukuyang estado ng LED.
- **`getLastToggle()`** ay ginagamit upang malaman ang oras mula nang huling pagbabago ng estado ng LED.

### Output Format:
Ang output ay nagpapakita ng mga sumusunod na impormasyon tungkol sa LED:
- **Pin**: Ang pin kung saan nakakabit ang LED.
- **Tatak**: Ang label ng kasalukuyang `HeartbeatLevel` ng LED.
- **Hatimpuktol (ms)**: Ang numerical value ng kasalukuyang `HeartbeatLevel`.
- **Aktibong Mataas**: Kung ang LED ay active sa HIGH state.
- **Pinagana**: Kung ang LED ay pinagana.
- **Kasalukuyang Estado**: Kung ang LED ay kasalukuyang naka-on (HIGH) o naka-off (LOW).
- **Huling Tikwas**: Ang tagal ng oras mula nang huling pagpapalit ng estado ng LED.

### Halimbawa ng Output:

``` sh
=== Tibok Getters Demo ===
Pin: 13
Tatak: BABALA
Hatimpuktol (ms): 500
Aktibong Mataas: true
Pinagana: true
Kasalukuyang Estado (Nakasindi ba LED?): HIGH
Huling Tikwas (ms): 250
```

### Mga Pagpapahusay:
**Pagdagdag ng mga feature**: Maaari mong dagdagan ang sketch upang mag-log ng mas maraming impormasyon o mag-trigger ng mga aksyon batay sa mga estado ng LED.

**Pagtukoy ng mga Time Intervals**: Ang `getHeartbeat()` at `getLastToggle()` ay maaaring gamitin upang tukuyin ang mga interval ng pagtibok at pagbabago ng estado ng LED.

### Kongklusyon:
Ang `TibokGetters Demo` ay isang mahusay na halimbawa ng paggamit ng mga getter functions ng `Tibok` class upang makuha ang mga detalye ng estado ng isang LED. Ang mga getter functions na ito ay nagbibigay ng flexibility at kontrol sa kung paano natin ginagamit at minomonitor ang mga status indicators sa ating mga proyekto.

## License

Ito ay bahagi ng ***Proyektong LundayHangin*** at sumusunod sa parehong license na inilatag para sa naturang proyekto. 