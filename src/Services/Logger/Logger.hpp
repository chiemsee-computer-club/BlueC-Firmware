#pragma once

#include <Arduino.h>
#include <list>
#include "LoggerBackend.hpp"

class Logger
{
private:
    static std::list<LoggerBackend*> _backends;

public:
    static void AddBackend(LoggerBackend* backend);
    static void Debug(String value);
};