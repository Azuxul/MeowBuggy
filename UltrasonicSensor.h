#ifndef UltrasonicSensor_h
#define UltrasonicSensor_h

#include <Arduino.h>

class UltrasonicSensor {
public:
  // Constructor
  UltrasonicSensor(int echoPin, int trigPin);

  // Methods
  void sendTriger();
  double getDistance();
  
private:

  // Globals variables
  int _echoPin;
  int _trigPin;
};

#endif

