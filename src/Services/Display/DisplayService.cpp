#include "DisplayService.hpp"

DisplayService::DisplayService()
{
    if (!_display->begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("Cannot connect to display");
        return;
    }

    delay(250);

    _display->clearDisplay();
    _display->setTextSize(1);
    _display->setTextColor(WHITE);
    _display->display();
}

void DisplayService::SplashScreen() {
    _display->clearDisplay();

    _display->drawBitmap(5, 5, LOGO32, 32, 32, WHITE);

    _display->setCursor(47, 15);
    _display->println(OSName);

    _display->setCursor(47, 25);
    _display->println(Version);

    _display->setCursor(20, 50);
    _display->println("Initializing...");

    _display->display();
}

void DisplayService::HomeScreen() {
    _display->clearDisplay();

    _display->drawBitmap(5, 5, LOGO32, 32, 32, WHITE);

    _display->setCursor(47, 15);
    _display->println(OSName);

    _display->setCursor(47, 25);
    _display->println(Version);

    _display->setCursor(50, 50);
    _display->println("Ready");

    _display->display();
}