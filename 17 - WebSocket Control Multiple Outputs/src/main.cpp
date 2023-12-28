#include <Arduino.h>

//Importação das Bibliotecas
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "SPIFFS.h"
#include <AsyncElegantOTA.h>

// Credenciais de Rede
const char* ssid = "Oi_A822";
const char* password = "MchCM3TM";

AsyncWebServer server(80);             // Cria o servidor na porta 80
AsyncWebSocket ws("/ws");              // Crie um objeto WebSocket

// Inicialização SPIFFS
void initSPIFFS() {
  if (!SPIFFS.begin(true)) {
    Serial.println("An error has occurred while mounting SPIFFS");
  }
  Serial.println("SPIFFS mounted successfully");
}

// Inicialização WiFi
void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
      delay(500);
  }
  Serial.println(WiFi.localIP());
}

bool ledState1 = 0;
bool ledState2 = 0;
bool ledState3 = 0;
bool ledState4 = 0;
bool ledState5 = 0;

//Notifica os clientes sobre o estado atual do LED
void notifyClients1() {ws.textAll(String(ledState1));}
void notifyClients2() {ws.textAll(String(ledState2 + 2));}
void notifyClients3() {ws.textAll(String(ledState3 + 4));}
void notifyClients4() {ws.textAll(String(ledState4 + 6));}
void notifyClients5() {ws.textAll(String(ledState5 + 8));}


/*
Função de retorno que é executada sempre que recebemos novos dados do cliente (WebSite) através do
protocolo WebSocket. Se recebermos a mensagem "toggle", será alterado o valor da variável ledState.
Também todos os clientes serão notificados da mudança, chamando a função notifyClients(), isso é feito
para a interface ser atualizada de acordo, com o estado atual do led.
*/


void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;
    if (strcmp((char*)data, "toggle1") == 0) {ledState1 = !ledState1;notifyClients1();}
    if (strcmp((char*)data, "toggle2") == 0) {ledState2 = !ledState2;notifyClients2();}
    if (strcmp((char*)data, "toggle3") == 0) {ledState3 = !ledState3;notifyClients3();}
    if (strcmp((char*)data, "toggle4") == 0) {ledState4 = !ledState4;notifyClients4();}
    if (strcmp((char*)data, "toggle5") == 0) {ledState5 = !ledState5;notifyClients5();}
  }
}

// Função que lida com as etapas de conexão do WebSocket
void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
  void *arg, uint8_t *data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:                  // quando o cliente está logado
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      break;
    case WS_EVT_DISCONNECT:               // когда клиент вышел из системы
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:                     //quando o cliente está desconectado
      handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:                     //em resposta a uma solicitação de ping
    case WS_EVT_ERROR:                    // ao receber um erro do cliente
      break;
  }
}

String processor(const String& var) {
  Serial.println(var);
  if (var == "STATE1") {if (ledState1) {return "ON";} else {return "OFF";}}
  if (var == "STATE2") {if (ledState2) {return "ON";} else {return "OFF";}}
  if (var == "STATE3") {if (ledState3) {return "ON";} else {return "OFF";}}
  if (var == "STATE4") {if (ledState4) {return "ON";} else {return "OFF";}}
  if (var == "STATE5") {if (ledState5) {return "ON";} else {return "OFF";}}
}

// Inicializa o WebSocket
void initWebSocket() {
  ws.onEvent(onEvent);
  server.addHandler(&ws);
}

void setup() {

  Serial.begin(115200);

  pinMode(2, OUTPUT); digitalWrite(2, LOW);
  pinMode(33, OUTPUT); digitalWrite(33, LOW);
  pinMode(25, OUTPUT); digitalWrite(25, LOW);
  pinMode(26, OUTPUT); digitalWrite(26, LOW);
  pinMode(27, OUTPUT); digitalWrite(27, LOW);


  initSPIFFS();
  initWiFi();
  initWebSocket();

  // Página Inicial HTML
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/index.html", "text/html", false, processor);
  });
  server.serveStatic("/", SPIFFS, "/");

  // Inicialização ElegantOTA
  AsyncElegantOTA.begin(&server);

  // Inicia o servidor
  server.begin();
}

void loop() {
  AsyncElegantOTA.loop();
  ws.cleanupClients();

  digitalWrite(2, ledState1);
  digitalWrite(33, ledState2);
  digitalWrite(25, ledState3);
  digitalWrite(26, ledState4);
  digitalWrite(27, ledState5);
}