# ActiveLowHighHeartbeat Demo

Ang sketch na ito ay nagpapakita ng paggamit ng `Tibok` library upang makontrol ang dalawang LED: isa sa **Active LOW** (pin 13) at isa sa **Active HIGH** (pin 12). Ang parehong LED ay kikilos sa pattern ng `WARNING` heartbeat na may interval na 500ms.

### Paano Gumagana ang Sketch?

1. **Pin 13 (Active LOW)**  
   - Ang LED na nakakabit sa pin 13 ay nakakumpigura sa **Active LOW** logic. Ibig sabihin, magiging **ON** ang LED kapag ang signal ay **LOW**, at magiging **OFF** ito kapag ang signal ay **HIGH**.

2. **Pin 12 (Active HIGH)**  
   - Ang LED na nakakabit sa pin 12 ay nakakumpigura sa **Active HIGH** logic. Ibig sabihin, magiging **ON** ang LED kapag ang signal ay **HIGH**, at magiging **OFF** ito kapag ang signal ay **LOW**.

3. **Heartbeat Pattern**  
   - Ang parehong LED ay kikilos sa **`WARNING` heartbeat pattern** (500ms interval). Ibig sabihin, magpapalit-palit ang estado ng LED bawat 500 milliseconds.

### Layunin ng Demo

Ang demo na ito ay nagpapakita ng parehong **Active LOW** at **Active HIGH** configuration gamit ang dalawang LED, kung saan ipinapakita ang pag-toggle ng estado ng bawat LED (ON/OFF) batay sa kanilang respective logic states.

### Paano Gamitin:

1. **I-upload ang Sketch**: I-upload ang `ActiveLowHighHeartbeat.ino` sa iyong Arduino board. Siguraduhing nakakabit ang mga LED sa tamang pins (pin 13 para sa Active LOW at pin 12 para sa Active HIGH).
   
2. **Pagmasdan ang mga LED**: Ang mga LED lamang ang magpapakita ng estado batay sa kanilang logic level.

### Mga Detalye ng Sketch:

- **`Tibok invertedLED(13, WARNING, false)`**: Lumikha ng `Tibok` object para sa pin 13 gamit ang **Active LOW** logic.
- **`Tibok normalLED(12, WARNING, true)`**: Lumikha ng `Tibok` object para sa pin 12 gamit ang **Active HIGH** logic.
- **`update()`**: Tinatawag ang `update()` function sa bawat ikot ng `loop()` upang mapanatili ang tibok ng mga LED.

### Output:

Dahil walang serial output, ang mga LED na nakakabit sa pin 13 at pin 12 ay magpapalit-palit ng kanilang estado (ON/OFF) batay sa `WARNING` heartbeat pattern:

<center> 

| Logic Level | Pin 13 <br> (Active Low) | Pin 12 <br> (Active High) |
|-------------|-------------------------|--------------------------|
| LOW | ON | OFF |
| HIGH | OFF | ON |

</center>

### Kongklusyon:
Ang `ActiveLowHighHeartbeat Demo` ay isang halimbawa ng paggamit ng `Tibok` library upang kontrolin ang parehong **Active LOW** at **Active HIGH** LED configurations. Ipinapakita nito kung paano mag-toggle ng LED state batay sa bawat logic level, at magagamit ito upang maipakita ang pagkakaiba ng behavior ng Active LOW at Active HIGH LED setups.

## License

Ito ay bahagi ng ***Proyektong LundayHangin*** at sumusunod sa parehong license na inilatag para sa naturang proyekto.
