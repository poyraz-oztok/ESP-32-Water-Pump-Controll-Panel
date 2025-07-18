#ifndef KEYBOARDMANAGER_H
#define KEYBOARDMANAGER_H

#include "config.h"
#include "commandHandler.h"
#include <Keypad.h>

//Functions
String getMeaning(char x);
void keyboardListen();

#endif