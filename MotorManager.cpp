#include <Arduino.h>
#include "MotorManager.h"
#include "Pins.h"
#include "Direction.h"
#include "Motor.h"

void MotorManager::stop() {

	_motorLeftFront.stop();
	_motorRightFront.stop();
	_motorLeftBack.stop();
	_motorRightBack.stop();
}

void MotorManager::changeDirection(Direction motorFrontLeft, Direction motorFrontRight, Direction motorBackLeft, Direction motorBackRight) {


	if (motorFrontLeft != IGNORE)
		_motorLeftFront.changeDirection(motorFrontLeft);
	if (motorFrontRight != IGNORE)
		_motorRightFront.changeDirection(motorFrontRight);
	if (motorBackLeft != IGNORE)
		_motorLeftBack.changeDirection(motorBackLeft);
	if (motorBackRight != IGNORE)
		_motorRightBack.changeDirection(motorBackRight);

}

void MotorManager::changeDirectionFromServoLoc(int servoLoc, int distance) {

	Direction motorFrontLeft;
	Direction motorFrontRight;
	Direction motorsBack;

	stop();

	if (distance <= 4) {
		motorFrontLeft = BACKWARD;
		motorFrontRight = BACKWARD;
		motorsBack = BACKWARD;
	}

	switch (servoLoc)
	{
	case 0:
		motorFrontLeft = FORWARD;
		motorFrontRight = STOPED;
		motorsBack = FORWARD;
		break;
	case 90:
		motorFrontLeft = STOPED;
		motorFrontRight = FORWARD;
		motorsBack = FORWARD;
		break;
	case 180:
		break;
		motorFrontLeft = BACKWARD;
		motorFrontRight = BACKWARD;
		motorsBack = BACKWARD;
	default:
		break;
	}

	changeDirection(motorFrontLeft, motorFrontRight, motorsBack, motorsBack);

	_lastFrontLeft = motorFrontLeft;
	_lastFrontRight = motorFrontRight;
	_lastBackLeft = motorsBack;
	_lastBackRight = motorsBack;

	lastDirection = true;
	buffer = 8;
}

void MotorManager::defualtDirection() {


	if (lastDirection) {

		changeDirection(_lastFrontLeft, _lastFrontRight, _lastBackLeft, _lastBackRight);

		if (--buffer <= 0) {
			lastDirection = false;
		}

	}
	else {
		changeDirection(FORWARD, FORWARD, FORWARD, FORWARD);
	}

}

