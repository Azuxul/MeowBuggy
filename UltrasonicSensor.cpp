#include <Arduino.h>
#include "UltrasonicSensor.h"
#include "Pins.h"

UltrasonicSensor::UltrasonicSensor() {
  
  pinMode(ULTRASONIC_TRIG, OUTPUT);
  pinMode(ULTRASONIC_ECHO, INPUT);
}

void UltrasonicSensor::sendTriger() {

  digitalWrite(ULTRASONIC_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIG, LOW);
}

double UltrasonicSensor::getDistance() {
  sendTriger();

  unsigned long pulseDuration = pulseIn(ULTRASONIC_ECHO, HIGH);
  return pulseDuration/58;
}

