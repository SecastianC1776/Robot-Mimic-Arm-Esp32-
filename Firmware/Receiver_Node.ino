// base station code - gets the imu data from the sleeve over espnow and moves the servos, other 2 channels just sit at center until i get funding to buy them(ESP32-S3)

#include <esp_now.h>
#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(); 

// ince i requested the 180 servos, so center is always 90
#define SERVOMIN  102   // this is roughly 500us at 50hz, got this off a forum post
#define SERVOMAX  512   // roughly 2500us, same deal
#define SERVO_FREQ 50
#define CH_SHOULDER 0
#define CH_ELBOW    1
#define CH_WRIST    2
#define CH_CLAW     3
// channels 4 and 5 not wired to anything(YET!!)

// this HAS to match my struct on the sender side or it just reads garbage, learned that the hard way after like an hour of debugging lol
typedef struct {
  int id;
  float roll;
  float pitch;
  float yaw;
  int flexVal;
} incoming;

incoming lastData;
bool gotFirstPacket = false;

void setup() {
  Serial.begin(115200);
  Wire.begin(8, 9); // s3 board im using has sda/scl on 8 and 9, not the usual 21/22(im getting the 44 pin n16r8)

  pwm.begin();
  pwm.setPWMFreq(SERVO_FREQ);

  // send everything to center before it starts so it doesnt jerk around on boot
  pwm.setPWM(CH_SHOULDER, 0, angleToPulse(90));
  pwm.setPWM(CH_ELBOW, 0, angleToPulse(90));
  pwm.setPWM(CH_WRIST, 0, angleToPulse(90));
  pwm.setPWM(CH_CLAW, 0, angleToPulse(90));

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("espnow init failed, not sure why");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);
  Serial.println("waiting for packets...");
}

void loop() {
  if (gotFirstPacket) {
    // just mapping the pitch value straight to the shoulder servo for now, ned $
    // this is definitely not gonna be the final mapping but wanted to copy it so it looks full of codeee
    int shoulderAngle = map(lastData.pitch, -90, 90, 0, 180);
    shoulderAngle = constrain(shoulderAngle, 0, 180); 
    pwm.setPWM(CH_SHOULDER, 0, angleToPulse(shoulderAngle));
    int clawAngle = map(lastData.flexVal, 0, 4095, 30, 120);
    pwm.setPWM(CH_CLAW, 0, angleToPulse(clawAngle));

    Serial.print("pitch: ");
    Serial.print(lastData.pitch);
    Serial.print(" -> shoulder angle: ");
    Serial.print(shoulderAngle);
    Serial.print("   flex: ");
    Serial.print(lastData.flexVal);
    Serial.print(" -> claw: ");
    Serial.println(clawAngle);
  }

  delay(30);
}

//I got this conversion from some pca9685 servo example, works fine for now
int angleToPulse(int angle) {
  int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  return pulse;
}

void OnDataRecv(const esp_now_recv_info_t *info, const uint8_t *incomingData, int len) {
  memcpy(&lastData, incomingData, sizeof(lastData));
  gotFirstPacket = true;

}

// stuff i still need to fix / add:
// - The elbow and wrist channels arent doing anything yet, need those sensors bought asap
// - no timeout check, if the sleeve loses connection the arm just freezes wherever it was, which might actually be fine? or might be bad if its mid claw close on something. check later
// - roll and yaw arent used at all right now, only pitch. probably need those for the other joints
// - should double check the SERVOMIN/SERVOMAX numbers against the actual servo datasheet instead of just using whatever that forum post said
// - claw mapping direction might be backwards, need to physically test with the sensor on my hand, after purrchase
