//2X2 ROUND DISPLAY WITH ESP32 - DEMO DISPLAY EXAMPLE 
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_GC9A01A.h>
#include <SPI.h>

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


//create instance for SPI Display 
Adafruit_GC9A01A tft1(TFT1_CS, TFT1_DC, TFT1_MOSI, TFT1_SCLK, TFT1_RST);
Adafruit_GC9A01A tft2(TFT2_CS, TFT2_DC, TFT2_MOSI, TFT2_SCLK, TFT2_RST);
Adafruit_GC9A01A tft3(TFT3_CS, TFT3_DC, TFT3_MOSI, TFT3_SCLK, TFT3_RST);
Adafruit_GC9A01A tft4(TFT4_CS, TFT4_DC, TFT4_MOSI, TFT4_SCLK, TFT4_RST);

float p = 3.1415926;

void setup(void) {
  Serial.begin(115200);
  Serial.println(F("Hello! Display Test"));
  pinMode(BACKLIGHT, OUTPUT);
  digitalWrite(BACKLIGHT, HIGH);

  // initialize display
  tft1.begin();
  tft2.begin();
  tft3.begin();
  tft4.begin();

  tft1.fillScreen(GC9A01A_BLACK);
  tft2.fillScreen(GC9A01A_BLACK);
  tft3.fillScreen(GC9A01A_BLACK);
  tft4.fillScreen(GC9A01A_BLACK);
  Serial.println(F("Initialized"));
  
  testtriangles();
  testdrawcircles(10, GC9A01A_GREEN);
  testdrawrects(GC9A01A_RED);
  testroundrects();
}

void loop() {
  Serial.println("Inside Loop");
  digitalWrite(BACKLIGHT, LOW);
  delay(500);
  digitalWrite(BACKLIGHT, HIGH);
  delay(500);
}

void testdrawtext(char *text, uint16_t color) {
  tft.setCursor(0, 0);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(text);
}

void testroundrects() {
  tft4.fillScreen(GC9A01A_BLACK);
  uint16_t color = 100;
  int i;
  int t;
  for(t = 0 ; t <= 4; t+=1) {
    int x = 0;
    int y = 0;
    int w = tft4.width()-2;
    int h = tft4.height()-2;
    for(i = 0 ; i <= 16; i+=1) {
      tft4.drawRoundRect(x, y, w, h, 5, color);
      x+=2;
      y+=3;
      w-=4;
      h-=6;
      color+=1100;
    }
    color+=100;
  }
}

void testtriangles() {
  tft3.fillScreen(GC9A01A_BLACK);
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

void testdrawcircles(uint8_t radius, uint16_t color) {
  tft2.fillScreen(GC9A01A_BLACK);
  for (int16_t x=0; x < tft2.width()+radius; x+=radius*2) {
    for (int16_t y=0; y < tft2.height()+radius; y+=radius*2) {
      tft2.drawCircle(x, y, radius, color);
    }
  }
}

void testdrawrects(uint16_t color) {
  tft1.fillScreen(GC9A01A_BLACK);
  for (int16_t x=0; x < tft1.width(); x+=6) {
    tft1.drawRect(tft1.width()/2 -x/2, tft1.height()/2 -x/2 , x, x, color);
  }
}
