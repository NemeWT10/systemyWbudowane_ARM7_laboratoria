#include <targets\AT91SAM7.h>
#include "pcf8833u8_lcd.h"
 
#define LCD_BACKLIGHT PIOB_SODR_P20
int main (){
 
InitLCD();
LCDClearScreen();
 
 // Timer PIT init:
/*
  PMC_PCER = PMC_PCER_PIOB;
  PIOB_PER = LCD_BACKLIGHT; 
  PIOB_OER = LCD_BACKLIGHT;
  PIT_MR = 299999 | (1 << 24); // ustawienie wartosci PIV i ustawienie bitu PITEN
  PIT_PIVR;
 
  while(1)
  {
    if( (PIT_SR & (1<<0) ) !=0 ) // sprawdzenie flagi PITS - mozna usunac tego ifa
	{ 

        int liczniki = PIT_PIIR;
        int picnt = liczniki >> 20; // liczba przepelnien licznika CPIV
        if(picnt >= 50) //jesli uplynelo 50 okresow
		{
			//zmiana stanu B20
			if ( (PIOB_PDSR & (1<<20)) != 0 )
			{
				PIOB_CODR = (1 << 20);
			}
			else
			{
				PIOB_SODR = (1 << 20);
			}
            PIT_PIVR; //wyczyszczenie PICNT i flagi PITS (z rejestru PIT_SR)
        }
    }
  }
  */
 
 
	//tc0 init:
	PMC_PCER = PMC_PCER_PIOB | (1 << 12);
	PIOB_PER = LCD_BACKLIGHT; 
	PIOB_OER = LCD_BACKLIGHT;
	int licznik = 0; //opt.
 
	TC0_CCR = (1 << 1); //wylaczenie inkrementacji licznika - CLKDIS
	TC0_SR; // pusty odczyt do resetu flag (reset TC0_SR)
	TC0_CMR = (1 << 14) | (1 << 1) | (1 << 0); // ustawienie bitu CPCTRG (bit14) i preskalera 128
	TC0_RC = 37499; // obliczona wartosc RC
	TC0_CCR = (1 << 2) | (1 << 0); // wlaczenie zegara timera i reset programowy STWRG
 
	while(1)
	{
		if((TC0_SR & (1 << 4)) != 0) // sprawdzenie bitu CPCS (TC0_SR kasuje tę flagę)
		{ 
			licznik++; //opt.
			if(licznik >= 50) //5 sekund zeby cos zauwazyc
			{
				if ( (PIOB_PDSR & (1<<20)) != 0 )
				{
					PIOB_CODR = (1 << 20);
				}
				else
				{
					PIOB_SODR = (1 << 20);
				}
				licznik = 0; //opt.
			}
		}
	}
}
