#include <SoftwareSerial.h>
#include "UltrasonicSensor.h"
#include "MotorManager.h"
#include "Accelerometer.h"
#include "Pins.h"
#include "Direction.h"
#include <Servo.h>

Servo servo;
int motorLoc;
bool motorPossitiveLoc;
UltrasonicSensor utlrasonicSensor;
MotorManager motorManager;
Accelerometer accelerometer;
int distances[3];
int delayAccelerometer;

void setup() {

  Serial.begin(9600);

  servo.attach(2);
  servo.write(0);

  motorLoc = 180;

  motorManager.defualtDirection();

  Wire.begin();
  //accelerometer.setup();

  pinMode(STATUS_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(STATUS_LED, HIGH);
  digitalWrite(BUZZER, HIGH);

  delay(700);

  digitalWrite(BUZZER, LOW);
}

void loop() {

	if (servo.attached()) {

		double distance = utlrasonicSensor.getDistance();

		if (distance <= 1) {
			motorManager.stop();
		}

		if (distance <= 8) {
			motorManager.changeDirectionFromServoLoc(motorLoc, distance);
		}
		else {
			motorManager.defualtDirection();
		}

		delay(1);

		updateServoMotor();
	}
	else {
		motorManager.stop();
	}
}

void updateServoMotor() {
  
	servo.write(motorLoc); 

	delay(200);

	if (motorLoc >= 180) {
		motorPossitiveLoc = false;
	}
	else if (motorLoc <= 0) {
		motorPossitiveLoc = true;
	}

	motorLoc += motorPossitiveLoc ? 90 : -90;
}

