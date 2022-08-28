#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  ledcSetup(0, 9600, 8);
  ledcAttachPin(27, 0);
}


void loop() {
  if(Serial.available() > 0){
  //só vai ser se tiver /, ou seja, só quando tiver um numero -> não lê o tempo todo
  String state = Serial.readStringUntil('/');
  Serial.flush();

  uint8_t valor = state.toInt();
  ledcWrite(0, valor);
  }
  


}