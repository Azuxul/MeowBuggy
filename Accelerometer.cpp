#include <Arduino.h>
#include <Wire.h>
#include "Accelerometer.h"

void Accelerometer::setup() {
  Wire.beginTransmission(ACCELEROMETER_ADDRESS);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission(true);
}

Axes Accelerometer::getAccelerationValues() {
  
  Wire.beginTransmission(ACCELEROMETER_ADDRESS);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  
  Wire.requestFrom(ACCELEROMETER_ADDRESS, 6, true);
  int aX = Wire.read() << 8 | Wire.read();
  int aY = Wire.read() << 8 | Wire.read();
  int aZ = Wire.read() << 8 | Wire.read();

  Axes accelerationAxes;

  accelerationAxes.x= aX - _oldAxes.x;
  accelerationAxes.y = aY - _oldAxes.y;
  accelerationAxes.z = aZ - _oldAxes.z;

  _accelerationAxes = accelerationAxes;

  Axes axes;

  axes.x= aX;
  axes.y = aY;
  axes.z = aZ;

  _oldAxes = axes;

  return _accelerationAxes;
}

