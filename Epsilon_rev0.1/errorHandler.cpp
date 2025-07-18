#include "errorHandler.h"

void error(String error, bool stopMotors){
    digitalWrite(errLed, HIGH);
    
    if(stopMotors){
      execute("L1stop");
      execute("L2stop");
      execute("L3stop");
    }

    Serial.println("Error Occured: " + error);

    //Add func to write the error to the web interface.

    isError = true;
  };