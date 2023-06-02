/****************************************************************************/
/*  SETUP_CONFIG module library                                             */
/****************************************************************************/
/*  LEnsE / Julien VILLEMEJANE       /   Institut d'Optique Graduate School */
/****************************************************************************/
/*  Library - SETUP_CONFIG.h file                                           */
/****************************************************************************/
/*  Tested on Nucleo-L476RG / 11th nov 2021                                 */
/****************************************************************************/


#ifndef     SETUP_CONFIG_H_INCLUDED
#define     SETUP_CONFIG_H_INCLUDED
#include    "mbed.h"

#define     DEBUG_MODE      true



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

#endif