#include "keyboardManager.h"

Keypad keypad = Keypad(makeKeymap(buttons), rowPin, colPin, rowCount, colCount);

String getMeaning(char x){
    switch(x){
      case 'a':
        Btn = "automan";
        break;
      case 'r':
        Btn = "reset";
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
        Btn = "menu";
        break;
      case 'b':
        Btn = "back";
        break;
      case 'k':
        Btn = "ok";
        break;
      case 'u':
        Btn = "up";
        break;
      case 'd':
        Btn = "down";
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