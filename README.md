<img width="1171" height="740" alt="image" src="https://github.com/user-attachments/assets/3198485d-42a6-4c53-b6ea-411cb913dd8c" />

# Robot Mimic Arm 🦾

The official repo for the ESP32-Based 5 Axis Robotic Arm(for Hack Club's Macondo)


A tracking Sleeve that lets you control a robotic claw, with the movements of your arm. 
This project repo consists of:


*   📁 **`STL Files/`** — The 3D model parts for each segment of the robotic arm(material type varies).

*   📁 **`Firmware/`** — The complete code for the finished product:
 *   `Transmitter_Node.ino` — Code for the wearable sleeve segments tracking sensor data over ESP-NOW.
 *   `Transmitter_Node.ino_build`— The Diagram for the segmnts of the sleeeve.(Not currenty available here, see: https://wokwi.com/projects/471405418466111489)
 *   `Receiver_Node.ino` — Code for the robot base responsible for handling the wireless packets from the wearable and driving the PCA9685 PWM servos.
 *   `Receiver_Node.ino_build`— The Wiring diagram for the central base responsible for controlling all of the servos.(Not curently available here, see: https://wokwi.com/projects/471498644573130753)

*   📁 **`Bonus Prototypes & Extras/`** — Early development prints, validation scripts, and some noticeable moments from start to finish:
    *   `Wired_SingleNode_Core.ino` — The initial framework to check for responsive orientation mapping using justa single ESP32, MPU6050, and servo.
    *   `ESP32_MAC_Scanner.ino` — Diagnostic script used to extract the MAC address of each ESP32-S3 node for the ESP-NOW targeting👀.
    *   `Servo_Mechanical_Calibrator.ino` — Alignment test utility that sweeps joint actuators to fixed center positions to calibrate 3D-printed hinges before the full assembly🦾.
