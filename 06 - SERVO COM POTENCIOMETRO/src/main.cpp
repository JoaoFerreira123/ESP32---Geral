#include <Arduino.h>
#include <Servo.h>

static const int servoPin = 2;
static const int potentiometerPin = 15; //deve ser um pino ADC

Servo servo1;

void setup() {
    Serial.begin(9600);
    servo1.attach(servoPin);
}

void loop() {
    int servoPosition = map(analogRead(potentiometerPin), 0, 4096, 0, 180);
    servo1.write(servoPosition);
    Serial.println(servoPosition);
    delay(20);
}