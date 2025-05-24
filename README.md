# erc-convener-training-week2

## 🧠 Topics Covered

### 1. How Does a Microcontroller Work? (Code to Hardware Implementation)
- Understand the process from writing code in Arduino IDE to actual hardware execution.
- Compilation → Hex file → Flash memory → Instruction execution on chip.

---

### 2. Peripheral Interaction with Microcontrollers (GPIO, ADC, DAC)
- How peripherals like LEDs, sensors, and actuators connect via GPIOs.
- Conversion of real-world analog signals to digital values using ADC.
- Outputting analog-like signals using DAC/PWM for things like motor control or audio signals.

---

### 3. Communication Protocols: SPI, I2C, UART, USB
- Learn and implement:
  - **SPI (Serial Peripheral Interface)**
  - **I2C (Inter-Integrated Circuit)**
  - **UART (Universal Asynchronous Receiver-Transmitter)**
  - **USB (Universal Serial Bus)**
- Use Arduino Uno and MPU6050 with `Serial Monitor` and `Wire.h` for real hardware communication examples.

---

### 4. SPI Modes, I2C Addresses, and Bus Architecture
- Understand SPI Modes (0-3) and how Clock Polarity/Phase affects data transfer.
- Master/slave addressing in I2C and how devices communicate on a shared bus.
- Visualize a complete microcontroller ecosystem:  
  **Sensor → Microcontroller → Actuator**

---

### 5. Storing Data on Microcontrollers
- Store persistent or runtime data using:
  - **EEPROM** (internal non-volatile memory)
  - **SD Card Modules** (external storage for larger data logging)

---

### 6. Processing Capabilities: Cores & Threads
- What is a **core**? What is a **thread**?
- How multi-core and multi-threading work.
- Pros and cons: Which one is better for different use cases?

---

### 7. RTOS: Real-Time Operating System (Basic Research)
- What is an RTOS and how is it different from normal OS?
---

