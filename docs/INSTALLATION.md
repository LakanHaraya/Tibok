# `Tibok/` – *Installation, Verification, and Uninstallation*

Sa seksiyong ito, ipapakita ang mga hakbang upang matagumpay na ma-install, magamit, at ma-uninstall ang Tibok library.

- [Installation](#installation)  
  - [Paraan 1: Paggamit ng Arduino IDE (Manually)](#paraan-1-paggamit-ng-arduino-ide-manually)
  - [Paraan 2: Paggamit ng PlatformIO](#paraan-2-paggamit-ng-platformio)
- [Verification of Installation](#verification-of-installation)  
- [Uninstallation](#uninstallation)  
  - [Arduino IDE](#arduino-ide-manually) 
  - [PlatformIO](#platformio)  

---

## Installation

### Paraan 1: *Paggamit ng Arduino IDE (Manually)*

Dahil hindi pa available ang `Tibok/` library sa Arduino Library Manager, kinakailangang manu-manong i-install ito. Sundin ang mga hakbang na ito:

1. **I-download ang Library**  
   I-download ang `Tibok/` library zip file mula sa [Tibok Repository](https://github.com/LakanHaraya/Tibok.git).

2. **Buksan ang Arduino IDE**  
   I-launch ang Arduino IDE sa iyong computer.

3. **Magdagdag ng Library**  
   - Pumunta sa `Sketch` menu at piliin ang `Include Library` > `Add .ZIP Library...`.
   - Hanapin ang na-download na `Tibok` zip file at piliin ito.
   
    >   Matapos itong gawin, awtomatikong madadagdag ang library sa iyong Arduino IDE.

4. **I-verify ang Pagkakasunod ng Installation**  
   - Pumunta sa `Sketch` > `Include Library` at hanapin ang `Tibok` sa listahan ng mga available na library.  
   - Kung makikita mo ito, matagumpay na itong na-install.

### Paraan 2: *Paggamit ng PlatformIO*

1. **I-install ang PlatformIO**  
   Kung wala ka pang PlatformIO, i-install ito mula sa [PlatformIO website](https://platformio.org/) o gamit ang Visual Studio Code.

2. **I-clone ang Repository**  
   Buksan ang terminal at i-clone ang repository gamit ang git:
   ```bash
   git clone https://github.com/LakanHaraya/Tibok.git

3. **Idagdag ang Library sa PlatformIO Project**

   - Buksan ang iyong PlatformIO project.

   - Kopyahin ang buong `Tibok/` folder sa `lib/` directory ng iyong PlatformIO project.

4. **Gamitin ang Library sa iyong Code**

   - Sa iyong source file (.cpp o .ino), idagdag ang sumusunod na linya:

      ``` cpp
      #include <Tibok.h>
      ```
5. **I-build at I-upload ang Proyekto**  
   Matapos idagdag ang library, i-compile at i-upload ang iyong code sa iyong board.

---

## Verification of Installation

Upang matiyak na tama ang pag-install ng library, subukan ang isang halimbawa mula sa `examples/` folder. Maaari mong buksan ang isa sa mga halimbawa at i-upload ito sa iyong board.

---

## Uninstallation
Kung nais mong tanggalin ang library mula sa:

### Arduino IDE *(Manually)*:

1. **Buksan ang Arduino IDE**
I-launch ang Arduino IDE sa iyong computer.

2. **Pumunta sa Library Folder**

   - Pumunta sa `Sketch` > `Include Library` > `Manage Libraries...`.

   - Hanapin ang folder ng library sa pamamagitan ng `Sketch` > `Show Sketch Folder`.

   Ang iyong mga library ay matatagpuan sa `libraries/` directory ng Arduino IDE.

3. **Tanggalin ang Library Folder**

   - Sa loob ng `libraries/` folder, hanapin ang folder na pinangalanang `Tibok` (ito ang folder na naglalaman ng mga source code ng library).

   - I-delete ang `Tibok` folder upang alisin ang library.

### PlatformIO:

- Tanggalin ang folder ng `Tibok/` mula sa `lib/` directory ng iyong proyekto.
