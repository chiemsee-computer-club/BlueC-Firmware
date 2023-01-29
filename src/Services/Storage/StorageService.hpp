#pragma once

#include <SPI.h>
#include <SPIFFS.h>
#include <SD.h>

#define SD_CS 13
#define SD_SCK 14
#define SD_MISO 2
#define SD_MOSI 15
#define SD_SS 13

class StorageService {
    public:
        bool Initialize();

    private:
        SPIClass * sdSpi = new SPIClass(HSPI);

        bool SetupSdCard();
        bool SetupSpiffs();
};