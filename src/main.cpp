#include <Arduino.h>

#include <TFT_eSPI.h>
#include <Wire.h>
#include "TCA9555.h"
#include "returnMain.h"

TFT_eSPI tft = TFT_eSPI();
TCA9555 TCA(0x20);

/*
 * This is an Example code of External Application boot form OTA partition via SD Card
 * Compile this code and upload it to the sd card (firmware.bin)
 * And Enjoy the External Application
 * Press Menu button to return to the main firmware
 */

void setup()
{
    pinMode(3, OUTPUT);
    digitalWrite(3, HIGH);

    tft.begin();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);

    tft.setTextSize(2);

    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.drawString("This is an external", 10, 10);

    tft.setCursor(10, 30);
    tft.print("Press Menu button to exit");
}
void loop()
{
    if (!((TCA.read16() >> 5) & 0x01))
    {
        Serial.println("_Menu");
        return_to_main_firmware();
    }
}