/*H**********************************************************************
* FILENAME :        M2D_IO.h            
*
* DESCRIPTION :
*       Inputs Ouputs configuration file.
*
* PUBLIC FUNCTIONS :
*       int     FM_CompressFile( FileHandle )
*
* NOTES :
*       These functions are a part of the MIDI2DMX application
*       Developped by Villou / LEnsE
**
* AUTHOR :    Julien VILLEMEJANE        START DATE :    22/sept/2022
*
*       LEnsE / Institut d'Optique Graduate School
*H***********************************************************************/


/****************************************************************************/
/*  Board Pinout                                                            */
/*      + DMX (output only) : PE_8, PE_7, PE_12, PE_10, PE_14               */
/*              (uart7 - tx, rx, out_tx, start, enable)                     */
/*      + MIDI1 : PB_9, PB_8 (uart5)                                        */
/*      + MIDI2 : PG_14, PG_9 (uart6)                                       */
/*      + MIDI3 (input only) : PE_1, PE_2                                   */
/*      + Analog R,G,B : PF_8, PF_7, PF_9                                   */
/*      + Analog Pitch - Volume : PB_1, PC_2                                */
/*      + Analog In 1 & 2 : PA_6, PA_7                                      */
/*      + LCD : PB_5, PB_4, PB_3, PB_13, PF_13                              */
/*              (mosi, miso, sck, cs, rs)                                   */
/*              EA DOG LCD / 3 lines / SPI mode / 5V                        */
/*      + SD : PE_6, PE_5, PE_2, PE_3                                       */
/*              (mosi, miso, sck, cs)                                       */
/*      + nRF module : PB_5, PB_4, PB_3, PB_15, PC_7, PA_15                 */
/*              (mosi, miso, sck, cs, ce, irq)                              */
/*      + MSGEQ7 : PD_14, PD_15, PA_4                                       */
/*              (strobe, reset, analog out)                                 */
/*      + WS2812 led out : PC_8                                             */
/*      + DAC1 out : PA_5                                                   */
/*      + HC-05 BT module : PD_1, PD_0 (uart4)                              */
/*      + Digital In Pull-Down 1 to 4 : PA_7, PF_2, PF_1, PF_0              */
/****************************************************************************/

#ifndef     __M2D_IO_H_INCLUDED
#define     __M2D_IO_H_INCLUDED

#include    "M2D_LENSE.h"


/****************************************************/
/* Inputs and Outputs declaration                   */  
/****************************************************/
/* LCD outputs */
extern      SPI             lcd_nrf; // mosi, miso, sck
extern      DigitalOut      CS_LCD;
extern      DigitalOut      RS_LCD;
/* Debug Output */
extern      DigitalOut      debug_out;
/* Dmx Ouputs */
extern      BufferedSerial  dmx;
extern      DigitalOut      out_tx;
extern      DigitalOut      start;     //envoie des données
extern      DigitalOut      enableDMX;
/* CV Volume and Pitch for specific instruments */
extern      AnalogIn        CV_volume;
extern      AnalogIn        CV_pitch;
/* Midi Inputs and Outputs */
extern      BufferedSerial  midi1, midi2, midi3;
/* Analog Inputs */
extern      AnalogIn    variationR;
extern      AnalogIn    variationG;
extern      AnalogIn    variationB;


/****************************************************/
/* Global Variables                                 */
/****************************************************/
extern      char        temp_string[17];

/****************************************************/
/* Functions                                        */  
/****************************************************/
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