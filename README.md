# Smart Room Environmental Monitoring and Alert System

Project Overview

The **Smart Room Environmental Monitoring and Alert System** is an Arduino-based embedded solution designed to automate room climate and lighting conditions. By integrating temperature and light sensors, the system provides real-time visual and audible feedback to ensure user comfort and safety.

---

Circuit Diagram

> View the full interactive circuit on TinkerCAD:
> **[▶ Open TinkerCAD Circuit Diagram](https://www.tinkercad.com/things/7KfILeUbDau-milly-project-12/editel?sharecode=6ONXWdXN2-Zshqihs7_I0OphS1aaYs8EPY3IrLaCKxk)**

---

Features

- **Automated Climate Alert:** Monitors temperature and triggers a visual (Red LED) and audible (Piezo Buzzer) alarm if levels exceed a set threshold.
- **Smart Lighting:** Automatically activates room lighting (Yellow LED) when ambient light levels drop below a specific intensity.
- **Real-time Display:** Uses a 16×2 LCD screen to display live temperature (in Celsius) and light intensity values.
- **Serial Monitoring:** Outputs system status to the Serial Monitor for debugging and data logging.

---

## 🔧 Hardware Components

| Category | Component |
|---|---|
| **Microcontroller** | Arduino Uno R3 |
| **Sensors** | TMP36 Temperature Sensor, Photoresistor (LDR) |
| **Display** | 16×2 LCD Display (Liquid Crystal) |
| **Actuators** | Piezo Buzzer, Red LED (Alert), Yellow LED (Lighting) |
| **Passive Components** | 10kΩ Potentiometer (contrast), 220Ω & 10kΩ Resistors |
| **Other** | Breadboard & Jumper Wires |

---

## 📌 Pin Mapping

| Component | Arduino Pin | Type |
|---|---|---|
| TMP36 Sensor | A0 | Analog Input |
| Photoresistor | A1 | Analog Input |
| Piezo Buzzer | 8 | Digital Output |
| Alert LED (Red) | 13 | Digital Output |
| Room LED (Yellow) | 12 | Digital Output |
| LCD RS | 7 | Digital |
| LCD Enable | 6 | Digital |
| LCD D4–D7 | 5, 4, 3, 2 | Digital |

---

## 🧠 System Logic

The system operates in a continuous loop (`void loop`), processing sensor data as follows:

### 1. Temperature Control

The analog signal from the TMP36 is converted into a voltage and then into Celsius using the formula:

```
Temperature (°C) = (Voltage - 0.5) × 100
```

- **Threshold:** If **Temp > 30°C** → Red LED turns **HIGH** and Piezo Buzzer sounds a **1000 Hz tone**.
- **Normal:** If **Temp ≤ 30°C** → Red LED turns **LOW** and Buzzer is silenced.

### 2. Lighting Control

The Photoresistor measures ambient light, providing an analog value (0–1023).

- **Threshold:** If **Light < 800** → Room LED turns **ON**.
- **Normal:** If **Light ≥ 800** → Room LED turns **OFF**.

### 3. Display Logic

The **16×2 LCD** serves as the primary User Interface (UI):

- **Row 1:** Displays the current temperature in Celsius.
- **Row 2:** Displays a `Safe` or `ALARM!` status message alongside the current light level.

---

## ⚙️ Installation & Setup

### 1. Prerequisites

Before starting, ensure you have the following:

- **Software:** [Arduino IDE](https://www.arduino.cc/en/software) (Version 2.0 or higher recommended)
- **Library:** The `LiquidCrystal` library is required. To install it:
  1. Open the Arduino IDE.
  2. Go to **Sketch → Include Library → Manage Libraries...**
  3. Search for `LiquidCrystal` and click **Install**.

### 2. Hardware Assembly (Step-by-Step)

1. **Hardware Wiring:** Connect all components according to the [Pin Mapping](#-pin-mapping) table above.

2. **Sensor Integration:**
   - Connect the TMP36 and Photoresistor to the power rails and analog pins (A0 and A1).
   - Ensure a **10kΩ pull-down resistor** is placed in series with the Photoresistor to create a readable voltage divider.

3. **Display & Actuators:**
   - Wire the LCD pins (RS, E, D4–D7) to Digital Pins 7 through 2.
   - Connect the **Potentiometer** to LCD Pin 3 (V0) for contrast adjustment.
   - Connect the **Piezo Buzzer** to Pin 8 and the **LEDs** to Pins 12 and 13, each with a **220Ω resistor** for protection.

---

## ✅ System Verification

Once the system is assembled/simulated, perform the following checks:

- **LCD Contrast:** Rotate the Potentiometer knob until text is clearly visible on the LCD.
- **Temperature Threshold Test:** Increase the temperature on the TMP36 slider — the Red LED and Buzzer should activate once it crosses **30°C**.
- **Light Threshold Test:** Adjust the Photoresistor slider until the **Yellow LED** turns on.
