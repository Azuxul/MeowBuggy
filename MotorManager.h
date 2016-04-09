#pragma once

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
	void defualtDirection();
	void changeDirection(Direction motorFrontLeft, Direction motorFrontRight, Direction motorBackLeft, Direction motorBackRight);
	void changeDirectionFromServoLoc(int servoLoc, int distance);
private:

	// Variables
	bool lastDirection;
	int buffer;
	Direction _lastFrontLeft;
	Direction _lastFrontRight;
	Direction _lastBackLeft;
	Direction _lastBackRight;
	Motor _motorLeftFront;
	Motor _motorLeftBack;
	Motor _motorRightFront;
	Motor _motorRightBack;
};

