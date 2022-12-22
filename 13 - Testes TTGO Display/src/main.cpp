#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>

// construtor
TFT_eSPI tft=TFT_eSPI();

void setup() {
  //inicializa a tela
  tft.init();

  //preenche a tela com uma cor
  //a cor pode ser um código haxadecimal da cor
  tft.fillScreen(TFT_BLUE);
  delay(1000);
  tft.fillScreen(0x05DC);

  //Define a cor do texto e do fundo do texto
  tft.setTextColor(TFT_RED, 0x05DC);

  //Coloca a String na tela, nas posições X=30 e Y = 30.
  //A origem é no canto superior esquerdo da tela
  //O terceiro argumento é a fonte. Cada fonte tem seu tamanho
  tft.drawString("Hello World", 30, 30,2);
  
}

int count = 0;

void loop() {
  count++;
  tft.drawString(String(count), 50, 150, 7); //A fonte 7 é somente para números. Usando a classe String pra converter número pra String
  delay(1000);
}