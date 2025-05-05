# 📖 `Tibok/`
![Release](https://img.shields.io/github/v/release/LakanHaraya/Tibok?include_prereleases)
![Malapamantayan](https://img.shields.io/badge/malapamantayan-LNDH--0051-purple)  
![Last Commit](https://img.shields.io/github/last-commit/LakanHaraya/Tibok?label=last%20commit&style=flat-square)
![First Commit](https://img.shields.io/badge/first%20commit-2025--04--11-FCD116)  
![Language](https://img.shields.io/badge/language-Filipino%20(may%20neolohismo)-0038A8)

Ang **Tibok** ay isang magaan at mumunting aklatan para sa
pagkontrol ng LED o iba pang output device bilang *status indicator* na
sumasalamin sa operational status ng sistema. Ang tibok ay maaaring magpakita ng
iba't ibang antas gaya ng `Tibok::NORMAL`, `Tibok::WARNING`, `Tibok::CRITICAL`, o `Tibok::EMERGENCY` batay sa antas ng alerto sa pamantayang
[IEC 60073:2002](https://webstore.iec.ch/en/publication/587).

> Ang aklatang ito ay bahagi ng *Proyektong LundayHangin* ngunit
> maaaring isama sa anumang proyekto ng mikrokontroler na
> nangangailangan ng malinaw na pidbak na natatanaw, nadidinig, o
> nahahaplos.

---

## Mga Tampok

- Maaaring ikumpigura ang antas ng tibok batay sa mga predefined na halaga (4Hz hanggang 0.5Hz)
- Non-blocking na `update()` para sa maayos na pagtakbo ng `loop()`
- Suportado ang active HIGH o LOW na logic
- Puwedeng i-enable o i-disable ang pagtibok sa runtime
- May readable na mga label para sa bawat antas ng tibok
- Fluent API para sa madaling dugtungan ng mga method


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