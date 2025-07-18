#include "commandHandler.h"
#include "errorHandler.h"

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
    } 
    else if (z == "L2" && !isError) {
      Serial.println("L2 Started Running");
    } 
    else if (z == "L3" && !isError) {
      Serial.println("L3 Started Running");
    }

    else if (z == "L1" && isError) {
      Serial.println("Cant run the Pump due to the error ocured");
    } 
    else if (z == "L2" && isError) {
      Serial.println("Cant run the Pump due to the error ocured");
    } 
    else if (z == "L3" && isError) {
      Serial.println("Cant run the Pump due to the error ocured");
    }

    else if (z == "L1stop") {
      Serial.println("L1 Stopped Running.");
    }

    else if (z == "L2stop") {
      Serial.println("L2 Stopped Running.");
    }

    else if (z == "L3stop") {
      Serial.println("L3 Stopped Running.");
    }

    else if (z == "reset"){
      Serial.println("Resetted");
    }
    
    else if (z == "menu"){
      Serial.println("Menu Oppend");
    }

    else if (z == "back"){
      Serial.println("Got Back");
    }

    else if (z == "up"){
      Serial.println("Got Up");
    }

    else if (z == "down"){
      Serial.println("Got Down");
    }

    else if (z == "ok"){
      Serial.println("Saved");
    }

    else{
      error("Unknown command" + z, false);
    }

    Serial.println("CMD: " + z);
  }