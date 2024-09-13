# NXP Application Code Hub
[<img src="https://mcuxpresso.nxp.com/static/icon/nxp-logo-color.svg" width="100"/>](https://www.nxp.com)

## FRDM RW612 Kitchen Timer

This demo shows a kitchen timer that has a config screen to set the timer, date and color


#### Boards: FRDM-RW612
#### Categories: Graphics, HMI, RTOS
#### Peripherals: DISPLAY
#### Toolchains: MCUXpresso IDE

## Table of Contents
1. [Software](#step1)
2. [Hardware](#step2)
3. [Setup](#step3)
4. [Results](#step4)
5. [FAQs](#step5)
6. [Support](#step6)
7. [Release Notes](#step7)

## 1. Software<a name="step1"></a>
This code has been implemented using MCUXpresso IDE version 11.9.0. LVGL (version 8.3.10) and all other software is included in MCUXpresso SDK - version 2.16.0 was used.

## 2. Hardware<a name="step2"></a>
- Purchase supported board:
    - [FRDM-RW612](https://www.nxp.com/)

- Purchase supported display:
    - [LCD-PAR-S035](https://www.nxp.com/part/LCD-PAR-S035#/)

## 3. Setup<a name="step3"></a>

### 3.1 Step 1
Import the project into MCUXpresso IDE by following the following sections of the "MCUXpresso IDE - User Guide" found in the documentation section of the [MCUXpresso IDE page](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools-/mcuxpresso-integrated-development-environment-ide:MCUXpresso-IDE):

### 3.2 Step 2

Connect the Low Cost Display to the board as shown in the following image:

Low Cost Display:

[<img src="./doc/images/LCD_Connection.png" width="800"/>](./doc/images/LCD_Connection.png)

Make sure the LCD is configured to use SPI 4-wire

[<img src="./doc/images/SPI_4_wire.png" width="800"/>](./doc/images/SPI_4_wire.png)

Connect the USB's type C from J10(MCU-LINK) to the computer as shown in the following image:

[<img src="./doc/images/USB.png" width="800"/>](./doc/images/USB.png)

### 3.3 Step 3

Press Alt+Enter to open properties and set the display macro to use the mounted board

LCD-PAR0S035=1

as shown in the following image:
[<img src="./doc/images/Settings.png" width="800"/>](./doc/images/Settings.png)

### 3.4 Step 4

Build and download the Demo to the board

## 4. Results<a name="step4"></a>
Now you can interact with the Kitchen Timer by setting a new timer, a new date and a new color.

[<img src="./doc/images/Init_Screen.png" width="800"/>](./doc/images/Init_Screen.png)

[<img src="./doc/images/Settings_Screen.png" width="800"/>](./doc/images/Settings_Screen.png)

[<img src="./doc/images/Change_Color.png" width="800"/>](./doc/images/Change_Color.png)

[<img src="./doc/images/Set_Timer.png" width="800"/>](./doc/images/Set_Timer.png)

[<img src="./doc/images/Timer.png" width="800"/>](./doc/images/Timer.png)

[<img src="./doc/images/Date.png" width="800"/>](./doc/images/Date.png)

also you can view the Kitchen Timer on a terminal.

[<img src="./doc/images/Terminal.png" width="800"/>](./doc/images/Terminal.png)



## 5. FAQs<a name="step5"></a>

## 6. Support<a name="step6"></a>
If you have any questions or feedback on this code please contact NXP support or post on our community at https://community.nxp.com/. You can find forums here for different aspects of this code example, including GUI Guider, MCUXpresso tools and device families.


#### Project Metadata

<!----- Boards ----->
[![Board badge](https://img.shields.io/badge/Board-FRDM&ndash;RW612-blue)](https://www.nxp.com/pip/RW612)

<!----- Categories ----->
[![Category badge](https://img.shields.io/badge/Category-GRAPHICS-yellowgreen)](https://github.com/search?q=org%3Anxp-appcodehub+graphics+in%3Areadme&type=Repositories)
[![Category badge](https://img.shields.io/badge/Category-HMI-yellowgreen)](https://github.com/search?q=org%3Anxp-appcodehub+hmi+in%3Areadme&type=Repositories)
[![Category badge](https://img.shields.io/badge/Category-RTOS-yellowgreen)](https://github.com/search?q=org%3Anxp-appcodehub+rtos+in%3Areadme&type=Repositories)

<!----- Peripherals ----->
[![Peripheral badge](https://img.shields.io/badge/Peripheral-DISPLAY-yellow)](https://github.com/search?q=org%3Anxp-appcodehub+display+in%3Areadme&type=Repositories)

<!----- Toolchains ----->
[![Toolchain badge](https://img.shields.io/badge/Toolchain-MCUXPRESSO%20IDE-orange)](https://github.com/search?q=org%3Anxp-appcodehub+mcux+in%3Areadme&type=Repositories)

Questions regarding the content/correctness of this example can be entered as Issues within this GitHub repository.

>**Warning**: For more general technical questions regarding NXP Microcontrollers and the difference in expected functionality, enter your questions on the [NXP Community Forum](https://community.nxp.com/)

[![Follow us on Youtube](https://img.shields.io/badge/Youtube-Follow%20us%20on%20Youtube-red.svg)](https://www.youtube.com/NXP_Semiconductors)
[![Follow us on LinkedIn](https://img.shields.io/badge/LinkedIn-Follow%20us%20on%20LinkedIn-blue.svg)](https://www.linkedin.com/company/nxp-semiconductors)
[![Follow us on Facebook](https://img.shields.io/badge/Facebook-Follow%20us%20on%20Facebook-blue.svg)](https://www.facebook.com/nxpsemi/)
[![Follow us on Twitter](https://img.shields.io/badge/X-Follow%20us%20on%20X-black.svg)](https://x.com/NXP)

## 7. Release Notes<a name="step7"></a>
| Version | Description / Update                           | Date                        |
|:-------:|------------------------------------------------|----------------------------:|
| 1.0     | Initial release on Application Code Hub        | August 6<sup>th</sup> 2024 |

<small>
<b>Trademarks and Service Marks</b>: There are a number of proprietary logos, service marks, trademarks, slogans and product designations ("Marks") found on this Site. By making the Marks available on this Site, NXP is not granting you a license to use them in any fashion. Access to this Site does not confer upon you any license to the Marks under any of NXP or any third party's intellectual property rights. While NXP encourages others to link to our URL, no NXP trademark or service mark may be used as a hyperlink without NXP’s prior written permission. The following Marks are the property of NXP. This list is not comprehensive; the absence of a Mark from the list does not constitute a waiver of intellectual property rights established by NXP in a Mark.
</small>
<br>
<small>
NXP, the NXP logo, NXP SECURE CONNECTIONS FOR A SMARTER WORLD, Airfast, Altivec, ByLink, CodeWarrior, ColdFire, ColdFire+, CoolFlux, CoolFlux DSP, DESFire, EdgeLock, EdgeScale, EdgeVerse, elQ, Embrace, Freescale, GreenChip, HITAG, ICODE and I-CODE, Immersiv3D, I2C-bus logo , JCOP, Kinetis, Layerscape, MagniV, Mantis, MCCI, MIFARE, MIFARE Classic, MIFARE FleX, MIFARE4Mobile, MIFARE Plus, MIFARE Ultralight, MiGLO, MOBILEGT, NTAG, PEG, Plus X, POR, PowerQUICC, Processor Expert, QorIQ, QorIQ Qonverge, RoadLink wordmark and logo, SafeAssure, SafeAssure logo , SmartLX, SmartMX, StarCore, Symphony, Tower, TriMedia, Trimension, UCODE, VortiQa, Vybrid are trademarks of NXP B.V. All other product or service names are the property of their respective owners. © 2021 NXP B.V.
</small>
