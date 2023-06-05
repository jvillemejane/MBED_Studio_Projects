/****************************************************************************/
/*  MIDI_MODE module library                                                */
/****************************************************************************/
/*  LEnsE / Julien VILLEMEJANE       /   Institut d'Optique Graduate School */
/****************************************************************************/
/*  Library - MIDI_MODE.h file                                              */
/****************************************************************************/
/****************************************************************************/
/*  Debugging on USB @ 115200 bauds                                         */
/****************************************************************************/

#ifndef     MODE_MIDI_H_INCLUDED
#define     MODE_MIDI_H_INCLUDED

#include    "DMX_2_MIDI.h"


/************************************/
/* Global Parameters                */
/************************************/

/* Global mode - CTRL or SEQ or KEYB - for each midi input */
#define     MODE_CTRL       1
#define     MODE_SEQ        2
#define     MODE_KEYB       3

extern      uint8_t     mode_midi[3];


#endif