#include "Main.hpp"


void setup()
{
    Serial.begin(115200);
    Serial.print("Databse name");

    _displayService = new DisplayService();
    _loRaService = new LoRaService();
    _storageService = new StorageService();
    _sqliteService = new SqliteService();

    _displayService->SplashScreen();
    _storageService->Initialize();
    _sqliteService->Initialize();
    _loRaService->Initialize();
}

void loop()
{
    _loRaService->CheckForNewMessages();
}
