//2X2 DISPLAY WITH ESP32 - DEMO DISPLAY EXAMPLE 
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

//Define and configure Display SPI interface
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

float p = 3.1415926;

void setup(void) {
  Serial.begin(9600);
  Serial.print(F("Hello! 2x2 Display DEMO"));
  pinMode(BACKLIGHT, OUTPUT);
  digitalWrite(BACKLIGHT, HIGH);

  // use this initializer (uncomment) if using a 1.3" or 1.54" 240x240 TFT:
  tft1.init(240, 240);           // Init ST7789 240x240
  tft2.init(240, 240);           // Init ST7789 240x240
  tft3.init(240, 240);           // Init ST7789 240x240
  tft4.init(240, 240);           // Init ST7789 240x240
  Serial.println(F("Display Initialized"));

  tft1.fillScreen(ST77XX_BLACK);
  tft2.fillScreen(ST77XX_BLACK);
  tft3.fillScreen(ST77XX_BLACK);
  tft4.fillScreen(ST77XX_BLACK);
  delay(100);

  testdrawrects(ST77XX_YELLOW);
  testdrawcircles(10, ST77XX_GREEN);
  testtriangles();
  testfastlines(ST77XX_RED,ST77XX_BLUE);
    
  Serial.println("Done!");
  delay(1000);
}

void loop() {
  tft1.invertDisplay(true);
  tft2.invertDisplay(false);
  tft3.invertDisplay(true);
  tft4.invertDisplay(false);
  delay(500);
  tft1.invertDisplay(false);
  tft2.invertDisplay(true);
  tft3.invertDisplay(false);
  tft4.invertDisplay(true);
  delay(500);
}

void testdrawrects(uint16_t color) {
  tft1.fillScreen(ST77XX_BLACK);
  for (int16_t x=0; x < tft1.width(); x+=6) {
    tft1.drawRect(tft1.width()/2 -x/2, tft1.height()/2 -x/2 , x, x, color);
  }
}

void testdrawcircles(uint8_t radius, uint16_t color) {
  tft2.fillScreen(ST77XX_BLACK);
  for (int16_t x=0; x < tft2.width()+radius; x+=radius*2) {
    for (int16_t y=0; y < tft2.height()+radius; y+=radius*2) {
      tft2.drawCircle(x, y, radius, color);
    }
  }
}


void testtriangles() {
  tft3.fillScreen(ST77XX_BLACK);
  uint16_t color = 0xF800;
  int t;
  int w = tft3.width()/2;
  int x = tft3.height()-1;
  int y = 0;
  int z = tft3.width();
  for(t = 0 ; t <= 15; t++) {
    tft3.drawTriangle(w, y, y, x, z, x, color);
    x-=4;
    y+=4;
    z-=4;
    color+=100;
  }
}

void testfastlines(uint16_t color1, uint16_t color2) {
  tft4.fillScreen(ST77XX_BLACK);
  for (int16_t y=0; y < tft4.height(); y+=5) {
    tft4.drawFastHLine(0, y, tft4.width(), color1);
  }
  for (int16_t x=0; x < tft4.width(); x+=5) {
    tft4.drawFastVLine(x, 0, tft4.height(), color2);
  }
}
