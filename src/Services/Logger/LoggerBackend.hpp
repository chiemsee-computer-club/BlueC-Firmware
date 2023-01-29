#pragma once

#include <Arduino.h>

class LoggerBackend
{
public:
    virtual void WriteLine(String value);
};