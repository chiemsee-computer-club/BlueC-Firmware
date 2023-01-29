#pragma once

#include <Arduino.h>
#include "Services/Display/DisplayService.hpp"
#include "Services/LoRa/LoRaService.hpp"
#include "Services/Sqlite/SqliteService.hpp"
#include "Services/Storage/StorageService.hpp"


DisplayService *_displayService;
LoRaService *_loRaService;
StorageService *_storageService;
SqliteService *_sqliteService;