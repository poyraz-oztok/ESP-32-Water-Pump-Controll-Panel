#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include "config.h"
#include "commandHandler.h"

void error(String error, bool stopMotors);
void adderor(const char* errorMessage);

#endif