#include "BluetoothManager.h"
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "MotorManager.h"
#include "Direction.h"

BluetoothManager::BluetoothManager(MotorManager& motorManager) : serialConnexion(BLUETOOTH_SERIAL_RXD, BLUETOOTH_SERIAL_TXD), motorManager(motorManager) {

	serialConnexion.begin(SPEED);
}

void BluetoothManager::update() {

	String dataBuffer = "";
	int commands[10] = {0x00};
	int indexOfArray = 0;
	const char separator = ';';

	while (serialConnexion.available()) {
		delay(1);
		const char c = serialConnexion.read();

		if (c == separator) {

			if(indexOfArray < 10) {
				commands[indexOfArray] = dataBuffer.toInt();
				indexOfArray++;
				dataBuffer = "";
			}
		}
		else {
			dataBuffer += c;
		}
	}

	if (commands[0] != 0x00) {

		Serial.println(commands[0]);
		Serial.println(commands[1] == 0x01);

		switch (commands[0])
		{
		case 0x01: // Motor direction packet
			updateMotorFromPacket(commands);
			break;
		case 0x02: // Motor stop packet
			motorManager.stop();
			break;
		case 0x03: // Motor auto mode packet
			motorManager.setAutoMode(commands[1] == 0x01);
			break;
		case 0x04: // Motor inpulse direction mode packet
			motorManager.setImpulseDirectionMode(commands[1] == 0x01);
			break;
		default:
			break;
		}
	}
	
}

void BluetoothManager::updateMotorFromPacket(int (&packet)[10]) {

	Direction motorDirections[4] = { IGNORE };

	for (int i = 1; i <= 5; i++) {

		switch (packet[i])
		{
		case 0x00:
			break;
		case 0x01:
			motorDirections[i - 1] = FORWARD;
			break;
		case 0x02:
			motorDirections[i - 1] = BACKWARD;
			break;
		case 0x03:
			motorDirections[i - 1] = STOPED;
			break;
		default:
			break;
		}
	}

	motorManager.changeDirection(motorDirections[0], motorDirections[1], motorDirections[2], motorDirections[3]);
}


