# ConstructorDemo

Ang sketch na ito ay nagpapakita ng iba't ibang paraan ng paggamit ng `Tibok`
constructor gamit ang magkakaibang bilang ng argumento. Layunin nitong ipakita
kung paano tumutugon ang library sa mga default at custom na configuration para sa
heartbeat level, active HIGH level, at enabled state.

### Paano Gumagana ang Sketch?

1. **Apat na Halimbagay ng `Tibok`**  
   - May apat na LED na nakakabit sa mga pin 2, 3, 4, at 5. Bawat isa ay may iba't ibang configuration batay sa constructor parameters:

<center>

   | Halimbagay | Pin | `HeartbeatLevel` | `activeHigh` | `enabled` |
   |-----------|-----|------------------|--------------|---------|
   | `tibok2`  | 2   | `NORMAL` (default)   | `true` (default) | `true` (default) |
   | `tibok3`  | 3   | `WARNING`            | `true` (default) | `true` (default) |
   | `tibok4`  | 4   | `CRITICAL`           | `true`           | `true` (default) |
   | `tibok5`  | 5   | `EMERGENCY`          | `true`           | `true`           |

</center>

2. **Heartbeat Pattern**  
   - Ang bawat LED ay magpapalit-palit ng estado (ON/OFF) batay sa kanilang `HeartbeatLevel` intervals.

3. **Walang Karagdagang Setup**  
   - Ang lahat ng pin configuration ay awtomatikong isinasagawa ng constructor (ang `pinMode()` at initial `digitalWrite()`).

### Layunin ng Demo

- Ipakita kung paano gumagana ang overloading ng constructor sa `Tibok` library.
- Maunawaan kung paano ginagamit ang default values at paano ito ma-override sa pamamagitan ng iba't ibang parameter.

### Paano Gamitin:

1. **I-upload ang Sketch**: I-upload ang `ConstructorDemo.ino` sa iyong Arduino board. Siguraduhing may LED na nakakabit sa pins 2, 3, 4, at 5 (gamit ang tamang resistor).
2. **Pagmasdan ang Asal ng LED**: Ang bawat LED ay kikilos ayon sa kanilang nakatakdang heartbeat pattern.

### Mga Detalye ng Sketch:

- **`Tibok tibok2(2)`**: Itinakda ang unang parameter at default values sa tatlong huling parameter.
- **`Tibok tibok3(3, WARNING)`**: Itinakda ang unang dalawang parameter at default values sa dalawang huling parameter.
- **`Tibok tibok4(4, CRITICAL, true)`**: Itinakda ang unang tatlong parameter at default values sa huling parameter.
- **`Tibok tibok5(5, EMERGENCY, true, true)`**: Kompletong custom configuration.

### Output:

Ang apat na LED ay magpapalit-palit ng estado sa iba't ibang bilis depende sa kanilang heartbeat level. Halimbawa:

<center>

| `HeartbeatLevel` | Hatimpuktol <br> (Half-Period) |
|:---------------:|:----------:|
| `NORMAL`        | 1000ms   |
| `WARNING`       | 500ms    |
| `CRITICAL`      | 250ms    |
| `EMERGENCY`     | 125ms    |

</center>

### Kongklusyon:

Ang `ConstructorDemo` ay isang mahalagang halimbawa ng flexibility ng `Tibok` constructor. Sa pamamagitan ng iba't ibang configuration, maipapakita kung gaano kadaling gamitin ang library upang lumikha ng LED indicators na tumutugon sa antas ng alerto o estado ng isang sistema.

## License

Ito ay bahagi ng ***Proyektong LundayHangin*** at sumusunod sa parehong license na inilatag para sa naturang proyekto.
