# 🔥 Smoke Detector using Arduino

This project uses an **MQ-2 Smoke Sensor** to detect smoke in the surroundings.  
When the smoke level crosses a threshold:
- A 🔔 **buzzer rings**  
- A 📲 **message is sent via HC-05 Bluetooth** to your phone

---

## 📦 Components Used

| Component             | Quantity |
|-----------------------|----------|
| Arduino UNO           | 1        |
| MQ-2 Smoke Sensor     | 1        |
| HC-05 Bluetooth Module| 1        |
| Buzzer                | 1        |
| Jumper Wires          | As required |
| 9V Battery or USB Power | 1      |

---

## ⚡ Circuit Connections

### 🔌 MQ-2 Smoke Sensor:
- **VCC → 5V**  
- **GND → GND**  
- **AO → A0**

### 🔌 HC-05 Bluetooth:
- **TX → RX (D0)**  
- **RX → TX (D1)** *(Use Voltage Divider)*  
- **VCC → 5V**, **GND → GND**

### 🔔 Buzzer:
- **+ → D9**  
- **- → GND**

---

## 🖼️ Circuit Diagram

![Smoke Detector Circuit](smoke_detector_diagram.png)

---

## 🧠 Arduino Code

<details>
<summary>Click to view Arduino Code</summary>

```cpp
int smokeSensor = A0;
int buzzer = 9;
int threshold = 400;

void setup() {
  pinMode(smokeSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int smokeLevel = analogRead(smokeSensor);
  Serial.print("Smoke Level: ");
  Serial.println(smokeLevel);

  if (smokeLevel > threshold) {
    digitalWrite(buzzer, HIGH);
    Serial.println("ALERT: Smoke Detected!");
  } else {
    digitalWrite(buzzer, LOW);
  }

  delay(1000);
}
