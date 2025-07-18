#ifndef KEYBOARDMANAGER_H
#define KEYBOARDMANAGER_H

#include "config/config.h"
#include "control/commandHandler.h"
#include <Keypad.h>

//Functions
String getMeaning(char x);
void keyboardListen();

#endif