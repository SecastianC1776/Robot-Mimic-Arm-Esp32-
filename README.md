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

## Bill of Materials

| Item | Category | Qty Needed | Package Size | Packages to Buy | Price per Package | Total Price | Purchase Link | Notes |
| :--- | :--- | :---: | :---: | :---: | :---: | :---: | :---: | :--- |
| **ESP32-S3 Dev Board (N16R8, External Antenna)** | Sensor/Control | 4 | 5-pack | 1 | $29.99 | $29.99 | [🛒 Buy Now](https://www.amazon.com/gp/product/B0H2918LZD/ref=ox_sc_act_title_19?smid=A2Z10KY0342329&psc=1) | 3 for wearable sleeve islands (hand/forearm/bicep) + 1 for command center, and 1 for ruview extencion. |
| **MPU6050 6-Axis IMU** | Sensor | 5 | 5-pack | 1 | $13.99 | $13.99 | [🛒 Buy Now](https://www.amazon.com/dp/B07M98PKT4) | 3 required (1 per sleeve island). 2 required for pose comparison on the robot arm. |
| **DS3218 PRO Servo (20kg, 180 Control Angle)** | Actuator | 6 | 1 unit | 6 | $16.99 | $101.94 | [🛒 Buy Now](https://www.amazon.com/dp/B07KRMJTH5) | 2x shoulder (ball/socket) + 1x elbow + 2x wrist + 1x claw. Confirmed 180 degree + genuine PRO gear spec. |
| **PCA9685 16-Channel PWM Servo Driver** | Control | 1 | 2-pack | 1 | $8.99 | $8.99 | [🛒 Buy Now](https://www.amazon.com/gp/product/B01D1D0CX2) | Servo driver under heavy electrical stress of the wall power. |
| **Electrolytic Capacitor Assortment Kit** | Power | 1 | 1 kit | 1 | $9.99 | $9.99 | [🛒 Buy Now](https://www.amazon.com/dp/B0C1VBXCQM) | Smooths current dips on servo power rail near PCA9685 V+/GND. |
| **6V 10A (60W) DC Switching Power Supply** | Power | 1 | 1 unit | 1 | $16.99 | $16.99 | [🛒 Buy Now](https://www.amazon.com/dp/B01GHN2S7Q) | MUST select the 60W/10A variant at checkout. Powers servo rail directly; also feeds buck converter for logic 5V. |
| **2S 7.4V LiPo Battery Pack (800mAh)** | Power | 3 | 2-pack | 2 | $23.99 | $47.98 | [🛒 Buy Now](https://www.amazon.com/dp/B0BWRV94SC) | 3 required (1 per sleeve island) + 1 recharge for mem on Command Center. Lightweight pick for wearable comfort. |
| **PETG Filament 1.75mm - Sky Blue** | Print Material | 1 | 1kg spool | 1 | $13.99 | $13.99 | [🛒 Buy Now](https://www.amazon.com/dp/B0FDVJ1M2W) | iSANMATE Sky Blue HF PETG. Print settings: 220-250C nozzle / 70-80C bed. |
| **PETG Filament 1.75mm - Orange** | Print Material | 1 | 1kg spool | 1 | $13.99 | $13.99 | [🛒 Buy Now](https://www.amazon.com/gp/product/B0FDW84RK1/ref=ox_sc_act_title_11?smid=A2ASAAKDZRYBYM&th=1) | Second color for two-tone build (blue arm segments / orange accents). |
| **M3/M4/M5 Stainless Screw+Nut+Washer Kit (Countersunk)** | Fastener | 1 | 330pcs | 1 | $8.58 | $8.58 | [🛒 Buy Now](https://www.amazon.com/gp/product/B0C2CHP3X7/ref=ox_sc_act_title_1?smid=A2KCSSELB8NLZN&psc=1) | 304 stainless. Countersunk heads sit flush - important for moving 3D printed joints. |
| **2.4GHz WiFi Antenna 3dBi (U.FL to SMA)** | Wireless | 4 | 4-pack | 1 | $11.99 | $11.99 | [🛒 Buy Now](https://www.amazon.com/gp/product/B0CD7LBJ3D/ref=ox_sc_act_title_2?smid=A1GUQD3SRXOFFI&psc=1) | 3dBi is the sweet spot: - lower gain / more omnidirectional performs better on a rotating wearable than high-gain directional antennas. Confirmed straight SMA (not RP-SMA). |
| **Mini MP1584EN DC-DC Buck Converter** | Power | 4 | 5-pack | 1 | $8.69 | $8.69 | [🛒 Buy Now](https://www.amazon.com/dp/B00LTQU4EQ) | 3 for sleeve islands (7.4-8.4V to 5V) + 1 for command center (6V servo rail to 5V logic). |
| **SSD1306 0.96in I2C OLED Display** | Display | 2 | 2-pack | 1 | $9.99 | $9.99 | [🛒 Buy Now](https://www.amazon.com/dp/B0DXVVJZ3S) | Blue variant. 1 mounted on wearable, 1 on robot base for live diagnostics. |
| **Resistor Assortment Kit (1/4W)** | Sensor Support | 1 | 760pcs | 1 | $6.99 | $6.99 | [🛒 Buy Now](https://www.amazon.com/dp/B0BFRNTVZF) | Used to build the analog voltage divider circuit for the flex sensor. |
| **Flex Sensor 2.2in** | Sensor | 1 | 1 unit | 1 | $10.59 | $10.59 | [🛒 Buy Now](https://www.amazon.com/dp/B0H1CLTHNV) | Mounted on index finger of wearable sleeve; drives claw open/close. |
| **IP2326 2S LiPo USB-C Charger Module** | Power | 3 | 2-pack | 2 | $14.99 | $29.98 | [🛒 Buy Now](https://www.amazon.com/dp/B0FYXCV7W3) | 4 required (1 per battery). Confirmed genuine 2S balancing (chip only balances in 2S mode, not 3S). |
| **Solderless Breadboard + Jumper Wire Kit** | Prototyping | 1 | 1 kit | 1 | $6.29 | $6.29 | [🛒 Buy Now](https://www.amazon.com/dp/B0GVD11LSS) | Breadboards required for protopyting; kit's included 120 jumper wires cover the dupont wire set needed too. |
| **18 AWG Inline Fuse Holder** | Safety | 1 | 5-pack | 1 | $7.49 | $7.49 | [🛒 Buy Now](https://www.amazon.com/dp/B0DT4NCD5V) | Wired in series on servo rail positive line between power supply and PCA9685 V+. wil; be using 10A fuse to match supply rating. |
| **Knit Elastic Band Spool (4in wide, Black)** | Wearable | 1 | 3 yards | 1 | $9.99 | $9.99 | [🛒 Buy Now](https://www.amazon.com/dp/B071G3K17C) | Sleeve construction material for the wearable arm segments(Best for mobility). |
