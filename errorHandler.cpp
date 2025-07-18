#include "errorHandler.h"

void error(String error, bool stopMotors){
    digitalWrite(errLed, HIGH);
    
    if(stopMotors){
      command("L1stop");
      command("L2stop");
      command("L3stop");
    }

    Serial.println("Error Occured: " + error);

    //Add func to write the error to the web interface.

    isError = true;
  };