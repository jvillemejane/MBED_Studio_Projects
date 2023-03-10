/*H**********************************************************************
* FILENAME :        M2D_LENSE.cpp            
*
* DESCRIPTION :
*       Global configuration file.
*
* NOTES :
*       These functions are a part of the MIDI2DMX application
*       Developped by Villou / LEnsE
**
* AUTHOR :    Julien VILLEMEJANE        START DATE :    22/sept/2022
*
*       LEnsE / Institut d'Optique Graduate School
*H***********************************************************************/

#include    "M2D_LENSE.h"

/* Variables globales */
uint16_t        channels_int_on[3], channels_int_off[3];
int             rgb;
// Midi
uint8_t         cpt_midi;
uint8_t         new_data_midi[3], new_note_midi[3], new_CC_midi[3];
uint8_t         midi_data[3][3], channel_data[3], note_data[3], velocity_data[3];


/* Detection d'une note reçue en MIDI - entrée MIDI 1 */
void detectNoteMIDI1(void){
    if(new_note_midi[0] == 1){
        //  playNote(1, note_data, velocity_data);
        new_note_midi[0] = 0;
        if(DEBUG) printf("MIDI1 - %x - %d %d \r\n", midi_data[0][0], note_data[0], velocity_data[0]);
    }
}

/* Detection d'une note reçue en MIDI - entrée MIDI 1 */
void detectNoteMIDI2(void){
    if(new_note_midi[1] == 1){
        //  playNote(1, note_data, velocity_data);
        new_note_midi[1] = 0;
        if(DEBUG) printf("MIDI2 - %x - %d %d \r\n", midi_data[1][0], note_data[1], velocity_data[1]);
    }
}

/* Detection d'une note reçue en MIDI - entrée MIDI 1 */
void detectNoteMIDI3(void){
    if(new_note_midi[2] == 1){
        //  playNote(1, note_data, velocity_data);
        new_note_midi[2] = 0;
        if(DEBUG) printf("MIDI3 - %x - %d %d \r\n", midi_data[2][0], note_data[2], velocity_data[2]);
    }
}

/* Joue une note sur la liaison MIDI */
void playNote(char midi_nb, char note, char velocity){
    uint8_t     temp_data[3];
    temp_data[0] = MIDI_NOTE_ON;
    temp_data[1] = note;
    temp_data[2] = velocity;
    switch(midi_nb){
        case 1:
            midi1.write(temp_data, 3);
            break;
        case 2:
            midi2.write(temp_data, 3);
            break;   
        default:
            midi1.write(temp_data, 3);
            break;           
    }
    
}

/* Stoppe une note sur la liaison MIDI */
void stopNote(char midi_nb, char note, char velocity){
    uint8_t     temp_data[3];
    temp_data[0] = MIDI_NOTE_OFF;
    temp_data[1] = note;
    temp_data[2] = velocity;   
    switch(midi_nb){
        case 1:
            midi1.write(temp_data, 3);
            break;
        case 2:
            midi2.write(temp_data, 3);
            break;   
        default:
            midi1.write(temp_data, 3);
            break;           
    }
}
