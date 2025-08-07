#include "config.h"

// ---Globals---
bool wasManual= true;
bool isOn= false;
bool isError= false;
bool isControllingLcd;
char pressed;

bool isSaved = false;
bool menu = false;
bool subMenu =false;
String Mode = "off";
String Btn;
String msg;
String target;

String pump1 = "Inactive";
String pump2 = "Inactive";
String pump3 = "Inactive";

String Menu[menuCount] = {"Language", "Pump 1 Settings", "Pump 2 Settings"
                         , "Pump 3 Settings", "Settings", "Service Settings"
                         , "Custom Settings", "PID Settings", "About"};
int selectedM = 0;

String lang[langCount]{"English", "Turkish", "German", "French","Danish", "Romanian"};
int selectedSubM = 0;

// ---Keypad----
byte rowPin[rowCount] = {LCD_D7, LCD_D6, LCD_D5, LCD_D4};
byte colPin[colCount] = {LCD_D3,LCD_D2 , LCD_D1, LCD_D0};

char buttons[rowCount][colCount] = {
  {' ','k','3','4'},
  {'m','b','5','6'},
  {' ','u','1','2'},
  {' ','d','a','r'}
  };


//Functions
void initializeLed(){
    pinMode(errLed, OUTPUT);
    pinMode(onLed, OUTPUT);
}