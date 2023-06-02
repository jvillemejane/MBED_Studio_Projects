/****************************************************************************/
/*  SETUP_CONFIG module library                                             */
/****************************************************************************/
/*  LEnsE / Julien VILLEMEJANE       /   Institut d'Optique Graduate School */
/****************************************************************************/
/*  Library - SETUP_CONFIG.cpp file                                         */
/****************************************************************************/
/*  Tested on Nucleo-L476RG / 11th nov 2021                                 */
/****************************************************************************/
/*  SetUp for CeTI Introduction with KORG Electribe Sampler                 */
/*  Light Type                                                              */
/*      SLS-6 - 7 ch - DIM / STR / R / G / B / PRES / PROG                  */
/*      LVPT12 - 7 ch - MODE(0) / COLOR / SPEED / DIM / R / G / B           */
/*      TMH-46 - 16 ch - PAN / TILT / SPEED / DIM / STR / R / G / B /
                    W / A / UV / SND1 / SPD_M / SND2 / SPD_C / RES          */
/*      LEDPARTY - 7 ch - DIM / R / G / B / W / STR / MODE                  */

#include    "PROCESS_MIDI.h"
#include    "DMX_MIDI.h"
#include <cstdint>

/* Action à réaliser / Controleur / Note Midi */
void    processNoteMidiCtrl(uint8_t chan){

}
/* Action à réaliser / Clavier / Note Midi */
void    processNoteMidiKeyb(uint8_t chan){
    uint8_t note = note_data[chan-1] % KEY_NB;
    // TODO : boucle sur groupes
    uint8_t color_nb = key_colors[note*MIDI_CH + 0];
    printf("NoteMidiKEYB - N=%d - %d - %d\r\n", chan, note_data[chan-1], color_nb);
    uint8_t c[6];
    getColor(color_nb, c);
    setAllColorSpots(0, c);
}
/* Action à réaliser / Séquenceur / Note Midi */
void    processNoteMidiSequ(uint8_t chan){

}
/* Action à réaliser / Controleur / CC Midi */
void    processCCMidiCtrl(uint8_t chan){
    switch(note_data[chan-1]){
        case 1 :    /* DIMMER GLOBAL - CC 1 */
            setAllDimmerSpots(0, velocity_data[chan-1]);
            break;
        case 4 :    /* SPEED MVT - CC 4 */
            setAllPan(0, velocity_data[chan-1]);
            break;
        case 5 :    /* SPEED MVT - CC 5 */
            setAllTilt(0, velocity_data[chan-1]);
            break;
        case 6 :    /* SPEED MVT - CC 6 */
            setAllPTSpeed(0, velocity_data[chan-1]);
            break;
        default:
            break;
    }
    

}
/* Action à réaliser / Séquenceur / CC Midi */
void    processCCMidiSequ(uint8_t chan){
    
}