#include "commandHandler.h"
#include "errorHandler.h"
#include "lcdManager.h"

String whatsMsg(){
    if(pressed){
      msg = getMeaning(pressed);
    }
    else{
      msg = target;
    }
    return msg;
  }

void autoMan(){
    if (isOn && wasManual) {
          Mode = "off";
          isOn = false;
          digitalWrite(onLed, LOW);
        }

        else if (isOn && !wasManual) {
          Mode = "Manual";
          wasManual = true;
          digitalWrite(onLed, HIGH);
        }
        
        else if (!isOn) {
          Mode = "Auto";
          isOn = true;
          wasManual = false;
          digitalWrite(onLed, HIGH);
        }
  }

  void execute(String z){
    if (z == "L1" && !isError) {
      Serial.println("L1 Started Running");
      printLCD(5, 16, "Pump 1 Running");
      pump1 = "Running";
    } 
    else if (z == "L2" && !isError) {
      Serial.println("L2 Started Running");
      pump2 = "Running";
    } 
    else if (z == "L3" && !isError) {
      Serial.println("L3 Started Running");
      pump3 = "Running";
    }

    else if (z == "L1" && isError) {
      Serial.println("Cant run the Pump due to the error ocured");
      pump1 = "Err";
    } 
    else if (z == "L2" && isError) {
      Serial.println("Cant run the Pump due to the error ocured");
      pump2 = "Err";
    } 
    else if (z == "L3" && isError) {
      Serial.println("Cant run the Pump due to the error ocured");
      pump3 = "Err";
    }

    else if (z == "L1Stop") {
      Serial.println("L1 Stopped Running.");
      pump1 = "Inactive";
    }

    else if (z == "L2Stop") {
      Serial.println("L2 Stopped Running.");
      pump2 = "Inactive";
    }

    else if (z == "L3Stop") {
      Serial.println("L3 Stopped Running.");
      pump3 = "Inactive";
    }

    else if (z == "reset"){
      Serial.println("Resetted");
      clrLCD();
      
    }
    
    else if (z == "menu"){
      Serial.println("Menu Oppend");
      menu = true;

    }

    else if (z == "back"){
      Serial.println("Got Back");
      if (menu){
        menu = false;
        selectedM = 0;
      }
      if (subMenu){
        subMenu = false;
        menu = true;
        selectedM = 0;
      }
    }

    else if (z == "down"){
      Serial.println("Got Down");
      if (menu & selectedM <= menuCount-2){
        selectedM++;
      }
      else if (subMenu & selectedSubM< langCount-1){
        selectedSubM++;
      }
    }

    else if (z == "up"){
      Serial.println("Got Up");
      if (menu & selectedM > 0){
        selectedM--;
      }
      else if (subMenu & selectedSubM > 0){
        selectedSubM--;
      }
    }

    else if (z == "ok"){
      Serial.println("Saved");
      
      if (menu){
        subMenu= true;
        menu = false;

      }
    }

    else if (z == "automan"){
      initializeLCD();
      clrLCD();
      autoMan();
      Serial.println("Mode: "+ Mode);
    }

    else{
      error("Unknown command: " + z, false);
    }

    Serial.println("CMD: " + z);
    updateLCD();
  }