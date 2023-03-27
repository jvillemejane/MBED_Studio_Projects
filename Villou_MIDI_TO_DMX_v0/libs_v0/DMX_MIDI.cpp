/****************************************************************************/
/*  DMX_MIDI module library                                                 */
/****************************************************************************/
/*  LEnsE / Julien VILLEMEJANE       /   Institut d'Optique Graduate School */
/****************************************************************************/
/*  Library - DMX_MIDI.cpp file                                             */
/****************************************************************************/
/*  Pinout based on F767ZI DMX extension Board                                                                */
/*      @see : https://github.com/jvillemejane/LEnsE_IOGS_Maquettes/tree/main/Maquettes/Elec_Num_Emb/MIDI_DMX_F767
                                                                            */
/****************************************************************************/
/*  Tested on Nucleo-L476RG / 11th nov 2021                                 */
/****************************************************************************/

#include "DMX_MIDI.h"
#include <cstdint>

/* Entrées - Sorties */
// DMX
UnbufferedSerial    dmx(PE_8, PE_7);    // DMX
DigitalOut      out_tx(PE_12); 
DigitalOut      start(PE_10);     //envoie des données
DigitalOut      enableDMX(PE_14 );
// MIDI
/* Midi Inputs and Outputs */
UnbufferedSerial    midi1(PB_9, PB_8);  // Midi 1
UnbufferedSerial    midi2(PG_14, PG_9); // Midi 2
UnbufferedSerial    midi3(PE_1, PE_0);  // Midi 3
// Analogiques
AnalogIn    CV_volume(PC_2);
AnalogIn    CV_pitch(PB_1);
AnalogIn    variationR(PF_8);
AnalogIn    variationG(PF_7);
AnalogIn    variationB(PF_9);

/* Variables globales */
char        dmx_data[SAMPLES] = {0};
int         rgb;
// Midi
char        cpt_midi[3];
char        new_data_midi[3], new_note_midi[3], midi_channel[3];
char        midi_data[3][3], note_data[3], velocity_data[3];
char        control_ch[3], control_value[3];

/* Fonction d'initialisation de la liaison DMX */
void initDMX(void){
    dmx.baud(250000);
    dmx.format (8, SerialBase::None, 2);
    enableDMX = 0;
    
    clearDMX();
} 

void clearDMX(void){
    // Initialisation canaux DMX
    for(int k = 0; k < SAMPLES; k++){
        dmx_data[k] = 0;
    }    
    updateDMX();
}

/* Fonction de mise à jour de la sortie DMX */
void updateDMX(){
        enableDMX = 1;
        start = 1;      // /start
        out_tx = 0;     // break
        wait_us(88);    
        out_tx = 1;     // mb
        wait_us(8);     
        out_tx = 0;     // break
        start = 0;
        char d = 0;
        dmx.write(&d, 1);     // Start
        for(int i = 0; i < SAMPLES; i++){
            dmx.write(dmx_data+i, 1);     // data
        }
        wait_us(23000); // time between frame  
}

/* Fonction d'initialisation de la liaison MIDI */
void initMIDI(uint8_t device){
    switch(device){
        case 1:
            midi1.baud(31250);
            midi1.format(8, SerialBase::None, 1);
            midi1.attach(&ISR_midi_in1, UnbufferedSerial::RxIrq);
            break;
        case 2:
            midi2.baud(31250);
            midi2.format(8, SerialBase::None, 1);
            midi2.attach(&ISR_midi_in2, UnbufferedSerial::RxIrq);
            break;
        case 3:
            midi3.baud(31250);
            midi3.format(8, SerialBase::None, 1);
            midi3.attach(&ISR_midi_in3, UnbufferedSerial::RxIrq);
            break;        

    }
}
/* Detection d'une note reçue en MIDI */
bool isNoteMIDIdetected(uint8_t device){
    if(new_note_midi[device-1] == 1)
        return true;
    else
        return false;
}
/* Note reçue en MIDI traitée */
void resetNoteMIDI(uint8_t device){
    new_note_midi[device-1] = 0;
}

/* Detection d'un controle reçu en MIDI */
bool isCCMIDIdetected(uint8_t device){
    if(new_data_midi[device-1] == 1)
        return true;
    else
        return false;
}
/* Controle reçu en MIDI traité */
void resetCCMIDI(uint8_t device){
    new_data_midi[device-1] = 0;
}

/* Renvoie la note reçue sur la liaison MIDI */
void resendNoteMIDI(uint8_t source, uint8_t dest){
    /*
    midi.putc(MIDI_NOTE_ON);
    midi.putc(note_data);
    midi.putc(127);
    */
}

/* Joue une note sur la liaison MIDI */
void playNoteMIDI(uint8_t device, char note, char velocity){
    /*
    midi.putc(MIDI_NOTE_ON);
    midi.putc(note);
    midi.putc(velocity);
    */
}

/* Stoppe une note sur la liaison MIDI */
void stopNoteMIDI(uint8_t device, char note, char velocity){
    /*
    midi.putc(MIDI_NOTE_OFF);
    midi.putc(note);
    midi.putc(velocity);
    */
}

/* Fonction d'interruption sur MIDI */
/* Format MIDI : 
		- 1 octet pour le type de message
		- 1 ou 2 octets pour l'information transmise (Note et Velocité, par exemple)
 */
void ISR_midi_in1(void){
    debug_out = !debug_out;
	// Récupération de la donnée sur la liaison série
    char data;
    midi1.read(&data, 1);
	// Détection du premier octet (valeur > 128 d'après le protocole MIDI)
    if(data >= 128)
        cpt_midi[0] = 0;
    else
        cpt_midi[0]++;
	// Stocktage de la donnée reçue dans une des 3 cases du tableau midi_data
    midi_data[0][cpt_midi[0]] = data;
	
	uint8_t message_type = midi_data[0][0] & 0xF0;
	midi_channel[0] = midi_data[0][0] & 0x0F;
	
    if(cpt_midi[0] == 2){
        cpt_midi[0] = 0;
        if((message_type == MIDI_NOTE_ON) || (message_type == MIDI_NOTE_OFF)){
            new_note_midi[0] = 1;
            note_data[0] = midi_data[0][1];
            velocity_data[0] = midi_data[0][2];
        }
        else{
            if(message_type == MIDI_CC){
                new_data_midi[0] = 1;
                control_ch[0] = midi_data[0][1];
                control_value[0] = midi_data[0][2];
            }
        }
    }
}