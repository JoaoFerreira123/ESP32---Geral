#include <Arduino.h>

#define vermelho 21
#define verde 19
#define azul 18

void setup() { 
  ledcAttachPin(vermelho, 1);
  ledcAttachPin(verde, 2); // assign RGB led pins to channels
  ledcAttachPin(azul, 3);

  // Initialize channels 
  // channels 0-15, resolution 1-16 bits, freq limits depend on resolution
  // ledcSetup(uint8_t channel, uint32_t freq, uint8_t resolution_bits);
  ledcSetup(1, 12000, 8); // 12 kHz PWM, 8-bit resolution
  ledcSetup(2, 12000, 8);
  ledcSetup(3, 12000, 8);
  

  pinMode(2, OUTPUT);
}

void loop() {
  ledcWrite(1, 0);
  ledcWrite(2, 151);
  ledcWrite(3, 157);
  
}