#include "Motors.h"
#include "UltrasonicSensor.h"
#include "MotorManager.h"
#include "Accelerometer.h"
#include <Servo.h>

#define ULTRASONIC_ECHO 31
#define ULTRASONIC_TRIG 30
#define STATUS_LED 33
#define BUZZER_PIN 32

#define PRESURE_ADDRESS 0x77

Servo servo;
int motorLoc;
bool motorNeg;
bool needToChangeDirection;
UltrasonicSensor utlrasonicSensor(ULTRASONIC_ECHO, ULTRASONIC_TRIG);
MotorManager motorManager;
Accelerometer accelerometer;
int distances[90];
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
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(STATUS_LED, HIGH);
  digitalWrite(BUZZER_PIN, HIGH);

  delay(700);

  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {

  double distance = utlrasonicSensor.getDistance();
  distances[motorLoc/2] = distance;
  Serial.println(distance);

  if(distance <= 5) {
    needToChangeDirection = true;
  }

  if(++delayAccelerometer >= 500) {
    delayAccelerometer = 0;
    
  }

  delay(1);

  updateServoMotor();
}

void updateServoMotor() {
  
  if(motorNeg) {
    motorLoc-=2;
  } else {
    motorLoc+=2;
  }

  if(motorLoc <= 0 || motorLoc > 180) {
    motorNeg = !motorNeg;

    if(needToChangeDirection) {
      needToChangeDirection = false;
      motorManager.changeDirectionFromDisatenceArray(distances);
    } else {
      motorManager.defualtDirection();
    }
  }

  servo.write(motorLoc);
}

