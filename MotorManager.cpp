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

	_motorLeftFront.changeDirection(motorFrontLeft);
	_motorRightFront.changeDirection(motorFrontRight);
	_motorLeftBack.changeDirection(motorBackLeft);
	_motorRightBack.changeDirection(motorBackRight);
  
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
	changeDirection(BACKWARD, BACKWARD, BACKWARD, BACKWARD);

  } else {

    buffer = 10;

    if(degrees > 0) {

		changeDirection(STOPED, FORWARD, FORWARD, FORWARD);
    } else {
		changeDirection(FORWARD, STOPED, FORWARD, FORWARD);
    }
  }

  lastIsDefaultDirection = false;
}

void MotorManager::defualtDirection() {

  buffer = 10;

  changeDirection(FORWARD, FORWARD, FORWARD, FORWARD);

}

