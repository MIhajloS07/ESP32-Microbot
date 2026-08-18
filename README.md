# NM245 Microbot
[![Arduino](https://img.shields.io/badge/Arduino-IDE-blue?logo=arduino)](https://www.arduino.cc/)
[![ESP32](https://img.shields.io/badge/ESP32-DevKit-orange?logo=espressif)](https://www.espressif.com/en/products/socs/esp32)
[![C++](https://img.shields.io/badge/C++-Language-green?logo=c%2B%2B)](https://isocpp.org/)
[![KiCad](https://img.shields.io/badge/KiCad-Schematic-lightgrey?logo=kicad)](https://www.kicad.org/)

## Overview
**NM245 Microbot** is an interactive robot developed with the **ESP32 Dev Module**.  
It is programmed using the **Arduino framework** with **C++ language**, combining hardware integration and algorithmic logic to simulate the behavior and personality traits of modern robots.  
The project demonstrates how embedded systems can be designed to react to environmental changes, express emotions, and interact with users in a friendly and engaging way.

<p align="center">
<img width="300" height="300" alt="1666364456Esp32_devkitc_v4" src="https://github.com/user-attachments/assets/948a674b-1928-41d9-a067-4903e96b06b5" />
</p>

## Hardware
Microbot integrates multiple sensors and actuators to create expressive and interactive behavior:

- **ESP32 Dev Module** – main controller.
- **OLED Display (SSD1306, I²C)** – expressive eyes and emotional states.
- **TM1637 4-digit display** – text and numeric output.
- **DFPlayer Mini + Speaker** – sound effects and voice reactions.
- **Touch sensor (TTP223)** – tactile interaction.
- **KY-037 microphone sensor** – detects loud sounds and triggers responses.
- **DHT11 temperature sensor** – measures ambient temperature and influences robot mood.
- **RGB LED (common anode)** – visualizes emotions with color.
- **Button (GPIO32)** – triggers “refren mode” with music and dancing eyes.

### Pinout
| Component        | ESP32 Pin |
|------------------|-----------|
| TM1637 CLK       | GPIO18    | 
| TM1637 DIO       | GPIO19    |
| Touch Sensor     | GPIO4     | 
| Sound Sensor     | GPIO34 (ADC) |
| RGB LED Red      | GPIO25    |
| RGB LED Green    | GPIO26    |
| RGB LED Blue     | GPIO27    |
| DHT11 Data       | GPIO23    |
| DFPlayer RX      | GPIO16 (ESP32 RX) |
| DFPlayer TX      | GPIO17 (ESP32 TX via ~2kΩ resistor) |
| Music Button     | GPIO15    |
| OLED SDA         | GPIO21    |
| OLED SCL         | GPIO22    |

---

## Software
<table>
  <tr>
    <td>
      <p>
        The robot is programmed in <b>C++</b> using the <b>Arduino framework</b>.  
        The software integrates hardware drivers (OLED, TM1637, DFPlayer, sensors) with behavioral logic:
        <ul>
          <li><b>Emotional responses</b>: Happy, sad, tired, or “in love” depending on sensor input.</li>
          <li><b>Environmental awareness</b>: Reacts to loud sounds, touch, and temperature changes.</li>
          <li><b>Fatigue simulation</b>: After a period of inactivity, Microbot “gets tired” and goes to sleep.</li>
          <li><b>Interactive play mode</b>: Button press triggers music and animated eye movement.</li>
        </ul>
      </p>
    </td>
    <td>
      <img width="200" height="200" alt="c--logo-icon-0" src="https://github.com/user-attachments/assets/8b34492c-1dfc-45a6-bcb0-58f99f30d2d3" />
    </td>
  </tr>
</table>

---

## Schematic

### Assembly Diagram
<p align="center">
  <img width="828" height="862" alt="image" src="https://github.com/user-attachments/assets/1cbad4ad-8bbf-4ce1-bc26-5874cedf4b97" />
</p>

**Caption:** Assembly diagram showing wiring, connectors, power distribution and mounting points.

##

### Circuit Schematic
<p align="center">
  <img width="1253" height="856" alt="image" src="https://github.com/user-attachments/assets/b65f24c7-35f1-4d58-83af-140f41ad53d6" />
</p>

**Caption:** Full schematic of ESP32 connections with sensors, displays, DFPlayer Mini, and RGB LED.

---

## Robot images
<table>
  <tr>
    <td><img width="250" alt="0-02-05-74379f641fc1c1a8be20fcecdaa9cd18b30c0649f9aa3e7a555e493d668d1a62_68433e4146752fc7" src="https://github.com/user-attachments/assets/7a846396-aaa0-4fe8-aa1d-e950bbad993f" /></td>
    <td><img width="250"  alt="0-02-05-a2b6c3e8c4a3ba34041af1623a637a5ef3107b7b7537646edc3e7cd3c57e2e7a_727e73ecee6430bb" src="https://github.com/user-attachments/assets/26e2d8d9-3269-48fa-99b0-63e9266596b9" /></td>
    <td><img width="250"  alt="0-02-05-8a5abab5fc7385c0d9edf23cb2320050e8ef326d4ba8e8c4a83e004cbfcf273a_8945c67b52a56966" src="https://github.com/user-attachments/assets/ec912699-4efe-4d3e-9215-00e5753c1a84" /></td>
  </tr>
  <tr>
    <td> <img width="250"  alt="0-02-05-d777b171e253f313412e277734d9ead74caa63ce39c9c0ae8c1ed149c9af6b0d_179a72e0791d6e38" src="https://github.com/user-attachments/assets/fe612b64-7cd2-4a8c-9359-720d996ed2c7" /></td>
    <td><img width="250"  alt="0-02-05-741cd1436dbc0ad88f6df1bff6465053401684b6103e84e2cb75196a1f26143c_c931415c3920c49e" src="https://github.com/user-attachments/assets/49aba610-d8a4-410e-bf15-864e2f7e01e9" /></td>
  </tr>
</table>

---

## Getting Started with installation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/microbot.git

2. Install Arduino IDE
  - Download from Arduino official site.
  - Add ESP32 board support via Boards Manager (Espressif Systems → ESP32).

3. Install required libraries
  - Adafruit SSD1306
  - Adafruit GFX
  - TM1637Display
  - DFRobotDFPlayerMini
  - DHT sensor library

4. Open the project in Arduino IDE
  - Select ESP32 Dev Module as board.
  - Choose correct COM port.
  - Upload the sketch to your ESP32.

5. Connect hardware
  - Follow the schematic and assembly diagram in the hardware/ folder.

## Story

The NM245 Microbot was not just a technical project — it was born as a gift for someone special.  
I wanted to create more than a robot; I wanted to build a digital representation of myself, a symbolic presence that could stay close even when I am not physically there.  

Every sensor, every LED color, every sound effect was carefully chosen to reflect emotions, reactions, and personality traits.  
The OLED eyes show happiness, sadness, or fatigue — just like me. The DFPlayer Mini plays music to bring joy, while the RGB LED glows in colors that mirror moods.  
Together, these elements form a small digital being, a companion that embodies me in the language of **010101**, the binary code of ones and zeros.  

This Microbot is more than wires and code. It is a message:  
*"Here I am, represented in circuits and algorithms, a digital version of myself created for you."*  

---

## FAQ

**Q: Can the Microbot run on batteries?**  
A: Yes, it can be powered from a Li‑ion battery pack or USB power bank, as long as it provides stable 5V to VIN.  

**Q: Which libraries are required?**  
A: You need Adafruit SSD1306, Adafruit GFX, TM1637Display, DFRobotDFPlayerMini, and the DHT sensor library.  

**Q: Can I customize the emotions?**  
A: Absolutely. The OLED animations and RGB LED colors are fully programmable in the code.  

**Q: Does the Microbot support WiFi or Bluetooth?**  
A: The ESP32 has built‑in WiFi and Bluetooth, but in this project they are not yet used. Future versions may add cloud connectivity.  

**Q: How do I upload the code?**  
A: Open the project in Arduino IDE, select ESP32 Dev Module, choose the correct COM port, and click Upload.  

**Q: Can I add more sensors or modules?**  
A: Yes, the ESP32 has plenty of GPIO pins available. You can extend the schematic with new inputs or outputs.  


## Feedback

If you have any feedback, please reach out to us at mihajlostoiljkovic554@gmail.com

## License

This project is licensed under the MIT License – see the [LICENSE](LICENSE) file for details. <br><br>
[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)
