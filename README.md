# **LDR-Based Light Intensity Monitoring System**

This project is part of **Arduino Winter Internship 2025 – Task 1**.
It demonstrates a real-time system that reads an **analog sensor** and controls an **actuator** based on light intensity.

In this setup:

* An **LDR** acts as the analog sensor.
* An **LED** and an **active buzzer** work as actuators.
* A **16×4 I2C LCD** displays sensor readings, thresholds, and actuator states.

---

## **Project Overview**

The Arduino continuously reads the LDR through an analog pin.
Based on the light level:

* If it's darker than the **low threshold**, the LED turns ON.
* If it's brighter than the **high threshold**, the buzzer activates.
* If the reading is between the two thresholds, both remain OFF.

The LCD shows everything in real time:

* Current LDR ADC value
* Low and high threshold levels
* LED state
* Buzzer state

This setup clearly illustrates a complete sensor–actuator loop.

---

## **Hardware Used**

* Arduino Uno
* LDR
* 10kΩ resistor
* LED + 220Ω resistor
* Active buzzer
* 16×4 I2C LCD
* Breadboard and jumper wires

---

## **Circuit Diagram**

### **LDR Voltage Divider**

* LDR → 5V
* Other LDR leg → A0
* A0 → 10k resistor → GND

### **LED**

* Anode → D9
* Cathode → GND (with 220Ω resistor)

### **Buzzer**

* + → D8
* – → GND

### **LCD 16×4 (I2C)**

* SDA → A4
* SCL → A5
* VCC → 5V
* GND → GND

---

## **Arduino Code**

The full code is included in the repository.
It reads the LDR value, compares it with two thresholds, updates the LCD, and controls the LED and buzzer accordingly.

Thresholds used:

* `lightThreshold = 400` (dark)
* `brightThreshold = 800` (very bright)

These values can be adjusted based on your environment.

---

## **Demo Video**

A short demonstration video is available here:

👉 **[Demo Video Link](https://drive.google.com/file/d/1u36vJzkR97-bo2GQL8OaG67ndW62gIG_/view?usp=drivesdk)**

The video shows:

* The working circuit
* Changing light levels on the LDR
* LCD updates
* LED and buzzer responses

---

## **Repository Structure**

```
📁 Task1
│── code/
│     └── ldr_system.ino
│── images/
│     ├── circuit_diagram.png
|     ├── serial_monitor.png
│     └── setup.jpg
└── README.md
```

---
