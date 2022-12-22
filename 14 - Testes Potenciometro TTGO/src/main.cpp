#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();

#define pot 39
int valorPot = 0;

void setup() {
  tft.init();
  tft.fillScreen(TFT_BLACK);
  Serial.begin(9600);

}

void loop() {
  valorPot = map(analogRead(pot),0,4096,0,240);
  tft.fillScreen(TFT_BLACK);
  Serial.println(valorPot);
  tft.drawFastHLine(0, valorPot, 150, TFT_RED);
  delay(50);



}