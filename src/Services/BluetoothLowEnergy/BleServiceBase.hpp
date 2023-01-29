#pragma once

#include <ArduinoBLE.h>

class BleServiceBase
{
public:
    virtual BLEService* GetService();
};