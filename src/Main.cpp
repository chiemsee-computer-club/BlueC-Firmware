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
    _loRaService = new LoRaService();

    _bluetoothLowEnergy->AddService(_bleLoggingService);
    _bluetoothLowEnergy->Advertise();
    Logger::Debug("BLE initialized");

    _displayService->SplashScreen();
    Logger::Debug("SplashScreen initialized");
    
    _loRaService->Initialize();
    Logger::Debug("LoRa initialized");

    _bluetoothLowEnergy->Advertise();
}

void loop()
{   
    _loRaService->CheckForNewMessages();
    _bluetoothLowEnergy->Update();
}