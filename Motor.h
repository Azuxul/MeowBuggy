#ifndef Motor_h
#define Motor_h

#include <Arduino.h>
#include "Direction.h"

class Motor {
public:

	// Constructor
	Motor(const int pinForwad, const int pinBackward);

	// Methods
	void stop();
	void changeDirection(Direction direction);
private:

	//Variables
	int _pinForwad;
	int _pinBackward;
};

#endif

