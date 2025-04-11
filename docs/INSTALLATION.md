# `MuntingTibok/` – *Installation, Verification, and Uninstallation*

Sa seksiyong ito, ipapakita ang mga hakbang upang matagumpay na ma-install, magamit, at ma-uninstall ang MuntingTibok library.

- [Installation](#installation)  
  - ~~Paraan 1: Paggamit ng Arduino IDE~~
  - [Paraan 2: Paggamit ng PlatformIO](#paraan-2-paggamit-ng-platformio)
- [Verification of Installation](#verification-of-installation)  
- [Uninstallation](#uninstallation)  
  - ~~Arduino IDE~~ 
  - [PlatformIO](#platformio)  

---
## Installation

### ~~Paraan 1: *Paggamit ng Arduino IDE*~~

<!-- 1. **I-download ang Library**  
   I-download ang `MuntingTibok` library zip file mula sa [MuntingTibok Repository](https://github.com/LakanHaraya/MuntingTibok.git).

2. **Buksan ang Arduino IDE**  
   I-launch ang Arduino IDE sa iyong computer.

3. **Magdagdag ng Library**  
   - Pumunta sa `Sketch` menu at piliin ang `Include Library` > `Add .ZIP Library...`.
   - Hanapin ang na-download na `MuntingTibok` zip file at piliin ito.
   
    >   Matapos itong gawin, awtomatikong madadagdag ang library sa iyong Arduino IDE.

4. **I-verify ang Pagkakasunod ng Installation**  
   - Pumunta sa `Sketch` > `Include Library` at hanapin ang `MuntingTibok` sa listahan ng mga available na library.  
   - Kung makikita mo ito, matagumpay na itong na-install. -->

### Paraan 2: *Paggamit ng PlatformIO*

1. **I-install ang PlatformIO**  
   Kung wala ka pang PlatformIO, i-install ito mula sa [PlatformIO website](https://platformio.org/) o gamit ang Visual Studio Code.

2. **I-clone ang Repository**  
   Buksan ang terminal at i-clone ang repository gamit ang git:
   ```bash
   git clone https://github.com/LakanHaraya/MuntingTibok.git
   ```

3. **Idagdag ang Library sa PlatformIO Project**

   - Buksan ang iyong PlatformIO project.
   - Kopyahin ang buong `MuntingTibok` folder sa `lib/` directory ng iyong PlatformIO project.

4. **Gamitin ang Library sa iyong Code**

   - Sa iyong source file (.cpp o .ino), idagdag ang sumusunod na linya:

   ``` cpp
   #include <MuntingTibok.h>
   ```

5. **I-build at I-upload ang Proyekto**
Matapos idagdag ang library, i-compile at i-upload ang iyong code sa iyong board.

## Verification of Installation
Upang matiyak na tama ang pag-install ng library, subukan ang isang halimbawa mula sa [`examples/`](../examples/) folder. Maaari mong buksan ang isa sa mga halimbawa at i-upload ito sa iyong board.

## Uninstallation
Kung nais mong tanggalin ang library mula sa ~~*Arduino IDE* o~~ *PlatformIO*, sundin ang mga sumusunod:

### ~~*Arduino IDE:*~~
<!-- - Pumunta sa `Sketch` > `Include Library` > `Manage Libraries...`

- Hanapin ang `MuntingTibok` at i-click ang **"Remove"** button. -->

### *PlatformIO:*
- Tanggalin ang folder ng `MuntingTibok` mula sa `lib/` directory ng iyong proyekto.

