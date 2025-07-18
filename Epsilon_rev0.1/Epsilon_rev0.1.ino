// Written by poyraz-oztok 9.07.2025

#include "assets/index.h"
#include "assets/logo.h"
#include "config/config.h"
#include "control/commandHandler.h"
#include "error/errorHandler.h"
#include "input/keyboardManager.h"
#include "lcd/lcdManager.h"
#include "web/webInterface.h"

void setup() {
  initializeLed();
  setUpLCD();
  serverInit();
  startUpScheneLCD();
}

void loop() {
serverListen();
keyboardListen();

}