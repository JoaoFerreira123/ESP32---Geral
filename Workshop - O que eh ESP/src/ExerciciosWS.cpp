/* 
//------ 1 - LED BLINK -------------
#include <Arduino.h>

#define LED 32

void setup(){
  pinMode(LED, OUTPUT);
}

void loop(){
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
}
*/


//---------- 2 - LEDS ALTERNADOS---------
/*
#include <Arduino.h>

#define LED1 32
#define LED2 33
#define TIME 500

void setup(){
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop(){
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  delay(TIME);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  delay(TIME);
}

*/



//-------- 3 - LEDS COM BOTÃO ------------
/*
#include <Arduino.h>

#define LED 32
#define BOTAO 35

void setup(){
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(BOTAO, INPUT);
}

void loop(){
  int estado_botao = digitalRead(BOTAO);
  //Serial.println(estado_botao);
  if(estado_botao == 0){
    Serial.println("Apertei");
    digitalWrite(LED, HIGH);
  }else{
    Serial.println("Solto");
    digitalWrite(LED, LOW);
  }
}
*/

//-------- 4 - VARIANDO LUMINOSIADE DO LED ------------
/*#include <Arduino.h>


#define LED 25

void setup(){
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop(){
 analogWrite(LED, 50); 
}
*/

//----------- 4.1 - VARIANDO A LUMINOSIDADE DO LED COM LEDC---------
/*
#include <Arduino.h>

#define LED 25

#define canal 0 //São 16 canais (0 a 15)
#define frequencia 12000 //Frequencia do Canal (1 a 40MHz)
#define resolucao 8 // Resolução do canal (1 a 16 bits)

void setup(){
  Serial.begin(115200);
  pinMode(LED, OUTPUT);

  ledcSetup(canal, frequencia, resolucao); //configura o canal
  ledcAttachPin(LED, canal); //atribui um pino a um canal
}

void loop(){
  ledcWrite(canal, 50);
}
*/

//-------- 5 - LED + POTENCIÔMETRO ---------------------
/*
#include <Arduino.h>

#define LED 25
#define POT_PIN 32

void setup(){
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(POT_PIN, INPUT);
}

void loop(){
  int pot = analogRead(POT_PIN);
  //Serial.println(pot);
  int brilho = map(pot, 0, 4095, 0, 255);
  Serial.println(brilho);
  analogWrite(LED, brilho);
}

*/

//--------- 6 - VELOCIDADE DO LED COM POTENCIÔMETRO --------------
/*
#include <Arduino.h>

#define LED 25
#define POT_PIN 32

void setup(){
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(POT_PIN, INPUT);
}

void loop(){
  int pot = analogRead(POT_PIN);
  //Serial.println(pot);
  int vel = map(pot, 0, 2000, 100, 1000);
  digitalWrite(LED, HIGH);
  delay(vel);
  digitalWrite(LED, LOW);
  delay(vel);
}

*/


//----------- 7 - DESAFIO SEMÁFORO --------------------
/*
#include <Arduino.h>

#define LED_VERDE 25
#define LED_VERMELHO 26
#define LED_AMARELO 27

#define BOTAO 34


int delay_verde = 2000;
int delay_vermelho = 1000;
int delay_amarelo = 500;

void pedestre(){
  Serial.println(digitalRead(BOTAO));
  delay_vermelho = 5000;
}


void setup(){
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);

  pinMode(BOTAO, INPUT);
  attachInterrupt(BOTAO, pedestre, FALLING);

  Serial.begin(115200);

}

void loop(){

  //Vermelho Acende
  digitalWrite(LED_VERMELHO, HIGH);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERDE, LOW);
  delay(delay_vermelho);

  delay_vermelho = 1000;

  //Vermelho Apaga e Verde Acende
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERDE, HIGH);
  delay(delay_verde);

  //Verde Apaga e Amarelo Acende
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_AMARELO, HIGH);
  digitalWrite(LED_VERDE, LOW);
  delay(delay_amarelo);



}

*/