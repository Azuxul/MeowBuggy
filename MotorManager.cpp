#include <Arduino.h>
#include "MotorManager.h"
#include "Motors.h"

MotorManager::MotorManager() {

  // Init motors
  initMotor(MOTOR_1_F, 23);
  initMotor(MOTOR_1_B, 22);
  initMotor(MOTOR_2_F, 25);
  initMotor(MOTOR_2_B, 24);
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

void MotorManager::changeDirectionFromDisatenceArray(int (&distances)[90]) {

  int higestDistance = -1;
  int degrees = -1;

  for(int i = 90; i >= 0; i--) {
    if(distances[i] > higestDistance) {
      higestDistance = distances[i];
      degrees = i;
    }
  }

  degrees -= 45;

  if(higestDistance <= 2) {
    stop();
  }

  if(higestDistance <= 5 || buffer >= 0) {

    buffer--;
    
    setMotorStatus(MOTOR_1_F, LOW); 
    setMotorStatus(MOTOR_2_F, LOW);
    setMotorStatus(MOTOR_3_F, LOW);
    setMotorStatus(MOTOR_4_F, LOW);
    setMotorStatus(MOTOR_1_B, HIGH);
    setMotorStatus(MOTOR_2_B, HIGH);
    setMotorStatus(MOTOR_3_B, HIGH);
    setMotorStatus(MOTOR_4_B, HIGH);
  } else {

    buffer = 10;

    setMotorStatus(MOTOR_1_B, LOW); 
    setMotorStatus(MOTOR_2_B, LOW);
    setMotorStatus(MOTOR_3_B, LOW);
    setMotorStatus(MOTOR_4_B, LOW);
    setMotorStatus(MOTOR_3_F, HIGH);
    setMotorStatus(MOTOR_4_F, HIGH);

    if(degrees > 0) {

      setMotorStatus(MOTOR_1_F, HIGH);
      setMotorStatus(MOTOR_2_F, LOW);
    } else {
      setMotorStatus(MOTOR_1_F, LOW);
      setMotorStatus(MOTOR_2_F, HIGH);
    }
  }

  lastIsDefaultDirection = false;
}

void MotorManager::defualtDirection() {

  buffer = 10;

  if(!lastIsDefaultDirection) {
    setMotorStatus(MOTOR_1_B, LOW);
    setMotorStatus(MOTOR_2_B, LOW);
    setMotorStatus(MOTOR_3_B, LOW);
    setMotorStatus(MOTOR_4_B, LOW);
  }

  lastIsDefaultDirection = true;

  setMotorStatus(MOTOR_1_F, HIGH);
  setMotorStatus(MOTOR_2_F, HIGH);
  setMotorStatus(MOTOR_3_F, HIGH);
  setMotorStatus(MOTOR_4_F, HIGH);

}

