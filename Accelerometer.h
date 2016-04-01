#ifndef Accelerometer_h
#define Accelerometer_h

#include <Arduino.h>
#include <Wire.h>

#define ACCELEROMETER_ADDRESS 0x68

typedef struct {
  int x;
  int y;
  int z;
} Axes;

class Accelerometer {
public:

  // Methods
  Axes getAccelerationValues();
  void setup();
private:

  // Variables
  Axes _accelerationAxes;
  Axes _oldAxes;
};

#endif

