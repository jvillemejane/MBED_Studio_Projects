
#ifndef     SPECIFIC_H_INCLUDED
#define     SPECIFIC_H_INCLUDED

#include    "mbed.h"
#include <cstdint>

#define     NB_SPOTS        14
#define     NB_PARAMS       17

// DIM / STR / R / G / B / W / A / UV / MODE / DEF_MOD / PAN / TILT / SPEED
//   / SOUND / SND_VAL_MIN / MAX / FADE_VAL
const uint8_t spotLEDPARTY[NB_PARAMS] = {1, 6, 2, 3, 4, 5, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0};
const uint8_t spotRenkLVPT[NB_PARAMS] = {4, 3, 5, 6, 7, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
const uint8_t spotSLS7[NB_PARAMS] = {1, 2, 3, 4, 5, 6, 7, 8, 2, 0, 0, 0, 0, 10, 130, 255, 10};
const uint8_t spotTMH[NB_PARAMS] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 0, 1, 2, 3, 12, 129, 255, 2};
const uint8_t spotBAR3[NB_PARAMS] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 0, 0, 0, 0, 10, 130, 255, 10};

// TYPE / ADD / CHAN / GPE
const uint16_t type_spot[NB_SPOTS][4] = {
            {1, 1, 7, 1}, {1, 9, 7, 2}, {1, 17, 7, 3}, {1, 25, 7, 4},
            {1, 33, 7, 4}, {1, 41, 7, 3}, {1, 49, 7, 2}, {1, 57, 7, 1}, 
            {4, 257, 16, 5}, {4, 273, 16, 5}, {3, 289, 10, 6}, {3, 305, 10, 6},
            {5, 129, 10, 5}, {5, 145, 10, 5}};




/* TMH 46 */
void    ANNIV_mode_strobe(uint8_t gpe);
void    ANNIV_mode_sound(uint8_t gpe);
void    ANNIV_mode_nofunc(uint8_t gpe);

#endif