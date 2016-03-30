#include "Motors.h"
#include "UltrasonicSensor.h"
#include "MotorManager.h"
#include <Servo.h>

#define ULTRASONIC_ECHO 30
#define ULTRASONIC_TRIG 31

Servo servo;
int motorLoc;
bool motorNeg;
bool needToChangeDirection;
UltrasonicSensor utlrasonicSensor(ULTRASONIC_ECHO, ULTRASONIC_TRIG);
MotorManager motorManager;
int distances[90];

void setup() {

  Serial.begin(9600);

  servo.attach(2);
  servo.write(0);

  motorLoc = 180;

  motorManager.defualtDirection();
}

void loop() {

  double distance = utlrasonicSensor.getDistance();
  distances[motorLoc/2] = distance;

  if(distance <= 10) {
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

