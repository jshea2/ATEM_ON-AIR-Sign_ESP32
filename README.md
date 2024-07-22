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