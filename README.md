 Robot Mimic Arm

The official repo for the ESP32-Based 5 Axis Robotic Arm


A tracking Sleeve that lets you control a robotic claw, with the movements of your arm. 
This project repo consists of:


*   📁 **`STL-Files/`** — The scale-accurate, high-strength 3D model parts for each segment of the robot arm chassis and wearable arm sleeve.

*   📁 **`Firmware/`** — The complete code for the finished product:
 *   `Transmitter_Node.ino` — Code for the wearable sleeve's segments tracking IMU and flex sensor data over ESP-NOW.
    *   `Receiver_Node.ino` — Code for the central robot base responsible for handling the wireless packets from the wearable and driving the PCA9685 PWM servos.

*   📁 **`Bonus Prototypes & Extras/`** — Early development prints, sandboxed drivers, validation scripts, and some noticeable moments from start to finish:
    *   `Wired_SingleNode_Core.ino` — The initial framework executing 1:1 responsive orientation mapping using ajust  single ESP32, MPU6050, and servo.
    *   `ESP32_MAC_Scanner.ino` — Diagnostic script used to extract the hardcoded MAC address of each ESP32-S3 node for ESP-NOW targeting.
    *   `Servo_Mechanical_Calibrator.ino` — Alignment test utility that sweeps joint actuators to fixed center positions to calibrate 3D-printed hinges before full assembly.
