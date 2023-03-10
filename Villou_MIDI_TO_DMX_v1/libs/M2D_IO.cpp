/*H**********************************************************************
* FILENAME :        M2D_IO.cpp            
*
* DESCRIPTION :
*       Inputs Ouputs configuration file.
*
* NOTES :
*       These functions are a part of the MIDI2DMX application
*       Developped by Villou / LEnsE
**
* AUTHOR :    Julien VILLEMEJANE        START DATE :    22/sept/2022
*
*       LEnsE / Institut d'Optique Graduate School
*H***********************************************************************/

#include    "M2D_IO.h"



/****************************************************/
/* Global Variables                                 */
/****************************************************/
char            temp_string[17];

/****************************************************/
/* Inputs and Outputs declaration                   */  
/****************************************************/
/* LCD outputs */
SPI             lcd_nrf(PB_5, PB_4, PB_3); // mosi, miso, sck
DigitalOut      CS_LCD(PB_13);
DigitalOut      RS_LCD(PF_13);
/* Debug Output */
DigitalOut      debug_out(D13);
/* Dmx Ouputs */
BufferedSerial  dmx(PE_8, PE_7);
DigitalOut      out_tx(PE_12); 
DigitalOut      start(PE_10);     //envoie des données
DigitalOut      enableDMX(PE_14 );
/* CV Volume and Pitch for specific instruments */
// AnalogIn        CV_volume;
// AnalogIn        CV_pitch;
/* Midi Inputs and Outputs */
BufferedSerial  midi1(PB_9, PB_8);  // Midi 1
BufferedSerial  midi2(PG_14, PG_9);  // Midi 2
BufferedSerial  midi3(PE_1, PE_0);  // Midi 3
/* Analog Inputs */
// AnalogIn    variationR;
// AnalogIn    variationG;
// AnalogIn    variationB;

/****************************************************/
/* Functions                                        */  
/****************************************************/
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
    LCD_DOG_writeStr((char *)"                ", line, 1);
}

