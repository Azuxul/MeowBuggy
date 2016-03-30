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

  update();
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

unsigned int MotorManager::getMotorId(Motors motor) {

  unsigned int resultMotorId = -1;
  unsigned int motorArraySize = sizeof(motorState);
  
  for(unsigned int i = motorArraySize; i >= 0; i--) {
    if(motorState[i][MOTOR_PIN] == motor) {
      resultMotorId = i;
      break;
    }
  }

  return resultMotorId;
}

void MotorManager::stop() {
  
  unsigned int motorArraySize = sizeof(motorState);
  
  for(unsigned int i = motorArraySize; i >= 0; i--) {
    motorState[i][MOTOR_STATE] = LOW;
    digitalWrite(motorState[i][MOTOR_PIN], LOW);
  }
}

void MotorManager::setMotorStatus(Motors motor, unsigned int status) {

  unsigned int motorId = getMotorId(motor);

  if(motorId >= 0) {
    motorState[motorId][MOTOR_STATE] = status;
  }
}

