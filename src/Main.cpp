#include "Main.hpp"
#include "Services/Logger/SerialLoggerBackend.hpp"

int counter = 0;

void setup()
{
    Logger::AddBackend(new SerialLoggerBackend());

    _displayService = new DisplayService();

    _displayService->SplashScreen();
    Logger::Debug("Drawing SplashScreen");

    _bleStack = new BleStack();
    _bleLoggingService = new BleLoggingService();

    Logger::AddBackend(_bleLoggingService);
    
    _storageService = new StorageService();
    _sqliteService = new SqliteService();
    _loRaService = new LoRaService(_sqliteService);


    _storageService->Initialize();
    Logger::Debug("StorageService initialized");

    _sqliteService->Initialize();
    Logger::Debug("SQLite initialized");

    _loRaService->Initialize();
    Logger::Debug("LoRa initialized");

    _bleStack->Advertise();

    _displayService->HomeScreen();
    Logger::Debug("Drawing HomeScreen");
}

void loop()
{   
    _loRaService->CheckForNewMessages();
    _bleStack->Update();
}