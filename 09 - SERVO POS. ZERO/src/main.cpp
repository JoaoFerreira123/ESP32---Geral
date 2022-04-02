#include <Arduino.h>
#include <Servo.h>

static const int servoPin = 5;//tava no 2

Servo servo1;

void setup() {
    Serial.begin(9600);
    servo1.attach(servoPin);
}

void loop(){
  servo1.write(0);
}