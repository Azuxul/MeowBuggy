#include <Arduino.h>
#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(int echoPin, int trigPin) {
  _echoPin = echoPin;
  _trigPin = trigPin;

  pinMode(_echoPin, OUTPUT);
  pinMode(_trigPin, INPUT);
}

void UltrasonicSensor::sendTriger() {

  digitalWrite(_echoPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_echoPin, LOW);
}

double UltrasonicSensor::getDistance() {
  sendTriger();

  unsigned long pulseDuration = pulseIn(_trigPin, HIGH);
  return pulseDuration/58;
}

