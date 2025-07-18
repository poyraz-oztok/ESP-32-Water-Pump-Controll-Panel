#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// ---Led Pins---
#define onLed 19
#define errLed 0

// ---LCD Pins---

#define LCD_D0 0
#define LCD_D1 1
#define LCD_D2 2
#define LCD_D3 3
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7

#define LCD_WR 8
#define LCD_RST 10
#define LCD_CS  19
#define LCD_RS  18

// ---constants---
const String ssıd = "ESP32";
const String password = "T@ytech123";
const uint8_t port = 80;

// ---Booleans---
extern bool wasManual;
extern bool isOn;
extern bool isError;
extern bool isControllingLcd;

// ---Keypad---
const uint8_t rowCount = 4;
const uint8_t colCount = 4;

extern byte rowPin[rowCount];
extern byte colPin[colCount];

extern String Mode;
extern String Btn;
extern String msg;
extern String target;

extern char pressed;
extern char buttons[rowCount][colCount];

//Func
void initializeLed();

#endif