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
byte rowPin[rowCount] = {33, 32, 35, 34};
byte colPin[colCount] = {14, 27, 26, 25};

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