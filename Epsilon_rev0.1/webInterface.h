#ifndef WEBINTERFACE_H
#define WEBINTERFACE_H

#include "config.h"
#include <WiFi.h>
#include <WebServer.h>

void serverInit();
void serverListen();
void handleRoot();
void handleAutoMan();
void handleCommand();
void whatMode();

#endif