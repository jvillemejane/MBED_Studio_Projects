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
#define     PRESET_NB   1
extern      uint8_t     key_colors[];
extern      uint8_t     key_strobe[];


/*** CONTROLEUR ***/
#define     SEQ_RGB_SPOTS   4
#define     SEQ_RGB_STEPS   8

/*** COULEURS ***/

#define     COLOR_POS_R     0
#define     COLOR_POS_G     1
#define     COLOR_POS_B     2
#define     COLOR_POS_W     3
#define     COLOR_POS_A     4
#define     COLOR_POS_UV    5

/* Définition couleur */
#define     COLOR_N         0
#define     COLOR_W         1
#define     COLOR_R         2
#define     COLOR_B         3
#define     COLOR_G         4
#define     COLOR_UV        5
#define     COLOR_A         6
#define     COLOR_UV_L      7
#define     COLOR_UV_D      8
#define     COLOR_UV_A      9
#define     COLOR_UV_A_D    10
#define     COLOR_R_L       11
#define     COLOR_OR        12
#define     COLOR_BR        13
#define     COLOR_RB        14
#define     COLOR_Y         15
#define     COLOR_B_L       16
#define     COLOR_G_L       17
#define     COLOR_GB        18
#define     COLOR_BG        19


/* Preset positions - PAN / TILT / SPD / ST / SPD */
#define     POS_NB          19

#define     POS_0_NOS       0
#define     POS_0_ST        1
#define     POS_VERT_NOS    2
#define     POS_VERT_ST     3
#define     POS_45_45_FF    4
#define     POS_90_45_FF    5
#define     POS_45_90_FF    6
#define     POS_45_135_FF   7
#define     POS_90_135_FF   8
#define     POS_45_45_F     9
#define     POS_90_45_F     10
#define     POS_45_90_F     11
#define     POS_45_135_F    12
#define     POS_90_135_F    13
#define     POS_45_45_L     14
#define     POS_90_45_L     15
#define     POS_45_90_L     16
#define     POS_45_135_L    17
#define     POS_90_135_L    18

/* Preset positions - PAN / TILT / SPD / ST(speed by pot)*/
const       uint8_t     positions[POS_NB * 4] = {
    0,  0,  0,  0,      // No Strobe - Pos 0
    0,  0,  0,  1,      // Strobe - Pos 0
    128,0,  0,  0,      // No Strobe - Pos vert
    128,0,  0,  1,      // Strobe - Pos vert
    64, 32, 0,  0,      // POS 45 45 - FF
    128, 32, 0,  0,
    64, 64, 0,  0,
    64, 96, 0,  0,
    128, 96, 0,  0,
    64, 32, 32,  0,     // POS 45 45 - F
    128, 32, 32,  0,
    64, 64, 32,  0,
    64, 96, 32,  0,
    128, 96, 32,  0,
    64, 32, 64,  0,     // POS 45 45 - L
    128, 32, 64,  0,
    64, 64, 64,  0,
    64, 96, 64,  0,
    128, 96, 64,  0
};

/* SEQUENCES CONTROLEUR - Nb couleurs + valeurs couleurs */
extern      uint8_t     seq1[];
extern      uint8_t     seq2[];
extern      uint8_t     seq3[];
extern      uint8_t     seq4[];

extern      uint8_t     seq_rgb_steps[];
/* Liste Couleurs PADS */
extern      uint8_t     color_pads[];

/* FONCTIONS */

void    getColor(uint8_t indice, uint8_t c[]);


#endif