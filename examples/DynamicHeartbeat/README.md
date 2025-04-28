# DynamicHeartbeat Demo

Ang sketch na ito ay nagpapakita ng paggamit ng `Tibok/` library upang **dynamically** na mabago ang tibok o blinking pattern ng isang status LED **habang tumatakbo ang system**, gamit ang `heartbeat()` method.

### Paano Gumagana ang Sketch?

- Isang `Tibok` object (`statusLED`) ang nilikha sa **pin 13**, na may panimulang `NORMAL` heartbeat level.
- Sa bawat **5 segundo**, ang tibok ng LED ay pinapalitan sa pagitan ng:
  - **`EMERGENCY`** – 125ms interval (mas mabilis na tibok)
  - **`WARNING`** – 500ms interval (katamtamang tibok)
- Ginagamit ang `millis()` upang masubaybayan ang paglipas ng oras at matiyak na tuloy-tuloy ang pagbabago ng antas ng tibok.

### Layunin ng Demo

Ipamalas ang kakayahan ng `Tibok/` library na:
- Magpalit ng heartbeat pattern **sa runtime**
- Gamitin ang `heartbeat()` upang **tumugon sa mga kondisyon ng system**, gaya ng pagbabago ng alert levels o system states

### Paano Gamitin:

1. **I-upload ang Sketch**: I-upload ang `DynamicHeartbeat.ino` sa iyong Arduino board. Siguraduhing may LED sa pin 13 (built-in sa karamihan ng Arduino boards).
2. **Pagmasdan ang LED**: Mapapansin mong ang LED ay magpapalit-palit ng bilis ng pagtibok kada 5 segundo.

### Mga Detalye ng Sketch:

- **`Tibok statusLED(13, NORMAL)`**: Nagsisimula sa `NORMAL` level, ngunit pinapalitan sa `loop()`.
- **`heartbeat()`**: Method na ginagamit upang baguhin ang tibok batay sa kondisyon.
- **`update()`**: Tinatawag sa bawat `loop()` cycle upang ipatupad ang kasalukuyang tibok.

### Output:

- Kada 5 segundo, magpapalit ang LED ng:
  - **Mabilis na tibok (EMERGENCY)**
  - **Mas mabagal na tibok (WARNING)**

### Kongklusyon:

Ang `DynamicHeartbeat Demo` ay isang praktikal na halimbawa ng **adaptive status signaling**, na kapaki-pakinabang sa mga proyektong nangangailangan ng feedback batay sa system status o kalagayan. Makatutulong ito sa mga sitwasyong kritikal kung saan kailangan ang agarang atensiyon gamit lamang ang LED o iba pang indicator.

## License

Ito ay bahagi ng ***Proyektong LundayHangin*** at sumusunod sa parehong license na inilatag para sa naturang proyekto.
