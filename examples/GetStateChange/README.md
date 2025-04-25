# GetStateChange Demo

Ang sketch na ito ay nagpapakita ng paggamit ng `Tibok` class upang subaybayan ang estado ng isang LED at ipakita lamang ang mga pagbabago sa estado nito. Gumagamit ito ng mga getter functions na `getState()` at `getLastToggle()` upang kunin ang kasalukuyang estado ng LED at ang huling tagal ng pagtibok, ayon sa pagkakabanggit.

### Paano Gumagana ang `getState()` at `getLastToggle()`?

1. **`getState()`**  
   - Ang `getState()` ay isang getter function na ginagamit upang makuha ang kasalukuyang estado ng LED (HIGH o LOW).
   - Ang function na ito ay tumutulong upang matukoy kung ang LED ay kasalukuyang naka-on (`HIGH`) o naka-off (`LOW`).
   - Halimbawa:
     ```cpp
     bool currentState = statusLed.getState();
     ```
   
2. **`getLastToggle()`**  
   - Ang `getLastToggle()` ay isang getter function na nagbibigay ng tagal ng oras (sa milliseconds) mula nang huling pagbabago ng estado ng LED.
   - Pinapayagan ng function na ito ang iyong program na malaman kung gaano katagal mula nang huling pagpapalit ng estado ng LED, na maaaring magamit sa iba pang mga bahagi ng iyong proyekto.
   - Halimbawa:
     ```cpp
     unsigned long lastToggleTime = statusLed.getLastToggle();
     ```

### Layunin ng Demo

Ang demo na ito ay naglalarawan kung paano gamitin ang `getState()` at `getLastToggle()` upang i-monitor ang estado ng isang LED na kumikilos tulad ng isang heartbeat (pagtibok). Ang mga outputs ay ipapakita lamang kapag may pagbabago sa estado ng LED, kaya't pinipigilan ang mga paulit-ulit na prints.

### Paano Gamitin:

1. **I-upload ang Sketch**: I-upload ang `GetStateChange.ino` sa iyong Arduino board. Siguraduhin na ang board ay may built-in LED (tulad ng mga Arduino Uno at iba pang compatible boards).
   
2. **Buksan ang Serial Monitor**: Pagkatapos i-upload ang sketch, buksan ang Serial Monitor (115200 baud rate).

3. **Makikita ang Output**:
    - Ang output ay ipapakita lamang kapag may pagbabago sa estado ng LED (mula sa HIGH patungong LOW o vice versa).
    - Halimbawa ng output:
      ```
      [Kasalukuyang Estado] | [Huling Tikwas]
      HIGH | 125ms
      LOW  | 250ms
      HIGH | 375ms
      ```

### Mga Detalye ng Sketch:

- **`getState()`** ay ginagamit upang malaman kung ang LED ay kasalukuyang naka-on (HIGH) o naka-off (LOW).
- **`getLastToggle()`** ay ginagamit upang sukatin kung gaano katagal mula nang huling pagbabago ng estado ng LED, at ito ang ipinapakita sa `[Huling Tikwas]` column ng output.

### Output Format:
Ang output ay nagpapakita ng dalawang pangunahing impormasyon:
- **Kasalukuyang Estado**: Ang kasalukuyang estado ng LED (`HIGH` o `LOW`).
- **Huling Tikwas**: Ang tagal ng oras (sa milliseconds) mula nang huling pag-toggle ng LED.

### Halimbawa ng Output:

``` sh
[Kasalukuyang Estado] | [Huling Tikwas]
HIGH | 125ms
LOW  | 250ms
HIGH | 375ms
LOW  | 500ms
...
```


### Mga Pagpapahusay:

- **Pagdagdag ng mga feature**: Maaari mong dagdagan ang sketch upang mag-log ng mas maraming impormasyon tulad ng pag-count ng mga cycles ng pagtibok o pag-trigger ng mga aksyon batay sa mga estado ng LED.
- **Pagtukoy ng mga Time Intervals**: Ang `getLastToggle()` ay maaaring gamitin upang tukuyin ang interval ng mga pagbabago ng estado ng LED, na mahalaga sa mga proyekto tulad ng monitoring systems o notifications.

### Kongklusyon:

Ang `GetStateChange Demo` ay isang magandang halimbawa ng paggamit ng `Tibok` class para magmonitor ng mga pagbabago sa estado ng isang LED gamit ang `getState()` at `getLastToggle()`. Magiging kapaki-pakinabang ang mga functions na ito para sa mga proyekto na may mga status indicators o heartbeat monitoring.

## License

Ito ay bahagi ng ***Proyektong LundayHangin*** at sumusunod sa parehong license na inilatag para sa naturang proyekto. 
