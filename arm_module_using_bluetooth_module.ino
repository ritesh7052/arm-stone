#include <Wire.h>
#include <MPU6050.h>

 int motor1 = 3;
 int motor2 = 4;
 int motor3 = 5;
 int motor4 = 6;

// Initialize the MPU6050
MPU6050 mpu;

// Threshold for movement detection (you can adjust these values)
int forward = 5000;
int backward = -5000;
int left = -5000;
int right = 5000;

void setup() {
  Serial.begin(9600);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  
  Wire.begin();
  mpu.initialize();

  if (mpu.testConnection()) {
    Serial.println("MPU6050 is connected ");
  }
}

void loop() {

  int ax, ay, az;
 // int gx, gy, gz;
  // Read accelerometer values
  mpu.getAcceleration(&ax, &ay, &az);
  //mpu.getRotation(&gx, &gy, &gz);

  // Print the accelerometer values for debugging
  Serial.print("ax: "); Serial.print(ax);
  Serial.print(" ay: "); Serial.print(ay);
  Serial.print(" az: "); Serial.println(az);

  if (ay > 5000) {
    moveForward();
  }
  else if (ay < -5000) {
    moveBackward();
  }
  else if (ax < -5000) {
    turnLeft();
  }
  else if (ax > 5000) {
    turnRight();
  }
  else {
    stopMotors();
  }
  delay(100);
}

void moveForward() {
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
}
void moveBackward() {
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
}
void turnLeft() {
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
}
void turnRight() {
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
}
void stopMotors() {
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, LOW);
}
