/*H**********************************************************************
* FILENAME :        M2D_MIDI_PRESETS.h            
*
* DESCRIPTION :
*       MIDI Presets - CC and Notes - routines.
*
* PUBLIC FUNCTIONS :
*       int     FM_CompressFile( FileHandle )
*
* NOTES :
*       These functions are a part of the MIDI2DMX application
*       Developped by Villou / LEnsE
**
* AUTHOR :    Julien VILLEMEJANE        START DATE :    22/sept/2022
*
*       LEnsE / Institut d'Optique Graduate School
*H***********************************************************************/

#ifndef     __M2D_MIDI_PRESETS_H_INCLUDED
#define     __M2D_MIDI_PRESETS_H_INCLUDED

#include    "M2D_LENSE.h"


/* Variables globales */
const short             channel_ad_nb[16][2] = {       // spot adress and dmx chan number for instrument at MIDI channel
        {   0,  0},     {   0,  0},     {   0,  0},     {   0,  0},
        {   0,  0},     {   0,  0},     {   0,  0},     {   0,  0},
        {   128,  7},   {   136,  7},   {   144,  7},   {   152,  7},
        {   16,  7},     {   24,  7},     {   8,  7},    {   0,  7}};

const uint8_t           channel_dim[16][2] = {       // DMX dimmer channel number for instrument at MIDI channel and relative intensity (0 - 100%)
        {   0,  0},     {   0,  0},     {   0,  0},     {   0,  0},
        {   0,  0},     {   0,  0},     {   0,  0},     {   0,  0},
        {   1,  100},   {   1,  70},    {   1,  80},    {   1,  80},
        {   1,  80},    {   1,  80},    {   1,  80},    {   1,  80}};

const uint8_t           channel_dmxConfig[16][8] = {    // DMX value for each DMX channel (first byte) for instrument at MIDI channel
        {   0,  0,  0,  0,  0,  0,  0,  0},     // MIDI channel 0
        {   0,  0,  0,  0,  0,  0,  0,  0},
        {   0,  0,  0,  0,  0,  0,  0,  0},
        {   0,  0,  0,  0,  0,  0,  0,  0},
        {   0,  0,  0,  0,  0,  0,  0,  0},     // MIDI channel 4
        {   0,  0,  0,  0,  0,  0,  0,  0},
        {   0,  0,  0,  0,  0,  0,  0,  0},
        {   0,  0,  0,  0,  0,  0,  0,  0},     
        {   255,  0,  255,  0,  0,  0,  0,  0},     // MIDI channel 8   - DIM / STR / R / G / B / PRES / PROG 
        {   255,  0,  128,  64,  196,  0,  0,  0},
        {   255,  0,  64,  255,  64,  0,  0,  0},
        {   255,  0,  128,  128,  64,  0,  0,  0},
        {   255,  255,  128, 0,  0,  0,  0,  0},     // MIDI channel 12  - MODE(0) / COLOR / SPEED / DIM / R / G / B
        {   255,  128,  196, 64,  0,  0,  0,  0},
        {   255,  64,  128, 196,  0,  0,  0,  0},
        {   255,  128,  64,  196,  0,  0,  0,  0}};


#endif