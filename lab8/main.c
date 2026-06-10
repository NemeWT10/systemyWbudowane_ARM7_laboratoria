#include <targets\AT91SAM7.h>
#include "pcf8833u8_lcd.h"
#define LCD_BACKLIGHT PIOB_SODR_P20
#define AUDIO_OUT PIOB_SODR_P19
#define SW_1 PIOB_SODR_P24
#define SW_2 PIOB_SODR_P25
//joystick
#define JOY_UP PIOA_SODR_P9
#define JOY_ENTER PIOA_SODR_P15
#define JOY_LEFT PIOA_SODR_P7
#define JOY_DOWN PIOA_SODR_P8
#define JOY_RIGHT PIOA_SODR_P14
 
int main(void)
{
 
    //wlaczenie kontrolerow PIO
    PMC_PCER = PMC_PCER_PIOB;
    PMC_PCER = PMC_PCER_PIOA;
    //konfiguracja sterowania podswietleniem
    PIOB_OER = LCD_BACKLIGHT;
    PIOB_PER = LCD_BACKLIGHT; 
    //konfiguracja sterowania joystickiem
    PIOA_PER = JOY_UP | JOY_ENTER | JOY_LEFT | JOY_DOWN | JOY_RIGHT;
    PIOA_ODR = JOY_UP | JOY_ENTER | JOY_LEFT | JOY_DOWN | JOY_RIGHT;
    //konfiguracja SW1 i SW2
    PIOB_ODR = SW_1 | SW_2 ;
    PIOB_PER = SW_1 | SW_2 ;
    //Lcd init
    InitLCD();
    LCDSettings();
    LCDClearScreen();
 
 
    PIOB_SODR |= LCD_BACKLIGHT;
    LCDSetRect(0, 0, 131, 131, FILL, GREEN);
 
    LCDPutStr("UP",15,60, MEDIUM, BLACK, GREEN);
    LCDPutStr("LEFT",60,10, MEDIUM, BLACK,GREEN);
    LCDPutStr("ENTER",60,45, MEDIUM, BLACK, GREEN);
    LCDPutStr("RIGHT",60,90,MEDIUM,BLACK,GREEN);
    LCDPutStr("SW1",110,10,MEDIUM,BLACK,GREEN);
    LCDPutStr("DOWN",110,50,MEDIUM,BLACK,GREEN);
    LCDPutStr("SW2",110,100,MEDIUM,BLACK,GREEN);
    LCDPutStr("Szymon",50,45,MEDIUM,BLACK,GREEN);
    LCDPutStr("Wojcik",70,45,MEDIUM,BLACK,GREEN);
    LCDPutStr("101699",80,45,MEDIUM,BLACK,GREEN);
    LCDPutStr("gr 5.10", 90, 45,MEDIUM,BLACK,GREEN);
 
 
    Delaya(10000000);
 
 
    LCDClearScreen();
 
    LCDSetRect(0, 0, 131, 131, FILL, GREEN);
    while(1)
    {
        //przyciski
        if ((PIOB_PDSR & SW_1) == 0)
        {
            LCDPutStr("SW1", 110, 10, MEDIUM, BLACK, GREEN);
        }
        else 
        {
            LCDPutStr("   ", 110, 10, MEDIUM, BLACK, GREEN);
        }
        if ((PIOB_PDSR & SW_2) == 0)
        {
            LCDPutStr("SW2", 110, 100, MEDIUM, BLACK, GREEN);
        }
        else
        {
            LCDPutStr("   ", 110, 100, MEDIUM, BLACK, GREEN);
        }
        //joystick
        if ((PIOA_PDSR & JOY_UP) == 0)
            LCDPutStr("UP",    15, 60, MEDIUM, BLACK, GREEN);
        else
            LCDPutStr("  ",    15, 60, MEDIUM, BLACK, GREEN);
        if ((PIOA_PDSR & JOY_LEFT) == 0)
            LCDPutStr("LEFT",  60, 10, MEDIUM, BLACK, GREEN);
        else
            LCDPutStr("    ",  60, 10, MEDIUM, BLACK, GREEN);
        if ((PIOA_PDSR & JOY_RIGHT) == 0)
            LCDPutStr("RIGHT", 60, 90, MEDIUM, BLACK, GREEN);
        else
           LCDPutStr("     ", 60, 90, MEDIUM, BLACK, GREEN);
        if ((PIOA_PDSR & JOY_DOWN) == 0)
            LCDPutStr("DOWN",  110, 50, MEDIUM, BLACK, GREEN);
        else
            LCDPutStr("     ",  110, 50, MEDIUM, BLACK, GREEN);
        if ((PIOA_PDSR & JOY_ENTER) == 0)
            LCDPutStr("ENTER", 60, 45, MEDIUM, BLACK, GREEN);
        else
            LCDPutStr("     ", 60, 45, MEDIUM, BLACK, GREEN);
    }
    return 0;
}
