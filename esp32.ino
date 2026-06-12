#include <WiFi.h>
#include <WebServer.h>

// Substitua com as credenciais da sua rede Wi-Fi
const char* ssid     = "TESTEIOT";
const char* password = "TESTEIOT";

// O LED está conectado ao pino GPIO 2
const int ledPin = 2;

// Inicializa o servidor web na porta 80 (padrão HTTP)
WebServer server(80);

// Função que gera a página HTML no celular
void handleRoot() {
  String html = "<!DOCTYPE html><html>";
  html += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
  html += "<link rel=\"icon\" href=\"data:,\">";
  html += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}";
  html += ".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;";
  html += "text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}";
  html += ".button2 {background-color: #555555;}</style></head>";
  
  html += "<body><h1>Controle do LED - ESP32</h1>";
  html += "<p>Placa do Helder conectada!</p>";
  
  // Botões para controlar o LED
  html += "<p><a href=\"/led/on\"><button class=\"button\">LIGAR</button></a></p>";
  html += "<p><a href=\"/led/off\"><button class=\"button button2\">DESLIGAR</button></a></p>";
  
  html += "</body></html>";
  
  server.send(200, "text/html", html);
}

// Função para ligar o LED
void handleLedOn() {
  digitalWrite(ledPin, HIGH);
  server.sendHeader("Location", "/");
  server.send(303); // Redireciona de volta para a página principal
}

// Função para desligar o LED
void handleLedOff() {
  digitalWrite(ledPin, LOW);
  server.sendHeader("Location", "/");
  server.send(303); // Redireciona de volta para a página principal
}

void setup() {
  Serial.begin(115200);
  
  // Configura o pino do LED como saída
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Começa desligado

  // Conecta ao Wi-Fi
  Serial.print("Conectando em: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Exibe os dados de conexão no Monitor Serial
  Serial.println("");
  Serial.println("Wi-Fi conectado!");
  Serial.print("IP do ESP32: ");
  Serial.println(WiFi.localIP());

  // Define as rotas do servidor web
  server.on("/", handleRoot);
  server.on("/led/on", handleLedOn);
  server.on("/led/off", handleLedOff);

  // Inicia o servidor
  server.begin();
  Serial.println("Servidor Web iniciado.");
}

void loop() {
  // Mantém o servidor escutando as requisições do celular
  server.handleClient();
}
