# 📘 `Tibok/` – *API Reference*

Ito ang detalyadong talaan ng mga magagamit na *API (Application Programming Interface)* ng aklatan ng **Tibok**.

---

## 📘 Talaan ng API

[`Tibok`](#tibokint-pin-heartbeatlevel-level--tibokstandby-bool-activehigh--true-bool-enabled--true)
[`update()`](#void-update)
[`enable(...)`](#tibok-enablebool-enabled--true)
[`setHeartbeat(...)`](#tibok-setheartbeatheartbeatlevel-level--tibokstandby)
[`setActiveHigh(...)`](#tibok-setactivehighbool-activehigh--true)
[`getPin()`](#int-getpin-const)
[`getLabel()`](#string-getlabel-const)
[`getState()`](#bool-getstate-const)
[`getLastToggle()`](#unsigned-long-getlasttoggle-const)
[`isActiveHigh()`](#bool-isactivehigh-const)
[`isEnabled()`](#bool-isenabled-const)
[`Tibok::EMERGENCY`](#enum-heartbeatlevel)
[`Tibok::CRITICAL`](#enum-heartbeatlevel)
[`Tibok::WARNING`](#enum-heartbeatlevel)
[`Tibok::NOTICE`](#enum-heartbeatlevel)
[`Tibok::STANDBY`](#enum-heartbeatlevel)
[`Tibok::NORMAL`](#enum-heartbeatlevel)

---

## 🏗️ Konstruktor

### `Tibok(int pin, HeartbeatLevel level = Tibok::STANDBY, bool activeHigh = true, bool enabled = true)`

Gumawa ng bagong `Tibok` objek na may partikular na GPIO pin at asal.

<center>

| Parameter | Uri | Paliwanag | Default |
|----------|-----|---|-----------|
| `pin` | `int` | GPIO pin na kokontrolin | *Wala* |
| `level` | `HeartbeatLevel` | Inisyal na antas ng tibok (tingnan ang mga [konstant](#enum-heartbeatlevel)) | `Tibok::STANDBY` |
| `activeHigh` | `bool` | Antas ng lohika: aktibo sa HIGH o LOW | `true` |
| `enabled` | `bool` | Awtomatikong pagaganahin ba ang tibok? | `true` |

</center>

---

## ⚙️ Pangunahing Metodo

### `void update()`

Panatilihing tumitibok ang status indicator.

> - Dapat itong tawagin sa loob ng `loop()`.
> - *Non-blocking* ang operasyon nito.
> - Batay sa `millis()`, hindi sa `delay()`.

---

## 🔄 Pantakdang Metodo *(Setter Methods)*

### `Tibok& enable(bool enabled = true)`

Pinapagana o pinapahinto ang tibok.

<center>

| Parameter | Uri | Paliwanag | Default |
|----------|-----|---|--------|
| `enabled` | `bool` | Kung `true`, pinapagana ang tibok; <br> Kung `false`, pinapahinto ito. | `true` |

</center>

> - Nagrereset ng output pin batay sa bagong lohika.
> - Metodong **nakapagdudugtong**.

---

### `Tibok& setHeartbeat(HeartbeatLevel level = Tibok::STANDBY)`

Itinatakda ang bagong heartbeat level.

<center>

| Parameter | Uri | Paliwanag | Mga Halagang <br> Tinatanggap | Default |
|----------|-----|----|----|---|
| `level` | `HeartbeatLevel` | Bagong itinakdang antas ng tibok. <br> [tingnan](#enum-heartbeatlevel) |  `Tibok::EMERGENCY` <br> `Tibok::CRITICAL` <br> `Tibok::WARNING` <br> `Tibok::NOTICE` <br> `Tibok::STANDBY` <br> `Tibok::NORMAL` | `Tibok::STANDBY` |

</center>

> - Hindi nagrereset ng oras.
> - Metodong **nakapagdudugtong**.

---

### `Tibok& setActiveHigh(bool activeHigh = true)`

Itinatakda kung active HIGH (`true`) o LOW (`false`) ang output logic.

<center>

| Parameter | Uri | Paliwanag | Default |
|----------|-----|----|-------|
| `activeHigh` | `bool` | Antas ng lohika: aktibo sa HIGH o LOW | `true` |

</center>

> - Agad na inilalapat ang lohika.
> - Metodong **nakapagdudugtong**.

---

## 📊 Pangkuhang Metodo *(Getter Methods)*

### `int getPin() const`

Ibinabalik ang ginamit na GPIO pin number.

---

### `String getLabel() const`

Ibinabalik ang human-readable na label ng kasalukuyang `HeartbeatLevel`.

> | `HeartbeatLevel` | Tatak |
> | :---: | :---: |
> | `Tibok::EMERGENCY` | `"KAGIPITAN"` |
> | `Tibok::CRITICAL`  | `"KRITIKAL"`  |
> | `Tibok::WARNING`   | `"BABALA"`    |
> | `Tibok::NOTICE`    | `"PAALALA"`   | 
> | `Tibok::STANDBY`   | `"ANTABAY"`   |
> | `Tibok::NORMAL`    | `"NORMAL"`    |
> | (fallback)         | `"DI-KILALA"` |

---

### `bool getState() const`

Ibinabalik kung HIGH (`true`) o LOW (`false`) ang kasalukuyang estado ng output pin.

---

### `unsigned long getLastToggle() const`

Ibinabalik ang `millis()` timestamp ng huling pagtikwas.

---

### `bool isActiveHigh() const`
 
Ibinabalik kung aktibong HIGH (`true`) o aktibong LOW (`false`) ang kumpigurasyon.

---

### `bool isEnabled() const`
 
Ibinabalik kung ang tibok ay pinagana (`true`) o hindi (`false`).

---

## 📦 Mga Konstant

### Enum: `HeartbeatLevel`
 
Mga predefined na antala para sa iba't ibang antas ng alerto:

<center>

| Konstant | Kulay (Rekomendado) | Asal ng Pagtibok <br> (Alinsunod-IEC) | Dalasan (Hz) | Antas ng Priyoridad | Interpretasyon |
|------|-------|---------|-----------| --- | --- |
| `Tibok::EMERGENCY` | 🔴 Pula | Kumikislap: mabilis | `~4 Hz` | Pinakamataas | Agarang aksiyon ang kinakailangan |
| `Tibok::CRITICAL` | 🔴 Pula | Kumikislap: tuloy-tuloy | `~2 Hz` | Mataas | Seryosong atensiyon ang kinakailangan |
| `Tibok::WARNING` | 🟠 Amber/Dilaw | Kumikislap | `~1 Hz` | Katamtaman | Babalang kondisyon |
| `Tibok::NOTICE` | 🟢 Berde | Kumikislap: mabagal | `~0.5 Hz` | Mababa | Pang-impormasyong kondisyon |
| `Tibok::STANDBY` | 🟢 Berde | Kumikislap: mabugso | `~0.5 Hz` mabugso | Napakababa | Matamlay o nakaantabay |
| `Tibok::NORMAL` | 🟢 Berde | Matatag nakaSINDI | `0 Hz` (walang tibok) | Karaniwan | Karaniwang operasyon |

</center>

> 🔍 Ang **IEC 60073:2002** ay hindi nagtatakda ng eksaktong frequency values — nagbibigay ito ng mga halimbawa
(e.g., "**mas mabilis na *flashing* = mas mataas ang *urgency***").
> 
> Layunin nitong *maipahayag ang antas ng urgency sa paraang madaling maunawaan ng tao*.
> Sa madaling salita: **mas mahalaga ang *relatibong* bilis ng flashing kaysa sa eksaktong frequency**.

---

## 🧠 Paalala sa Paggamit

### 🕒 Update Loop
- Tawagin ang `update()` sa bawat `loop()`; *non-blocking* ito.
- Iwasan ang `delay()`; gumamit ng `millis()` para sa timing.

### ⚙️ Dynamic Setup
- Lahat ng `setter` ay nakapagdudugtong (*chainable*) at *real-time configurable*.
- Puwedeng baguhin habang tumatakbo ang sistema.

### ⚡ GPIO Pin
- Gamitin lamang ang isang `Tibok` object bawat pin.
- Ingatan kung active HIGH (may pull-down) o active LOW (may pull-up).

### 🔍 Estado
- Gamitin ang `isEnabled()`, `getState()`, at `getLastToggle()` para sa lohika.
- Gamitin ang `getHeartbeat()` at `getLabel()` para sa status reporting.

### 🧱 Inisyal
- Walang `begin()` function — gumamit ng konstruktor sa `setup()` o global scope.

---

## 📂 Kaugnay na File

- [`src/Tibok.h`](../src/Tibok.h) – Mga deklarasyon ng klase at API.
- [`src/Tibok.cpp`](../src/Tibok.cpp) – Mga implementasyon ng lohika.
- [`examples/`](../examples/) – Mga halimbawa ng paggamit.
