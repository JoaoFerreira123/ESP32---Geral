#include <Arduino.h>

#define led 4
#define buttom 18
bool estadoLed = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(buttom, INPUT);
}

void loop() {
  if(digitalRead(buttom) == LOW){//SE O BOTÃO FOR PRESSIONADO
    estadoLed = !estadoLed; //inverte o estado do LED
    digitalWrite(led, estadoLed); //vai acender ou apagar o led
    while (digitalRead(buttom) == LOW);
    {
      delay(100);
    }
    
  } 


}

