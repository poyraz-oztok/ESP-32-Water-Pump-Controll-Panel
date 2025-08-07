#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// ---Led Pins---
#define onLed 4 //------------------
#define errLed 0 //----------------

// ---LCD Pins---

#define LCD_D0 0
#define LCD_D1 1
#define LCD_D2 2
#define LCD_D3 3
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7

#define LCD_WR 9
#define LCD_RST 19
#define LCD_CS  18
#define LCD_RS  8


// ---constants---
const String ssıd = "ESP32";
const String password = "T@ytech123";
const uint8_t port = 80;

// ---Booleans---
extern bool wasManual;
extern bool isOn;
extern bool isError;
extern bool isControllingLcd;
extern bool isSaved;
extern bool menu;

// ---Keypad---
const uint8_t rowCount = 4;
const uint8_t colCount = 4;

extern byte rowPin[rowCount];
extern byte colPin[colCount];

extern String Mode;
extern String Btn;
extern String msg;
extern String target;

extern int selectedM;
extern bool subMenu;

extern String pump1;
extern String pump2;
extern String pump3;

extern char pressed;
extern char buttons[rowCount][colCount];

int const menuCount = 9;
extern String Menu[menuCount];

int const langCount = 6;
extern String lang[langCount];
extern int selectedSubM;

//Func
void initializeLed();

#endif