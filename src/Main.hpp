#pragma once

#include <Arduino.h>
#include "Services/Display/DisplayService.hpp"
#include "Services/LoRa/LoRaService.hpp"
#include "Services/BluetoothLowEnergy/BluetoothLowEnergy.hpp"
#include "Services/BluetoothLowEnergy/Services/BleLoggingService.hpp"
#include "Services/Logger/Logger.hpp"


DisplayService *_displayService;
LoRaService *_loRaService;
BluetoothLowEnergy *_bluetoothLowEnergy;

BleLoggingService* _bleLoggingService;