#include <Arduino.h>
#include <WiFi.h>

const char* nomeRedeWifi = "Oi_A822";
const char* senhaWifi = "MchCM3TM";
int LED = 13;

//Inicia o servidor 
WiFiServer servidor(80);

void setup(){
  Serial.begin(115200);
  pinMode(LED, OUTPUT);

  Serial.println();
  Serial.print("Conectando-se a ");
  Serial.println(nomeRedeWifi);
  //conecta ao Wifi
  WiFi.begin(nomeRedeWifi, senhaWifi);

  //Rotina para verificar se conectou ao Wifi
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print('.');
  }
  Serial.println("");
  Serial.println("WiFi conectada.");
  Serial.println("Endereço de IP: ");
  //Endereço de IP do servidor
  Serial.println(WiFi.localIP());

  servidor.begin();
};

void loop(){
  WiFiClient cliente = servidor.available(); //verifica se há alguém conectado e armazena na variável cliente
  if (cliente){ //se tiver um cliente
    Serial.println("Novo Cliente"); 
    String dados = ""; //faz uma string pra manter os dados recebidos do cliente
    while (cliente.connected()){ 

      if(cliente.available()){ //se houver btytes (dados) para ler do cliente
        char d = cliente.read(); //leia 
        Serial.write(d);

        if(d == '\n'){ //se o byte for um caractere de nova linha
          if(dados.length() == 0){
            cliente.println("HTTP/1.1 200 OK");
            cliente.println("Content-type:text/html");
            cliente.println();
            cliente.print("Clique <a href=\"/H\">AQUI</a> para acender o LED.<br>");
            cliente.print("Clique <a href=\"/L\">AQUI</a> para apagar o LED.<br>");
            cliente.println();
            break;
          }else{
            dados = ""; //se tiver uma nova linha, limpe a linha atual
          }
        } else if (d != '\r'){ //se tiver qualquer coisa além do caractere de retorno da linha, adiciona ao final da linha
          dados += d;
        }
        if (dados.endsWith("GET /H")){
          digitalWrite(LED, HIGH);
        }
        if (dados.endsWith("GET /L")){
          digitalWrite(LED, LOW);
        }
      }
    }
    cliente.stop();
    Serial.println("Cliente Desconectado");
  }

};