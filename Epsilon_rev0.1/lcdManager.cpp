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
    pinMode(LCD_D0, OUTPUT);
    pinMode(LCD_D1, OUTPUT);
    pinMode(LCD_D2, OUTPUT);
    pinMode(LCD_D3, OUTPUT);
    pinMode(LCD_D4, OUTPUT);
    pinMode(LCD_D5, OUTPUT);
    pinMode(LCD_D6, OUTPUT);
    pinMode(LCD_D7, OUTPUT);
    pinMode(LCD_WR, OUTPUT);
    pinMode(LCD_RS, OUTPUT);
    pinMode(LCD_RST, OUTPUT);
    pinMode(LCD_CS, OUTPUT);
};

void setUpLCD(){
    initializeLCD();
    lcd.begin();
    lcd.clearBuffer();
    lcd.setFont(u8g2_font_6x10_tr);
};

void clrLCD(){
    initializeLCD();
    lcd.clearBuffer();
    printLCD(1, 1, " ");
};

void showLogo(){
    clrLCD();
    lcd.drawXBMP(0, 0, 128, 64, logo);
    lcd.sendBuffer();
};

void startUpScheneLCD(){
    printLCD(20, 30, "- by poyrazoztok");
    delay(1500);
    showLogo();
    delay(2000);
};

void printLCD(uint8_t x, uint8_t y, String message){
    initializeLCD();
    lcd.drawStr(x, y, message.c_str());
    lcd.sendBuffer();
};

void showDefault(){
    clrLCD();
    printLCD(5, 16, "Pump 1 inactive");
    printLCD(5, 32, "Pump 2 inactive");
    printLCD(5, 48, "Pump 3 inactive");
    printLCD(94, 10, "off");

};

void updateLCD(){
    initializeLCD();
    clrLCD();
    if (isSaved){
        printLCD(25, 60, "Saved");
        isSaved = false;
        delay(500);
        updateLCD();
    }
    else if (subMenu){
        clrLCD();
        switch(selectedM){
          case 0: 
            clrLCD();
            printLCD(1, 16, ">");
            printLCD(8, 16, lang[selectedSubM]);
            if (selectedSubM+1 >= langCount);{
            printLCD(8, 32, lang[selectedSubM+1]);
            }
            if (selectedSubM < langCount-2){
                printLCD(8, 48, lang[selectedSubM+2]);

            }
            /* else if (selectedSubM < langCount-2){

            } */
            break;
          case 1: 
            printLCD(8, 16, "Pump Speed");
            printLCD(8, 32, "Pump Current");
            break;
          case 2: 
            printLCD(8, 16, "Pump Speed");
            printLCD(8, 32, "Pump Current");
            break;
          case 3: 
            printLCD(8, 16, "Pump Speed");
            printLCD(8, 32, "Pump Current");
            break;
          case 4: 
            printLCD(8, 16, "Brightness");
            printLCD(8, 32, "Scale");
            break;
          case 5: 
            printLCD(8, 16, "Password: ----");

            break;
          case 6: 
            printLCD(8, 16, "Color");
            printLCD(8, 32, " Font");

            break;
          case 7: 
            printLCD(8, 16, " P Value: ");
            printLCD(8, 32, " I Value: ");
            printLCD(8, 48, " D Value: ");
            break;
          case 8: 
            printLCD(8, 16, "Made by -poyrazoztok");
            printLCD(8, 32, "6.08.2026");
            break;
        }
    }
    else if (menu){
      Serial.println(selectedM);
        clrLCD();
        printLCD(1, 16, ">");
        printLCD(8, 16, Menu[selectedM]);
        printLCD(8, 32, Menu[selectedM + 1]);
        if (selectedM < menuCount-2)
        printLCD(8, 48, Menu[selectedM+2 ]);
    }
    else{
        printLCD(5, 16, "Pump 1> "+ pump1);
        printLCD(5, 32, "Pump 2> "+ pump2);
        printLCD(5, 48, "Pump 3> "+ pump3);
        printLCD(75, 62, "05.08.25");
        printLCD(94, 10, Mode);
        
    }

}