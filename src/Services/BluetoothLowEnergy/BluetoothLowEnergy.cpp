#include "BluetoothLowEnergy.hpp"
#include "Services/BleLoggingService.hpp"

BluetoothLowEnergy::BluetoothLowEnergy()
{
    if (!BLE.begin()) {
        Serial.println("Failed to initialize BLE!");
        return;
    }
    
    BLEAdvertisingData scanData;
    scanData.setLocalName("BlueC Device");

    BLE.setDeviceName("BlueC Device");
    BLE.setScanResponseData(scanData);

    BLE.setEventHandler(BLEConnected, BluetoothLowEnergy::BlePeripheralConnectHandler);
    BLE.setEventHandler(BLEDisconnected, BluetoothLowEnergy::BlePeripheralDisconnectHandler);

    _initialized = true;
}

void BluetoothLowEnergy::AddService(BleServiceBase* service)
{
    BLE.addService(*(service->GetService()));
    _bleAdvertisingData.setAdvertisedService(*(service->GetService()));
}

void BluetoothLowEnergy::BlePeripheralConnectHandler(BLEDevice central)
{
    Serial.print("Connected event, central: ");
    Serial.println(central.address());
}

void BluetoothLowEnergy::BlePeripheralDisconnectHandler(BLEDevice central)
{
    Serial.print("Disconnected event, central: ");
    Serial.println(central.address());
}

void BluetoothLowEnergy::Advertise()
{
    _bleAdvertisingData.setManufacturerData(0x004C, manufactData, sizeof(manufactData));
    _bleAdvertisingData.setAdvertisedServiceData(0xfff0, serviceData, sizeof(serviceData));
    BLE.setAdvertisingData(_bleAdvertisingData);
    BLE.advertise();
}

void BluetoothLowEnergy::Update()
{
    BLE.poll();
}
