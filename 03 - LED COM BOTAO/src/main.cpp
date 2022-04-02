#include <Arduino.h>

void setup() {
  pinMode(4, OUTPUT);
  pinMode(18, INPUT);
}

void loop() {
  int buttom = 0;
  buttom = digitalRead(18);

  if(buttom == 1){
    digitalWrite(4, 1);
  }else{
    digitalWrite(4, 0);
  }

}

//IDEIA DE LÓGIGA PARA MANTER ACESO
/*if (botao == ON && LED == APAGADO) {
    LED = LIGADO; 
}
if (botao == ON && LED == LIGADO) {
    LED = APAGADO; 
}

*/

