#include "Main.hpp"
#include "Services/Logger/SerialLoggerBackend.hpp"

int counter = 0;

void setup()
{
    Logger::AddBackend(new SerialLoggerBackend());

    _bluetoothLowEnergy = new BluetoothLowEnergy();
    _bleLoggingService = new BleLoggingService();

    Logger::AddBackend(_bleLoggingService);

    _displayService = new DisplayService();
    _storageService = new StorageService();
    _sqliteService = new SqliteService();
    _loRaService = new LoRaService(_sqliteService);

    _displayService->SplashScreen();
    _storageService->Initialize();
    _sqliteService->Initialize();
    _loRaService->Initialize();
    Logger::Debug("LoRa initialized");

    _bluetoothLowEnergy->Advertise();
}

void loop()
{   
    _loRaService->CheckForNewMessages();
    _bluetoothLowEnergy->Update();
}