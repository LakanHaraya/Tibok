# 📖 `Tibok/` v1.1.0

📜 *Malapamantayan:* **LNDH-0051** *(Aktibo)*  
📅 *Petsa ng Paglalathala:* **2025-04-11**  
🔢 *Bersiyon:* **v1.1.0** *(Balangkas)*  
🛠️ *Huling Rebisyon:* **2025-04-25**  
👨‍💻 *May-akda:* **Lakan Haraya Dima**  

Ang **Tibok** ay isang magaan at mumunting aklatan para sa
pagkontrol ng LED o iba pang output device bilang *status indicator* na
sumasalamin sa operational status ng sistema. Ang tibok ay maaaring magpakita ng
iba't ibang antas gaya ng `NORMAL`, `WARNING`, `CRITICAL`, o `EMERGENCY` batay sa antas ng alerto sa pamantayang
[IEC 60073:2002](https://webstore.iec.ch/en/publication/587).

> Ang aklatang ito ay bahagi ng *Proyektong LundayHangin* ngunit
> maaaring isama sa anumang proyekto ng mikrokontroler na
> nangangailangan ng malinaw na pidbak na natatanaw, nadidinig, o
> nahahaplos.

---

## Mga Tampok

- **Simpleng API para sa heartbeat-style LED signaling**: Madaling gamitin upang magbigay ng visual feedback gamit ang LED o ibang output device bilang *heartbeat indicator*.

- **Predefined Heartbeat Levels**: May apat na *heartbeat levels* na maaaring itakda:
  - `EMERGENCY`: 125ms hatimpuktol (4Hz)
  - `CRITICAL`: 250ms hatimpuktol (2Hz)
  - `WARNING`: 500ms hatimpuktol (1Hz)
  - `NORMAL`: 1s hatimpuktol (0.5Hz)

- **Dynamic na Pagpapalit ng Tibok**: Gamit ang `setHeartbeat()` para baguhin ang *heartbeat level* at `setActiveHigh()` upang itakda ang active HIGH o LOW logic.

- **Runtime Control**: Gamit ang `enable()` para paganahin o di-paganahin ang tibok sa runtime.

- **Getter Methods**: Madaling makuha ang impormasyon tungkol sa tibok gamit ang mga getter methods:
  - `getPin()` – kinukuha ang pin number
  - `getLabel()` – kinukuha ang label ng kasalukuyang *heartbeat level*
  - `getState()` – kinukuha ang kasalukuyang estado (HIGH o LOW)
  - `getLastToggle()` – kinukuha ang oras ng huling pagtikwas
  - `getHeartbeat()` – kinukuha ang numerical value ng *heartbeat level*
  - `isActiveHigh()` – kinukuha kung ang output ay active HIGH
  - `isEnabled()` – kinukuha kung ang tibok ay naka-enable

---

## Karagdagang Dokumentasyon

- [INSTALLATION.md](../docs/INSTALLATION.md)
- [API_REFERENCE.md](../docs/API_REFERENCE.md)
- [CHANGELOG](../docs/CHANGELOG)

---

## Mga Halimbawa

Tingnan ang [`examples/`](../examples/) folder para sa mga sumusunod na sketch

- [`ActiveLowHighHeartbeat.ino`](../examples/ActiveLowHighHeartbeat/) – Aktibong LOW at aktibong HIGH na signal
- [`BasicHeartbeat.ino`](../examples/BasicHeartbeat/) – Simpleng tibok
- [`GetStateChange.ino`](../examples/GetStateChange/) – Subaybayan ang estado ng indikador at ipakita ang mga pagbabago sa estado nito.
- [`TibokGetters`](../examples/TibokGetters/) – Kunin ang mga iba't ibang impormasyon tungkol sa status indicator
- [`ConstructorDemo`](../examples/ConstructorDemo/) – Iba't ibang paraan ng paggamit ng constructor gamit ang magkakaibang bilang ng argumento.
- [`DynamicHeartbeat`](../examples/DynamicHeartbeat/) – Pagpapalit ng tibok sa runtime
- [`EnableDisable`](../examples/EnableDisable/) – Pagtikwas ng tibok

> ### Testing
> 1. I-upload ang isa sa mga halimbawa sa iyong board.
> 2. Suriin kung gumagana ang heartbeat tulad ng inaasahan.

---

## Lisensiya

Ang **MuntingTibok** ay inilabas sa ilalim ng [MIT License](LICENSE)