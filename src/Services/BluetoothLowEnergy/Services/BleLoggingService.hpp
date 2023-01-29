#pragma once

#include <ArduinoBLE.h>
#include <Arduino.h>
#include "../BleServiceBase.hpp"
#include "../../Logger/LoggerBackend.hpp"

static const char* ServiceUuid = "715F6B95-FB3C-4C40-8288-4FBA89C7F979";
static const char* CharacteristicUuid = "012CF118-0915-432C-A69A-59979E61B81A";

class BleLoggingService : public BleServiceBase, public LoggerBackend
{
private:
    BLEService* _service;
    BLEStringCharacteristic* _characteristic;

public:
    BleLoggingService();
    ~BleLoggingService();

    void WriteLine(String value) override;
    BLEService* GetService() override;
};