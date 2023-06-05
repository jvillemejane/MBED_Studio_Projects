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



/* Variables globales */




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

#endif