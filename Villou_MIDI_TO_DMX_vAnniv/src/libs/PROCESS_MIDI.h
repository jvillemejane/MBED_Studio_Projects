/****************************************************************************/
/*  PROCESS_MIDI module library                                             */
/****************************************************************************/
/*  LEnsE / Julien VILLEMEJANE       /   Institut d'Optique Graduate School */
/****************************************************************************/
/*  Library - PROCESS_MIDI.h file                                           */
/****************************************************************************/
/*  Tested on Nucleo-L476RG / 11th nov 2021                                 */
/****************************************************************************/


#ifndef     PROCESS_MIDI_H_INCLUDED
#define     PROCESS_MIDI_H_INCLUDED
#include    "mbed.h"
#include    "SPECIFIC_ANNIV.h"
 
#define     FADE_STEPS      128


/* Variables globales */
const uint8_t   fade_ramp[FADE_STEPS] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2,
    3, 4, 5, 6, 8, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60,
    65, 75, 85, 95, 110, 130, 150, 170, 190, 210, 225, 235, 245, 250, 255, 255,
    255, 255, 255, 250, 245, 235, 225, 210, 190, 170, 150, 130, 110, 95, 85, 75,
    65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 8, 6, 5, 4,
    3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};



/* Fonctions */  
/* Action à réaliser / Controleur / Note Midi */
void    processNoteMidiCtrl(uint8_t chan);
/* Action à réaliser / Clavier / Note Midi */
void    processNoteMidiKeyb(uint8_t chan);
/* Action à réaliser / Séquenceur / Note Midi */
void    processNoteMidiSequ(uint8_t chan);
/* Action à réaliser / Controleur / CC Midi */
void    processCCMidiCtrl(uint8_t chan);
/* Action à réaliser / Séquenceur / CC Midi */
void    processCCMidiSequ(uint8_t chan);

/* Action globale */
void    processAllTime(void);

/* Action sur séquenceur global RGB */
void    seq_rgb_glob(void);
/* Action sur séquenceur 1 to 4 */
void    seq_nb_glob(uint8_t nb);
/* Action sur mode fade */
void    fade_mode_glob(void);

#endif