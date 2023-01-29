#include "SerialLoggerBackend.hpp"

SerialLoggerBackend::SerialLoggerBackend()
{
    Serial.begin(115200);
}

void SerialLoggerBackend::WriteLine(String value)
{
    Serial.println(value);
}
