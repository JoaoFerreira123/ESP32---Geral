#include <Arduino.h>

#define canal 0
#define freq 12000
#define resoluc 8


void setup() {
  ledcSetup(canal, freq, resoluc);
  ledcAttachPin(27, canal);
}

void loop() {
  for(int i=0; i<255; i+=8){
    ledcWrite(canal, i);
    delay(20);
  }
  
  for(int j=255; j>0; j-=8){
    ledcWrite(canal, j);
    delay(20);
  }

  
}