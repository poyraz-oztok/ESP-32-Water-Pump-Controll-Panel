
# Epsilon : ESP-32-Water-Pump-Controll-Panel

![Project Status](https://img.shields.io/badge/status-prototype-purple) ![IoT](https://img.shields.io/badge/IoT-enabled-blueviolet) ![Microcontroller](https://img.shields.io/badge/MCU-ESP32-orange) ![C++](https://img.shields.io/badge/language-C++-blue) ![IDE](https://img.shields.io/badge/IDE-Arduino-turquoise)

---
This is a prototype IoT-based water pump controller developed during my internship. The system is designed to manage clean and dirty water pumps using an ESP32 microcontroller. It features a local LCD interface, keypad control, a web-based IoT dashboard, and supports automation through programmable rules. The controller manages up to three relays to control different pump configurations.

---


## Features

- 💧 Controls **clean and dirty water pumps**
- 📟 **LCD screen** for real-time system feedback
- ⌨️ **Keypad** for local control and menu navigation
- 🌐 **IoT capabilities** for remote monitoring and control via a web interface
- 🧠 **Shared GPIO for LCD and Keypad** By implementing a multiplexed I/O scheme, the LCD and keypad will share GPIO pins, significantly reducing the total pin count
- ⚙️ **ESP32 microcontroller** as the core controller
- 🔌 Supports up to **3 relays** to switch pumps or valves
- 🔧 Custom **PCB** designed for compact and reliable installation

---

### Parts Used

- **ESP32-WROOM-32UE** (WiFi-enabled microcontroller)
- **LM6063ACW** COG LCD Screen
- **11 Buttons Keypad**
- **3x ALDP112 Relay** controlled via 5V
- **Custom PCB**

---

## 🧩 Custom PCB Design
<p align="center">
  <figure style="display:inline-block; text-align:center; margin:10px;">
    <img src="https://github.com/user-attachments/assets/7db76729-60f1-4e9e-9192-f4f842646040" width="250" />
  </figure>
  
  <figure style="display:inline-block; text-align:center; margin:10px;">
    <img src="https://github.com/user-attachments/assets/347bdfd7-53c8-475b-95c6-09c6ad928ee3" width="250" />
  </figure>

  <figure style="display:inline-block; text-align:center; margin:10px;">
    <img src="https://github.com/user-attachments/assets/9466580f-0799-4eb7-88fe-6df96e14b687" width="250" />
  </figure>
</p>

