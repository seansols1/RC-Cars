#include <WiFi.h>
#include <WebServer.h>
//libraries
//server 
const char* ssid = "RC_CAR";
const char* password = "12345678";
//pin from esp32 and L something 
WebServer server(80);

const int IN1 = 16;
const int IN2 = 17;
const int IN3 = 18;
const int IN4 = 19;
const int ENA = 21;
const int ENB = 22;
//controls the motor 
void forward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

void stopCar() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}
//server with html and css / Ai assinstance 
void handleRoot() {
  String html = "<!DOCTYPE html><html><head>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  html += "<style>";
  html += "body{display:flex;flex-direction:column;align-items:center;justify-content:center;height:100vh;margin:0;background:#111;font-family:sans-serif;}";
  html += "button{width:120px;height:120px;margin:10px;font-size:40px;border:none;border-radius:20px;background:#333;color:white;cursor:pointer;user-select:none;-webkit-user-select:none;}";
  html += "button:active{background:#555;}";
  html += ".row{display:flex;}";
  html += "</style></head><body>";
  html += "<div class='row'><button "
          "ontouchstart=\"fetch('/forward')\" "
          "ontouchend=\"fetch('/stop')\" "
          "onmousedown=\"fetch('/forward')\" "
          "onmouseup=\"fetch('/stop')\">&#8679;</button></div>";
  html += "<div class='row'>";
  html += "<button "
          "ontouchstart=\"fetch('/left')\" "
          "ontouchend=\"fetch('/stop')\" "
          "onmousedown=\"fetch('/left')\" "
          "onmouseup=\"fetch('/stop')\">&#8678;</button>";
  html += "<button onclick=\"fetch('/stop')\">&#9632;</button>";
  html += "<button "
          "ontouchstart=\"fetch('/right')\" "
          "ontouchend=\"fetch('/stop')\" "
          "onmousedown=\"fetch('/right')\" "
          "onmouseup=\"fetch('/stop')\">&#8680;</button>";
  html += "</div>";
  html += "<div class='row'><button "
          "ontouchstart=\"fetch('/backward')\" "
          "ontouchend=\"fetch('/stop')\" "
          "onmousedown=\"fetch('/backward')\" "
          "onmouseup=\"fetch('/stop')\">&#8681;</button></div>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}
//commands for the esp32 
void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  ledcAttach(ENA, 2000, 8);
  ledcAttach(ENB, 2000, 8);
  ledcWrite(ENA, 255);
  ledcWrite(ENB, 255);

  WiFi.softAP(ssid, password);

  server.on("/", handleRoot);
  server.on("/forward", []() { forward(); server.send(200, "text/plain", "OK"); });
  server.on("/backward", []() { backward(); server.send(200, "text/plain", "OK"); });
  server.on("/left", []() { left(); server.send(200, "text/plain", "OK"); });
  server.on("/right", []() { right(); server.send(200, "text/plain", "OK"); });
  server.on("/stop", []() { stopCar(); server.send(200, "text/plain", "OK"); });

  server.begin();
}
//loop for the server so it runs 
void loop() {
  server.handleClient();
}