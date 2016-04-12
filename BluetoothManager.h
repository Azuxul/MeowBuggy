#pragma once

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "MotorManager.h"
#include "Direction.h"

#define SPEED 9600

class BluetoothManager
{
public:

	BluetoothManager(MotorManager& motorManager);

	void update();
private:

	void updateMotorFromPacket(int (&packet)[10]);

	SoftwareSerial serialConnexion;
	MotorManager& motorManager;
};
