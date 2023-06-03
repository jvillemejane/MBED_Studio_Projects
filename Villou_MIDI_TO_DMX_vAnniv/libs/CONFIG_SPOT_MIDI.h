/****************************************************************************/
/*  CONFIG_SPOT_MIDI module library                                         */
/****************************************************************************/
/*  LEnsE / Julien VILLEMEJANE       /   Institut d'Optique Graduate School */
/****************************************************************************/

#ifndef     CONFIG_SPOT_MIDI_H_INCLUDED
#define     CONFIG_SPOT_MIDI_H_INCLUDED

#include "mbed.h"
#include "PROCESS_MIDI.h"
#include "CONFIG_PRESETS.h"
#include "DMX_SPOTS.h"

/*  SetUp for CeTI Introduction with KORG Electribe Sampler                 */
/*  Light Type                                                              */
/*      SLS-6 - 7 ch - DIM / STR / R / G / B / PRES / PROG                  */
/*      LVPT12 - 7 ch - MODE(0) / COLOR / SPEED / DIM / R / G / B           */
/*      TMH-46 - 16 ch - PAN / TILT / SPEED / DIM / STR / R / G / B /
                    W / A / UV / SND1 / SPD_M / SND2 / SPD_C / RES          */
/*      LEDPARTY - 7 ch - DIM / R / G / B / W / STR / MODE                  */
/*      SLS-7 - 10 ch - DIM / MODE / R / G / B / W / A/ UV / MODE / MODE    */

#define     NB_SPOTS        8
/* Catalogues spots */

extern      DMX_spots       spots[];

// DIM / STR / R / G / B / W / A / UV / MODE / DEF_MOD / PAN / TILT / SPEED
const uint8_t spotLEDPARTY[13] = {1, 6, 2, 3, 4, 5, 0, 0, 7, 0, 0, 0, 0};
const uint8_t spotRenkLVPT[13] = {4, 3, 5, 6, 7, 0, 0, 0, 1, 0, 0, 0, 0};
const uint8_t spotSLS7[13] = {4, 3, 5, 6, 7, 0, 0, 0, 1, 0, 0, 0, 0};
const uint8_t spotTMH[13] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 0, 1, 2, 3};

// TYPE / ADD / CHAN / GPE
const uint16_t type_spot[NB_SPOTS][4] = {
            {1, 1, 7, 1}, {1, 9, 7, 2}, {1, 17, 7, 3}, {1, 25, 7, 4}, 
            {4, 257, 16, 5}, {4, 273, 16, 5}, {3, 289, 10, 6}, {3, 305, 10, 6}};


/* Fonctions */
/* Copie d'un tableau d'entier */
void    cpyTab(uint8_t* source, uint8_t* dest, int size);
/* Configuration des spots */
void    configSpots(void);

/* Mise à jour des couleurs */
void    setAllColorSpots(uint8_t gpe, uint8_t color[]);
void    setAllColorRGBSpots(uint8_t gpe, uint8_t R, uint8_t G, uint8_t B);
void    setAllColorAWUVSpots(uint8_t gpe, uint8_t A, uint8_t W, uint8_t UV);
/* Mise à jour des couleurs - R */
void    setAllRSpots(uint8_t gpe, uint8_t val);
void    setAllGSpots(uint8_t gpe, uint8_t val);
void    setAllBSpots(uint8_t gpe, uint8_t val);
void    setAllASpots(uint8_t gpe, uint8_t val);
void    setAllWSpots(uint8_t gpe, uint8_t val);
void    setAllUVSpots(uint8_t gpe, uint8_t val);

/* Mise à jour du dimmer */
void    setAllDimmerSpots(uint8_t gpe, uint8_t dim);

/* Mise à jour des positions */
void    setAllPosition(uint8_t gpe, uint8_t speed, uint16_t pan, uint16_t tilt);
void    setAllPTSpeed(uint8_t gpe, uint8_t speed);
void    setAllPan(uint8_t gpe, uint8_t pan);
void    setAllTilt(uint8_t gpe, uint8_t tilt);

#endif