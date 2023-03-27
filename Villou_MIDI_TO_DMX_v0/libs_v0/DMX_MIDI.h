/****************************************************************************/
/*  DMX_MIDI module library                                                 */
/****************************************************************************/
/*  LEnsE / Julien VILLEMEJANE       /   Institut d'Optique Graduate School */
/****************************************************************************/
/*  Library - DMX_MIDI.h file                                               */
/****************************************************************************/
/*  Tested on Nucleo-L476RG / 11th nov 2021                                 */
/****************************************************************************/

#ifndef     DMX_MIDI_H_INCLUDED
#define     DMX_MIDI_H_INCLUDED

#include    "mbed.h"
#include <cstdint>

#define     SAMPLES     512 

#define     MIDI_NOTE_ON        0x90
#define     MIDI_NOTE_OFF       0x80
#define     MIDI_CC             0xB0

/* Entrées - Sorties */
extern      UnbufferedSerial      debug_pc;
extern      DigitalOut  debug_out;
// DMX
extern      UnbufferedSerial      dmx;
extern      DigitalOut  out_tx;
extern      DigitalOut  start;     //envoie des données
extern      DigitalOut  enableDMX;

/* Midi Inputs and Outputs */
extern      UnbufferedSerial    midi1;  // Midi 1
extern      UnbufferedSerial    midi2; // Midi 2
extern      UnbufferedSerial    midi3;  // Midi 3

extern      AnalogIn    CV_volume;
extern      AnalogIn    CV_pitch;

extern      AnalogIn    variationR;
extern      AnalogIn    variationG;
extern      AnalogIn    variationB;

/* Variables globales */
extern      const uint8_t vague[];
extern      char        dmx_data[];

extern      char        cpt_midi[];
extern      char        new_data_midi[], new_note_midi[];
extern      char        midi_data[3][3], note_data[], velocity_data[];
extern      char        control_ch[], control_value[];

/* Fonctions */  
/* Fonction d'initialisation de la liaison DMX */
void initDMX(void);
/* Remise à zéro des données DMX */
void clearDMX(void);
/* Fonction de mise à jour de la sortie DMX */
void updateDMX();

/* Fonction d'initialisation de la liaison MIDI */
void initMIDI(uint8_t device);
/* Detection d'une note reçue en MIDI */
bool isNoteMIDIdetected(uint8_t device);
/* Note reçue en MIDI traité */
void resetNoteMIDI(uint8_t device);

/* Renvoie la note reçue sur la liaison MIDI */
void resendNoteMIDI(uint8_t source, uint8_t dest);
/* Joue une note sur la liaison MIDI */
void playNoteMIDI(uint8_t device, char note, char velocity);
/* Stoppe une note sur la liaison MIDI */
void stopNoteMIDI(uint8_t device, char note, char velocity);

/* Detection d'un controle reçu en MIDI */
bool isCCMIDIdetected(uint8_t device);
/* Controle reçu en MIDI traité */
void resetCCMIDI(uint8_t device);




/* Fonction d'interruption sur MIDI */
void ISR_midi_in(void);
/* Fonction d'interruption sur MIDI - version beta */
void ISR_midi_in2(void);

#endif