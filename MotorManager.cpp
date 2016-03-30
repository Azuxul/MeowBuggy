#include <Arduino.h>
#include "MotorManager.h"
#include "Motors.h"

MotorManager::MotorManager() {

  // Init motors
  initMotor(MOTOR_1_F, 22);
  initMotor(MOTOR_1_B, 23);
  initMotor(MOTOR_2_F, 24);
  initMotor(MOTOR_2_B, 25);
  initMotor(MOTOR_3_F, 26);
  initMotor(MOTOR_3_B, 27);
  initMotor(MOTOR_4_F, 28);
  initMotor(MOTOR_4_B, 29);

  update();
}

void MotorManager::initMotor(Motors motor, unsigned int pin) {
  motorState[motor][MOTOR_PIN] = pin;
  motorState[motor][MOTOR_STATE] = LOW;

  pinMode(motor, OUTPUT);
}

void MotorManager::update() {

  unsigned int motorArraySize = sizeof(motorState);
  for(int i = motorArraySize; i >= 0; i--) {
    digitalWrite(motorState[i][MOTOR_PIN], motorState[i][MOTOR_STATE]);
  }
}

unsigned int MotorManager::getMotorIdFromPin(unsigned int pin) {

  unsigned int resultMotorId = -1;
  unsigned int motorArraySize = sizeof(motorState);
  
  for(int i = motorArraySize; i >= 0; i--) {
    if(motorState[i][MOTOR_PIN] == pin) {
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

   motorState[motor][MOTOR_STATE] = status;
   digitalWrite(motorState[motor][MOTOR_PIN], status);
}

