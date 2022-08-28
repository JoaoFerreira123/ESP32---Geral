#include <Arduino.h>

char comando;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  comando = Serial.read();
  Serial.print(comando);
  if (comando == 'L'){
    digitalWrite(13, HIGH);
  }
  if (comando == 'D'){
    digitalWrite(13, LOW);
  }

}