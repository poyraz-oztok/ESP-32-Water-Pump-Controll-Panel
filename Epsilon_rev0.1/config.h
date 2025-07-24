#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// ---Led Pins---
#define onLed 4 //------------------
#define errLed 0 //----------------

// ---Relay Pins---
#define relay0 12
#define relay1 21
#define relay2 //-----------------

// ---LCD Pins---

#define LCD_D0 34
#define LCD_D1 35
#define LCD_D2 32
#define LCD_D3 33
#define LCD_D4 25
#define LCD_D5 26
#define LCD_D6 27
#define LCD_D7 14

#define LCD_WR 22 
#define LCD_RD 23
#define LCD_RST 18
#define LCD_CS  5
#define LCD_RS  19

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