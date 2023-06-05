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

#ifndef     LCD_DOG_H_INCLUDED
#define     LCD_DOG_H_INCLUDED

#include    "mbed.h"

/* Entrées/Sorties */  
extern      SPI                 lcd_nrf; // mosi, miso, sck
extern      DigitalOut          CS_LCD;
extern      DigitalOut          RS_LCD;

/* Fonctions */  
/* SPI Initialization / 400 kHz */
void    initSPI(void);
/* LCD Initialization / EA DOG 3 lines 16 char / 5V */
void    LCD_DOG_init(void);
void    LCD_DOG_setPosition(char ligne, char colonne);
void    LCD_DOG_writeChar(char val);
void    LCD_DOG_writeStr(char *c, char ligne, char colonne);
void    LCD_DOG_clear(void);
void    LCD_DOG_clear_Line(uint8_t line);


#endif