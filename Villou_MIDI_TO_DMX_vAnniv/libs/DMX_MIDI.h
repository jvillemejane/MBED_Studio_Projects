/****************************************************************************/
/*  DMX_MIDI module library                                                 */
/****************************************************************************/
/*  LEnsE / Julien VILLEMEJANE       /   Institut d'Optique Graduate School */
/****************************************************************************/
/*  Library - DMX_MIDI.h file                                               */
/****************************************************************************/
/*  Tested on Nucleo-L476RG / 08th sept 2022                                */
/****************************************************************************/
/*  Debugging on USB @ 115200 bauds                                         */
/****************************************************************************/
/*  Board Pinout                                                            */
/*      + DMX (output only) : PE_8, PE_7, PE_12, PE_10, PE_14               */
/*              (uart7 - tx, rx, out_tx, start, enable)                     */
/*      + MIDI1 : PB_9, PB_8 (uart5)                                        */
/*      + MIDI2 : PG_14, PG_9 (uart6)                                       */
/*      + MIDI3 (input only) : PE_1, PE_2                                   */
/*      + Analog R,G,B : PF_8, PF_7, PF_9                                   */
/*      + Analog Pitch - Volume : PB_1, PC_2                                */
/*      + Analog In 1 & 2 : PA_6, PA_7                                      */
/*      + LCD : PB_5, PB_4, PB_3, PB_13, PF_13                              */
/*              (mosi, miso, sck, cs, rs)                                   */
/*              EA DOG LCD / 3 lines / SPI mode / 5V                        */
/*      + SD : PE_6, PE_5, PE_2, PE_3                                       */
/*              (mosi, miso, sck, cs)                                       */
/*      + nRF module : PB_5, PB_4, PB_3, PB_15, PC_7, PA_15                 */
/*              (mosi, miso, sck, cs, ce, irq)                              */
/*      + MSGEQ7 : PD_14, PD_15, PA_4                                       */
/*              (strobe, reset, analog out)                                 */
/*      + WS2812 led out : PC_8                                             */
/*      + DAC1 out : PA_5                                                   */
/*      + HC-05 BT module : PD_1, PD_0 (uart4)                              */
/*      + Digital In Pull-Down 1 to 4 : PA_7, PF_2, PF_1, PF_0              */
/****************************************************************************/

#ifndef     DMX_MIDI_H_INCLUDED
#define     DMX_MIDI_H_INCLUDED

#define     SAMPLES             512 
#define     MIDI_NOTE_ON        0x90
#define     MIDI_NOTE_OFF       0x80
#define     MIDI_CONTINUOUS_CTL 0xB0
#define     MIDI_FIRST_NOTE     20
#define     MIDI_NB_NOTE_PER_OCT    12

#include    "mbed.h"
#include    "PROCESS_MIDI.h"
#include    "CONFIG_SPOT_MIDI.h"
#include    "DMX_2_MIDI.h"

/* Entrées - Sorties */

extern      DigitalOut  debug_out;

extern      BufferedSerial      dmx;
extern      DigitalOut  out_tx;
extern      DigitalOut  start;     //envoie des données
extern      DigitalOut  enableDMX;
extern      AnalogIn    CV_volume;
extern      AnalogIn    CV_pitch;

extern      BufferedSerial  midi1, midi2, midi3;

extern      AnalogIn    variationR;
extern      AnalogIn    variationG;
extern      AnalogIn    variationB;

/* Variables globales */
extern      uint8_t     dmx_data[];
extern      int         rgb;
extern      uint16_t    channels_int_on[], channels_int_off[];
extern      uint8_t     cpt_midi[3];
extern      uint8_t     new_data_midi[], new_note_midi[], new_CC_midi[];
extern      uint8_t     midi_data[3][3], channel_data[], note_data[], velocity_data[];
extern      uint8_t     midi_on;

/* Functions */  
/* DMX output initialization */
void initDMX(void);
/* Clear internal values for DMX output */
void clearDMX();
/* Updating DMX output with internal values */
void updateDMX();

/* Joue une note sur la liaison MIDI */
void playNote(char midi_nb, char note, char velocity);
/* Stoppe une note sur la liaison MIDI */
void stopNote(char midi_nb, char note, char velocity);
/* Fonction d'initialisation de la liaison MIDI */
void initMIDI1(void);
/* Fonction d'initialisation de la liaison MIDI */
void initMIDI2(void);
/* Fonction d'initialisation de la liaison MIDI */
void initMIDI3(void);
/* Detection d'une note reçue en MIDI */
void detectNoteMIDI(uint8_t chan);
/* Remise à zéro d'une note reçue en MIDI */
void resetNoteMIDI(uint8_t chan);

/* Detection d'un CC reçu en MIDI */
void detectCCMIDI(uint8_t chan);
/* Remise à zéro d'un CC reçu en MIDI */
void resetCCMIDI(uint8_t chan);

/* Fonction d'interruption sur MIDI */
void ISR_midi_in(void);

/* Mise à jour tableau data */
void updateSpots(DMX_spots spots[]);


#endif