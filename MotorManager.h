#ifndef MotorManager_h
#define MotorManager_h

#include <Arduino.h>
#include "Pins.h"
#include "Direction.h"
#include "Motor.h"

class MotorManager {
public:

  // Constuctor
	MotorManager() : _motorLeftFront(MOTOR_FRONT_LEFT_FORWARD, MOTOR_FRONT_LEFT_BACKWARD),
		_motorRightFront(MOTOR_FRONT_RIGHT_FORWARD, MOTOR_FRONT_RIGHT_BACKWARD),
		_motorLeftBack(MOTOR_BACK_LEFT_FORWARD, MOTOR_BACK_LEFT_BACKWARD),
		_motorRightBack(MOTOR_BACK_RIGHT_FORWARD, MOTOR_BACK_RIGHT_BACKWARD) {};

  // Methods
  void stop();
  void changeDirectionFromDisatenceArray(int (&distances)[90]);
  void defualtDirection();
private:

  // Methods
  void changeDirection(Direction motorFrontLeft, Direction motorFrontRight, Direction motorBackLeft, Direction motorBackRight);

  // Variables
  int buffer;
  bool lastIsDefaultDirection;
  Motor _motorLeftFront;
  Motor _motorLeftBack;
  Motor _motorRightFront;
  Motor _motorRightBack;
};

#endif

