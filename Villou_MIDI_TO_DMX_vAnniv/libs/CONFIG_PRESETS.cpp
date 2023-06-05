/****************************************************************************/
/*  CONFIG_PRESETS module library                                           */
/****************************************************************************/
/*  LEnsE / Julien VILLEMEJANE       /   Institut d'Optique Graduate School */
/****************************************************************************/

#include "CONFIG_PRESETS.h"
#include <cstdint>

/* KEYBOARD - COLORS */

uint8_t     key_pos[KEY_NB]{
    POS_0_NOS,  POS_0_NOS,  POS_45_45_L,   POS_0_NOS,
    POS_45_90_L,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0
};

uint8_t     key_colors[KEY_NB * MIDI_CH] = {
/*1 */ 0,  0,  0,  0,  COLOR_UV_L,  COLOR_UV_L,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*2#*/ 0,  0,  0,  0,  COLOR_N,  COLOR_N,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  COLOR_UV,  COLOR_UV,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*4#*/ 0,  0,  0,  0,  COLOR_UV_A_D,  COLOR_UV_A_D,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*5 */ 0,  0,  0,  0,  COLOR_UV_D,  COLOR_UV_D,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       COLOR_R,  COLOR_R,  COLOR_R,  COLOR_R,  COLOR_R_L,  COLOR_R_L,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*7#*/ COLOR_B,  COLOR_B_L,  COLOR_B_L,  COLOR_B,  COLOR_UV_D,  COLOR_UV_L,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       COLOR_W,  COLOR_Y,  COLOR_Y,  COLOR_W,  COLOR_Y,  COLOR_Y,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*9#*/ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       COLOR_B,  COLOR_B_L,  COLOR_B_L,  COLOR_B,  COLOR_UV,  COLOR_UV,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*11#*/0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*12*/ COLOR_BG,  COLOR_GB,  COLOR_GB,  COLOR_BG,  COLOR_B_L,  COLOR_G_L,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,

/*13 */COLOR_BR,  COLOR_RB,  COLOR_BR,  COLOR_RB,  COLOR_R,  COLOR_B,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*2#*/ COLOR_G_L,  COLOR_Y,  COLOR_Y,  COLOR_G_L,  COLOR_UV,  COLOR_UV,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       COLOR_G_L,  COLOR_Y,  COLOR_Y,  COLOR_G_L,  COLOR_N,  COLOR_N,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*4#*/ 0,  0,  0,  0,  COLOR_UV_A_D,  COLOR_UV_A_D,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*5 */ COLOR_B,  COLOR_R,  COLOR_B,  COLOR_R,  COLOR_R,  COLOR_B,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       COLOR_R,  COLOR_B,  COLOR_R,  COLOR_B,  COLOR_B,  COLOR_R,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*7#*/ COLOR_GB,  COLOR_G,  COLOR_GB,  COLOR_G,  COLOR_G,  COLOR_B,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       COLOR_G,  COLOR_GB,  COLOR_G,  COLOR_N,  COLOR_G,  COLOR_W,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*9#*/ COLOR_GB,  COLOR_G_L,  COLOR_G_L,  COLOR_GB,  COLOR_G,  COLOR_B,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       COLOR_B_L,  COLOR_GB,  COLOR_GB,  COLOR_B_L,  COLOR_G,  COLOR_W,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*11#*/COLOR_GB,  COLOR_GB, COLOR_GB,  COLOR_N,  COLOR_BG,  COLOR_G_L,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*24*/ COLOR_N,  COLOR_GB,  COLOR_GB,  COLOR_G_L,  COLOR_BG,  COLOR_G_L,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,

/*25*/ COLOR_N,  COLOR_GB,  COLOR_G_L,  COLOR_N,  COLOR_BG,  COLOR_G_L,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       COLOR_GB,  COLOR_N,  COLOR_N,  COLOR_G_L,  COLOR_BG,  COLOR_G_L,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       COLOR_GB,  COLOR_G,  COLOR_GB,  COLOR_G,  COLOR_B_L,  COLOR_G_L,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*4#*/ COLOR_G,  COLOR_GB,  COLOR_G,  COLOR_N,  COLOR_B_L,  COLOR_W,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*5 */ COLOR_GB,  COLOR_G_L,  COLOR_G_L,  COLOR_GB,  COLOR_B_L,  COLOR_G_L,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       COLOR_B_L,  COLOR_GB,  COLOR_GB,  COLOR_B_L,  COLOR_B_L,  COLOR_W,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*7#*/ COLOR_GB,  COLOR_GB, COLOR_GB,  COLOR_N,  COLOR_BG,  COLOR_B_L,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       COLOR_N,  COLOR_GB,  COLOR_GB,  COLOR_G_L,  COLOR_BG,  COLOR_W,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*9#*/ COLOR_N,  COLOR_GB,  COLOR_G_L,  COLOR_N,  COLOR_BG,  COLOR_B_L,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       COLOR_GB,  COLOR_N,  COLOR_N,  COLOR_G_L,  COLOR_BG,  COLOR_W,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*11#*/COLOR_OR,  COLOR_Y,  COLOR_OR,  COLOR_B_L,  COLOR_A,  COLOR_R,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*36*/ COLOR_B_L,  COLOR_OR,  COLOR_B_L,  COLOR_Y,  COLOR_N,  COLOR_R,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,

/*37 */COLOR_Y,  COLOR_R,  COLOR_R,  COLOR_Y,  COLOR_OR,  COLOR_N,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*2#*/ COLOR_R,  COLOR_OR,  COLOR_OR,  COLOR_R,  COLOR_N,  COLOR_A,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       COLOR_OR,  COLOR_Y,  COLOR_R,  COLOR_R,  COLOR_A,  COLOR_N,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*4#*/ COLOR_Y,  COLOR_OR,  COLOR_OR,  COLOR_Y,  COLOR_OR,  COLOR_A,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*5 */ COLOR_R,  COLOR_B,  COLOR_R,  COLOR_B,  COLOR_UV,  COLOR_N,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       COLOR_B,  COLOR_R,  COLOR_B,  COLOR_N,  COLOR_UV,  COLOR_W,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*7#*/ COLOR_N,  COLOR_BR,  COLOR_R,  COLOR_BR,  COLOR_BR, COLOR_N,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       COLOR_BR, COLOR_R,  COLOR_BR,  COLOR_N,  COLOR_BR,  COLOR_W,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*9#*/ COLOR_Y,  COLOR_RB,  COLOR_Y,  COLOR_RB,  COLOR_W,  COLOR_W,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       COLOR_RB,  COLOR_N,  COLOR_RB,  COLOR_N,  COLOR_W,  COLOR_W,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*11#*/COLOR_B,  COLOR_RB,  COLOR_B,  COLOR_RB,  COLOR_R,  COLOR_N,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*48*/ COLOR_RB,  COLOR_B,  COLOR_RB,  COLOR_N,  COLOR_R,  COLOR_N,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
};

/* Strobe mode - gpe */
uint8_t     key_strobe[KEY_NB*MIDI_CH]{
/*1 */ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*2#*/ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*4#*/ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*5 */ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*7#*/ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*9#*/ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*11#*/0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*12*/ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,


/*13*/ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*2#*/ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*4#*/ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*5 */ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*7#*/ 0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*9#*/ 0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*11#*/0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*24*/ 0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,

/*25*/ 0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*2#*/ 0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*4#*/ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*5 */ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*7#*/ 0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*9#*/ 0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*11#*/0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*36*/ 0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,

/*37 */0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*2#*/ 0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*4#*/ 0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*5 */ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*7#*/ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*9#*/ 0,  0,  0,  0,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*11#*/0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*48*/ 0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
};

uint8_t     seq1[32+1] = {16, 
                41,  42, 43,  44,  41,  42,  43,  44,
                45,  46,  47,  48,  45,  46,  47,  48,
                0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0
            };
uint8_t     seq2[32+1] = {16, 
                35,  36,  35,  36,  35,  36,  35,  36,
                37,  38,  39,  40,  37,  38,  39,  40,
                0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0
            };        
uint8_t     seq3[32+1] = {16, 
                19,  20,  21,  22,  23,  24,  25,  26,
                27,  28,  29,  30,  31,  32,  33,  34,
                0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0
            };
uint8_t     seq4[32+1] = {4, 
                15,  16,  17,  18,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0,
                0,  0,  0,  0,  0,  0,  0,  0
            };

uint8_t     seq_rgb_steps[SEQ_RGB_SPOTS * SEQ_RGB_STEPS] = {
    2, 0, 0, 0,     1, 2, 0, 0,     0, 1, 2, 0,     0, 0, 1, 2,
    0, 0, 0, 2,     0, 0, 2, 1,     0, 2, 1, 0,     2, 1, 0, 0
};

/* Liste Couleurs PADS */
uint8_t     color_pads[12] = {28, 29, 19, 23, 41, 42, 15, 16, 0, 0, 0, 0};


/* getColor */
void    getColor(uint8_t indice, uint8_t c[]){
    c[COLOR_POS_R] = 0;     c[COLOR_POS_G] = 0;     c[COLOR_POS_B] = 0;
    c[COLOR_POS_A] = 0;     c[COLOR_POS_W] = 255;   c[COLOR_POS_UV] = 0;


    switch(indice){
        case COLOR_W :
            c[COLOR_POS_R] = 0;     c[COLOR_POS_G] = 0;     c[COLOR_POS_B] = 0;
            c[COLOR_POS_A] = 0;     c[COLOR_POS_W] = 255;   c[COLOR_POS_UV] = 0;
            break;
        case COLOR_R :
            c[COLOR_POS_R] = 255;   c[COLOR_POS_G] = 0;     c[COLOR_POS_B] = 0;
            c[COLOR_POS_A] = 0;     c[COLOR_POS_W] = 0;     c[COLOR_POS_UV] = 0;
            break;
        case COLOR_B :
            c[COLOR_POS_R] = 0;     c[COLOR_POS_G] = 0;     c[COLOR_POS_B] = 255;
            c[COLOR_POS_A] = 0;     c[COLOR_POS_W] = 0;     c[COLOR_POS_UV] = 0;
            break;
        case COLOR_G :
            c[COLOR_POS_R] = 0;     c[COLOR_POS_G] = 255;   c[COLOR_POS_B] = 0;
            c[COLOR_POS_A] = 0;     c[COLOR_POS_W] = 0;     c[COLOR_POS_UV] = 0;
            break;
        case COLOR_UV:
            c[COLOR_POS_R] = 0;     c[COLOR_POS_G] = 0;     c[COLOR_POS_B] = 0;
            c[COLOR_POS_A] = 0;     c[COLOR_POS_W] = 0;     c[COLOR_POS_UV] = 128;
            break;            
        case COLOR_UV_L:
            c[COLOR_POS_R] = 0;     c[COLOR_POS_G] = 0;     c[COLOR_POS_B] = 0;
            c[COLOR_POS_A] = 0;     c[COLOR_POS_W] = 0;     c[COLOR_POS_UV] = 64;
            break;
        case COLOR_UV_D:
            c[COLOR_POS_R] = 0;     c[COLOR_POS_G] = 0;     c[COLOR_POS_B] = 0;
            c[COLOR_POS_A] = 0;     c[COLOR_POS_W] = 0;     c[COLOR_POS_UV] = 255;
            break;
        case COLOR_A:
            c[COLOR_POS_R] = 0;     c[COLOR_POS_G] = 0;     c[COLOR_POS_B] = 0;
            c[COLOR_POS_A] = 255;   c[COLOR_POS_W] = 0;     c[COLOR_POS_UV] = 0;
            break;
        case COLOR_UV_A:
            c[COLOR_POS_R] = 0;     c[COLOR_POS_G] = 0;     c[COLOR_POS_B] = 0;
            c[COLOR_POS_A] = 192;   c[COLOR_POS_W] = 0;     c[COLOR_POS_UV] = 64;
            break;       
        case COLOR_UV_A_D:
            c[COLOR_POS_R] = 0;     c[COLOR_POS_G] = 0;     c[COLOR_POS_B] = 0;
            c[COLOR_POS_A] = 128;   c[COLOR_POS_W] = 0;     c[COLOR_POS_UV] = 128;
            break;
        case COLOR_R_L:
            c[COLOR_POS_R] = 128;   c[COLOR_POS_G] = 10;    c[COLOR_POS_B] = 10;
            c[COLOR_POS_A] = 32;    c[COLOR_POS_W] = 0;     c[COLOR_POS_UV] = 0;
            break;
         case COLOR_G_L:
            c[COLOR_POS_R] = 10;   c[COLOR_POS_G] = 128;    c[COLOR_POS_B] = 10;
            c[COLOR_POS_A] = 0;    c[COLOR_POS_W] = 0;      c[COLOR_POS_UV] = 0;
            break;        
        case COLOR_B_L:
            c[COLOR_POS_R] = 10;   c[COLOR_POS_G] = 10;    c[COLOR_POS_B] = 128;
            c[COLOR_POS_A] = 0;    c[COLOR_POS_W] = 0;     c[COLOR_POS_UV] = 30;
            break;
        case COLOR_OR:
            c[COLOR_POS_R] = 255;   c[COLOR_POS_G] = 128;   c[COLOR_POS_B] = 0;
            c[COLOR_POS_A] = 0;     c[COLOR_POS_W] = 0;     c[COLOR_POS_UV] = 0;
            break;
        case COLOR_BR:
            c[COLOR_POS_R] = 112;   c[COLOR_POS_G] = 0;     c[COLOR_POS_B] = 144;
            c[COLOR_POS_A] = 0;     c[COLOR_POS_W] = 0;     c[COLOR_POS_UV] = 0;
            break;
        case COLOR_RB:
            c[COLOR_POS_R] = 144;   c[COLOR_POS_G] = 0;     c[COLOR_POS_B] = 112;
            c[COLOR_POS_A] = 0;     c[COLOR_POS_W] = 0;     c[COLOR_POS_UV] = 0;
            break;
        case COLOR_Y:
            c[COLOR_POS_R] = 192;   c[COLOR_POS_G] = 192;   c[COLOR_POS_B] = 0;
            c[COLOR_POS_A] = 0;     c[COLOR_POS_W] = 0;     c[COLOR_POS_UV] = 0;
            break;
        case COLOR_GB:
            c[COLOR_POS_R] = 0;     c[COLOR_POS_G] = 176;   c[COLOR_POS_B] = 112;
            c[COLOR_POS_A] = 0;     c[COLOR_POS_W] = 0;     c[COLOR_POS_UV] = 0;
            break;
        case COLOR_BG:
            c[COLOR_POS_R] = 0;     c[COLOR_POS_G] = 112;   c[COLOR_POS_B] = 176;
            c[COLOR_POS_A] = 0;     c[COLOR_POS_W] = 0;     c[COLOR_POS_UV] = 0;
            break;
        case COLOR_N :
        default : 
            c[COLOR_POS_R] = 0;     c[COLOR_POS_G] = 0;     c[COLOR_POS_B] = 0;
            c[COLOR_POS_A] = 0;     c[COLOR_POS_W] = 0;     c[COLOR_POS_UV] = 0;
    }
}

