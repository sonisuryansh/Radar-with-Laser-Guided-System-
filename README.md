<div align="center">

# 🎯 Radar with Laser-Guided System
### *Autonomous Sensing • Real-Time Visualization • Precision Response*

<p>
  <img src="https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white" />
  <img src="https://img.shields.io/badge/Processing-006699?style=for-the-badge&logo=processing&logoColor=white" />
  <img src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
  <img src="https://img.shields.io/badge/Hardware-Robotics-orange?style=for-the-badge" />
</p>

---

**[ 🛰️ System Logic ](#-intelligent-response-matrix) • [ 🛠️ Hardware ](#-hardware-stack) • [ 📊 Visualization ](#-radar-visualization-interface) • [ 📬 Contact ](#-author)**

</div>

---

## 🏛️ Project Architecture
This system is an integrated embedded solution that combines **ultrasonic telemetry** with a **tri-stage alert system** and a **timed laser-guided countermeasure**.



| Phase | Detection Range | Visual/Audio Feedback | System Action |
| :--- | :--- | :--- | :--- |
| **Normal** | > 200 cm | 🔵 Blue LED | Monitoring Mode |
| **Warning** | 50 cm - 100 cm | 🟡 Yellow LED | Increased Sampling |
| **Critical** | < 50 cm | 🔴 Red Flash + Buzzer | Emergency Alert |
| **Lock-On** | < 50 cm (3s+) | 🔦 Laser Activated | 5s Precise Target Marking |

---

## 🚀 Key Features

### 📏 Intelligent Distance Logic
The system uses high-frequency ultrasonic waves to calculate "Time of Flight" (ToF), converting it into precise distance data. The logic is designed to filter noise and provide stable readings across three thresholds.

### 🔦 Precision Laser Guidance
Unlike basic sensors, this project features a **Time-Accumulation Trigger**. If a target stays in the "Critical Zone" for over 3 seconds, the laser module engages for 5 seconds—demonstrating a sophisticated automated response protocol.

### 📡 Telemetry & Communication
* **Serial Streaming:** Real-time data output to the Arduino IDE console.
* **Bluetooth Integration:** Ready for wireless remote monitoring and smartphone alerts.
* **Logic Handshake:** Seamless communication between the Arduino (Hardware) and Processing (UI).

---

## 📊 Radar Visualization Interface
The hardware is paired with a **Processing-based UI** that renders a professional radar sweep.



* **Dynamic Scanning:** Visualizes the sweep angle and object distance.
* **Color-Coded Blips:** Real-time object tracking on a graphical grid.
* **Telemetry Overlay:** Displays raw distance and status messages on-screen.

---

## 🛠️ Hardware Stack
<details>
<summary><b>Click to expand Component List</b></summary>

* **Microcontroller:** Arduino Uno (Atmega328P)
* **Sensing:** HC-SR04 Ultrasonic Sensor
* **Indicators:** High-brightness LEDs (R, Y, B) & Active Piezo Buzzer
* **Actuator:** 5V Laser Diode Module
* **Connectivity:** HC-05/06 Bluetooth Module (Optional)
* **Power:** 9V DC / USB Bus Power

</details>

---

## 🧠 Learning Outcomes
* **Embedded Logic:** Designing non-blocking time delays using `millis()` for the laser trigger.
* **Signal Processing:** Managing sensor bounce and calculating accurate distance formulas.
* **GUI Development:** Mapping serial data strings to coordinate systems in Processing.
* **Hardware Integration:** Managing power distribution across multiple LEDs and high-draw modules like lasers.

---

## 🌟 Real-World Applications
* **Intrusion Detection:** Security perimeters with automated deterrents.
* **Industrial Safety:** Visual and audio warning zones for moving machinery.
* **Robotics:** Obstacle avoidance and targeting systems for autonomous rovers.

---

## 👤 Author

<div align="center">

**Suryansh Soni**
*Embedded Systems Developer & Robotics Enthusiast*

[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=flat&logo=linkedin&logoColor=white)](#) 
[![GitHub](https://img.shields.io/badge/GitHub-181717?style=flat&logo=github&logoColor=white)](https://github.com/Suryansh-Soni)

*"Bridging the gap between the physical world and digital logic."*

</div>

---
<div align="center">
<sub>© 2026 Radar Project Lab. Open Source for Educational Use.</sub>
</div>
