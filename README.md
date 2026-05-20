# NM245 Microbot

## Overview
**NM245 Microbot** is an interactive robot developed with the **ESP32 Dev Module**.  
It is programmed using the **Arduino framework** with **C++ language**, combining hardware integration and algorithmic logic to simulate the behavior and personality traits of modern robots.  
The project demonstrates how embedded systems can be designed to react to environmental changes, express emotions, and interact with users in a friendly and engaging way.


<img width="300" height="300" alt="1666364456Esp32_devkitc_v4" src="https://github.com/user-attachments/assets/948a674b-1928-41d9-a067-4903e96b06b5" />


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
| Music Button     | GPIO32    |
| OLED SDA         | GPIO21    |
| OLED SCL         | GPIO22    |

---

## Software
The robot is programmed in **C++** using the **Arduino framework**.            
<img width="200" height="200" alt="c--logo-icon-0" src="https://github.com/user-attachments/assets/8b34492c-1dfc-45a6-bcb0-58f99f30d2d3" />

The software integrates hardware drivers (OLED, TM1637, DFPlayer, sensors) with behavioral logic:

- **Emotional responses**:  
  - Happy, sad, tired, or “in love” depending on sensor input.
- **Environmental awareness**:  
  - Reacts to loud sounds, touch, and temperature changes.
- **Fatigue simulation**:  
  - After a period of inactivity, Microbot “gets tired” and goes to sleep.
- **Interactive play mode**:  
  - Button press triggers music and animated eye movement.

---

## Robot images
<img width="500" height="495" alt="0-02-05-74379f641fc1c1a8be20fcecdaa9cd18b30c0649f9aa3e7a555e493d668d1a62_68433e4146752fc7" src="https://github.com/user-attachments/assets/7a846396-aaa0-4fe8-aa1d-e950bbad993f" />

<img width="500" height="495" alt="0-02-05-a2b6c3e8c4a3ba34041af1623a637a5ef3107b7b7537646edc3e7cd3c57e2e7a_727e73ecee6430bb" src="https://github.com/user-attachments/assets/26e2d8d9-3269-48fa-99b0-63e9266596b9" />

 <img width="300" height="400" alt="0-02-05-8a5abab5fc7385c0d9edf23cb2320050e8ef326d4ba8e8c4a83e004cbfcf273a_8945c67b52a56966" src="https://github.com/user-attachments/assets/ec912699-4efe-4d3e-9215-00e5753c1a84" />

<img width="300" height="400" alt="0-02-05-d777b171e253f313412e277734d9ead74caa63ce39c9c0ae8c1ed149c9af6b0d_179a72e0791d6e38" src="https://github.com/user-attachments/assets/fe612b64-7cd2-4a8c-9359-720d996ed2c7" />

<img width="300" height="400" alt="0-02-05-741cd1436dbc0ad88f6df1bff6465053401684b6103e84e2cb75196a1f26143c_c931415c3920c49e" src="https://github.com/user-attachments/assets/49aba610-d8a4-410e-bf15-864e2f7e01e9" />

---

## Getting Started
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/microbot.git

## Feedback

If you have any feedback, please reach out to us at mihajlostoiljkovic554@gmail.com

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)
