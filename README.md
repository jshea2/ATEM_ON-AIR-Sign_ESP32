
# ATEM_ON AIR Sign_ESP32

Trigger ON AIR Sign to turn on when ATEM is streaming and turn off when ATEM has ended streaming

https://github.com/user-attachments/assets/93a61eb2-cb9a-4f0a-9d0c-53f0e3ab7c55


Hardware Requirements:
- [ON AIR sign](https://www.amazon.com/Air-Light-Wall-Mountable-Desktop/dp/B096H44MTL/)
- [ESP32](https://www.amazon.com/ESP-WROOM-32-Development-Microcontroller-Integrated-Compatible/dp/B08D5ZD528/)
- [5V 1ch Relay](https://www.amazon.com/dp/B00LW15A4W?psc=1&ref=ppx_yo2ov_dt_b_product_details)
- [Micro USB Cable](https://www.amazon.com/Charging-Transfer-Android-Trustable-MYFON/dp/B098DW7485/)
- [Breadboard Jumper Wire](https://www.amazon.com/Elegoo-EL-CP-004-Multicolored-Breadboard-arduino/dp/B01EV70C78/)
- Soldering Iron
- ATEM Switcher
- Router

Hardware Setup:
- ATEM must be connected to a router in the same IP range as the ESP32
- Wiring Diagram:
![IMG_0825](https://github.com/user-attachments/assets/445e708b-613e-4e35-aa15-b1a5496f4aee)
- ESP32 Pin 15 -> Relay DI
- Relay Power In + - soldered to led strip
- ESP32 plug in micro usb cable then strip and soldered to + - led strip
- Relay Com -> soldered to - led strip
- Relay NO (Normally Open) -> soldered to R1 led strip
-   Careful the resistors might come off

-   Note: If you're flashing the ESP32 from your computer and trying to test this should only print the ATEM status, but not trigger the relay, because the rest is from a different power source then the relay won't trigger because it's not the same ground COM.


Software Setup Requirements:
- Visual Studio Code
- PlatformIO
  - Enable VSCode Extension

- Replace ***SSID***, ***Password***, and ***ATEM IP*** with your info:

  - **main.cpp**
-   ```// WiFi credentials
    const char* ssid = "SSID";  // Replace with your SSID
    const char* password = "password";  // Replace with your password

    // ATEM device IP address
    const IPAddress atemIP(192, 168, 10, 240); // Replace with your ATEM IP Address
    ```

- Upload to ESP32
