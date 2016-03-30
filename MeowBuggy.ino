#include "Motors.h"
#include "UltrasonicSensor.h"
#include <Servo.h>

#define ULTRASONIC_ECHO 30
#define ULTRASONIC_TRIG 31

Servo servo;
int motorLoc;
bool motorNeg;
UltrasonicSensor utlrasonicSensor(ULTRASONIC_ECHO, ULTRASONIC_TRIG);

void setup() {

  // Init motors
  pinMode(MOTOR_1_F,OUTPUT);
  pinMode(MOTOR_1_B,OUTPUT);
  pinMode(MOTOR_2_F,OUTPUT);
  pinMode(MOTOR_2_B,OUTPUT);
  pinMode(MOTOR_3_F,OUTPUT);
  pinMode(MOTOR_3_B,OUTPUT);
  pinMode(MOTOR_4_F,OUTPUT);
  pinMode(MOTOR_4_B,OUTPUT);

  Serial.begin(9600);

  servo.attach(2);
  servo.write(0);

  motorLoc = 180;

  utlrasonicSensor.sendTriger();
}

void loop() {

  double distance = utlrasonicSensor.getDistance();
  Serial.println(distance);

  delay(1);

  updateMotor();
}

void updateMotor() {
  
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

