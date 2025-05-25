# ⚙️ Working Principle – Two-Player Ping Pong Game (Arduino + OLED)

---

## 🧠 System Overview

The game logic runs entirely on the Arduino. The system includes:

- **Display Interface (OLED)** via **I2C**: shows ball, paddles, and score
- **4 Push Buttons**: control paddle movement (UP/DOWN for each player)
- **Buzzer**: provides sound effects for countdowns, paddle hits, and scoring

All components interact with the Arduino in real-time, enabling a fluid and interactive gaming experience.

---

## 🛠️ Component Roles

| Component       | Function                                                                 |
|----------------|--------------------------------------------------------------------------|
| **Arduino Uno** | Central controller for game logic, inputs, and display updates          |
| **SSD1306 OLED (128x64)** | Displays game state: paddles, ball, score, countdown          |
| **Tactile Buttons** | 4 buttons (2 per player): paddle up/down movement                   |
| **Buzzer**      | Plays tones for hits, scoring, and countdowns                           |

---

## 🔄 Game Flow

### 1. **Startup Sequence**
- OLED displays a **3-2-1-GO! countdown**
- Buzzer beeps on each step
- Ball is launched after the countdown

### 2. **Paddle Control**
- Player 1 controls their paddle with **two buttons** (UP/DOWN)
- Player 2 does the same with their two buttons
- Each press updates the paddle’s Y-position within screen limits

### 3. **Ball Movement & Physics**
- Ball moves in 2D with fixed speed vectors (`X` and `Y`)
- Collides with:
  - **Top/Bottom screen edges** → bounces vertically
  - **Player paddles** → bounces horizontally
  - **Missed paddle** → opponent scores a point

### 4. **Scoring & Reset**
- If a player misses the ball:
  - Opponent score increases
  - A short pause + countdown happens
  - Ball is relaunched from the center

### 5. **Sound Feedback**
- Buzzer plays:
  - Countdown beeps
  - Hit sound when ball touches paddle or wall
  - Score tone when a point is earned

---

## 🧩 Real-Time Concepts Used

- **Debounced digital inputs** using `INPUT_PULLUP` mode
- **Frame-based game loop**: constant screen refresh for smooth animation
- **Collision detection**: comparing paddle/ball positions
- **Display updates**: `Adafruit_SSD1306` library for drawing shapes and text
- **I2C communication**: OLED display updates over 2-wire interface

---

## 🎯 Learning Outcomes

Participants learn to:

- Use **I2C** to communicate with OLED displays
- Handle **digital inputs** for real-time control
- Build **interactive graphics** with microcontroller constraints
- Apply **game physics** and simple AI logic
- Integrate **audio feedback** with a buzzer

---

## ⚠️ Circuit Diagram 

![image](https://github.com/user-attachments/assets/7ee73718-8337-4a2a-b3b8-ad73eea513ed)

---

## 🕹️ Working Video 

https://github.com/user-attachments/assets/b61c2065-10f5-45c3-87d0-781627b9c525



