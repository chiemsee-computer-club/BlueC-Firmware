#pragma once

#include <ArduinoBLE.h>
#include <Arduino.h>
#include "BleServiceBase.hpp"

class BleStack
{
private:
    const uint8_t manufactData[4] = { 0x01, 0x02, 0x03, 0x04 };
    const uint8_t serviceData[3] = { 0x00, 0x01, 0x02 };
    bool _initialized = false;
    BLEAdvertisingData _bleAdvertisingData;

    static void BlePeripheralConnectHandler(BLEDevice central);
    static void BlePeripheralDisconnectHandler(BLEDevice central);
public:
    BleStack();
    void AddService(BleServiceBase* service);
    void Advertise();
    void Update();
};