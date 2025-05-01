# 📖 `Tibok/`
![Release](https://img.shields.io/github/v/release/LakanHaraya/Tibok?include_prereleases)
![Malapamantayan](https://img.shields.io/badge/malapamantayan-LNDH--0051-purple)  
![Last Commit](https://img.shields.io/github/last-commit/LakanHaraya/Tibok?label=last%20commit&style=flat-square)
![First Commit](https://img.shields.io/badge/first%20commit-2025--04--11-FCD116)  
![Language](https://img.shields.io/badge/language-Filipino%20(may%20neolohismo)-0038A8)

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

- **Dynamic na Pagkontrol sa Tibok sa Runtime**: Gamit ang `heartbeat()`
para baguhin ang *heartbeat level*, `activeHigh()` upang itakda ang
active HIGH o LOW logic, at `enable()` para paganahin o hindi
paganahin ang tibok habang umaandar ang programa.

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

- [INSTALLATION.md](docs/INSTALLATION.md)
- [API_REFERENCE.md](docs/API_REFERENCE.md)
- [CHANGELOG.md](docs/CHANGELOG.md)

---

## Mga Halimbawa

Tingnan ang [`examples/`](examples/) folder para sa mga sumusunod na sketch.

- [`ActiveLowHighHeartbeat.ino`](examples/ActiveLowHighHeartbeat/ActiveLowHighHeartbeat.ino) – Aktibong LOW at aktibong HIGH na signal
- [`BasicHeartbeat.ino`](examples/BasicHeartbeat/BasicHeartbeat.ino) – Simpleng tibok
- [`WithChainedMethods.ino`](examples/WithChainedMethods/WithChainedMethods.ino) – Paggamit ng chaining method
- [`GetStateChange.ino`](examples/GetStateChange/GetStateChange.ino) – Subaybayan ang estado ng indikador at ipakita ang mga pagbabago sa estado nito.
- [`TibokGetters.ino`](examples/TibokGetters/TibokGetters.ino) – Kunin ang mga iba't ibang impormasyon tungkol sa status indicator
- [`ConstructorDemo.ino`](examples/ConstructorDemo/ConstructorDemo.ino) – Iba't ibang paraan ng paggamit ng constructor gamit ang magkakaibang bilang ng argumento.
- [`DynamicHeartbeat.ino`](examples/DynamicHeartbeat/DynamicHeartbeat.ino) – Pagpapalit ng tibok sa runtime
- [`EnableDisable.ino`](examples/EnableDisable/EnableDisable.ino) – Pagtikwas ng tibok

> ### Testing
> 1. I-upload ang isa sa mga halimbawa sa iyong board.
> 2. Suriin kung gumagana ang heartbeat tulad ng inaasahan.

---

## Lisensiya

Ang **Tibok** ay inilabas sa ilalim ng [MIT License](license.txt)