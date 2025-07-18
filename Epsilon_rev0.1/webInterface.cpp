#include "webInterface.h"
#include "index.h"
#include "keyboardManager.h"

WebServer server(port);

void serverInit(){
    WiFi.softAP(ssıd, password);
    IPAddress IP = WiFi.softAPIP();
    Serial.print("Ip Adress ");
    Serial.println(IP);

    server.on("/", handleRoot);
    server.on("/autoMan", handleAutoMan);
    server.on("/whatMode", whatMode);
    server.on("/command", handleCommand);

    server.begin();
    Serial.println("Acess Point And Web Interface created!");
    Serial.print("The Server has Begun: ");
    Serial.println("SSID: " + ssıd + " | Password: " + password);
}

void serverListen(){
    server.handleClient();
}

void handleRoot() {
    server.send_P(200, "text/html; charset=utf-8", html);
}

void handleAutoMan() {
    if (isOn && wasManual) {
      Mode = "off";
      isOn = false;
      digitalWrite(onLed, LOW);
    }
    else if (isOn && !wasManual) {
      Mode = "Manual";
      wasManual = true;
      digitalWrite(onLed, HIGH);
    }
    else if (!isOn) {
      Mode = "Auto";
      isOn = true;
      wasManual = false;
      digitalWrite(onLed, HIGH);
    }

    server.send(200, "text/plain; charset=utf-8", Mode);
  }

void handleCommand() {
    target = server.arg("target");
    whatsMsg();
    execute(msg);
    server.send(200, "text/plain", "OK");
  }

void whatMode() {
    server.send(200, "text/plain; charset=utf-8", Mode);
  }