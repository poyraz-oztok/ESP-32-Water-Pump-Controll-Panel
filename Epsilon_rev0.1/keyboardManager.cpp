#include "keyboardManager.h"

Keypad keypad = Keypad(makeKeymap(buttons), rowPin, colPin, rowCount, colCount);

String getMeaning(char x){
    switch(x){
      case 'a':
        autoMan();
        Btn = Mode;
        break;
      case 'r':
        Btn = "Reset";
        break;
      case '1':
        Btn = "L1";
        break;
      case '2':
        Btn = "L1Stop";
        break;
      case '3':
        Btn = "L2";
        break;
      case '4':
        Btn = "L2Stop";
        break;
      case 'm':
        Btn = "Menu";
        break;
      case 'b':
        Btn = "Back";
        break;
      case 'k':
        Btn = "OK";
        break;
      case 'u':
        Btn = "Up";
        break;
      case 'd':
        Btn = "Down";
        break;
      case '5':
        Btn = "L3";
        break;
      case '6':
        Btn = "L3Stop";
        break;
      default:
        Btn = x;
    }
    return Btn;
}

void keyboardListen(){
  pressed = keypad.getKey();
    if (pressed){

      execute(whatsMsg());
    }; 
}