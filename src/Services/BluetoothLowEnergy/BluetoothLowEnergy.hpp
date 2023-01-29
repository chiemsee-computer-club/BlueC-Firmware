#pragma once

#include <ArduinoBLE.h>
#include <Arduino.h>
#include "BleServiceBase.hpp"

class BluetoothLowEnergy
{
private:
    static constexpr const char* characteristicUuid = "012CF118-0915-432C-A69A-59979E61B81A";
    const uint8_t manufactData[4] = { 0x01, 0x02, 0x03, 0x04 };
    const uint8_t serviceData[3] = { 0x00, 0x01, 0x02 };
    bool _initialized = false;
    BLEAdvertisingData _bleAdvertisingData;

    static void BlePeripheralConnectHandler(BLEDevice central);
    static void BlePeripheralDisconnectHandler(BLEDevice central);
public:
    BluetoothLowEnergy();
    void AddService(BleServiceBase* service);
    void Advertise();
    void Update();
};