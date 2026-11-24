# Autonomous Maze-Solving Robot (Arduino, Left-Hand Rule)

An autonomous line-following maze-solving robot built on an Arduino UNO (ATmega328P). Using a 6-channel IR sensor array and the **left-hand rule (LSRS)**, it detects turns, intersections, dead ends and the finish marker on a black-line-on-white maze, and navigates from start to end with no human input.

> Complex Engineering Problem, Microprocessor & Microcontroller, Department of Electrical & Computer Engineering, Air University (February 2024)

---

## Features

- Autonomous maze solving with the **left-hand rule** (Left > Straight > Right > U-turn)
- 6-channel IR sensor array for line, junction and dead-end detection
- Dedicated sensor for **end-of-maze detection**, after which the robot stops
- Speed control with **PWM** on an L298N dual H-bridge motor driver
- Serial Monitor debugging of all sensor values (9600 baud)
- Verified in **Proteus** simulation and on real hardware

## Hardware

| Component | Details |
|---|---|
| Microcontroller | Arduino UNO (ATmega328P) |
| Motor driver | L298N dual H-bridge module |
| Motors | 2x geared DC motors with wheels, plus a castor wheel |
| Sensors | IR sensor array (6 digital channels) |
| Power | 2x 18650 Li-ion cells (3.7 V, 2200 mAh) with switch |
| Chassis | Two-layer car chassis |

## Pin configuration

**IR sensors**

| Sensor | Arduino pin |
|---|---|
| Right most | 2 |
| Right | 3 |
| Center | 12 |
| Upper center (end marker) | 13 |
| Left | 4 |
| Left most | 5 |

**L298N motor driver**

| Signal | Arduino pin |
|---|---|
| ENA | 6 |
| IN1 | 7 |
| IN2 | 8 |
| IN3 | 9 |
| IN4 | 10 |
| ENB | 11 |

## How it works

Each IR sensor outputs `0` on black (line) and `1` on white (surface). The Arduino reads all six sensors in a loop and picks a movement using the left-hand rule:

1. Turn **left** whenever a left turn is possible
2. Otherwise go **straight**
3. Otherwise turn **right**
4. At a dead end, make a **U-turn** (implemented as a left turn)
5. At a full intersection, stop if the upper-center sensor sees the end marker, otherwise turn left

Motor speed is set with PWM (`Speed = 160`) on the L298N enable pins.

## Getting started

1. Wire the circuit using the pin tables above.
2. Open the sketch in the **Arduino IDE** and select *Arduino Uno*.
3. Upload it. The sketch compiles to 3110 bytes (9% of program storage) and 268 bytes (13%) of dynamic memory.
4. Open the Serial Monitor at **9600 baud** to check the sensor readings.
5. Put the robot at the start of a black-tape maze on a light surface, switch on the battery, and it starts solving.

## Results

- Sensor values verified live through the Serial Monitor
- Straight paths, left turns, right turns and plus (+) intersections handled correctly
- Robot stops at the end of the maze
- Circuit validated in a Proteus simulation

*(Add photos or GIFs of the robot to an `images/` folder and link them here.)*

## Challenges and lessons learned

- At high speed the robot overshoots sharp corners, and adding `delay()` did not fix it, so a medium speed gave the best results.
- PWM that is too low can leave only one wheel turning, so a tuned speed is needed.
- Six sensors give 2^6 possible readings, and every one must be handled, otherwise the robot can get stuck in undefined cases.

## Future improvements

- PID control for smoother, faster line tracking
- Shortest-path optimization on a second run (storing the maze path)
- Wheel encoders for better turn accuracy

## Tech stack

`C/C++` | `Arduino IDE` | `ATmega328P` | `L298N` | `IR sensors` | `PWM` | `Proteus`

## Authors

- **Muhammad Burhan Ahmed**
- **Asnan Khan**

**Instructor:** Dr. Mumajjed UL Mudassir, Air University, Islamabad

## License

This project was developed for academic purposes. Add a license of your choice (for example MIT) if you want others to reuse it.
