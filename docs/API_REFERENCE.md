# 📘 `MuntingTibok/` – *API Reference*

Ito ang detalyadong talaan ng mga magagamit na API (Application Programming Interface) ng aklatan ng **MuntingTibok**.

---

## Talaan ng API

<center>

| API                               | Paggamit                                                              |
| :--                               | :--                                                                   |
| [`Tibok(...)`](#tibokint-pin-heartbeatlevel-level) | Konstruktor – paglikha ng halimbagay ng `Tibok` class                    |
| [`update()`](#void-update)         | Isinasapanahon ang tibok, kailangang tawagin sa loob ng `loop()`        |
| [`setHeartbeat(...)`](#void-setheartbeatheartbeatlevel-level) | Pinapalitan ang kasalukuyang antas ng tibok                            |
| [`enable(...)`](#void-enablebool-enabled)       | Pinapagana o pinapahinto ang tibok                                     |
| [`setActiveHigh(...)`](#void-setactivehighbool-activehigh)    | Itinatakda kung active HIGH o LOW ang output                            |
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

| Parameter | Uri | Paliwanag |
|----------|-----|-----------|
| `pin` | `int` | Arduino GPIO pin na kokontrolin |
| `level` | `HeartbeatLevel` | Inisyal na tibok level (e.g., `NORMAL`, `CRITICAL`) |
| `activeHigh` | `bool` | Kung `true`, active HIGH ang output. Kung `false`, active LOW (default: `true`) |
| `enabled` | `bool` | Kung `true`, awtomatikong pinapalakas ang tibok (default: `true`) |

</center>

---

## ⚙️ Mga Metodo

### `void update()`

**Layunin:** Panatilihing tumitibok ang output. Dapat itong tawagin sa loob ng `loop()` function ng sketch.

---

### `void setHeartbeat(HeartbeatLevel level)`

**Layunin:** Palitan ang kasalukuyang tibok interval.

<center>

| Parameter | Uri | Paliwanag |
|----------|-----|-----------|
| `level` | `HeartbeatLevel` | Bagong tibok level | 

</center>

---

### `void enable(bool enabled = true)`

**Layunin:** Pinapagana o pinapahinto ang tibok ng status indicator.

<center>

| Parameter | Uri | Paliwanag |
|----------|-----|-----------|
| `enabled` | `bool` | Kung `true`, pinapalakas ang tibok. Kung `false`, pinapahinto ito (default: `true`) |

</center>

---

### `void setActiveHigh(bool activeHigh)`

**Layunin:** Itinatakda kung active HIGH o LOW ang output.

<center>

| Parameter | Uri | Paliwanag |
|----------|-----|-----------|
| `activeHigh` | `bool` | Kung `true`, active HIGH ang output. Kung `false`, active LOW |

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

> ## 📝 Tandaan
>
> - Ang `update()` ay *non-blocking*, kaya ligtas tawagin sa bawat `loop()`.
> - Maaari mong gamitin ang `setHeartbeat()` kahit tumatakbo ang tibok.
> - Ang `enable()` ay ginagamit para mag-enable o mag-disable ng tibok.
> - Kung naka-`DISABLED`, walang LED toggling na magaganap.

---

## 📂 Kaugnay na File

- `src/MuntingTibok.h` – Ang mga deklarasyon ng API [dito](../src/MuntingTibok.h).
- `src/MuntingTibok.cpp` – Ang mga implementasyon ng API [dito](../src/MuntingTibok.cpp).

---

## 🧪 Tingnan din

Para sa aktuwal na paggamit ng API na ito, tingnan ang `examples/` folder [dito](../examples/).
