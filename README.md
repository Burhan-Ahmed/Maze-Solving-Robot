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


## How it works

Each IR sensor outputs `0` on black (line) and `1` on white (surface). The Arduino reads all six sensors in a loop and picks a movement using the left-hand rule:

1. Turn **left** whenever a left turn is possible
2. Otherwise go **straight**
3. Otherwise turn **right**
4. At a dead end, make a **U-turn** (implemented as a left turn)
5. At a full intersection, stop if the upper-center sensor sees the end marker, otherwise turn left

Motor speed is set with PWM (`Speed = 160`) on the L298N enable pins.

## Results

- Sensor values verified live through the Serial Monitor
- Straight paths, left turns, right turns and plus (+) intersections handled correctly
- Robot stops at the end of the maze
- Circuit validated in a Proteus simulation

## Authors

- **Muhammad Burhan Ahmed**
- **Asnan Khan**

## License

This project was developed for academic purposes. Add a license of your choice (for example MIT) if you want others to reuse it.
