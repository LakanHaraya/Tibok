# 📘 `Tibok/` – *API Reference*

Ito ang detalyadong talaan ng mga magagamit na API (Application Programming Interface) ng aklatan ng **Tibok**.

---

## 📘 Talaan ng API

<center>

| API | Paggamit |
| :-- | :-- |
| [`Tibok(...)`](#tibokint-pin-heartbeatlevel-level--normal-bool-activehigh--true-bool-enabled--true) | Konstruktor – paglikha ng halimbagay ng `Tibok` class | 
| [`update()`](#void-update) | Isinasapanahon ang tibok; kailangang tawagin sa loob ng `loop()` |
| [`enable(...)`](#tibok-enablebool-enabled--true) | Pinapagana o pinapahinto ang tibok |
| [`heartbeat(...)`](#tibok-heartbeatheartbeatlevel-level--normal) | Pinapalitan ang kasalukuyang antas ng tibok |
| [`activeHigh(...)`](#tibok-activehighbool-activehigh--true) | Itinatakda kung active HIGH o LOW ang output logic |
| [`getPin()`](#int-getpin-const) | Ibinabalik ang GPIO pin na ginagamit para sa status indicator |
| [`getLabel()`](#string-getlabel-const) | Ibinabalik ang label na ginagamit para sa status indicator |
| [`getHeartbeat()`](#unsigned-long-getheartbeat-const) | Ibinabalik ang kasalukuyang tibok interval (sa `millis`) |
| [`getState()`](#bool-getstate-const) | Ibinabalik ang kasalukuyang estado ng status indicator |
| [`getLastToggle()`](#unsigned-long-getlasttoggle-const) | Ibinabalik ang huling oras ng pagtibok (`millis`) |
| [`isActiveHigh()`](#bool-isactivehigh-const) | Ibinabalik kung active HIGH o LOW ang output |
| [`isEnabled()`](#bool-isenabled-const) | Ibinabalik kung ang tibok ay pinagana o hindi |
| [`Tibok::EMERGENCY`](#enum-heartbeatlevel) <br> [`Tibok::CRITICAL`](#enum-heartbeatlevel) <br> [`Tibok::WARNING`](#enum-heartbeatlevel) <br> [`Tibok::NORMAL`](#enum-heartbeatlevel) | Mga konstant ng enum `HeartbeatLevel` para sa antas ng tibok |

</center>

---

## 🏗️ Konstruktor

### `Tibok(int pin, HeartbeatLevel level = Tibok::NORMAL, bool activeHigh = true, bool enabled = true)`

**Layunin:** Gumawa ng bagong `Tibok` object.

<center>

| Parameter | Uri | Paliwanag | Default |
|----------|-----|---|-----------|
| `pin` | `int` | GPIO pin na kokontrolin | *Wala* |
| `level` | `HeartbeatLevel` | Inisyal na antas ng tibok (tingnan ang mga [konstant](#enum-heartbeatlevel)) | `Tibok::NORMAL` |
| `activeHigh` | `bool` | Kung `true`, active HIGH ang output. <br> Kung `false`, active LOW. | `true` |
| `enabled` | `bool` | Kung `true`, awtomatikong pinapagana ang tibok. <br> Kung `false`, hindi pagaganahin. | `true` |

</center>

---

## ⚙️ Kontrol at Operasyon

### `void update()`

**Layunin:** Panatilihing tumitibok ang output. Dapat itong tawagin sa loob ng `loop()` function ng sketch.

---

## 🔄 Panakdang Metodo *(Setter Methods)*

### `Tibok& enable(bool enabled = true)`

**Layunin:** Pinapagana o pinapahinto ang tibok ng status indicator.

<center>

| Parameter | Uri | Paliwanag | Default |
|----------|-----|---|--------|
| `enabled` | `bool` | Kung `true`, pinapagana ang tibok. <br> Kung `false`, pinapahinto ito. | `true` |

</center>

---

### `Tibok& heartbeat(HeartbeatLevel level = Tibok::NORMAL)`

**Layunin:** Palitan ang kasalukuyang tibok interval.

<center>

| Parameter | Uri | Paliwanag | Mga Halagang <br> Tinatanggap | Default |
|----------|-----|----|----|---|
| `level` | `HeartbeatLevel` | Bagong itinakdang antas ng tibok. <br> [tingnan](#enum-heartbeatlevel) |  `Tibok::EMERGENCY` <br> `Tibok::CRITICAL` <br> `Tibok::WARNING` <br> `Tibok::NORMAL` | `Tibok::NORMAL` |

</center>

---

### `Tibok& activeHigh(bool activeHigh = true)`

**Layunin:** Itinatakda kung active HIGH o LOW ang output.

<center>

| Parameter | Uri | Paliwanag | Default |
|----------|-----|----|-------|
| `activeHigh` | `bool` | Kung `true`, active HIGH ang output. <br> Kung `false`, active LOW. | `true` |

</center>

---

## 📊 Panguhang Metodo *(Getter Methods)*

### `int getPin() const`

**Layunin:** Ibinabalik ang GPIO pin na ginagamit para sa status indicator.

---

### `String getLabel() const`

**Layunin:** Ibinabalik ang label na ginagamit para sa status indicator. Halimbawa, maaari itong gamitin para sa pag-debug o pagpapakita ng impormasyon tungkol sa tibok.

---

### `unsigned long getHeartbeat() const`

**Layunin:** Ibinabalik ang kasalukuyang tibok interval sa milliseconds.

---

### `bool getState() const`

**Layunin:** Ibinabalik ang kasalukuyang estado ng status indicator (HIGH o LOW).

---

### `unsigned long getLastToggle() const`

**Layunin:** Ibinabalik ang huling oras ng pagtibok sa milliseconds mula nang ito ay na-enable.

---

### `bool isActiveHigh() const`
 
**Layunin:** Ibinabalik kung active HIGH o LOW ang output.

---

### `bool isEnabled() const`
 
**Layunin:** Ibinabalik kung ang tibok ay pinagana o hindi.

---

## 📦 Mga Konstant

### Enum: `HeartbeatLevel`
 
Predefined na tibok na mga delay (sa milliseconds):

<center>

| Antas ng Tibok | Hatimpuktol (*ms*) | Dalasan (*Hz*) | Paliwanag |
|------|-------|---------|-----------|
| `Tibok::EMERGENCY` | `125` | **4** | Mabilis na tibok para sa matinding alerto |
| `Tibok::CRITICAL` | `250` | **2** | Kritikal na tibok |
| `Tibok::WARNING` | `500` | **1** | Babala |
| `Tibok::NORMAL` | `1000` | **0.5** ( *1 ulit / 2 seg* ) | Pangkaraniwang tibok |

</center>

---

## 🧠 Mga Paalala sa Paggamit
Ilang mahahalagang detalye ukol sa maayos at inaasahang paggamit ng `Tibok` library.

### 🕒 Timing at Update Loop
- Ang `update()` ay *non-blocking*, kaya ligtas itong tawagin sa bawat `loop()` cycle.
- Iwasan ang `delay()` sa loob ng `loop()` kung ginagamit ang `update()`. Maaaring magdulot ito ng hindi pantay o nabibinbing tibok.
- Iminumungkahi ang paggamit ng `millis()`-*based logic* para sa ibang bahagi ng iyong sketch upang hindi makaapekto sa tibok.

### ⚙️ Dynamic Configuration
- Ligtas gamitin ang mga setter gaya ng `heartbeat()`, `activeHigh()`, at `enable()` kahit habang tumatakbo ang tibok.
- Maaari mong baguhin ang antas ng tibok anumang oras ayon sa pangangailangan ng sistema.

### ⚡ Pin Control
- Siguraduhing hindi ginagamit ng ibang bahagi ng programa ang GPIO pin na ibinigay sa konstruktor.
- Tiyaking ang configuration ng hardware (*pull-up/pull-down*) ay tumutugma sa `activeHigh` setting:

    - Gumamit ng `activeHigh = true` kung may *pull-down resistor*.
    - Gumamit ng `activeHigh = false` kung may *pull-up resistor*.

### 🔍 Estado at Debugging
- Magagamit ang `isEnabled()`, `getState()`, at `getLastToggle()` upang suriin ang kasalukuyang estado ng tibok para sa mga lohikal na desisyon.
- Magagamit ang `getHeartbeat()` at `getLabel()` para sa status reporting o user interface.

### 🧱 Inisyalisasyon
- Tiyaking tama ang pagkatawag ng konstruktor sa `setup()` o *global scope*.
- Sa kasalukuyang bersiyon, walang `begin()` method – lahat ng inisyal na setup ay ginagawa sa konstruktor pa lamang.

---

## 📂 Kaugnay na File

- `src/Tibok.h` – Ang mga deklarasyon ng API [dito](../src/Tibok.h).
- `src/Tibok.cpp` – Ang mga implementasyon ng API [dito](../src/Tibok.cpp).
- `examples/` – Mga halimbawa para sa aktuwal na paggamit ng API [dito](../examples/).
