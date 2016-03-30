#include "Motors.h"
#include "UltrasonicSensor.h"
#include "MotorManager.h"
#include <Servo.h>

#define ULTRASONIC_ECHO 30
#define ULTRASONIC_TRIG 31

Servo servo;
int motorLoc;
bool motorNeg;
UltrasonicSensor utlrasonicSensor(ULTRASONIC_ECHO, ULTRASONIC_TRIG);
MotorManager motorManager();
int distances[180];

void setup() {

  Serial.begin(9600);

  servo.attach(2);
  servo.write(0);

  motorLoc = 180;

  utlrasonicSensor.sendTriger();
}

void loop() {

  double distance = utlrasonicSensor.getDistance();
  distances[motorLoc] = distance;

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
  }

  servo.write(motorLoc);
}

