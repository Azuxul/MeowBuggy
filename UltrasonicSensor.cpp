#include <Arduino.h>
#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(int echoPin, int trigPin) {
  _echoPin = echoPin;
  _trigPin = trigPin;

  pinMode(_trigPin, OUTPUT);
  pinMode(_echoPin, INPUT);
}

void UltrasonicSensor::sendTriger() {

  digitalWrite(_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigPin, LOW);
}

double UltrasonicSensor::getDistance() {
  sendTriger();

  unsigned long pulseDuration = pulseIn(_echoPin, HIGH);
  return pulseDuration/58;
}

