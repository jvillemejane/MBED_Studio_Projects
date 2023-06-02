/****************************************************************************/
/*  LCD_DOG module library                                                  */
/*      For EA DOG 3 lines x 16 characters                                  */
/****************************************************************************/
/*  LEnsE / Julien VILLEMEJANE       /   Institut d'Optique Graduate School */
/****************************************************************************/
/*  Library - LCD_DOG.h file                                                */
/****************************************************************************/
/*  Tested on Nucleo-L767ZI /                                               */
/****************************************************************************/

#include "LCD_DOG.h"

// LCD and nRF modules
SPI                 lcd_nrf(PB_5, PB_4, PB_3); // mosi, miso, sck
DigitalOut          CS_LCD(PB_13);
DigitalOut          RS_LCD(PF_13);

/* SPI Initialization / Mode 0 / 100 kHz */
void    initSPI(void){
    lcd_nrf.format(8,0);
    lcd_nrf.frequency(100000);
}

/* LCD Initialization / EA DOG 3 lines 16 char / 5V */
void    LCD_DOG_init(void){
    CS_LCD = 0;
    RS_LCD = 0;
    lcd_nrf.write(0x29); // Function Set - Table 1
    lcd_nrf.write(0x1D); // Bias Set
    lcd_nrf.write(0x50); // Power Control
    lcd_nrf.write(0x6C); // Follower Control
    lcd_nrf.write(0x78); // Contrast Set
    lcd_nrf.write(0x03); // Function Set - Table 0
    lcd_nrf.write(0x0F); // Display On
    lcd_nrf.write(0x01); // Clear Display
    thread_sleep_for(2);    // Wait 2 ms
    lcd_nrf.write(0x06); // Cursor On
    thread_sleep_for(10);    // Wait 10 ms
    RS_LCD=1;
    CS_LCD=1;
    thread_sleep_for(10);    // Wait 10 ms
}

/* LCD set cursor position - 
    @param line : line to display the cursor (1 to 3)
    @param column : column to display the cursor (1 to 16)
*/
void    LCD_DOG_setPosition(char line, char column){
  char adress = 0x80 + ((line - 1) * 16) + (column - 1);
  CS_LCD = 0;
  RS_LCD = 0;
  lcd_nrf.write(adress); 
  CS_LCD=1;
  RS_LCD = 1;
}

/* LCD display char at the current cursor position - 
    @param val : character to display
*/
void    LCD_DOG_writeChar(char val){
  CS_LCD = 0;
  lcd_nrf.write(val); 
  CS_LCD=1;
}

/* LCD display string of char at a specific position - 
    @param *c : string of char to display
    @param line : line to display string of char (1 to 3)
    @param column : column to display string of char (1 to 16)
*/
void    LCD_DOG_writeStr(char *c, char line, char column){
    char i = 0;
    LCD_DOG_setPosition(line,column);
    while(c[i] != '\0') {
        LCD_DOG_writeChar(c[i]);
        i++;
    }
}

/* LCD clear display */
void    LCD_DOG_clear(void){
    CS_LCD = 0;
    RS_LCD = 0;
    lcd_nrf.write(0x01);    //Clear Display
    thread_sleep_for(2);    // Wait 2 ms
    RS_LCD = 1;
    CS_LCD = 1;
}

/* LCD clear line */
void    LCD_DOG_clear_Line(uint8_t line){
    LCD_DOG_writeStr("                ", line, 1);
}