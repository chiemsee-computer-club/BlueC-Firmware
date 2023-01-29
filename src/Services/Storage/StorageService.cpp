#include "StorageService.hpp"

bool StorageService::Initialize()
{
    return SetupSpiffs() && SetupSdCard();
}

bool StorageService::SetupSdCard()
{
    sdSpi->begin(SD_SCK, SD_MISO, SD_MOSI, SD_SS);
    if (!SD.begin(SD_CS, *sdSpi))
    {
        Serial.println("SD-Card mounting failed.");
        return false;
    }
    else
    {
        Serial.println("SD-Card mounted successfully.");
    }

    Serial.print("SD-Card Type: ");

    switch (SD.cardType())
    {
    case CARD_NONE:
        Serial.println("CARD_NONE");
        return false;
    case CARD_SD:
        Serial.println("CARD_SD");
        break;
    case CARD_MMC:
        Serial.println("CARD_MMC");
        break;
    case CARD_SDHC:
        Serial.println("CARD_SDHC");
        break;
    default:
        Serial.println("UNKNOWN");
        return false;
    }

    return true;
}

bool StorageService::SetupSpiffs()
{
    if (SPIFFS.begin(true))
    {  
        Serial.println("SPIFFS mounted successfully.");
        return true;
    }
    else
    {
        Serial.println("SPIFFS mounting failed.");
        return false;
    }
}