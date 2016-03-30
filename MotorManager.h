#ifndef MotorManager_h
#define MotorManager_h

#include <Arduino.h>
#include "Motors.h"

// motorState index of values
#define MOTOR_PIN 0
#define MOTOR_STATE 1

class MotorManager {
public:
  // Constuctor
  MotorManager();

  // Methods
  void stop();
  void setMotorStatus(Motors motor, unsigned int status);
private:
  // Methods
  void update();
  void initMotor(Motors motor, unsigned int id);
  unsigned int getMotorId(Motors motor);

  // Variables
  int motorState[8][2];
};

#endif

