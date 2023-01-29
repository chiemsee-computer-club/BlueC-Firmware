#pragma once

#include "LoggerBackend.hpp"

class SerialLoggerBackend : public LoggerBackend
{
public:
    SerialLoggerBackend();
    void WriteLine(String value) override;
};
