#pragma once

#include <Arduino.h>
#include "Pins.h"

class UltrasonicSensor {
public:
	// Constructor
	UltrasonicSensor();

	// Methods
	void sendTriger();
	double getDistance();

private:

	// Globals variables
	int _echoPin;
	int _trigPin;
};
