/*H**********************************************************************
* FILENAME :        M2D_MIDI_MODE.h            
*
* DESCRIPTION :
*       MIDI Mode processing routines.
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
/* Default Parameters for CTRL / midiX_note_params                          */
/*      - 0 : blackout          / note                                      */
/*      - 1 : allR              / note                                      */
/*      - 2 : allG              / note                                      */
/*      - 3 : allB              / note                                      */
/*      - 4 : allA              / note                                      */
/*      - 5 : allW              / note                                      */
/*      - 6 : allUV             / note                                      */
/*      - 7 : allRGBWAUV        / note                                      */

/* Default Parameters for CTRL / midiX_CC_params                            */
/*      - 0 : dimmer            / cc                                        */
/*      - 1 : allR              / cc                                        */
/*      - 2 : allG              / cc                                        */
/*      - 3 : allB              / cc                                        */
/*      - 4 : allA              / cc                                        */
/*      - 5 : allW              / cc                                        */
/*      - 6 : allUV             / cc                                        */
/****************************************************************************/

#ifndef     __M2D_MIDI_MODE_H_INCLUDED
#define     __M2D_MIDI_MODE_H_INCLUDED

#include    "M2D_LENSE.h"

#define     DMX_MODE_NO         0
#define     DMX_MODE_BLACKOUT   1
#define     DMX_MODE_RGBAWUV    2


/************************************/
/* Global Parameters                */
/************************************/

/* Global mode - CTRL or SEQ or KEYB - for each midi input */
#define     MODE_CTRL       1
#define     MODE_SEQ        2
#define     MODE_KEYB       3

extern      uint8_t     mode_midi[3];

extern      uint8_t     midi1_note_params[32];
extern      uint8_t     midi1_CC_params[16];
extern      uint8_t     midi2_note_params[32];
extern      uint8_t     midi2_CC_params[16];
extern      uint8_t     midi3_note_params[32];
extern      uint8_t     midi3_CC_params[16];

/****************************************************/
/* Functions                                        */  
/****************************************************/
/* Note detection - Controller mode */
void detectNoteMidiCTRLMode(uint8_t midi);
/* CC detection - Controller mode */
void detectCCMidiCTRLMode(uint8_t midi);

/* MIDI1 Initialization Routine */
void initMIDI1(void);
/* MIDI2 Initialization Routine */
void initMIDI2(void);
/* MIDI3 Initialization Routine */
void initMIDI3(void);

/* MIDI1 Interrupt Subroutine */
void ISR_midi1_in(void);
/* MIDI2 Interrupt Subroutine */
void ISR_midi2_in(void);
#endif