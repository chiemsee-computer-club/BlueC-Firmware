#pragma once

#include <Arduino.h>
#include "Services/Display/DisplayService.hpp"
#include "Services/LoRa/LoRaService.hpp"
#include "Services/BluetoothLowEnergy/BleStack.hpp"
#include "Services/BluetoothLowEnergy/Services/BleLoggingService.hpp"
#include "Services/Logger/Logger.hpp"
#include "Services/Sqlite/SqliteService.hpp"
#include "Services/Storage/StorageService.hpp"


DisplayService* _displayService;
LoRaService* _loRaService;
BleStack* _bleStack;
BleLoggingService* _bleLoggingService;
StorageService* _storageService;
SqliteService* _sqliteService;
