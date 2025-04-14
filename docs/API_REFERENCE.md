# 📘 `MuntingTibok/` – *API Reference*

Ito ang detalyadong talaan ng mga magagamit na API (Application Programming Interface) ng aklatan ng **MuntingTibok**.

---

## Talaan ng Nilalaman

<center>

| API | Paggamit |
| :-- | :-- |
| [`MuntingTibok(...)`](#muntingtibokint-pin-heartbeatlevel-level) | Konstruktor – paglikha ng halimbagay |
| [`begin(bool)`](#void-beginbool-activehigh--true) | Itinatakda kung active HIGH o LOW |
| [`update()`](#void-update) | Isinasapanahon ang tibok |
| [`setLevel(...)`](#void-setlevelheartbeatlevel-level) | Pinapalitan ang antas ng tibok |
| [`disable()`](#void-disable) | Pansamantalang pinipindi ang indikador |
| [`enable()`](#void-enable) | Pinapagana muli ang tibok |
| [`HeartbeatLevel`](#enum-heartbeatlevel) | Enum ng mga predefined na antas ng tibok |

</center>

---

## 🏗️ Konstruktor

### `MuntingTibok(int pin, HeartbeatLevel level)`

**Layunin:** Gumawa ng bagong `MuntingTibok` object.

<center>

| Parameter | Uri | Paliwanag |
|----------|-----|-----------|
| `pin` | `int` | Arduino GPIO pin na kokontrolin |
| `level` | `HeartbeatLevel` | Inisyal na tibok level (e.g., `NORMAL`, `CRITICAL`) |

</center>

---

## ⚙️ Mga Metodo

### `void begin(bool activeHigh = true)`

**Layunin:** Isaaktibo ang object at itakda kung HIGH o LOW ang aktibong estado ng output.

<center>

| Parameter | Uri | Paliwanag |
|----------|-----|-----------|
| `activeHigh` | `bool` | `true` kung HIGH ang aktibong signal, `false` kung LOW |

</center>

---

### `void update()`

**Layunin:** Panatilihing tumitibok ang output. Dapat itong tawagin sa loob ng `loop()` function ng sketch.

---

### `void setLevel(HeartbeatLevel level)`

**Layunin:** Palitan ang kasalukuyang tibok interval.

<center>

| Parameter | Uri | Paliwanag |
|----------|-----|-----------|
| `level` | `HeartbeatLevel` | Bagong tibok level |

</center>

---

### `void disable()`

**Layunin:** Itigil ang tibok at itakda ang output sa inactive state.

---

### `void enable()`

**Layunin:** Muling paganahin ang tibok kung ito ay na-disable.

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
| `DISABLED` | `-1` | ~ | Walang tibok |

</center>

---

> ## 📝 Tandaan
>
> - Ang `update()` ay *non-blocking*, kaya ligtas tawagin sa bawat `loop()`.
> - Maaari mong gamitin ang `setLevel()` kahit tumatakbo ang tibok.
> - Kung naka-`DISABLED`, walang LED toggling na magaganap.

---

## 📂 Kaugnay na File

- `src/MuntingTibok.h` – Ang mga deklarasyon ng API [dito](../src/MuntingTibok.h).
- `src/MuntingTibok.cpp` – Ang mga implementasyon ng API [dito](../src/MuntingTibok.cpp).

---

## 🧪 Tingnan din

Para sa aktuwal na paggamit ng API na ito, tingnan ang `examples/` folder [dito](../examples/).

