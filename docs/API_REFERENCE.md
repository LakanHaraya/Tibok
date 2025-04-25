# 📘 `Tibok/` – *API Reference*

Ito ang detalyadong talaan ng mga magagamit na API (Application Programming Interface) ng aklatan ng **MuntingTibok**.

---

## Talaan ng API

<center>

| API | Paggamit |
| :-- | :-- |
| [`Tibok(...)`](#tibokint-pin-heartbeatlevel-level-bool-activehigh--true-bool-enabled--true) | Konstruktor – paglikha ng halimbagay ng `Tibok` class                    |
| [`update()`](#void-update)         | Isinasapanahon ang tibok, kailangang tawagin sa loob ng `loop()`        |
| [`setHeartbeat(...)`](#void-setheartbeatheartbeatlevel-level) | Pinapalitan ang kasalukuyang antas ng tibok                            |
| [`enable(...)`](#void-enablebool-enabled--true)       | Pinapagana o pinapahinto ang tibok                                     |
| [`setActiveHigh(...)`](#void-setactivehighbool-activehigh) | Itinatakda kung active HIGH o LOW ang output                            |
| [`getPin()`](#int-getpin-const)    | Ibinabalik ang GPIO pin na ginagamit para sa status indicator          |
| [`getLabel()`](#string-getlabel-const) | Ibinabalik ang label na ginagamit para sa status indicator             |
| [`isActiveHigh()`](#bool-isactivehigh-const) | Ibinabalik kung active HIGH o LOW ang output                           |
| [`isEnabled()`](#bool-isenabled-const) | Ibinabalik kung ang tibok ay pinagana o hindi                          |
| [`getState()`](#bool-getstate-const) | Ibinabalik ang kasalukuyang estado ng status indicator                 |
| [`getLastToggle()`](#unsigned-long-getlasttoggle-const) | Ibinabalik ang huling oras ng pagtibok (millis)                         |
| [`getHeartbeat()`](#unsigned-long-getheartbeat-const) | Ibinabalik ang kasalukuyang tibok interval bilang millis               |
| [`EMERGENCY`](#enum-heartbeatlevel) <br> [`CRITICAL`](#enum-heartbeatlevel) <br> [`WARNING`](#enum-heartbeatlevel) <br> [`NORMAL`](#enum-heartbeatlevel) | Mga constant ng enum `HeartbeatLevel` para sa antas ng tibok |

</center>

---

## 🏗️ Konstruktor

### `Tibok(int pin, HeartbeatLevel level, bool activeHigh = true, bool enabled = true)`

**Layunin:** Gumawa ng bagong `Tibok` object.

<center>

| Parameter | Uri | Paliwanag | Default |
|----------|-----|---|-----------|
| `pin` | `int` | Arduino GPIO pin na kokontrolin | *Wala* |
| `level` | `HeartbeatLevel` | Inisyal na antas ng tibok (e.g., `NORMAL`, `CRITICAL`, ... ) | *Wala* |
| `activeHigh` | `bool` | Kung `true`, active HIGH ang output. <br> Kung `false`, active LOW. | `true` |
| `enabled` | `bool` | Kung `true`, awtomatikong pinapagana ang tibok. <br> Kung `false`, hindi pagaganahin. | `true` |

</center>

---

## ⚙️ Mga Metodo

### `void update()`

**Layunin:** Panatilihing tumitibok ang output. Dapat itong tawagin sa loob ng `loop()` function ng sketch.

---

### `void setHeartbeat(HeartbeatLevel level)`

**Layunin:** Palitan ang kasalukuyang tibok interval.

<center>

| Parameter | Uri | Paliwanag | Mga Halagang Tinatanggap |
|----------|-----|----|----|
| `level` | `HeartbeatLevel` | Bagong antas ng tibok |  `EMERGENCY` <br> `CRITICAL` <br> `WARNING` <br> `NORMAL` |

</center>

---

### `void enable(bool enabled = true)`

**Layunin:** Pinapagana o pinapahinto ang tibok ng status indicator.

<center>

| Parameter | Uri | Paliwanag | Default |
|----------|-----|---|--------|
| `enabled` | `bool` | Kung `true`, pinapagana ang tibok. <br> Kung `false`, pinapahinto ito. | `true` |

</center>

---

### `void setActiveHigh(bool activeHigh)`

**Layunin:** Itinatakda kung active HIGH o LOW ang output.

<center>

| Parameter | Uri | Paliwanag | Default |
|----------|-----|----|-------|
| `activeHigh` | `bool` | Kung `true`, active HIGH ang output. <br> Kung `false`, active LOW. | `true` |

</center>

---

### `int getPin() const`

**Layunin:** Ibinabalik ang GPIO pin na ginagamit para sa status indicator.

---

### `String getLabel() const`

**Layunin:** Ibinabalik ang label na ginagamit para sa status indicator. Halimbawa, maaari itong gamitin para sa pag-debug o pagpapakita ng impormasyon tungkol sa tibok.

---

### `bool isActiveHigh() const`

**Layunin:** Ibinabalik kung active HIGH o LOW ang output.

---

### `bool isEnabled() const`

**Layunin:** Ibinabalik kung ang tibok ay pinagana o hindi.

---

### `bool getState() const`

**Layunin:** Ibinabalik ang kasalukuyang estado ng status indicator (HIGH o LOW).

---

### `unsigned long getLastToggle() const`

**Layunin:** Ibinabalik ang huling oras ng pagtibok sa milliseconds mula nang ito ay na-enable.

---

### `unsigned long getHeartbeat() const`

**Layunin:** Ibinabalik ang kasalukuyang tibok interval sa milliseconds.

---

## Enum: `HeartbeatLevel`

Predefined na tibok na mga delay (sa milliseconds):

<center>

| Enum | Value (*ms*) | Dalasan (*Hz*) | Paliwanag |
|------|-------|---------|-----------|
| `EMERGENCY` | `125` | **4** | Mabilis na tibok para sa matinding alerto |
| `CRITICAL` | `250` | **2** | Kritikal na tibok |
| `WARNING` | `500` | **1** | Babala |
| `NORMAL` | `1000` | **0.5** ( *1 ulit / 2 seg* ) | Pangkaraniwang tibok |

</center>

---

## 🧠 Mga Paalala sa Paggamit
Ilang mahahalagang detalye ukol sa maayos at inaasahang paggamit ng `Tibok` library.

### 🕒 Timing at Update Loop
- Ang `update()` ay *non-blocking*, kaya ligtas itong tawagin sa bawat `loop()` cycle.
- Iwasan ang `delay()` sa loob ng `loop()` kung ginagamit ang `update()`. Maaaring magdulot ito ng hindi pantay o nabibinbing tibok.
- Iminumungkahi ang paggamit ng `millis()`-*based logic* para sa ibang bahagi ng iyong sketch upang hindi makaapekto sa tibok.

### ⚙️ Dynamic Configuration
- Ligtas gamitin ang mga setter gaya ng `setHeartbeat()`, `setActiveHigh()`, at `enable()` kahit habang tumatakbo ang tibok.
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
