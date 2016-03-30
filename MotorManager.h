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
  void changeDirectionFromDisatenceArray(int (&distances)[90]);
  void defualtDirection();
private:
  // Methods
  void update();
  void initMotor(Motors motor, unsigned int id);
  unsigned int getMotorIdFromPin(unsigned int pin);

  // Variables
  int motorState[8][2];
  int buffer;
  bool lastIsDefaultDirection;
};

#endif

