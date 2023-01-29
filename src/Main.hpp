#pragma once

#include <Arduino.h>
#include "Services/Display/DisplayService.hpp"
#include "Services/LoRa/LoRaService.hpp"
#include "Services/BluetoothLowEnergy/BluetoothLowEnergy.hpp"
#include "Services/BluetoothLowEnergy/Services/BleLoggingService.hpp"
#include "Services/Logger/Logger.hpp"
#include "Services/Sqlite/SqliteService.hpp"
#include "Services/Storage/StorageService.hpp"


DisplayService *_displayService;
LoRaService *_loRaService;
BluetoothLowEnergy *_bluetoothLowEnergy;
BleLoggingService* _bleLoggingService;
StorageService *_storageService;
SqliteService *_sqliteService;