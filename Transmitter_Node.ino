// Transmitter_Node.ino
// just testing if this whole idea even works before building the real thing
// 1 esp32, 1 mpu6050, 1 servo, all wired straight to the board, no wireless yet

#include <Wire.h>
#include <MPU6050.h>
#include <ESP32Servo.h>

MPU6050 mpu;
Servo testServo;

int16_t ax, ay, az;
int16_t gx, gy, gz;

int servoPin = 18;
float angle = 90; 


float lastAngles[5] = {90, 90, 90, 90, 90};
int avgIndex = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  mpu.initialize();

  if (!mpu.testConnection()) {
    Serial.println("mpu not found????? check wiring");
    while (1) {
      // no point going further if the sonsor isnt even connected
    }
  }

  testServo.attach(servoPin);
  testServo.write(90);
  delay(1000);
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  float accAngle = atan2(ay, az) * 180.0 / PI;

  if (accAngle < -90) accAngle = -90;
  if (accAngle > 90) accAngle = 90;

  float shifted = accAngle + 90; 

  lastAngles[avgIndex] = shifted;
  avgIndex++;
  if (avgIndex >= 5) avgIndex = 0;

  float sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += lastAngles[i];
  }
  angle = sum / 5;

  testServo.write(angle);

  // Made these so i can see whats going on in serial monitor
  Serial.print("ax: ");
  Serial.print(ax);
  Serial.print(" ay: ");
  Serial.print(ay);
  Serial.print(" az: ");
  Serial.print(az);
  Serial.print("  raw angle: ");
  Serial.print(accAngle);
  Serial.print("  smoothed: ");
  Serial.println(angle);

  delay(50);
}

// notes to self / TODO:
// - Servo still jitters some even with the averaging, might need gyro after all
// - Need to figure out esp-now so this doesnt need to stay wired to my laptop
// - this is only testing ONE joint, real thing needs 6 servos through the pca9685
// - Remove all the serial prints once its actually working, this is just for debugging
// - the atan2 thing only really works right when the arm isnt also rotating on
//   the other axis at the same time, this is probably gonna be a problem later
