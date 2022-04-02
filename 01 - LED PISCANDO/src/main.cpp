#include <Arduino.h>

 
void setup() {
 pinMode(2, OUTPUT); //O PINO D27 CORRESPONDE AO GPIO27, ENTÃO NA PRÁTICA USA SÓ O NÚMERO DO GPIO
}
 
void loop() {
 
 digitalWrite(2, HIGH);
 delay(250);
 digitalWrite(2, LOW);
 delay(250);
}



