# WithChainedMethods Demo

Ang sketch na ito ay nagpapakita ng paggamit ng chaining method sa `Tibok/` library upang kontrolin ang isang LED gamit ang iba't ibang mga setting ng **Heartbeat** pattern. Sa halimbawa na ito, ang LED ay nakakabit sa **Pin 13** at tumitibok sa isang **250ms interval** gamit ang **Active LOW logic** (LOW = ON).

### Paano Gumagana ang Sketch?

1. **Pin 13 (Active LOW)**  
   - Ang LED na nakakabit sa pin 13 ay nakakumpigura sa **Active LOW** logic. Ibig sabihin, magiging **ON** ang LED kapag ang signal ay **LOW**, at magiging **OFF** ito kapag ang signal ay **HIGH**.

2. **Heartbeat Pattern**  
   - Ang LED ay tumitibok sa **"CRITICAL" heartbeat pattern**, na may interval na **250ms**. Ibig sabihin, ang LED ay magpapalit-palit mula **ON** (LOW) papuntang **OFF** (HIGH) kada 250ms.

3. **Chaining Configuration**  
   - Ginagamit ang chaining method upang madaling iset ang mga configuration ng Tibok object sa isang linya ng code. Sa sketch na ito, tatlong configuration ang isinagawa:
     - **Active LOW logic**
     - **CRITICAL heartbeat level**
     - **Enable heartbeat signal**

### Layunin ng Demo

Ang demo na ito ay isang halimbawa ng paggamit ng **method chaining** sa `Tibok/` library upang mabilis at madali ang pag-configure ng mga settings ng LED tulad ng logic, heartbeat level, at enable state.

### Paano Gamitin:

1. **I-upload ang Sketch**: I-upload ang `WithChainedMethods.ino` sa iyong Arduino board. Siguraduhing nakakabit ang isang LED sa pin 13.
   
2. **Pagmasdan ang LED**: Ang LED ay magpapalit-palit ng estado batay sa heartbeat pattern na nakatakda sa pamamagitan ng chaining configuration.

### Mga Detalye ng Sketch:

- **`Tibok tibok(13)`**: Lumikha ng `Tibok` object para sa pin 13 na may default na **NORMAL heartbeat** (1000ms interval) at **Active HIGH** logic.
- **Chaining Method**: Ang mga sumusunod na configuration ay ginawa gamit ang chaining:
  - `activeHigh(false)`: Itinatakda ang logic level sa Active LOW.
  - `heartbeat(CRITICAL)`: Itinatakda ang heartbeat level sa CRITICAL (250ms interval).
  - `enable(true)`: Ipinagpapahintulot ang tibok ng LED (heartbeat signal).
- **`update()`**: Tinatawag ang `update()` function sa bawat ikot ng `loop()` upang mapanatili ang tibok ng LED.

### Output:

Ang Serial Monitor ay maglalabas ng mga sumusunod na impormasyon:

```sh
Sinimulan ang Tibok
Pin: 13
Antas ng Tibok: KRITIKAL
Aktibong Mataas: DIPO
Pinagana: OPO
```

### Kongklusyon:

Ang `WithChainedMethods Demo` ay isang halimbawa ng paggamit ng **method chaining** sa `Tibok/` library upang mabilis na i-configure ang iba't ibang mga setting ng heartbeat signal sa LED. Pinapadali nito ang pag-set ng configurations tulad ng **Active LOW logic**, **CRITICAL heartbeat pattern**, at **enable state** sa isang streamlined na syntax.

## License

Ito ay bahagi ng ***Proyektong LundayHangin*** at sumusunod sa parehong license na inilatag para sa naturang proyekto.
