#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}


void loop() {
  char state = Serial.read();
  if(state == '1'){
    digitalWrite(13, HIGH);
  }else if(state == '0'){
    digitalWrite(13, LOW);
  }


}