//Szymon Wójcik 101699 Systemy wbudowane lab9 cz.1 i cz.2
#include <targets\AT91SAM7.h>
#include "PCF8833U8_lcd.h"
#include "bmp132.h"
#include "bmpChoinka.h"

#define LCD_BACKLIGHT PIOB_SODR_P20

int main(void)
{
    PMC_PCER = PMC_PCER_PIOB;

    PIOB_PER = LCD_BACKLIGHT;
    PIOB_OER = LCD_BACKLIGHT;


    InitLCD();
    LCDSettings();
    LCDClearScreen();

    PIOB_SODR |= LCD_BACKLIGHT;

    LCDClearScreen();
 
  
    //LAB9 CZĘŚĆ 2

    // Dwa kontrastowe prostokty  dzielimy ekran pionowo w osi Y (kolumny)
    LCDSetRect(0, 0, 131, 65,  FILL, BLUE);    // lewa polowa
    LCDSetRect(0, 66, 131, 131, FILL, YELLOW); // prawa polowa
 
    // Czarna linia graniczna (kolumna y=66)
    LCDSetLine(0, 66, 131, 66, BLACK);
 
    // Tekst przchodzacy przez oba prostokaty
    LCDPutStr("TEST1", 50, 60, LARGE, RED, TRANSPARENT2);
 
    Delaya(100000000);
 
    // Ten sam napis w tym samym miejscu - napisanie 2 w miejscu 1
    LCDPutStr("TEST2", 50, 60, LARGE, RED, TRANSPARENT2);



    //LAB9 CZĘŚĆ 1 
//    LCDPutChar('x', 50, 125, LARGE, BLACK, GREEN);
//    LCDPutChar('x', 125, 50, LARGE, BLACK, GREEN);
//    LCDPutChar('x', 0, 50, LARGE, BLACK, GREEN);
//    LCDPutChar('x', 50, 0, LARGE, BLACK, GREEN);


//    int w1 = LCDPutStr2(5, 5,  MEDIUM, BLACK, GREEN, "Szymon Wojcik");
//    int w2 = LCDPutStr2(30, 5, MEDIUM, BLACK, GREEN, "GL: 10");
//
//    Delaya(50000000);
//
//    LCDClearXY(5, 5,  MEDIUM, w1, BLUE);
//    LCDClearXY(30,5, MEDIUM, w2, BLUE);
//    LCDPutChar('A', 10, 10, LARGE, RED, TRANSPARENT2);
//
//    Delaya(50000000);      
//    LCDClearScreen();
//    Delaya(10000000);
//    //narysowanie grafiki 132x132
//    LCDDrawBmp12(bmp132, 132, 132, 0, 0);
//    Delaya(10000000);
//
//    LCDClearScreen();
//
//    //niepoprawne wyswietlenie malej grafiki 
//    LCDDrawBmp12(bmp80, 132, 132, 0, 0); //wyswietlamy grafike ktora ma 80x80 w oknie 132x132
//    Delaya(100000000);
//
//    //poprawne wyswietlenie mniejszej grafiki
//    LCDClearScreen();
//    LCDDrawBmp12(bmp80, 80, 80, 0, 0);
//    LCDSetTransparentBackground(bmp80, 80, 80, 0, 0);
//    LCDPutStr("TEST80", 50, 10, LARGE, RED, TRANSPARENT);
    



    //animacja - wyswietlenie naprzemiennie 2 grafik - LAB9 CZĘŚĆ 2 
    while (1)
    {
//      LCDClearScreen();
//      LCDDrawBmp12(bmpChoinka, 116, 121, 0, 0);
//      LCDPutStr("Wesolych Swiat!", 20, 10, SMALL, RED, TRANSPARENT2);
//
//      Delaya(10000000);
//      LCDClearScreen();
//      LCDDrawBmp12(bmpMikolaj, 120, 120, 0, 0);
//      LCDPutStr("Wesolych Swiat!", 20, 10, SMALL, BLUE, TRANSPARENT2);
//      Delaya(10000000);
    }

    return 0;
}
