#include "lcdManager.h"
#include "logo.h"

U8G2_ST7565_LM6063_F_8080 lcd(
    U8G2_R0,
    LCD_D0, LCD_D1, LCD_D2, LCD_D3,
    LCD_D4, LCD_D5, LCD_D6, LCD_D7,
    LCD_WR,
    LCD_CS,
    LCD_RS,
    LCD_RST
);

void initializeLCD(){
    isControllingLcd = true;
    for (int i =0; i <= 7; i++){
        pinMode(i, OUTPUT);
    }
    pinMode(8, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(19, OUTPUT);
    pinMode(18, OUTPUT);
};

void setUpLCD(){
    initializeLCD();
    lcd.begin();
    lcd.clearBuffer();
    lcd.setFont(u8g2_font_6x10_tr);
};

void clrLCD(){
    lcd.clearBuffer();
};

void showLogo(){
    clrLCD();
    lcd.drawXBMP(0, 0, 128, 64, logo);
    lcd.sendBuffer();
};

void startUpScheneLCD(){
    pritnLCD(20, 30, "- by poyrazoztok");
    delay(2000);
    clrLCD();
    showLogo();
};

void pritnLCD(uint8_t x, uint8_t y, String message){
    clrLCD();
    lcd.drawStr(x, y, message.c_str());
    lcd.sendBuffer();
};