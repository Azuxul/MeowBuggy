#include <Arduino.h>
#include "MotorManager.h"
#include "Motors.h"

MotorManager::MotorManager() {

  // Init motors
  initMotor(MOTOR_1_F, 0);
  initMotor(MOTOR_1_B, 1);
  initMotor(MOTOR_2_F, 2);
  initMotor(MOTOR_2_B, 3);
  initMotor(MOTOR_3_F, 4);
  initMotor(MOTOR_3_B, 5);
  initMotor(MOTOR_4_F, 6);
  initMotor(MOTOR_4_B, 7);

}

void MotorManager::initMotor(Motors motor, unsigned int id) {
  motorState[id][MOTOR_PIN] = motor;
  motorState[id][MOTOR_STATE] = LOW;

  pinMode(motor, OUTPUT);
}

void MotorManager::update() {

  unsigned int motorArraySize = sizeof(motorState);
  
  for(unsigned int i = motorArraySize; i >= 0; i--) {
    digitalWrite(motorState[i][MOTOR_PIN], motorState[i][MOTOR_STATE]);
  }
}

