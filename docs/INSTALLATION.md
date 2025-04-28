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

#### Hakbang 1: I-download ang Library

- Bisitahin ang **GitHub repository** ng library [dito](https://github.com/LakanHaraya/Tibok.git).

- I-click ang **Download ZIP** na button upang i-download ang `.zip` file ng library.

#### Hakbang 2: Buksan ang Arduino IDE

- Buksan ang iyong **Arduino IDE** sa iyong computer.

#### Hakbang 3: Magdagdag ng Library
- Pumunta sa `Sketch` menu.

- Piliin ang `Include Library` > `Add .ZIP Library...`.

- Hanapin ang na-download na `.zip` file ng library mula sa iyong file explorer at piliin ito.

- Awtomatikong idaragdag ng Arduino IDE ang library at makikita mo ito sa `Sketch` > `Include Library` menu.

#### Hakbang 4: I-verify ang Pagkakasunod ng Installation
- Pumunta sa `Sketch` > `Include Library`.

- Hanapin ang pangalan ng `Tibok` library. 

- Kung nakita mo ito sa listahan ng mga available na libraries, matagumpay na itong na-install.

### Paraan 2: *Paggamit ng PlatformIO*

- **I-install ang PlatformIO**  
   Kung wala ka pang PlatformIO, i-install ito mula sa [PlatformIO website](https://platformio.org/) o gamit ang Visual Studio Code.

- **I-clone ang Repository**  
   Buksan ang terminal at i-clone ang repository gamit ang git:
   ```bash
   git clone https://github.com/LakanHaraya/Tibok.git
   ```

- **Idagdag ang Library sa PlatformIO Project**

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

#### Hakbang 1: Hanapin ang Folder ng Library
- Pumunta sa iyong **Arduino libraries folder**:

   - **Windows:** `Documents/Arduino/libraries/`

   - **macOS:** `~/Documents/Arduino/libraries/`

   - **Linux:** `~/Arduino/libraries/`

- Sa folder na `libraries/`, hanapin ang `Tibok` library.

#### Hakbang 2: Tanggalin ang Library
- Kapag nakita mo na ang folder ng library, **i-delete** ito.

   - I-right-click ang folder ng library at piliin ang **Delete** o **Move to Trash** (depende sa iyong operating system).

#### Hakbang 3: I-restart ang Arduino IDE
- Pagkatapos tanggalin ang folder ng library, **i-restart ang Arduino IDE** upang matanggal ang library mula sa IDE.

#### Hakbang 4: I-verify ang Uninstallation
- Pumunta sa `Sketch` > `Include Library`.

- I-check kung wala nang entry para sa `Tibok` library.

- Kung hindi mo na ito makita sa listahan ng mga library, matagumpay na itong na-uninstall.

### PlatformIO:

- Tanggalin ang folder ng `Tibok/` mula sa `lib/` directory ng iyong proyekto.
