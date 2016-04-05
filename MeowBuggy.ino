#include "Motors.h"
#include "UltrasonicSensor.h"
#include "MotorManager.h"
#include "Accelerometer.h"
#include "Pins.h"
#include <Servo.h>

Servo servo;
int motorLoc;
bool motorNeg;
bool needToChangeDirection;
UltrasonicSensor utlrasonicSensor;
MotorManager motorManager;
Accelerometer accelerometer;
int distances[90];
int delayAccelerometer;

void setup() {

  Serial.begin(9600);

  servo.attach(2);
  servo.write(0);

  motorLoc = 180;

  motorManager.defualtDirection();

  Wire.begin();
  //accelerometer.setup();

  pinMode(STATUS_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(STATUS_LED, HIGH);
  digitalWrite(BUZZER, HIGH);

  delay(700);

  digitalWrite(BUZZER, LOW);
}

void loop() {

  double distance = utlrasonicSensor.getDistance();
  distances[motorLoc/2] = distance;

  if(distance <= 5) {
    needToChangeDirection = true;
  }

  delay(1);

  updateServoMotor();
}

void updateServoMotor() {
  
  if(motorNeg) {
    motorLoc-=2;
  } else {
    motorLoc+=2;
  }

  if(motorLoc <= 0 || motorLoc > 180) {
    motorNeg = !motorNeg;

    if(needToChangeDirection) {
      needToChangeDirection = false;
      motorManager.changeDirectionFromDisatenceArray(distances);
    } else {
      motorManager.defualtDirection();
    }
  }

  servo.write(motorLoc);
}

