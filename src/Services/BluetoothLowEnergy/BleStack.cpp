#include "BleStack.hpp"
#include "Services/BleLoggingService.hpp"

BleStack::BleStack()
{
    if (!BLE.begin()) {
        Serial.println("Failed to initialize BLE!");
        return;
    }
    
    BLEAdvertisingData scanData;
    scanData.setLocalName("BlueC Device");

    BLE.setDeviceName("BlueC Device");
    BLE.setScanResponseData(scanData);

    BLE.setAppearance(0x0980);
    BLE.setEventHandler(BLEConnected, BleStack::BlePeripheralConnectHandler);
    BLE.setEventHandler(BLEDisconnected, BleStack::BlePeripheralDisconnectHandler);

    _initialized = true;
}

void BleStack::AddService(BleServiceBase* service)
{
    BLE.addService(*(service->GetService()));
    _bleAdvertisingData.setAdvertisedService(*(service->GetService()));
}

void BleStack::BlePeripheralConnectHandler(BLEDevice central)
{
    Serial.print("Connected event, central: ");
    Serial.println(central.address());
}

void BleStack::BlePeripheralDisconnectHandler(BLEDevice central)
{
    Serial.print("Disconnected event, central: ");
    Serial.println(central.address());
}

void BleStack::Advertise()
{
    _bleAdvertisingData.setManufacturerData(0x004C, manufactData, sizeof(manufactData));
    _bleAdvertisingData.setAdvertisedServiceData(0xfff0, serviceData, sizeof(serviceData));
    BLE.setAdvertisingData(_bleAdvertisingData);
    BLE.advertise();
}

void BleStack::Update()
{
    BLE.poll();
}
