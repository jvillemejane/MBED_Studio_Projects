/*H**********************************************************************
* FILENAME :        M2D_LENSE.h            
*
* DESCRIPTION :
*       Global configuration file.
*
* NOTES :
*       These functions are a part of the MIDI2DMX application
*       Developped by Villou / LEnsE
**
* AUTHOR :    Julien VILLEMEJANE        START DATE :    22/sept/2022
*
*       LEnsE / Institut d'Optique Graduate School
*H***********************************************************************/


#ifndef     __M2D_LENSE_H_INCLUDED
#define     __M2D_LENSE_H_INCLUDED

#define     DEBUG   true

#include    "mbed.h"
#include    <stdio.h>
#include    <stdlib.h>
#include    "M2D_FILES.h"
#include    "M2D_IO.h"
#include    "M2D_MIDI_PRESETS.h"
#include    "M2D_MIDI_MODE.h"
#include    "M2D_DMX_SPOTS.h"
#include    "M2D_DMX_SPOTS_VALUES.h"
#include    "M2D_DMX_PRESETS.h"
#include    "M2D_DMX_MODE.h"

#define     SAMPLES                 512 
#define     MIDI_NOTE_ON            0x90
#define     MIDI_NOTE_OFF           0x80
#define     MIDI_CONTINUOUS_CTL     0xB0
#define     MIDI_FIRST_NOTE         20
#define     MIDI_NB_NOTE_PER_OCT    12


/* Variables globales */
extern      int         rgb;
extern      uint16_t    channels_int_on[], channels_int_off[];
extern      uint8_t     cpt_midi;
extern      uint8_t     new_data_midi[], new_note_midi[], new_CC_midi[];
extern      uint8_t     midi_data[3][3], channel_data[], note_data[], velocity_data[];


/****************************************************/
/* Functions                                        */  
/****************************************************/
/* Joue une note sur la liaison MIDI */
void playNote(char midi_nb, char note, char velocity);
/* Stoppe une note sur la liaison MIDI */
void stopNote(char midi_nb, char note, char velocity);
/* Detection d'une note reçue en MIDI */
void detectNoteMIDI1(void);
/* Detection d'une note reçue en MIDI */
void detectNoteMIDI2(void);
/* Detection d'une note reçue en MIDI */
void detectNoteMIDI3(void);



#endif