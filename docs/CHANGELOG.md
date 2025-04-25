# 📝 CHANGELOG

Lahat ng mahahalagang pagbabago sa **Tibok** ay idodokumento sa file na ito.

Ang format na ito ay batay sa [Keep a Changelog](https://keepachangelog.com/en/1.0.0/) at sumusunod sa [Semantic Versioning](https://semver.org/).

---

## [Unreleased] - 2025-04-25

### Idinagdag
- Idinagdag ang mga bagong getter method: `getPin()`, `isActiveHigh()`, `isEnabled()`, `getState()`, `getLastToggle()`, at `getHeartbeat`.
- Dinagdagan ng parameter ang `enable()` para suportahan ang disable.
- Dinagdagan ng parameter ang `Tibok` para suportahan ang `level`, `activeHigh`, at `enabled`, kasama ang mga default value nito.

### Pinalitan
- Pinalitan ang pangalan ng buong library bilang `Tibok`
- Pinalitan ang tawag sa `setLevel` at ginawang `setHeartbeat()`.

### Tinanggal
- Tinanggal ang `DISABLED` mula sa `HeartbeatLevel`.
- Tinanggal ang `begin()` dahil sinusuportahan na ito sa konstruktor.
- Tinanggal ang `disable()` dahil sinusuportahan na ito sa `enable()`.

### Inayos
- Pangkalahatang pagsasaayos ng mga dokumentasyon at halimbawa.

---

## [1.0.0] - 2025-04-11

### Idinagdag

- Inilabas ang `MuntingTibok` bilang isang minimalistikong bersiyon ng `LundayTibokAkl`.
- Idinagdag ang `HeartbeatLevel` enum batay sa IEC 60073:2002.
- Idinagdag ang `update()` method para sa patuloy na pagtibok.
- Idinagdag ang `enable()` at `disable()` para sa kontrol ng estado.
- Idinagdag ang `begin()` method para sa pagsisimula ng operasyon.
- Idinagdag ang kakayahang tukuyin kung active HIGH o LOW ang pin.
- Idinagdag ang `setLevel()` para sa runtime switching ng tibok.