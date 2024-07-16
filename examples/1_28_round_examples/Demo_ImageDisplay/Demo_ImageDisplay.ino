#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include "imagedata.h"

//LCD1
#define TFT1_CS         9
#define TFT1_MOSI       11
#define TFT1_SCLK       12
#define TFT1_RST        -1
#define TFT1_DC         13

//LCD2
#define TFT2_CS         21
#define TFT2_MOSI       6
#define TFT2_SCLK       15
#define TFT2_RST        -1
#define TFT2_DC         7


//LCD3
#define TFT3_CS         48
#define TFT3_MOSI       8
#define TFT3_SCLK       14
#define TFT3_RST        -1
#define TFT3_DC         47


//LCD4
#define TFT4_CS         10
#define TFT4_MOSI       16
#define TFT4_SCLK       18
#define TFT4_RST        -1
#define TFT4_DC         17

#define BACKLIGHT      45 // common backlight for all display

// OR for the ST7789-based displays, we will use this call
Adafruit_ST7789 tft1 = Adafruit_ST7789(TFT1_CS, TFT1_DC, TFT1_MOSI, TFT1_SCLK, TFT1_RST);
Adafruit_ST7789 tft2 = Adafruit_ST7789(TFT2_CS, TFT2_DC, TFT2_MOSI, TFT2_SCLK, TFT2_RST);
Adafruit_ST7789 tft3 = Adafruit_ST7789(TFT3_CS, TFT3_DC, TFT3_MOSI, TFT3_SCLK, TFT3_RST);
Adafruit_ST7789 tft4 = Adafruit_ST7789(TFT4_CS, TFT4_DC, TFT4_MOSI, TFT4_SCLK, TFT4_RST);

void setup() {
  pinMode(BACKLIGHT, OUTPUT);
  digitalWrite(BACKLIGHT, HIGH);
  // use this initializer (uncomment) if using a 1.3" or 1.54" 240x240 TFT:
  tft1.init(240, 240);           // Init ST7789 240x240
  tft2.init(240, 240);           // Init ST7789 240x240
  tft3.init(240, 240);           // Init ST7789 240x240
  tft4.init(240, 240);           // Init ST7789 240x240
  
  tft1.setRotation(3);
  tft2.setRotation(3);
  tft3.setRotation(3);
  tft4.setRotation(3);
  
  tft1.fillScreen(ST77XX_BLACK);
  tft2.fillScreen(ST77XX_BLACK);
  tft3.fillScreen(ST77XX_BLACK);
  tft4.fillScreen(ST77XX_BLACK);
  
  // Display the image
  for (int16_t y=0; y<240; y++) {
    for (int16_t x=0; x<240; x++) {
      tft1.drawPixel(x, y, logo_img[y][x]);
      tft2.drawPixel(x, y, logo_img[y][x]);
      tft3.drawPixel(x, y, logo_img[y][x]);
      tft4.drawPixel(x, y, logo_img[y][x]);
    }
  }

}

void loop() {
  // Do nothing here
}
