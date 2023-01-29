#include "BleLoggingService.hpp"

BleLoggingService::BleLoggingService()
{
    _service = new BLEService(ServiceUuid);
    _characteristic = new BLEStringCharacteristic(CharacteristicUuid, BLERead | BLENotify, 512);
    _service->addCharacteristic(*_characteristic);
    _characteristic->writeValue(""); // initial value
}

BleLoggingService::~BleLoggingService()
{
    delete _service;
    delete _characteristic;
}

void BleLoggingService::WriteLine(String value)
{
    _characteristic->writeValue(value);
}

BLEService* BleLoggingService::GetService()
{
    return _service;
}