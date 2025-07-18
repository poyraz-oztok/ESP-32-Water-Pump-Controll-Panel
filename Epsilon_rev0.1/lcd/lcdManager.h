#ifndef LCDMANAGER_H
#define LCDMANAGER_H

#include "config/config.h"
#include <U8g2lib.h>

void initializeLCD();
void showLogo();
void setUpLCD();
void startUpScheneLCD();
void clrLCD();
void pritnLCD(uint8_t x, uint8_t y, String message);

#endif