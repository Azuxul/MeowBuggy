#include <Arduino.h>
#include <SoftwareSerial.h>

#pragma once
class BluetoothManager
{
public:
	BluetoothManager() : serialConnexion(0, 1) {};
private:
	SoftwareSerial serialConnexion;
};

