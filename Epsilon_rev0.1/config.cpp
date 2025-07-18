#include "config.h"

// ---Globals---
bool wasManual= true;
bool isOn= false;
bool isError= false;
bool isControllingLcd;
char pressed;

String Mode;
String Btn;
String msg;
String target;

// ---Keypad----
byte rowPin[rowCount] = {0, 1, 2, 3};
byte colPin[colCount] = {4, 5, 6, 7};

char buttons[rowCount][colCount] = {
    {'r','2','6','4'},
    {'a','1','5','3'},
    {'d','u','b','k'},
    {' ',' ','m',' '} 
  };


//Functions
void initializeLed(){
    pinMode(errLed, OUTPUT);
    pinMode(onLed, OUTPUT);
}