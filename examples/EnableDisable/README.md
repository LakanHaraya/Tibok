# EnableDisableHeartbeat Demo

Ang sketch na ito ay nagpapakita kung paano **pansamantalang ihinto at muling paganahin** ang pagtibok ng isang status LED gamit ang `enable()` method ng `Tibok` library.

### Paano Gumagana ang Sketch?

- Isang `Tibok` object (`heartLED`) ang naka-configure sa **pin 13** na may **`CRITICAL` heartbeat level** (1000ms interval).
- Sa bawat **7 segundo**, ang LED ay:
  - **Tumitigil sa pagtibok** gamit ang `enable(false)`
  - **Muling magpatuloy sa pagtibok** gamit ang `enable()` (default ay `true`)
- Ginagamit ang `millis()` upang masubaybayan ang oras at kontrolin ang switching ng estado.

### Layunin ng Demo

Ipakita ang kakayahan ng `Tibok` na:
- **I-pause** ang LED indicator sa anumang oras
- **Muling paganahin** ito kapag kinakailangan
- Makontrol ito sa runtime nang hindi nawawala ang mga naunang configuration tulad ng pin, logic level, o antas ng tibok

### Paano Gamitin:

1. **I-upload ang Sketch**: I-upload ang `EnableDisable.ino` sa iyong Arduino board. Karamihan ng Arduino boards ay may built-in LED sa pin 13.
2. **Pagmasdan ang LED**: Ang LED ay tumitibok sa 7 segundo (CRITICAL), hihinto sa loob ng 7 segundo, at magpapatuloy muli—paulit-ulit.

### Mga Detalye ng Sketch:

- **`Tibok heartLED(13, CRITICAL)`**: Lumikha ng LED na tumitibok sa kritikal.
- **`enable(false)`**: Itigil ang tibok.
- **`enable()`**: Ibalik ang pagtibok.
- **`update()`**: Patuloy na tinatawag sa loop upang mapanatili ang heartbeat logic habang naka-enable.

### Output:

- Ang LED ON/OFF behavior ay titigil at babalik tuwing 7 segundo.
- Kapaki-pakinabang sa mga system na kailangang **i-mute** ang status indicator pansamantala.

### Kongklusyon:

Ang `EnableDisable Demo` ay isang kapaki-pakinabang na halimbawa ng **runtime control** ng heartbeat LED, kung saan maaaring pansamantalang ihinto ang LED feedback—halimbawa sa low-power mode o kapag hindi kinakailangan ang visual feedback.

## License

Ito ay bahagi ng ***Proyektong LundayHangin*** at sumusunod sa parehong license na inilatag para sa naturang proyekto.
