/****************************************************************************/
/*  DMX_2_MIDI module library                                               */
/****************************************************************************/
/*  LEnsE / Julien VILLEMEJANE       /   Institut d'Optique Graduate School */
/****************************************************************************/
/*  Library - DMX_2_MIDI.h file                                             */
/****************************************************************************/
/****************************************************************************/
/*  Debugging on USB @ 115200 bauds                                         */
/****************************************************************************/

#ifndef     DMX_2_MIDI_H_INCLUDED
#define     DMX_2_MIDI_H_INCLUDED

#include    "mbed.h"
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    "PROCESS_MIDI.h"
#include    "MIDI_MODE.h"
#include    "DMX_MIDI.h"
#include    "LCD_DOG.h"
#include    "DMX_SPOTS.h"
#include    "DMX_MIDI.h"

#define     DEBUG_MODE      false
#define     DEBUG           false

/************************************/
/* Main Ticker                      */
/************************************/
extern      Ticker      main_timer;
/* Main Timer interrupt subroutine */
void        ISR_mainTimer(void);
void        startMainTimer(void);
void        stopMainTimer(void);
void        setMainTimer(int time_ms);
bool        isMainTimer(void);

/************************************/
/* SD CARD                          */
/************************************/
#include <SDBlockDevice.h>
#include <FATFileSystem.h>
extern      SDBlockDevice       sd_card;
extern      FATFileSystem       file_syst;
/* Initialization of the SD Card */
void        mountSDcard(void);
// update the setup of the address list of spots - *.adr file
void        openNewAddress(char* fileName);

#endif