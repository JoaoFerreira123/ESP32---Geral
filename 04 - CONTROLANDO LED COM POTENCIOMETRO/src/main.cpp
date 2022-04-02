#include <Arduino.h>

void setup() {
  ledcAttachPin(19, 0);
  ledcSetup(0, 5000, 12);
  Serial.begin(9600);
}

void loop() {
  ledcWrite(0, analogRead(4));
  Serial.println(analogRead(4));
}