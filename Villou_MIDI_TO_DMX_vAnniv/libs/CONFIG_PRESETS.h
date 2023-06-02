/****************************************************************************/
/*  CONFIG_PRESETS module library                                           */
/****************************************************************************/
/*  LEnsE / Julien VILLEMEJANE       /   Institut d'Optique Graduate School */
/****************************************************************************/

#ifndef     CONFIG_PRESETS_H_INCLUDED
#define     CONFIG_PRESETS_H_INCLUDED

#include "mbed.h"
#include "PROCESS_MIDI.h"
#include "DMX_SPOTS.h"
#include <cstdint>


/*** KEYBOARD ***/
#define     KEY_NB      48
#define     MIDI_CH     16
extern      uint8_t     key_colors[];


/*** COULEURS ***/

#define     COLOR_NB        11

#define     COLOR_POS_R     0
#define     COLOR_POS_G     1
#define     COLOR_POS_B     2
#define     COLOR_POS_W     3
#define     COLOR_POS_A     4
#define     COLOR_POS_UV    5

/* Définition couleur */
#define     COLOR_BLACK     0
#define     COLOR_WHITE     1
#define     COLOR_RED       2
#define     COLOR_BLUE      3
#define     COLOR_GREEN     4
#define     COLOR_UV        5
#define     COLOR_AMBER     6
#define     COLOR_UV_LIGHT  7
#define     COLOR_UV_DARK   8
#define     COLOR_UV_AMBER  9
#define     COLOR_UV_A_DARK 10

/* Preset de couleurs - R G B W A UV */
const       uint8_t     colors[COLOR_NB * 6] = {
    0,  0,  0,  0,  0,  0,
    0,  0,  0,  255,0,  0,
    255,0,  0,  0,  0,  0,
    0,  255,0,  0,  0,  0,
    0,  0,  255,0,  0,  0,
    0,  0,  0,  0,  0,  128,
    0,  0,  0,  0,  255,0,
    0,  0,  0,  0,  0,  64,
    0,  0,  0,  0,  0,  255,
    0,  0,  0,  0,  64,  192,
    0,  0,  0,  0,  128,  162
};


/* FONCTIONS */

void    getColor(uint8_t indice, uint8_t c[]);


#endif