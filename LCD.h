// LCD.h

#ifndef _LCD_h
#define _LCD_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"

void print(int x);
void print(const char *characters);
void println(const char *characters);
void drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername);
void setTextSize(uint8_t x);
void setCursor(uint8_t x, uint8_t y);
void fillRect(int16_t x, int16_t y, int16_t w, int16_t h);
void fillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r);
void drawRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r);
void drawRect(int16_t x, int16_t y, int16_t w, int16_t h);
void drawFastHLine(int16_t x, int16_t y, int16_t w);
void fillCircle(int16_t x0, int16_t y0, int16_t r);
void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta);
void drawFastVLine(int16_t x, int16_t y, int16_t h);
void drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername);
void drawCircle(int16_t x0, int16_t y0, int16_t r);
void setBackColor(uint8_t red, uint8_t green, uint8_t blue);
void fillScreen(void);
void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1);
void rotate(byte _rotation);
void println(char *characters);
void print(char *characters);
void character(char character);
void drawFontPixel(uint8_t x, uint8_t y, uint8_t red, uint8_t green, uint8_t blue, uint8_t pixelSize);
void setColor(uint8_t red, uint8_t green, uint8_t blue);
void setAddrWindow(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);
void drawPixel(int16_t x, int16_t y);
void drawPixel(int16_t x, int16_t y, uint8_t red, uint8_t green, uint8_t blue);
void init_LCD(void);
void data(byte payload);
void cmd(byte payload);
void write(byte payload, byte dc);

#else
	#include "WProgram.h"
#endif


#endif

