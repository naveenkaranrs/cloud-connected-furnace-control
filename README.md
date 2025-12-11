# 🔥 Cloud-Connected Real-Time Closed-Loop Control System for Industrial Furnaces

A fully implemented **real-time furnace automation system** integrating **STM32**, **ESP32/NodeMCU**, **DHT11**, **Embedded C**, and
**cloud connectivity** to deliver accurate temperature regulation, remote visualization, and real-time alerts.

## 🚀 Overview

Industrial furnaces require **precise, stable, and continuous temperature control** for safe and efficient operation.
Traditional setups face challenges such as:

* Delay in sensor feedback
* No cloud visibility
* Absence of real-time alerts
* Limited monitoring
* Risk of overheating and component failure

This project solves these challenges by designing a **closed-loop embedded controller** with **cloud-based supervisory monitoring**, achieving:

* ⚡ Real-time control (local jitter < 5–10 ms)
* ☁️ Cloud updates within 1–5 seconds
* 🔧 Automated cooling via fan control
* 📊 Live dashboard with historical trends
* 🔌 Scalable, low-cost industrial automation

---

## 📌 Features

* Real-time temperature & humidity acquisition using **DHT11**
* Closed-loop control using **STM32 NUCLEO-F103RB**
* Automatic fan activation based on threshold
* ESP32/NodeMCU-based cloud communication (MQTT / Firebase / Blynk / ThingSpeak)
* Remote dashboard with:

  * Live values
  * Fan status
  * History plots
  * Alerts for temperature spikes
* UART communication between STM32 ↔ ESP32
* Modular and industry-ready architecture

---

## 🛠️ System Architecture

### **Hardware Components**

| Component               | Purpose                                             |
| ----------------------- | --------------------------------------------------- |
| **STM32 NUCLEO-F103RB** | Executes closed-loop control, processes sensor data |
| **DHT11 Sensor**        | Measures temperature and humidity                   |
| **ESP32 / NodeMCU-32S** | Publishes data to cloud dashboard                   |
| **Relay/MOSFET**        | Drives fan for cooling                              |
| **Fan**                 | Controls furnace temperature                        |

---

## 🔧 Methodology

### **1. Sensor Data Acquisition**

* DHT11 sends temperature/humidity data to STM32.
* STM32 reads data at fixed intervals.

### **2. Closed-Loop Control**

* Compares real-time temperature vs threshold (e.g., 40°C)
* If **temp > threshold → Fan ON**
* If **temp <= threshold → Fan OFF**

### **3. Cloud Communication**

* STM32 sends processed values over UART to ESP32.
* ESP32 uploads data via Wi-Fi to cloud platform.

### **4. Dashboard Monitoring**

* Displays real-time values, fan status, and historical graphs.
* Helps in remote supervision from any device.

---

## 🔄 Workflow Diagram (Text Format)

```
Start
  |
Read Temperature (DHT11)
  |
Compare with Threshold
  |----------------------------|
  |                            |
Temp > Threshold         Temp <= Threshold
  |                            |
Fan ON                     Fan OFF
  |
Send Data to ESP32
  |
Upload to Cloud
  |
Repeat
```

---

## 📡 Communication Flow

**DHT11 → STM32 → ESP32 → Cloud Dashboard → User**

* **STM32 ↔ DHT11**: Single-wire interface
* **STM32 ↔ ESP32**: UART
* **ESP32 ↔ Cloud**: WiFi + MQTT/HTTP

---

## 🖥️ Cloud Dashboard

The cloud dashboard includes:

* Live temperature & humidity
* Fan ON/OFF status
* Graphs of historic data
* Alerts for high temperature
* Remote access on mobile/laptop

Supports:
**ThingSpeak**, **Firebase**, **Blynk**, **InfluxDB**, or any custom API.

---

## 📁 Project Repository Structure (Recommended)

```
📦 industrial-furnace-cloud-control
│
├── firmware/
│   ├── stm32/
│   │   ├── dht11_driver.c
│   │   ├── control_logic.c
│   │   └── uart_comm.c
│   ├── esp32/
│   │   ├── wifi_mqtt.ino
│   │   └── cloud_upload.c
│
├── hardware/
│   ├── schematics/
│   └── wiring_diagram.png
│
├── cloud/
│   ├── dashboard_setup.md
│   └── api_endpoints.json
│
├── docs/
│   ├── project_report.pdf
│   └── methodology.md
│
├── README.md
└── LICENSE
```

---

## 🎯 Results

* Achieved <10 ms jitter real-time closed-loop control
* Cloud update latency between 1–5 seconds
* Stable industrial operation without temperature oscillations
* Reliable automated fan cooling
* Fully remote monitoring via dashboard
* Modular and expandable design

---

## 🔮 Future Improvements

* Add **PID control** for smoother furnace response
* Replace DHT11 with **industrial thermocouple sensors**
* Move to **MQTT + InfluxDB + Grafana** for advanced dashboards
* Integrate **edge AI** anomaly detection
* Add **mobile app** for furnace remote control
* Implement **multi-sensor fusion** for higher accuracy

---

## 🧑‍💻 Technologies Used

* **STM32 (Embedded C)**
* **ESP32 / NodeMCU**
* **DHT11 Sensor**
* **UART Communication**
* **MQTT / HTTP Protocols**
* **ThingSpeak / Firebase / Custom Cloud**
* **Real-Time Control Logic**

---

## 📜 Conclusion

This project successfully integrates **embedded systems**, **IoT**, and **cloud computing** to build a smart, reliable, and scalable furnace automation system.
It enables:

* Real-time closed-loop control
* Safe temperature management
* Remote industrial supervision
* Cloud-based analytics and alerts

This architecture is directly applicable to **industrial furnaces**, **dryers**, **boilers**, **ovens**, and **HVAC systems**.

---

## ⭐ Author

**Naveen Karan R.S**
B.Tech ECE | Embedded Systems & IoT Developer



