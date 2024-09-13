Overview
========

This project is used to work with LittleVGL GUI Guider. The GUI Guider generated
code is placed in the folder "generated". The example generated code shows a
button in the panel.

SDK version
===========
- Version: 2.16.000

Toolchain supported
===================
- Keil MDK  5.38.1
- IAR embedded Workbench  9.50.1
- MCUXpresso  11.9.0
- GCC ARM Embedded  12.3.1

Hardware requirements
=====================
- Micro USB cable
- FRDM-RW612 board
- Personal Computer
- Adafruit TFT LCD shield w/Cap Touch
- LCD-PAR-S035 panel

Board settings
==============
There are different versions of Adafruit 2.8" TFT LCD shields. The shields marked
v2.0 works directly with this project. For the other shields, please solder
the center pin of IOREF pads to the 3.3V pad, and solder the pads 11, 12, and 13.
See the link for details:
https://community.nxp.com/t5/MCUXpresso-Community-Articles/Modifying-the-latest-Adafruit-2-8-quot-LCD-for-SDK-graphics/ba-p/1131104

To use Adafruit panel:
- Attach the LCD shield to the board Arduino header.
- Wire SJ14
To use LCD-PAR-S035:
- Set the switch SW1 on LCD-PAR-S035 to 111.
- Attach the LCD to PMOD(J7).

Prepare the Demo
================
To use Adafruit panel: define DEMO_PANEL as DEMO_PANEL_ADAFRUIT_2_8 in display_support.h

To use LCD-PAR-S035: define DEMO_PANEL as DEMO_PANEL_LCD_PAR_S035 in display_support.h

1.  Connect a micro USB cable between the PC host and the MCU-Link USB port (J10) on the board.
2.  Open a serial terminal with the following settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3.  Download the program to the target board.
4.  Launch the debugger in your IDE to begin running the example.

Running the demo
================
If this example runs correctly, the sample GUI is displayed.
