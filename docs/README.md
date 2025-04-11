# 📖 `MuntingTibok/` v1.0.0

📜 *Malapamantayan:* **LNDH-0051** *(Aktibo)*  
📅 *Petsa ng Paglalathala:* **2025-04-11**  
🔢 *Bersiyon:* **v1.0.0** *(Matatag)*  
🛠️ *Huling Rebisyon:* **2025-04-11**  
👨‍💻 *May-akda:* **Lakan Haraya Dima**  

Ang **MuntingTibok** ay isang magaan at minimalistikong aklatan para sa
pagkontrol ng LED o iba pang output device bilang *heartbeat indicator* na
sumasalamin sa operational status ng sistema. Ang tibok ay maaaring magpakita ng
iba't ibang antas gaya ng `NORMAL`, `WARNING`, `CRITICAL`, o `EMERGENCY`.

> Ang aklatang ito ay bahagi ng *Proyektong LundayHangin* ngunit
> maaaring isama sa anumang proyekto ng mikrokontroler na
> nangangailangan ng malinaw na pidbak na natatanaw, nadidinig, o
> nahahaplos.

---

## Mga Tampok

- Simpleng API para sa heartbeat-style LED signaling
- Naka-`enum` ang predefined intervals (`Heartbeat`)
- Madaling itikwas ang active HIGH o active LOW logic
- May `enable()` at `disable()` methods para sa runtime control
- Suportado ang dynamic na pagpapalit ng tibok (`setLevel()`)

---

## Karagdagang Dokumentasyon

- [INSTALLATION.md](../docs/INSTALLATION.md)
- [API_REFERENCE.md](../docs/API_REFERENCE.md)
- [CHANGELOG](../docs/CHANGELOG)

---

## Mga Halimbawa

Tingnan ang [`examples/`](../examples/) folder para sa mga sumusunod na sketch

- [`ActiveLowHeartbeat.ino`](../examples/ActiveLowHeartbeat.ino) – Aktibong LOW na signal
- [`BasicHeartbeat.ino`](../examples/BasicHeartbeat.ino) – Simpleng tibok
- [`DynamicHeartbeat.ino`](../examples/DynamicHeartbeat.ino) – Pagpapalit ng tibok sa runtime
- [`EnableDisableTibok.ino`](../examples/EnableDisableHeartbeat.ino) – Pagtikwas ng tibok

> ### Testing
> 1. I-upload ang isa sa mga halimbawa sa iyong board.
> 2. Suriin kung gumagana ang heartbeat tulad ng inaasahan.

---

## Lisensiya

Ang **MuntingTibok** ay inilabas sa ilalim ng [MIT License](LICENSE)