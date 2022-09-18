# BafangSpeedAdjust

Simple speed adjustment for my bafang motor using CAN BUS on my Veloretti ace

What do you need:

- Arduino Nano = <5 euro
- [MCP 2515 CAN module](https://www.amazon.nl/gp/product/B07MY2D7TW/) = 7 euro
- [Bafang 6 pin brake cable (Female)](https://www.aliexpress.com/item/1005004128109927.html) = 9 euro or [here](https://a.aliexpress.com/_EIiGmyn) = 5.57

Connect MCP 2515 and arduino like shown [here](https://github.com/autowp/arduino-mcp2515) (no need for power converter, power comes over usb to the arduino and can module):

Connect the brake cable to the MCP 2515 module (H = green cable, L= white cable)

Download the [MCP 2515 arduino library](https://github.com/autowp/arduino-mcp2515) and add to the arduino ide as described

Copy code demo in ino file (try reading without writing the speed setting check if read code starts with 82F83203, first characters could be different)

Remove plastic cover from motor with 3 torx screws
Connect the cable to the bafang motor (purple connector, bike can be switched on)
And plug the arduino with an usb cable into a computer or smartphone (If you want to read the serial output, if you don't want to read the output and just write the new setting a powerbank is fine. I use the app serial monitor on android, adjust the baudrate to 115200)
If all is connected correctly, you should see a lot of data passing by in the serial monitor.

If you wait 10 seconds (set in code), the speed will be set to 35km/h

!!! USE AT OWN RISK !!!
