# MuntingTibok

Ang **MuntingTibok** ay isang magaan at minimalistikong aklatan para sa
pagkontrol ng LED o iba pang output device bilang *heartbeat indicator* na
sumasalamin sa katayuan ng sistema. Ang tibok ay maaaring magpakita ng iba't
ibang antas gaya ng NORMAL, WARNING, CRITICAL, o EMERGENCY.

---

## Mga Tampok

- Simpleng API para sa heartbeat-style LED signaling
- Naka-`enum` ang predefined intervals (`Heartbeat`)
- Madaling itikwas ang active HIGH o active LOW logic
- May `enable()` at `disable()` methods para sa runtime control
- Suportado ang dynamic na pagpapalit ng tibok (`setLevel()`)

---

## Sanggunian ng API

Para sa kompletong sanggunian ng API nito, tingnan ang `API_REFERENCE.md` [dito](../docs/API_REFERENCE.md). 

---

## Mga Halimbawa

Tingnan ang [`examples/`](../examples/) folder para sa mga sumusunod na sketch

- [`ActiveLowHeartbeat.ino`](../examples/ActiveLowHeartbeat.ino) – Aktibong LOW na signal
- [`BasicHeartbeat.ino`](../examples/BasicHeartbeat.ino) – Simpleng tibok
- [`DynamicHeartbeat.ino`](../examples/DynamicHeartbeat.ino) – Pagpapalit ng tibok sa runtime
- [`EnableDisableTibok.ino`](../examples/EnableDisableHeartbeat.ino) – Pagtikwas ng tibok

---

## May-akda

Binuo ni Lakan Haraya Dima
Bahagi ng *Proyektong LundayHangin*