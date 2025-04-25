# BasicHeartbeat Demo

Ang sketch na ito ay nagpapakita ng pinakapayak na paggamit ng `Tibok` library upang kontrolin ang isang LED gamit ang default na **Heartbeat** pattern. Sa halimbawa na ito, ang LED ay nakakabit sa **Pin 13** at tumitibok sa isang **1000ms interval** gamit ang **Active HIGH logic** (HIGH = ON).

### Paano Gumagana ang Sketch?

1. **Pin 13 (Active HIGH)**  
   - Ang LED na nakakabit sa pin 13 ay nakakumpigura sa **Active HIGH** logic. Ibig sabihin, magiging **ON** ang LED kapag ang signal ay **HIGH**, at magiging **OFF** ito kapag ang signal ay **LOW**.

2. **Heartbeat Pattern**  
   - Ang LED ay tumitibok sa **"NORMAL" heartbeat pattern**, na may interval na **1000ms**. Ibig sabihin, ang LED ay magpapalit-palit mula **ON** (HIGH) papuntang **OFF** (LOW) kada isang segundo.

### Layunin ng Demo

Ang demo na ito ay isang simpleng halimbawa kung paano gamitin ang `Tibok` library upang kontrolin ang isang LED gamit ang **Active HIGH** logic at ang default na **`NORMAL` heartbeat pattern** (1000ms interval).

### Paano Gamitin:

1. **I-upload ang Sketch**: I-upload ang `BasicHeartbeat.ino` sa iyong Arduino board. Siguraduhing nakakabit ang isang LED sa pin 13.
   
2. **Pagmasdan ang LED**: Ang LED lamang ang magpapakita ng estado batay sa heartbeat pattern.

### Mga Detalye ng Sketch:

- **`Tibok tibok(13, NORMAL)`**: Lumikha ng `Tibok` object para sa pin 13 gamit ang default na **NORMAL heartbeat** (1000ms interval) at **Active HIGH** logic.
- **`update()`**: Tinatawag ang `update()` function sa bawat ikot ng `loop()` upang mapanatili ang tibok ng LED.

### Output:

Dahil walang serial output, ang LED na nakakabit sa pin 13 ay magpapalit-palit ng kaniyang estado (ON/OFF) batay sa **`NORMAL` heartbeat pattern**:

<center>

| Logic Level | Pin 13 <br> (Active High) |
|-------------|--------------------------|
| LOW         | OFF                      |
| HIGH        | ON                       |
| LOW         | OFF                      |
| HIGH        | ON                       |
| LOW         | OFF                      |
| HIGH        | ON                       |

</center>

### Kongklusyon:
Ang `BasicHeartbeat Demo` ay isang simpleng halimbawa ng paggamit ng `Tibok` library upang kontrolin ang isang LED gamit ang **Active HIGH** logic at **`NORMAL` heartbeat pattern**. Ipinapakita nito kung paano mag-toggle ng LED state sa isang regular na interval (1000ms) gamit ang default na setting ng library.

## License

Ito ay bahagi ng ***Proyektong LundayHangin*** at sumusunod sa parehong license na inilatag para sa naturang proyekto.
