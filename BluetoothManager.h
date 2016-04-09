#pragma once

#include <Arduino.h>
#include <SoftwareSerial.h>

class BluetoothManager
{
public:
	BluetoothManager() : serialConnexion(0, 1) {};
private:
	SoftwareSerial serialConnexion;
};
