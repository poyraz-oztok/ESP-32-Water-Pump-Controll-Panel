// Written by poyraz-oztok 9.07.2025

#include "index.h"
#include "logo.h"
#include "config.h"
#include "commandHandler.h"
#include "errorHandler.h"
#include "keyboardManager.h"
#include "lcdManager.h"
#include "webInterface.h"

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