#pragma once

#include "stdlib.h"
#include "string"
#include <iostream>
#include <sstream>
#include <Adafruit_GFX.h>
#include "Adafruit_SSD1306.h"
#include "Wire.h"
#include "../../Config.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)

class DisplayService
{
public:
    DisplayService();
    void SplashScreen();

private:
	Adafruit_SSD1306* _display = new Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
};

// Parse image to arduino format: http://javl.github.io/image2cpp/

// 'logo-blue', 44x44px
const unsigned char LOGO44 [] PROGMEM = {
   0x00, 0x00, 0x7f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x3e, 0x7f, 0xff, 
	0x80, 0x00, 0x00, 0xfe, 0x7f, 0xff, 0xe0, 0x00, 0x01, 0xfe, 0x7f, 0xff, 0xf0, 0x00, 0x03, 0xff, 
	0x7f, 0xff, 0xf8, 0x00, 0x07, 0xff, 0x3f, 0xff, 0xfc, 0x00, 0x0f, 0xff, 0x3f, 0xff, 0xfe, 0x00, 
	0x1f, 0xff, 0xbf, 0xff, 0xff, 0x00, 0x1f, 0xff, 0x9f, 0xff, 0xff, 0x80, 0x3f, 0xff, 0x9f, 0xff, 
	0xff, 0x80, 0x7f, 0xff, 0x9f, 0xff, 0xff, 0xc0, 0x7f, 0xff, 0xdf, 0xff, 0xff, 0xc0, 0x7f, 0xff, 
	0xcf, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xf0, 
	0xff, 0xff, 0xef, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xe7, 0xff, 
	0xff, 0xf0, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xc7, 0xff, 0xff, 0xf0, 0xff, 0xff, 
	0x07, 0xff, 0xff, 0xf0, 0xff, 0xf0, 0x3f, 0xff, 0xff, 0xf0, 0xff, 0x01, 0xff, 0xff, 0xff, 0xf0, 
	0x70, 0x1f, 0xff, 0xff, 0xff, 0xf0, 0x01, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xff, 
	0xff, 0xf0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x3f, 0xff, 
	0xff, 0xff, 0xff, 0xf0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf0, 
	0x1f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xff, 
	0xff, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x03, 0xff, 
	0xff, 0xff, 0xff, 0xf0, 0x01, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xf0, 
	0x00, 0x3f, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x03, 0xff, 0xff, 
	0xff, 0xf0, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xf0
};

// 'logo-blue', 32x32px
const unsigned char LOGO32 [] PROGMEM = {
    0x00, 0x0f, 0xfc, 0x00, 0x00, 0xef, 0xff, 0x00, 0x03, 0xef, 0xff, 0xc0, 0x07, 0xef, 0xff, 0xe0, 
	0x0f, 0xf7, 0xff, 0xf0, 0x1f, 0xf7, 0xff, 0xf8, 0x3f, 0xf7, 0xff, 0xfc, 0x7f, 0xf7, 0xff, 0xfc, 
	0x7f, 0xfb, 0xff, 0xfe, 0xff, 0xfb, 0xff, 0xfe, 0xff, 0xfb, 0xff, 0xfe, 0xff, 0xfd, 0xff, 0xff, 
	0xff, 0xfd, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xf1, 0xff, 0xff, 
	0xff, 0x8f, 0xff, 0xff, 0xf8, 0x7f, 0xff, 0xff, 0x07, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 
	0x7f, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 
	0x3f, 0xff, 0xff, 0xff, 0x1f, 0xff, 0xff, 0xff, 0x0f, 0xff, 0xff, 0xff, 0x07, 0xff, 0xff, 0xff, 
	0x03, 0xff, 0xff, 0xff, 0x01, 0xff, 0xff, 0xff, 0x00, 0x7f, 0xff, 0xff, 0x00, 0x1f, 0xff, 0xff
};
