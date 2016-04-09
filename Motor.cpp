#include <Arduino.h>
#include "Motor.h"
#include "Direction.h"

Motor::Motor(const int pinForwad, const int pinBackward) : _pinForwad(pinForwad), _pinBackward(pinBackward) {

	pinMode(pinForwad, OUTPUT);
	pinMode(pinBackward, OUTPUT);
}

void Motor::stop() {
	int status = HIGH;

	for (int i = 0; i <= 2; i++) {
		digitalWrite(_pinForwad, status);
		digitalWrite(_pinBackward, status);

		if (i <= 1) {
			status = LOW;
			delay(1);
		}
	}
}

void Motor::changeDirection(Direction direction) {

	uint8_t statusMotorForward;
	uint8_t statusMotorBackward;

	if (direction == FORWARD) {
		statusMotorForward = HIGH;
		statusMotorBackward = LOW;
	}
	else if(direction == BACKWARD) {
		statusMotorForward = LOW;
		statusMotorBackward = HIGH;
	}
	else {
		statusMotorForward = LOW;
		statusMotorBackward = LOW;
	}

	digitalWrite(_pinForwad, statusMotorForward);
	digitalWrite(_pinBackward, statusMotorBackward);
}
