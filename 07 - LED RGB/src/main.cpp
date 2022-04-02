#include <Arduino.h>

#define verde 2
#define vermelho 4
#define azul 5

void setup() { 
  ledcAttachPin(verde, 1); // assign RGB led pins to channels
  ledcAttachPin(vermelho, 2);
  ledcAttachPin(azul, 3);

  // Initialize channels 
  // channels 0-15, resolution 1-16 bits, freq limits depend on resolution
  // ledcSetup(uint8_t channel, uint32_t freq, uint8_t resolution_bits);
  ledcSetup(1, 12000, 8); // 12 kHz PWM, 8-bit resolution
  ledcSetup(2, 12000, 8);
  ledcSetup(3, 12000, 8);

}

void loop() {
  ledcWrite(1, 255);
  delay(2000);
 
}