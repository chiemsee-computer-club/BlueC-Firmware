#include "Main.hpp"


void setup()
{
    Serial.begin(115200);

    _displayService = new DisplayService();
    _storageService = new StorageService();
    _sqliteService = new SqliteService();
    _loRaService = new LoRaService(_sqliteService);
    
    _displayService->SplashScreen();
    _storageService->Initialize();
    _sqliteService->Initialize();
    _loRaService->Initialize();
}

void loop()
{
    _loRaService->CheckForNewMessages();
}
