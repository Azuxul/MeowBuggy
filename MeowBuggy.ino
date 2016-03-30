#include "Motors.h"
#include <Servo.h>

Servo servo;
int motorLoc;
bool motorNeg;

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
}

void loop() {

  delay(10);

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

